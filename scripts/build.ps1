[CmdletBinding()]
param(
    [ValidateSet('modern', 'default', 'compare', 'clean', 'clean-tools', 'tidymodern')]
    [string]$Target = 'modern',

    [ValidateRange(1, 256)]
    [int]$Jobs = [Environment]::ProcessorCount
)

$ErrorActionPreference = 'Stop'

$candidateRoots = @(
    $env:MSYS2_ROOT,
    'C:\msys64',
    (Join-Path $env:LOCALAPPDATA 'Programs\msys64'),
    (Join-Path $env:LOCALAPPDATA 'MSYS2')
) | Where-Object { $_ }

$msysRoot = $candidateRoots |
    Where-Object { Test-Path (Join-Path $_ 'usr\bin\bash.exe') } |
    Select-Object -First 1

if (-not $msysRoot) {
    throw 'MSYS2 was not found. Install it and the UCRT64 build dependencies described in INSTALL.md.'
}

$bash = Join-Path $msysRoot 'usr\bin\bash.exe'
$repoRoot = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$env:PELE_WINDOWS_ROOT = $repoRoot
$unixRoot = (& $bash -lc 'cygpath -u -- "$PELE_WINDOWS_ROOT"').Trim()

if (-not $unixRoot) {
    throw "MSYS2 could not translate the repository path: $repoRoot"
}

$env:PELE_UNIX_ROOT = $unixRoot
$makeGoal = if ($Target -eq 'default') { '' } else { $Target }
$command = 'export PATH=/ucrt64/bin:/usr/bin:$PATH; cd "$PELE_UNIX_ROOT"; make ' + $makeGoal + " -j$Jobs"

$env:MSYSTEM = 'UCRT64'
$env:CHERE_INVOKING = '1'
& $bash -lc $command

if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

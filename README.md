# Pokémon Emerald Legacy Enhanced

Pokémon Emerald Legacy Enhanced is an fork of Pokémon Emerald Legacy by [TheSmithPlays](https://www.youtube.com/@smithplayspokemon) and his incredible project team aiming to add Quality of Life improvements and updates which do not align with the Legacy project vision, but nonetheless are features which I believe enhances the game.

I have **no official affiliation** with TheSmithPlays or his incredible project team, I'm just a single developer fan who wanted to make my own flavour of Emerald Legacy with the greatest respect for the fantastic version of Emerald the team has already built. I look to regularly pull in any updates or fixes from the base Pokémon Emerald Legacy whenever the project team publishes.

Some simple Quality of Life features are included in the base patch (such as using select in the party menu to switch Pokémon posititions and HMs only requiring Badge, HM in bag and a Pokemon able to learn the move (not taking up a move slot) to use them), whilst some larger additions will be separated as their own patches (such as Enhanced Starters which adds the starters for early route availability and buffs signature moves.)

**Note:** Save files should be compatible from base Pokémon Emerald Legacy, but please do keep a backup prior to moving and if there ar eany bugs or problems feel free to report an [Issue](https://github.com/Exclsior/Pokemon_Emerald_Legacy_Enhanced/issues).

## Download and Play

* To download the patch, see [RELEASES](https://github.com/Exclsior/Pokemon_Emerald_Legacy_Enhanced/releases) and download the zip file for the latest patch. Unzip the folder, then follow the instructions in one of the readme files in the `README` file.
* To set up the repository, see [INSTALL.md](INSTALL.md).

### For the tech-savvy

This repository initially started as "Pokémon Emerald Legacy - Starters Enhanced" which I've now moved into a feature branch instead, so I am slowly working through cleaning out branches and features to be mutually exclusive to allow anybody to pick and choose which branches they would like and compile their own custom version. This isn't at that point yet with all branches currently included "Enhanced Starters" branch at base.

The Pret Pokeemerald disassembly upon which the project is ultimately based has allowed many developers to build a myriad of amazing features, this fork primarily looks to incorporate already built and tested features. I'm happy for anybody to fork from this repository and use any feature branches, just please do credit the original feature creatures as I've done below, and happy to entertain pull requests if there's a feature which you've added which doesn't conflict with any other features in the game.

Without any further ado, below are the features added to Base Patch (main branch):

## Base Patch - v1.0.1:

The Base Emerald Legacy Enhanced version which primarily focuses on quality of life additions such as HM improvements, Stat Editor for IVs and EVs, Nature Mints and an Egg Move Tutor.

This Base patch includes all updates to Pokemon Emerald Legacy source coade as of 12 Jan 2025.

### Implemented Changes:
* Removed requirement for a HM move to have to be learned by a pokemon in order to be used outside of battle.
  * Relevant Gym Badge, HM in bag, and at least one pokemon capable of learning the move required to use the HM.
  * Dialogue for people providing HMs updated to note that a pokemon only needs to be able to learn the move.
    * e.g. "Cutter" in Rustboro's dialogue updated to note a pokemon able to learn cut can chop down thin trees.
  * Secret Power works similarly, requiring TM43 in Bag and a pokemon able to use the move (which is almost all pokemon)
* Stat Editor to edit IVs and EVs added to Party Menu after National Dex is unlocked.
* Nature Mints have been added in the game for purchase after beating Petalburg Gym.
  * One free Serious Mint will be given by Norman after gaining the Facade TM.
  * Pretty Petal Flower Shop North of Petalburg Woods will sell all mints at 20,000 pokedollars each.
  * **Note:**:
    * Save file compatibility with Emerald Legacy will work, however if you return to base Emerald Legacy, any Pokemon which has had it's nature altered from orginal via mint will retain its altered new nature stats with their original nature name and potentially incorrect highlighting of boosted and lowered stats.
    * Stats can be fixed for any Pokemon if they are deposited or withdrawn from a PC where their stats will be recalculated using their original nature and Base Stats.
* Added Egg Move Tutor to Fallarbor Town Move Tutor's House after beating the game.
* Low Health beep reduced to three beeps and not loop infinitely.
* Added Select as shortcut to swap Pokemon in Party
* Updated Options Menu to add ability to enable or disable Bike and Surf Music.
* Reduced in-battle item use animation
* Added Multi item Register Menu.
  * One registered item works same as vanilla Emerald, multiple registered items will show on-field menu to select item.
  * **Note:** Emerald Legacy Saves brought over will lose the originally selected item, re-registering Key Item will fix issue.
* Beldum, Metang and Metagross Catch Rates increased to 45 to match other psuedo-legendaries.

## Dragon Type Physical - v1.0.1:

Simple swap for Dragon type to be considered Physical. This **does not** do any stat rebalancing of any pokemon, just swaps the typing. (e.g. Salamence will benefit significantly, Latios will lose out).

### Implemented Changes:
* All changes already present in Base Patch.
* Dragon type Physical in battle.

## Dragon Grovyle and Sceptile - v1.0.1:

A common request throughout the Legacy project to make the Treecko Dragon type.

### Implemented Changes:
* All changes already present in Base Patch.
* Grovyle and Sceptile with added Dragon type.
* Starter Level-up moves updated (changes compared to Emerald Legacy only):
  * Grovyle:
    * Lvl 16: Twister
    * Lvl 19: Razor Leaf
    * Lvl 34: Dragonbreath
    * Lvl 37: Leaf Blade (in case of evolution cancellation)
    * Lvl 45: Dragon Claw
  * Sceptile:
    * Lvl 16: Twister
    * Lvl 19: Razor Leaf
    * Lvl 34: Dragonbreath
    * Lvl 60: Outrage

## Physical Dragon Grovyle and Sceptile - v1.0.1:

Combination of the two above patches for physical Dragon type and to add Dragon typing to the Treecko line. Only Grovyle and Sceptile stats rebalanced, as above no other pokemon rebalanced (e.g. Salamence will benefit significantly, Latios will lose out).

### Implemented Changes:
* All changes already present in Base Patch.
* Dragon type Physical in battle.
* Grovyle and Sceptile with added Dragon type.
* Starter Level-up moves updated (changes compared to Emerald Legacy only):
  * Grovyle:
    * Lvl 16: Twister
    * Lvl 19: Razor Leaf
    * Lvl 34: Dragonbreath
    * Lvl 37: Leaf Blade (in case of evolution cancellation)
    * Lvl 45: Dragon Claw
  * Sceptile:
    * Lvl 16: Twister
    * Lvl 19: Razor Leaf
    * Lvl 34: Dragonbreath
    * Lvl 60: Outrage
* Grovyle and Sceptile Stats reworked slightly due to change for Dragon Type changed to Physical (compared to Emerald Legacy):
  * Grovyle:
    * Base Attack Increased by 5
    * Base Special Attack Decreased by 5
  * Sceptile:
    * Base Attack Increased by 10
    * Base Special Attack Decreased by 5
    * Base Special Defence Decreased by 5
  * **Note:** If you are bringing a save file from Emerald Legacy and have Grovyle or Sceptile in your party, please deposit and withdraw from a PC to get their base stat calculations to be reset.

## Enhanced Starters - v1.0.1

An expansion on the Pokemon Emerald Legacy Enhanced Project which further buffs the Hoenn Starters (and my preferred way to play!). For the most balanced version, please use the original version! This version is just to feed into the childhood nostalgia feeling of having an overpowered starter throughout the game and to catch all the starters early in the game.

### Implemented Changes
* All changes already present in Base Patch.
* Added starters to following routes for increased availability:
  * Treeko:
    * Location: Petalburg Woods
    * Encounter Rate: 5% at level 7
    * Why?: Earliest Forest
    * Removed encounter: Shroomish at level 7 (Shroomish at level 5 remains)
  * Torchic:
    * Location: Route 116
    * Encounter Rate: 5% at level 8
    * Why?: Earliest route without any water other than 101
    * Removed encounter: Tailow at level 8 (Taillow at levels 6, 7 and 10 remain)
  * Mudkip:
    * Location: Route 103
    * Encounter Rate: 4% at level 4, 1% at level 5
    * Why?: Earliest river route, also noted as "Water's Edge" pokemon by FRLG pokedex
    * Reduced encounter: Wingull at levels 2 and 3 (Encounter percentage only reduced)
* Buffed Signature Moves:
  * Leaf Blade:
    * Retain Legacy Buffs
    * Battle Power increase to 95
  * Blaze Kick:
    * Retain Legacy Buffs
    * Battle Power increase to 95
  * Muddy Water:
    * Retain Legacy Buffs
    * Battle Power increase to 95
    * Accuracy increase to 100
* Grovyle and Sceptile with added Dragon type (Feel free to fork and revert files to base if you don't want Dragon Typing!)
* Starter Level-up moves updated (changes compared to Emerald Legacy only):
  * Grovyle:
    * Lvl 16: Twister
    * Lvl 19: Razor Leaf
    * Lvl 34: Dragonbreath
    * Lvl 37: Leaf Blade (in case of evolution cancellation)
    * Lvl 45: Dragon Claw
  * Sceptile:
    * Lvl  1: Crunch (Treeko Egg Move, for relearning)
    * Lvl 16: Twister
    * Lvl 19: Razor Leaf
    * Lvl 34: Dragonbreath
    * Lvl 60: Outrage
    * Lvl 65: Frenzy Plant
  * Combusken:
    * Lvl 37: Blaze Kick (in case of evolution cancellation)
    * Lvl 41: Sky Uppercut
    * Lvl 55: Hi Jump Kick
  * Blaziken:
    * Lvl  1: Rock Slide (Torchic Egg Move, for relearning)
    * Lvl 65: Blast Burn
  * Mudkip:
    * Lvl 21: Bubblebeam
    * Lvl 26: Dig
  * Marshtomp:
    * Lvl 24: Mud Sport (Was in both Mudkip's and Swampert's Learnsets, not in Marshtomp's)
    * Lvl 28: Dig
    * Lvl 37: Muddy Water (in case of evolution cancellation)
    * Lvl 40: Protect
    * Lvl 43: Earthquake
    * Lvl 45: Hydro Pump
    * Lvl 50: Endeavor
  * Swampert:
    * Lvl  1: Ice Ball (Mudkip Egg Move, for relearning)
    * Lvl 28: Dig
    * Lvl 65: Hydro Cannon
  * Meganium:
    * Lvl 65: Frenzy Plant
  * Typhlosion:
    * Lvl 65: Blast Burn
  * Feraligatr:
    * Lvl 65: Hydro Cannon

## Enhanced Credits List:
* Credit to devolov (Discord: devolov#4853) for [Only Pokemon that can Learn HM can Use Field Move so Long as HM is in Bag](https://github.com/pret/pokeemerald/wiki/Use-HMs-Without-Any-Pokemon-in-your-Party-Knowing-Them#only-pokemon-that-can-learn-hm-can-use-field-move-so-long-as-hm-is-in-bag)
* Credit to [ScyrousFX](https://www.pokecommunity.com/member.php?u=980149) for [Use Fly/Flash from party menu if Pokémon is compatible](https://www.pokecommunity.com/showpost.php?p=10420068)
* Credit to TeamAquasHideout for [EV IV Stat Editor UI](https://github.com/pret/pokeemerald/wiki/Add-a-EV---IV-Stat-Editor-UI)
* Credit to [ghoulslash](https://www.pokecommunity.com/members/ghoulslash.581824/) for [Nature Mints](https://www.pokecommunity.com/showpost.php?p=10245635&postcount=191)
* Source [Tweaking the count of health beeps
](https://github.com/pret/pokeemerald/wiki/Tweaking-the-count-of-health-beeps)
* Credit to [Lunos](https://www.pokecommunity.com/members/lunos.114506/) for [Swap party screen slots using Select](https://www.pokecommunity.com/showpost.php?p=10420662)
* Credits to [TheXaman](https://www.pokecommunity.com/members/thexaman.743189/), [DizzyEgg](https://github.com/DizzyEggg), [Lunos](https://www.pokecommunity.com/members/lunos.114506/), [AsparagusEduardo](https://github.com/AsparagusEduardo), and [ella_trifle/ellabrella](https://www.pokecommunity.com/members/ellabrella.751712/) for [New Options Plus ‐ Multipage Options Menu](https://github.com/pret/pokeemerald/wiki/New-Options-Plus-%E2%80%90-Multipage-Options-Menu-with-Faster-Text,-HP%E2%80%90EXP-Bar-Speeds-and-Metric)
* Credit to [KyuZee](https://github.com/kyuzeemctree) for [Speed Up Held Item Animation](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/wiki/Speed-Up-Held-Item-Animation)
* Credit to [Scyrous](https://github.com/Scyrous), Yak Attack, [Kurausukun](https://github.com/Kurausukun), and Zatsu for [Make Move Relearner Teach Egg Moves With A Flag](https://github.com/pret/pokeemerald/wiki/Make-Move-Relearner-Teach-Egg-Moves-With-A-Flag)
* Credits to [TheXaman](https://www.pokecommunity.com/members/thexaman.743189/), [RavePossum](https://github.com/RavePossum), and [iriv24](https://github.com/iriv24) for [Modified "register items in a list menu"](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/wiki/Feature-Branches/#iriv24tx_registered_items_menu)

# Pokémon Emerald Legacy

Emerald Legacy is meant to serve as a finale to the trio of planned projects in the Legacy Trilogy led by [TheSmithPlays](https://www.youtube.com/@smithplayspokemon). It is made using the [Pokémon Emerald Disassembly](https://github.com/pret/pokeemerald) made by the [Pret](https://pret.github.io/) team. This game is focused on refining a game that is considered a classic by many people into a nostalgic but improved experience with 20+ years of hindsight. Emerald is a great game with a ton of flaws when you use that experience to really look at it under a lens. Terrible pokemon pool, Weird team building choices, A great story idea executed poorly, baffling rival decisions, and one of the worst E4s. This game with all of these problems manages to shrug them off with memorable dex additions, fantastic gym leader ace choices, abilities, no more stat xp, Battle frontier, original ideas to the series, and overall a solid game. The Legacy Project aims to take what is good in a game and improve it while bringing its flaws up to that same level. 

Keeping that nostalgic feeling is a key part of the project and thus requires us to temper our changes into things that improve the experience but don’t take you out of that original generation 3 mindset. Things like the Physical/Special Split, adding moves, adding new evolutions, or adding the fairy typing are not things you will find in this game. Instead look for improvements to the Rival storyline, Team Magma & Aqua storyline, Tons of pokemon balancing using the tools given to us in this generation, a robust post game, improved boss fights throughout the game, adjusted level curve, and so much more. We are not trying to create a new game, nor are we trying to create a “Kaizo” game that is insanely difficult. We wanted to create a modern but nostalgic version of Pokémon Emerald. So please enjoy Pokémon Emerald Legacy.


## A complete list of features can be found here:
Full Documentation:
- [Make a Copy (Recommended)](https://docs.google.com/document/d/1rBSuhFmiiehghr3AQ37JwBzbLCD21TXo_SWpUUXsz9k/copy)
- [Published Page (Use this if you do not have a Google account and/or want to download the page as a PDF)](https://docs.google.com/document/d/e/2PACX-1vSv_enL8baSvetAUgBBrkh-TJka1-IeOxPchf9cuH317VLetLnvqQu7jgRXhj2gnlDqvBaEo2mbddJl/pub)

These videos also provide an overview of the hack and the ideology behind it:
- [Release 1.0](https://www.youtube.com/watch?v=jUHGejDvuNM)
- [Prerelease](https://www.youtube.com/playlist?list=PLyv5bsGgaxokt8gJX3WvI28pG3ddrhFLd)


## Our Other Projects
* [Pokemon Crystal Legacy](https://github.com/cRz-Shadows/Pokemon_Crystal_Legacy)
* [Pokemon Yellow Legacy](https://github.com/cRz-Shadows/Pokemon_Yellow_Legacy)
* [Pokemon Cursed Yellow](https://github.com/cRz-Shadows/Pokemon_Cursed_Yellow)
* [Pokemon Battle Simulator](https://github.com/cRz-Shadows/Pokemon_Trainer_Tournament_Simulator)


## Discussion and Community
* [YouTube](https://www.youtube.com/@smithplayspokemon)
* [Discord](https://discord.gg/Wupx8tHRVS)
* [Reddit](https://www.reddit.com/r/PokemonLegacy)
* [Twitter](https://twitter.com/TheSmithPlays)
* [Instagram](https://www.instagram.com/thesmithplays/)


## Pret Stuff
- **All Pret Projects:** [pret.github.io](https://pret.github.io/).


## Credits For Emerald Legacy:

### Creators:
- TheSmithPlays - Project Manager and Developer
- cRz Shadows - Lead Devoloper
- Weebra - Video Editor
- Aerogod - Developer
- Disq - Developer
- Isona - Developer
- ZuperZACH - Developer
- Karlos - Developer
- Regi -  Developer


### Playtesters:
- Obelisk
- JanitorOPplznerf
- Sable
- Alakadoof
- ReaderDragon
- Rwne
- Talos
- Tiberius
- SoulXCross
- Mogul


### Blind Testers:
- Kewaun
- SlifertheCanadian
- Awqweird
- Mungi
- Shaun Duz Stuffs
- Flint'sInfernape
- Dabrikishaw8008
- PotatoMan
- RevRush
- Flashbang
- Sam10q
- Elitegrove
- Nootathotep


### Sprite Artists:
- ZuperZACH
- Isona


### Music Credits:
- "Vs Zinnia" - GBA MIDI by LibertyTwins, Original Composition by Shota Kageyama
- "Battle! Rival Wally! (Pokemon Omega Ruby/Alpha Sapphire)" - Based on [a Score written by BreadMaster](https://musescore.com/user/13873941/scores/6601098), Original Composition by Minako Adachi


### Where you can find all Pret Tutorials:
* https://github.com/pret/pokeemerald/wiki/Tutorials


### Code Credits:
- Voloved:
    - [Bag expansion](https://github.com/pret/pokeemerald/wiki/Make-the-Bag-Able-to-Hold-120-Items-Instead-of-30)
    - [Make Key Items That Cannot Be Used In The Field Not Show A Use or Register Option](https://github.com/pret/pokeemerald/wiki/Make-Key-Items-That-Cannot-Be-Used-In-The-Field-Not-Show-A-Use-or-Register-Option)
    - [Item Automatically Goes to PC if Bag is Full](https://github.com/pret/pokeemerald/wiki/Item-Automatically-Goes-to-PC-if-Bag-is-Full)
    - [Allow Jumping Over Ledges with Acro Bike](https://github.com/pret/pokeemerald/wiki/Allow-Jumping-Over-Ledges-with-Acro-Bike)
    - [Get Match Calls Only If Caller Wants a Rematch](https://github.com/pret/pokeemerald/wiki/Get-Match-Calls-Only-If-Caller-Wants-a-Rematch)
    - [Make the Person in the Intro Match the the Save File](https://github.com/pret/pokeemerald/wiki/Make-the-Person-in-the-Intro-Match-the-the-Save-File)
    - [Fix AI's Switch In Battle](https://github.com/pret/pokeemerald/wiki/Fix-AI's-Switch-In-Battle)
    - [Add Move Description Submenu During Battle](https://github.com/pret/pokeemerald/wiki/Add-Description-Submenu)
- Ghoulslash:
    - [Bag sorting](https://github.com/pret/pokeemerald/compare/master...ghoulslash:pokeemerald:bag_sort)
    - [Repeated Field Medicine/Rare Candy Use](https://github.com/pret/pokeemerald/wiki/Repeated-Field-Medicine-Use)
    - [Overworld sprite expansion from 255 to 65536](https://github.com/pret/pokeemerald/compare/master...ghoulslash:pokeemerald:overworld-expansion)
- ExpoSeed:
    - [Allow running indoors](https://github.com/pret/pokeemerald/wiki/Allow-running-indoors)
    - [Repel reuse prompt](https://github.com/pret/pokeemerald/wiki/Prompt-for-reusing-Repels)
- Lunos 
    - [Check for a Specific Pokémon Species](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-9#post-10213715)
    - [Gen. 4 Styled Deoxys Form Change in the Overworld](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-10#post-10259063)
- Mkol103
    - [Improving the Pace of Battles](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-11#post-10266925)
    - [Improving Switching AI](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-11#post-10263816)
- FieryMewtwo
    - [Remove the extra save confirmation](https://github.com/pret/pokeemerald/wiki/Remove-the-extra-save-confirmation)
    - [Fast heal](https://github.com/pret/pokeemerald/wiki/Speedy-Nurse-Joy)
- TheXaman - [Pokedex plus upgrade](https://github.com/pret/pokeemerald/commit/abf5d238c2a5fe020123544a72fe432c27191153)
- CameruptQDX - [Create a new regular trainer battle](https://github.com/pret/pokeemerald/wiki/How-to-create-a-new-regular-trainer-battle)
- Surskitty - [Improved trainer control system](https://github.com/rh-hideout/pokeemerald-expansion/compare/master...surskitty:pokeemerald:trainer_control)
- devolov/tutorial by voloved - [Hard/Hardcore mode adapted from nuzlocke mode](https://github.com/pret/pokeemerald/wiki/Add-Nuzlocke-Challenge)
- Anon822 - [Wrong Save Type Error Screen](https://www.pokecommunity.com/showpost.php?p=10449518)
- paccy - [Change the Clock Time](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-18#post-10481737)
- dunsparce9 - [Less annoying berries](https://github.com/dunsparce9/pokeemerald-tweaks/commit/40685e31e4d50722a922ec1201a8397f81fc17d2)
- LOuroboros - [DPPt Bike (a 2-in-1 Bike)](https://github.com/LOuroboros/pokeemerald/commit/ab27f6ff1663a07ea8a8d96c877bbb9279f72f53)
- Jaizu - [Managing trainer Rematches in Emerald](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-8#post-10210036](https://www.pokecommunity.com/showpost.php?p=10210036&postcount=151))
- Jaizu, Buffel Saft, AkimotoBubble, PokemonCrazy, Scyrous - [Show IVs EVs in Summary Screen](https://github.com/pret/pokeemerald/wiki/Show-IVs-EVs-in-Summary-Screen)
- DizzyEgg/tutorial by ExpoSeed - [Colored stats by nature in summary screen](https://github.com/pret/pokeemerald/wiki/Colored-stats-by-nature-in-summary-screen)
- Ellabrella - [Increase Text Speed Beyond Fast](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-15#post-10400198)
- Robinlukke - [Feed any number of pokéblocks](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-14#post-10364627)
- AmbientDinosaur - [Changing encounter groups with map scripts](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-12#post-10315616)
- WiserVisor - [How To Add, Edit, And Understand Music in Pokeemerald](https://www.pokecommunity.com/threads/how-to-add-edit-and-understand-music-in-pokeemerald.444317/)
- Goppier - [Add zigzagoon scene back to the cable car](https://www.youtube.com/watch?v=7xdcbbfwEto)
- takyon - [Always inherit nature when holding an Everstone​](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-4#post-10160374)
- myxto - Always inherit nature when holding an Everstone alternate implementation​
- Jirachii - [Hidden Power type in summary screen](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-11#post-10269132)


### Other Credits:
- People that generally helped out with advice or otherwise
    - Idain
    - Nayru62
    - JaaShooUhh

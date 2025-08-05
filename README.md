# Pokémon Emerald Legacy Enhanced

Pokémon Emerald Legacy Enhanced is an fork of Pokémon Emerald Legacy by [TheSmithPlays](https://www.youtube.com/@smithplayspokemon) and his incredible project team aiming to add Quality of Life improvements and updates which do not align with the Legacy project vision, but nonetheless are features which I believe enhances the game.

I have **no official affiliation** with TheSmithPlays or his incredible project team, I'm just a single developer fan who wanted to make my own flavour of Emerald Legacy with the greatest respect for the fantastic version of Emerald the team has already built. I look to regularly pull in any updates or fixes from the base Pokémon Emerald Legacy whenever the project team publishes.

Quality of Life features are included in the base patch (such as using select in the party menu to switch Pokémon posititions and HMs only requiring Badge, HM in bag and a Pokémon able to learn the move (not taking up a move slot) to use them), whilst some larger deviations from the legacy vision will be separated as their own patches (such as Enhanced Starters which adds the starters for early route availability and buffs signature moves.)

### For the tech-savvy

The Pret Pokeemerald disassembly upon which the project is ultimately based has allowed many developers to build a myriad of amazing features, this fork primarily looks to incorporate already built and tested features. I'm happy for anybody to fork from this repository and use any feature branches, just please do credit the original feature creatures as I've done below, and I'm happy to entertain pull requests if there's a feature which you've added which doesn't conflict with any other features in the game.

Without any further ado, below are the features added to Base Patch (main branch):

## Base Patch - v1.1.4:

The Base Emerald Legacy Enhanced version which primarily focuses on quality of life additions such as HM improvements, Pokémon Followers, National Dex Mode, Shiny Charms, Stat Editor for IVs and EVs, Nature Mints and an Egg Move Tutor.

This Base patch includes all updates to Pokémon Emerald Legacy source code as of 27 Feb 2025.

**Note:**: Save file compatibility with Emerald Legacy available, but is one-way from Emerald Legacy to Enhanced and from older versions of Enhanced. Please backup original saves before moving to Enhanced.

### Implemented Changes:
* All Base Legacy changes as of v1.1.4.
* Removed requirement for all field moves (including HMs) to have to be learned by a Pokémon in order to be used outside of battle.
  * Relevant Gym Badge, HM in bag, and at least one Pokémon capable of learning the move required to use a HM.
  * Dialogue for people providing HMs updated to note that a Pokémon only needs to be able to learn the move.
    * e.g. "Cutter" in Rustboro's dialogue updated to note a Pokémon able to learn cut can chop down thin trees.
  * Secret Power requires TM43 in Bag and a Pokémon able to use the move (which is almost all Pokémon)
  * Dig requires TM28 in Bag and a Pokémon able to use the move from the party menu or level up as noted below.
  * The following field moves require the Pokémon to be able to learn it by level up equal or prior to their current level to be added to the party menu:
    * Dig
    * Teleport
    * Milk Drink
    * Softboiled
    * Sweet Scent
  * A maximum of four field moves will be added to the Party Menu list with priority given to moves already learned, followed by Fly and Flash HMs before any non-HM moves.
* Added Pokémon follower as first Pokémon in your party
  * Supports Shiny followers
  * As noted below, can be disabled in options menu.
  * If first Pokémon fainted, second Pokémon in party will be follower and so on.
  * Some areas such as Fortree and Mossdeep Gyms will have followers hidden to not interfere with the puzzles.
  * Very large followers (Steelix, Lugia, Ho-oh, Kyogre, Groudon and Rayquaza) will not appear indoors.
  * As noted below, can be disabled if preferred in options.
* Added unique per-Pokémon Surfing Overworld sprites instead of the "Surf blob"
  * Supports Shiny Pokémon.
  * As noted below, can revert back to Surf Blob if preferred in options.
  * Diving uses generic diving sprite.
* Added gold sparkle to Feebas spots on Route 119 after recieving the Devon Scope.
  * Feebas encounter rate on tiles reduced to 10% to retain a bit of challenge in finding wild Feebas (Normal 50% on Feebas tiles before getting the Devon Scope).
  * Steven's dialogue updated when providing Devon Scope to hint towards revisiting Route 119.
* Stat Editor to edit IVs and EVs added to Party Menu after National Dex is unlocked.
  * Updated in latest patch to decrease or increase EVs and IVs by 10 using L and R respectively.
* Nature Mints have been added in the game for purchase after beating Petalburg Gym.
  * One free Serious Mint will be given by Norman after gaining the Facade TM.
  * Pretty Petal Flower Shop North of Petalburg Woods will sell all mints at 20,000 pokedollars each.
* Ability Capsules added into the game to swap between Pokémon's abilities (if a species has more than one ability available)
  * Available from Slateport Mart Energy Guru for 20,000 pokedollars if your lead Pokémon has an Effort Ribbon
  * Available from Battle Frontier from vitamin seller for 4BP
* Added optional New Game National Dex Mode option to choose from the nine starters and unlock most National Dex encounters from the start of the game. (More information in separate section below)
* Added optional in-game Shiny Charms to the player's item PC which **must** be withdrawn into the item bag to work. (More information in separate section below)
* Added Egg Move Tutor to Fallarbor Town Move Tutor's House after beating the game.
* Updated Pokédex to include evolution information.
* Added EXP. All as reward from Mr. Stone for delivering Steven's Letter.
  * **Notes:**
    * This is in addition to traditional Gen 3 EXP. Share held item remaining unchanged.
    * This is **not** not Gen 6 EXP. Share.
    * EXP splits half the battle exp evenly between all eligible Pokémon in the party.
    * EXP would be the same as if all Pokémon in the party are each holding an EXP. Share.
    * EXP. All and EXP. Share do not work together, if EXP. All is on, held item EXP. Share does not do anything.
    * If you migrate your save file and have already collected your EXP. Share, visit Mr. Stone again to recieve the EXP. All.
* Lucky Egg increases all battle exp gained if any Pokémon in party is holding the item.
* Added ability to fly to your Secret Base after creating one.
  * Represented by grayscale player icon on route where base is made.
  * **Note**: If migrating a save file, you will have to manually enter your Secret Base at least once to activate the ability to fly to the base.
* Decoration Improvements:
  * Updated Lilycove Department Store Clearance Sale to appear permanently after beating the game.
  * Added both Red and Blue Tents to Slateport Decor seller after completing Trick House.
  * Added Lotad and Seedot dolls for purchase from Slateport Doll seller.
* Low Health beep reduced to three beeps and not loop infinitely.
* Added Select as shortcut to swap Pokémon in Party.
* Updated Options Menu with below additional options:
  * Ability to enable to disable Pokémon followers.
  * Ability to toggle between unique per-Pokémon surfing overworld and original "Surf blob"
  * Ability to increase player and Non-player character movement speed in the world.
  * Ability to enable or disable Auto Run.
    * Run without holding the B Button.
    * Hold B to walk.
  * Ability to enable to disable Fast Surf.
    * Fast Surfing without holding the B button.
    * Hold B to Surf at normal speed.
  * Ability to enable or disable Improved Fishing: Does not allow hooked fish to escape (disabled by default).
  * Ability to change diving movement speed.
  * Ability to enable or disable Bike Music.
  * Ability to enable or disable Surf Music.
  * Ability to swap game battle mode between Normal, Hard and Hardcore (Nuzlocke) after defeating Steven in Meteor Falls.
  * Ability to change speed of HP Bar draining in battle.
  * Ability to change speed of EXP Bar filling in battle.
  * Ability to reduce or turn off in-battle item use animation.
  * Ability to toggle Type Effectiveness colour coding within battle (Off by default).
    * Green: Super effective, Red: Not very effective, Grey: No effect.
  * Ability to change in-game font from Hoenn (original Emerald font) to Kanto (FireRed/LeafGreen font).
  * Ability to hide post-game Stat Editor from Party Menu.
  * Ability to hide Nickname option from Party Menu.
  * Ability to change Battle Mode (Normal/Hard Mode/Hardcore(Nuzlocke)) after beating Steven in Meteor Falls.
  * Ability to increase player and NPC in-game speed (World Speed) by 2x, 4x, or 8x (Music speed stays the same.)
    * Holding "R" button will slow back to standard 1x speed.
      * May conflict with changing Bike type. Recommend to use Button Mode: "L = Settings" to move Bike swap.
    * **Note:** 8x Speed may have some minor visual bugs. This is due to the emulators skipping some frames at that speed.
  * Added extra "Button Modes" for the "L" button as a shortcut in the overworld when pressing the "L" button:
    * L = Settings: Will change the relevant contextual setting based on what the player is doing:
      * If walking or running, toggle Auto Run.
      * If surfing, toggle Fast Surf.
      * If diving, will step through the different diving speeds on each press.
      * If on bike and unlocked dual swapping bike in post-game, swap bikes.
        * This is as an alternate for players using the above World Speed options to be able to change bike type and use the manual slow down of holding "R"
    * L = Speed: Will either step through, or toggle on/off the relevant chosen World Speed option
    * L = Fast Mode: Either toggles Auto Run, Fast Surf, World Speed and Diving speed to On or Max (as appropriate), or turns them all to Off or Minimum as appropriate.
    * L = Follower: Toggles Follower On or Off:
      * When turning off, follower will return to Pokeball immediately.
      * When toggling off, player needs to take a step for follower to spawn (if able)
    * All new above Button Modes have LR Button Mode enabled.
* Added Multi item Register Menu.
  * One registered item works same as vanilla Emerald, multiple registered items will show on-field menu to select item.
  * **Note:** Emerald Legacy Saves brought over will lose the originally selected item, re-registering Key Item will fix issue.
* Added larger quantity coin purchasing in Mauville Game Corner and improved efficiency to purchase more coins.
* Soot Sack use in bag now shows amount of ash in bag and registerable to view in overworld.
* Updated Regi overworld encounter sprites to match the Regi PokeDolls instead.
* Beldum, Metang and Metagross Catch Rates increased to 45 to match other psuedo-legendaries.
* Added Self-Destruct to Wailmer and Wailord Egg Move Pool
* Added Extremespeed to Zigzagoon and Linoone Egg Move Pool
* Added Heart Scales to Sootopolis Mart at 1000 pokedollars after beating the the game.
* Added all Type Enhancing Held Items to various Town and City Pokemarts at 9,800 pokedollars after beating the game.
  * Oldale Town: Poison Barb
  * Petalburg City: Silk Scarf & Silverpowder
  * Rustboro City: Hard Stone
  * Slateport City: Black Belt
  * Mauville City: Magnet
  * Verdanturf Town: Miracle Seed
  * Fallarbor Town: Dragon Fang
  * Lavaridge Town: Charcoal & Soft Sand
  * Fortree City: Sharp Beak
  * Mossdeep City: Twistedspoon & Nevermeltice
  * Sootopolis City: Mystic Water
  * Ever Grande City (Pokémon League): Blackglasses & Spell Tag
* Added a seller of Pokémon-specific held items to the Safari Zone Entrance.
  * Before beating the game Light Ball available for 9,800 pokedollars.
  * After beating the game or in National Dex Mode: Stick, Lucky Punch, Metal Powder, and Thick Club added for 9,800 pokedollars.
  * After beating the game and having Latias or Latios in party: Soul Dew added for 50,000 pokedollars.
* Battle Frontier Exchange Corner Items Updated:
  * Changed Rare Candy Cost to 1 BP each
  * Decorations cost halved (e.g. 16 BP to 8 BP)
  * Reduced rare berry costs to a quarter (e.g. 48 BP to 12 BP)
  * Battle Held Item costs reduced to a quarter (e.g. 48 BP to 12 BP)
    * Added more Held Items: Amulet Coin, Exp. Share, Lucky Egg, Macho Brace, Cleanse Tag, SmokeBall, Soothe Bell, & Everstone
  * PP Up added to Vitamin seller for 1BP
  * PP Max added after getting all Silver Symbols for 3BP
* Battle Frontier Move Tutor costs reduced:
  * All costs reduced to a quarter (e.g. 48 BP to 12 BP)
  * After gaining Silver Symbols Move Tutors teach moves for Free
* Amulet Coin doubles prize money if any Pokémon in party is holding the item.
* Pokeballs (except Master Ball) can be used from bag to change a Pokémon's current ball.
* Luxury ball added to Verdanturf Town Mart after clearing Rusturf Tunnel.
* Added ability for level capped and level 100 Pokémon to gain EVs.
* Pressing the B Button in Wild Battles moves the game cursor to "Run"
* Items can be moved between Pokémon in the party menu without using the bag.
* Postgame Encounters slightly reworked:
  * Sky Pillar encounter levels increased to match Ruby/Sapphire levels and merge encounter tables(now highest wild encounter levels in the game)
    * Dusclops and Mawile added to Sky Pillar Encounters
    * postgame levels updated to range from 48 - 60
  * Pseudo-legendary encounters reworked at 1% encounter rates:
    * Dragonair added to Meteor Falls Bagon room with Super Rod in postgame.
    * Pupitar replacing Larvitar in Victory Road in postgame.
    * Metang added to Steven's Meteor Falls Cave room in postgame.
    * Shelgon added to ground floor of Sky Pillar in postgame.
    * Dratini added to surfing pool of Meteor Falls Bagon room in postgame. (available in Sootopolis City in National Dex Mode)
    * Larvitar moved to Route 111 (Desert) in postgame and National Dex Mode.
  * General encounter rebalancing for National Dex Mode (changes standard postgame encounters slightly):
    * Mankey moved to Granite Cave B1F and B2F
    * Mr. Mime moved to Mt. Pyre Summit
    * Diglett moved to Route 119 (Desert)
    * Kabuto and Omanyte moved within Meteor Falls from mid-game caves to late-game caves
    * Mawile returned to Meteor Falls late-game caves
  * Lanette gives a gift Eevee in National Dex Mode or postgame.
  * Trick Master Eevee gift now Shiny.
    * If migrating a save after already claiming the gift Eevee, Trick Master will provide the Shiny Eevee gift.
  * Wild Snorlax static encounter added to National Dex Mode or postgame.
  * Trainer Hill Snorlax reward now Shiny.
    * If migrating a save after already receiving Trainer Hill Snorlax, completing Trainer Hill again will reward the Shiny Snorlax. (Two attempts may be required.)
  * Sudowoodo now respawns after each E4 clear.
  * Added reward from rival after trading for the two other Hoenn starters of Shiny starter of same species as player's starter.
* Wild Pokémon held item chances slightly buffed for Compoundeyes Ability users:
  * Chance of "common" item buffed from 60% to 70%
  * Chance of "rare" item buffed from 20% to 25%
* Clamperl wild held item changed:
  * Blue Shard removed as held item
  * 5% chance to hold Deepseascale or Deepseatooth (10% overall)
  * With compoundeyes Pokémon 10% chance to hold Deepseascale or Deepseatooth (20% overall)
* Added Fly to more Pokémon HM Learnsets (in addition to Base Legacy):
  * Butterfree
  * Beedrill
  * Venomoth
  * Scyther
  * Ledyba
  * Ledian
  * Jumpluff
  * Yanma
  * Gligar
  * Mantine
  * Celebi
  * Dustox
  * Ninjask
  * Volbeat
  * Illumise
* Blue Shard added as rare held item for Feebas (to replace Clamperl losing the held item)
* Name Rater can now rename traded Pokémon.
* Added option for Pokémon to be able to be nicknamed from the Party Menu (disabled by default).
  * Traded Pokémon can't be renamed in Party Menu, must be taken to Name Rater.
* "Move Pokémon" set as first option in Pokemon Storage System.
* Lanette's PC and Hall of Fame PC accessible from Player PC after beating the game.
* Pokeballs can now be sorted by "Type" like other bag pockets.
* Pressing "Start" on the Trainer Card screen will show the player's "Secret ID" for RNG Manipulation uses.
* Pokemon battled and seen in the Battle Frontier facilities now mark as "Seen" in the Pokédex.
* Can now fly away from Lilycove Dept. Store rooftop.
* Lilycove Vending Machine improved:
  * Cursor stays on same drink after purchase.
  * Increased chance of dropping a bonus drink.
* Steven's Champion Room and Battle Background ported from Ruby/Sapphire (Purple themed instead of Wallace's Blue theme)
  * Reverts to Wallace's Blue theme post-game
* Wallace's Gym Leader sprite ported from Ruby/Sapphire
  * Wallace's Emerald Champion Sprite remains for the E4
* Added further post-game battle with Steven in Meteor Falls (higher level)
  * Battle available after first beating Steven in Meteor Falls, then beating the E4 again.
  * Battle resets after each E4 clear.
* Mirage Island changes:
  * Appears if Wynaut in party.
  * After post-game now appears if Mew, Celebi, or Jirachi are in party as a nod to mythical Pokémon originally being referred to as "mirage" Pokémon.
* Overgrow, Blaze, Torrent and Swarm all show in-battle text when activating with a relevant move.
* Magma Armor ability now shows in-battle text when activating when hit with a water move.
* Roaming Lati now marked as "Seen" in the Pokédex after viewing TV in player home to allow tracking from Pokédex.
  * **Note:** If upgrading from base Legacy or an older version of Enhanced, changing routes once will add the relevant roaming Lati as seen to the Pokédex to track.
* As Soul Dew has no effect in Battle Frontier in Emerald, added a block to disallow a Soul Dew as a held item in Battle Frontier.
* Lati Moveset Improvements:
  * Luster Purge and Mist Ball buffed to 90BP (already 15 PP on Base Legacy)
  * Latias:
    * Water Sport moved to Lvl 1
    * Psybeam added at Lvl 25
    * Psychic moved to Lvl 35
    * Mist Ball moved to Lvl 40
    * Dragon Claw added to Level 55
  * Latios:
    * Protect moved to Lvl 1
    * Psybeam added at Lvl 25
    * Psychic moved to Lvl 35
    * Luster Purge moved to Lvl 40
    * Dragon Claw added to Level 55
* Raikou, Entei and Suicune encounters now use hidden Legendary Beasts music track for encounter music.
  * **Note:** this was intended as a test track so doesn't have the full range of other tracks in the game
* Many legendary overworld sprites updated to match follower sprites:
  * Articuno
  * Moltres
  * Zapdos
  * Mewtwo
  * Raikou
  * Entei
  * Suicune
  * Lugia
  * Ho-oh
  * Celebi
  * Latios (Southern Island)
  * Latias (Southern Island)
  * Unchanged:
    * Rayquaza, Groudon, Kyogre, Deoxys, Jirachi, Mew
* Jirachi able to be rematched if fled from or defeated
 * If defeated, E4 rematch required to reset defeated flag like other legendaries
* Many general pokemon overworld sprites updated:
  * Not changed: Kecleon, Zigzagoon who chases Birch
* All in game trades now have the relevant trade or traded pokemon in the building.
* Made Sky Pillar Puzzle easier if player has completed Battle Frontier Silver Symbols.
* Made Mirage Tower puzzle easier in postgame if not cleared beforehand.
* Final (undocumented) late post-game developer battle with Exclsior added with secret reward for completion. Reqirements for battle to become available:
  * Defeated Steven in Meteor Falls at least once.
  * Caught the Southern Island Lati.
  * Finished all in-game quests to get the Kanto starters.
  * Defeated in game base legacy developer battles against Weebra, Craig and Smith.
  * Collected all Silver Symbols from Battle Frontier.
  * Completed the Prof. Birch post-game quest to unlock the post-game encounters.

#### National Dex Mode
National Dex Mode is an alternate play mode for new games on Emerald Legacy Enhanced allowing to select from all nine starters from the start of the game as well as having all of Base Legacy's post-game route encounters available from the start of the game (i.e Rattata as a possible rare spawn on Route 101). The game **has not** been rebalanced for National Dex Pokémon, as such I do not recommend using this game mode for your first play through of Emerald Legacy Enhanced (unless you have finished Emerald Legacy already).

Some key notes:
* Able to select National Dex as an option when starting a new game.
* National Dex wild encounters unlocked
  * National Dex encounters are still rarer encounters than Hoenn counterparts through the game.
* Able to choose from all 9 available Gen 1-3 starters to play
* If you select a non-Hoenn starter:
  * The rival will still have the Hoenn starter of the type super effective against yours (i.e. if you select Charmander, your rival will start with Mudkip)
  * The Hoenn starters will be available in the post-game from your rival by trading the base form of your selected starter.
  * The relevant quest or reward matching the player's starter will be shiny. (i.e. If you chose Charmander, your rival will gift you a shiny Charmander for the relevant quest.)
* No in-game trainers or battles have been updated, the game is still Hoenn leaning.
  * As a result, the game is "unbalanced" in favour of the player.
* Some post-game gift National Dex encounters remain in the post-game (such as Aerodactyl for example)
* Safari Zone is fully available to explore (meaning the Johto encounters are available in the main game)
* One Snorlax is available somewhere in the overworld before post-game. (Respawns after each E4 clear)
* Eevee is available as a gift before post-game from Lanette.
* Porygon available from Game Corner.
* First form pseudo-legendaries all available in the wild.
  * Dratini remains available in Sootopolis city with original Base Legacy post-game location.
  * As noted above, Larvitar moved to Route 111 (Desert) as 1% encounter.
    * No Larvitar encounter in Victory Road **at all**.
* All post-game legendaries from Base Legacy **remain** post-game for National Dex mode, no changes to legendary availability.

#### Shiny Charms
Completely optional to use Shiny Charms have been added to the game. These are a "secret" feature, meaning no in-game NPCs or dialogue refer to their existence.

Some key notes, Shiny Charms:
* will be silently awarded to the player's item PC when in-game milestones have been met.
  * do not work if left or stored in the player's item PC.
* only take effect if they are in the player's bag.
* cannot be tossed.
* do work for Breeding as long as they're in the bag when you collect an egg.
* can be held by Pokémon and therefore traded between different Emerald Legacy Enhanced games.
  * do not work if held by a Pokémon
* If migrating a save and already completed a relevant milestone, the Shiny Charm will be added to your PC, except for the Pokédex Shiny Charms which require the below in-game tasks to be added to the PC.

In-game milestones for Shiny Charm acquisition (all added to Player Item PC, max 8 available per game.):
* One from start of the game
* Beating the Game (E4 and Champion)
* Getting all Contest Artworks in Lilycove Museum
* Defeating Steven in Meteor Falls
* Completing Hoenn Pokédex (And speak to Prof. Birch)
* Completing National Pokédex (And speak to game developers in Lilycove City)
* Getting all Silver Symbols in Battle Frontier
* Getting all Gold Symbols in Battle Frontier

Shiny Charm Rates:
* 0 Charms - 1/8192 (No Shiny Charms in bag) - 0.01221% - Same as original Emerald
1. 1/1024 (Available from Start of Game) - 0.09766%
2. 1/512  - 0.1953%
3. 3/1024 - 0.2930% (I suspect most people will end up here by end of their main playthrough)
4. 1/256  - 0.3906%
5. 5/1024 - 0.4883%
6. 3/512  - 0.5859%
7. 7/1024 - 0.6836%
8. 1/128  - 0.7812%

## Dragon Type Physical - v1.1.1:

Simple swap for Dragon type to be considered Physical. This **does not** do any stat rebalancing of any Pokémon, just swaps the typing. (e.g. Salamence will benefit significantly, Latios will lose out).

### Implemented Changes:
* All changes already present in Base Patch.
* Dragon type Physical in battle.
* Updated text in Rustboro School to note change of Dragon typing to Physical.

## Dragon Grovyle and Sceptile - v1.1.1:

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

## Physical Dragon Grovyle and Sceptile - v1.1.1:

Combination of the two above patches for physical Dragon type and to add Dragon typing to the Treecko line. Only Grovyle and Sceptile stats rebalanced, as above no other Pokémon rebalanced (e.g. Salamence will benefit significantly, Latios will lose out).

### Implemented Changes:
* All changes already present in Base Patch.
* Dragon type Physical in battle.
* Updated text in Rustboro School to note change of Dragon typing to Physical.
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

## Enhanced Starters - v1.1.1

An expansion on the Pokémon Emerald Legacy Enhanced Project which further buffs the Hoenn Starters (and my preferred way to play!). For the most balanced version, please use the base version! This version is just to feed into the childhood nostalgia feeling of having an overpowered starter throughout the game and to catch all the starters early in the game.

### Implemented Changes
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
    * Why?: Earliest river route, also noted as "Water's Edge" Pokémon by FRLG Pokédex
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
* Grovyle and Sceptile with added Dragon Type (Feel free to fork and revert files to base if you don't want Dragon Typing!)
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
    * Lvl 65: Frenzy Plant
  * Combusken:
    * Lvl 37: Blaze Kick (in case of evolution cancellation)
    * Lvl 41: Sky Uppercut
    * Lvl 55: Hi Jump Kick
  * Blaziken:
    * Lvl  1: Rock Slide (Torchic Egg Move, for relearning)
    * Lvl 65: Blast Burn
  * Marshtomp:
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
    * Lvl 65: Hydro Cannons
  * Brendan/May give 2 Ultra Balls in addition to Poké Balls to help catch the other starters
  * 2000 extra Pokédollars at start of game to help catch the other starters

## Enhanced Starters - Dragon Physical - v1.1.1

A combination of Enhanced Starters with Physical Dragon type.

### Implemented Changes
* All changes already present in Base patch.
* All changes in optional Enhanced Starters patch.
* All changes in Physical Dragon Grovyle and Sceptile patch.

## Enhanced Credits List:
* Credit to devolov (Discord: devolov#4853) for [Only Pokemon that can Learn HM can Use Field Move so Long as HM is in Bag](https://github.com/pret/pokeemerald/wiki/Use-HMs-Without-Any-Pokemon-in-your-Party-Knowing-Them#only-pokemon-that-can-learn-hm-can-use-field-move-so-long-as-hm-is-in-bag)
* Credit to [ScyrousFX](https://www.pokecommunity.com/member.php?u=980149) for [Use Fly/Flash from party menu if Pokémon is compatible](https://www.pokecommunity.com/showpost.php?p=10420068)
* Credit to TeamAquasHideout for [EV IV Stat Editor UI](https://github.com/pret/pokeemerald/wiki/Add-a-EV---IV-Stat-Editor-UI)
* Credit to [ghoulslash](https://www.pokecommunity.com/members/ghoulslash.581824/) for [Nature Mints](https://www.pokecommunity.com/showpost.php?p=10245635&postcount=191)
* Credit to [ScyrousFX](https://www.pokecommunity.com/member.php?u=980149), [Yak Attack](https://www.pokecommunity.com/members/yak-attack.891333/), [Kurausukun](https://github.com/Kurausukun), [Zatsu](https://www.pokecommunity.com/members/zatsu.444936/)
* Source [Tweaking the count of health beeps
](https://github.com/pret/pokeemerald/wiki/Tweaking-the-count-of-health-beeps)
* Credit to [Lunos](https://www.pokecommunity.com/members/lunos.114506/) for [Swap party screen slots using Select](https://www.pokecommunity.com/showpost.php?p=10420662)
* Credit to [slawter666](https://www.pokecommunity.com/members/slawter666.109486/) and [wally-217](https://www.pokecommunity.com/members/wally-217.356904/) for [Unique surfing overworlds](https://www.pokecommunity.com/threads/unique-surfing-overworlds.415063/)
* Credit to [Kurausukun](https://github.com/Kurausukun) for [Feebas Encounter Tile Highlight](https://github.com/DizzyEggg/pokeemerald/commit/f40f1107105244850d26ab57bad928c09300b69b)
* Credit to [Hiroshi Sotomura](https://www.pokecommunity.com/members/hiroshi-sotomura.5/) for [Add routes as Fly destinations](https://www.pokecommunity.com/threads/add-routes-as-fly-destinations.440310/) as basis for flying to Secret Base.
* Credit to [voloved](https://github.com/voloved) for [*Amulet Coin Effects If Anyone In Party is Holding It](https://github.com/pret/pokeemerald/wiki/Amulet-Coin-Effects-If-Anyone-In-Party-is-Holding-It)
* Credit to [voloved](https://github.com/voloved) for [*Show Type Effectiveness In Battle Using Pre Existing Function and Disable in Option Menu](https://github.com/pret/pokeemerald/wiki/Show-Type-Effectiveness-In-Battle-Using-Pre-Existing--Function-and-Disable-in-Option-Menu)
* Credit to [Sapphire Jester](https://www.pokecommunity.com/members/sapphire-jester.747989/) for [Checking how much ash you collected with the Soot Sack](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-9#post-10222284)
* Credit to [merrp](https://www.pokecommunity.com/members/merrp.720751/) for [Pokémon followers](https://github.com/PokemonSanFran/merrp/tree/followers-expanded-id)
* Credit to [Rom Hacking Hideout](https://github.com/rh-hideout) for Ability Capsules and Shiny Charm from [pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion/)
* Credit to [voloved](https://github.com/voloved) for [Push B in wild battle moves to Run](https://github.com/pret/pokeemerald/wiki/Push-B-in-wild-battle-moves-to-Run)
* Credit to [Zeturic](https://github.com/Zeturic), [Deokishisu](https://github.com/Deokishisu) and [ScyrousFX](https://www.pokecommunity.com/member.php?u=980149) for [Move Item](https://github.com/pret/pokeemerald/wiki/Move-Item)
* Credit to Archie, Mudskip, [ghoulslash](https://www.pokecommunity.com/members/ghoulslash.581824/), [Lunos](https://www.pokecommunity.com/members/lunos.114506/), and [Grunt Lucas](https://github.com/grunt-lucas) for [New Birch's Briefcase With Fully Custom Starters](https://github.com/pret/pokeemerald/wiki/New-Birch's-Briefcase-With-Fully-Custom-Starters-by-Archie-and-Mudskip)
* Credit to [Lunos](https://www.pokecommunity.com/members/lunos.114506/) for [Make Poké Balls usable outside of battles](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-21#post-10539730)
* Credit to [voloved](https://github.com/voloved) for [Fish Will Now Always Get on Hook](https://github.com/pret/pokeemerald/wiki/Fish-Will-Now-Always-Get-on-Hook) used as base for Fish cannot escape.
* Credit to [Shinny456](https://github.com/shinny456/), [TheXaman](https://github.com/TheXaman/), [Lunos](https://www.pokecommunity.com/members/lunos.114506/) and [Zadien](https://www.pokecommunity.com/members/zadien.1134131/) for [Nickname your Pokémon from the party menu](https://github.com/pret/pokeemerald/wiki/Nickname-your-Pok%C3%A9mon-from-the-party-menu)
* Credit to [AsparagusEdu](https://www.pokecommunity.com/members/asparagusedu.459940/) for ["Move Pokémon" as first Pokemon Storage System option](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-2#post-10065761)
* Credit to [HashtagMarky](https://github.com/HashtagMarky) for [Overworld Speedup](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/wiki/Overworld-Speedup)
* Credit to [Robinlukke](https://www.pokecommunity.com/members/robinlukke.237429/) for [Register pokémon you battle at the Battle Frontier in the Pokédex](https://www.pokecommunity.com/threads/simple-modifications-directory.416647/page-12#post-10271410)
* Credit to Rain for support in creating Overgrow, Blaze, Torrent, Swarm and Magma Armor ability text appear in battle.
* Credit to Sherry for late post-game balancing.
* Thanks to [moosedude451](https://www.reddit.com/user/moosedude451/)'s [Crystal Legacy - You can FLY!](https://www.reddit.com/r/PokemonLegacy/comments/1eu3xbt/my_fanmade_minimod_of_crystal_legacy_called/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1) Fork for inspiration of adding Fly to further HM learnsets.

# Pokémon Emerald Legacy

Emerald Legacy is meant to serve as a finale to the trio of planned projects in the Legacy Trilogy led by [TheSmithPlays](https://www.youtube.com/@smithplayspokemon). It is made using the [Pokémon Emerald Disassembly](https://github.com/pret/pokeemerald) made by the [Pret](https://pret.github.io/) team. This game is focused on refining a game that is considered a classic by many people into a nostalgic but improved experience with 20+ years of hindsight. Emerald is a great game with a ton of flaws when you use that experience to really look at it under a lens. Terrible pokemon pool, Weird team building choices, A great story idea executed poorly, baffling rival decisions, and one of the worst E4s. This game with all of these problems manages to shrug them off with memorable dex additions, fantastic gym leader ace choices, abilities, no more stat xp, Battle frontier, original ideas to the series, and overall a solid game. The Legacy Project aims to take what is good in a game and improve it while bringing its flaws up to that same level. 

Keeping that nostalgic feeling is a key part of the project and thus requires us to temper our changes into things that improve the experience but don’t take you out of that original generation 3 mindset. Things like the Physical/Special Split, adding moves, adding new evolutions, or adding the fairy typing are not things you will find in this game. Instead look for improvements to the Rival storyline, Team Magma & Aqua storyline, Tons of pokemon balancing using the tools given to us in this generation, a robust post game, improved boss fights throughout the game, adjusted level curve, and so much more. We are not trying to create a new game, nor are we trying to create a “Kaizo” game that is insanely difficult. We wanted to create a modern but nostalgic version of Pokémon Emerald. So please enjoy Pokémon Emerald Legacy.


## Download and Play

* To download the patch, see [RELEASES](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy/releases) and download the zip file for the latest patch. Unzip the folder, then follow the instructions in one of the readme files in the `Patching Instructions` folder.
* To set up the repository, see [INSTALL.md](INSTALL.md).


## A complete list of features can be found here:
- [The Main Doc](https://docs.google.com/document/d/1rBSuhFmiiehghr3AQ37JwBzbLCD21TXo_SWpUUXsz9k/copy) is the primary source of info for Emerald Legacy
    - [A Website Version](https://mryakobo.github.io/poke-emerald-legacy-docs/) of this doc is now available, thanks to @ MrYakobo! Please use this if you have trouble copying/viewing the Google page.
- [The ChangeDex](https://docs.google.com/spreadsheets/d/1XyuXmMi0sodXXR8yG7_6RYDwIn4L56QNFGdcFl4PsOI/edit) remains the best source for game data, featuring reference colors for changes since Vanilla as well as some in 1.1.
    - [Sorted Encounters](https://docs.google.com/spreadsheets/d/1euQCVphGYMXH9cEX2CwEztvbxzvF9Hik6fAoxq0_e7k/edit?gid=1066205367#gid=1066205367) is a more readable version of Changedex, specifically for Pokemon locations.
- [The Trainer Doc](https://docs.google.com/spreadsheets/d/18XWOpv-q7e-xTfC9YEsDXsL6s3HANrA5T8rcMf41K-o/edit?gid=1969522899#gid=1969522899) is now ready for a full public release! It's still WIP, because there are plans to further sort the trainers by location for easier viewing, but the newest version now separates Rematches to their own tabs - a great resource for viewing all the new Match Call updates.
- [A PKHeX Fork](https://github.com/cp1835/PKHeX-EmeraldLegacy) for Emerald Legacy is now available! Special thanks to [u/Silent_Pause_2425 on Reddit](https://www.reddit.com/r/PokemonLegacy/comments/1hqlp4p/i_modified_pkhex_for_emerald_legacy/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button) for adapting this tool for the game.

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
- "Battle! Rival Wally! (Pokemon Omega Ruby/Alpha Sapphire)" - [Arrangement written by BreadMaster](https://musescore.com/user/13873941/scores/23255677/s/0sBU8r), Original Composition by Minako Adachi


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
- mxeg
	- [Fixed clock events breaking after changing the clock](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy/pull/5)
    - [Fixed Petaya and Apicot berry are displayed as costing 48BP but actually cost 3BP](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy/pull/5)
    - [Fixed after purchasing any berry, either successfully or unsuccessfully due to insufficient BP, the menu resets to held item shop instead of berry shop](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy/pull/5)
	- [Fix msgbox not disappearing for Sootopolis gentleman](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy/pull/7)
	- [Fix msgbox not disappearing after exiting BF berry shop](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy/pull/7)
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
- Exclsior
	- [Fixed Tate and Liza getting stuck on 2nd rematch](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy/pull/13)
	- [Maxie grammar fix](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy/pull/10)
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
- cromerc - [Fixed unix build issues](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy/pull/1)
- ElusiveEllie - [Fixed INSTALL.md instructions to point to correct project](https://github.com/cRz-Shadows/Pokemon_Emerald_Legacy/pull/8)
- Scyrous - [Make Move Relearner Teach Egg Moves With A Flag](https://github.com/pret/pokeemerald/wiki/Make-Move-Relearner-Teach-Egg-Moves-With-A-Flag)


### Other Credits:
- People that generally helped out with advice or otherwise
    - Idain
    - Nayru62
    - JaaShooUhh

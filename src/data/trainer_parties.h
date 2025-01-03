/*
trainer_control by surskitty
    .nickname = _("Nickname")
    .ivs[NUM_STATS] OR .iv Use .iv to assign all IVs to the same number. .ivs needs an array of six stats, in order of HP ATK DEF SPEED SPATK SPDEF; many optimal IV spreads are pre-defined in include/constants/pokemon.h
    .heldItem and .moves[MAX_MON_MOVES] are as in vanilla.
    .ability should be set to ABILITY_SLOT_1, ABILITY_SLOT_2, or ABILITY_HIDDEN for future-proofing.
    .evs[NUM_STATS] again uses the stat order. The constants provided are not player-legal.
    .ball will still allow trainer-class balls to function when unset.
    .shiny = TRUE if you want shinies :)
    .friendship should be set to TRAINER_MON_FRIENDLY or TRAINER_MON_UNFRIENDLY to adjust Return/Frustration.
*/
// Mt Chimney Hiker
static const struct TrainerMon sParty_Sawyer1[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_GRAVELER,
    }
};
// Aqua Hideout Entrance GruntM
static const struct TrainerMon sParty_GruntAquaHideout1[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_ELECTRODE,
    }
};
// Aqua Hideout B1F 3 GruntM
static const struct TrainerMon sParty_GruntAquaHideout2[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_SEADRA,
    }
};
// Aqua Hideout B1F 6 GruntM
static const struct TrainerMon sParty_GruntAquaHideout3[] = {
    {
    .iv = 0,
    .lvl = 37,
    .species = SPECIES_WAILMER,
    }
};
// Aqua Hideout Submarine Room 1 GruntM
static const struct TrainerMon sParty_GruntAquaHideout4[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_SNEASEL,
    }
};

static const struct TrainerMon sParty_GruntSeafloorCavern1[] = {
    {
    .iv = 0,
    .lvl = 44,
    .species = SPECIES_SEVIPER,
    }
};

static const struct TrainerMon sParty_GruntSeafloorCavern2[] = {
    {
    .iv = 0,
    .lvl = 44,
    .species = SPECIES_ELECTRODE,
    }
};

static const struct TrainerMon sParty_GruntSeafloorCavern3[] = {
    {
    .iv = 0,
    .lvl = 44,
    .species = SPECIES_GOLBAT,
    }
};
// Mt Pyre Interior 3F BreederF
static const struct TrainerMon sParty_Gabrielle1[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_SHUPPET,
    },
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_DUSKULL,
    },
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_NATU,
    },
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_CHIMECHO,
    }
};
//Petalburg Woods Team Aqua Grunt 
static const struct TrainerMon sParty_GruntPetalburgWoods[] = {
    {
    .iv = 0,
    .lvl = 8,
    .species = SPECIES_POOCHYENA,
    },
    {
    .iv = 0,
    .lvl = 8,
    .species = SPECIES_CARVANHA,
    }
};
// Route 121 CooltrainerM
static const struct TrainerMon sParty_Marcel[] = {
    {
    .iv = 100,
    .lvl = 32,
    .species = SPECIES_HERACROSS,
    },
    {
    .iv = 100,
    .lvl = 32,
    .species = SPECIES_GIRAFARIG,
    }
};
// Route 123 (via 122 from Mt Pyre) Bird Keeper
static const struct TrainerMon sParty_Alberto[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_XATU,
    }
};
// Route 123 (via 122 from Mt Pyre) Collector
static const struct TrainerMon sParty_Ed[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_ZANGOOSE,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_SEVIPER,
    }
};

static const struct TrainerMon sParty_GruntSeafloorCavern4[] = {
    {
    .iv = 0,
    .lvl = 44,
    .species = SPECIES_MUK,
    }
};
// Route 124 SwimmerM
static const struct TrainerMon sParty_Declan[] = {
    {
    .iv = 0,
    .lvl = 37,
    .species = SPECIES_GYARADOS,
    }
};
// Rusturf Tunnel Aqua Grunt
static const struct TrainerMon sParty_GruntRusturfTunnel[] = {
    {
    .iv = 20,
    .lvl = 11,
    .species = SPECIES_POOCHYENA,
    },
    {
    .iv = 20,
    .lvl = 11,
    .species = SPECIES_CARVANHA,
    }
};
// Weather Institute Aqua Grunt (1st floor)
static const struct TrainerMon sParty_GruntWeatherInst1[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_GOLBAT,
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_TENTACOOL,
    }
};
// Weather Institute Aqua Grunt (2nd floor double battle)
static const struct TrainerMon sParty_GruntWeatherInst2[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_TENTACOOL,
    }
};
// Weather Institute Aqua Grunt (2nd floor)
static const struct TrainerMon sParty_GruntWeatherInst3[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_GRIMER,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_VOLTORB,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_GRIMER,
    }
};
//Slateport Museum Grunt 1
static const struct TrainerMon sParty_GruntMuseum1[] = {
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_CARVANHA,
    },
    {
    .iv = 0,
    .lvl = 17,
    .species = SPECIES_ZUBAT,
    }
};
//Slateport Museum Grunt 2
static const struct TrainerMon sParty_GruntMuseum2[] = {
     {
    .iv = 0,
    .lvl = 17,
    .species = SPECIES_POOCHYENA,
    },
    {
    .iv = 0,
    .lvl = 18,
    .species = SPECIES_TENTACOOL,
    }
};
// Space Center
static const struct TrainerMon sParty_GruntSpaceCenter1[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_CAMERUPT,
    }
};
// Mt Pyre Summit Magma Grunt 1
static const struct TrainerMon sParty_GruntMtPyre1[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_CROBAT,
    }
};
// Mt Pyre Summit Aqua Grunt 1
static const struct TrainerMon sParty_GruntMtPyre2[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_SHARPEDO,
    }
};
// UNUSED Mt Pyre Summit Aqua GruntM 3 (Double Battle w GruntF)
static const struct TrainerMon sParty_GruntMtPyre3[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_SEVIPER,
    }
};
// Weather Institute Aqua GruntF (1st floor)
static const struct TrainerMon sParty_GruntWeatherInst4[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_SEVIPER,
    }
};
// Aqua Hideout B1F 3 GruntF
static const struct TrainerMon sParty_GruntAquaHideout5[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_MUK,
    }
};
// Aqua Hideout Submarine Room 4 GruntF (Double)
static const struct TrainerMon sParty_GruntAquaHideout6[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_GOLBAT,
    }
};
// Route 123 (via 122 from Mt Pyre) Expert
static const struct TrainerMon sParty_Fredrick[] = {
    {
    .iv = 100,
    .lvl = 32,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = 100,
    .lvl = 34,
    .species = SPECIES_MACHOKE,
    }
};
// Aqua Hideout Aqua Admin 
static const struct TrainerMon sParty_Matt[] = {
    {
    .iv = 150,
    .lvl = 38,
    .species = SPECIES_ELECTRODE,
    .moves = {MOVE_RAIN_DANCE, MOVE_THUNDER, MOVE_EXPLOSION, MOVE_MIRROR_COAT}
    },
    {
    .iv = 150,
    .lvl = 39,
    .species = SPECIES_CRAWDAUNT,
    .moves = {MOVE_CRABHAMMER, MOVE_KNOCK_OFF, MOVE_ICE_BEAM, MOVE_BRICK_BREAK}
    },
    {
    .iv = 150,
    .lvl = 38,
    .species = SPECIES_MACHAMP,
    .moves = {MOVE_BODY_SLAM, MOVE_SUBMISSION, MOVE_ROCK_TOMB, MOVE_FOCUS_ENERGY}
    },
    {
    .iv = 190,
    .lvl = 40,
    .species = SPECIES_HUNTAIL,
    .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_CRUNCH, MOVE_SURF}
    }
};
// Mt Pyre Interior 2f Blackbelt
static const struct TrainerMon sParty_Zander[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_HARIYAMA,
    }
};
// Weather Institute Aqua Admin 
static const struct TrainerMon sParty_ShellyWeatherInstitute[] = {
    {
    .iv = 50,
    .lvl = 32,
    .species = SPECIES_MIGHTYENA,
    .moves = {MOVE_BITE, MOVE_TAKE_DOWN, MOVE_DIG, MOVE_SCARY_FACE}
    },
    {
    .iv = 50,
    .lvl = 31,
    .species = SPECIES_SEVIPER,
    .moves = {MOVE_POISON_FANG, MOVE_IRON_TAIL, MOVE_GLARE, MOVE_CRUNCH}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_GOREBYSS,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_PSYCHIC, MOVE_WATER_PULSE, MOVE_AMNESIA}
    }
};
// Aqua Admin Seafloor Cavern
static const struct TrainerMon sParty_ShellySeafloorCavern[] = {
    {
    .iv = 100,
    .lvl = 44,
    .species = SPECIES_SEVIPER,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_POISON_TAIL, MOVE_POISON_FANG, MOVE_IRON_TAIL, MOVE_GLARE}
    },
    {
    .iv = 100,
    .lvl = 44,
    .species = SPECIES_CASTFORM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WEATHER_BALL, MOVE_RAIN_DANCE, MOVE_HEADBUTT, MOVE_AURORA_BEAM}
    },
    {
    .iv = 100,
    .lvl = 45,
    .species = SPECIES_GOREBYSS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_PSYCHIC, MOVE_HYDRO_PUMP, MOVE_AMNESIA}
    }
};
// Aqua Leader Seafloor Cavern
static const struct TrainerMon sParty_Archie[] = {
    {
    .iv = 150,
    .lvl = 46,
    .species = SPECIES_MIGHTYENA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SUPER_FANG, MOVE_CRUNCH, MOVE_TAKE_DOWN, MOVE_ROAR}
    },
    {
    .iv = 150,
    .lvl = 45,
    .species = SPECIES_WAILORD,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_SPOUT, MOVE_AMNESIA, MOVE_SURF, MOVE_REST}
    },
    {
    .iv = 150,
    .lvl = 46,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_VITAL_THROW, MOVE_KNOCK_OFF, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB}
    },
    {
    .iv = 150,
    .lvl = 46,
    .species = SPECIES_CROBAT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_AIR_CUTTER, MOVE_BITE, MOVE_SLUDGE_BOMB, MOVE_HAZE}
    },
    {
    .iv = 255,
    .lvl = 47,
    .species = SPECIES_SHARPEDO,
    .heldItem = ITEM_LIECHI_BERRY,
    .moves = {MOVE_SURF, MOVE_CRUNCH, MOVE_SLASH, MOVE_ICE_BEAM}
    }
};
// Mt Pyre Interior 2F Hex Maniac
static const struct TrainerMon sParty_Leah[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_GRUMPIG,
    }
};
// Route 103 Aroma Lady
static const struct TrainerMon sParty_Daisy[] = {
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_ROSELIA,
    }
};
//Route 118 Mauville Aroma Lady
static const struct TrainerMon sParty_Rose1[] = {
    {
    .iv = 0,
    .lvl = 17,
    .species = SPECIES_ODDISH,
    },
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = 0,
    .lvl = 18,
    .species = SPECIES_ROSELIA,
    }
};
// Victory Road CooltrainerM
static const struct TrainerMon sParty_Felix[] = {
    {
    .iv = 0,
    .lvl = 46,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_ROLLING_KICK, MOVE_NONE, MOVE_NONE}
    },
    {
    .iv = 0,
    .lvl = 46,
    .species = SPECIES_SWALOT,
    .moves = {MOVE_SLUDGE_BOMB, MOVE_YAWN, MOVE_BODY_SLAM, MOVE_NONE}
    },
    {
    .iv = 0,
    .lvl = 46,
    .species = SPECIES_CLAYDOL,
    .moves = {MOVE_SKILL_SWAP, MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_NONE}
    }
};
// Route 123 (via 118 from mauville) Aroma Lady
static const struct TrainerMon sParty_Violet[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_GLOOM,
    }
};

static const struct TrainerMon sParty_Rose2[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Rose3[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Rose4[] = {
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = 0,
    .lvl = 31,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Rose5[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_VILEPLUME,
    },
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_ROSELIA,
    }
};
//Route 111 Desert Ruin Maniac 1
static const struct TrainerMon sParty_Dusty1[] = {
    {
    .iv = 50,
    .lvl = 29,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_SLASH}
    }
};
// Route 120 Ruin Maniac
static const struct TrainerMon sParty_Chip[] = {
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_BALTOY,
    .moves = {MOVE_PSYBEAM, MOVE_SELF_DESTRUCT, MOVE_SANDSTORM, MOVE_ANCIENT_POWER}
    },
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_SANDSHREW,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    },
    {
    .iv = 50,
    .lvl = 31,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_ROCK_TOMB}
    }
};
// Route 105 Ruin Maniac
static const struct TrainerMon sParty_Foster[] = {
    {
    .iv = 100,
    .lvl = 28,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    },
    {
    .iv = 100,
    .lvl = 28,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};

static const struct TrainerMon sParty_Dusty2[] = {
    {
    .iv = 60,
    .lvl = 31,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};

static const struct TrainerMon sParty_Dusty3[] = {
    {
    .iv = 70,
    .lvl = 33,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};

static const struct TrainerMon sParty_Dusty4[] = {
    {
    .iv = 80,
    .lvl = 36,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};

static const struct TrainerMon sParty_Dusty5[] = {
    {
    .iv = 90,
    .lvl = 39,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SLASH, MOVE_SAND_ATTACK, MOVE_POISON_STING}
    }
};
//Route 111 Mid Interviewer
static const struct TrainerMon sParty_GabbyAndTy1[] = {
    {
    .iv = 50,
    .lvl = 22,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = 50,
    .lvl = 22,
    .species = SPECIES_WHISMUR,
    }
};
//Route 118 East Interviewer
static const struct TrainerMon sParty_GabbyAndTy2[] = {
    {
    .iv = 100,
    .lvl = 28,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = 100,
    .lvl = 28,
    .species = SPECIES_LOUDRED,
    }
};
// Route 120 Interviewer
static const struct TrainerMon sParty_GabbyAndTy3[] = {
    {
    .iv = 150,
    .lvl = 33,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = 150,
    .lvl = 33,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_GabbyAndTy4[] = {
    {
    .iv = 200,
    .lvl = 35,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = 200,
    .lvl = 35,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_GabbyAndTy5[] = {
    {
    .iv = 250,
    .lvl = 38,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = 250,
    .lvl = 38,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_GabbyAndTy6[] = {
    {
    .iv = 250,
    .lvl = 42,
    .species = SPECIES_MAGNETON,
    .moves = {MOVE_SONIC_BOOM, MOVE_THUNDER_WAVE, MOVE_METAL_SOUND, MOVE_THUNDERBOLT}
    },
    {
    .iv = 250,
    .lvl = 42,
    .species = SPECIES_EXPLOUD,
    .moves = {MOVE_ASTONISH, MOVE_STOMP, MOVE_SUPERSONIC, MOVE_HYPER_VOICE}
    }
};
// Route 109 TuberF 2 (Potential Double Battle with Chandler)
static const struct TrainerMon sParty_Lola1[] = {
    {
    .iv = 10,
    .lvl = 12,
    .species = SPECIES_AZURILL,
    },
    {
    .iv = 10,
    .lvl = 14,
    .species = SPECIES_MARILL,
    }
};
//Route 109 Surf TuberF 1
static const struct TrainerMon sParty_Austina[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_AZUMARILL,
    }
};
//Route 109 Surf TuberF 2
static const struct TrainerMon sParty_Gwen[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_AZUMARILL,
    }
};

static const struct TrainerMon sParty_Lola2[] = {
    {
    .iv = 10,
    .lvl = 26,
    .species = SPECIES_MARILL,
    },
    {
    .iv = 10,
    .lvl = 26,
    .species = SPECIES_AZUMARILL,
    }
};

static const struct TrainerMon sParty_Lola3[] = {
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_AZUMARILL,
    }
};

static const struct TrainerMon sParty_Lola4[] = {
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_AZUMARILL,
    }
};

static const struct TrainerMon sParty_Lola5[] = {
    {
    .iv = 40,
    .lvl = 35,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = 40,
    .lvl = 35,
    .species = SPECIES_AZUMARILL,
    }
};
// Route 109 TuberM 1 (Potential Double Battle with Edmond or Hailey)
static const struct TrainerMon sParty_Ricky1[] = {
    {
    .iv = 10,
    .lvl = 14,
    .species = SPECIES_ZIGZAGOON,
    .moves = {MOVE_SAND_ATTACK, MOVE_HEADBUTT, MOVE_TAIL_WHIP, MOVE_SURF}
    }
};
// Route 109 Seashore House TuberM
static const struct TrainerMon sParty_Simon[] = {
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_CORPHISH,
    },
    {
    .iv = 0,
    .lvl = 14,
    .species = SPECIES_PSYDUCK,
    }
};
// Abandoned Ship TuberM
static const struct TrainerMon sParty_Charlie[] = {
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_HEADBUTT, MOVE_SHADOW_BALL, MOVE_TAIL_WHIP, MOVE_SURF}
    }
};

static const struct TrainerMon sParty_Ricky2[] = {
    {
    .iv = 10,
    .lvl = 27,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_SAND_ATTACK, MOVE_PIN_MISSILE, MOVE_TAIL_WHIP, MOVE_SURF}
    }
};

static const struct TrainerMon sParty_Ricky3[] = {
    {
    .iv = 20,
    .lvl = 30,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_SAND_ATTACK, MOVE_PIN_MISSILE, MOVE_TAIL_WHIP, MOVE_SURF}
    }
};

static const struct TrainerMon sParty_Ricky4[] = {
    {
    .iv = 30,
    .lvl = 33,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_SAND_ATTACK, MOVE_PIN_MISSILE, MOVE_TAIL_WHIP, MOVE_SURF}
    }
};

static const struct TrainerMon sParty_Ricky5[] = {
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_SAND_ATTACK, MOVE_PIN_MISSILE, MOVE_TAIL_WHIP, MOVE_SURF}
    }
};
//Petalburg Gym CooltrainerM Speed Room
static const struct TrainerMon sParty_Randall[] = {
    {
    .iv = 255,
    .lvl = 30,
    .species = SPECIES_SWELLOW,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_QUICK_ATTACK, MOVE_AGILITY, MOVE_WING_ATTACK, MOVE_FACADE}
    }
};
//Petalburg Gym CooltrainerM Confusion Room
static const struct TrainerMon sParty_Parker[] = {
    {
    .iv = 255,
    .lvl = 30,
    .species = SPECIES_SPINDA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TEETER_DANCE, MOVE_DIZZY_PUNCH, MOVE_FAINT_ATTACK, MOVE_NONE}
    }
};
//Petalburg Gym CooltrainerM Recovery Room
static const struct TrainerMon sParty_George[] = {
    {
    .iv = 255,
    .lvl = 30,
    .species = SPECIES_SLAKOTH,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_SLACK_OFF, MOVE_COUNTER, MOVE_SHADOW_BALL, MOVE_NONE}
    }
};
//Petalburg Gym CooltrainerM Berke
static const struct TrainerMon sParty_Berke[] = {
    {
    .iv = 255,
    .lvl = 30,
    .species = SPECIES_VIGOROTH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FOCUS_ENERGY, MOVE_SLASH, MOVE_FAINT_ATTACK, MOVE_NONE}
    }
};
// Route 123 (via 122 from Mt Pyre) CooltrainerM
static const struct TrainerMon sParty_Braxton[] = {
    {
    .iv = 100,
    .lvl = 31,
    .species = SPECIES_SWELLOW,
    .moves = {MOVE_FOCUS_ENERGY, MOVE_QUICK_ATTACK, MOVE_WING_ATTACK, MOVE_ENDEAVOR}
    },
    {
    .iv = 100,
    .lvl = 32,
    .species = SPECIES_TRAPINCH,
    .moves = {MOVE_BITE, MOVE_DIG, MOVE_FAINT_ATTACK, MOVE_SAND_TOMB}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_WAILMER,
    .moves = {MOVE_ROLLOUT, MOVE_WHIRLPOOL, MOVE_ASTONISH, MOVE_WATER_PULSE}
    },
    {
    .iv = 100,
    .lvl = 32,
    .species = SPECIES_MAGNETON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUPERSONIC, MOVE_THUNDER_WAVE, MOVE_SONIC_BOOM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_SHIFTRY,
    .moves = {MOVE_GIGA_DRAIN, MOVE_FAINT_ATTACK, MOVE_DOUBLE_TEAM, MOVE_SWAGGER}
    }
};
// Trick House 8
static const struct TrainerMon sParty_Vincent[] = {
    {
    .iv = 100,
    .lvl = 52,
    .species = SPECIES_BANETTE,
    },
    {
    .iv = 100,
    .lvl = 51,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = 100,
    .lvl = 52,
    .species = SPECIES_SHARPEDO,
    }
};
// Trick House 8
static const struct TrainerMon sParty_Leroy[] = {
    {
    .iv = 100,
    .lvl = 50,
    .species = SPECIES_MAWILE,
    },
    {
    .iv = 100,
    .lvl = 52,
    .species = SPECIES_STARMIE,
    },
    {
    .iv = 100,
    .lvl = 50,
    .species = SPECIES_FLYGON,
    }
};
// Route 111 Northern End
static const struct TrainerMon sParty_Wilton1[] = {
    {
    .iv = 100,
    .lvl = 20,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = 100,
    .lvl = 21,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = 100,
    .lvl = 20,
    .species = SPECIES_MAKUHITA,
    }
};
// Victory Road CooltrainerM
static const struct TrainerMon sParty_Edgar[] = {
    {
    .iv = 100,
    .lvl = 48,
    .species = SPECIES_CACTURNE,
    },
    {
    .iv = 100,
    .lvl = 48,
    .species = SPECIES_AGGRON,
    }
};
// Victory Road CooltrainerM
static const struct TrainerMon sParty_Albert[] = {
    {
    .iv = 100,
    .lvl = 48,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = 100,
    .lvl = 48,
    .species = SPECIES_MUK,
    }
};
// Victory Road CooltrainerM
static const struct TrainerMon sParty_Samuel[] = {
    {
    .iv = 100,
    .lvl = 46,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 100,
    .lvl = 47,
    .species = SPECIES_MAWILE,
    },
    {
    .iv = 100,
    .lvl = 46,
    .species = SPECIES_ALAKAZAM,
    }
};
// Victory Road CooltrainerM Winstrate
static const struct TrainerMon sParty_Vito[] = {
    {
    .iv = 200,
    .lvl = 47,
    .species = SPECIES_SWELLOW,
    .moves = {MOVE_STEEL_WING, MOVE_ENDEAVOR, MOVE_AERIAL_ACE, MOVE_FACADE}
    },
    {
    .iv = 150,
    .lvl = 46,
    .species = SPECIES_ALAKAZAM,
    .moves = {MOVE_SHOCK_WAVE, MOVE_RECOVER, MOVE_CALM_MIND, MOVE_PSYCHIC}
    },
    {
    .iv = 200,
    .lvl = 47,
    .species = SPECIES_MANECTRIC,
    .moves = {MOVE_SHADOW_BALL, MOVE_CHARGE, MOVE_THUNDERBOLT, MOVE_CRUNCH}
    },
    {
    .iv = 220,
    .lvl = 48,
    .species = SPECIES_SHIFTRY,
    .moves = {MOVE_FAINT_ATTACK, MOVE_FAKE_OUT, MOVE_LEAF_BLADE, MOVE_EXTRASENSORY}
    }
};
// Victory Road CooltrainerM
static const struct TrainerMon sParty_Owen[] = {
    {
    .iv = 100,
    .lvl = 47,
    .species = SPECIES_KECLEON,
    },
    {
    .iv = 100,
    .lvl = 46,
    .species = SPECIES_GOLEM,
    },
    {
    .iv = 100,
    .lvl = 45,
    .species = SPECIES_WAILORD,
    }
};

static const struct TrainerMon sParty_Wilton2[] = {
    {
    .iv = 110,
    .lvl = 26,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = 110,
    .lvl = 26,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = 110,
    .lvl = 26,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Wilton3[] = {
    {
    .iv = 120,
    .lvl = 29,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = 120,
    .lvl = 29,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = 120,
    .lvl = 29,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Wilton4[] = {
    {
    .iv = 130,
    .lvl = 32,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = 130,
    .lvl = 32,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = 130,
    .lvl = 32,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Wilton5[] = {
    {
    .iv = 140,
    .lvl = 35,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = 140,
    .lvl = 35,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = 140,
    .lvl = 35,
    .species = SPECIES_HARIYAMA,
    }
};
// Route 133 CooltrainerM
static const struct TrainerMon sParty_Warren[] = {
    {
    .iv = 100,
    .lvl = 43,
    .species = SPECIES_GOLEM,
    },
    {
    .iv = 100,
    .lvl = 43,
    .species = SPECIES_LAIRON,
    },
    {
    .iv = 100,
    .lvl = 43,
    .species = SPECIES_SHIFTRY,
    }
};
//Petalburg Gym CooltrainerF Accuracy Room
static const struct TrainerMon sParty_Mary[] = {
    {
    .iv = 255,
    .lvl = 30,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FAINT_ATTACK, MOVE_SHOCK_WAVE, MOVE_SWIFT, MOVE_NONE}
    }
};
//Petalburg Gym CooltrainerF Defense Room
static const struct TrainerMon sParty_Alexia[] = {
    {
    .iv = 255,
    .lvl = 30,
    .species = SPECIES_WIGGLYTUFF,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DEFENSE_CURL, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_NONE}
    }
};
//Petalburg Gym CooltrainerF Strength Room
static const struct TrainerMon sParty_Jody[] = {
    {
    .iv = 255,
    .lvl = 30,
    .species = SPECIES_ZANGOOSE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SWORDS_DANCE, MOVE_SLASH, MOVE_NONE, MOVE_NONE}
    }
};
// Route 123 (via 122 from Mt Pyre) CooltrainerF
static const struct TrainerMon sParty_Wendy[] = {
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_MAWILE,
    .moves = {MOVE_BATON_PASS, MOVE_FAINT_ATTACK, MOVE_FAKE_TEARS, MOVE_BITE}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_MEGA_DRAIN, MOVE_MAGICAL_LEAF, MOVE_GRASS_WHISTLE, MOVE_LEECH_SEED}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_PELIPPER,
    .moves = {MOVE_FLY, MOVE_WATER_PULSE, MOVE_MIST, MOVE_NONE}
    }
};
// Trick House 8
static const struct TrainerMon sParty_Keira[] = {
    {
    .iv = 100,
    .lvl = 50,
    .species = SPECIES_AGGRON,
    },
    {
    .iv = 100,
    .lvl = 50,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = 100,
    .lvl = 50,
    .species = SPECIES_MILOTIC,
    }
};
// Route 111 Northern End
static const struct TrainerMon sParty_Brooke1[] = {
    {
    .iv = 100,
    .lvl = 21,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = 100,
    .lvl = 21,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = 100,
    .lvl = 21,
    .species = SPECIES_ROSELIA,
    }
};
// Route 120 CooltrainerF
static const struct TrainerMon sParty_Jennifer[] = {
    {
    .iv = 200,
    .lvl = 33,
    .species = SPECIES_SWALOT,
    }
};
// Victory Road CooltrainerF
static const struct TrainerMon sParty_Hope[] = {
    {
    .iv = 100,
    .lvl = 48,
    .species = SPECIES_ROSELIA,
    }
};
// Victory Road CooltrainerF
static const struct TrainerMon sParty_Shannon[] = {
    {
    .iv = 100,
    .lvl = 49,
    .species = SPECIES_CLAYDOL,
    }
};
// Victory Road CooltrainerF
static const struct TrainerMon sParty_Michelle[] = {
    {
    .iv = 100,
    .lvl = 47,
    .species = SPECIES_TORKOAL,
    },
    {
    .iv = 100,
    .lvl = 47,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = 100,
    .lvl = 47,
    .species = SPECIES_LUDICOLO,
    }
};
// Victory Road CooltrainerF
static const struct TrainerMon sParty_Caroline[] = {
    {
    .iv = 100,
    .lvl = 47,
    .species = SPECIES_SKARMORY,
    },
    {
    .iv = 100,
    .lvl = 47,
    .species = SPECIES_SABLEYE,
    }
};
// Victory Road CooltrainerF
static const struct TrainerMon sParty_Julie[] = {
    {
    .iv = 100,
    .lvl = 46,
    .species = SPECIES_SANDSLASH,
    },
    {
    .iv = 100,
    .lvl = 46,
    .species = SPECIES_NINETALES,
    },
    {
    .iv = 100,
    .lvl = 46,
    .species = SPECIES_TROPIUS,
    }
};

static const struct TrainerMon sParty_Brooke2[] = {
    {
    .iv = 110,
    .lvl = 26,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 110,
    .lvl = 26,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = 110,
    .lvl = 26,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Brooke3[] = {
    {
    .iv = 120,
    .lvl = 29,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 120,
    .lvl = 29,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = 120,
    .lvl = 29,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Brooke4[] = {
    {
    .iv = 130,
    .lvl = 32,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 130,
    .lvl = 32,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = 130,
    .lvl = 32,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Brooke5[] = {
    {
    .iv = 140,
    .lvl = 34,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 140,
    .lvl = 34,
    .species = SPECIES_CAMERUPT,
    },
    {
    .iv = 140,
    .lvl = 34,
    .species = SPECIES_ROSELIA,
    }
};
// Trick Room 7
static const struct TrainerMon sParty_Patricia[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_BANETTE,
    },
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_LUNATONE,
    }
};
// Route 123 (via 122 from Mt Pyre) Hex Maniac
static const struct TrainerMon sParty_Kindra[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_DUSKULL,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_SHUPPET,
    }
};
// Route 121 Hex Maniac
static const struct TrainerMon sParty_Tammy[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_DUSKULL,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_SHUPPET,
    }
};
// Mt Pyre Interior 6F Hex Maniac
static const struct TrainerMon sParty_Valerie1[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_SABLEYE,
    }
};
// Mt Pyre Interior 4F Hex Maniac
static const struct TrainerMon sParty_Tasha[] = {
    {
    .iv = 50,
    .lvl = 34,
    .species = SPECIES_SHUPPET,
    }
};

static const struct TrainerMon sParty_Valerie2[] = {
    {
    .iv = 10,
    .lvl = 35,
    .species = SPECIES_SABLEYE,
    },
    {
    .iv = 10,
    .lvl = 35,
    .species = SPECIES_GRUMPIG,
    }
};

static const struct TrainerMon sParty_Valerie3[] = {
    {
    .iv = 20,
    .lvl = 37,
    .species = SPECIES_GRUMPIG,
    },
    {
    .iv = 20,
    .lvl = 37,
    .species = SPECIES_SABLEYE,
    }
};

static const struct TrainerMon sParty_Valerie4[] = {
    {
    .iv = 30,
    .lvl = 40,
    .species = SPECIES_GRUMPIG,
    },
    {
    .iv = 30,
    .lvl = 40,
    .species = SPECIES_SABLEYE,
    }
};

static const struct TrainerMon sParty_Valerie5[] = {
    {
    .iv = 40,
    .lvl = 42,
    .species = SPECIES_DUSCLOPS,
    },
    {
    .iv = 40,
    .lvl = 42,
    .species = SPECIES_SABLEYE,
    },
    {
    .iv = 40,
    .lvl = 42,
    .species = SPECIES_GRUMPIG,
    }
};
//Route 104 Lady
static const struct TrainerMon sParty_Cindy1[] = {
    {
    .iv = 0,
    .lvl = 7,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_NUGGET
    }
};
//Sootopolis Gym Lady 1 (Middle Level - Double Battle w Annika)
static const struct TrainerMon sParty_Daphne[] = {
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_LUVDISC,
    .heldItem = ITEM_BRIGHT_POWDER,
    .moves = {MOVE_ATTRACT, MOVE_LOVELY_KISS, MOVE_RAIN_DANCE, MOVE_WATER_PULSE}
    },
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_LUVDISC,
    .heldItem = ITEM_BRIGHT_POWDER,
    .moves = {MOVE_ATTRACT, MOVE_LOVELY_KISS, MOVE_RAIN_DANCE, MOVE_WATER_PULSE}
    }
};
// Space Center
static const struct TrainerMon sParty_GruntSpaceCenter2[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_GOLEM,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_MAGCARGO,
    }
};

static const struct TrainerMon sParty_Cindy2[] = {
    {
    .iv = 0,
    .lvl = 11,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_NONE, MOVE_NONE}
    }
};
//Sootopolis Gym Lady 2 (Highest Level - Double Battle w Bridget)
static const struct TrainerMon sParty_Brianna[] = {
    {
    .iv = 150,
    .lvl = 45,
    .species = SPECIES_SEAKING,
    .heldItem = ITEM_NUGGET
    }
};
// SS Tidal Aroma Lady (nat dex)
static const struct TrainerMon sParty_Naomi[] = {
    {
    .iv = 255,
    .lvl = 53,
    .species = SPECIES_SUNFLORA,
    .heldItem = ITEM_SUN_STONE
    },
    {
    .iv = 255,
    .lvl = 53,
    .species = SPECIES_SKIPLOOM,
    .heldItem = ITEM_NONE
    },
};

static const struct TrainerMon sParty_Cindy3[] = {
    {
    .iv = 10,
    .lvl = 27,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_DOUBLE_SLAP, MOVE_SING, MOVE_FAINT_ATTACK, MOVE_CHARM}
    }
};

static const struct TrainerMon sParty_Cindy4[] = {
    {
    .iv = 20,
    .lvl = 30,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_DOUBLE_SLAP, MOVE_SING, MOVE_FAINT_ATTACK, MOVE_CHARM}
    }
};

static const struct TrainerMon sParty_Cindy5[] = {
    {
    .iv = 30,
    .lvl = 33,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_SING, MOVE_FAINT_ATTACK, MOVE_SAND_ATTACK}
    }
};

static const struct TrainerMon sParty_Cindy6[] = {
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_SING, MOVE_FAINT_ATTACK, MOVE_SAND_ATTACK}
    }
};
// Mt Chimney Beauty
static const struct TrainerMon sParty_Melissa[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_AZUMARILL,
    }
};
// Mt Chimney  Beauty 2
static const struct TrainerMon sParty_Sheila[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_BRELOOM,
    }
};
// Mt Chimney Beauty 3
static const struct TrainerMon sParty_Shirley[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_SPOINK,
    }
};
// Route 121 Beauty
static const struct TrainerMon sParty_Jessica1[] = {
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_BIND, MOVE_LICK, MOVE_FURY_SWIPES, MOVE_FAINT_ATTACK}
    },
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_SEVIPER,
    .moves = {MOVE_POISON_TAIL, MOVE_SCREECH, MOVE_GLARE, MOVE_CRUNCH}
    }
};
//Sootopolis Gym Beauty 1 (Lowest Level)
static const struct TrainerMon sParty_Connie[] = {
    {
    .iv = 150,
    .lvl = 44,
    .species = SPECIES_WALREIN,
    }
};
//Sootopolis Gym Beauty 4 (Highest Level - Double Battle w Brianna)
static const struct TrainerMon sParty_Bridget[] = {
    {
    .iv = 150,
    .lvl = 46,
    .species = SPECIES_AZUMARILL,
    }
};
//Sootopolis Gym Beauty 3 (Highest Level - Double Battle w Bethany)
static const struct TrainerMon sParty_Olivia[] = {
    {
    .iv = 100,
    .lvl = 45,
    .species = SPECIES_CLAMPERL,
    .moves = {MOVE_IRON_DEFENSE, MOVE_WHIRLPOOL, MOVE_RAIN_DANCE, MOVE_WATER_PULSE}
    },
    {
    .iv = 100,
    .lvl = 45,
    .species = SPECIES_CRAWDAUNT,
    .moves = {MOVE_TAUNT, MOVE_CRABHAMMER, MOVE_WATER_PULSE, MOVE_NONE}
    },
    {
    .iv = 100,
    .lvl = 45,
    .species = SPECIES_LUDICOLO,
    .moves = {MOVE_UPROAR, MOVE_FURY_SWIPES, MOVE_FAKE_OUT, MOVE_WATER_PULSE}
    }
};
//Sootopolis Gym Beauty 2 (Highest Level - Double Battle w Crissy)
static const struct TrainerMon sParty_Tiffany[] = {
    {
    .iv = 100,
    .lvl = 45,
    .species = SPECIES_SHARPEDO,
    },
    {
    .iv = 100,
    .lvl = 46,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Jessica2[] = {
    {
    .iv = 10,
    .lvl = 35,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_BIND, MOVE_LICK, MOVE_FURY_SWIPES, MOVE_FAINT_ATTACK}
    },
    {
    .iv = 10,
    .lvl = 35,
    .species = SPECIES_SEVIPER,
    .moves = {MOVE_POISON_TAIL, MOVE_SCREECH, MOVE_GLARE, MOVE_CRUNCH}
    }
};

static const struct TrainerMon sParty_Jessica3[] = {
    {
    .iv = 20,
    .lvl = 38,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_BIND, MOVE_LICK, MOVE_FURY_SWIPES, MOVE_FAINT_ATTACK}
    },
    {
    .iv = 20,
    .lvl = 38,
    .species = SPECIES_SEVIPER,
    .moves = {MOVE_POISON_TAIL, MOVE_SCREECH, MOVE_GLARE, MOVE_CRUNCH}
    }
};

static const struct TrainerMon sParty_Jessica4[] = {
    {
    .iv = 30,
    .lvl = 41,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_BIND, MOVE_LICK, MOVE_FURY_SWIPES, MOVE_FAINT_ATTACK}
    },
    {
    .iv = 30,
    .lvl = 41,
    .species = SPECIES_SEVIPER,
    .moves = {MOVE_POISON_TAIL, MOVE_SCREECH, MOVE_GLARE, MOVE_CRUNCH}
    }
};

static const struct TrainerMon sParty_Jessica5[] = {
    {
    .iv = 40,
    .lvl = 44,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_BIND, MOVE_LICK, MOVE_FURY_SWIPES, MOVE_FAINT_ATTACK}
    },
    {
    .iv = 40,
    .lvl = 44,
    .species = SPECIES_SEVIPER,
    .moves = {MOVE_POISON_TAIL, MOVE_SCREECH, MOVE_GLARE, MOVE_CRUNCH}
    }
};
//Route 104 North Rich Boy
static const struct TrainerMon sParty_Winston1[] = {
    {
    .iv = 0,
    .lvl = 7,
    .species = SPECIES_SLAKOTH,
    .heldItem = ITEM_NUGGET
    }
};
// Route 133 ExpertF
static const struct TrainerMon sParty_Mollie[] = {
    {
    .iv = 0,
    .lvl = 44,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 200,
    .lvl = 45,
    .species = SPECIES_MEDICHAM,
    }
};
// SS Tidal Rich Boy (nat dex)
static const struct TrainerMon sParty_Garret[] = {
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_CHANSEY,
    .heldItem = ITEM_NUGGET
    },
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_PERSIAN,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Winston2[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_VIGOROTH,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Winston3[] = {
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_VIGOROTH,
    .heldItem = ITEM_NUGGET
    }
};

static const struct TrainerMon sParty_Winston4[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_VIGOROTH,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_FURY_SWIPES, MOVE_FAINT_ATTACK, MOVE_YAWN, MOVE_THUNDERBOLT}
    }
};

static const struct TrainerMon sParty_Winston5[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_NUGGET,
    .moves = {MOVE_FURY_SWIPES, MOVE_FAINT_ATTACK, MOVE_YAWN, MOVE_THUNDERBOLT}
    }
};
// Route 114 Pokemaniac
static const struct TrainerMon sParty_Steve1[] = {
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_SEVIPER,
    }
};
// Abandoned Ship Beauty
static const struct TrainerMon sParty_Thalia1[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_SWABLU,
    }
};
// Mt Pyre Interior 2F Pokemaniac
static const struct TrainerMon sParty_Mark[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_RHYHORN,
    }
};
// Mt Chimney GruntF (double)
static const struct TrainerMon sParty_GruntMtChimney1[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_VULPIX,
    }
};

static const struct TrainerMon sParty_Steve2[] = {
    {
    .iv = 10,
    .lvl = 29,
    .species = SPECIES_SEVIPER
    }
};

static const struct TrainerMon sParty_Steve3[] = {
    {
    .iv = 20,
    .lvl = 31,
    .species = SPECIES_SEVIPER,
    },
    {
    .iv = 20,
    .lvl = 31,
    .species = SPECIES_RHYHORN,
    }
};

static const struct TrainerMon sParty_Steve4[] = {
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_SEVIPER,
    },
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_RHYHORN,
    }
};

static const struct TrainerMon sParty_Steve5[] = {
    {
    .iv = 40,
    .lvl = 40,
    .species = SPECIES_SEVIPER,
    },
    {
    .iv = 40,
    .lvl = 40,
    .species = SPECIES_RHYDON,
    }
};
// Route 105 SwimmerM
static const struct TrainerMon sParty_Luis[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_CARVANHA,
    }
};
// Route 105 SwimmerM
static const struct TrainerMon sParty_Dominik[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_TENTACOOL,
    }
};
// Route 106 Surf SwimmerM
static const struct TrainerMon sParty_Douglas[] = {
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_TENTACOOL,
    }
};
// Route 107 SwimmerM
static const struct TrainerMon sParty_Darrin[] = {
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_TENTACOOL,
    }
};
// Route 107 SwimmerM
static const struct TrainerMon sParty_Tony1[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_CARVANHA,
    }
};
// Route 108 SwimmerM
static const struct TrainerMon sParty_Jerome[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_TENTACRUEL,
    }
};
// Route 108 SwimmerM
static const struct TrainerMon sParty_Matthew[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_CARVANHA,
    }
};
//Route 109 Surf SwimmerM
static const struct TrainerMon sParty_David[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_CARVANHA,
    }
};
// Route 124 SwimmerM
static const struct TrainerMon sParty_Spencer[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_SEAKING,
    },
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_PELIPPER,
    }
};
// Route 124 SwimmerM
static const struct TrainerMon sParty_Roland[] = {
    {
    .iv = 0,
    .lvl = 37,
    .species = SPECIES_LANTURN,
    }
};
// Route 125 SwimmerM
static const struct TrainerMon sParty_Nolen[] = {
    {
    .iv = 0,
    .lvl = 37,
    .species = SPECIES_TENTACRUEL,
    }
};
// Route 125 SwimmerM
static const struct TrainerMon sParty_Stan[] = {
    {
    .iv = 0,
    .lvl = 37,
    .species = SPECIES_SEADRA,
    },
    {
    .iv = 0,
    .lvl = 37,
    .species = SPECIES_GYARADOS,
    }
};
// Route 126 SwimmerM
static const struct TrainerMon sParty_Barry[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_GYARADOS,
    }
};
// Route 126 SwimmerM
static const struct TrainerMon sParty_Dean[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_SHARPEDO,
    },
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_CRAWDAUNT,
    },
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_CARVANHA,
    }
};
// Route 130 SwimmerM
static const struct TrainerMon sParty_Rodney[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_GYARADOS,
    }
};
// Route 131 SwimmerM
static const struct TrainerMon sParty_Richard[] = {
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_PELIPPER,
    }
};
// Route 131 SwimmerM 
static const struct TrainerMon sParty_Herman[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_TENTACRUEL,
    }
};
// Route 130 SwimmerM (Potential Double Battle with Katie)
static const struct TrainerMon sParty_Santiago[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_WAILORD,
    }
};
// Route 132 SwimmerM
static const struct TrainerMon sParty_Gilbert[] = {
    {
    .iv = 0,
    .lvl = 44,
    .species = SPECIES_SHARPEDO,
    }
};
// Route 133 SwimmerM
static const struct TrainerMon sParty_Franklin[] = {
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_WALREIN,
    }
};
// Route 131 SwimmerM
static const struct TrainerMon sParty_Kevin[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_RELICANTH,
    }
};
// Route 134 SwimmerM
static const struct TrainerMon sParty_Jack[] = {
    {
    .iv = 0,
    .lvl = 46,
    .species = SPECIES_GYARADOS,
    }
};

static const struct TrainerMon sParty_Dudley[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_TENTACRUEL,
    }
};
// Route 124 SwimmerM
static const struct TrainerMon sParty_Chad[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_WAILMER,
    }
};

static const struct TrainerMon sParty_Tony2[] = {
    {
    .iv = 10,
    .lvl = 30,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Tony3[] = {
    {
    .iv = 20,
    .lvl = 33,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Tony4[] = {
    {
    .iv = 30,
    .lvl = 34,
    .species = SPECIES_STARYU,
    },
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Tony5[] = {
    {
    .iv = 40,
    .lvl = 37,
    .species = SPECIES_STARMIE,
    },
    {
    .iv = 40,
    .lvl = 39,
    .species = SPECIES_SHARPEDO,
    }
};
// Dewford Gym Black Belt 1 (Bottom Left)
static const struct TrainerMon sParty_Takao[] = {
    {
    .iv = 127,
    .lvl = 14,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = 127,
    .lvl = 14,
    .species = SPECIES_MACHOP,
    }
};
// Route 134 Black Belt
static const struct TrainerMon sParty_Hitoshi[] = {
    {
    .iv = 50,
    .lvl = 45,
    .species = SPECIES_HERACROSS,
    },
    {
    .iv = 50,
    .lvl = 45,
    .species = SPECIES_MACHAMP,
    },
    {
    .iv = 200,
    .lvl = 45,
    .species = SPECIES_BRELOOM,
    }
};
// Route 132 Black Belt
static const struct TrainerMon sParty_Kiyo[] = {
    {
    .iv = 100,
    .lvl = 43,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = 100,
    .lvl = 43,
    .species = SPECIES_MEDICHAM,
    },
};
// Route 115 Surf Black Belt
static const struct TrainerMon sParty_Koichi[] = {
    {
    .iv = 100,
    .lvl = 24,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = 150,
    .lvl = 30,
    .species = SPECIES_MACHOKE,
    }
};
// Route 115 Black Belt
static const struct TrainerMon sParty_Nob1[] = {
    {
    .iv = 100,
    .lvl = 26,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Nob2[] = {
    {
    .iv = 110,
    .lvl = 29,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Nob3[] = {
    {
    .iv = 120,
    .lvl = 29,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = 120,
    .lvl = 29,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Nob4[] = {
    {
    .iv = 130,
    .lvl = 31,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = 130,
    .lvl = 31,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = 130,
    .lvl = 31,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Nob5[] = {
    {
    .iv = 140,
    .lvl = 32,
    .species = SPECIES_MACHOP,
    .heldItem = ITEM_NONE
    },
    {
    .iv = 140,
    .lvl = 34,
    .species = SPECIES_MACHOKE,
    .heldItem = ITEM_NONE
    },
    {
    .iv = 140,
    .lvl = 36,
    .species = SPECIES_MACHOKE,
    .heldItem = ITEM_NONE
    },
    {
    .iv = 140,
    .lvl = 38,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_BLACK_BELT
    }
};
// Trick Room 4
static const struct TrainerMon sParty_Yuji[] = {
    {
    .iv = 100,
    .lvl = 27,
    .species = SPECIES_MEDICHAM,
    }
};
// Route 111 Northern End (Mach Bike)
static const struct TrainerMon sParty_Daisuke[] = {
    {
    .iv = 100,
    .lvl = 23,
    .species = SPECIES_MACHOP,
    }
};
// Mt Pyre Interior 5F Black Belt
static const struct TrainerMon sParty_Atsushi[] = {
    {
    .iv = 100,
    .lvl = 35,
    .species = SPECIES_HARIYAMA,
    }
};
// Mauville Gym Guitarist 1
static const struct TrainerMon sParty_Kirk[] = {
    {
    .iv = 100,
    .lvl = 20,
    .species = SPECIES_VOLTORB,
    .moves = {MOVE_ROLLOUT, MOVE_SHOCK_WAVE, MOVE_SCREECH, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = 100,
    .lvl = 20,
    .species = SPECIES_ELECTRIKE,
    .moves = {MOVE_QUICK_ATTACK, MOVE_HOWL, MOVE_SHOCK_WAVE, MOVE_LEER}
    }
};
// Aqua Hideout B1F 3 GruntF
static const struct TrainerMon sParty_GruntAquaHideout7[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_ELECTRODE,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_GOLBAT,
    }
};
// Aqua Hideout Submarine Room 4 GruntM (Double)
static const struct TrainerMon sParty_GruntAquaHideout8[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_MURKROW,
    }
};
// Mauville Gym Guitarist 2
static const struct TrainerMon sParty_Shawn[] = {
    {
    .iv = 100,
    .lvl = 19,
    .species = SPECIES_VOLTORB,
    },
    {
    .iv = 100,
    .lvl = 18,
    .species = SPECIES_MAGNEMITE,
    }
};
// Route 123 (via 122 from Mt Pyre) Guitarist
static const struct TrainerMon sParty_Fernando1[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_ELECTRODE,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_LOUDRED,
    }
};
//Route 118 Mauville Guitarist
static const struct TrainerMon sParty_Dalton1[] = {
    {
    .iv = 0,
    .lvl = 18,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = 0,
    .lvl = 19,
    .species = SPECIES_WHISMUR,
    }
};

static const struct TrainerMon sParty_Dalton2[] = {
    {
    .iv = 10,
    .lvl = 25,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = 10,
    .lvl = 25,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = 10,
    .lvl = 25,
    .species = SPECIES_MAGNEMITE,
    }
};

static const struct TrainerMon sParty_Dalton3[] = {
    {
    .iv = 20,
    .lvl = 28,
    .species = SPECIES_MAGNEMITE,
    },
    {
    .iv = 20,
    .lvl = 28,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = 20,
    .lvl = 28,
    .species = SPECIES_MAGNEMITE,
    }
};

static const struct TrainerMon sParty_Dalton4[] = {
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_LOUDRED,
    },
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_MAGNETON,
    }
};

static const struct TrainerMon sParty_Dalton5[] = {
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_MAGNETON,
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_EXPLOUD,
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_MAGNETON,
    }
};
// Lavaridge Gym Kindler 3
static const struct TrainerMon sParty_Cole[] = {
    {
    .iv = 100,
    .lvl = 27,
    .species = SPECIES_NUMEL,
    }
};
// Lavaridge Gym Kindler 1
static const struct TrainerMon sParty_Jeff[] = {
    {
    .iv = 100,
    .lvl = 26,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = 100,
    .lvl = 27,
    .species = SPECIES_SLUGMA,
    }
};
// Lavaridge Gym Kindler 4
static const struct TrainerMon sParty_Axle[] = {
    {
    .iv = 100,
    .lvl = 27,
    .species = SPECIES_NUMEL,
    }
};
// Lavaridge Gym Kindler 2
static const struct TrainerMon sParty_Jace[] = {
    {
    .iv = 100,
    .lvl = 27,
    .species = SPECIES_VULPIX,
    }
};
// Lavaridge Gym Kindler 5
static const struct TrainerMon sParty_Keegan[] = {
    {
    .iv = 120,
    .lvl = 27,
    .species = SPECIES_SLUGMA,
    }
};
// Route 114 Kindler
static const struct TrainerMon sParty_Bernie1[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_WINGULL,
    }
};

static const struct TrainerMon sParty_Bernie2[] = {
    {
    .iv = 10,
    .lvl = 26,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = 10,
    .lvl = 27,
    .species = SPECIES_PELIPPER,
    }
};

static const struct TrainerMon sParty_Bernie3[] = {
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_PELIPPER,
    }
};

static const struct TrainerMon sParty_Bernie4[] = {
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_PELIPPER,
    }
};

static const struct TrainerMon sParty_Bernie5[] = {
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_PELIPPER,
    }
};
// Route 111 Desert Camper
static const struct TrainerMon sParty_Drew[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_DIG, MOVE_SAND_ATTACK, MOVE_POISON_STING, MOVE_SLASH}
    }
};
//Route 111 Desert Camper 1 
static const struct TrainerMon sParty_Beau[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_BALTOY,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_SANDSHREW,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_TRAPINCH,
    }
};
// Route 112 South Section Camper 1
static const struct TrainerMon sParty_Larry[] = {
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_NUZLEAF,
    }
};
// Route 114 Camper 
static const struct TrainerMon sParty_Shane[] = {
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_SANDSHREW,
    },
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_NUZLEAF,
    }
};
// Trick House 3 Camper
static const struct TrainerMon sParty_Justin[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_MACHOKE,
    }
};
// Jagged Pass Camper
static const struct TrainerMon sParty_Ethan1[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_SWELLOW
    },
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_LINOONE,
    }
};
// Jagged Pass Picnicker 2
static const struct TrainerMon sParty_Autumn[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_BRELOOM,
    }
};
//Route 111 Mid Camper
static const struct TrainerMon sParty_Travis[] = {
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_SANDSHREW,
    }
};

static const struct TrainerMon sParty_Ethan2[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_SWELLOW
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_LINOONE,
    }
};

static const struct TrainerMon sParty_Ethan3[] = {
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Ethan4[] = {
    {
    .iv = 30,
    .lvl = 31,
    .species = SPECIES_SANDSHREW,
    },
    {
    .iv = 30,
    .lvl = 31,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 30,
    .lvl = 31,
    .species = SPECIES_LINOONE,
    }
};

static const struct TrainerMon sParty_Ethan5[] = {
    {
    .iv = 40,
    .lvl = 34,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 40,
    .lvl = 34,
    .species = SPECIES_SANDSLASH,
    },
    {
    .iv = 40,
    .lvl = 34,
    .species = SPECIES_LINOONE,
    }
};
// Route 119 Bug Maniac 3
static const struct TrainerMon sParty_Brent[] = {
    {
    .iv = 100,
    .lvl = 28,
    .species = SPECIES_MASQUERAIN,
    }
};
// Route 119 Bug Maniac 1
static const struct TrainerMon sParty_Donald[] = {
    {
    .iv = 100,
    .lvl = 28,
    .species = SPECIES_WURMPLE,
    },
    {
    .iv = 100,
    .lvl = 28,
    .species = SPECIES_SILCOON,
    },
    {
    .iv = 100,
    .lvl = 28,
    .species = SPECIES_BEAUTIFLY,
    }
};
// Route 119 Bug Maniac Taylor
static const struct TrainerMon sParty_Taylor[] = {
    {
    .iv = 100,
    .lvl = 27,
    .species = SPECIES_WURMPLE,
    },
    {
    .iv = 100,
    .lvl = 27,
    .species = SPECIES_CASCOON,
    },
    {
    .iv = 100,
    .lvl = 27,
    .species = SPECIES_DUSTOX,
    }
};
// Route 120 Bug Maniac
static const struct TrainerMon sParty_Jeffrey1[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_SURSKIT,
    },
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_MASQUERAIN,
    },
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_SURSKIT,
    }
};
// Route 117 Bug Maniac
static const struct TrainerMon sParty_Derek[] = {
    {
    .iv = 150,
    .lvl = 17,
    .species = SPECIES_DUSTOX,
    },
    {
    .iv = 150,
    .lvl = 17,
    .species = SPECIES_BEAUTIFLY,
    }
};

static const struct TrainerMon sParty_Jeffrey2[] = {
    {
    .iv = 10,
    .lvl = 31,
    .species = SPECIES_MASQUERAIN,
    },
    {
    .iv = 10,
    .lvl = 31,
    .species = SPECIES_MASQUERAIN,
    },
    {
    .iv = 10,
    .lvl = 31,
    .species = SPECIES_MASQUERAIN,
    }
};

static const struct TrainerMon sParty_Jeffrey3[] = {
    {
    .iv = 20,
    .lvl = 34,
    .species = SPECIES_MASQUERAIN,
    },
    {
    .iv = 20,
    .lvl = 34,
    .species = SPECIES_MASQUERAIN,
    },
    {
    .iv = 20,
    .lvl = 34,
    .species = SPECIES_MASQUERAIN,
    }
};

static const struct TrainerMon sParty_Jeffrey4[] = {
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_MASQUERAIN,
    },
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_DUSTOX,
    },
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_MASQUERAIN,
    },
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_MASQUERAIN,
    }
};

static const struct TrainerMon sParty_Jeffrey5[] = {
    {
    .iv = 40,
    .lvl = 38,
    .species = SPECIES_MASQUERAIN,
    .heldItem = ITEM_NONE
    },
    {
    .iv = 40,
    .lvl = 38,
    .species = SPECIES_DUSTOX,
    .heldItem = ITEM_NONE
    },
    {
    .iv = 40,
    .lvl = 38,
    .species = SPECIES_MASQUERAIN,
    .heldItem = ITEM_NONE
    },
    {
    .iv = 40,
    .lvl = 38,
    .species = SPECIES_MASQUERAIN,
    .heldItem = ITEM_SILVER_POWDER
    },
    {
    .iv = 40,
    .lvl = 38,
    .species = SPECIES_BEAUTIFLY,
    .heldItem = ITEM_NONE
    }
};
// Route 110 PsychicM
static const struct TrainerMon sParty_Edward[] = {
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_KADABRA,
    .moves = {MOVE_HIDDEN_POWER, MOVE_CONFUSION, MOVE_NONE, MOVE_NONE}
    }
};
// Mossdeep Gym PsychicM 1 - Entrance Room (Double Battle w Maura)
static const struct TrainerMon sParty_Preston[] = {
    {
    .iv = 100,
    .lvl = 40,
    .species = SPECIES_GARDEVOIR,
    }
};
// Mossdeep Gym PsychicM 4 - Northwest (Double Battle w Nate or Sylvia)
static const struct TrainerMon sParty_Virgil[] = {
    {
    .iv = 200,
    .lvl = 40,
    .species = SPECIES_KADABRA,
    }
};
// Mossdeep Gym PsychicM 2 - West Central (Double Battle w Samantha)
static const struct TrainerMon sParty_Blake[] = {
    {
    .iv = 100,
    .lvl = 40,
    .species = SPECIES_GIRAFARIG,
    }
};
// Mt Pyre Interior 3F PsychicM
static const struct TrainerMon sParty_William[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_RALTS,
    },
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_KIRLIA,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_GARDEVOIR,
    }
};
// Trick Room 7
static const struct TrainerMon sParty_Joshua[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_ALAKAZAM,
    },
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_SOLROCK,
    }
};
// Route 123 (via 122 with Cut) Psychic
static const struct TrainerMon sParty_Cameron1[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_SOLROCK,
    }
};

static const struct TrainerMon sParty_Cameron2[] = {
    {
    .iv = 10,
    .lvl = 36,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = 10,
    .lvl = 36,
    .species = SPECIES_SOLROCK,
    }
};

static const struct TrainerMon sParty_Cameron3[] = {
    {
    .iv = 20,
    .lvl = 38,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = 20,
    .lvl = 38,
    .species = SPECIES_SOLROCK,
    }
};

static const struct TrainerMon sParty_Cameron4[] = {
    {
    .iv = 30,
    .lvl = 41,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = 30,
    .lvl = 41,
    .species = SPECIES_SOLROCK,
    }
};

static const struct TrainerMon sParty_Cameron5[] = {
    {
    .iv = 40,
    .lvl = 45,
    .species = SPECIES_SOLROCK,
    },
    {
    .iv = 40,
    .lvl = 45,
    .species = SPECIES_ALAKAZAM,
    }
};
// Cycling Road fPsychic
static const struct TrainerMon sParty_Jaclyn[] = {
    {
    .iv = 0,
    .lvl = 19,
    .species = SPECIES_KADABRA,
    .moves = {MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE}
    }
};
// Mossdeep Gym PsychicF 4 - Northwest (Double Battle w Sylvia)
static const struct TrainerMon sParty_Hannah[] = {
    {
    .iv = 100,
    .lvl = 41,
    .species = SPECIES_ABSOL,
    }
};
// Mossdeep Gym PsychicF 2 - West Central (Double Battle w Blake)
static const struct TrainerMon sParty_Samantha[] = {
    {
    .iv = 100,
    .lvl = 41,
    .species = SPECIES_XATU,
    }
};
// Mossdeep Gym PsychicF 1 - Entrance Room (Double Battle w Preston)
static const struct TrainerMon sParty_Maura[] = {
    {
    .iv = 200,
    .lvl = 40,
    .species = SPECIES_KADABRA,
    }
};
// Mt Pyre Interior 3F PsychicF
static const struct TrainerMon sParty_Kayla[] = {
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_WOBBUFFET,
    },
    {
    .iv = 0,
    .lvl = 31,
    .species = SPECIES_XATU,
    },
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_KADABRA,
    }
};
// Trick Room 7
static const struct TrainerMon sParty_Alexis[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_GARDEVOIR,
    },
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_XATU,
    }
};
// Route 123 (via 122 from Mt Pyre) Psychic
static const struct TrainerMon sParty_Jacki1[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_LUNATONE,
    }
};

static const struct TrainerMon sParty_Jacki2[] = {
    {
    .iv = 10,
    .lvl = 34,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = 10,
    .lvl = 34,
    .species = SPECIES_LUNATONE,
    }
};

static const struct TrainerMon sParty_Jacki3[] = {
    {
    .iv = 20,
    .lvl = 37,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = 20,
    .lvl = 37,
    .species = SPECIES_LUNATONE,
    }
};

static const struct TrainerMon sParty_Jacki4[] = {
    {
    .iv = 30,
    .lvl = 40,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = 30,
    .lvl = 40,
    .species = SPECIES_LUNATONE,
    }
};

static const struct TrainerMon sParty_Jacki5[] = {
    {
    .iv = 40,
    .lvl = 45,
    .species = SPECIES_LUNATONE,
    },
    {
    .iv = 40,
    .lvl = 45,
    .species = SPECIES_ALAKAZAM,
    }
};
// Route 121 Gentleman
static const struct TrainerMon sParty_Walter1[] = {
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_MANECTRIC,
    }
};
// SS Tidal Gentleman (nat dex)
static const struct TrainerMon sParty_Micah[] = {
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_GROWLITHE,
    },
    {
    .iv = 255,
    .lvl = 52,
    .species = SPECIES_ARCANINE,
    }
};
// SS Tidal Gentleman (nat dex)
static const struct TrainerMon sParty_Thomas[] = {
    {
    .iv = 255,
    .lvl = 52,
    .species = SPECIES_TAUROS,
    }
};

static const struct TrainerMon sParty_Walter2[] = {
    {
    .iv = 10,
    .lvl = 34,
    .species = SPECIES_MANECTRIC,
    }
};

static const struct TrainerMon sParty_Walter3[] = {
    {
    .iv = 20,
    .lvl = 36,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_ODOR_SLEUTH, MOVE_FURY_SWIPES}
    },
    {
    .iv = 20,
    .lvl = 36,
    .species = SPECIES_MANECTRIC,
    .moves = {MOVE_QUICK_ATTACK, MOVE_SPARK, MOVE_ODOR_SLEUTH, MOVE_ROAR}
    }
};

static const struct TrainerMon sParty_Walter4[] = {
    {
    .iv = 30,
    .lvl = 39,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_ODOR_SLEUTH, MOVE_FURY_SWIPES}
    },
    {
    .iv = 30,
    .lvl = 39,
    .species = SPECIES_MANECTRIC,
    .moves = {MOVE_QUICK_ATTACK, MOVE_SPARK, MOVE_ODOR_SLEUTH, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Walter5[] = {
    {
    .iv = 40,
    .lvl = 41,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_ODOR_SLEUTH, MOVE_FURY_SWIPES}
    },
    {
    .iv = 40,
    .lvl = 41,
    .species = SPECIES_GOLDUCK,
    .moves = {MOVE_FURY_SWIPES, MOVE_DISABLE, MOVE_CONFUSION, MOVE_PSYCH_UP}
    },
    {
    .iv = 40,
    .lvl = 41,
    .species = SPECIES_MANECTRIC,
    .moves = {MOVE_QUICK_ATTACK, MOVE_SPARK, MOVE_ODOR_SLEUTH, MOVE_ROAR}
    }
};
// Elite Four Sydney
static const struct TrainerMon sParty_Sidney[] = {
    {
    .iv = 250,
    .lvl = 51,
    .species = SPECIES_MIGHTYENA,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_CRUNCH, MOVE_SUPER_FANG, MOVE_YAWN, MOVE_SCARY_FACE}
    },
    {
    .iv = 250,
    .lvl = 51,
    .species = SPECIES_MURKROW,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SKY_ATTACK, MOVE_PURSUIT, MOVE_STEEL_WING, MOVE_HAZE}
    },
    {
    .iv = 250,
    .lvl = 52,
    .species = SPECIES_SHIFTRY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LEAF_BLADE, MOVE_FAINT_ATTACK, MOVE_AERIAL_ACE, MOVE_EXTRASENSORY}
    },
    {
    .iv = 250,
    .lvl = 52,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_SCOPE_LENS,
    .moves = {MOVE_CRABHAMMER, MOVE_SWORDS_DANCE, MOVE_CRUNCH, MOVE_SLUDGE_BOMB}
    },
    {
    .iv = 255,
    .lvl = 53,
    .species = SPECIES_ABSOL,
    .heldItem = ITEM_FIGY_BERRY,
    .moves = {MOVE_CRUNCH, MOVE_IRON_TAIL, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE}
    }
};
//Elite Four Phoebe
static const struct TrainerMon sParty_Phoebe[] = {
    {
    .iv = 250,
    .lvl = 52,
    .species = SPECIES_SABLEYE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_MOONLIGHT, MOVE_CRUNCH, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY}
    },
    {
    .iv = 250,
    .lvl = 53,
    .species = SPECIES_BANETTE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_REVENGE, MOVE_DESTINY_BOND}
    },
    {
    .iv = 250,
    .lvl = 52,
    .species = SPECIES_NINETALES,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_WILL_O_WISP, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY}
    },
    {
    .iv = 250,
    .lvl = 52,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_HI_JUMP_KICK, MOVE_ENDURE, MOVE_REVERSAL}
    },
    {
    .iv = 255,
    .lvl = 54,
    .species = SPECIES_DUSCLOPS,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_SHADOW_BALL, MOVE_ICE_BEAM, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE}
    }
};
// Elite Four Glacia
static const struct TrainerMon sParty_Glacia[] = {
    {
    .iv = 250,
    .lvl = 54,
    .species = SPECIES_GLALIE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BLIZZARD, MOVE_WATER_PULSE, MOVE_SHADOW_BALL, MOVE_HAIL}
    },
    {
    .iv = 250,
    .lvl = 53,
    .species = SPECIES_SNEASEL,
    .heldItem = ITEM_SCOPE_LENS,
    .moves = {MOVE_FAINT_ATTACK, MOVE_BLIZZARD, MOVE_SWORDS_DANCE, MOVE_SLASH}
    },
    {
    .iv = 250,
    .lvl = 53,
    .species = SPECIES_CASTFORM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WEATHER_BALL, MOVE_HYDRO_PUMP, MOVE_HAIL, MOVE_THUNDERBOLT}
    },
    {
    .iv = 250,
    .lvl = 54,
    .species = SPECIES_PILOSWINE,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_BLIZZARD, MOVE_ROCK_SLIDE, MOVE_REST}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_SURF, MOVE_BLIZZARD, MOVE_HAIL, MOVE_SHEER_COLD}
    }
};
// Elite Four Drake
static const struct TrainerMon sParty_Drake[] = {
    {
    .iv = 250,
    .lvl = 54,
    .species = SPECIES_FLYGON,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_EARTHQUAKE, MOVE_FLAMETHROWER, MOVE_SIGNAL_BEAM, MOVE_CRUNCH}
    },
    {
    .iv = 250,
    .lvl = 55,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_SHARP_BEAK,
    .moves = {MOVE_SKY_ATTACK, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = 250,
    .lvl = 53,
    .species = SPECIES_HUNTAIL,
    .heldItem = ITEM_PETAYA_BERRY,
    .moves = {MOVE_BODY_SLAM, MOVE_CRUNCH, MOVE_HYDRO_PUMP, MOVE_CONFUSE_RAY}
    },
    {
    .iv = 250,
    .lvl = 55,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_REST, MOVE_SLEEP_TALK, MOVE_SURF, MOVE_DRAGON_BREATH}
    },
    {
    .iv = 255,
    .lvl = 56,
    .species = SPECIES_SALAMENCE,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_ROCK_SLIDE, MOVE_CRUNCH}
    }
};
//Rustboro Gym Leader
static const struct TrainerMon sParty_Roxanne1[] = {
    {
    .iv = 100,
    .lvl = 13,
    .species = SPECIES_ANORITH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SCRATCH, MOVE_HARDEN, MOVE_NONE, MOVE_NONE}
    },
    {
    .iv = 100,
    .lvl = 12,
    .species = SPECIES_LILEEP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ASTONISH, MOVE_CONSTRICT, MOVE_HARDEN, MOVE_NONE}
    },
    {
    .iv = 200,
    .lvl = 15,
    .species = SPECIES_NOSEPASS,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_ROCK_THROW, MOVE_HARDEN, MOVE_HEADBUTT, MOVE_ROCK_TOMB}
    }
};
// Dewford Gym Leader
static const struct TrainerMon sParty_Brawly1[] = {
    {
    .iv = 100,
    .lvl = 17,
    .species = SPECIES_MAKUHITA,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_VITAL_THROW, MOVE_REVERSAL, MOVE_BULK_UP, MOVE_FAINT_ATTACK}
    },
    {
    .iv = 100,
    .lvl = 16,
    .species = SPECIES_MEDITITE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CONFUSION, MOVE_THUNDER_PUNCH, MOVE_LIGHT_SCREEN, MOVE_REFLECT}
    },
    {
    .iv = 200,
    .lvl = 19,
    .species = SPECIES_BRELOOM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_TACKLE, MOVE_MEGA_DRAIN, MOVE_BULK_UP, MOVE_STUN_SPORE}
    }
};
// Mauville Gym Leader
static const struct TrainerMon sParty_Wattson1[] = {
    {
    .iv = 200,
    .lvl = 24,
    .species = SPECIES_CHINCHOU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHOCK_WAVE, MOVE_BUBBLE_BEAM, MOVE_ICY_WIND, MOVE_THUNDER_WAVE}
    },
    {
    .iv = 220,
    .lvl = 23,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER_SHOCK, MOVE_THUNDER_WAVE, MOVE_SUPERSONIC, MOVE_SONIC_BOOM}
    },
    {
    .iv = 200,
    .lvl = 24,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SPARK, MOVE_CHARM, MOVE_QUICK_ATTACK, MOVE_MAGICAL_LEAF}
    },
    {
    .iv = 250,
    .lvl = 25,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_LUM_BERRY,
    .moves = {MOVE_QUICK_ATTACK, MOVE_BITE, MOVE_SHOCK_WAVE, MOVE_HOWL}
    }
};

static const struct TrainerMon sParty_Flannery1[] = {
    {
    .iv = 250,
    .lvl = 29,
    .species = SPECIES_VULPIX,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_OVERHEAT, MOVE_WILL_O_WISP, MOVE_ROAR, MOVE_SUNNY_DAY}
    },
    {
    .iv = 200,
    .lvl = 28,
    .species = SPECIES_MAGCARGO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_OVERHEAT, MOVE_ROCK_THROW, MOVE_LIGHT_SCREEN, MOVE_SUNNY_DAY}
    },
    {
    .iv = 250,
    .lvl = 30,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_OVERHEAT, MOVE_MAGNITUDE, MOVE_SUNNY_DAY, MOVE_ATTRACT}
    },
    {
    .iv = 250,
    .lvl = 32,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_BODY_SLAM, MOVE_ATTRACT}
    }
};
//Petalburg Gym Leader
static const struct TrainerMon sParty_Norman1[] = {
    {
    .iv = 200,
    .lvl = 31,
    .species = SPECIES_VIGOROTH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SLASH, MOVE_FACADE, MOVE_ENCORE, MOVE_FAINT_ATTACK}
    },
    {
    .iv = 200, 
    .lvl = 30,
    .species = SPECIES_GIRAFARIG,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FACADE, MOVE_PSYBEAM, MOVE_BITE, MOVE_SHOCK_WAVE}
    },
    {
    .iv = 200,
    .lvl = 31,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_PURSUIT, MOVE_BELLY_DRUM, MOVE_FACADE, MOVE_DIG}
    },
    {
    .iv = 250,
    .lvl = 33,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_COUNTER, MOVE_YAWN, MOVE_FACADE, MOVE_FAINT_ATTACK}
    }
};
// Fortree Gym Leader
static const struct TrainerMon sParty_Winona1[] = {
    {
    .iv = 200,
    .lvl = 36,
    .species = SPECIES_TROPIUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_AERIAL_ACE, MOVE_MAGICAL_LEAF, MOVE_EARTHQUAKE, MOVE_WHIRLWIND}
    },
    {
    .iv = 220,
    .lvl = 37,
    .species = SPECIES_SWELLOW,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_AERIAL_ACE, MOVE_STEEL_WING, MOVE_TAKE_DOWN, MOVE_WHIRLWIND}
    },
    {
    .iv = 200,
    .lvl = 36,
    .species = SPECIES_PELIPPER,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_SHOCK_WAVE, MOVE_ICE_BEAM, MOVE_AERIAL_ACE}
    },
    {
    .iv = 235,
    .lvl = 37,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_WHIRLWIND, MOVE_MUD_SLAP, MOVE_STEEL_WING, MOVE_AERIAL_ACE}
    },
    {
    .iv = 255,
    .lvl = 38,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_LUM_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_FLAMETHROWER, MOVE_DRAGON_DANCE, MOVE_AERIAL_ACE}
    }
};
// Mossdeep Gym Leader
static const struct TrainerMon sParty_TateAndLiza1[] = {
    {
    .iv = 250,
    .lvl = 44,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_PSYCHIC, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = 250,
    .lvl = 44,
    .species = SPECIES_XATU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_SUNNY_DAY, MOVE_GIGA_DRAIN}
    },
    {
    .iv = 250,
    .lvl = 43,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EXTRASENSORY, MOVE_HI_JUMP_KICK, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH}
    },
    {
    .iv = 250,
    .lvl = 43,
    .species = SPECIES_CHIMECHO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_WISH, MOVE_HEAL_BELL }
    },
    {
    .iv = 250,
    .lvl = 45,
    .species = SPECIES_LUNATONE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_LIGHT_SCREEN, MOVE_HYPNOSIS, MOVE_CALM_MIND}
    },
    {
    .iv = 250,
    .lvl = 45,
    .species = SPECIES_SOLROCK,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_SOLAR_BEAM, MOVE_FLAMETHROWER, MOVE_SUNNY_DAY}
    }
};
// Original Base Gym Leader Placeholder
static const struct TrainerMon sParty_Juan1[] = {
    {
    .iv = 200,
    .lvl = 41,
    .species = SPECIES_LUVDISC,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_ATTRACT, MOVE_SWEET_KISS, MOVE_FLAIL}
    },
    {
    .iv = 200,
    .lvl = 41,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_PULSE, MOVE_AMNESIA, MOVE_EARTHQUAKE}
    },
    {
    .iv = 200,
    .lvl = 43,
    .species = SPECIES_SEALEO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ENCORE, MOVE_BODY_SLAM, MOVE_AURORA_BEAM, MOVE_WATER_PULSE}
    },
    {
    .iv = 200,
    .lvl = 43,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_CRABHAMMER, MOVE_TAUNT, MOVE_LEER}
    },
    {
    .iv = 250,
    .lvl = 46,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_WATER_PULSE, MOVE_DOUBLE_TEAM, MOVE_ICE_BEAM, MOVE_REST}
    }
};
// Route 116 Cut School Kid
static const struct TrainerMon sParty_Jerry1[] = {
    {
    .iv = 10,
    .lvl = 12,
    .species = SPECIES_MEDITITE,
    },
    {
    .iv = 10,
    .lvl = 12,
    .species = SPECIES_RALTS,
    }
};
// Trick House 2
static const struct TrainerMon sParty_Ted[] = {
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_KIRLIA,
    }
};
// Trick House 2
static const struct TrainerMon sParty_Paul[] = {
    {
    .iv = 10,
    .lvl = 18,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = 10,
    .lvl = 19,
    .species = SPECIES_ODDISH,
    },
    {
    .iv = 10,
    .lvl = 18,
    .species = SPECIES_GULPIN,
    }
};

static const struct TrainerMon sParty_Jerry2[] = {
    {
    .iv = 20,
    .lvl = 26,
    .species = SPECIES_KIRLIA,
    },
    {
    .iv = 20,
    .lvl = 26,
    .species = SPECIES_MEDITITE,
    }
};

static const struct TrainerMon sParty_Jerry3[] = {
    {
    .iv = 30,
    .lvl = 29,
    .species = SPECIES_KIRLIA,
    },
    {
    .iv = 30,
    .lvl = 29,
    .species = SPECIES_MEDITITE,
    }
};

static const struct TrainerMon sParty_Jerry4[] = {
    {
    .iv = 40,
    .lvl = 32,
    .species = SPECIES_GARDEVOIR,
    },
    {
    .iv = 40,
    .lvl = 32,
    .species = SPECIES_MEDICHAM,
    }
};

static const struct TrainerMon sParty_Jerry5[] = {
    {
    .iv = 50,
    .lvl = 34,
    .species = SPECIES_GARDEVOIR,
    },
    {
    .iv = 50,
    .lvl = 34,
    .species = SPECIES_BANETTE,
    },
    {
    .iv = 50,
    .lvl = 34,
    .species = SPECIES_MEDICHAM,
    }
};
// Route 116 School Kid
static const struct TrainerMon sParty_Karen1[] = {
    {
    .iv = 10,
    .lvl = 10,
    .species = SPECIES_SHROOMISH,
    }
};
// Trick House 2 
static const struct TrainerMon sParty_Georgia[] = {
    {
    .iv = 10,
    .lvl = 18,
    .species = SPECIES_SURSKIT,
    },
    {
    .iv = 10,
    .lvl = 20,
    .species = SPECIES_BEAUTIFLY,
    }
};

static const struct TrainerMon sParty_Karen2[] = {
    {
    .iv = 20,
    .lvl = 26,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 20,
    .lvl = 26,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_Karen3[] = {
    {
    .iv = 30,
    .lvl = 29,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 30,
    .lvl = 29,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_Karen4[] = {
    {
    .iv = 40,
    .lvl = 32,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 40,
    .lvl = 32,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_Karen5[] = {
    {
    .iv = 50,
    .lvl = 35,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 50,
    .lvl = 35,
    .species = SPECIES_EXPLOUD,
    }
};
// Route 121 Sr and Jr
static const struct TrainerMon sParty_KateAndJoy[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_SPINDA,
    .moves = {MOVE_HYPNOSIS, MOVE_PSYBEAM, MOVE_DIZZY_PUNCH, MOVE_TEETER_DANCE}
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_SLAKING,
    .moves = {MOVE_YAWN, MOVE_SLACK_OFF, MOVE_FAINT_ATTACK, MOVE_FURY_SWIPES }
    }
};
// Route 117 Sr and Jr
static const struct TrainerMon sParty_AnnaAndMeg1[] = {
    {
    .iv = 0,
    .lvl = 17,
    .species = SPECIES_ZIGZAGOON,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_NONE}
    },
    {
    .iv = 0,
    .lvl = 17,
    .species = SPECIES_MAKUHITA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_AnnaAndMeg2[] = {
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .iv = 10,
    .lvl = 30,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_AnnaAndMeg3[] = {
    {
    .iv = 30,
    .lvl = 31,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_ODOR_SLEUTH}
    },
    {
    .iv = 30,
    .lvl = 31,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_AnnaAndMeg4[] = {
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_SHADOW_BALL}
    },
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_TACKLE, MOVE_FOCUS_ENERGY, MOVE_ARM_THRUST, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_AnnaAndMeg5[] = {
    {
    .iv = 40,
    .lvl = 38,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_HEADBUTT, MOVE_SHADOW_BALL}
    },
    {
    .iv = 40,
    .lvl = 38,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_BODY_SLAM, MOVE_FOCUS_ENERGY, MOVE_BRICK_BREAK, MOVE_NONE}
    }
};
//Winstrate House
static const struct TrainerMon sParty_Victor[] = {
    {
    .iv = 100,
    .lvl = 17,
    .species = SPECIES_TAILLOW,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = 100,
    .lvl = 17,
    .species = SPECIES_ZIGZAGOON,
    .heldItem = ITEM_ORAN_BERRY
    }
};
// Route 103 Pokefan
static const struct TrainerMon sParty_Miguel1[] = {
    {
    .iv = 0,
    .lvl = 18,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_ORAN_BERRY
    }
};
// SS Tidal Pokefan Colton (all gen 2 baby from nat dex)
static const struct TrainerMon sParty_Colton[] = {
    {
    .iv = 0,
    .lvl = 53,
    .species = SPECIES_TOGEPI,
    .heldItem = ITEM_ORAN_BERRY,
    },
    {
    .iv = 0,
    .lvl = 52,
    .species = SPECIES_SMOOCHUM,
    .heldItem = ITEM_ORAN_BERRY,
    },
    {
    .iv = 0,
    .lvl = 53,
    .species = SPECIES_CLEFFA,
    .heldItem = ITEM_ORAN_BERRY,
    },
    {
    .iv = 0,
    .lvl = 54,
    .species = SPECIES_MAGBY,
    .heldItem = ITEM_ORAN_BERRY,
    },
    {
    .iv = 0,
    .lvl = 53,
    .species = SPECIES_ELEKID,
    .heldItem = ITEM_ORAN_BERRY,
    },
    {
    .iv = 0,
    .lvl = 55,
    .species = SPECIES_TYROGUE,
    .heldItem = ITEM_ORAN_BERRY,
    }
};

static const struct TrainerMon sParty_Miguel2[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Miguel3[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_SKITTY,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Miguel4[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Miguel5[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_SITRUS_BERRY
    }
};
// Winstrate House
static const struct TrainerMon sParty_Victoria[] = {
    {
    .iv = 150,
    .lvl = 19,
    .species = SPECIES_ROSELIA,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_POISON_STING, MOVE_STUN_SPORE, MOVE_MEGA_DRAIN, MOVE_LEECH_SEED}
    }
};
// Route 121 PokefanF
static const struct TrainerMon sParty_Vanessa[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_PIKACHU,
    .heldItem = ITEM_SITRUS_BERRY
    }
};
//Sootopolis Gym Pokefan 2 (Highest Level - Double Battle w Olivia)
static const struct TrainerMon sParty_Bethany[] = {
    {
    .iv = 100,
    .lvl = 40,
    .species = SPECIES_AZURILL,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = 100,
    .lvl = 44,
    .species = SPECIES_MARILL,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = 100,
    .lvl = 46,
    .species = SPECIES_AZUMARILL,
    .heldItem = ITEM_ORAN_BERRY
    }
};
//Route 110 PokefanF 1
static const struct TrainerMon sParty_Isabel1[] = {
    {
    .iv = 0,
    .lvl = 15,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_THUNDER_SHOCK, MOVE_GROWL, MOVE_LIGHT_SCREEN, MOVE_FLASH}
    },
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_THUNDER_SHOCK, MOVE_HELPING_HAND, MOVE_LIGHT_SCREEN, MOVE_QUICK_ATTACK}
    }
};

static const struct TrainerMon sParty_Isabel2[] = {
    {
    .iv = 10,
    .lvl = 26,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = 10,
    .lvl = 26,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Isabel3[] = {
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Isabel4[] = {
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_ORAN_BERRY
    },
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_ORAN_BERRY
    }
};

static const struct TrainerMon sParty_Isabel5[] = {
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_SITRUS_BERRY
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_SITRUS_BERRY
    }
};
// Route 115 Surf Expert 
static const struct TrainerMon sParty_Timothy1[] = {
    {
    .iv = 200,
    .lvl = 31,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Timothy2[] = {
    {
    .iv = 210,
    .lvl = 34,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_ARM_THRUST, MOVE_KNOCK_OFF, MOVE_SAND_ATTACK, MOVE_DIG}
    }
};

static const struct TrainerMon sParty_Timothy3[] = {
    {
    .iv = 220,
    .lvl = 37,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_ARM_THRUST, MOVE_KNOCK_OFF, MOVE_SAND_ATTACK, MOVE_DIG}
    }
};

static const struct TrainerMon sParty_Timothy4[] = {
    {
    .iv = 230,
    .lvl = 40,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_ARM_THRUST, MOVE_BELLY_DRUM, MOVE_SAND_ATTACK, MOVE_DIG}
    }
};

static const struct TrainerMon sParty_Timothy5[] = {
    {
    .iv = 240,
    .lvl = 42,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_ARM_THRUST, MOVE_BELLY_DRUM, MOVE_SAND_ATTACK, MOVE_DIG}
    }
};
// Winstrate House
static const struct TrainerMon sParty_Vicky[] = {
    {
    .iv = 200,
    .lvl = 21,
    .species = SPECIES_MEDITITE,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_HI_JUMP_KICK, MOVE_MEDITATE, MOVE_CONFUSION, MOVE_CALM_MIND}
    }
};
// Mt Chimney ExpertF
static const struct TrainerMon sParty_Shelby1[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Shelby2[] = {
    {
    .iv = 210,
    .lvl = 30,
    .species = SPECIES_MEDITITE,
    },
    {
    .iv = 210,
    .lvl = 30,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Shelby3[] = {
    {
    .iv = 220,
    .lvl = 33,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = 220,
    .lvl = 33,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Shelby4[] = {
    {
    .iv = 230,
    .lvl = 36,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = 230,
    .lvl = 36,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Shelby5[] = {
    {
    .iv = 240,
    .lvl = 39,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = 240,
    .lvl = 39,
    .species = SPECIES_HARIYAMA,
    }
};
//Route 102 Youngster 1
static const struct TrainerMon sParty_Calvin1[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_POOCHYENA,
    }
};
//Route 104 Youngster
static const struct TrainerMon sParty_Billy[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .iv = 0,
    .lvl = 7,
    .species = SPECIES_SEEDOT,
    }
};
//Rustboro Gym Youngster 1 (One by himself)
static const struct TrainerMon sParty_Josh[] = {
    {
    .iv = 100,
    .lvl = 9,
    .species = SPECIES_GEODUDE,
    .moves = {MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_NONE, MOVE_NONE}
    },
    {
    .iv = 100,
    .lvl = 10,
    .species = SPECIES_ARON,
    .moves = {MOVE_TACKLE, MOVE_HARDEN, MOVE_NONE, MOVE_NONE}
    },
    {
    .iv = 100,
    .lvl = 9,
    .species = SPECIES_GEODUDE,
    .moves = {MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_NONE, MOVE_NONE}
    }
};
//Rustboro Gym Youngster 2 (Potential Double Battle with Marc)
static const struct TrainerMon sParty_Tommy[] = {
    {
    .iv = 110,
    .lvl = 9,
    .species = SPECIES_GEODUDE,
    .moves = {MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_NONE, MOVE_NONE}
    },
    {
    .iv = 110,
    .lvl = 10,
    .species = SPECIES_ARON,
    .moves = {MOVE_METAL_CLAW, MOVE_TACKLE, MOVE_HARDEN, MOVE_NONE}
    },
};
// Route 116 Youngster 1
static const struct TrainerMon sParty_Joey[] = {
    {
    .iv = 0,
    .lvl = 9,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = 0,
    .lvl = 8,
    .species = SPECIES_VULPIX,
    },
};
// Mauville Gym Youngster
static const struct TrainerMon sParty_Ben[] = {
    {
    .iv = 150,
    .lvl = 18,
    .species = SPECIES_LINOONE,
    .moves = {MOVE_HEADBUTT, MOVE_SAND_ATTACK, MOVE_GROWL, MOVE_THUNDERBOLT}
    },
    {
    .iv = 150,
    .lvl = 17,
    .species = SPECIES_GULPIN,
    .moves = {MOVE_AMNESIA, MOVE_SLUDGE, MOVE_YAWN, MOVE_POUND}
    }
};
// Victory Road CooltrainerM (Iconic Double Battle w Katelynn)
static const struct TrainerMon sParty_Quincy[] = {
    {
    .iv = 100,
    .lvl = 48,
    .species = SPECIES_SLAKING,
    .moves = {MOVE_ATTRACT, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER}
    },
    {
    .iv = 100,
    .lvl = 48,
    .species = SPECIES_DUSCLOPS,
    .moves = {MOVE_SKILL_SWAP, MOVE_PROTECT, MOVE_WILL_O_WISP, MOVE_TOXIC}
    }
};
// Victory Road CooltrainerF (Iconic Double Battle w Quincy)
static const struct TrainerMon sParty_Katelynn[] = {
    {
    .iv = 100,
    .lvl = 48,
    .species = SPECIES_GARDEVOIR,
    .moves = {MOVE_SKILL_SWAP, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_CALM_MIND}
    },
    {
    .iv = 100,
    .lvl = 48,
    .species = SPECIES_SLAKING,
    .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_AERIAL_ACE, MOVE_BRICK_BREAK}
    }
};
// Route 113 Youngster 1
static const struct TrainerMon sParty_Jaylen[] = {
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_TRAPINCH,
    }
};
// Route 113 Youngster 2
static const struct TrainerMon sParty_Dillon[] = {
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_ARON,
    }
};

static const struct TrainerMon sParty_Calvin2[] = {
    {
    .iv = 10,
    .lvl = 27,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_Calvin3[] = {
    {
    .iv = 20,
    .lvl = 28,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 20,
    .lvl = 30,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_Calvin4[] = {
    {
    .iv = 30,
    .lvl = 31,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 30,
    .lvl = 29,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = 30,
    .lvl = 33,
    .species = SPECIES_MIGHTYENA,
    }
};

static const struct TrainerMon sParty_Calvin5[] = {
    {
    .iv = 40,
    .lvl = 34,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 40,
    .lvl = 32,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_MIGHTYENA,
    }
};
// Trick House 1 (Cut) Youngster
static const struct TrainerMon sParty_Eddie[] = {
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_NINCADA,
    },
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_NUZLEAF,
    }
};
//Route 102 Youngster 2
static const struct TrainerMon sParty_Allen[] = {
    {
    .iv = 0,
    .lvl = 4,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .iv = 0,
    .lvl = 3,
    .species = SPECIES_TAILLOW,
    }
};
//Route 110 Youngster 1
static const struct TrainerMon sParty_Timmy[] = {
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_ARON,
    },
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_GULPIN,
    }
};

// Gym Leader
static const struct TrainerMon sParty_Wallace1[] = {
    {
    .iv = 255,
    .lvl = 49,
    .species = SPECIES_TENTACRUEL,
    .heldItem = ITEM_PETAYA_BERRY,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_PULSE, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM}
    },
    {
    .iv = 255,
    .lvl = 48,
    .species = SPECIES_MASQUERAIN,
    .heldItem = ITEM_SILVER_POWDER,
    .moves = {MOVE_HYDRO_PUMP, MOVE_SIGNAL_BEAM, MOVE_STUN_SPORE, MOVE_BLIZZARD}
    },
    {
    .iv = 255,
    .lvl = 49,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_EARTHQUAKE, MOVE_SURF, MOVE_RAIN_DANCE, MOVE_YAWN}
    },
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_LUDICOLO,
    .heldItem = ITEM_MYSTIC_WATER,
    .moves = {MOVE_GIGA_DRAIN, MOVE_WATER_PULSE, MOVE_LEECH_SEED, MOVE_DOUBLE_TEAM}
    },
    {
    .iv = 255,
    .lvl = 51,
    .species = SPECIES_MILOTIC,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_RECOVER, MOVE_DIVE, MOVE_ICE_BEAM, MOVE_TOXIC}
    }
};

// Champion (Rematch)
static const struct TrainerMon sParty_Wallace2[] = {
    {
    .iv = 255,
    .lvl = 77,
    .species = SPECIES_WAILORD,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {252, 0, 0, 0, 252, 0},
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_SPOUT, MOVE_DOUBLE_EDGE, MOVE_BLIZZARD}
    },
    {
    .iv = 255,
    .lvl = 75,
    .species = SPECIES_TENTACRUEL,
    .heldItem = ITEM_SALAC_BERRY,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_RAIN_DANCE, MOVE_HYDRO_PUMP, MOVE_TOXIC, MOVE_ICE_BEAM}
    },
    {
    .iv = 255,
    .lvl = 76,
    .species = SPECIES_LUDICOLO,
    .heldItem = ITEM_MIRACLE_SEED,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_GIGA_DRAIN, MOVE_SURF, MOVE_ICE_BEAM, MOVE_RAIN_DANCE}
    },
    {
    .iv = 255,
    .lvl = 76,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_FOCUS_BAND,
    .evs = {252, 252, 0, 0, 0, 0},
    .moves = {MOVE_EARTHQUAKE, MOVE_SURF, MOVE_YAWN, MOVE_ICY_WIND}
    },
    {
    .iv = 255,
    .lvl = 76,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_CHOICE_BAND,
    .evs = {0, 252, 0, 0, 0, 252},
    .moves = {MOVE_BOUNCE, MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_SURF}
    },
    {
    .iv = 255,
    .lvl = 78,
    .species = SPECIES_MILOTIC,
    .heldItem = ITEM_LEFTOVERS,
    .evs = {252, 0, 0, 0, 0, 252},
    .moves = {MOVE_DIVE, MOVE_RECOVER, MOVE_LIGHT_SCREEN, MOVE_TOXIC}
    }
};

// Route 103 Fisherman
static const struct TrainerMon sParty_Andrew[] = {
    {
    .iv = 0,
    .lvl = 15,
    .species = SPECIES_BARBOACH,
    },
    {
    .iv = 0,
    .lvl = 15,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 0,
    .lvl = 19,
    .species = SPECIES_MAGIKARP,
    }
};
//Route 104 North Fisherman
static const struct TrainerMon sParty_Ivan[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_MAGIKARP,
    },
    {
    .iv = 0,
    .lvl = 7,
    .species = SPECIES_GOLDEEN,
    }
};
// Route 114 Fisherman 3
static const struct TrainerMon sParty_Claude[] = {
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_BARBOACH,
    },
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_GOLDEEN,
    },
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_BARBOACH,
    }
};
// Route 106 Fisherman 2
static const struct TrainerMon sParty_Elliot1[] = {
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_CORPHISH,
    }
};
// Route 106 Fisherman 1
static const struct TrainerMon sParty_Ned[] = {
    {
    .iv = 10,
    .lvl = 11,
    .species = SPECIES_HORSEA,
    },
    {
    .iv = 10,
    .lvl = 11,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 10,
    .lvl = 11,
    .species = SPECIES_HORSEA,
    },
};
// Route 110 Fisherman
static const struct TrainerMon sParty_Dale[] = {
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = 0,
    .lvl = 15,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_WAILMER,
    }
};
// Route 114 Fisherman 1
static const struct TrainerMon sParty_Nolan[] = {
    {
    .iv = 0,
    .lvl = 20,
    .species = SPECIES_GYARADOS,
    }
};
//Route 118 East Fisherman
static const struct TrainerMon sParty_Barny[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_BARBOACH,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_CARVANHA,
    }
};
//Route 118 Mauville Fisherman
static const struct TrainerMon sParty_Wade[] = {
    {
    .iv = 0,
    .lvl = 19,
    .species = SPECIES_BARBOACH,
    }
};
//Route 109 Surf Fisherman 1
static const struct TrainerMon sParty_Carter[] = {
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_TENTACRUEL,
    }
};

static const struct TrainerMon sParty_Elliot2[] = {
    {
    .iv = 10,
    .lvl = 24,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 10,
    .lvl = 27,
    .species = SPECIES_CORPHISH,
    },
    {
    .iv = 10,
    .lvl = 27,
    .species = SPECIES_GYARADOS,
    }
};

static const struct TrainerMon sParty_Elliot3[] = {
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_CRAWDAUNT,
    },
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_GYARADOS,
    }
};

static const struct TrainerMon sParty_Elliot4[] = {
    {
    .iv = 30,
    .lvl = 31,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 30,
    .lvl = 30,
    .species = SPECIES_CRAWDAUNT,
    },
    {
    .iv = 30,
    .lvl = 30,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .iv = 31,
    .lvl = 31,
    .species = SPECIES_GYARADOS,
    }
};

static const struct TrainerMon sParty_Elliot5[] = {
    {
    .iv = 40,
    .lvl = 33,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 40,
    .lvl = 33,
    .species = SPECIES_CRAWDAUNT,
    },
    {
    .iv = 40,
    .lvl = 33,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 40,
    .lvl = 35,
    .species = SPECIES_TENTACRUEL,
    }
};
// Route 132 Fisherman
static const struct TrainerMon sParty_Ronald[] = {
    {
    .iv = 0,
    .lvl = 19,
    .species = SPECIES_MAGIKARP,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_GYARADOS,
    }
};
// Cycling Road mTriathlete
static const struct TrainerMon sParty_Jacob[] = {
    {
    .iv = 20,
    .lvl = 18,
    .species = SPECIES_TAILLOW,
    },
    {
    .iv = 20,
    .lvl = 20,
    .species = SPECIES_VOLTORB,
    },
    {
    .iv = 200,
    .lvl = 18,
    .species = SPECIES_PONYTA,
    }
};
// Cycling Road mTriathlete
static const struct TrainerMon sParty_Anthony[] = {
    {
    .iv = 0,
    .lvl = 18,
    .species = SPECIES_PLUSLE,
    },
    {
    .iv = 0,
    .lvl = 18,
    .species = SPECIES_DODUO,
    }
};
// Cycling Road mTriathlete 
static const struct TrainerMon sParty_Benjamin1[] = {
    {
    .iv = 0,
    .lvl = 20,
    .species = SPECIES_MAGNEMITE,
    }
};

static const struct TrainerMon sParty_Benjamin2[] = {
    {
    .iv = 10,
    .lvl = 30,
    .species = SPECIES_MAGNETON,
    }
};

static const struct TrainerMon sParty_Benjamin3[] = {
    {
    .iv = 20,
    .lvl = 33,
    .species = SPECIES_MAGNETON,
    }
};

static const struct TrainerMon sParty_Benjamin4[] = {
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_MAGNETON,
    }
};

static const struct TrainerMon sParty_Benjamin5[] = {
    {
    .iv = 40,
    .lvl = 39,
    .species = SPECIES_MAGNETON,
    }
};
// Cycling Road fTriathlete
static const struct TrainerMon sParty_Abigail1[] = {
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_MAGNEMITE,
    }
};
// Cycling Road fTriathlete
static const struct TrainerMon sParty_Jasmine[] = {
    {
    .iv = 80,
    .lvl = 18,
    .species = SPECIES_DODUO,
    },
    {
    .iv = 80,
    .lvl = 20,
    .species = SPECIES_PONYTA,
    },
    {
    .iv = 0,
    .lvl = 18,
    .species = SPECIES_VOLTORB,
    }
};

static const struct TrainerMon sParty_Abigail2[] = {
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_MAGNEMITE,
    }
};

static const struct TrainerMon sParty_Abigail3[] = {
    {
    .iv = 20,
    .lvl = 31,
    .species = SPECIES_MAGNETON,
    }
};

static const struct TrainerMon sParty_Abigail4[] = {
    {
    .iv = 30,
    .lvl = 34,
    .species = SPECIES_MAGNETON,
    }
};

static const struct TrainerMon sParty_Abigail5[] = {
    {
    .iv = 40,
    .lvl = 37,
    .species = SPECIES_MAGNETON,
    }
};
// Route 117 Triathlete
static const struct TrainerMon sParty_Dylan1[] = {
    {
    .iv = 0,
    .lvl = 17,
    .species = SPECIES_DODUO,
    },
    {
    .iv = 0,
    .lvl = 17,
    .species = SPECIES_PONYTA,
    }
};

static const struct TrainerMon sParty_Dylan2[] = {
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_DODUO,
    },
    {
    .iv = 0,
    .lvl = 31,
    .species = SPECIES_PONYTA,
    }
};

static const struct TrainerMon sParty_Dylan3[] = {
    {
    .iv = 20,
    .lvl = 31,
    .species = SPECIES_DODUO,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_PONYTA,
    }
};

static const struct TrainerMon sParty_Dylan4[] = {
    {
    .iv = 30,
    .lvl = 34,
    .species = SPECIES_DODRIO,
    },
    {
    .iv = 0,
    .lvl = 37,
    .species = SPECIES_PONYTA,
    }
};

static const struct TrainerMon sParty_Dylan5[] = {
    {
    .iv = 40,
    .lvl = 37,
    .species = SPECIES_DODRIO,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_RAPIDASH,
    }
};
// Route 117 TriathleteF
static const struct TrainerMon sParty_Maria1[] = {
    {
    .iv = 0,
    .lvl = 19,
    .species = SPECIES_DODUO,
    }
};

static const struct TrainerMon sParty_Maria2[] = {
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_DODUO,
    }
};

static const struct TrainerMon sParty_Maria3[] = {
    {
    .iv = 20,
    .lvl = 31,
    .species = SPECIES_DODUO,
    }
};

static const struct TrainerMon sParty_Maria4[] = {
    {
    .iv = 30,
    .lvl = 34,
    .species = SPECIES_DODRIO,
    }
};

static const struct TrainerMon sParty_Maria5[] = {
    {
    .iv = 40,
    .lvl = 37,
    .species = SPECIES_DODRIO,
    },
    {
    .iv = 40,
    .lvl = 40,
    .species = SPECIES_RAPIDASH,
    }
};
// Route 127 TriathleteM
static const struct TrainerMon sParty_Camden[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_STARMIE,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_LUVDISC,
    }
};
// Abandoned Ship
static const struct TrainerMon sParty_Demetrius[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_MANECTRIC,
    }
};
// Route 128 TriatheleteM
static const struct TrainerMon sParty_Isaiah1[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_STARMIE,
    }
};
// Route 126 Triathlete
static const struct TrainerMon sParty_Pablo1[] = {
    {
    .iv = 50,
    .lvl = 38,
    .species = SPECIES_LANTURN,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_STARMIE,
    }
};
// Route 129 TriathleteM
static const struct TrainerMon sParty_Chase[] = {
    {
    .iv = 0,
    .lvl = 41,
    .species = SPECIES_RELICANTH,
    }
};

static const struct TrainerMon sParty_Isaiah2[] = {
    {
    .iv = 10,
    .lvl = 42,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Isaiah3[] = {
    {
    .iv = 20,
    .lvl = 44,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Isaiah4[] = {
    {
    .iv = 30,
    .lvl = 46,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Isaiah5[] = {
    {
    .iv = 40,
    .lvl = 48,
    .species = SPECIES_STARMIE,
    }
};
// Route 126 SwimmerF
static const struct TrainerMon sParty_Isobel[] = {
    {
    .iv = 0,
    .lvl = 39,
    .species = SPECIES_GOLDUCK,
    }
};
// Route 127 TriathleteF
static const struct TrainerMon sParty_Donny[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 200,
    .lvl = 38,
    .species = SPECIES_STARYU,
    }
};
// Route 131 TriathleteF
static const struct TrainerMon sParty_Talia[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_GYARADOS,
    }
};
// Route 128 TriathleteF
static const struct TrainerMon sParty_Katelyn1[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_STARMIE,
    }
};
// Route 129 TriathleteF
static const struct TrainerMon sParty_Allison[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 240,
    .lvl = 40,
    .species = SPECIES_SEAKING,
    }
};

static const struct TrainerMon sParty_Katelyn2[] = {
    {
    .iv = 10,
    .lvl = 42,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Katelyn3[] = {
    {
    .iv = 20,
    .lvl = 45,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Katelyn4[] = {
    {
    .iv = 30,
    .lvl = 48,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Katelyn5[] = {
    {
    .iv = 40,
    .lvl = 50,
    .species = SPECIES_STARMIE,
    }
};
// Meteor Falls Dragon Tamer
static const struct TrainerMon sParty_Nicolas1[] = {
    {
    .iv = 100,
    .lvl = 48,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = 100,
    .lvl = 48,
    .species = SPECIES_ALTARIA,
    }
};

static const struct TrainerMon sParty_Nicolas2[] = {
    {
    .iv = 110,
    .lvl = 52,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = 110,
    .lvl = 53,
    .species = SPECIES_ALTARIA,
    }
};

static const struct TrainerMon sParty_Nicolas3[] = {
    {
    .iv = 120,
    .lvl = 54,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = 120,
    .lvl = 55,
    .species = SPECIES_FLYGON,
    },
    {
    .iv = 120,
    .lvl = 55,
    .species = SPECIES_ALTARIA,
    }
};

static const struct TrainerMon sParty_Nicolas4[] = {
    {
    .iv = 130,
    .lvl = 49,
    .species = SPECIES_SHELGON,
    },
    {
    .iv = 130,
    .lvl = 57,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = 150,
    .lvl = 56,
    .species = SPECIES_FLYGON,
    },
    {
    .iv = 130,
    .lvl = 58,
    .species = SPECIES_ALTARIA,
    }
};

static const struct TrainerMon sParty_Nicolas5[] = {
    {
    .iv = 140,
    .lvl = 60,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_NONE
    },
    {
    .iv = 120,
    .lvl = 55,
    .species = SPECIES_FLYGON,
    },
    {
    .iv = 140,
    .lvl = 60,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_NONE
    },
    {
    .iv = 240,
    .lvl = 60,
    .species = SPECIES_SALAMENCE,
    .heldItem = ITEM_DRAGON_FANG
    }
};
// Route 134 Dragon Tamer
static const struct TrainerMon sParty_Aaron[] = {
    {
    .iv = 255,
    .lvl = 34,
    .species = SPECIES_BAGON,
    .moves = {MOVE_DRAGON_BREATH, MOVE_HEADBUTT, MOVE_FOCUS_ENERGY, MOVE_EMBER}
    },
    {
    .iv = 255,
    .lvl = 44,
    .species = SPECIES_SHELGON,
    .moves = {MOVE_DRAGON_BREATH, MOVE_HEADBUTT, MOVE_FOCUS_ENERGY, MOVE_FLAMETHROWER}
    },
    {
    .iv = 255,
    .lvl = 49,
    .species = SPECIES_SHELGON,
    .moves = {MOVE_DRAGON_BREATH, MOVE_HEADBUTT, MOVE_FOCUS_ENERGY, MOVE_FIRE_BLAST}
    }
};
//Route 118 East Bird Keeper 2
static const struct TrainerMon sParty_Perry[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_PELIPPER,
    }
};
// Route 119 Bird Keeper 2
static const struct TrainerMon sParty_Hugh[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_TROPIUS,
    }
};
// Route 119 Bird Keeper 1
static const struct TrainerMon sParty_Phil[] = {
    {
    .iv = 50,
    .lvl = 28,
    .species = SPECIES_SWELLOW,
    }
};
// Fortree Gym Bird Keeper 2
static const struct TrainerMon sParty_Jared[] = {
    {
    .iv = 100,
    .lvl = 32,
    .species = SPECIES_DODUO,
    },
    {
    .iv = 100,
    .lvl = 32,
    .species = SPECIES_TROPIUS,
    }
};
// Fortree Gym Bird Keeper 1
static const struct TrainerMon sParty_Humberto[] = {
    {
    .iv = 250,
    .lvl = 34,
    .species = SPECIES_SKARMORY,
    }
};
// Route 125 Bird Keeper
static const struct TrainerMon sParty_Presley[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_TROPIUS,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_XATU,
    }
};
// Fortree Gym Bird Keeper 3 (Double Battle with Flint)
static const struct TrainerMon sParty_Edwardo[] = {
    {
    .iv = 150,
    .lvl = 33,
    .species = SPECIES_VIBRAVA,
    },
    {
    .iv = 150,
    .lvl = 32,
    .species = SPECIES_MASQUERAIN,
    }
};
// Route 120 Bird Keeper 2
static const struct TrainerMon sParty_Colin[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_XATU,
    }
};
// Route 120 Bird Keeper 1
static const struct TrainerMon sParty_Robert1[] = {
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_XATU,
    }
};
// Trick Room 6
static const struct TrainerMon sParty_Benny[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_XATU,
    }
};
//Route 118 East Bird Keeper 1
static const struct TrainerMon sParty_Chester[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_TAILLOW,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Robert2[] = {
    {
    .iv = 10,
    .lvl = 32,
    .species = SPECIES_XATU,
    },
    {
    .iv = 10,
    .lvl = 35,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Robert3[] = {
    {
    .iv = 20,
    .lvl = 35,
    .species = SPECIES_XATU,
    },
    {
    .iv = 20,
    .lvl = 35,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Robert4[] = {
    {
    .iv = 30,
    .lvl = 38,
    .species = SPECIES_XATU,
    },
    {
    .iv = 30,
    .lvl = 38,
    .species = SPECIES_SWELLOW,
    }
};

static const struct TrainerMon sParty_Robert5[] = {
    {
    .iv = 40,
    .lvl = 41,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 40,
    .lvl = 41,
    .species = SPECIES_XATU,
    }
};
// Route 134 Bird Keeper
static const struct TrainerMon sParty_Alex[] = {
    {
    .iv = 150,
    .lvl = 45,
    .species = SPECIES_XATU,
    },
    {
    .iv = 150,
    .lvl = 45,
    .species = SPECIES_SWELLOW,
    }
};
// Route 133 Bird Keeper
static const struct TrainerMon sParty_Beck[] = {
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_TROPIUS,
    }
};
// Route 119 (Post Weather Insitute) Ninja Boy 1
static const struct TrainerMon sParty_Yasu[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_NINJASK,
    }
};
// Route 119 Ninja Boy
static const struct TrainerMon sParty_Takashi[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_NINJASK,
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_KOFFING,
    }
};
// Victory Road CooltrainerF
static const struct TrainerMon sParty_Dianne[] = {
    {
    .iv = 0,
    .lvl = 48,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SKILL_SWAP, MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_NONE}
    },
    {
    .iv = 0,
    .lvl = 48,
    .species = SPECIES_LANTURN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_SURF, MOVE_NONE}
    },
    {
    .iv = 0,
    .lvl = 48,
    .species = SPECIES_MASQUERAIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SIGNAL_BEAM, MOVE_ICE_BEAM, MOVE_HYDRO_PUMP, MOVE_NONE}
    }
};
// Abandoned Ship
static const struct TrainerMon sParty_Jani[] = {
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_SPHEAL,
    }
};
// Route 113 Ninja Boy 2
static const struct TrainerMon sParty_Lao1[] = {
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SMOG, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_GULPIN,
    .moves = {MOVE_SLUDGE, MOVE_TACKLE, MOVE_ENCORE, MOVE_YAWN}
    },
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    }
};
// Route 113 Ninja Boy 1
static const struct TrainerMon sParty_Lung[] = {
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_NINCADA,
    },
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_NINJASK,
    }
};

static const struct TrainerMon sParty_Lao2[] = {
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Lao3[] = {
    {
    .iv = 20,
    .lvl = 27,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = 20,
    .lvl = 27,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = 20,
    .lvl = 27,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .iv = 20,
    .lvl = 29,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Lao4[] = {
    {
    .iv = 30,
    .lvl = 30,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .iv = 30,
    .lvl = 30,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .iv = 30,
    .lvl = 30,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_Lao5[] = {
    {
    .iv = 40,
    .lvl = 33,
    .species = SPECIES_KOFFING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE}
    },
    {
    .iv = 40,
    .lvl = 34,
    .species = SPECIES_KOFFING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_WEEZING,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_POISON_GAS, MOVE_TACKLE, MOVE_SLUDGE, MOVE_SELF_DESTRUCT}
    },
    {
    .iv = 40,
    .lvl = 38,
    .species = SPECIES_WEEZING,
    .heldItem = ITEM_SMOKE_BALL,
    .moves = {MOVE_TACKLE, MOVE_SLUDGE, MOVE_NONE, MOVE_NONE}
    }
};
// Dewford Gym Battle Girl 3 (Top Right Corner)
static const struct TrainerMon sParty_Jocelyn[] = {
    {
    .iv = 127,
    .lvl = 13,
    .species = SPECIES_MEDITITE,
    },
     {
    .iv = 150,
    .lvl = 13,
    .species = SPECIES_SHROOMISH,
    }
};
// Dewford Gym Battle Girl 1 (Bottom Right/First)
static const struct TrainerMon sParty_Laura[] = {
    {
    .iv = 150,
    .lvl = 14,
    .species = SPECIES_MEDITITE,
    }
};
// Route 115 Battle Girl
static const struct TrainerMon sParty_Cyndy1[] = {
    {
    .iv = 100,
    .lvl = 25,
    .species = SPECIES_MEDITITE,
    }
};
// Trick Room 4
static const struct TrainerMon sParty_Cora[] = {
    {
    .iv = 100,
    .lvl = 30,
    .species = SPECIES_MACHOKE,
    }
};
// Trick Room 4
static const struct TrainerMon sParty_Paula[] = {
    {
    .iv = 100,
    .lvl = 29,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Cyndy2[] = {
    {
    .iv = 110,
    .lvl = 28,
    .species = SPECIES_MEDITITE,
    }
};

static const struct TrainerMon sParty_Cyndy3[] = {
    {
    .iv = 120,
    .lvl = 32,
    .species = SPECIES_MEDICHAM,
    }
};

static const struct TrainerMon sParty_Cyndy4[] = {
    {
    .iv = 130,
    .lvl = 34,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = 130,
    .lvl = 32,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Cyndy5[] = {
    {
    .iv = 140,
    .lvl = 37,
    .species = SPECIES_MEDICHAM,
    },
    {
    .iv = 140,
    .lvl = 37,
    .species = SPECIES_HARIYAMA,
    }
};
// Route 113 Parasol Lady
static const struct TrainerMon sParty_Madeline1[] = {
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_NUMEL,
    .moves = {MOVE_EMBER, MOVE_TACKLE, MOVE_MAGNITUDE, MOVE_SUNNY_DAY}
    }
};
// Route 120 Parasol Lady 1
static const struct TrainerMon sParty_Clarissa[] = {
    {
    .iv = 0,
    .lvl = 31,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 0,
    .lvl = 31,
    .species = SPECIES_WAILMER,
    }
};
// Route 120 Parasol Lady 2
static const struct TrainerMon sParty_Angelica[] = {
    {
    .iv = 50,
    .lvl = 33,
    .species = SPECIES_CASTFORM,
    .moves = {MOVE_RAIN_DANCE, MOVE_WEATHER_BALL, MOVE_THUNDER, MOVE_WATER_PULSE}
    }
};

static const struct TrainerMon sParty_Madeline2[] = {
    {
    .iv = 10,
    .lvl = 29,
    .species = SPECIES_NUMEL,
    .moves = {MOVE_EMBER, MOVE_TACKLE, MOVE_MAGNITUDE, MOVE_SUNNY_DAY}
    }
};

static const struct TrainerMon sParty_Madeline3[] = {
    {
    .iv = 20,
    .lvl = 33,
    .species = SPECIES_CAMERUPT,
    .moves = {MOVE_EMBER, MOVE_TAKE_DOWN, MOVE_MAGNITUDE, MOVE_SUNNY_DAY}
    }
};

static const struct TrainerMon sParty_Madeline4[] = {
    {
    .iv = 30,
    .lvl = 34,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_LEECH_SEED, MOVE_MEGA_DRAIN, MOVE_GRASS_WHISTLE, MOVE_SUNNY_DAY}
    },
    {
    .iv = 30,
    .lvl = 35,
    .species = SPECIES_CAMERUPT,
    .moves = {MOVE_FLAMETHROWER, MOVE_TAKE_DOWN, MOVE_MAGNITUDE, MOVE_SUNNY_DAY}
    }
};

static const struct TrainerMon sParty_Madeline5[] = {
    {
    .iv = 40,
    .lvl = 37,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY}
    },
    {
    .iv = 40,
    .lvl = 39,
    .species = SPECIES_CAMERUPT,
    .moves = {MOVE_FLAMETHROWER, MOVE_TAKE_DOWN, MOVE_EARTHQUAKE, MOVE_SUNNY_DAY}
    }
};
// Route 105 SwimmerF
static const struct TrainerMon sParty_Beverly[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_TENTACOOL,
    }
};
// Route 105 SwimmerF
static const struct TrainerMon sParty_Imani[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_CORSOLA,
    }
};
// Route 106 Surf SwimmerF
static const struct TrainerMon sParty_Kyla[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_WAILMER,
    }
};
// Route 107 SwimmerF
static const struct TrainerMon sParty_Denise[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_SPHEAL,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_GOLDEEN,
    }
};
// Route 107 SwimmerF
static const struct TrainerMon sParty_Beth[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_CORSOLA,
    }
};
// Route 108 SwimmerF
static const struct TrainerMon sParty_Tara[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_HORSEA,
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_AZUMARILL,
    }
};
// Route 108 SwimmerF
static const struct TrainerMon sParty_Missy[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_GOLDEEN,
    }
};
//Route 109 Surf SwimmerF
static const struct TrainerMon sParty_Alice[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_GOLDEEN,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_GOLDEEN,
    }
};
// Route 124 SwimmerF
static const struct TrainerMon sParty_Jenny1[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_WAILMER
    }
};
// Route 124 SwimmerF
static const struct TrainerMon sParty_Grace[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_WHISCASH,
    },
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_WHISCASH,
    }
};
// Route 125 SwimmerF
static const struct TrainerMon sParty_Tanya[] = {
    {
    .iv = 0,
    .lvl = 39,
    .species = SPECIES_LUVDISC,
    }
};
// Route 125 SwimmerF
static const struct TrainerMon sParty_Sharon[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_SEAKING,
    }
};
// Route 126 SwimmerF
static const struct TrainerMon sParty_Nikki[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_SEALEO,
    }
};
// Route 126
static const struct TrainerMon sParty_Brenda[] = {
    {
    .iv = 0,
    .lvl = 39,
    .species = SPECIES_SEAKING,
    }
};
// Route 130 SwimmerF (Potential Double with Santiago)
static const struct TrainerMon sParty_Katie[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_SEAKING,
    },
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_WALREIN,
    }
};
// Route 131 SwimmerF
static const struct TrainerMon sParty_Susie[] = {
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_LUVDISC,
    }
};
// Route 131 SwimmerF
static const struct TrainerMon sParty_Kara[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_SEAKING,
    }
};
// Route 132 SwimmerF
static const struct TrainerMon sParty_Dana[] = {
    {
    .iv = 0,
    .lvl = 44,
    .species = SPECIES_AZUMARILL,
    }
};
// Route 126 SwimmerF
static const struct TrainerMon sParty_Sienna[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_PELIPPER,
    }
};
// Route 133 SwimmerF
static const struct TrainerMon sParty_Debra[] = {
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_SEAKING,
    }
};
// Route 133 SwimmerF
static const struct TrainerMon sParty_Linda[] = {
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_SEADRA,
    },
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_SEADRA,
    }
};

static const struct TrainerMon sParty_Kaylee[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_LANTURN,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_PELIPPER,
    }
};
// Route 134 SwimmerF
static const struct TrainerMon sParty_Laurel[] = {
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_LUVDISC,
    },
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_LUVDISC,
    }
};
// Route 128 SwimmerF
static const struct TrainerMon sParty_Carlee[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_GOREBYSS,
    }
};

static const struct TrainerMon sParty_Jenny2[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = 100,
    .lvl = 38,
    .species = SPECIES_WAILMER,
    }
};

static const struct TrainerMon sParty_Jenny3[] = {
    {
    .iv = 0,
    .lvl = 39,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = 0,
    .lvl = 41,
    .species = SPECIES_WAILORD,
    }
};

static const struct TrainerMon sParty_Jenny4[] = {
    {
    .iv = 0,
    .lvl = 41,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_WAILORD,
    }
};

static const struct TrainerMon sParty_Jenny5[] = {
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_LUVDISC,
    },
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_WAILORD,
    },
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_AZUMARILL,
    },
};
//Route 111 Desert Picnicker 1
static const struct TrainerMon sParty_Heidi[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_SANDSHREW,
    .moves = {MOVE_DIG, MOVE_SAND_ATTACK, MOVE_POISON_STING, MOVE_SLASH}
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_CACNEA,
    .moves = {MOVE_ABSORB, MOVE_MUD_SLAP, MOVE_PURSUIT, MOVE_SPIKES}
    }
};
//Route 111 Desert Picnicker 2
static const struct TrainerMon sParty_Becky[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_BALTOY,
    .moves = {MOVE_MUD_SLAP, MOVE_RAPID_SPIN, MOVE_PSYBEAM, MOVE_DIG}
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_MARILL,
    .moves = {MOVE_ROLLOUT, MOVE_BUBBLE_BEAM, MOVE_TAIL_WHIP, MOVE_DEFENSE_CURL}
    }
};
// Route 112 South Section Picnicker 1
static const struct TrainerMon sParty_Carol[] = {
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_TAILLOW,
    },
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_LOMBRE,
    }
};
// Route 114 Picnicker 2
static const struct TrainerMon sParty_Nancy[] = {
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_MARILL,
    },
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_LOMBRE,
    }
};
// Trick House 3 Picknicker
static const struct TrainerMon sParty_Martha[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_SKITTY,
    },
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_SPOINK,
    }
};
// Jagged Pass Picnicker
static const struct TrainerMon sParty_Diana1[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_VULPIX,
    },
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_SWABLU,
    }
};
// Mt Pyre Interior 6F PsychicM
static const struct TrainerMon sParty_Cedric[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_WOBBUFFET,
    .moves = {MOVE_DESTINY_BOND, MOVE_SAFEGUARD, MOVE_COUNTER, MOVE_MIRROR_COAT}
    }
};
//Route 111 Mid Picnicker
static const struct TrainerMon sParty_Irene[] = {
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_MARILL,
    }
};

static const struct TrainerMon sParty_Diana2[] = {
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_VULPIX,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_GLOOM,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_SWABLU,
    }
};

static const struct TrainerMon sParty_Diana3[] = {
    {
    .iv = 20,
    .lvl = 31,
    .species = SPECIES_VULPIX,
    },
    {
    .iv = 20,
    .lvl = 30,
    .species = SPECIES_VILEPLUME,
    },
    {
    .iv = 20,
    .lvl = 31,
    .species = SPECIES_SWABLU,
    }
};

static const struct TrainerMon sParty_Diana4[] = {
    {
    .iv = 30,
    .lvl = 35,
    .species = SPECIES_VULPIX,
    },
    {
    .iv = 30,
    .lvl = 34,
    .species = SPECIES_VILEPLUME,
    },
    {
    .iv = 30,
    .lvl = 35,
    .species = SPECIES_ALTARIA,
    }
};

static const struct TrainerMon sParty_Diana5[] = {
   {
    .iv = 40,
    .lvl = 40,
    .species = SPECIES_NINETALES,
    },
    {
    .iv = 40,
    .lvl = 40,
    .species = SPECIES_VILEPLUME,
    },
    {
    .iv = 40,
    .lvl = 40,
    .species = SPECIES_ALTARIA,
    }
};
// Route 103 Twins
static const struct TrainerMon sParty_AmyAndLiv1[] = {
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_PLUSLE,
    .moves = {MOVE_THUNDER_SHOCK, MOVE_GROWL, MOVE_LIGHT_SCREEN, MOVE_QUICK_ATTACK}
    },
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_MINUN,
    .moves = {MOVE_THUNDER_SHOCK, MOVE_GROWL, MOVE_FLASH, MOVE_QUICK_ATTACK}
    }
};

static const struct TrainerMon sParty_AmyAndLiv2[] = {
    {
    .iv = 10,
    .lvl = 27,
    .species = SPECIES_PLUSLE,
    },
    {
    .iv = 10,
    .lvl = 27,
    .species = SPECIES_MINUN,
    }
};
//Route 104 North Twins
static const struct TrainerMon sParty_GinaAndMia1[] = {
    {
    .iv = 0,
    .lvl = 6,
    .species = SPECIES_SEEDOT,
    },
    {
    .iv = 0,
    .lvl = 6,
    .species = SPECIES_LOTAD,
    }
};
// Route 123 (via 118 from mauville) Twins
static const struct TrainerMon sParty_MiuAndYuki[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_BEAUTIFLY,
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_DUSTOX,
    }
};

static const struct TrainerMon sParty_AmyAndLiv3[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_PLUSLE,
    },
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_MINUN,
    }
};

static const struct TrainerMon sParty_GinaAndMia2[] = {
    {
    .iv = 0,
    .lvl = 10,
    .species = SPECIES_DUSKULL,
    .moves = {MOVE_NIGHT_SHADE, MOVE_DISABLE, MOVE_NONE, MOVE_NONE}
    },
    {
    .iv = 0,
    .lvl = 10,
    .species = SPECIES_SHROOMISH,
    .moves = {MOVE_ABSORB, MOVE_LEECH_SEED, MOVE_NONE, MOVE_NONE}
    }
};

static const struct TrainerMon sParty_AmyAndLiv4[] = {
    {
    .iv = 20,
    .lvl = 32,
    .species = SPECIES_PLUSLE,
    },
    {
    .iv = 20,
    .lvl = 32,
    .species = SPECIES_MINUN,
    }
};

static const struct TrainerMon sParty_AmyAndLiv5[] = {
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_PLUSLE,
    .moves = {MOVE_THUNDERBOLT, MOVE_CHARGE, MOVE_FAKE_TEARS, MOVE_HELPING_HAND}
    },
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_MINUN,
    .moves = {MOVE_THUNDERBOLT, MOVE_CHARGE, MOVE_CHARM, MOVE_HELPING_HAND}
    }
};

static const struct TrainerMon sParty_AmyAndLiv6[] = {
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_PLUSLE,
    .moves = {MOVE_THUNDER, MOVE_CHARGE, MOVE_FAKE_TEARS, MOVE_HELPING_HAND}
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_MINUN,
    .moves = {MOVE_THUNDER, MOVE_CHARGE, MOVE_CHARM, MOVE_HELPING_HAND}
    }
};
// Route 109 Sailor 1
static const struct TrainerMon sParty_Huey[] = {
    {
    .iv = 10,
    .lvl = 14,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = 10,
    .lvl = 14,
    .species = SPECIES_MACHOP,
    }
};
// Route 109 Sailor 2 (Potential Double Battle w Hailey or Ricky)
static const struct TrainerMon sParty_Edmond[] = {
    {
    .iv = 0,
    .lvl = 15,
    .species = SPECIES_SPHEAL,
    }
};
// Route 125 Sailor
static const struct TrainerMon sParty_Ernest1[] = {
    {
    .iv = 0,
    .lvl = 37,
    .species = SPECIES_PILOSWINE,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_SNORUNT,
    },
    {
    .iv = 0,
    .lvl = 37,
    .species = SPECIES_HARIYAMA,
    }
};
// Route 109 Seashore House Sailor
static const struct TrainerMon sParty_Dwayne[] = {
    {
    .iv = 0,
    .lvl = 13,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 0,
    .lvl = 13,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = 0,
    .lvl = 13,
    .species = SPECIES_CLAMPERL,
    }
};
// SS Tidal Storage Sailor (nat dex)
static const struct TrainerMon sParty_Phillip[] = {
    {
    .iv = 255,
    .lvl = 48,
    .species = SPECIES_MANKEY,
    },
    {
    .iv = 255,
    .lvl = 49,
    .species = SPECIES_POLIWRATH,
    },
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_PRIMEAPE,
    }
};
// SS Tidal Storage Sailor (nat dex)
static const struct TrainerMon sParty_Leonard[] = {
    {
    .iv = 255,
    .lvl = 48,
    .species = SPECIES_POLIWHIRL,
    },
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_HITMONTOP,
    },
    {
    .iv = 255,
    .lvl = 51,
    .species = SPECIES_QWILFISH,
    }
};
// Abandoned Ship Sailor
static const struct TrainerMon sParty_Duncan[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_SPHEAL,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Ernest2[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_MACHAMP,
    }
};

static const struct TrainerMon sParty_Ernest3[] = {
    {
    .iv = 20,
    .lvl = 40,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_MACHAMP,
    }
};

static const struct TrainerMon sParty_Ernest4[] = {
    {
    .iv = 20,
    .lvl = 43,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_MACHAMP,
    }
};

static const struct TrainerMon sParty_Ernest5[] = {
    {
    .iv = 20,
    .lvl = 45,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_MACHAMP,
    }
};
// Lavaridge Gym Hiker
static const struct TrainerMon sParty_Eli[] = {
    {
    .iv = 100,
    .lvl = 27,
    .species = SPECIES_GRAVELER,
    }
};
//Sootopolis Gym Pokefan 1 (Middle Level - Double Battle w Daphne)
static const struct TrainerMon sParty_Annika[] = {
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_FEEBAS,
    .heldItem = ITEM_BRIGHT_POWDER,
    .moves = {MOVE_SURF, MOVE_BLIZZARD, MOVE_RAIN_DANCE, MOVE_ATTRACT}
    },
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_FEEBAS,
    .heldItem = ITEM_BRIGHT_POWDER,
    .moves = {MOVE_SURF, MOVE_BLIZZARD, MOVE_RAIN_DANCE, MOVE_ATTRACT}
    }
};
// Route 123 (via 118 from mauville) CooltrainerF
static const struct TrainerMon sParty_Jazmyn[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_ABSOL,
    }
};
// Route 123 (via 123 with Cut) Ninja Boy
static const struct TrainerMon sParty_Jonas[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_WEEZING,
    .moves = {MOVE_TOXIC, MOVE_THUNDER, MOVE_SELF_DESTRUCT, MOVE_SLUDGE_BOMB}
    }
};
// Route 123 (via 123 with Cut) 
static const struct TrainerMon sParty_Kayley[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_CASTFORM,
    .moves = {MOVE_SUNNY_DAY, MOVE_WEATHER_BALL, MOVE_FLAMETHROWER, MOVE_SOLAR_BEAM}
    }
};
// Route 125 Expert
static const struct TrainerMon sParty_Auron[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_GLALIE,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_BANETTE,
    }
};
// Route 134 Sailor
static const struct TrainerMon sParty_Kelvin[] = {
    {
    .iv = 150,
    .lvl = 45,
    .species = SPECIES_MACHAMP,
    },
    {
    .iv = 150,
    .lvl = 45,
    .species = SPECIES_WALREIN,
    }
};
// Route 134 CooltrainerF
static const struct TrainerMon sParty_Marley[] = {
    {
    .iv = 255,
    .lvl = 46,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CRUNCH, MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE, MOVE_THUNDERBOLT}
    }
};
// Route 134 Battle Girl
static const struct TrainerMon sParty_Reyna[] = {
    {
    .iv = 200,
    .lvl = 45,
    .species = SPECIES_PINSIR,
    },
    {
    .iv = 50,
    .lvl = 45,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 200,
    .lvl = 45,
    .species = SPECIES_HERACROSS,
    }
};
// Route 134 Sailor
static const struct TrainerMon sParty_Hudson[] = {
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_WAILORD,
    },
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_MACHAMP,
    }
};
// Route 133 Expert
static const struct TrainerMon sParty_Conor[] = {
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_HERACROSS,
    },
    {
    .iv = 200,
    .lvl = 45,
    .species = SPECIES_DONPHAN,
    }
};
//Route 110 Collector (Potential Double Battle with Joseph)
static const struct TrainerMon sParty_Edwin1[] = {
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_NUZLEAF,
    }
};
// Route 115 Collector
static const struct TrainerMon sParty_Hector[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_ZANGOOSE,
    }
};
// Magma Admin Space Center (Double SC)
static const struct TrainerMon sParty_TabithaMossdeep[] = {
    {
    .iv = 150,
    .lvl = 43,
    .species = SPECIES_CROBAT,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_WING_ATTACK, MOVE_GIGA_DRAIN, MOVE_POISON_FANG, MOVE_CONFUSE_RAY}
    },
    {
    .iv = 150,
    .lvl = 43,
    .species = SPECIES_AGGRON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_IRON_TAIL, MOVE_PROTECT}
    },
    {
    .iv = 150,
    .lvl = 44,
    .species = SPECIES_ZANGOOSE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CRUSH_CLAW, MOVE_FAINT_ATTACK, MOVE_SUNNY_DAY,  MOVE_SWORDS_DANCE}
    }
};

static const struct TrainerMon sParty_Edwin2[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_NUZLEAF,
    }
};

static const struct TrainerMon sParty_Edwin3[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_NUZLEAF,
    }
};

static const struct TrainerMon sParty_Edwin4[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_SHIFTRY,
    }
};

static const struct TrainerMon sParty_Edwin5[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_LUDICOLO,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_SHIFTRY,
    }
};
// Victory Road Pre Champion
static const struct TrainerMon sParty_WallyVR1[] = {
    {
    .iv = 150,
    .lvl = 49,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_SING, MOVE_DOUBLE_EDGE, MOVE_CHARM, MOVE_FAINT_ATTACK}
    },
    {
    .iv = 200,
    .lvl = 48,
    .species = SPECIES_AZUMARILL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_DOUBLE_EDGE, MOVE_SUPERPOWER, MOVE_ICE_BEAM}
    },
    {
    .iv = 200,
    .lvl = 49,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_SHARP_BEAK,
    .moves = {MOVE_AERIAL_ACE, MOVE_EARTHQUAKE, MOVE_FIRE_BLAST, MOVE_DRAGON_DANCE}
    },
    {
    .iv = 150,
    .lvl = 48,
    .species = SPECIES_ROSELIA,
    .heldItem = ITEM_PERSIM_BERRY,
    .moves = {MOVE_PETAL_DANCE, MOVE_LEECH_SEED, MOVE_SLUDGE_BOMB, MOVE_TOXIC}
    },
    {
    .iv = 150,
    .lvl = 49,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_FOCUS_BAND,
    .moves = {MOVE_THUNDERBOLT, MOVE_TRI_ATTACK, MOVE_LIGHT_SCREEN, MOVE_THUNDER_WAVE}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_GARDEVOIR,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_DOUBLE_TEAM}
    }
};
// Rival 1
static const struct TrainerMon sParty_BrendanRoute103Mudkip[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_TREECKO,
    }
};
// Rival 3
static const struct TrainerMon sParty_BrendanRoute110Mudkip[] = {
    {
    .iv = 50,
    .lvl = 20,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_CONFUSION, MOVE_TACKLE, MOVE_CONFUSE_RAY, MOVE_PSYCH_UP}
    },
    {
    .iv = 50,
    .lvl = 18,
    .species = SPECIES_TORKOAL,
    .moves = {MOVE_SMOG, MOVE_EMBER, MOVE_SMOKESCREEN, MOVE_FIRE_SPIN}
    },
    {
    .iv = 100,
    .lvl = 22,
    .species = SPECIES_GROVYLE,
    .moves = {MOVE_ABSORB, MOVE_QUICK_ATTACK, MOVE_FALSE_SWIPE, MOVE_RAZOR_LEAF}
    }
};
// Route 119 Rival 4 w Treecko
static const struct TrainerMon sParty_BrendanRoute119Mudkip[] = {
   {
    .iv = 100,
    .lvl = 34,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_TORKOAL,
    .moves = {MOVE_CURSE, MOVE_BODY_SLAM, MOVE_FLAMETHROWER, MOVE_SUNNY_DAY}
    },
    {
    .iv = 150,
    .lvl = 35,
    .species = SPECIES_GROVYLE,
    .moves = {MOVE_ROCK_TOMB, MOVE_RAZOR_LEAF, MOVE_GROWTH, MOVE_SLASH}
    }
};
// Rival 1
static const struct TrainerMon sParty_BrendanRoute103Treecko[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_TORCHIC,
    }
};
// Rival 3
static const struct TrainerMon sParty_BrendanRoute110Treecko[] = {
    {
    .iv = 50,
    .lvl = 20,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_CONFUSION, MOVE_TACKLE, MOVE_CONFUSE_RAY, MOVE_PSYCH_UP}
    },
    {
    .iv = 10,
    .lvl = 18,
    .species = SPECIES_WAILMER,
    .moves = {MOVE_GROWL, MOVE_WATER_GUN, MOVE_WHIRLPOOL, MOVE_ASTONISH}
    },
    {
    .iv = 100,
    .lvl = 22,
    .species = SPECIES_COMBUSKEN,
    .moves = {MOVE_PECK, MOVE_FOCUS_ENERGY, MOVE_EMBER, MOVE_DOUBLE_KICK}
    }
};
// Route 119 Rival 4 w Torchic
static const struct TrainerMon sParty_BrendanRoute119Treecko[] = {
    {
    .iv = 100,
    .lvl = 34,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_WAILMER,
    .moves = {MOVE_WATER_PULSE, MOVE_ICE_BEAM, MOVE_GROWL, MOVE_ASTONISH}
    },
    {
    .iv = 150,
    .lvl = 35,
    .species = SPECIES_COMBUSKEN,
    .moves = {MOVE_FIRE_PUNCH, MOVE_ROLLING_KICK, MOVE_BULK_UP, MOVE_SUNNY_DAY}
    }
};
// Rival 1
static const struct TrainerMon sParty_BrendanRoute103Torchic[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_MUDKIP,
    }
};
// Rival 3
static const struct TrainerMon sParty_BrendanRoute110Torchic[] = {
    {
    .iv = 50,
    .lvl = 20,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_CONFUSION, MOVE_TACKLE, MOVE_CONFUSE_RAY, MOVE_PSYCH_UP}
    },
    {
    .iv = 220,
    .lvl = 18,
    .species = SPECIES_SHROOMISH,
    .moves = {MOVE_TACKLE, MOVE_STUN_SPORE, MOVE_LEECH_SEED, MOVE_MEGA_DRAIN}
    },
    {
    .iv = 100,
    .lvl = 22,
    .species = SPECIES_MARSHTOMP,
    .moves = {MOVE_MUD_SHOT, MOVE_ROCK_TOMB, MOVE_WATER_GUN, MOVE_TACKLE}
    }
};
// Route 119 Rival 4 w Mudkip
static const struct TrainerMon sParty_BrendanRoute119Torchic[] = {
    {
    .iv = 100,
    .lvl = 34,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_BRELOOM,
    .moves = {MOVE_MEGA_DRAIN, MOVE_HEADBUTT, MOVE_MACH_PUNCH, MOVE_LEECH_SEED}
    },
    {
    .iv = 150,
    .lvl = 35,
    .species = SPECIES_MARSHTOMP,
    .moves = {MOVE_MUD_SHOT, MOVE_ROCK_TOMB, MOVE_TAKE_DOWN, MOVE_BUBBLE_BEAM}
    }
};
// Rival 1
static const struct TrainerMon sParty_MayRoute103Mudkip[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_TREECKO,
    }
};
// Rival 3
static const struct TrainerMon sParty_MayRoute110Mudkip[] = {
    {
    .iv = 50,
    .lvl = 20,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_CONFUSION, MOVE_TACKLE, MOVE_CONFUSE_RAY, MOVE_PSYCH_UP}
    },
    {
    .iv = 50,
    .lvl = 18,
    .species = SPECIES_TORKOAL,
    .moves = {MOVE_SMOG, MOVE_EMBER, MOVE_SMOKESCREEN, MOVE_FIRE_SPIN}
    },
    {
    .iv = 100,
    .lvl = 22,
    .species = SPECIES_GROVYLE,
    .moves = {MOVE_ABSORB, MOVE_QUICK_ATTACK, MOVE_FALSE_SWIPE, MOVE_RAZOR_LEAF}
    }
};
// Route 119 Rival 4 w Treecko
static const struct TrainerMon sParty_MayRoute119Mudkip[] = {
    {
    .iv = 100,
    .lvl = 34,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_TORKOAL,
    .moves = {MOVE_CURSE, MOVE_BODY_SLAM, MOVE_FLAMETHROWER, MOVE_SUNNY_DAY}
    },
    {
    .iv = 150,
    .lvl = 35,
    .species = SPECIES_GROVYLE,
    .moves = {MOVE_ROCK_TOMB, MOVE_RAZOR_LEAF, MOVE_GROWTH, MOVE_SLASH}
    }
};
// Rival 1
static const struct TrainerMon sParty_MayRoute103Treecko[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_TORCHIC,
    }
};
// Rival 3
static const struct TrainerMon sParty_MayRoute110Treecko[] = {
    {
    .iv = 50,
    .lvl = 20,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_CONFUSION, MOVE_TACKLE, MOVE_CONFUSE_RAY, MOVE_PSYCH_UP}
    },
    {
    .iv = 10,
    .lvl = 18,
    .species = SPECIES_WAILMER,
    .moves = {MOVE_GROWL, MOVE_WATER_GUN, MOVE_WHIRLPOOL, MOVE_ASTONISH}
    },
    {
    .iv = 100,
    .lvl = 22,
    .species = SPECIES_COMBUSKEN,
    .moves = {MOVE_PECK, MOVE_FOCUS_ENERGY, MOVE_EMBER, MOVE_DOUBLE_KICK}
    }
};
// Route 119 Rival 4 w Torchic
static const struct TrainerMon sParty_MayRoute119Treecko[] = {
    {
    .iv = 100,
    .lvl = 34,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_WAILMER,
    .moves = {MOVE_WATER_PULSE, MOVE_ICE_BEAM, MOVE_GROWL, MOVE_ASTONISH}
    },
    {
    .iv = 150,
    .lvl = 35,
    .species = SPECIES_COMBUSKEN,
    .moves = {MOVE_FIRE_PUNCH, MOVE_ROLLING_KICK, MOVE_BULK_UP, MOVE_SUNNY_DAY}
    }
};
// Rival 1 
static const struct TrainerMon sParty_MayRoute103Torchic[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_MUDKIP,
    }
};
// Rival 3
static const struct TrainerMon sParty_MayRoute110Torchic[] = {
    {
    .iv = 50,
    .lvl = 20,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_CONFUSION, MOVE_TACKLE, MOVE_CONFUSE_RAY, MOVE_PSYCH_UP}
    },
    {
    .iv = 220,
    .lvl = 18,
    .species = SPECIES_SHROOMISH,
    .moves = {MOVE_TACKLE, MOVE_STUN_SPORE, MOVE_LEECH_SEED, MOVE_MEGA_DRAIN}
    },
    {
    .iv = 100,
    .lvl = 22,
    .species = SPECIES_MARSHTOMP,
    .moves = {MOVE_MUD_SHOT, MOVE_ROCK_TOMB, MOVE_WATER_GUN, MOVE_TACKLE}
    }
};
// Route 119 Rival 4 w Mudkip
static const struct TrainerMon sParty_MayRoute119Torchic[] = {
    {
    .iv = 100,
    .lvl = 34,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYBEAM}
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_BRELOOM,
    .moves = {MOVE_MEGA_DRAIN, MOVE_HEADBUTT, MOVE_MACH_PUNCH, MOVE_LEECH_SEED}
    },
    {
    .iv = 150,
    .lvl = 35,
    .species = SPECIES_MARSHTOMP,
    .moves = {MOVE_MUD_SHOT, MOVE_ROCK_TOMB, MOVE_TAKE_DOWN, MOVE_BUBBLE_BEAM}
    }
};
// Route 117 BreederM
static const struct TrainerMon sParty_Isaac1[] = {
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_SNORUNT,
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_ARON,
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_POOCHYENA,
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_TAILLOW,
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_MAKUHITA,
    }
};
// Route 123 (via 118 from mauville) Bug Catcher
static const struct TrainerMon sParty_Davis[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_PINSIR,
    }
};
// Victory Road CooltrainerM
static const struct TrainerMon sParty_Mitchell[] = {
    {
    .iv = 0,
    .lvl = 48,
    .species = SPECIES_LUNATONE,
    .moves = {MOVE_EXPLOSION, MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_PSYCHIC}
    },
    {
    .iv = 0,
    .lvl = 48,
    .species = SPECIES_SOLROCK,
    .moves = {MOVE_EXPLOSION, MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_SHADOW_BALL}
    }
};

static const struct TrainerMon sParty_Isaac2[] = {
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_SNORUNT,
    },
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_ARON,
    },
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_MAKUHITA,
    }
};

static const struct TrainerMon sParty_Isaac3[] = {
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_SNORUNT,
    },
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_ARON,
    },
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Isaac4[] = {
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_SNORUNT
    },
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_ARON,
    },
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_HARIYAMA,
    }
};

static const struct TrainerMon sParty_Isaac5[] = {
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_GLALIE,
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_LAIRON,
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_HARIYAMA,
    }
};
// Route 117 BreederF
static const struct TrainerMon sParty_Lydia1[] = {
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_MARILL,
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_SKITTY,
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_GOLDEEN,
    }
};
// Victory Road CooltrainerM
static const struct TrainerMon sParty_Halle[] = {
    {
    .iv = 0,
    .lvl = 47,
    .species = SPECIES_SABLEYE,
    },
    {
    .iv = 0,
    .lvl = 47,
    .species = SPECIES_ABSOL,
    }
};
// Abandoned Ship
static const struct TrainerMon sParty_Garrison[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_RELICANTH,
    }
};

static const struct TrainerMon sParty_Lydia2[] = {
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_WINGULL,
    },
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_MARILL,
    },
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_SKITTY,
    },
    {
    .iv = 10,
    .lvl = 22,
    .species = SPECIES_GOLDEEN,
    }
};

static const struct TrainerMon sParty_Lydia3[] = {
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_MARILL,
    },
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_DELCATTY,
    },
    {
    .iv = 20,
    .lvl = 25,
    .species = SPECIES_GOLDEEN,
    }
};

static const struct TrainerMon sParty_Lydia4[] = {
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_MARILL,
    },
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_DELCATTY,
    },
    {
    .iv = 30,
    .lvl = 28,
    .species = SPECIES_GOLDEEN,
    }
};

static const struct TrainerMon sParty_Lydia5[] = {
    {
    .iv = 40,
    .lvl = 34,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 40,
    .lvl = 34,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 40,
    .lvl = 34,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = 40,
    .lvl = 35,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 40,
    .lvl = 35,
    .species = SPECIES_DELCATTY,
    },
    {
    .iv = 40,
    .lvl = 36,
    .species = SPECIES_SEAKING,
    }
};
// Route 119 Pokemon RangerM
static const struct TrainerMon sParty_Jackson1[] = {
    {
    .iv = 50,
    .lvl = 27,
    .species = SPECIES_BRELOOM,
    }
};
// Route 120 Pokemon RangerM
static const struct TrainerMon sParty_Lorenzo[] = {
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_SEEDOT,
    },
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_NUZLEAF,
    },
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_SHIFTRY,
    }
};
// Trick Room 6
static const struct TrainerMon sParty_Sebastian[] = {
    {
    .iv = 50,
    .lvl = 40,
    .species = SPECIES_CACTURNE,
    }
};

static const struct TrainerMon sParty_Jackson2[] = {
    {
    .iv = 60,
    .lvl = 31,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Jackson3[] = {
    {
    .iv = 70,
    .lvl = 35,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Jackson4[] = {
    {
    .iv = 80,
    .lvl = 39,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Jackson5[] = {
    {
    .iv = 90,
    .lvl = 39,
    .species = SPECIES_KECLEON,
    },
    {
    .iv = 90,
    .lvl = 42,
    .species = SPECIES_BRELOOM,
    }
};
// Route 119 Pokemon RangerF 
static const struct TrainerMon sParty_Catherine1[] = {
    {
    .iv = 50,
    .lvl = 27,
    .species = SPECIES_HERACROSS,
    }
};
// Route 120 Pokemon RangerF
static const struct TrainerMon sParty_Jenna[] = {
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_LOTAD,
    },
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_LUDICOLO,
    }
};
// Trick Room 6
static const struct TrainerMon sParty_Sophia[] = {
    {
    .iv = 200,
    .lvl = 38,
    .species = SPECIES_VIBRAVA,
    },
    {
    .iv = 50,
    .lvl = 38,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Catherine2[] = {
    {
    .iv = 60,
    .lvl = 30,
    .species = SPECIES_HERACROSS,
    },
};

static const struct TrainerMon sParty_Catherine3[] = {
    {
    .iv = 70,
    .lvl = 33,
    .species = SPECIES_HERACROSS,
    },
    {
    .iv = 70,
    .lvl = 33,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Catherine4[] = {
    {
    .iv = 80,
    .lvl = 36,
    .species = SPECIES_HERACROSS,
    },
    {
    .iv = 80,
    .lvl = 36,
    .species = SPECIES_ROSELIA,
    }
};

static const struct TrainerMon sParty_Catherine5[] = {
    {
    .iv = 90,
    .lvl = 40,
    .species = SPECIES_HERACROSS,
    },
    {
    .iv = 90,
    .lvl = 40,
    .species = SPECIES_ROSELIA,
    }
};
// Jagged Pass Triathlete
static const struct TrainerMon sParty_Julio[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_MAGNEMITE,
    }
};
// Seafloor Cavern (Double with shelly)
static const struct TrainerMon sParty_GruntSeafloorCavern5[] = {
    {
    .iv = 50,
    .lvl = 44,
    .species = SPECIES_MIGHTYENA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CRUNCH, MOVE_TAKE_DOWN, MOVE_PROTECT, MOVE_SCARY_FACE}
    },
    {
    .iv = 100,
    .lvl = 43,
    .species = SPECIES_TENTACRUEL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RAIN_DANCE, MOVE_SLUDGE_BOMB}
    }, 
    {
    .iv = 100,
    .lvl = 43,
    .species = SPECIES_SNEASEL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FAINT_ATTACK, MOVE_BLIZZARD, MOVE_METAL_CLAW, MOVE_SLASH}
    }
};

static const struct TrainerMon sParty_GruntUnused[] = {
    {
    .iv = 0,
    .lvl = 31,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = 0,
    .lvl = 31,
    .species = SPECIES_ZUBAT,
    }
};
// UNUSED Mt Pyre Summit Aqua GruntF (Double Battle with GruntM 3)
static const struct TrainerMon sParty_GruntMtPyre4[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_SEADRA,
    }
};
// Jagged Pass Magma Grunt
static const struct TrainerMon sParty_GruntJaggedPass[] = {
    {
    .iv = 50,
    .lvl = 26,
    .species = SPECIES_ZANGOOSE,
    },
    {
    .iv = 50,
    .lvl = 26,
    .species = SPECIES_NUMEL,
    }
};
//Rustboro Gym Hiker 1 (Potential Double Battle with Tommy)
static const struct TrainerMon sParty_Marc[] = {
    {
    .iv = 110,
    .lvl = 9,
    .species = SPECIES_ARON,
    },
    {
    .iv = 130,
    .lvl = 10,
    .species = SPECIES_GEODUDE,
    }
};
// Dewford Gym Sailor 1 (Double Battle w Lilith)
static const struct TrainerMon sParty_Brendan[] = {
    {
    .iv = 100,
    .lvl = 13,
    .species = SPECIES_MACHOP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LOW_KICK, MOVE_LEER, MOVE_FOCUS_ENERGY, MOVE_FORESIGHT}
    },
    {
    .iv = 100,
    .lvl = 13,
    .species = SPECIES_CORPHISH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROCK_SMASH, MOVE_BUBBLE, MOVE_HARDEN, MOVE_VICE_GRIP}
    }
};
// Dewford Gym Battle Girl 2 (Double Battle w Brendan)
static const struct TrainerMon sParty_Lilith[] = {
    {
    .iv = 150,
    .lvl = 13,
    .species = SPECIES_MEDITITE,
    },
    {
    .iv = 100,
    .lvl = 13,
    .species = SPECIES_MEDITITE,
    }
};
// Dewford Gym Black Belt 2 (Top Middle)
static const struct TrainerMon sParty_Cristian[] = {
    {
    .iv = 127,
    .lvl = 12,
    .species = SPECIES_MACHOP,
    },
    {
    .iv = 200,
    .lvl = 14,
    .species = SPECIES_MAKUHITA,
    },
    {
    .iv = 127,
    .lvl = 12,
    .species = SPECIES_MACHOP,
    }
};
// Mossdeep Gym Hex Maniac 2 - Northwest (Double Battle w Hannah or Virgil)
static const struct TrainerMon sParty_Sylvia[] = {
    {
    .iv = 100,
    .lvl = 40,
    .species = SPECIES_MEDICHAM,
    }
};
// Route 126 SwimmerM
static const struct TrainerMon sParty_Leonardo[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_SHARPEDO,
    }
};
// Route 127 CooltrainerF 
static const struct TrainerMon sParty_Athena[] = {
    {
    .iv = 100,
    .lvl = 38,
    .species = SPECIES_TENTACRUEL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_RAIN_DANCE, MOVE_SLUDGE_BOMB, MOVE_NONE}
    },
    {
    .iv = 100,
    .lvl = 38,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDER, MOVE_THUNDER_WAVE, MOVE_QUICK_ATTACK, MOVE_NONE}
    },
    {
    .iv = 100,
    .lvl = 38,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_HEADBUTT, MOVE_NONE, MOVE_NONE}
    }
};
// Route 128 SwimmerM
static const struct TrainerMon sParty_Harrison[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_HUNTAIL,
    }
};
// Mt Chimney GruntM (double)
static const struct TrainerMon sParty_GruntMtChimney2[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_GOLBAT,
    }
};
// Route 129 SwimmerM
static const struct TrainerMon sParty_Clarence[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_Terry[] = {
    {
    .iv = 0,
    .lvl = 37,
    .species = SPECIES_GIRAFARIG,
    }
};
// Mossdeep Gym Gentleman 2 - Northwest (Double Battle w Virgil)
static const struct TrainerMon sParty_Nate[] = {
    {
    .iv = 100,
    .lvl = 41,
    .species = SPECIES_GRUMPIG,
    }
};
// Mossdeep Gym Hex Maniac - Southeast (Double Battle w Clifford or Nicholas)
static const struct TrainerMon sParty_Kathleen[] = {
    {
    .iv = 50,
    .lvl = 42,
    .species = SPECIES_ALAKAZAM,
    }
};
// Mossdeep Gym Gentleman 1 - Southeast (Double Battle w Macey or Kathleen)
static const struct TrainerMon sParty_Clifford[] = {
    {
    .iv = 50,
    .lvl = 42,
    .species = SPECIES_GIRAFARIG,
    }
};
// Mossdeep Gym PsychicM 3 - Entrance Room (Double Battle w Kathleen)
static const struct TrainerMon sParty_Nicholas[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_WOBBUFFET,
    }
};
// Space Center
static const struct TrainerMon sParty_GruntSpaceCenter3[] = {
    {
    .iv = 0,
    .lvl = 41,
    .species = SPECIES_GOLBAT,
    },
    {
    .iv = 0,
    .lvl = 41,
    .species = SPECIES_MIGHTYENA,
    }
};
// Space Center
static const struct TrainerMon sParty_GruntSpaceCenter4[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_RHYDON,
    }
};
// Space Center
static const struct TrainerMon sParty_GruntSpaceCenter5[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_NINETALES,
    }
};
// Space Center
static const struct TrainerMon sParty_GruntSpaceCenter6[] = {
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_MIGHTYENA,
    }
};
// Space Center
static const struct TrainerMon sParty_GruntSpaceCenter7[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_CLAYDOL,
    }
};
// Mossdeep Gym PsychicF 4 - Southeast (Double Battle w Clifford)
static const struct TrainerMon sParty_Macey[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_XATU,
    }
};
// Rival 2 Torchic & Lotad
static const struct TrainerMon sParty_BrendanRustboroTreecko[] = {
    {
    .iv = 25,
    .lvl = 13,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_TACKLE, MOVE_CONFUSION, MOVE_ODOR_SLEUTH, MOVE_NONE}
    },
    {
    .iv = 50,
    .lvl = 15,
    .species = SPECIES_TORCHIC,
    .moves = {MOVE_GROWL, MOVE_PECK, MOVE_EMBER, MOVE_SAND_ATTACK}
    }
};
// Rival 2 Treecko & Wingull
static const struct TrainerMon sParty_BrendanRustboroMudkip[] = {
    {
    .iv = 25,
    .lvl = 13,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_TACKLE, MOVE_CONFUSION, MOVE_ODOR_SLEUTH, MOVE_NONE}
    },
    {
    .iv = 50,
    .lvl = 15,
    .species = SPECIES_TREECKO,
    .moves = {MOVE_LEER, MOVE_ABSORB, MOVE_QUICK_ATTACK, MOVE_NONE}
    }
};
// Route 132 Expert
static const struct TrainerMon sParty_Paxton[] = {
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_CHIMECHO,
    }
};
// Route 124 TriathleteF
static const struct TrainerMon sParty_Isabella[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_STARMIE,
    }
};
// Weather Institute Aqua GruntF (2nd floor double)
static const struct TrainerMon sParty_GruntWeatherInst5[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_SNEASEL,
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_WAILMER,
    }
};
// Magma Admin Mt Chimney 
static const struct TrainerMon sParty_TabithaMtChimney[] = {
    {
    .iv = 50,
    .lvl = 25,
    .species = SPECIES_CACNEA,
    .moves = {MOVE_LEECH_SEED, MOVE_PURSUIT, MOVE_PIN_MISSILE, MOVE_INGRAIN}
    },
    {
    .iv = 50,
    .lvl = 25,
    .species = SPECIES_LAIRON,
    .moves = {MOVE_METAL_CLAW, MOVE_ROCK_THROW, MOVE_MUD_SLAP, MOVE_HEADBUTT}
    },
    {
    .iv = 50,
    .lvl = 26,
    .species = SPECIES_ZANGOOSE,
    .moves = {MOVE_SLASH, MOVE_PURSUIT, MOVE_METAL_CLAW, MOVE_QUICK_ATTACK}
    }
};
// Route 132 CooltrainerM
static const struct TrainerMon sParty_Jonathan[] = {
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_KECLEON,
    },
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_EXPLOUD,
    },
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_SABLEYE,
    }
};
// Rival 2 Mudkip & Slugma
static const struct TrainerMon sParty_BrendanRustboroTorchic[] = {
    {
    .iv = 25,
    .lvl = 13,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_TACKLE, MOVE_CONFUSION, MOVE_ODOR_SLEUTH, MOVE_NONE}
    },
    {
    .iv = 50,
    .lvl = 15,
    .species = SPECIES_MUDKIP,
    .moves = {MOVE_TACKLE, MOVE_GROWL, MOVE_MUD_SLAP, MOVE_WATER_GUN}
    }
};
// Rival 2 Treecko & Wingull
static const struct TrainerMon sParty_MayRustboroMudkip[] = {
    {
    .iv = 25,
    .lvl = 13,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_TACKLE, MOVE_CONFUSION, MOVE_ODOR_SLEUTH, MOVE_NONE}
    },
    {
    .iv = 50,
    .lvl = 15,
    .species = SPECIES_TREECKO,
    .moves = {MOVE_LEER, MOVE_ABSORB, MOVE_QUICK_ATTACK, MOVE_NONE}
    }
};
// Magma Leader Magma Hideout
static const struct TrainerMon sParty_MaxieMagmaHideout[] = {
    {
    .iv = 150,
    .lvl = 37,
    .species = SPECIES_HOUNDOOM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_SUNNY_DAY, MOVE_ROAR}
    },
    {
    .iv = 200,
    .lvl = 38,
    .species = SPECIES_SHIFTRY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LEAF_BLADE, MOVE_EXTRASENSORY, MOVE_FAINT_ATTACK, MOVE_SUNNY_DAY}
    },
    {
    .iv = 150,
    .lvl = 38,
    .species = SPECIES_AGGRON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_IRON_TAIL, MOVE_ROCK_THROW, MOVE_EARTHQUAKE, MOVE_IRON_DEFENSE}
    },
    {
    .iv = 150,
    .lvl = 39,
    .species = SPECIES_CROBAT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLY, MOVE_POISON_FANG, MOVE_GIGA_DRAIN, MOVE_HAZE}
    },
    {
    .iv = 150,
    .lvl = 40,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_FIRE_BLAST, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_AMNESIA}
    }
};
// Magma Leader Mt Chimney 
static const struct TrainerMon sParty_MaxieMtChimney[] = {
    {
    .iv = 150,
    .lvl = 26,
    .species = SPECIES_MIGHTYENA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_BITE, MOVE_SAND_ATTACK, MOVE_TAKE_DOWN, MOVE_ROAR}
    },
    {
    .iv = 150,
    .lvl = 26,
    .species = SPECIES_GOLBAT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WING_ATTACK, MOVE_CONFUSE_RAY, MOVE_BITE, MOVE_LEECH_LIFE}
    },
    {
    .iv = 50,
    .lvl = 25,
    .species = SPECIES_NUZLEAF,
    .moves = {MOVE_RAZOR_LEAF, MOVE_LEECH_SEED, MOVE_ROCK_TOMB, MOVE_GROWTH}
    },
    {
    .iv = 150,
    .lvl = 28,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_MAGNITUDE, MOVE_FLAME_WHEEL, MOVE_ROCK_TOMB, MOVE_MUD_SLAP}
    }
};
//Route 102 Lass
static const struct TrainerMon sParty_Tiana[] = {
    {
    .iv = 0,
    .lvl = 4,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .iv = 0,
    .lvl = 4,
    .species = SPECIES_SHROOMISH,
    }
};
//Route 104 North Lass
static const struct TrainerMon sParty_Haley1[] = {
    {
    .iv = 0,
    .lvl = 6,
    .species = SPECIES_LOTAD,
    },
    {
    .iv = 0,
    .lvl = 6,
    .species = SPECIES_SHROOMISH,
    }
};
// Route 116 Cut Lass
static const struct TrainerMon sParty_Janice[] = {
    {
    .iv = 0,
    .lvl = 11,
    .species = SPECIES_VULPIX,
    },
    {
    .iv = 0,
    .lvl = 11,
    .species = SPECIES_MARILL,
    },
};
// Winstrate House
static const struct TrainerMon sParty_Vivi[] = {
    {
    .iv = 100,
    .lvl = 16,
    .species = SPECIES_MARILL,
    },
    {
    .iv = 100,
    .lvl = 16,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = 100,
    .lvl = 16,
    .species = SPECIES_NUMEL,
    }
};

static const struct TrainerMon sParty_Haley2[] = {
    {
    .iv = 10,
    .lvl = 26,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = 10,
    .lvl = 26,
    .species = SPECIES_SHROOMISH,
    }
};

static const struct TrainerMon sParty_Haley3[] = {
    {
    .iv = 20,
    .lvl = 30,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = 20,
    .lvl = 30,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Haley4[] = {
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = 30,
    .lvl = 32,
    .species = SPECIES_BRELOOM,
    }
};

static const struct TrainerMon sParty_Haley5[] = {
    {
    .iv = 40,
    .lvl = 34,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 40,
    .lvl = 34,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = 40,
    .lvl = 34,
    .species = SPECIES_BRELOOM,
    }
};
// Trick House 1 (Cut) Lass 
static const struct TrainerMon sParty_Sally[] = {
    {
    .iv = 0,
    .lvl = 17,
    .species = SPECIES_ODDISH,
    }
};
// Trick House 1 (Cut) Lass
static const struct TrainerMon sParty_Robin[] = {
    {
    .iv = 0,
    .lvl = 15,
    .species = SPECIES_LOMBRE,
    },
    {
    .iv = 0,
    .lvl = 15,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .iv = 0,
    .lvl = 15,
    .species = SPECIES_SANDSHREW,
    }
};
//Sootopolis Gym Lass 1 (Lowest Level)
static const struct TrainerMon sParty_Andrea[] = {
    {
    .iv = 100,
    .lvl = 46,
    .species = SPECIES_GYARADOS,
    }
};
//Sootopolis Gym Lass 2 (Highest Level - Double Battle w Tiffany)
static const struct TrainerMon sParty_Crissy[] = {
    {
    .iv = 100,
    .lvl = 45,
    .species = SPECIES_SEAKING,
    },
    {
    .iv = 100,
    .lvl = 45,
    .species = SPECIES_WAILORD,
    }
};
//Route 102 Bug Catcher
static const struct TrainerMon sParty_Rick[] = {
    {
    .iv = 0,
    .lvl = 4,
    .species = SPECIES_WURMPLE,
    },
    {
    .iv = 0,
    .lvl = 4,
    .species = SPECIES_WURMPLE,
    }
};
//Petalburg Woods Bug Catcher 1
static const struct TrainerMon sParty_Lyle[] = {
    {
    .iv = 0,
    .lvl = 3,
    .species = SPECIES_WURMPLE,
    },
    {
    .iv = 0,
    .lvl = 3,
    .species = SPECIES_WURMPLE,
    },
    {
    .iv = 0,
    .lvl = 3,
    .species = SPECIES_WURMPLE,
    },
    {
    .iv = 0,
    .lvl = 3,
    .species = SPECIES_WURMPLE,
    }
};
// Route 116 Bug Catcher - Wurmple & Nincada
static const struct TrainerMon sParty_Jose[] = {
    {
    .iv = 50,
    .lvl = 8,
    .species = SPECIES_SILCOON,
    },
    {
    .iv = 50,
    .lvl = 8,
    .species = SPECIES_NINCADA,
    }
};
// Route 119 Bug Catcher 3
static const struct TrainerMon sParty_Doug[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_NINJASK,
    },
    {
    .iv = 50,
    .lvl = 28,
    .species = SPECIES_SHEDINJA,
    }
};
// Route 119 Bug Catcher 2
static const struct TrainerMon sParty_Greg[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_VOLBEAT,
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_ILLUMISE,
    }
};
// Route 119 Bug Catcher 1
static const struct TrainerMon sParty_Kent[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_PINSIR,
    }
};
//Petalburg Woods Bug Catcher 2
static const struct TrainerMon sParty_James1[] = {
    {
    .iv = 0,
    .lvl = 6,
    .species = SPECIES_NINCADA,
    },
    {
    .iv = 0,
    .lvl = 6,
    .species = SPECIES_NINCADA,
    }
};

static const struct TrainerMon sParty_James2[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_NINCADA,
    },
    {
    .iv = 10,
    .lvl = 27,
    .species = SPECIES_NINJASK,
    },
    {
    .iv = 10,
    .lvl = 27,
    .species = SPECIES_SHEDINJA,
    }
};

static const struct TrainerMon sParty_James3[] = {
     {
    .iv = 0,
    .lvl = 31,
    .species = SPECIES_NINCADA,
    },
    {
    .iv = 10,
    .lvl = 30,
    .species = SPECIES_NINJASK,
    },
    {
    .iv = 10,
    .lvl = 30,
    .species = SPECIES_SHEDINJA,
    }
};

static const struct TrainerMon sParty_James4[] = {
     {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_NINCADA,
    },
    {
    .iv = 10,
    .lvl = 33,
    .species = SPECIES_NINJASK,
    },
    {
    .iv = 10,
    .lvl = 33,
    .species = SPECIES_SHEDINJA,
    }
};

static const struct TrainerMon sParty_James5[] = {
    {
    .iv = 10,
    .lvl = 36,
    .species = SPECIES_SHEDINJA,
    },
    {
    .iv = 10,
    .lvl = 36,
    .species = SPECIES_NINJASK,
    },
    {
    .iv = 10,
    .lvl = 36,
    .species = SPECIES_SHEDINJA,
    },
    {
    .iv = 10,
    .lvl = 36,
    .species = SPECIES_NINJASK,
    }
};
// Route 112 South Section Hiker 2
static const struct TrainerMon sParty_Brice[] = {
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_MACHOP,
    }
};
// Route 112 South Section Hiker 1
static const struct TrainerMon sParty_Trent1[] = {
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_GEODUDE,
    }
};
// Route 114 Hiker 2
static const struct TrainerMon sParty_Lenny[] = {
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_MACHOP,
    }
};
// Route 114 Hiker 1
static const struct TrainerMon sParty_Lucas1[] = {
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_NUMEL,
    }
};
// Trick House 3 Hiker
static const struct TrainerMon sParty_Alan[] = {
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_NOSEPASS,
    },
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_GRAVELER,
    }
};
// Route 116 Hiker 1
static const struct TrainerMon sParty_Clark[] = {
    {
    .iv = 0,
    .lvl = 9,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 20,
    .lvl = 8,
    .species = SPECIES_GEODUDE,
    }
};
// Jagged Pass Hiker
static const struct TrainerMon sParty_Eric[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_BALTOY,
    }
};
// Flag Note: what is this? 114 
static const struct TrainerMon sParty_Lucas2[] = {
    {
    .iv = 0,
    .lvl = 9,
    .species = SPECIES_WAILMER,
    .moves = {MOVE_SPLASH, MOVE_WATER_GUN, MOVE_NONE, MOVE_NONE}
    }
};
// Verdanturf Tunnel? Unused??
static const struct TrainerMon sParty_Mike1[] = {
    {
    .iv = 0,
    .lvl = 10,
    .species = SPECIES_PELIPPER,
    .moves = {MOVE_GUST, MOVE_GROWL, MOVE_NONE, MOVE_NONE}
    },
    {
    .iv = 0,
    .lvl = 10,
    .species = SPECIES_POOCHYENA,
    .moves = {MOVE_BITE, MOVE_SCARY_FACE, MOVE_NONE, MOVE_NONE}
    }
};
// Flag note: what is this? Unused?
static const struct TrainerMon sParty_Mike2[] = {
    {
    .iv = 0,
    .lvl = 18,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 0,
    .lvl = 18,
    .species = SPECIES_SABLEYE,
    },
    {
    .iv = 0,
    .lvl = 18,
    .species = SPECIES_RHYHORN,
    }
};

static const struct TrainerMon sParty_Trent2[] = {
    {
    .iv = 10,
    .lvl = 24,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 10,
    .lvl = 24,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 10,
    .lvl = 24,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 10,
    .lvl = 25,
    .species = SPECIES_GRAVELER,
    }
};

static const struct TrainerMon sParty_Trent3[] = {
    {
    .iv = 20,
    .lvl = 26,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 20,
    .lvl = 27,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 20,
    .lvl = 28,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = 20,
    .lvl = 30,
    .species = SPECIES_GRAVELER,
    }
};

static const struct TrainerMon sParty_Trent4[] = {
    {
    .iv = 30,
    .lvl = 30,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 30,
    .lvl = 33,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = 30,
    .lvl = 36,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = 30,
    .lvl = 38,
    .species = SPECIES_GOLEM,
    }
};

static const struct TrainerMon sParty_Trent5[] = {
    {
    .iv = 40,
    .lvl = 38,
    .species = SPECIES_GOLEM,
    },
    {
    .iv = 40,
    .lvl = 39,
    .species = SPECIES_GOLEM,
    },
    {
    .iv = 40,
    .lvl = 40,
    .species = SPECIES_GOLEM,
    },
    {
    .iv = 40,
    .lvl = 42,
    .species = SPECIES_GOLEM,
    }
};
// Mt Pyre Interior 2F Young Couple
static const struct TrainerMon sParty_DezAndLuke[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_DELCATTY,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_MANECTRIC,
    }
};
// SS Tidal Young Couple (nat dex)
static const struct TrainerMon sParty_LeaAndJed[] = {
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_MILTANK,
    },
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_SLOWBRO,
    }
};
// Abandoned Ship
static const struct TrainerMon sParty_KiraAndDan1[] = {
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_VOLBEAT,
    },
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_ILLUMISE,
    }
};

static const struct TrainerMon sParty_KiraAndDan2[] = {
    {
    .iv = 10,
    .lvl = 33,
    .species = SPECIES_VOLBEAT,
    },
    {
    .iv = 10,
    .lvl = 33,
    .species = SPECIES_ILLUMISE,
    }
};

static const struct TrainerMon sParty_KiraAndDan3[] = {
    {
    .iv = 20,
    .lvl = 35,
    .species = SPECIES_VOLBEAT,
    },
    {
    .iv = 20,
    .lvl = 35,
    .species = SPECIES_ILLUMISE,
    }
};

static const struct TrainerMon sParty_KiraAndDan4[] = {
    {
    .iv = 30,
    .lvl = 38,
    .species = SPECIES_VOLBEAT,
    },
    {
    .iv = 30,
    .lvl = 38,
    .species = SPECIES_ILLUMISE,
    }
};

static const struct TrainerMon sParty_KiraAndDan5[] = {
    {
    .iv = 40,
    .lvl = 41,
    .species = SPECIES_VOLBEAT,
    },
    {
    .iv = 40,
    .lvl = 41,
    .species = SPECIES_ILLUMISE,
    }
};
// Route 109 Seashore House Beauty
static const struct TrainerMon sParty_Johanna[] = {
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_HORSEA,
    },
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_ODDISH,
    }
};
// Lavaridge Gym CooltrainerM
static const struct TrainerMon sParty_Gerald[] = {
    {
    .iv = 100,
    .lvl = 26,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_FLAMETHROWER, MOVE_FURY_SWIPES, MOVE_FAINT_ATTACK, MOVE_BIND}
    }
};
// Mauville Gym Battle Girl
static const struct TrainerMon sParty_Vivian[] = {
    {
    .iv = 100,
    .lvl = 18,
    .species = SPECIES_MEDITITE,
    .moves = {MOVE_BIDE, MOVE_DETECT, MOVE_CONFUSION, MOVE_THUNDER_PUNCH}
    },
    {
    .iv = 100,
    .lvl = 18,
    .species = SPECIES_MEDITITE,
    .moves = {MOVE_THUNDER_PUNCH, MOVE_DETECT, MOVE_CONFUSION, MOVE_MEDITATE}
    }
};
// Lavaridge Gym Battle Girl
static const struct TrainerMon sParty_Danielle[] = {
    {
    .iv = 100,
    .lvl = 27,
    .species = SPECIES_MEDITITE,
    .moves = {MOVE_BIDE, MOVE_DETECT, MOVE_CONFUSION, MOVE_FIRE_PUNCH}
    }
};
// Route 119 (Post Weather Insitute) Ninja Boy 2
static const struct TrainerMon sParty_Hideo[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TACKLE, MOVE_SELF_DESTRUCT, MOVE_SLUDGE, MOVE_SMOKESCREEN}
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_SWALOT,
    .moves = {MOVE_ENCORE, MOVE_YAWN, MOVE_SLUDGE, MOVE_TACKLE}
    }
};
// Route 120 Ninja Boy 2
static const struct TrainerMon sParty_Keigo[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_SWALOT,
    .moves = {MOVE_POISON_GAS, MOVE_SELF_DESTRUCT, MOVE_SLUDGE, MOVE_SMOKESCREEN}
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_NINJASK,
    .moves = {MOVE_SAND_ATTACK, MOVE_DOUBLE_TEAM, MOVE_FURY_CUTTER, MOVE_SWORDS_DANCE}
    }
};
// Route 120 Ninja Boy 1
static const struct TrainerMon sParty_Riley[] = {
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_NINJASK,
    .moves = {MOVE_LEECH_LIFE, MOVE_FURY_SWIPES, MOVE_DIG, MOVE_NONE}
    },
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_KOFFING,
    .moves = {MOVE_TACKLE, MOVE_SELF_DESTRUCT, MOVE_SLUDGE, MOVE_SMOKESCREEN}
    }
};
// Fortree Gym Camper (Double Battle with Edwardo)
static const struct TrainerMon sParty_Flint[] = {
    {
    .iv = 150,
    .lvl = 32,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 150,
    .lvl = 33,
    .species = SPECIES_XATU,
    }
};
// Fortree Gym Picknicker
static const struct TrainerMon sParty_Ashley[] = {
    {
    .iv = 150,
    .lvl = 32,
    .species = SPECIES_SWABLU,
    },
    {
    .iv = 100,
    .lvl = 32,
    .species = SPECIES_DODRIO,
    }
};
// Mauville
static const struct TrainerMon sParty_WallyMauville[] = {
    {
    .iv = 30,
    .lvl = 16,
    .species = SPECIES_RALTS,
    }
};
// Rematch 1
static const struct TrainerMon sParty_WallyVR2[] = {
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_MAWILE,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_SWORDS_DANCE, MOVE_BATON_PASS, MOVE_METEOR_MASH, MOVE_BATON_PASS}
    },
    {
    .iv = 255,
    .lvl = 56,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_SILK_SCARF,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_WISH, MOVE_FOLLOW_ME, MOVE_HEAL_BELL}
    },
    {
    .iv = 255,
    .lvl = 56,
    .species = SPECIES_AZUMARILL,
    .heldItem = ITEM_MYSTIC_WATER,
    .moves = {MOVE_SURF, MOVE_DOUBLE_EDGE, MOVE_SUPERPOWER, MOVE_ICE_BEAM}
    },
    {
    .iv = 255,
    .lvl = 56,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_SHARP_BEAK,
    .moves = {MOVE_AERIAL_ACE, MOVE_EARTHQUAKE, MOVE_FIRE_BLAST, MOVE_DRAGON_DANCE}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_WIKI_BERRY,
    .moves = {MOVE_VOLT_TACKLE, MOVE_WISH, MOVE_MAGICAL_LEAF, MOVE_THUNDER_WAVE}
    },
    {
    .iv = 255,
    .lvl = 57,
    .species = SPECIES_GARDEVOIR,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_FIRE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_CALM_MIND}
    }
};
// Rematch 2
static const struct TrainerMon sParty_WallyVR3[] = {
    {
    .iv = 255,
    .lvl = 61,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_SKY_ATTACK, MOVE_EARTHQUAKE, MOVE_REST, MOVE_DRAGON_DANCE}
    },
    {
    .iv = 255,
    .lvl = 61,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_THUNDERBOLT, MOVE_WISH, MOVE_FOLLOW_ME, MOVE_THUNDER_WAVE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_MAWILE,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_SWORDS_DANCE, MOVE_CRUNCH, MOVE_METEOR_MASH, MOVE_BATON_PASS}
    },
    {   
    .iv = 255,
    .lvl = 61,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_SILK_SCARF,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_WISH, MOVE_FOLLOW_ME, MOVE_HEAL_BELL}
    },
    {
    .iv = 255,
    .lvl = 61,
    .species = SPECIES_AZUMARILL,
    .heldItem = ITEM_BLACK_BELT,
    .moves = {MOVE_SURF, MOVE_DOUBLE_EDGE, MOVE_SUPERPOWER, MOVE_ICE_BEAM}
    },
    {
    .iv = 255,
    .lvl = 62,
    .species = SPECIES_GARDEVOIR,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_PROTECT}
    }
};
// Rematch 3
static const struct TrainerMon sParty_WallyVR4[] = {
    {
    .iv = 255,
    .lvl = 67,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_SKY_ATTACK, MOVE_EARTHQUAKE, MOVE_REST, MOVE_DRAGON_DANCE}
    },
    {
    .iv = 255,
    .lvl = 66,
    .species = SPECIES_MEGANIUM,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_GRASS_WHISTLE, MOVE_LEECH_SEED, MOVE_EARTHQUAKE, MOVE_GIGA_DRAIN}
    },
    {
    .iv = 255,
    .lvl = 66,
    .species = SPECIES_RAPIDASH,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_HI_JUMP_KICK, MOVE_HYPNOSIS, MOVE_DOUBLE_EDGE}
    },
    {   
    .iv = 255,
    .lvl = 66,
    .species = SPECIES_GRANBULL,
    .heldItem = ITEM_SILK_SCARF,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_IRON_TAIL, MOVE_HEAL_BELL}
    },
    {
    .iv = 255,
    .lvl = 67,
    .species = SPECIES_AZUMARILL,
    .heldItem = ITEM_BLACK_BELT,
    .moves = {MOVE_SURF, MOVE_DOUBLE_EDGE, MOVE_SUPERPOWER, MOVE_ICE_BEAM}
    },
    {
    .iv = 255,
    .lvl = 67,
    .species = SPECIES_GARDEVOIR,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_ICE_PUNCH}
    }
};
// Rematch 4
static const struct TrainerMon sParty_WallyVR5[] = {
    {   
    .iv = 255,
    .lvl = 72,
    .species = SPECIES_CLEFABLE,
    .heldItem = ITEM_WIKI_BERRY,
    .moves = {MOVE_BODY_SLAM, MOVE_METEOR_MASH, MOVE_FOLLOW_ME, MOVE_TOXIC}
    },
    {
    .iv = 255,
    .lvl = 72,
    .species = SPECIES_SWELLOW,
    .heldItem = ITEM_CHOICE_BAND,
    .moves = {MOVE_SKY_ATTACK, MOVE_FACADE, MOVE_STEEL_WING, MOVE_NONE}
    },
    {
    .iv = 255,
    .lvl = 73,
    .species = SPECIES_AZUMARILL,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_IRON_TAIL, MOVE_DOUBLE_EDGE, MOVE_SUPERPOWER, MOVE_HYDRO_PUMP}
    },
    {
    .iv = 255,
    .lvl = 73,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_SKY_ATTACK, MOVE_HEAL_BELL, MOVE_REST, MOVE_TOXIC}
    },
    {
    .iv = 255,
    .lvl = 73,
    .species = SPECIES_GARDEVOIR,
    .heldItem = ITEM_LUM_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_FIRE_PUNCH}
    },
    {
    .iv = 255,
    .lvl = 73,
    .species = SPECIES_MEGANIUM,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_GRASS_WHISTLE, MOVE_SWORDS_DANCE, MOVE_EARTHQUAKE, MOVE_BODY_SLAM}
    }
};

// Lilycove Rival 5
static const struct TrainerMon sParty_BrendanLilycoveMudkip[] = {
    {
    .iv = 100,
    .lvl = 36,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 37,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_HERACROSS,
    .moves = {MOVE_BRICK_BREAK, MOVE_COUNTER, MOVE_TWINEEDLE, MOVE_TAKE_DOWN}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_TORKOAL,
    .moves = {MOVE_CURSE, MOVE_BODY_SLAM, MOVE_FLAMETHROWER, MOVE_AMNESIA}
    },
    {
    .iv = 200,
    .lvl = 38,
    .species = SPECIES_SCEPTILE,
    .moves = {MOVE_GROWTH, MOVE_SLASH, MOVE_ROCK_TOMB, MOVE_LEAF_BLADE}
    }
};
// Lilycove Rival 5
static const struct TrainerMon sParty_BrendanLilycoveTreecko[] = {
   {
    .iv = 100,
    .lvl = 36,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 37,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_DONPHAN,
    .moves = {MOVE_EARTHQUAKE, MOVE_FLAIL, MOVE_TAKE_DOWN, MOVE_ROLLOUT}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_WAILORD,
    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_ASTONISH, MOVE_AMNESIA}
    },
    {
    .iv = 200,
    .lvl = 38,
    .species = SPECIES_BLAZIKEN,
    .moves = {MOVE_BLAZE_KICK, MOVE_ROLLING_KICK, MOVE_BULK_UP, MOVE_MACH_PUNCH}
    }
};
// Lilycove Rival 5
static const struct TrainerMon sParty_BrendanLilycoveTorchic[] = {
    {
    .iv = 100,
    .lvl = 36,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 37,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_PINSIR,
    .moves = {MOVE_SEISMIC_TOSS, MOVE_REVENGE, MOVE_TWINEEDLE, MOVE_BRICK_BREAK}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_BRELOOM,
    .moves = {MOVE_GIGA_DRAIN, MOVE_HEADBUTT, MOVE_COUNTER, MOVE_BRICK_BREAK}
    },
    {
    .iv = 200,
    .lvl = 38,
    .species = SPECIES_SWAMPERT,
    .moves = {MOVE_MUD_SHOT, MOVE_ROCK_TOMB, MOVE_TAKE_DOWN, MOVE_MUDDY_WATER}
    }
};
// Lilycove Rival 5
static const struct TrainerMon sParty_MayLilycoveMudkip[] = {
   {
    .iv = 100,
    .lvl = 36,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 37,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_HERACROSS,
    .moves = {MOVE_BRICK_BREAK, MOVE_COUNTER, MOVE_TWINEEDLE, MOVE_TAKE_DOWN}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_TORKOAL,
    .moves = {MOVE_CURSE, MOVE_BODY_SLAM, MOVE_FLAMETHROWER, MOVE_AMNESIA}
    },
    {
    .iv = 200,
    .lvl = 38,
    .species = SPECIES_SCEPTILE,
    .moves = {MOVE_GROWTH, MOVE_SLASH, MOVE_ROCK_TOMB, MOVE_LEAF_BLADE}
    }
};
// Lilycove Rival 5
static const struct TrainerMon sParty_MayLilycoveTreecko[] = {
    {
    .iv = 100,
    .lvl = 36,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 37,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_DONPHAN,
    .moves = {MOVE_EARTHQUAKE, MOVE_FLAIL, MOVE_TAKE_DOWN, MOVE_ROLLOUT}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_WAILORD,
    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_ASTONISH, MOVE_AMNESIA}
    },
    {
    .iv = 200,
    .lvl = 38,
    .species = SPECIES_BLAZIKEN,
    .moves = {MOVE_BLAZE_KICK, MOVE_ROLLING_KICK, MOVE_BULK_UP, MOVE_MACH_PUNCH}
    }
};
// Lilycove Rival 5
static const struct TrainerMon sParty_MayLilycoveTorchic[] = {
   {
    .iv = 100,
    .lvl = 36,
    .species = SPECIES_KECLEON,
    .moves = {MOVE_THUNDERBOLT, MOVE_SUBSTITUTE, MOVE_SLASH, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 37,
    .species = SPECIES_GRUMPIG,
    .moves = {MOVE_SHOCK_WAVE, MOVE_REST, MOVE_SLEEP_TALK, MOVE_PSYCHIC}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_PINSIR,
    .moves = {MOVE_SEISMIC_TOSS, MOVE_REVENGE, MOVE_TWINEEDLE, MOVE_BRICK_BREAK}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_BRELOOM,
    .moves = {MOVE_GIGA_DRAIN, MOVE_HEADBUTT, MOVE_COUNTER, MOVE_BRICK_BREAK}
    },
    {
    .iv = 200,
    .lvl = 38,
    .species = SPECIES_SWAMPERT,
    .moves = {MOVE_MUD_SHOT, MOVE_ROCK_TOMB, MOVE_TAKE_DOWN, MOVE_MUDDY_WATER}
    }
};
// Route 127 Fisherman 1
static const struct TrainerMon sParty_Jonah[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_WAILMER,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_SHARPEDO,
    }
};
// Route 127 Fisherman 3
static const struct TrainerMon sParty_Henry[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_CLAMPERL,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_SEAKING,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_WAILMER,
    }
};
// Route 127 Fisherman 2
static const struct TrainerMon sParty_Roger[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_MAGIKARP,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_GYARADOS,
    }
};
// Route 128 CooltrainerF
static const struct TrainerMon sParty_Alexa[] = {
    {
    .iv = 100,
    .lvl = 40,
    .species = SPECIES_BELLOSSOM,
    },
    {
    .iv = 100,
    .lvl = 40,
    .species = SPECIES_VILEPLUME,
    }
};
// Route 128 CooltrainerM
static const struct TrainerMon sParty_Ruben[] = {
    {
    .iv = 100,
    .lvl = 40,
    .species = SPECIES_MASQUERAIN,
    },
    {
    .iv = 100,
    .lvl = 40,
    .species = SPECIES_NOSEPASS,
    }
};
// Route 127 Black Belt 
static const struct TrainerMon sParty_Koji1[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_BRELOOM,
    }
};
// Route 128 Fisherman 
static const struct TrainerMon sParty_Wayne[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_TENTACRUEL,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_WAILORD,
    }
};
// Route 127 Bird Keeper
static const struct TrainerMon sParty_Aidan[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_TROPIUS,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_SKARMORY,
    }
};
// Route 129 SwimmerM note we need to give all these mons surf lol
static const struct TrainerMon sParty_Reed[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_ZANGOOSE,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_EXPLOUD,
    }
};
// Route 129 SwimmerF
static const struct TrainerMon sParty_Tisha[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_LANTURN,
    }
};
// Route 113 Twins
static const struct TrainerMon sParty_ToriAndTia[] = {
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_SPINDA,
    },
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_SNORUNT,
    }
};
// Route 125 Sr and Jr
static const struct TrainerMon sParty_KimAndIris[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_ALTARIA,
    .moves = {MOVE_SING, MOVE_DRAGON_BREATH, MOVE_SAFEGUARD, MOVE_AERIAL_ACE}
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_CAMERUPT,
    .moves = {MOVE_FLAMETHROWER, MOVE_TAKE_DOWN, MOVE_REST, MOVE_EARTHQUAKE}
    }
};
// Route 114 Sr and Jr 
static const struct TrainerMon sParty_TyraAndIvy[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_ROSELIA,
    .moves = {MOVE_GROWTH, MOVE_STUN_SPORE, MOVE_MEGA_DRAIN, MOVE_LEECH_SEED}
    },
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_GRAVELER,
    .moves = {MOVE_DEFENSE_CURL, MOVE_MAGNITUDE, MOVE_TACKLE, MOVE_ROCK_THROW}
    }
};
//Route 109 Surf Couple
static const struct TrainerMon sParty_MelAndPaul[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_DUSTOX,
    .moves = {MOVE_SILVER_WIND, MOVE_PSYBEAM, MOVE_TOXIC, MOVE_PROTECT}
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_BEAUTIFLY,
    .moves = {MOVE_GUST, MOVE_MEGA_DRAIN, MOVE_ATTRACT, MOVE_STUN_SPORE}
    }
};
// METEOR FALLS EXPERT
static const struct TrainerMon sParty_JohnAndJay1[] = {
    {
    .iv = 200,
    .lvl = 52,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_PROTECT}
    },
    {
    .iv = 200,
    .lvl = 52,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_BRICK_BREAK, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    }
};

static const struct TrainerMon sParty_JohnAndJay2[] = {
    {
    .iv = 240,
    .lvl = 54,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_PROTECT}
    },
    {
    .iv = 240,
    .lvl = 54,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_BRICK_BREAK, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    }
};

static const struct TrainerMon sParty_JohnAndJay3[] = {
    {
    .iv = 250,
    .lvl = 56,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_PROTECT}
    },
    {
    .iv = 250,
    .lvl = 56,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_BRICK_BREAK, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    }
};

static const struct TrainerMon sParty_JohnAndJay4[] = {
    {
    .iv = 250,
    .lvl = 58,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_PROTECT}
    },
    {
    .iv = 250,
    .lvl = 58,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_BRICK_BREAK, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    },
    {
    .iv = 250,
    .lvl = 58,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_BRICK_BREAK, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    },
    {
    .iv = 250,
    .lvl = 58,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_PROTECT}
    }
};

static const struct TrainerMon sParty_JohnAndJay5[] = {
    {
    .iv = 250,
    .lvl = 60,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_PROTECT}
    },
    {
    .iv = 250,
    .lvl = 60,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_BRICK_BREAK, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    },
    {
    .iv = 250,
    .lvl = 60,
    .species = SPECIES_HARIYAMA,
    .moves = {MOVE_BRICK_BREAK, MOVE_ROCK_TOMB, MOVE_REST, MOVE_BELLY_DRUM}
    },
    {
    .iv = 250,
    .lvl = 60,
    .species = SPECIES_MEDICHAM,
    .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_PROTECT}
    }
};
// Route 131 Sis and Bro note linoone needs surf
static const struct TrainerMon sParty_ReliAndIan[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_LINOONE,
    }
};
// Route 124 Sis and Bro
static const struct TrainerMon sParty_LilaAndRoy1[] = {
    {
    .iv = 100,
    .lvl = 36,
    .species = SPECIES_CORSOLA,
    },
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_RELICANTH,
    }
};

static const struct TrainerMon sParty_LilaAndRoy2[] = {
    {
    .iv = 100,
    .lvl = 42,
    .species = SPECIES_CORSOLA,
    },
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_RELICANTH,
    }
};

static const struct TrainerMon sParty_LilaAndRoy3[] = {
    {
    .iv = 150,
    .lvl = 45,
    .species = SPECIES_CORSOLA,
    },
    {
    .iv = 50,
    .lvl = 45,
    .species = SPECIES_RELICANTH,
    }
};

static const struct TrainerMon sParty_LilaAndRoy4[] = {
    {
    .iv = 150,
    .lvl = 48,
    .species = SPECIES_CORSOLA,
    },
    {
    .iv = 0,
    .lvl = 46,
    .species = SPECIES_LANTURN,
    },
    {
    .iv = 50,
    .lvl = 48,
    .species = SPECIES_RELICANTH,
    },
    {
    .iv = 0,
    .lvl = 46,
    .species = SPECIES_SHARPEDO,
    }
};

static const struct TrainerMon sParty_LilaAndRoy5[] = {
   {
    .iv = 150,
    .lvl = 51,
    .species = SPECIES_CORSOLA,
    },
    {
    .iv = 0,
    .lvl = 48,
    .species = SPECIES_LANTURN,
    },
    {
    .iv = 50,
    .lvl = 51,
    .species = SPECIES_RELICANTH,
    },
    {
    .iv = 0,
    .lvl = 48,
    .species = SPECIES_SHARPEDO,
    }
};
// Route 107 Sis and Bro
static const struct TrainerMon sParty_LisaAndRay[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_GOLDEEN,
    },
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_TENTACOOL,
    }
};
// Route 119 Fisherman 
static const struct TrainerMon sParty_Chris[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_GYARADOS,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_TENTACOOL,
    },
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_FEEBAS,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_CARVANHA,
    }
};
// Route 116 Cut Rich Boy
static const struct TrainerMon sParty_Dawson[] = {
    {
    .iv = 0,
    .lvl = 10,
    .species = SPECIES_SPOINK,
    .heldItem = ITEM_NUGGET
    },
    {
    .iv = 0,
    .lvl = 10,
    .species = SPECIES_POOCHYENA,
    .heldItem = ITEM_NONE
    }
};
// Route 116 Cut Lady
static const struct TrainerMon sParty_Sarah[] = {
    {
    .iv = 0,
    .lvl = 10,
    .species = SPECIES_LOTAD,
    .heldItem = ITEM_NONE
    },
    {
    .iv = 0,
    .lvl = 12,
    .species = SPECIES_IGGLYBUFF,
    .heldItem = ITEM_NUGGET
    }
};
//Route 104 Fisherman
static const struct TrainerMon sParty_Darian[] = {
    {
    .iv = 0,
    .lvl = 9,
    .species = SPECIES_MAGIKARP,
    }
};
// Route 109 TuberF 1 (Potential Double Battle with Edmond or Ricky)
static const struct TrainerMon sParty_Hailey[] = {
    {
    .iv = 0,
    .lvl = 14,
    .species = SPECIES_MARILL,
    }
};
// Route 109 TuberM 2 (Potential Double Battle with Lola)
static const struct TrainerMon sParty_Chandler[] = {
    {
    .iv = 0,
    .lvl = 13,
    .species = SPECIES_STARYU,
    },
    {
    .iv = 0,
    .lvl = 13,
    .species = SPECIES_CORPHISH,
    }
};
//Route 110 PokefanM 1 (Double Battle w Isabel)
static const struct TrainerMon sParty_Kaleb[] = {
    {
    .iv = 0,
    .lvl = 15,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_THUNDER_SHOCK, MOVE_HELPING_HAND, MOVE_LIGHT_SCREEN, MOVE_HELPING_HAND}
    },
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_THUNDER_SHOCK, MOVE_GROWL, MOVE_DOUBLE_TEAM, MOVE_QUICK_ATTACK}
    }
};
//Route 110 Guitarist (Potential Double Battle with Edwin)
static const struct TrainerMon sParty_Joseph[] = {
    {
    .iv = 0,
    .lvl = 15,
    .species = SPECIES_ELECTRIKE,
    },
    {
    .iv = 0,
    .lvl = 15,
    .species = SPECIES_VOLTORB,
    }
};
// Route 110 Triathlete
static const struct TrainerMon sParty_Alyssa[] = {
    {
    .iv = 0,
    .lvl = 18,
    .species = SPECIES_MAGNEMITE,
    }
};
// Route 103 Cut Guitarist (Double Battle w Rhett)
static const struct TrainerMon sParty_Marcos[] = {
    {
    .iv = 100,
    .lvl = 17,
    .species = SPECIES_VOLTORB,
    },
    {
    .iv = 100,
    .lvl = 17,
    .species = SPECIES_WHISMUR,
    },
};
// Route 103 Cut Black Belt (Double Battle w Marcos)
static const struct TrainerMon sParty_Rhett[] = {
    {
    .iv = 100,
    .lvl = 18,
    .species = SPECIES_MAKUHITA,
    }
};
//Route 111 South Camper 
static const struct TrainerMon sParty_Tyron[] = {
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_SANDSHREW,
    }
};
//Route 111 South Aroma Lady
static const struct TrainerMon sParty_Celina[] = {
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_ROSELIA,
    }
};
//Route 111 South Picnicker
static const struct TrainerMon sParty_Bianca[] = {
    {
    .iv = 0,
    .lvl = 21,
    .species = SPECIES_SHROOMISH,
    }
};
//Route 111 Mid Kindler
static const struct TrainerMon sParty_Hayden[] = {
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_NUMEL,
    }
};
// Route 113 Picnicker
static const struct TrainerMon sParty_Sophie[] = {
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_MARILL,
    },
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_LOMBRE,
    }
};
// Route 113 Bird Keeper (optional double)
static const struct TrainerMon sParty_Coby[] = {
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_SKARMORY,
    },
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_SWELLOW,
    }
};
// Route 113 Camper
static const struct TrainerMon sParty_Lawrence[] = {
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_BALTOY,
    },
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_SANDSHREW,
    }
};
// Route 113 Pokemaniac
static const struct TrainerMon sParty_Wyatt[] = {
    {
    .iv = 0,
    .lvl = 23,
    .species = SPECIES_SNEASEL,
    }
};
// Route 114 Picnicker 3
static const struct TrainerMon sParty_Angelina[] = {
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_SWABLU,
    },
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_SURSKIT,
    }
};
// Route 114 Fisherman 2
static const struct TrainerMon sParty_Kai[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_BARBOACH,
    }
};
// Route 114 Picnicker 1
static const struct TrainerMon sParty_Charlotte[] = {
    {
    .iv = 0,
    .lvl = 24,
    .species = SPECIES_BRELOOM,
    }
};
//Route 118 Mauville Youngster
static const struct TrainerMon sParty_Deandre[] = {
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_ZIGZAGOON,
    },
    {
    .iv = 0,
    .lvl = 17,
    .species = SPECIES_ARON,
    },
    {
    .iv = 0,
    .lvl = 16,
    .species = SPECIES_ELECTRIKE,
    }
};
// Magma Hideout Entrance (Elevated Level)
static const struct TrainerMon sParty_GruntMagmaHideout1[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_GRAVELER,
    }
};
// Magma Hideout Entrance Magma GruntM
static const struct TrainerMon sParty_GruntMagmaHideout2[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_ZANGOOSE,
    }
};
// Magma Hideout 1F Magma GruntM
static const struct TrainerMon sParty_GruntMagmaHideout3[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_TORKOAL,
    }
};
// Magma Hideout 1F Magma GruntM (Double)
static const struct TrainerMon sParty_GruntMagmaHideout4[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_DONPHAN,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_GOLBAT,
    }
};
// Magma Hideout 1F Magma GruntM (Double)
static const struct TrainerMon sParty_GruntMagmaHideout5[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_MIGHTYENA,
    },
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_CACTURNE,
    }
};
// Magma Hideout 1F Magma GruntF
static const struct TrainerMon sParty_GruntMagmaHideout6[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_NINETALES,
    }
};
// Magma Hideout B1F Magma GruntM
static const struct TrainerMon sParty_GruntMagmaHideout7[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_RHYHORN,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_KOFFING,
    }
};
// Magma Hideout B1F Magma GruntM
static const struct TrainerMon sParty_GruntMagmaHideout8[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_LAIRON,
    }
};
// Magma Hideout B2F Magma GruntM
static const struct TrainerMon sParty_GruntMagmaHideout9[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_MAGCARGO,
    }
};
// Magma Hideout B1F Magma GruntM
static const struct TrainerMon sParty_GruntMagmaHideout10[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_MIGHTYENA,
    }
};
// Magma Hideout B2F Magma GruntF
static const struct TrainerMon sParty_GruntMagmaHideout11[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_ZANGOOSE,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_BALTOY,
    }
};
// Magma Hideout B1F Magma GruntF
static const struct TrainerMon sParty_GruntMagmaHideout12[] = {
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_MURKROW,
    },
    {
    .iv = 0,
    .lvl = 33,
    .species = SPECIES_RHYHORN,
    }
};
// Magma Hideout B4F Magma GruntM (DOUBLE)
static const struct TrainerMon sParty_GruntMagmaHideout13[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_MAGCARGO,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_GOLBAT,
    }
};
// Magma Hideout B1F Magma GruntM
static const struct TrainerMon sParty_GruntMagmaHideout14[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_WEEZING,
    }
};
// Magma Hideout B4F Magma GruntM (DOUBLE)
static const struct TrainerMon sParty_GruntMagmaHideout15[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_MURKROW,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_LAIRON,
    }
};
// Magma Hideout B4F Magma GruntM
static const struct TrainerMon sParty_GruntMagmaHideout16[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_CLAYDOL,
    }
};
// Magma Admin Magma Hideout
static const struct TrainerMon sParty_TabithaMagmaHideout[] = {
    {
    .iv = 50,
    .lvl = 36,
    .species = SPECIES_CROBAT,
    .moves = {MOVE_WING_ATTACK, MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_CONFUSE_RAY}
    },
    {
    .iv = 50,
    .lvl = 35,
    .species = SPECIES_LAIRON,
    .moves = {MOVE_IRON_TAIL, MOVE_ROCK_TOMB, MOVE_SANDSTORM, MOVE_MUD_SLAP}
    },
    {
    .iv = 50,
    .lvl = 35,
    .species = SPECIES_CACTURNE,
    .moves = {MOVE_NEEDLE_ARM, MOVE_FAINT_ATTACK, MOVE_LEECH_SEED, MOVE_INGRAIN}
    },
    {
    .iv = 50,
    .lvl = 37,
    .species = SPECIES_ZANGOOSE,
    .moves = {MOVE_CRUSH_CLAW, MOVE_FAINT_ATTACK, MOVE_SWORDS_DANCE, MOVE_METAL_CLAW}
    }
};
// Route 132 CooltrainerF
static const struct TrainerMon sParty_Darcy[] = {
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_CACTURNE,
    },
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_CAMERUPT,
    }
};
// Magma Leader Space Center (Double SC)
static const struct TrainerMon sParty_MaxieMossdeep[] = {
    {
    .iv = 200,
    .lvl = 44,
    .species = SPECIES_HOUNDOOM,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_FLAMETHROWER, MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_CRUNCH}
    },
    {
    .iv = 200,
    .lvl = 44,
    .species = SPECIES_SHIFTRY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_LEAF_BLADE, MOVE_EXTRASENSORY, MOVE_FAINT_ATTACK, MOVE_SUNNY_DAY}
    },
    {
    .iv = 200,
    .lvl = 45,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_FOCUS_BAND,
    .moves = {MOVE_HEAT_WAVE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SUNNY_DAY}
    }
};
// Route 103 Surf SwimmerM
static const struct TrainerMon sParty_Pete[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_TENTACRUEL,
    }
};
// Route 103 Surf SwimmerF 
static const struct TrainerMon sParty_Isabelle[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_AZUMARILL,
    }
};
// Route 105 Ruin Maniac
static const struct TrainerMon sParty_Andres1[] = {
    {
    .iv = 50,
    .lvl = 28,
    .species = SPECIES_BALTOY,
    },
    {
    .iv = 50,
    .lvl = 28,
    .species = SPECIES_TRAPINCH,
    }
};
// Route 105 Bird Keeper
static const struct TrainerMon sParty_Josue[] = {
    {
    .iv = 50,
    .lvl = 28,
    .species = SPECIES_SWABLU,
    },
    {
    .iv = 50,
    .lvl = 28,
    .species = SPECIES_SWELLOW,
    }
};
// Route 107 Triathlete
static const struct TrainerMon sParty_Camron[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_STARYU,
    }
};
// Route 108 Sailor (Double Battle w Carolina)
static const struct TrainerMon sParty_Cory1[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_TENTACOOL,
    }
};
// Route 108 Cooltrainer F (Double Battle with Cory)
static const struct TrainerMon sParty_Carolina[] = {
    {
    .iv = 50,
    .lvl = 26,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = 50,
    .lvl = 27,
    .species = SPECIES_SWELLOW,
    },
    {
    .iv = 50,
    .lvl = 26,
    .species = SPECIES_MANECTRIC,
    }
};
//Route 109 Surf Bird Keeper
static const struct TrainerMon sParty_Elijah[] = {
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_SKARMORY,
    },
    {
    .iv = 0,
    .lvl = 27,
    .species = SPECIES_SKARMORY,
    }
};
//Route 111 Desert Picnicker 3
static const struct TrainerMon sParty_Celia[] = {
    {
    .iv = 150,
    .lvl = 29,
    .species = SPECIES_RHYHORN,
    .moves = {MOVE_SCARY_FACE, MOVE_PROTECT, MOVE_MAGNITUDE, MOVE_ROCK_TOMB}
    },
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_METAL_CLAW, MOVE_DOUBLE_TEAM, MOVE_SLASH, MOVE_CUT}
    },
};
//Route 111 Desert Ruin Maniac 2
static const struct TrainerMon sParty_Bryan[] = {
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_CACTURNE,
    .moves = {MOVE_GROWTH, MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_FAINT_ATTACK}
    },
    {
    .iv = 100,
    .lvl = 31,
    .species = SPECIES_NOSEPASS,
    .moves = {MOVE_ROCK_SLIDE, MOVE_SPARK, MOVE_THUNDER_WAVE, MOVE_HEADBUTT}
    }
};
//Route 111 Desert Camper 3
static const struct TrainerMon sParty_Branden[] = {
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_GRAVELER,
    .moves = {MOVE_ROCK_TOMB, MOVE_PROTECT, MOVE_MAGNITUDE, MOVE_ROLLOUT}
    },
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_SANDSLASH,
    .moves = {MOVE_METAL_CLAW, MOVE_DOUBLE_TEAM, MOVE_SLASH, MOVE_CUT}
    }
};
// Route 112 North Section Kindler
static const struct TrainerMon sParty_Bryant[] = {
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_SLUGMA,
    }
};
// Route 112 North Section Aroma Lady
static const struct TrainerMon sParty_Shayla[] = {
    {
    .iv = 0,
    .lvl = 22,
    .species = SPECIES_SHROOMISH,
    },
    {
    .iv = 0,
    .lvl = 20,
    .species = SPECIES_ROSELIA,
    }
};
// Route 115 Surf Triathlete
static const struct TrainerMon sParty_Kyra[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_PONYTA,
    },
    {
    .iv = 0,
    .lvl = 31,
    .species = SPECIES_DODRIO,
    }
};
// Route 115 Surf Ninja Boy
static const struct TrainerMon sParty_Jaiden[] = {
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_NINJASK,
    },
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_SHEDINJA,
    }
};
// Route 115 Surf Psychic (Double Battle w Helene)
static const struct TrainerMon sParty_Alix[] = {
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_KADABRA,
    },
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_GARDEVOIR,
    }
};
// Route 115 Surf Battle Girl (Double Battle w Alix)
static const struct TrainerMon sParty_Helene[] = {
    {
    .iv = 0,
    .lvl = 31,
    .species = SPECIES_MEDITITE,
    },
    {
    .iv = 0,
    .lvl = 28,
    .species = SPECIES_HARIYAMA,
    }
};
// Route 115 Psychic
static const struct TrainerMon sParty_Marlene[] = {
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_KIRLIA,
    },
    {
    .iv = 0,
    .lvl = 26,
    .species = SPECIES_SPOINK,
    }
};
// Route 116 Hiker 2
static const struct TrainerMon sParty_Devan[] = {
    {
    .iv = 0,
    .lvl = 8,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 0,
    .lvl = 9,
    .species = SPECIES_GEODUDE,
    }
};
// Route 116 Youngster 2
static const struct TrainerMon sParty_Johnson[] = {
    {
    .iv = 0,
    .lvl = 8,
    .species = SPECIES_POOCHYENA,
    },
    {
    .iv = 0,
    .lvl = 8,
    .species = SPECIES_LOTAD,
    }
};
// Route 117 TriathleteF 2
static const struct TrainerMon sParty_Melina[] = {
    {
    .iv = 0,
    .lvl = 19,
    .species = SPECIES_PONYTA,
    }
};
// Route 117 Psychic
static const struct TrainerMon sParty_Brandi[] = {
    {
    .iv = 0,
    .lvl = 20,
    .species = SPECIES_KIRLIA,
    }
};
// Route 117 Battle Girl
static const struct TrainerMon sParty_Aisha[] = {
    {
    .iv = 0,
    .lvl = 19,
    .species = SPECIES_MEDITITE,
    }
};
// Route 132 ExpertF
static const struct TrainerMon sParty_Makayla[] = {
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_GLALIE,
    },
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_MEDICHAM,
    }
};
// Route 119 (Post Weather Insitute) Guitarist
static const struct TrainerMon sParty_Fabian[] = {
    {
    .iv = 0,
    .lvl = 29,
    .species = SPECIES_MANECTRIC,
    }
};
// Route 119 Kindler
static const struct TrainerMon sParty_Dayton[] = {
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_SLUGMA,
    },
    {
    .iv = 0,
    .lvl = 25,
    .species = SPECIES_NUMEL,
    }
};
// Route 119 Parasol Lady
static const struct TrainerMon sParty_Rachel[] = {
    {
    .iv = 150,
    .lvl = 26,
    .species = SPECIES_GOLDEEN,
    }
};
// Route 120 CooltrainerM
static const struct TrainerMon sParty_Leonel[] = {
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_MANECTRIC,
    .moves = {MOVE_THUNDER, MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE, MOVE_NONE}
    }
};
// Route 120 Battle Girl
static const struct TrainerMon sParty_Callie[] = {
    {
    .iv = 50,
    .lvl = 30,
    .species = SPECIES_MEDITITE,
    },
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_HARIYAMA,
    }
};
// Route 121 Bug Maniac
static const struct TrainerMon sParty_Cale[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_TRAPINCH,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_VIBRAVA,
    }
};
// Route 121 BreederM
static const struct TrainerMon sParty_Myles[] = {
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_RAICHU,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_SEAKING,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_NOSEPASS,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_WIGGLYTUFF,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_BELLOSSOM,
    }
};
// Route 121 BreederF
static const struct TrainerMon sParty_Pat[] = {
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_LINOONE,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_VILEPLUME,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_AZUMARILL,
    },
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_SWALOT,
    }
};
// Route 121 CooltrainerF
static const struct TrainerMon sParty_Cristin1[] = {
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_DONPHAN,
    },
    {
    .iv = 100,
    .lvl = 33,
    .species = SPECIES_GOLDUCK,
    }
};
// Rival 2 Torchic & Lotad
static const struct TrainerMon sParty_MayRustboroTreecko[] = {
    {
    .iv = 25,
    .lvl = 13,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_TACKLE, MOVE_CONFUSION, MOVE_ODOR_SLEUTH, MOVE_NONE}
    },
    {
    .iv = 50,
    .lvl = 15,
    .species = SPECIES_TORCHIC,
    .moves = {MOVE_GROWL, MOVE_PECK, MOVE_EMBER, MOVE_SAND_ATTACK}
    }
};
// Rival 2 Mudkip & Torkoal
static const struct TrainerMon sParty_MayRustboroTorchic[] = {
    {
    .iv = 25,
    .lvl = 13,
    .species = SPECIES_SPOINK,
    .moves = {MOVE_TACKLE, MOVE_CONFUSION, MOVE_ODOR_SLEUTH, MOVE_NONE}
    },
    {
    .iv = 50,
    .lvl = 15,
    .species = SPECIES_MUDKIP,
    .moves = {MOVE_TACKLE, MOVE_GROWL, MOVE_MUD_SLAP, MOVE_WATER_GUN}
    }
};
// Rematch 1 after beating Wattson 
static const struct TrainerMon sParty_Roxanne2[] = {
    {
    .iv = 150,
    .lvl = 25,
    .species = SPECIES_LILEEP,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SANDSTORM, MOVE_INGRAIN, MOVE_ROCK_TOMB, MOVE_MEGA_DRAIN}
    },
    {
    .iv = 150,
    .lvl = 25,
    .species = SPECIES_ANORITH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROCK_TOMB, MOVE_METAL_CLAW, MOVE_CUT, MOVE_ROCK_SMASH}
    },
    {
    .iv = 100,
    .lvl = 24,
    .species = SPECIES_CORSOLA,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROCK_TOMB, MOVE_BUBBLE_BEAM, MOVE_RECOVER, MOVE_AMNESIA}
    },
    {
    .iv = 200,
    .lvl = 26,
    .species = SPECIES_NOSEPASS,
    .heldItem = ITEM_ORAN_BERRY,
    .moves = {MOVE_ROCK_SLIDE, MOVE_SPARK, MOVE_THUNDER_WAVE, MOVE_SPARK}
    }
};
// Roxanne Rematch 2 After Becoming Champion
static const struct TrainerMon sParty_Roxanne3[] = {
    
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_RELICANTH,
    .heldItem = ITEM_HARD_STONE,
    .moves = {MOVE_ROCK_SLIDE, MOVE_SANDSTORM, MOVE_DOUBLE_EDGE, MOVE_SURF}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_ARMALDO,
    .heldItem = ITEM_KINGS_ROCK,
    .moves = {MOVE_ROCK_TOMB, MOVE_METAL_CLAW, MOVE_CUT, MOVE_ROCK_SMASH}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_RHYDON,
    .heldItem = ITEM_SOFT_SAND,
    .moves = {MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_SANDSTORM, MOVE_ROCK_SMASH}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_CRADILY,
    .heldItem = ITEM_APICOT_BERRY,
    .moves = {MOVE_SANDSTORM, MOVE_INGRAIN, MOVE_RECOVER, MOVE_GIGA_DRAIN}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_NOSEPASS,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_SMELLING_SALT, MOVE_PROTECT, MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE}
    }
};
// Roxanne Rematch 3
static const struct TrainerMon sParty_Roxanne4[] = {
     {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_TYRANITAR,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_ROCK_SLIDE, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_PROTECT}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_AERODACTYL,
    .heldItem = ITEM_SCOPE_LENS,
    .moves = {MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE, MOVE_SKY_ATTACK, MOVE_PROTECT}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_DONPHAN,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SUBSTITUTE, MOVE_REST}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_CRADILY,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_INGRAIN, MOVE_ANCIENT_POWER, MOVE_GIGA_DRAIN, MOVE_PROTECT}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_STEELIX,
    .heldItem = ITEM_CHOICE_BAND,
    .moves = {MOVE_ROCK_SLIDE, MOVE_EXPLOSION, MOVE_CRUNCH, MOVE_EARTHQUAKE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_NOSEPASS,
    .heldItem = ITEM_MAGNET,
    .moves = {MOVE_ROCK_SLIDE, MOVE_PROTECT, MOVE_THUNDER, MOVE_ICE_PUNCH}
    }
};
// Roxanne Rematch 4
static const struct TrainerMon sParty_Roxanne5[] = {
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_TYRANITAR,
    .heldItem = ITEM_CHOICE_BAND,
    .evs = {252, 252, 0, 0, 0, 0},
    .moves = {MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_PURSUIT, MOVE_AERIAL_ACE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_FLYGON,
    .heldItem = ITEM_LEFTOVERS,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SUBSTITUTE, MOVE_FIRE_BLAST}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_AERODACTYL,
    .heldItem = ITEM_SOFT_SAND,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE, MOVE_SKY_ATTACK, MOVE_TAUNT}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_CRADILY,
    .heldItem = ITEM_SALAC_BERRY,
    .evs = {252, 0, 252, 0, 0, 0},
    .moves = {MOVE_INGRAIN, MOVE_ANCIENT_POWER, MOVE_GIGA_DRAIN, MOVE_PROTECT}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_ARMALDO,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE, MOVE_TWINEEDLE, MOVE_ROCK_BLAST}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_NOSEPASS,
    .heldItem = ITEM_BRIGHT_POWDER,
    .evs = {252, 252, 0, 0, 0, 0},
    .moves = {MOVE_ROCK_SLIDE, MOVE_PROTECT, MOVE_THUNDER_WAVE, MOVE_DOUBLE_TEAM}
    }
};
// Rematch 1 & After Beating Flannery (same as 1_2)
static const struct TrainerMon sParty_Brawly2[] = {
    {
    .iv = 180,
    .lvl = 31,
    .species = SPECIES_MEDITITE,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_EXTRASENSORY, MOVE_THUNDER_PUNCH, MOVE_LIGHT_SCREEN, MOVE_REFLECT}
    },
    {
    .iv = 100,
    .lvl = 30,
    .species = SPECIES_MACHOKE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KARATE_CHOP, MOVE_ROCK_TOMB, MOVE_SEISMIC_TOSS, MOVE_REVENGE}
    },
    {
    .iv = 100,
    .lvl = 31,
    .species = SPECIES_BRELOOM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_MACH_PUNCH, MOVE_MEGA_DRAIN, MOVE_BULK_UP, MOVE_STUN_SPORE}
    },
    {
    .iv = 200,
    .lvl = 32,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_VITAL_THROW, MOVE_REVERSAL, MOVE_BULK_UP, MOVE_FAINT_ATTACK}
    }
};
// Brawly Rematch 2 - After Becoming Champion
static const struct TrainerMon sParty_Brawly3[] = {
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_HITMONCHAN,
    .heldItem = ITEM_BLACK_BELT,
    .moves = {MOVE_DYNAMIC_PUNCH, MOVE_ROCK_SLIDE, MOVE_AGILITY, MOVE_BULK_UP}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_BRELOOM,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_FOCUS_PUNCH, MOVE_LEECH_SEED, MOVE_STUN_SPORE, MOVE_SUBSTITUTE}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_POLIWRATH,
    .heldItem = ITEM_MYSTIC_WATER,
    .moves = {MOVE_SURF, MOVE_HYPNOSIS, MOVE_FOCUS_PUNCH, MOVE_ICE_BEAM}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_PRIMEAPE,
    .heldItem = ITEM_HARD_STONE,
    .moves = {MOVE_CROSS_CHOP, MOVE_BULK_UP, MOVE_ROCK_SLIDE, MOVE_FAINT_ATTACK}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_REST, MOVE_SLEEP_TALK, MOVE_CROSS_CHOP, MOVE_WHIRLWIND}
    }
};
// Brawly Rematch 3
static const struct TrainerMon sParty_Brawly4[] = {
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_POLIWRATH,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_BELLY_DRUM, MOVE_BRICK_BREAK, MOVE_SUBSTITUTE, MOVE_EARTHQUAKE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_MAGMAR,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_THUNDER_PUNCH, MOVE_CROSS_CHOP, MOVE_FOLLOW_ME}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_BLACK_BELT,
    .moves = {MOVE_FAKE_OUT, MOVE_HI_JUMP_KICK, MOVE_BULK_UP, MOVE_ROCK_SLIDE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_ELECTABUZZ,
    .heldItem = ITEM_MAGNET,
    .moves = {MOVE_CROSS_CHOP, MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH, MOVE_THUNDER_WAVE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_BRELOOM,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_MACH_PUNCH, MOVE_SWORDS_DANCE, MOVE_SPORE, MOVE_FACADE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_CHOICE_BAND,
    .moves = {MOVE_BODY_SLAM, MOVE_ROCK_SLIDE, MOVE_CROSS_CHOP, MOVE_EARTHQUAKE}
    }
};
// Brawly Rematch 4
static const struct TrainerMon sParty_Brawly5[] = {
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_HITMONTOP,
    .heldItem = ITEM_LUM_BERRY,
    .evs = {252, 0, 0, 0, 0, 252},
    .moves = {MOVE_FAKE_OUT, MOVE_MACH_PUNCH, MOVE_PURSUIT, MOVE_BULK_UP}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_BRELOOM,
    .heldItem = ITEM_SALAC_BERRY,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_FOCUS_PUNCH, MOVE_GIGA_DRAIN, MOVE_SPORE, MOVE_SUBSTITUTE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_BLAZIKEN,
    .heldItem = ITEM_WHITE_HERB,
    .evs = {0, 252, 0, 0, 252, 0},
    .moves = {MOVE_OVERHEAT, MOVE_THUNDER_PUNCH, MOVE_HI_JUMP_KICK, MOVE_ROCK_SLIDE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_CHOICE_BAND,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_MEGA_KICK, MOVE_HI_JUMP_KICK, MOVE_BRICK_BREAK, MOVE_ROCK_SLIDE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_HERACROSS,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_CROSS_CHOP, MOVE_ROCK_SLIDE, MOVE_MEGAHORN, MOVE_SWORDS_DANCE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_LEFTOVERS,
    .evs = {252, 252, 0, 0, 0, 0},
    .moves = {MOVE_FOCUS_PUNCH, MOVE_REVENGE, MOVE_ROCK_SLIDE, MOVE_TOXIC}
    }
};
// Wattson Rematch 1 after New Mauville
static const struct TrainerMon sParty_Wattson2[] = {
    {
    .iv = 210,
    .lvl = 34,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDERBOLT, MOVE_MAGICAL_LEAF, MOVE_CHARM, MOVE_THUNDER_WAVE}
    },
    {
    .iv = 210,
    .lvl = 34,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDERBOLT, MOVE_WISH, MOVE_ENCORE, MOVE_THUNDER_WAVE}
    },
    {
    .iv = 220,
    .lvl = 33,
    .species = SPECIES_LANTURN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_THUNDERBOLT, MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_THUNDER_WAVE}
    },
    {
    .iv = 230,
    .lvl = 33,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHOCK_WAVE, MOVE_THUNDER_WAVE, MOVE_REFLECT, MOVE_TRI_ATTACK}
    },
    {
    .iv = 250,
    .lvl = 35,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_MAGNET,
    .moves = {MOVE_THUNDERBOLT, MOVE_CRUNCH, MOVE_CHARGE, MOVE_THUNDER_WAVE}
    }
};
// Wattson Rematch 2 
static const struct TrainerMon sParty_Wattson3[] = {
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_RAICHU,
    .heldItem = ITEM_MYSTIC_WATER,
    .moves = {MOVE_THUNDERBOLT, MOVE_ENCORE, MOVE_FOCUS_PUNCH, MOVE_SURF}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_LANTURN,
    .heldItem = ITEM_WIKI_BERRY,
    .moves = {MOVE_RAIN_DANCE, MOVE_DIVE, MOVE_THUNDER_WAVE, MOVE_CONFUSE_RAY}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_JOLTEON,
    .heldItem = ITEM_SPELL_TAG,
    .moves = {MOVE_AGILITY, MOVE_THUNDER, MOVE_BATON_PASS, MOVE_SHADOW_BALL}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_ELECTABUZZ,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH, MOVE_THUNDER, MOVE_PSYCHIC}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_MAGNET,
    .moves = {MOVE_CRUNCH, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_ROAR}
    }
};
// Wattson Rematch 3
static const struct TrainerMon sParty_Wattson4[] = {
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_PLUSLE,
    .heldItem = ITEM_PETAYA_BERRY,
    .moves = {MOVE_THUNDERBOLT, MOVE_MAGICAL_LEAF, MOVE_THUNDER_WAVE, MOVE_SUBSTITUTE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_MINUN,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_THUNDERBOLT, MOVE_WISH, MOVE_THUNDER_WAVE, MOVE_FOLLOW_ME}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_LANTURN,
    .heldItem = ITEM_BRIGHT_POWDER,
    .moves = {MOVE_THUNDER, MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_RAIN_DANCE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_MAGNETON,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_THUNDER_WAVE, MOVE_REFLECT, MOVE_THUNDER, MOVE_RAIN_DANCE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_PORYGON2,
    .heldItem = ITEM_CHOICE_BAND,
    .moves = {MOVE_HYPER_BEAM, MOVE_IRON_TAIL, MOVE_AERIAL_ACE, MOVE_THIEF}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_MAGNET,
    .moves = {MOVE_CRUNCH, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_ROAR}
    }
};
// Wattson Rematch 4
static const struct TrainerMon sParty_Wattson5[] = {
     {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_RAICHU,
    .heldItem = ITEM_MYSTIC_WATER,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_VOLT_TACKLE, MOVE_SURF, MOVE_THUNDER_WAVE, MOVE_WISH}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_LANTURN,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {252, 0, 0, 0, 252, 0},
    .moves = {MOVE_THUNDER, MOVE_SURF, MOVE_THUNDER_WAVE, MOVE_RAIN_DANCE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_JOLTEON,
    .heldItem = ITEM_SPELL_TAG,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_AGILITY, MOVE_THUNDER, MOVE_BATON_PASS, MOVE_SHADOW_BALL}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_PORYGON2,
    .heldItem = ITEM_SALAC_BERRY,
    .evs = {0, 0, 252, 0, 252, 0},
    .moves = {MOVE_THUNDER, MOVE_ICE_BEAM, MOVE_THUNDER_WAVE, MOVE_RECOVER}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_ELECTABUZZ,
    .heldItem = ITEM_LEFTOVERS,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_THUNDER, MOVE_CROSS_CHOP, MOVE_RAIN_DANCE, MOVE_ICE_PUNCH}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_MANECTRIC,
    .heldItem = ITEM_MAGNET,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_CRUNCH, MOVE_SHADOW_BALL, MOVE_THUNDER, MOVE_RAIN_DANCE}
    }
};
// Flannery Rematch 1 after Magma Hideout
static const struct TrainerMon sParty_Flannery2[] = {
    {
    .iv = 240,
    .lvl = 39,
    .species = SPECIES_NINETALES,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HEAT_WAVE, MOVE_SOLAR_BEAM, MOVE_WILL_O_WISP, MOVE_SUNNY_DAY}
    },
    {
    .iv = 230,
    .lvl = 38,
    .species = SPECIES_CASTFORM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WEATHER_BALL, MOVE_SUNNY_DAY, MOVE_HEADBUTT, MOVE_ICE_BEAM}
    },
    {
    .iv = 230,
    .lvl = 39,
    .species = SPECIES_MAGCARGO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_OVERHEAT, MOVE_ROCK_SLIDE, MOVE_YAWN, MOVE_ATTRACT}
    },
    {
    .iv = 240,
    .lvl = 38,
    .species = SPECIES_RAPIDASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_OVERHEAT, MOVE_DOUBLE_KICK, MOVE_IRON_TAIL, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = 250,
    .lvl = 40,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_BODY_SLAM, MOVE_SLUDGE_BOMB}
    }
};
// Flannery Rematch 2
static const struct TrainerMon sParty_Flannery3[] = {
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_MAGCARGO,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_FIRE_BLAST, MOVE_ROCK_SLIDE, MOVE_AMNESIA, MOVE_SUNNY_DAY}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_BELLOSSOM,
    .heldItem = ITEM_MIRACLE_SEED,
    .moves = {MOVE_SYNTHESIS, MOVE_SOLAR_BEAM, MOVE_SLEEP_POWDER, MOVE_SUNNY_DAY}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_ATTRACT, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_CHARIZARD,
    .heldItem = ITEM_HARD_STONE,
    .moves = {MOVE_OVERHEAT, MOVE_SWORDS_DANCE, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_MAGMAR,
    .heldItem = ITEM_CHARCOAL,
    .moves = {MOVE_FIRE_BLAST, MOVE_PSYCHIC, MOVE_THUNDER_PUNCH, MOVE_CONFUSE_RAY}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_ERUPTION, MOVE_ROCK_SLIDE, MOVE_YAWN, MOVE_REST}
    }
};
// Flannery Rematch 3
static const struct TrainerMon sParty_Flannery4[] = {
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_CHARIZARD,
    .heldItem = ITEM_CHARCOAL,
    .moves = {MOVE_SUNNY_DAY, MOVE_HEAT_WAVE, MOVE_DRAGON_CLAW, MOVE_ROCK_SLIDE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_ERUPTION, MOVE_PROTECT, MOVE_EXPLOSION, MOVE_EARTHQUAKE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_JUMPLUFF,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_SLEEP_POWDER, MOVE_SYNTHESIS, MOVE_LEECH_SEED, MOVE_PROTECT}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_HOUNDOOM,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_REST}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_RAPIDASH,
    .heldItem = ITEM_FOCUS_BAND,
    .moves = {MOVE_FIRE_BLAST, MOVE_HI_JUMP_KICK, MOVE_BATON_PASS, MOVE_AGILITY}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_ERUPTION, MOVE_ROCK_SLIDE, MOVE_YAWN, MOVE_REST}
    }
};
// Flannery Rematch 4
static const struct TrainerMon sParty_Flannery5[] = {
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_ARCANINE,
    .heldItem = ITEM_CHARCOAL,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_FIRE_BLAST, MOVE_EXTREME_SPEED, MOVE_SUNNY_DAY, MOVE_ROAR}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_MAGCARGO,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {0, 0, 252, 0, 252, 0},
    .moves = {MOVE_HEAT_WAVE, MOVE_SUBSTITUTE, MOVE_REFRESH, MOVE_ROCK_SLIDE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_SHIFTRY,
    .heldItem = ITEM_SCOPE_LENS,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_LEAF_BLADE, MOVE_FAINT_ATTACK, MOVE_SYNTHESIS, MOVE_SUNNY_DAY}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_BLAZIKEN,
    .heldItem = ITEM_BLACK_BELT,
    .evs = {0, 252, 0, 0, 252, 0},
    .moves = {MOVE_BLAZE_KICK, MOVE_HI_JUMP_KICK, MOVE_THUNDER_PUNCH, MOVE_BOUNCE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_TYPHLOSION,
    .heldItem = ITEM_LIECHI_BERRY,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_ERUPTION, MOVE_ENDURE, MOVE_REVERSAL, MOVE_THUNDER_PUNCH}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_TORKOAL,
    .heldItem = ITEM_WHITE_HERB,
    .evs = {252, 0, 0, 0, 252, 0},
    .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_CURSE, MOVE_ROCK_SLIDE}
    }
};
// Norman Rematch 1 after getting all 8 gym badges
static const struct TrainerMon sParty_Norman2[] = {
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_DELCATTY,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_HELPING_HAND, MOVE_WISH, MOVE_BLIZZARD, MOVE_FAKE_OUT}
    },
    {
    .iv = 250, 
    .lvl = 50,
    .species = SPECIES_EXPLOUD,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_OVERHEAT, MOVE_TEETER_DANCE, MOVE_HYPER_VOICE, MOVE_WATER_PULSE}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_ZANGOOSE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SLASH, MOVE_SWORDS_DANCE, MOVE_CUT, MOVE_BRICK_BREAK}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_LINOONE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_HEADBUTT, MOVE_BELLY_DRUM, MOVE_FACADE, MOVE_IRON_TAIL}
    },
    {
    .iv = 250, 
    .lvl = 50,
    .species = SPECIES_GIRAFARIG,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SKILL_SWAP, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_EARTHQUAKE}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_REST, MOVE_FACADE, MOVE_FAINT_ATTACK}
    }
};
// Norman Rematch 2
static const struct TrainerMon sParty_Norman3[] = {
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_AIPOM,
    .heldItem = ITEM_WIKI_BERRY,
    .moves = {MOVE_AGILITY, MOVE_BATON_PASS, MOVE_BEAT_UP, MOVE_SUBSTITUTE}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_STANTLER,
    .heldItem = ITEM_SILK_SCARF,
    .moves = {MOVE_DREAM_EATER, MOVE_HYPNOSIS, MOVE_REFLECT, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_PORYGON2,
    .heldItem = ITEM_SHARP_BEAK,
    .moves = {MOVE_RECOVER, MOVE_CURSE, MOVE_TRI_ATTACK, MOVE_AERIAL_ACE}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_EXPLOUD,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_TEETER_DANCE, MOVE_HYPER_VOICE, MOVE_OVERHEAT, MOVE_BRICK_BREAK}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_GIRAFARIG,
    .heldItem = ITEM_TWISTED_SPOON,
    .moves = {MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_WISH, MOVE_CALM_MIND}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_EARTHQUAKE, MOVE_FACADE, MOVE_FOCUS_PUNCH, MOVE_COUNTER}
    }
};
// Norman Rematch 3
static const struct TrainerMon sParty_Norman4[] = {
     {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_TAUROS,
    .heldItem = ITEM_LUM_BERRY,
    .moves = {MOVE_DOUBLE_EDGE, MOVE_PURSUIT, MOVE_IRON_TAIL, MOVE_EARTHQUAKE}
    },
    {
    .iv = 255,
    .lvl = 60, 
    .species = SPECIES_GRANBULL,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_HEAL_BELL, MOVE_PROTECT, MOVE_CRUNCH, MOVE_BODY_SLAM}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_URSARING,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_REST, MOVE_SLEEP_TALK, MOVE_BODY_SLAM, MOVE_CRUNCH}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_BLISSEY,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_REST, MOVE_THUNDER_WAVE, MOVE_WATER_PULSE, MOVE_BLIZZARD}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_GIRAFARIG, 
    .heldItem = ITEM_TWISTED_SPOON,
    .moves = {MOVE_THUNDER_WAVE, MOVE_PSYCHIC, MOVE_WISH, MOVE_THUNDERBOLT}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_SLAKING, 
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_EARTHQUAKE, MOVE_HYPER_BEAM, MOVE_DOUBLE_EDGE, MOVE_BRICK_BREAK}
    }
};
// Norman Rematch 4
static const struct TrainerMon sParty_Norman5[] = {
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_SLAKING,
    .heldItem = ITEM_LEFTOVERS,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_BLIZZARD, MOVE_THUNDER, MOVE_CRUSH_CLAW, MOVE_ROCK_SLIDE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_BLISSEY,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {252, 0, 252, 0, 0, 0},
    .moves = {MOVE_SEISMIC_TOSS, MOVE_HEAL_BELL, MOVE_SKILL_SWAP, MOVE_THUNDER_WAVE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_TAUROS,
    .heldItem = ITEM_LUM_BERRY,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_PURSUIT}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_SMEARGLE,
    .heldItem = ITEM_SALAC_BERRY,
    .evs = {252, 0, 0, 252, 0, 0},
    .moves = {MOVE_BELLY_DRUM, MOVE_SUBSTITUTE, MOVE_SPORE, MOVE_BATON_PASS}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_SNORLAX,
    .heldItem = ITEM_CHESTO_BERRY,
    .evs = {252, 0, 252, 0, 0, 0},
    .moves = {MOVE_CURSE, MOVE_REST, MOVE_BODY_SLAM, MOVE_FOCUS_PUNCH}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_ZANGOOSE,
    .heldItem = ITEM_CHOICE_BAND,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_BRICK_BREAK, MOVE_IRON_TAIL, MOVE_RETURN, MOVE_CUT}
    }
};
// Winona Rematch 1 after Rayquaza Event
static const struct TrainerMon sParty_Winona2[] = {
    {
    .iv = 250,
    .lvl = 48,
    .species = SPECIES_CROBAT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_AERIAL_ACE, MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = 255,
    .lvl = 49,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_WHIRLWIND, MOVE_SPIKES, MOVE_PROTECT, MOVE_TOXIC}
    },
    {
    .iv = 250,
    .lvl = 49,
    .species = SPECIES_TROPIUS,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ROCK_SMASH, MOVE_GIGA_DRAIN, MOVE_EARTHQUAKE, MOVE_WHIRLWIND}
    },
    {
    .iv = 250,
    .lvl = 49,
    .species = SPECIES_SWELLOW,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SKY_ATTACK, MOVE_STEEL_WING, MOVE_FACADE, MOVE_WHIRLWIND}
    },
    {
    .iv = 250,
    .lvl = 48,
    .species = SPECIES_DODRIO,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRILL_PECK, MOVE_TRI_ATTACK, MOVE_ENDEAVOR, MOVE_PURSUIT}
    },
    {
    .iv = 255,
    .lvl = 50,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_LUM_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_FLAMETHROWER, MOVE_DRAGON_DANCE, MOVE_SKY_ATTACK}
    }
};
// Winona Rematch 2
static const struct TrainerMon sParty_Winona3[] = {
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_XATU,
    .heldItem = ITEM_MIRACLE_SEED,
    .moves = {MOVE_GIGA_DRAIN, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_CALM_MIND}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_MASQUERAIN,
    .heldItem = ITEM_MYSTIC_WATER,
    .moves = {MOVE_STUN_SPORE, MOVE_HYDRO_PUMP, MOVE_GIGA_DRAIN, MOVE_SHADOW_BALL}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_MURKROW,
    .heldItem = ITEM_SHARP_BEAK,
    .moves = {MOVE_SKY_ATTACK, MOVE_DOUBLE_EDGE, MOVE_FAINT_ATTACK, MOVE_STEEL_WING}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_PIDGEOT,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_SKY_ATTACK, MOVE_EXTREME_SPEED, MOVE_PROTECT, MOVE_PURSUIT}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_MANTINE,
    .heldItem = ITEM_WIKI_BERRY,
    .moves = {MOVE_BLIZZARD, MOVE_HYDRO_PUMP, MOVE_HAZE, MOVE_CONFUSE_RAY}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_CHOICE_BAND,
    .moves = {MOVE_SKY_ATTACK, MOVE_DOUBLE_EDGE, MOVE_IRON_TAIL, MOVE_EARTHQUAKE}
    }
};
// Winona Rematch 3
static const struct TrainerMon sParty_Winona4[] = {
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_CROBAT,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_SLEEP_TALK, MOVE_REST, MOVE_AERIAL_ACE, MOVE_CONFUSE_RAY}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_LUM_BERRY,
    .moves = {MOVE_SPIKES, MOVE_PROTECT, MOVE_TOXIC, MOVE_WHIRLWIND}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_TROPIUS,
    .heldItem = ITEM_SOFT_SAND,
    .moves = {MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE, MOVE_FACADE, MOVE_STEEL_WING}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_DRAGONITE,
    .heldItem = ITEM_KINGS_ROCK,
    .moves = {MOVE_THUNDER_WAVE, MOVE_WATERFALL, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_SWELLOW,
    .heldItem = ITEM_FOCUS_BAND,
    .moves = {MOVE_SKY_ATTACK, MOVE_STEEL_WING, MOVE_AGILITY, MOVE_BATON_PASS}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_CHOICE_BAND,
    .moves = {MOVE_SKY_ATTACK, MOVE_DOUBLE_EDGE, MOVE_IRON_TAIL, MOVE_EARTHQUAKE}
    }
};
// Winona Rematch 4
static const struct TrainerMon sParty_Winona5[] = {
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_DRAGONITE,
    .heldItem = ITEM_LEFTOVERS,
    .evs = {252, 252, 0, 0, 0, 0},
    .moves = {MOVE_THUNDER_WAVE, MOVE_EARTHQUAKE, MOVE_DYNAMIC_PUNCH, MOVE_THUNDERBOLT}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_YANMA,
    .heldItem = ITEM_LIECHI_BERRY,
    .evs = {252, 252, 0, 0, 0, 0},
    .moves = {MOVE_SUBSTITUTE, MOVE_REVERSAL, MOVE_PROTECT, MOVE_TWINEEDLE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_CHARIZARD,
    .heldItem = ITEM_FOCUS_BAND,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_FIRE_BLAST, MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_SWELLOW,
    .heldItem = ITEM_STARF_BERRY,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_SUBSTITUTE, MOVE_ENDEAVOR, MOVE_QUICK_ATTACK, MOVE_BATON_PASS}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_TROPIUS,
    .heldItem = ITEM_SOFT_SAND,
    .evs = {252, 252, 0, 0, 0, 0},
    .moves = {MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE, MOVE_GIGA_DRAIN, MOVE_SYNTHESIS}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_LUM_BERRY,
    .evs = {252, 252, 0, 0, 0, 0},
    .moves = {MOVE_SKY_ATTACK, MOVE_DRAGON_DANCE, MOVE_PURSUIT, MOVE_EARTHQUAKE}
    }
};
// Tate & Liza Rematch 1 After 8 badges
static const struct TrainerMon sParty_TateAndLiza2[] = {
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_LUNATONE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_LIGHT_SCREEN, MOVE_HYPNOSIS, MOVE_CALM_MIND}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_SOLROCK,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_SOLAR_BEAM, MOVE_FLAMETHROWER, MOVE_SUNNY_DAY}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_WOBBUFFET,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ENCORE, MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_DESTINY_BOND}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_STARMIE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_THUNDERBOLT}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_XATU,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_SUNNY_DAY, MOVE_GIGA_DRAIN}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_PSYCHIC, MOVE_LIGHT_SCREEN}
    }
};
// Tate & Liza Rematch 2
static const struct TrainerMon sParty_TateAndLiza3[] = {
   {
    .iv = 250,
    .lvl = 55,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_BLACK_BELT,
    .moves = {MOVE_SUNNY_DAY, MOVE_FIRE_PUNCH, MOVE_FAKE_OUT, MOVE_HI_JUMP_KICK}
    },
    {
    .iv = 250,
    .lvl = 55,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_SOFT_SAND,
    .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SKILL_SWAP, MOVE_FACADE}
    },
    {
    .iv = 250,
    .lvl = 55,
    .species = SPECIES_GARDEVOIR,
    .heldItem = ITEM_TWISTED_SPOON,
    .moves = {MOVE_CALM_MIND, MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_THUNDERBOLT}
    },
    {
    .iv = 250,
    .lvl = 55,
    .species = SPECIES_EXEGGUTOR,
    .heldItem = ITEM_LUM_BERRY,
    .moves = {MOVE_SYNTHESIS, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_SLEEP_POWDER}
    },
    {
    .iv = 250,
    .lvl = 55,
    .species = SPECIES_LUNATONE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_HYPNOSIS, MOVE_CALM_MIND}
    },
    {
    .iv = 250,
    .lvl = 55,
    .species = SPECIES_SOLROCK,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_PSYCH_UP, MOVE_SOLAR_BEAM, MOVE_OVERHEAT, MOVE_SUNNY_DAY}
    }
};
// Tate & Liza Rematch 3
static const struct TrainerMon sParty_TateAndLiza4[] = {
    {
    .iv = 250,
    .lvl = 60,
    .species = SPECIES_SLOWKING,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_THUNDER_WAVE, MOVE_FLAMETHROWER, MOVE_REST, MOVE_PSYCHIC}
    },
    {
    .iv = 250,
    .lvl = 60,
    .species = SPECIES_SLOWBRO,
    .heldItem = ITEM_SOFT_SAND,
    .moves = {MOVE_THUNDER_WAVE, MOVE_CALM_MIND, MOVE_SURF, MOVE_PSYCHIC}
    },
    {
    .iv = 250,
    .lvl = 60,
    .species = SPECIES_GRUMPIG,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_YAWN, MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_FOCUS_PUNCH}
    },
    {
    .iv = 250,
    .lvl = 60,
    .species = SPECIES_ALAKAZAM,
    .heldItem = ITEM_CHOICE_BAND,
    .moves = {MOVE_PSYCHIC, MOVE_TRICK, MOVE_THUNDER_PUNCH, MOVE_THUNDER_WAVE}
    },
    {
    .iv = 250,
    .lvl = 60,
    .species = SPECIES_LUNATONE,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_HYPNOSIS, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = 250,
    .lvl = 60,
    .species = SPECIES_SOLROCK,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_OVERHEAT, MOVE_CURSE}
    }
};
// Tate & Liza Rematch 4
static const struct TrainerMon sParty_TateAndLiza5[] = {
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {0, 0, 252, 0, 0, 252},
    .moves = {MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_SKILL_SWAP, MOVE_LIGHT_SCREEN}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_UMBREON,
    .heldItem = ITEM_APICOT_BERRY,
    .evs = {252, 0, 0, 0, 0, 252},
    .moves = {MOVE_SUBSTITUTE, MOVE_BATON_PASS, MOVE_DOUBLE_TEAM, MOVE_TOXIC}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_ESPEON,
    .heldItem = ITEM_STARF_BERRY,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_BATON_PASS, MOVE_CALM_MIND, MOVE_SHADOW_BALL, MOVE_PSYCHIC}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_LUNATONE,
    .heldItem = ITEM_LEFTOVERS,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_BATON_PASS, MOVE_COSMIC_POWER}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_SOLROCK,
    .heldItem = ITEM_LUM_BERRY,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_PSYCHIC, MOVE_FLAMETHROWER, MOVE_CALM_MIND, MOVE_BATON_PASS}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_METAGROSS,
    .heldItem = ITEM_WIKI_BERRY,
    .evs = {0, 252, 0, 0, 252, 0},
    .moves = {MOVE_PSYCHIC, MOVE_METEOR_MASH, MOVE_ICE_PUNCH, MOVE_ROCK_SLIDE}
    }
};
// Placeholder, Not Used
static const struct TrainerMon sParty_Juan2[] = {
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_LUVDISC,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_ATTRACT, MOVE_SWEET_KISS, MOVE_FLAIL}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_WATER_PULSE, MOVE_AMNESIA, MOVE_EARTHQUAKE}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_ENCORE, MOVE_BODY_SLAM, MOVE_AURORA_BEAM, MOVE_WATER_PULSE}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WATER_PULSE, MOVE_CRABHAMMER, MOVE_TAUNT, MOVE_LEER}
    },
    {
    .iv = 250,
    .lvl = 50,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_WATER_PULSE, MOVE_DOUBLE_TEAM, MOVE_ICE_BEAM, MOVE_REST}
    }
};
// Juan Rematch 1 - After Becoming Champion
static const struct TrainerMon sParty_Juan3[] = {
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_HUNTAIL,
    .heldItem = ITEM_FOCUS_BAND,
    .moves = {MOVE_CRUNCH, MOVE_DRAGON_DANCE, MOVE_BATON_PASS, MOVE_HYDRO_PUMP}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_GOREBYSS,
    .heldItem = ITEM_MYSTIC_WATER,
    .moves = {MOVE_SURF, MOVE_RAIN_DANCE, MOVE_ICE_BEAM, MOVE_SHADOW_BALL}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_QUAGSIRE,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_RAIN_DANCE, MOVE_MUDDY_WATER, MOVE_YAWN, MOVE_EARTHQUAKE}
    },
    
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_ENCORE}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_RELICANTH,
    .heldItem = ITEM_HARD_STONE,
    .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE, MOVE_RAIN_DANCE}
    },
    {
    .iv = 255,
    .lvl = 55,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_SURF, MOVE_DOUBLE_TEAM, MOVE_ICE_BEAM, MOVE_REST}
    }
};
// Juan Rematch 2
static const struct TrainerMon sParty_Juan4[] = {
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_MANTINE,
    .heldItem = ITEM_FOCUS_BAND,
    .moves = {MOVE_RAIN_DANCE, MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_AERIAL_ACE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_WHISCASH,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_SURF, MOVE_YAWN, MOVE_ICY_WIND, MOVE_EARTHQUAKE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_CHOICE_BAND,
    .moves = {MOVE_CRABHAMMER, MOVE_SLUDGE_BOMB, MOVE_BLIZZARD, MOVE_CRUNCH}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_AZUMARILL,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_SUPERPOWER, MOVE_DOUBLE_EDGE, MOVE_IRON_TAIL, MOVE_HYDRO_PUMP}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_LANTURN,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_RAIN_DANCE, MOVE_HYDRO_PUMP, MOVE_THUNDER, MOVE_THUNDER_WAVE}
    },
    {
    .iv = 255,
    .lvl = 60,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_LUM_BERRY,
    .moves = {MOVE_HYDRO_PUMP, MOVE_RAIN_DANCE, MOVE_BLIZZARD, MOVE_FLAIL}
    }
};
// Juan Rematch 3 (FINAL)
static const struct TrainerMon sParty_Juan5[] = {
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_POLITOED,
    .heldItem = ITEM_WIKI_BERRY,
    .evs = {252, 0, 0, 252, 0, 0},
    .moves = {MOVE_WHIRLPOOL, MOVE_PERISH_SONG, MOVE_HYPNOSIS, MOVE_PROTECT}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_CASTFORM,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_RAIN_DANCE, MOVE_WEATHER_BALL, MOVE_THUNDER, MOVE_HYDRO_PUMP}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_LEFTOVERS,
    .evs = {252, 0, 0, 0, 252, 0},
    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_YAWN, MOVE_ROCK_SLIDE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_SCOPE_LENS,
    .evs = {0, 252, 0, 0, 252, 0},
    .moves = {MOVE_CRABHAMMER, MOVE_RAIN_DANCE, MOVE_ANCIENT_POWER, MOVE_CRUNCH}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_BLASTOISE,
    .heldItem = ITEM_MYSTIC_WATER,
    .evs = {252, 0, 0, 0, 252, 0},
    .moves = {MOVE_RAIN_DANCE, MOVE_YAWN, MOVE_HYDRO_CANNON, MOVE_EARTHQUAKE}
    },
    {
    .iv = 255,
    .lvl = 65,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_CHESTO_BERRY,
    .evs = {252, 0, 0, 252, 0, 0},
    .moves = {MOVE_OCTAZOOKA, MOVE_REST, MOVE_DOUBLE_TEAM, MOVE_ICE_BEAM}
    }
};
// Mauville Gym Bug Maniac
static const struct TrainerMon sParty_Angelo[] = {
    {
    .iv = 100,
    .lvl = 18,
    .species = SPECIES_ILLUMISE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHOCK_WAVE, MOVE_MOONLIGHT, MOVE_CHARM, MOVE_NONE}
    },
    {
    .iv = 100,
    .lvl = 17,
    .species = SPECIES_VOLBEAT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_SHOCK_WAVE, MOVE_QUICK_ATTACK, MOVE_CONFUSE_RAY, MOVE_NONE}
    }
};
// Fortree Gym Bird Keeper 4
static const struct TrainerMon sParty_Darius[] = {
    {
    .iv = 150,
    .lvl = 32,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 150,
    .lvl = 32,
    .species = SPECIES_TROPIUS,
    }
};
// Champion
static const struct TrainerMon sParty_Steven1[] = {
    {
    .iv = 255,
    .lvl = 57,
    .species = SPECIES_SKARMORY,
    .heldItem = ITEM_LIECHI_BERRY,
    .moves = {MOVE_TOXIC, MOVE_SKY_ATTACK, MOVE_STEEL_WING, MOVE_WHIRLWIND}
    },
    {
    .iv = 255,
    .lvl = 56,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_PSYCHIC, MOVE_EARTHQUAKE, MOVE_LIGHT_SCREEN, MOVE_EXPLOSION}
    },
    {
    .iv = 255,
    .lvl = 56,
    .species = SPECIES_AGGRON,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_THUNDER_WAVE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_IRON_TAIL}
    },
    {
    .iv = 255,
    .lvl = 57,
    .species = SPECIES_CRADILY,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_ANCIENT_POWER, MOVE_LEECH_SEED, MOVE_RECOVER, MOVE_CURSE}
    },
    {
    .iv = 255,
    .lvl = 57,
    .species = SPECIES_ARMALDO,
    .heldItem = ITEM_CHOICE_BAND,
    .moves = {MOVE_ROCK_BLAST, MOVE_TWINEEDLE, MOVE_IRON_TAIL, MOVE_FACADE}
    },
    {
    .iv = 255,
    .lvl = 58,
    .species = SPECIES_METAGROSS,
    .heldItem = ITEM_LUM_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_METEOR_MASH, MOVE_AGILITY}
    }
}; 
// Post Game Boss
static const struct TrainerMon sParty_Steven2[] = {
    {
    .iv = 255,
    .lvl = 76,
    .species = SPECIES_ARMALDO,
    .heldItem = ITEM_SCOPE_LENS,
    .evs = {0, 252, 252, 0, 0, 0},
    .moves = {MOVE_ROCK_BLAST, MOVE_TWINEEDLE, MOVE_FACADE, MOVE_EARTHQUAKE}
    },
    {
    .iv = 255,
    .lvl = 75,
    .species = SPECIES_TYRANITAR,
    .heldItem = ITEM_SALAC_BERRY,
    .evs = {0, 252, 252, 0, 0, 0},
    .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_CRUNCH, MOVE_THUNDERBOLT}
    },
    {
    .iv = 255,
    .lvl = 77,
    .species = SPECIES_AERODACTYL,
    .heldItem = ITEM_CHOICE_BAND,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_SKY_ATTACK, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = 255,
    .lvl = 76,
    .species = SPECIES_CRADILY,
    .heldItem = ITEM_LEFTOVERS,
    .evs = {252, 0, 0, 0, 0, 252},
    .moves = {MOVE_REST, MOVE_CURSE, MOVE_SLEEP_TALK, MOVE_ANCIENT_POWER}
    },
    {
    .iv = 255,
    .lvl = 76,
    .species = SPECIES_STEELIX,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {252, 252, 0, 0, 0, 0},
    .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_EXPLOSION, MOVE_CRUNCH}
    },
    {
    .iv = 255,
    .lvl = 78,
    .species = SPECIES_METAGROSS,
    .heldItem = ITEM_LUM_BERRY,
    .evs = {252, 252, 0, 0, 0, 0},
    .moves = {MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_METEOR_MASH, MOVE_FIRE_PUNCH}
    }
};

static const struct TrainerMon sParty_Anabel[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Tucker[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Spenser[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Greta[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Noland[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Lucy[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Brandon[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_BELDUM,
    }
};

static const struct TrainerMon sParty_Andres2[] = {
    {
    .iv = 10,
    .lvl = 31,
    .species = SPECIES_SANDSLASH,
    },
    {
    .iv = 50,
    .lvl = 31,
    .species = SPECIES_BALTOY,
    },
    {
    .iv = 50,
    .lvl = 31,
    .species = SPECIES_TRAPINCH,
    }
};

static const struct TrainerMon sParty_Andres3[] = {
    {
    .iv = 10,
    .lvl = 35,
    .species = SPECIES_SANDSLASH,
    },
    {
    .iv = 50,
    .lvl = 35,
    .species = SPECIES_BALTOY,
    },
    {
    .iv = 50,
    .lvl = 35,
    .species = SPECIES_VIBRAVA,
    }
};

static const struct TrainerMon sParty_Andres4[] = {
    {
    .iv = 10,
    .lvl = 37,
    .species = SPECIES_SANDSLASH,
    },
    {
    .iv = 50,
    .lvl = 38,
    .species = SPECIES_CLAYDOL,
    },
    {
    .iv = 50,
    .lvl = 40,
    .species = SPECIES_VIBRAVA,
    }
};

static const struct TrainerMon sParty_Andres5[] = {
    {
    .iv = 10,
    .lvl = 45,
    .species = SPECIES_SANDSLASH,
    },
    {
    .iv = 50,
    .lvl = 44,
    .species = SPECIES_CLAYDOL,
    },
    {
    .iv = 50,
    .lvl = 45,
    .species = SPECIES_FLYGON,
    }
};

static const struct TrainerMon sParty_Cory2[] = {
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = 0,
    .lvl = 30,
    .species = SPECIES_TENTACRUEL,
    }
};

static const struct TrainerMon sParty_Cory3[] = {
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_TENTACRUEL,
    }
};

static const struct TrainerMon sParty_Cory4[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_MACHAMP,
    },
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_TENTACRUEL,
    }
};

static const struct TrainerMon sParty_Cory5[] = {
    {
    .iv = 40,
    .lvl = 40,
    .species = SPECIES_HARIYAMA,
    },
    {
    .iv = 40,
    .lvl = 40,
    .species = SPECIES_MACHAMP,
    },
    {
    .iv = 40,
    .lvl = 40,
    .species = SPECIES_TENTACRUEL,
    }
};

static const struct TrainerMon sParty_Pablo2[] = {
    {
    .iv = 50,
    .lvl = 40,
    .species = SPECIES_LANTURN,
    },
    {
    .iv = 50,
    .lvl = 40,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Pablo3[] = {
    {
    .iv = 50,
    .lvl = 42,
    .species = SPECIES_LANTURN,
    },
    {
    .iv = 50,
    .lvl = 42,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Pablo4[] = {
    {
    .iv = 40,
    .lvl = 42,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 50,
    .lvl = 45,
    .species = SPECIES_LANTURN,
    },
    {
    .iv = 50,
    .lvl = 45,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Pablo5[] = {
    {
    .iv = 60,
    .lvl = 45,
    .species = SPECIES_PELIPPER,
    },
    {
    .iv = 60,
    .lvl = 48,
    .species = SPECIES_LANTURN,
    },
    {
    .iv = 60,
    .lvl = 48,
    .species = SPECIES_STARMIE,
    }
};

static const struct TrainerMon sParty_Koji2[] = {
    {
    .iv = 10,
    .lvl = 42,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 10,
    .lvl = 37,
    .species = SPECIES_MACHOKE,
    }
};

static const struct TrainerMon sParty_Koji3[] = {
    {
    .iv = 10,
    .lvl = 44,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 10,
    .lvl = 40,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = 20,
    .lvl = 42,
    .species = SPECIES_MACHAMP,
    }
};

static const struct TrainerMon sParty_Koji4[] = {
    {
    .iv = 20,
    .lvl = 45,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 10,
    .lvl = 42,
    .species = SPECIES_MACHAMP,
    },
    {
    .iv = 30,
    .lvl = 44,
    .species = SPECIES_MACHAMP,
    }
};

static const struct TrainerMon sParty_Koji5[] = {
    {
    .iv = 40,
    .lvl = 47,
    .species = SPECIES_BRELOOM,
    },
    {
    .iv = 40,
    .lvl = 46,
    .species = SPECIES_MACHAMP,
    },
    {
    .iv = 40,
    .lvl = 48,
    .species = SPECIES_MACHAMP,
    }
};

static const struct TrainerMon sParty_Cristin2[] = {
    {
    .iv = 100,
    .lvl = 36,
    .species = SPECIES_DONPHAN,
    },
    {
    .iv = 100,
    .lvl = 36,
    .species = SPECIES_GOLDUCK,
    }
};

static const struct TrainerMon sParty_Cristin3[] = {
    {
    .iv = 120,
    .lvl = 37,
    .species = SPECIES_PINSIR,
    },
    {
    .iv = 100,
    .lvl = 38,
    .species = SPECIES_DONPHAN,
    },
    {
    .iv = 100,
    .lvl = 38,
    .species = SPECIES_GOLDUCK,
    }
};

static const struct TrainerMon sParty_Cristin4[] = {
    {
    .iv = 120,
    .lvl = 40,
    .species = SPECIES_PINSIR,
    },
    {
    .iv = 100,
    .lvl = 40,
    .species = SPECIES_DONPHAN,
    },
    {
    .iv = 100,
    .lvl = 40,
    .species = SPECIES_GOLDUCK,
    }
};

static const struct TrainerMon sParty_Cristin5[] = {
    {
    .iv = 120,
    .lvl = 42,
    .species = SPECIES_PINSIR,
    },
    {
    .iv = 100,
    .lvl = 43,
    .species = SPECIES_DONPHAN,
    },
    {
    .iv = 100,
    .lvl = 45,
    .species = SPECIES_GOLDUCK,
    }
};

static const struct TrainerMon sParty_Fernando2[] = {
    {
    .iv = 10,
    .lvl = 35,
    .species = SPECIES_ELECTRODE
    },
    {
    .iv = 10,
    .lvl = 35,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = 10,
    .lvl = 38,
    .species = SPECIES_LOUDRED,
    }
};

static const struct TrainerMon sParty_Fernando3[] = {
    {
    .iv = 20,
    .lvl = 38,
    .species = SPECIES_ELECTRODE,
    },
    {
    .iv = 20,
    .lvl = 37,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = 20,
    .lvl = 40,
    .species = SPECIES_EXPLOUD,
    }
};

static const struct TrainerMon sParty_Fernando4[] = {
    {
    .iv = 20,
    .lvl = 40,
    .species = SPECIES_ELECTRODE,
    },
    {
    .iv = 20,
    .lvl = 40,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = 20,
    .lvl = 42,
    .species = SPECIES_EXPLOUD,
    }
};

static const struct TrainerMon sParty_Fernando5[] = {
    {
    .iv = 20,
    .lvl = 43,
    .species = SPECIES_ELECTRODE,
    },
    {
    .iv = 20,
    .lvl = 43,
    .species = SPECIES_MANECTRIC,
    },
    {
    .iv = 20,
    .lvl = 45,
    .species = SPECIES_EXPLOUD,
    }
};

static const struct TrainerMon sParty_Sawyer2[] = {
    {
    .iv = 10,
    .lvl = 28,
    .species = SPECIES_GRAVELER,
    },
    {
    .iv = 10,
    .lvl = 26,
    .species = SPECIES_NUMEL,
    }
};

static const struct TrainerMon sParty_Sawyer3[] = {
    {
    .iv = 20,
    .lvl = 28,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = 20,
    .lvl = 30,
    .species = SPECIES_NUMEL,
    },
    {
    .iv = 20,
    .lvl = 30,
    .species = SPECIES_GRAVELER,
    }
};

static const struct TrainerMon sParty_Sawyer4[] = {
    {
    .iv = 30,
    .lvl = 35,
    .species = SPECIES_MACHOKE,
    },
    {
    .iv = 30,
    .lvl = 34,
    .species = SPECIES_CAMERUPT
    },
    {
    .iv = 30,
    .lvl = 35,
    .species = SPECIES_GRAVELER,
    }
};

static const struct TrainerMon sParty_Sawyer5[] = {
    {
    .iv = 40,
    .lvl = 38,
    .species = SPECIES_MACHAMP,
    },
    {
    .iv = 40,
    .lvl = 30,
    .species = SPECIES_CAMERUPT,
    },
    {
    .iv = 40,
    .lvl = 38,
    .species = SPECIES_GOLEM,
    }
};

static const struct TrainerMon sParty_Gabrielle2[] = {
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_SHUPPET,
    },
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_DUSKULL,
    },
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_NATU,
    },
    {
    .iv = 0,
    .lvl = 32,
    .species = SPECIES_CHIMECHO,
    }
};

static const struct TrainerMon sParty_Gabrielle3[] = {
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_SHUPPET,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_DUSCLOPS,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_XATU,
    },
    {
    .iv = 0,
    .lvl = 35,
    .species = SPECIES_CHIMECHO,
    }
};

static const struct TrainerMon sParty_Gabrielle4[] = {
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_BANETTE,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_DUSCLOPS,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_XATU,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_CHIMECHO,
    }
};

static const struct TrainerMon sParty_Gabrielle5[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_BANETTE,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_DUSCLOPS,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_XATU,
    },
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_CHIMECHO,
    }
};

static const struct TrainerMon sParty_Thalia2[] = {
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 0,
    .lvl = 34,
    .species = SPECIES_SWABLU,
    },
    {
    .iv = 10,
    .lvl = 34,
    .species = SPECIES_SEADRA,
    }
};

static const struct TrainerMon sParty_Thalia3[] = {
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 0,
    .lvl = 36,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = 10,
    .lvl = 36,
    .species = SPECIES_SEADRA,
    }
};

static const struct TrainerMon sParty_Thalia4[] = {
    {
    .iv = 0,
    .lvl = 40,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 0,
    .lvl = 38,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = 10,
    .lvl = 40,
    .species = SPECIES_SEADRA,
    }
};

static const struct TrainerMon sParty_Thalia5[] = {
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_ROSELIA,
    },
    {
    .iv = 0,
    .lvl = 45,
    .species = SPECIES_ALTARIA,
    },
    {
    .iv = 40,
    .lvl = 45,
    .species = SPECIES_KINGDRA,
    }
};
// Trick Room 7
static const struct TrainerMon sParty_Mariela[] = {
    {
    .iv = 0,
    .lvl = 43,
    .species = SPECIES_CHIMECHO,
    }
};
// Trick Room 7
static const struct TrainerMon sParty_Alvaro[] = {
    {
    .iv = 0,
    .lvl = 42,
    .species = SPECIES_DUSCLOPS,
    },
    {
    .iv = 0,
    .lvl = 41,
    .species = SPECIES_ALAKAZAM,
    }
};
// Trick Room 7
static const struct TrainerMon sParty_Everett[] = {
    {
    .iv = 0,
    .lvl = 41,
    .species = SPECIES_WOBBUFFET,
    }
};

static const struct TrainerMon sParty_Red[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_CHARMANDER,
    }
};

static const struct TrainerMon sParty_Leaf[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_BULBASAUR,
    }
};

static const struct TrainerMon sParty_BrendanLinkPlaceholder[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_GROUDON,
    }
};

static const struct TrainerMon sParty_MayLinkPlaceholder[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_KYOGRE,
    }
};
// Dewford Gym (added) Black Belt 3 (Top Left)
static const struct TrainerMon sParty_Kenji[] = {
    {
    .iv = 127,
    .lvl = 12,
    .species = SPECIES_MAKUHITA,
    },
    {
    .iv = 200,
    .lvl = 14,
    .species = SPECIES_MACHOP,
    }
};

// Route 106 Fisherman 3 (added) 
static const struct TrainerMon sParty_Tully[] = {
    {
    .iv = 10,
    .lvl = 11,
    .species = SPECIES_GOLDEEN,
    },
    {
    .iv = 10,
    .lvl = 11,
    .species = SPECIES_TENTACOOL,
    }
};
// Granite Cave Hiker 1 (added) 
static const struct TrainerMon sParty_Daniel[] = {
    {
    .iv = 100,
    .lvl = 15,
    .species = SPECIES_GEODUDE,
    }
};
// Granite Cave Hiker 2 (added) 
static const struct TrainerMon sParty_Tobin[] = {
    {
    .iv = 50,
    .lvl = 13,
    .species = SPECIES_GEODUDE,
    },
    {
    .iv = 50,
    .lvl = 13,
    .species = SPECIES_MACHOP,
    }
};
// Petalburg (added)
static const struct TrainerMon sParty_WallyPetalburg[] = {
    {
    .iv = 50,
    .lvl = 28,
    .species = SPECIES_SWABLU,
    .moves = {MOVE_AIR_CUTTER, MOVE_SING, MOVE_FLY, MOVE_TAKE_DOWN}
    },
    {
    .iv = 50,
    .lvl = 28,
    .species = SPECIES_DELCATTY,
    .moves = {MOVE_CHARM, MOVE_FAINT_ATTACK, MOVE_TAKE_DOWN, MOVE_SING}
    },
    {
    .iv = 100,
    .lvl = 29,
    .species = SPECIES_KIRLIA,
    .moves = {MOVE_PSYCHIC, MOVE_DOUBLE_TEAM, MOVE_SHOCK_WAVE, MOVE_CALM_MIND}
    }
};

// Dewford Gym Leader if beat Wattson prior
static const struct TrainerMon sParty_Brawly1_2[] = {
    {
    .iv = 150,
    .lvl = 24,
    .species = SPECIES_MEDITITE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CONFUSION, MOVE_THUNDER_PUNCH, MOVE_LIGHT_SCREEN, MOVE_REFLECT}
    },
    {
    .iv = 100,
    .lvl = 25,
    .species = SPECIES_MACHOKE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KARATE_CHOP, MOVE_ROCK_TOMB, MOVE_SEISMIC_TOSS, MOVE_REVENGE}
    },
    {
    .iv = 100,
    .lvl = 24,
    .species = SPECIES_BRELOOM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_MACH_PUNCH, MOVE_MEGA_DRAIN, MOVE_BULK_UP, MOVE_STUN_SPORE}
    },
    {
    .iv = 200,
    .lvl = 26,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_VITAL_THROW, MOVE_REVERSAL, MOVE_BULK_UP, MOVE_FAINT_ATTACK}
    }
};

// Dewford Gym Leader if beat Flannery prior
static const struct TrainerMon sParty_Brawly1_3[] = {
   {
    .iv = 180,
    .lvl = 31,
    .species = SPECIES_MEDITITE,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_EXTRASENSORY, MOVE_THUNDER_PUNCH, MOVE_LIGHT_SCREEN, MOVE_REFLECT}
    },
    {
    .iv = 100,
    .lvl = 30,
    .species = SPECIES_MACHOKE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_KARATE_CHOP, MOVE_ROCK_TOMB, MOVE_SEISMIC_TOSS, MOVE_REVENGE}
    },
    {
    .iv = 100,
    .lvl = 31,
    .species = SPECIES_BRELOOM,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_MACH_PUNCH, MOVE_MEGA_DRAIN, MOVE_BULK_UP, MOVE_STUN_SPORE}
    },
    {
    .iv = 200,
    .lvl = 32,
    .species = SPECIES_HARIYAMA,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_VITAL_THROW, MOVE_REVERSAL, MOVE_BULK_UP, MOVE_FAINT_ATTACK}
    }
};

// Magma Admin (Magma Hideout)
static const struct TrainerMon sParty_Courtney1[] = {
    {
    .iv = 100,
    .lvl = 37,
    .species = SPECIES_MURKROW,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_WING_ATTACK, MOVE_FAINT_ATTACK, MOVE_ICY_WIND, MOVE_STEEL_WING}
    },
    {
    .iv = 100,
    .lvl = 37,
    .species = SPECIES_ROSELIA,
    .heldItem = ITEM_PERSIM_BERRY,
    .moves = {MOVE_PETAL_DANCE, MOVE_SLUDGE_BOMB, MOVE_GRASS_WHISTLE, MOVE_SYNTHESIS}
    },
    {
    .iv = 100,
    .lvl = 37,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC, MOVE_ANCIENT_POWER, MOVE_LIGHT_SCREEN, MOVE_REFLECT}
    },
    {
    .iv = 150,
    .lvl = 38,
    .species = SPECIES_NINETALES,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLAMETHROWER, MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_SHADOW_BALL}
    }
};

// Magma Admin (Space Center)
static const struct TrainerMon sParty_Courtney2[] = {
     {
    .iv = 100,
    .lvl = 42,
    .species = SPECIES_MURKROW,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_DRILL_PECK, MOVE_FAINT_ATTACK, MOVE_ICY_WIND, MOVE_STEEL_WING}
    },
    {
    .iv = 100,
    .lvl = 43,
    .species = SPECIES_ROSELIA,
    .heldItem = ITEM_PERSIM_BERRY,
    .moves = {MOVE_PETAL_DANCE, MOVE_SLUDGE_BOMB, MOVE_GRASS_WHISTLE, MOVE_SYNTHESIS}
    },
    {
    .iv = 100,
    .lvl = 42,
    .species = SPECIES_CLAYDOL,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_PSYCHIC, MOVE_EARTHQUAKE, MOVE_LIGHT_SCREEN, MOVE_SUNNY_DAY}
    },
    {
    .iv = 150,
    .lvl = 44,
    .species = SPECIES_NINETALES,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_FLAMETHROWER, MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_SHADOW_BALL}
    }
};

// Archie Double Battle (Mt Pyre)
static const struct TrainerMon sParty_ArchieMtPyre[] = {
    {
    .iv = 150,
    .lvl = 38,
    .species = SPECIES_WAILORD,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_REST, MOVE_SLEEP_TALK, MOVE_SURF, MOVE_WHIRLPOOL}
    },
    {
    .iv = 150,
    .lvl = 38,
    .species = SPECIES_CROBAT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CONFUSE_RAY, MOVE_SLUDGE_BOMB, MOVE_TOXIC, MOVE_FLY}
    },
    {
    .iv = 220,
    .lvl = 39,
    .species = SPECIES_SHARPEDO,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_SLASH, MOVE_CRUNCH, MOVE_WATERFALL, MOVE_EARTHQUAKE}
    }
};
// Matt Double Battle (Mt Pyre)
static const struct TrainerMon sParty_MattMyPyre[] = {
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_ELECTRODE,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_RAIN_DANCE, MOVE_THUNDER, MOVE_LIGHT_SCREEN, MOVE_MIRROR_COAT}
    },
    {
    .iv = 150,
    .lvl = 36,
    .species = SPECIES_CRAWDAUNT,
    .heldItem = ITEM_NONE,
    .moves = {MOVE_CRABHAMMER, MOVE_KNOCK_OFF, MOVE_ICE_BEAM, MOVE_ROCK_SMASH}
    },
    {
    .iv = 150,
    .lvl = 37,
    .species = SPECIES_HUNTAIL,
    .heldItem = ITEM_SITRUS_BERRY,
    .moves = {MOVE_BODY_SLAM, MOVE_CURSE, MOVE_CRUNCH, MOVE_SURF}
    }
};

// Archie Marine Cave (Post Game)
static const struct TrainerMon sParty_ArchieMarineCave[] = {
    {
    .iv = 150,
    .lvl = 66,
    .species = SPECIES_TENTACRUEL,
    .heldItem = ITEM_PETAYA_BERRY,
    .moves = {MOVE_RAIN_DANCE, MOVE_SURF, MOVE_GIGA_DRAIN, MOVE_BLIZZARD}
    },
    {
    .iv = 150,
    .lvl = 67,
    .species = SPECIES_MACHAMP,
    .heldItem = ITEM_SCOPE_LENS,
    .moves = {MOVE_BULK_UP, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_CROSS_CHOP}
    },
    {
    .iv = 150,
    .lvl = 67,
    .species = SPECIES_WAILORD,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_WATER_SPOUT, MOVE_RAIN_DANCE, MOVE_EARTHQUAKE, MOVE_ICE_BEAM}
    },
    {
    .iv = 150,
    .lvl = 66,
    .species = SPECIES_MUK,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_THUNDER, MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_MINIMIZE}
    },
    {
    .iv = 150,
    .lvl = 66,
    .species = SPECIES_GYARADOS,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_REST, MOVE_EARTHQUAKE, MOVE_THUNDER_WAVE, MOVE_HYDRO_PUMP}
    },
    {
    .iv = 220,
    .lvl = 67,
    .species = SPECIES_SHARPEDO,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SURF, MOVE_FACADE}
    }
};

// Maxie Terra Cave (Post Game)
static const struct TrainerMon sParty_MaxieTerraCave[] = {
    {
    .iv = 150,
    .lvl = 65,
    .species = SPECIES_ARCANINE,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_SUNNY_DAY, MOVE_FIRE_BLAST, MOVE_BODY_SLAM, MOVE_REST}
    },
    {
    .iv = 150,
    .lvl = 66,
    .species = SPECIES_SHIFTRY,
    .heldItem = ITEM_SCOPE_LENS,
    .moves = {MOVE_LEAF_BLADE, MOVE_EXPLOSION, MOVE_FAINT_ATTACK, MOVE_EXTRASENSORY}
    },
    {
    .iv = 150,
    .lvl = 66,
    .species = SPECIES_HOUNDOOM,
    .heldItem = ITEM_WHITE_HERB,
    .moves = {MOVE_SOLAR_BEAM, MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_CRUNCH}
    },
    {
    .iv = 150,
    .lvl = 65,
    .species = SPECIES_WEEZING,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_EXPLOSION, MOVE_SUNNY_DAY, MOVE_SHADOW_BALL, MOVE_FIRE_BLAST}
    },
    {
    .iv = 150,
    .lvl = 65,
    .species = SPECIES_STEELIX,
    .heldItem = ITEM_SALAC_BERRY,
    .moves = {MOVE_SUNNY_DAY, MOVE_EXPLOSION, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE}
    },
    {
    .iv = 220,
    .lvl = 67,
    .species = SPECIES_CAMERUPT,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_ERUPTION, MOVE_EARTHQUAKE, MOVE_HEAT_WAVE, MOVE_ROCK_SLIDE}
    }
};

// Zinnia (Post Game)
static const struct TrainerMon sParty_Zinnia[] = {
    {
    .iv = 150,
    .lvl = 70,
    .species = SPECIES_ALTARIA,
    .heldItem = ITEM_CHESTO_BERRY,
    .moves = {MOVE_REST, MOVE_SKY_ATTACK, MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW}
    },
    {
    .iv = 150,
    .lvl = 70,
    .species = SPECIES_AMPHAROS,
    .heldItem = ITEM_QUICK_CLAW,
    .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_FIRE_PUNCH, MOVE_HEAL_BELL}
    },
    {
    .iv = 150,
    .lvl = 70,
    .species = SPECIES_SCEPTILE,
    .heldItem = ITEM_LEFTOVERS,
    .moves = {MOVE_LEECH_SEED, MOVE_DRAGON_CLAW, MOVE_LEAF_BLADE, MOVE_DOUBLE_TEAM}
    },
    {
    .iv = 150,
    .lvl = 70,
    .species = SPECIES_FLYGON,
    .heldItem = ITEM_CHOICE_BAND,
    .moves = {MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_SIGNAL_BEAM, MOVE_CRUNCH}
    },
    {
    .iv = 150,
    .lvl = 70,
    .species = SPECIES_CHARIZARD,
    .heldItem = ITEM_PETAYA_BERRY,
    .moves = {MOVE_ENDURE, MOVE_DRAGON_DANCE, MOVE_DRAGON_CLAW, MOVE_HEAT_WAVE}
    },
    {
    .iv = 220,
    .lvl = 70,
    .species = SPECIES_SALAMENCE,
    .heldItem = ITEM_LUM_BERRY,
    .moves = {MOVE_WISH, MOVE_TOXIC, MOVE_DRAGON_CLAW, MOVE_FIRE_BLAST}
    }
};

// Elite Four Sydney Rematch
static const struct TrainerMon sParty_Sidney2[] = {
    {
    .iv = 255,
    .lvl = 67,
    .species = SPECIES_NINJASK,
    .heldItem = ITEM_PETAYA_BERRY,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_PROTECT, MOVE_SUBSTITUTE, MOVE_BATON_PASS, MOVE_AERIAL_ACE}
    },
    {
    .iv = 255,
    .lvl = 68,
    .species = SPECIES_SHIFTRY,
    .heldItem = ITEM_LIECHI_BERRY,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_LEAF_BLADE, MOVE_FAINT_ATTACK, MOVE_AERIAL_ACE, MOVE_EXTRASENSORY}
    },
    {
    .iv = 255,
    .lvl = 68,
    .species = SPECIES_HOUNDOOM,
    .heldItem = ITEM_CHARCOAL,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_CRUNCH, MOVE_FIRE_BLAST, MOVE_REST, MOVE_REVERSAL}
    },
    {
    .iv = 255,
    .lvl = 68,
    .species = SPECIES_SHARPEDO,
    .heldItem = ITEM_LUM_BERRY,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_WATERFALL, MOVE_ICE_BEAM, MOVE_CRUNCH, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = 255,
    .lvl = 67,
    .species = SPECIES_ZANGOOSE,
    .heldItem = ITEM_SALAC_BERRY,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_ENDURE, MOVE_PURSUIT, MOVE_FLAIL, MOVE_AERIAL_ACE}
    },
    {
    .iv = 255,
    .lvl = 69,
    .species = SPECIES_ABSOL,
    .heldItem = ITEM_CHOICE_BAND,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_CRUNCH, MOVE_FACADE, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE}
    }
};
//Elite Four Phoebe Rematch
static const struct TrainerMon sParty_Phoebe2[] = {
    {
    .iv = 255,
    .lvl = 68,
    .species = SPECIES_MISDREAVUS,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {252, 0, 252, 0, 0, 0},
    .moves = {MOVE_PERISH_SONG, MOVE_PROTECT, MOVE_PAIN_SPLIT, MOVE_DESTINY_BOND}
    },
    {
    .iv = 255,
    .lvl = 68,
    .species = SPECIES_WOBBUFFET,
    .heldItem = ITEM_LUM_BERRY,
    .evs = {252, 0, 252, 0, 0, 0},
    .moves = {MOVE_COUNTER, MOVE_ENCORE, MOVE_MIRROR_COAT, MOVE_DESTINY_BOND}
    },
    {
    .iv = 255,
    .lvl = 69,
    .species = SPECIES_NINETALES,
    .heldItem = ITEM_WHITE_HERB,
    .evs = {252, 0, 0, 0, 252, 0},
    .moves = {MOVE_OVERHEAT, MOVE_WILL_O_WISP, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY}
    },
    {
    .iv = 255,
    .lvl = 69,
    .species = SPECIES_MEDICHAM,
    .heldItem = ITEM_CHOICE_BAND,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_HI_JUMP_KICK, MOVE_MEGA_KICK, MOVE_REVERSAL, MOVE_ROCK_SLIDE}
    },
    {
    .iv = 255,
    .lvl = 70,
    .species = SPECIES_GENGAR,
    .heldItem = ITEM_SPELL_TAG,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_EXPLOSION, MOVE_FIRE_PUNCH}
    },
    {
    .iv = 255,
    .lvl = 70,
    .species = SPECIES_DUSCLOPS,
    .heldItem = ITEM_LEFTOVERS,
    .evs = {252, 0, 0, 0, 0, 252},
    .moves = {MOVE_SHADOW_BALL, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_PAIN_SPLIT}
    }
};
// Elite Four Glacia Rematch
static const struct TrainerMon sParty_Glacia2[] = {
    {
    .iv = 255,
    .lvl = 72,
    .species = SPECIES_LAPRAS,
    .heldItem = ITEM_LEFTOVERS,
    .evs = {252, 0, 0, 0, 252, 0},
    .moves = {MOVE_SURF, MOVE_BLIZZARD, MOVE_THUNDERBOLT, MOVE_HAIL}
    },
    {
    .iv = 255,
    .lvl = 72,
    .species = SPECIES_PILOSWINE,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {0, 252, 0, 0, 252, 0},
    .moves = {MOVE_EARTHQUAKE, MOVE_BLIZZARD, MOVE_ROCK_SLIDE, MOVE_HAIL}
    },
    {
    .iv = 255,
    .lvl = 71,
    .species = SPECIES_GLALIE,
    .heldItem = ITEM_NEVER_MELT_ICE,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_BLIZZARD, MOVE_WATER_PULSE, MOVE_SHADOW_BALL, MOVE_EXPLOSION}
    },
    {
    .iv = 255,
    .lvl = 72,
    .species = SPECIES_JYNX,
    .heldItem = ITEM_LUM_BERRY,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_PSYCHIC, MOVE_BLIZZARD, MOVE_LOVELY_KISS, MOVE_CALM_MIND}
    },
    {
    .iv = 255,
    .lvl = 71,
    .species = SPECIES_CASTFORM,
    .heldItem = ITEM_MYSTIC_WATER,
    .evs = {0, 0, 0, 0, 252, 252},
    .moves = {MOVE_BLIZZARD, MOVE_WATER_PULSE, MOVE_HAIL, MOVE_THUNDERBOLT}
    },
    {
    .iv = 255,
    .lvl = 72,
    .species = SPECIES_WALREIN,
    .heldItem = ITEM_SALAC_BERRY,
    .evs = {252, 0, 0, 0, 0, 252},
    .moves = {MOVE_REST, MOVE_BLIZZARD, MOVE_SLEEP_TALK, MOVE_SHEER_COLD}
    }
};
// Elite Four Drake Rematch
static const struct TrainerMon sParty_Drake2[] = {
    {
    .iv = 255,
    .lvl = 72,
    .species = SPECIES_FERALIGATR,
    .heldItem = ITEM_QUICK_CLAW,
    .evs = {252, 252, 0, 0, 0, 0},
    .moves = {MOVE_EARTHQUAKE, MOVE_SWORDS_DANCE, MOVE_ROCK_SLIDE, MOVE_CRUNCH}
    },
    {
    .iv = 255,
    .lvl = 73,
    .species = SPECIES_DRAGONITE,
    .heldItem = ITEM_BLACK_BELT,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_THUNDERBOLT, MOVE_DYNAMIC_PUNCH, MOVE_FLAMETHROWER, MOVE_EARTHQUAKE}
    },
    {
    .iv = 255,
    .lvl = 72,
    .species = SPECIES_CHARIZARD,
    .heldItem = ITEM_SALAC_BERRY,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_FIRE_BLAST, MOVE_BELLY_DRUM, MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = 255,
    .lvl = 72,
    .species = SPECIES_SCEPTILE,
    .heldItem = ITEM_PETAYA_BERRY,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_LEAF_BLADE, MOVE_DRAGON_CLAW, MOVE_THUNDER_PUNCH, MOVE_ENDURE}
    },
    {
    .iv = 255,
    .lvl = 73,
    .species = SPECIES_KINGDRA,
    .heldItem = ITEM_CHESTO_BERRY,
    .evs = {252, 0, 0, 0, 252, 0},
    .moves = {MOVE_OCTAZOOKA, MOVE_REST, MOVE_DRAGON_DANCE, MOVE_DOUBLE_EDGE}
    },
    {
    .iv = 255,
    .lvl = 75,
    .species = SPECIES_SALAMENCE,
    .heldItem = ITEM_LUM_BERRY,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_IRON_TAIL, MOVE_DRAGON_DANCE, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE}
    }
};

// Smith
static const struct TrainerMon sParty_Smith[] = {
    {
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_KYOGRE,
    .heldItem = ITEM_LEFTOVERS,
    .ability = ABILITY_SLOT_1,
    .evs = {252, 0, 0, 0, 252, 0},
    .moves = {MOVE_SURF, MOVE_BLIZZARD, MOVE_EARTHQUAKE, MOVE_CALM_MIND}
    },
    {
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_ZAPDOS,
    .heldItem = ITEM_MAGNET,
    .ability = ABILITY_SLOT_1,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_THUNDER, MOVE_SKY_ATTACK, MOVE_THUNDER_WAVE, MOVE_PROTECT}
    },
    {
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_STARMIE,
    .heldItem = ITEM_SALAC_BERRY,
    .ability = ABILITY_SLOT_1,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_THUNDER, MOVE_RECOVER}
    },
    {
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_RAIKOU,
    .heldItem = ITEM_MAGNET,
    .ability = ABILITY_SLOT_1,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_CALM_MIND, MOVE_SUBSTITUTE}
    },
    {
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_SUICUNE,
    .heldItem = ITEM_CHESTO_BERRY,
    .ability = ABILITY_SLOT_1,
    .evs = {252, 0, 0, 252, 0, 0},
    .moves = {MOVE_SURF, MOVE_CALM_MIND, MOVE_REST, MOVE_ICE_BEAM}
    },
    {
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_GENGAR,
    .heldItem = ITEM_SPELL_TAG,
    .ability = ABILITY_SLOT_1,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_SHADOW_BALL, MOVE_ICE_PUNCH, MOVE_THUNDER, MOVE_GIGA_DRAIN}
    }
};

// Craig / cRz Shadows
static const struct TrainerMon sParty_Craig[] = {
    {
    .nickname = _("MEGANIUM"),
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_MEGANIUM,
    .heldItem = ITEM_AGUAV_BERRY,
    .ability = ABILITY_SLOT_1,
    .evs = {252, 0, 132, 0, 72, 52},
    .moves = {MOVE_GRASS_WHISTLE, MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_REFLECT}
    },
    {
    .nickname = _("AERODACTYL"),
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_AERODACTYL,
    .heldItem = ITEM_CHOICE_BAND,
    .ability = ABILITY_SLOT_1,
    .evs = {76, 252, 0, 180, 0, 0},
    .moves = {MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_AERIAL_ACE}
    },
    {
    .nickname = _("MILOTIC"),
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_MILOTIC,
    .heldItem = ITEM_LEFTOVERS,
    .ability = ABILITY_SLOT_1,
    .evs = {252, 0, 252, 0, 4, 0},
    .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_HYPNOSIS}
    },
    {
    .nickname = _("RAYQUAZA"),
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_RAYQUAZA,
    .heldItem = ITEM_LUM_BERRY,
    .ability = ABILITY_SLOT_1,
    .evs = {40, 0, 0, 216, 252, 0},
    .moves = {MOVE_CRUNCH, MOVE_DRAGON_CLAW, MOVE_THUNDERBOLT, MOVE_BRICK_BREAK}
    },
    {
    .nickname = _("JOLTEON"),
    .ivs = BEST_IV_SPREAD_HIDDEN_POWER_ICE,
    .lvl = 70,
    .species = SPECIES_JOLTEON,
    .heldItem = ITEM_MAGNET,
    .ability = ABILITY_SLOT_1,
    .evs = {76, 0, 0, 252, 180, 0},
    .moves = {MOVE_THUNDERBOLT, MOVE_HELPING_HAND, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER}
    },
    {
    .nickname = _("FURBALL"),
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_ARCANINE,
    .heldItem = ITEM_WHITE_HERB,
    .ability = ABILITY_SLOT_1,
    .evs = {252, 0, 12, 152, 32, 60},
    .moves = {MOVE_OVERHEAT, MOVE_HELPING_HAND, MOVE_EXTREME_SPEED, MOVE_PROTECT}
    }
};

// Weebra
static const struct TrainerMon sParty_Weebra[] = {
    {
    .nickname = _("JIRACHI"),
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_JIRACHI,
    .heldItem = ITEM_LUM_BERRY,
    .ability = ABILITY_SLOT_1,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_RAIN_DANCE, MOVE_THUNDER, MOVE_SECRET_POWER, MOVE_ICE_PUNCH}
    },
    {
    .nickname = _("LUDICOLO"),
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_LUDICOLO,
    .heldItem = ITEM_LEFTOVERS,
    .ability = ABILITY_SLOT_1,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_FAKE_OUT, MOVE_TEETER_DANCE, MOVE_SURF, MOVE_GIGA_DRAIN}
    },
    {
    .nickname = _("GENGAR"),
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_GENGAR,
    .heldItem = ITEM_BRIGHT_POWDER,
    .ability = ABILITY_SLOT_1,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_THUNDER, MOVE_SHADOW_BALL, MOVE_ICE_PUNCH, MOVE_MEAN_LOOK}
    },
    {
    .nickname = _("METAGROSS"),
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_METAGROSS,
    .heldItem = ITEM_SCOPE_LENS,
    .ability = ABILITY_SLOT_1,
    .evs = {0, 252, 0, 252, 0, 0},
    .moves = {MOVE_EXPLOSION, MOVE_BRICK_BREAK, MOVE_METEOR_MASH, MOVE_EARTHQUAKE}
    },
    {
    .nickname = _("LATIOS"),
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_LATIOS,
    .heldItem = ITEM_SOUL_DEW,
    .ability = ABILITY_SLOT_1,
    .evs = {0, 0, 0, 252, 252, 0},
    .moves = {MOVE_PSYCHIC, MOVE_THUNDER, MOVE_REFLECT, MOVE_DRAGON_CLAW}
    },
    {
    .nickname = _("CINDERELLA"),
    .ivs = BEST_IV_SPREAD,
    .lvl = 70,
    .species = SPECIES_HITMONTOP,
    .heldItem = ITEM_KINGS_ROCK,
    .ability = ABILITY_SLOT_1,
    .evs = {252, 0, 0, 252, 0, 0},
    .moves = {MOVE_FAKE_OUT, MOVE_TRIPLE_KICK, MOVE_BULK_UP, MOVE_ROCK_SLIDE}
    }
};

// Battle Frontier HP EV trainer
static const struct TrainerMon sParty_Eva[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_CLEFAIRY,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_CLEFAIRY,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_CLEFAIRY,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_CLEFAIRY,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_CLEFAIRY,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_VAPOREON,
    }
};

// Battle Frontier Attack EV trainer
static const struct TrainerMon sParty_Evin[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_NUZLEAF,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_NUZLEAF,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_NUZLEAF,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_NUZLEAF,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_NUZLEAF,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_FLAREON,
    }
};

// Battle Frontier Defense EV trainer
static const struct TrainerMon sParty_Eve[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_SILCOON,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_CASCOON,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_SILCOON,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_CASCOON,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_SILCOON,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_EEVEE,
    }
};

// Battle Frontier Speed EV trainer
static const struct TrainerMon sParty_Evangelos[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_PIKACHU,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_PIKACHU,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_PIKACHU,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_PIKACHU,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_PIKACHU,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_JOLTEON,
    }
};

// Battle Frontier Sp Attack EV trainer
static const struct TrainerMon sParty_Evvi[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_FLAAFFY,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_FLAAFFY,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_FLAAFFY,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_FLAAFFY,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_FLAAFFY,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_ESPEON,
    }
};

// Battle Frontier Sp Defense EV trainer
static const struct TrainerMon sParty_Evern[] = {
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_TOGETIC,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_TOGETIC,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_TOGETIC,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_TOGETIC,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_TOGETIC,
    },
    {
    .iv = 0,
    .lvl = 5,
    .species = SPECIES_UMBREON,
    }
};
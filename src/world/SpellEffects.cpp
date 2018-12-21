/*
* ArcEmu MMORPG Server
* Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
* Copyright (C) 2008-2011 <http://www.ArcEmu.org/>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "StdAfx.h"

pSpellEffect SpellEffectsHandler[TOTAL_SPELL_EFFECTS] =
{
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_NULL - 0
	&Spell::SpellEffectInstantKill,				//SPELL_EFFECT_INSTAKILL - 1
	&Spell::SpellEffectSchoolDMG,				//SPELL_EFFECT_SCHOOL_DAMAGE - 2
	&Spell::SpellEffectDummy,					//SPELL_EFFECT_DUMMY - 3
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_PORTAL_TELEPORT - 4
	&Spell::SpellEffectTeleportUnits,			//SPELL_EFFECT_TELEPORT_UNITS - 5
	&Spell::SpellEffectApplyAura,				//SPELL_EFFECT_APPLY_AURA - 6
	&Spell::SpellEffectEnvironmentalDamage,		//SPELL_EFFECT_ENVIRONMENTAL_DAMAGE - 7
	&Spell::SpellEffectPowerDrain,				//SPELL_EFFECT_POWER_DRAIN - 8
	&Spell::SpellEffectHealthLeech,				//SPELL_EFFECT_HEALTH_LEECH - 9
	&Spell::SpellEffectHeal,					//SPELL_EFFECT_HEAL - 10
	&Spell::SpellEffectBind,					//SPELL_EFFECT_BIND - 11
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_PORTAL - 12
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_RITUAL_BASE - 13
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_RITUAL_SPECIALIZE - 14
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL - 15
	&Spell::SpellEffectQuestComplete,			//SPELL_EFFECT_QUEST_COMPLETE - 16
	&Spell::SpellEffectWeapondamageNoschool,	//SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL - 17
	&Spell::SpellEffectResurrect,				//SPELL_EFFECT_RESURRECT - 18
	&Spell::SpellEffectAddExtraAttacks,			//SPELL_EFFECT_ADD_EXTRA_ATTACKS - 19
	&Spell::SpellEffectDodge,					//SPELL_EFFECT_DODGE - 20
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_EVADE - 21
	&Spell::SpellEffectParry,					//SPELL_EFFECT_PARRY - 22
	&Spell::SpellEffectBlock,					//SPELL_EFFECT_BLOCK - 23
	&Spell::SpellEffectCreateItem,				//SPELL_EFFECT_CREATE_ITEM - 24
	&Spell::SpellEffectWeapon,					//SPELL_EFFECT_WEAPON - 25
	&Spell::SpellEffectDefense,					//SPELL_EFFECT_DEFENSE - 26
	&Spell::SpellEffectPersistentAA,			//SPELL_EFFECT_PERSISTENT_AREA_AURA - 27
	&Spell::SpellEffectSummon,					//SPELL_EFFECT_SUMMON - 28
	&Spell::SpellEffectLeap,					//SPELL_EFFECT_LEAP - 29
	&Spell::SpellEffectEnergize,				//SPELL_EFFECT_ENERGIZE - 30
	&Spell::SpellEffectWeaponDmgPerc,			//SPELL_EFFECT_WEAPON_PERCENT_DAMAGE - 31
	&Spell::SpellEffectTriggerMissile,			//SPELL_EFFECT_TRIGGER_MISSILE - 32
	&Spell::SpellEffectOpenLock,				//SPELL_EFFECT_OPEN_LOCK - 33
	&Spell::SpellEffectTransformItem,			//SPELL_EFFECT_TRANSFORM_ITEM - 34
	&Spell::SpellEffectApplyGroupAA,			//SPELL_EFFECT_APPLY_GROUP_AREA_AURA - 35
	&Spell::SpellEffectLearnSpell,				//SPELL_EFFECT_LEARN_SPELL - 36
	&Spell::SpellEffectSpellDefense,			//SPELL_EFFECT_SPELL_DEFENSE - 37
	&Spell::SpellEffectDispel,					//SPELL_EFFECT_DISPEL - 38
	&Spell::SpellEffectNULL,                    //SPELL_EFFECT_LANGUAGE - 39
	&Spell::SpellEffectDualWield,				//SPELL_EFFECT_DUAL_WIELD - 40
	&Spell::SpellEffectSummonWield,				//SPELL_EFFECT_JUMP_TARGET - 41SpellEffectJumpTarget
	&Spell::SummonGuardian,		//SPELL_EFFECT_JUMP_BEHIND_TARGET - 42
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER - 43
	&Spell::SpellEffectSkillStep,				//SPELL_EFFECT_SKILL_STEP - 44
	&Spell::SpellEffectAddHonor,				//SPELL_ADD_HONOR - 45
	&Spell::SpellEffectSpawn,					//SPELL_EFFECT_SPAWN - 46
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_TRADE_SKILL - 47
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_STEALTH - 48
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_DETECT - 49
	&Spell::SpellEffectSummonObject,			//SPELL_EFFECT_SUMMON_OBJECT - 50
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_FORCE_CRITICAL_HIT - 51 NA
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_GUARANTEE_HIT - 52 NA
	&Spell::SpellEffectEnchantItem,				//SPELL_EFFECT_ENCHANT_ITEM - 53
	&Spell::SpellEffectEnchantItemTemporary,	//SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY - 54
	&Spell::SpellEffectTameCreature,			//SPELL_EFFECT_TAMECREATURE - 55
	&Spell::SpellEffectSummonPet,				//SPELL_EFFECT_SUMMON_PET	- 56
	&Spell::SpellEffectLearnPetSpell,			//SPELL_EFFECT_LEARN_PET_SPELL - 57
	&Spell::SpellEffectWeapondamage,			//SPELL_EFFECT_WEAPON_DAMAGE - 58
	&Spell::SpellEffectOpenLockItem,			//SPELL_EFFECT_OPEN_LOCK_ITEM - 59
	&Spell::SpellEffectProficiency,				//SPELL_EFFECT_PROFICIENCY - 60
	&Spell::SpellEffectSendEvent,				//SPELL_EFFECT_SEND_EVENT - 61
	&Spell::SpellEffectPowerBurn,				//SPELL_EFFECT_POWER_BURN - 62
	&Spell::SpellEffectThreat,					//SPELL_EFFECT_THREAT - 63
	&Spell::SpellEffectTriggerSpell,			//SPELL_EFFECT_TRIGGER_SPELL - 64
	&Spell::SpellEffectApplyRaidAA,				//SPELL_EFFECT_APPLY_RAID_AREA_AURA - 65
	&Spell::SpellEffectPowerFunnel,				//SPELL_EFFECT_POWER_FUNNEL - 66
	&Spell::SpellEffectHealMaxHealth,			//SPELL_EFFECT_HEAL_MAX_HEALTH - 67
	&Spell::SpellEffectInterruptCast,			//SPELL_EFFECT_INTERRUPT_CAST - 68
	&Spell::SpellEffectDistract,				//SPELL_EFFECT_DISTRACT - 69
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_PULL - 70
	&Spell::SpellEffectPickpocket,				//SPELL_EFFECT_PICKPOCKET - 71
	&Spell::SpellEffectAddFarsight,				//SPELL_EFFECT_ADD_FARSIGHT - 72
	&Spell::SummonPossessed,					//SPELL_EFFECT_UNTRAIN_TALENTS? - 73
	&Spell::SpellEffectUseGlyph,				//SPELL_EFFECT_USE_GLYPH - 74
	&Spell::SpellEffectHealMechanical,			//SPELL_EFFECT_HEAL_MECHANICAL - 75
	&Spell::SpellEffectSummonObjectWild,		//SPELL_EFFECT_SUMMON_OBJECT_WILD - 76
	&Spell::SpellEffectScriptEffect,			//SPELL_EFFECT_SCRIPT_EFFECT - 77
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_ATTACK - 78
	&Spell::SpellEffectSanctuary,				//SPELL_EFFECT_SANCTUARY - 79
	&Spell::SpellEffectAddComboPoints,			//SPELL_EFFECT_ADD_COMBO_POINTS - 80
	&Spell::SpellEffectCreateHouse,				//SPELL_EFFECT_CREATE_HOUSE - 81
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_BIND_SIGHT - 82
	&Spell::SpellEffectDuel,					//SPELL_EFFECT_DUEL - 83
	&Spell::SpellEffectStuck,					//SPELL_EFFECT_STUCK - 84
	&Spell::SpellEffectSummonPlayer,			//SPELL_EFFECT_SUMMON_PLAYER - 85
	&Spell::SpellEffectActivateObject,			//SPELL_EFFECT_ACTIVATE_OBJECT - 86
	&Spell::SpellEffectBuildingDamage,				//SPELL_EFFECT_BUILDING_DAMAGE - 87
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_BUILDING_REPAIR - 88
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_BUILDING_SWITCH_STATE - 89
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_KILL_CREDIT_90 - 90
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_THREAT_ALL - 91 UNUSED
	&Spell::SpellEffectEnchantHeldItem,			//SPELL_EFFECT_ENCHANT_HELD_ITEM - 92
	&Spell::SpellEffectSetMirrorName,			//SPELL_EFFECT_SUMMON_PHANTASM - 93 OLD
	&Spell::SpellEffectSelfResurrect,			//SPELL_EFFECT_SELF_RESURRECT - 94
	&Spell::SpellEffectSkinning,				//SPELL_EFFECT_SKINNING - 95
	&Spell::SpellEffectCharge,					//SPELL_EFFECT_CHARGE - 96
	&Spell::SpellEffectSummonCritter,					//SPELL_EFFECT_SUMMON_MULTIPLE_TOTEMS - 97
	&Spell::SpellEffectKnockBack,				//SPELL_EFFECT_KNOCK_BACK - 98
	&Spell::SpellEffectDisenchant,				//SPELL_EFFECT_DISENCHANT - 99
	&Spell::SpellEffectInebriate,				//SPELL_EFFECT_INEBRIATE - 100
	&Spell::SpellEffectFeedPet,					//SPELL_EFFECT_FEED_PET - 101
	&Spell::SpellEffectDismissPet,				//SPELL_EFFECT_DISMISS_PET - 102
	&Spell::SpellEffectReputation,				//SPELL_EFFECT_REPUTATION - 103
	&Spell::SpellEffectSummonObjectSlot,		//SPELL_EFFECT_SUMMON_OBJECT_SLOT1 - 104
	&Spell::SpellEffectSummonObjectSlot,		//SPELL_EFFECT_SUMMON_OBJECT_SLOT2 - 105
	&Spell::SpellEffectSummonObjectSlot,		//SPELL_EFFECT_SUMMON_OBJECT_SLOT3 - 106
	&Spell::SpellEffectSummonObjectSlot,		//SPELL_EFFECT_SUMMON_OBJECT_SLOT4 - 107
	&Spell::SpellEffectDispelMechanic,			//SPELL_EFFECT_DISPEL_MECHANIC - 108
	&Spell::SpellEffectSummonDeadPet,			//SPELL_EFFECT_SUMMON_DEAD_PET - 109
	&Spell::SpellEffectDestroyAllTotems,		//SPELL_EFFECT_DESTROY_ALL_TOTEMS - 110
	&Spell::SpellEffectDurabilityDamage,        //SPELL_EFFECT_DURABILITY_DAMAGE - 111
	&Spell::SpellEffectSummonDemon,					//not in 3.3.5a client - 112
	&Spell::SpellEffectResurrectNew,			//SPELL_EFFECT_RESURRECT_NEW - 113
	&Spell::SpellEffectAttackMe,				//SPELL_EFFECT_ATTACK_ME - 114
	&Spell::SpellEffectDurabilityDamagePCT,     //SPELL_EFFECT_DURABILITY_DAMAGE_PCT - 115
	&Spell::SpellEffectSkinPlayerCorpse,		//SPELL_EFFECT_SKIN_PLAYER_CORPSE - 116
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_SPIRIT_HEAL - 117//Not used
	&Spell::SpellEffectSkill,					//SPELL_EFFECT_SKILL - 118
	&Spell::SpellEffectApplyPetAA,				//SPELL_EFFECT_APPLY_PET_AURA - 119
	&Spell::SpellEffectNULL,					//SPELL_EFFECT_TELEPORT_GRAVEYARD - 120//Not used
	&Spell::SpellEffectDummyMelee,				//SPELL_EFFECT_DUMMYMELEE	- 121
	&Spell::SpellEffectNULL,					// unknown - 122 //not used
	&Spell::SpellEffectStartTaxi,				//SPELL_EFFECT_START_TAXI - 123 // http://www.wowhead.com/?spell=54575
	&Spell::SpellEffectPlayerPull,				//SPELL_EFFECT_PLAYER_PULL - 124 - http://thottbot.com/e2312
	&Spell::SpellEffectReduceThreatPercent,     //SPELL_EFFECT_REDUCE_THREAT_PERCENT - 125 // Reduce Threat by % //http://www.thottbot.com/?sp=32835
	&Spell::SpellEffectSpellSteal,				//SPELL_EFFECT_SPELL_STEAL - 126 // Steal Beneficial Buff (Magic) //http://www.thottbot.com/?sp=30449
	&Spell::SpellEffectProspecting,				// unknown - 127 // Search 5 ore of a base metal for precious gems.  This will destroy the ore in the process.
	&Spell::SpellEffectApplyFriendAA,			// Apply Aura friendly
	&Spell::SpellEffectApplyEnemyAA,			// Apply Aura enemy
	&Spell::SpellEffectRedirectThreat,			// unknown - 130 // http://www.thottbot.com/s34477
	&Spell::SpellEffectNULL,					// unknown - 131 // test spell
	&Spell::SpellEffectPlayMusic,				// Play Music - 132 // http://www.thottbot.com/s46852
	&Spell::SpellEffectForgetSpecialization,	//SPELL_EFFECT_FORGET_SPECIALIZATION - 133 // http://www.thottbot.com/s36441 // I think this is a gm/npc spell
	&Spell::SpellEffectKillCredit,				// Quest Credit (Player only, not party) - 134 // related to summoning objects and removing them, http://www.thottbot.com/s39161
	&Spell::SpellEffectNULL,					// Summon Pet: http://www.thottbot.com/s23498 - 135
	&Spell::SpellEffectRestoreHealthPct,		// Restore Health % - 136 // http://www.thottbot.com/s41542 and http://www.thottbot.com/s39703
	&Spell::SpellEffectRestorePowerPct,			// Restore Power % - 137 // http://www.thottbot.com/s41542
	&Spell::SpellEffectKnockBack2,				// knockback2 - 138 // related to superjump or even "*jump" spells http://www.thottbot.com/?e=Unknown%20138
	&Spell::SpellEffectClearQuest,				// Remove Quest - 139
	&Spell::SpellEffectTriggerSpell,			// triggers a spell from target back to caster - used at Malacrass f.e.
	&Spell::SpellEffectNULL,					// unknown - 141 // triggers spell, magic one,  (Mother spell) http://www.thottbot.com/s41065
	&Spell::SpellEffectTriggerSpellWithValue,	//SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE - 142 // triggers some kind of "Put spell on target" thing... (dono for sure) http://www.thottbot.com/s40872 and http://www.thottbot.com/s33076
	&Spell::SpellEffectApplyOwnerAA,			// Apply Aura on summon owner - 143 // Master -> demon effecting spell, http://www.thottbot.com/s25228 and http://www.thottbot.com/s35696
	&Spell::SpellEffectNULL,					// unknown - 144
	&Spell::SpellEffectNULL,					// unknown - 145
	&Spell::SpellEffectActivateRunes,			// Activate Rune - 146
	&Spell::SpellEffectNULL,					// Quest Fail - 147
	&Spell::SpellEffectNULL,					// unknown - 148
	&Spell::SpellEffectNULL,					// unknown - 149
	&Spell::SpellEffectNULL,					// unknown - 150
	&Spell::SpellEffectTriggerSpell,			// SPELL_EFFECT_TRIGGER_SPELL_2 - 151
	&Spell::SpellEffectNULL,					// Summon Refer-a-Friend - 152
	&Spell::SpellEffectCreatePet,				// Create tamed pet - 153
	&Spell::SpellEffectTeachTaxiPath,			// "Teach" a taxi path - 154
	&Spell::SpellEffectDualWield2H,				// DualWield2H (ex: Titan's Grip) - 155
	&Spell::SpellEffectEnchantItemPrismatic,	// Add a socket to an armor/a weapon - 156
	&Spell::SpellEffectCreateItem2,				//157 SPELL_EFFECT_CREATE_ITEM_2
	&Spell::SpellEffectMilling,					// Milling - 158
	&Spell::SpellEffectRenamePet,				// Allow Pet Rename - 159
	&Spell::SpellEffectNULL,					// unknown - 160
	&Spell::SpellEffectLearnSpec,				// Learn or unlearn a spec - 161
	&Spell::SpellEffectActivateSpec,			// Activate a spec - 162
};

const char* SpellEffectNames[TOTAL_SPELL_EFFECTS] =
{
	"NULL",
	"INSTANT_KILL",              //    1
	"SCHOOL_DAMAGE",             //    2
	"DUMMY",                     //    3
	"PORTAL_TELEPORT",           //    4
	"TELEPORT_UNITS",            //    5
	"APPLY_AURA",                //    6
	"ENVIRONMENTAL_DAMAGE",      //    7
	"POWER_DRAIN",               //    8
	"HEALTH_LEECH",              //    9
	"HEAL",                      //    10
	"BIND",                      //    11
	"PORTAL",                    //    12
	"RITUAL_BASE",               //    13
	"RITUAL_SPECIALIZE",         //    14
	"RITUAL_ACTIVATE_PORTAL",    //    15
	"QUEST_COMPLETE",            //    16
	"WEAPON_DAMAGE_NOSCHOOL",    //    17
	"RESURRECT",                 //    18
	"ADD_EXTRA_ATTACKS",         //    19
	"DODGE",                     //    20
	"EVADE",                     //    21
	"PARRY",                     //    22
	"BLOCK",                     //    23
	"CREATE_ITEM",               //    24
	"WEAPON",                    //    25
	"DEFENSE",                   //    26
	"PERSISTENT_AREA_AURA_GROUP",//    27
	"SUMMON",                    //    28
	"LEAP",                      //    29
	"ENERGIZE",                  //    30
	"WEAPON_PERCENT_DAMAGE",     //    31
	"TRIGGER_MISSILE",           //    32
	"OPEN_LOCK",                 //    33
	"TRANSFORM_ITEM",            //    34
	"APPLY_GROUP_AREA_AURA",     //    35
	"LEARN_SPELL",               //    36
	"SPELL_DEFENSE",             //    37
	"DISPEL",                    //    38
	"LANGUAGE",                  //    39
	"DUAL_WIELD",                //    40
	"LEAP_41",                   //    41
	"JUMP_BEHIND_TARGET",        //    42
	"TELEPORT_UNITS_FACE_CASTER",//    43
	"SKILL_STEP",                //    44
	"UNDEFINED_45",              //    45
	"SPAWN",                     //    46
	"TRADE_SKILL",               //    47
	"STEALTH",                   //    48
	"DETECT",                    //    49
	"SUMMON_OBJECT",             //    50
	"FORCE_CRITICAL_HIT",        //    51
	"GUARANTEE_HIT",             //    52
	"ENCHANT_ITEM",              //    53
	"ENCHANT_ITEM_TEMPORARY",    //    54
	"TAMECREATURE",              //    55
	"SUMMON_PET",                //    56
	"LEARN_PET_SPELL",           //    57
	"WEAPON_DAMAGE",             //    58
	"OPEN_LOCK_ITEM",            //    59
	"PROFICIENCY",               //    60
	"SEND_EVENT",                //    61
	"POWER_BURN",                //    62
	"THREAT",                    //    63
	"TRIGGER_SPELL",             //    64
	"APPLY_RAID_AREA_AURA",      //    65
	"POWER_FUNNEL",              //    66
	"HEAL_MAX_HEALTH",           //    67
	"INTERRUPT_CAST",            //    68
	"DISTRACT",                  //    69
	"PULL",                      //    70
	"PICKPOCKET",                //    71
	"ADD_FARSIGHT",              //    72
	"UNTRAIN_TALENTS",           //    73
	"USE_GLYPH",                 //    74
	"HEAL_MECHANICAL",           //    75
	"SUMMON_OBJECT_WILD",        //    76
	"SCRIPT_EFFECT",             //    77
	"ATTACK",                    //    78
	"SANCTUARY",                 //    79
	"ADD_COMBO_POINTS",          //    80
	"CREATE_HOUSE",              //    81
	"BIND_SIGHT",                //    82
	"DUEL",                      //    83
	"STUCK",                     //    84
	"SUMMON_PLAYER",             //    85
	"ACTIVATE_OBJECT",           //    86
	"BUILDING_DAMAGE",           //    87
	"BUILDING_REPAIR",           //    88
	"BUILDING_SWITCH_STATE",     //    89
	"KILL_CREDIT_90",               //    90
	"THREAT_ALL",                //    91
	"ENCHANT_HELD_ITEM",         //    92
	"SET_MIRROR_NAME",           //    93
	"SELF_RESURRECT",            //    94
	"SKINNING",                  //    95
	"CHARGE",                    //    96
	"SUMMON_MULTIPLE_TOTEMS",    //    97
	"KNOCK_BACK",                //    98
	"DISENCHANT",                //    99
	"INEBRIATE",                 //    100
	"FEED_PET",                  //    101
	"DISMISS_PET",               //    102
	"REPUTATION",                //    103
	"SUMMON_OBJECT_SLOT1",       //    104
	"SUMMON_OBJECT_SLOT2",       //    105
	"SUMMON_OBJECT_SLOT3",       //    106
	"SUMMON_OBJECT_SLOT4",       //    107
	"DISPEL_MECHANIC",           //    108
	"SUMMON_DEAD_PET",           //    109
	"DESTROY_ALL_TOTEMS",        //    110
	"DURABILITY_DAMAGE",         //    111
	"NONE",                      //    112
	"RESURRECT_FLAT",            //    113
	"ATTACK_ME",                 //    114
	"DURABILITY_DAMAGE_PCT",     //    115
	"SKIN_PLAYER_CORPSE",        //    116
	"SPIRIT_HEAL",               //    117
	"SKILL",                     //    118
	"APPLY_PET_AREA_AURA",       //    119
	"TELEPORT_GRAVEYARD",        //    120
	"DUMMYMELEE",                //    121
	"UNKNOWN1",                  //    122
	"START_TAXI",                //    123
	"PLAYER_PULL",               //    124
	"UNKNOWN4",                  //    125
	"UNKNOWN5",                  //    126
	"PROSPECTING",               //    127
	"APPLY_FRIEND_AREA_AURA",    //    128
	"APPLY_RAID_AREA_AURA",      //    129
	"UNKNOWN10",                 //    130
	"UNKNOWN11",                 //    131
	"PLAY_MUSIC",                //    132
	"FORGET_SPECIALIZATION",     //    133
	"KILL_CREDIT",               //    134
	"UNKNOWN15",                 //    135
	"UNKNOWN16",                 //    136
	"RESTORE_POWER_PCT",         //    137
	"KNOCKBACK2",                //    138
	"CLEAR_QUEST",               //    139
	"UNKNOWN20",                 //    140
	"UNKNOWN21",                 //    141
	"TRIGGER_SPELL_WITH_VALUE",  //    142
	"APPLY_OWNER_AREA_AURA",     //    143
	"UNKNOWN23",                 //    144
	"UNKNOWN24",                 //    145
	"ACTIVATE_RUNES",            //    146
	"QUEST_FAIL",                //    147
	"UNKNOWN26",                 //    148
	"UNKNOWN27",                 //    149
	"UNKNOWN28",                 //    150
	"SUMMON_TARGET",             //    151
	"UNKNOWN30",                 //    152
	"TAME_CREATURE",             //    153
	"UNKNOWN32",                 //    154
	"UNKNOWN33",                 //    155
	"UNKNOWN34",                 //    156
	"UNKNOWN35",                 //    157
	"MILLING",                   //    158
	"ALLOW_PET_RENAME",          //    159
	"UNKNOWN36",                 //    160
	"UNKNOWN37"                  //    161 //used by spell 63624(dual talents)
};

void Spell::ApplyAA(uint32 i) // Apply Area Aura
{
	if(!unitTarget || !unitTarget->isAlive()) return;
	if(u_caster != unitTarget) return;

	Aura * pAura;
	std::map<uint32,Aura*>::iterator itr=unitTarget->tmpAura.find(GetProto()->Id);
	if(itr==unitTarget->tmpAura.end())
	{
		pAura = sSpellFactoryMgr.NewAura(GetProto(), GetDuration(), m_caster, unitTarget);

		float r = GetRadius(i);

		uint32 eventtype = 0;

		switch(m_spellInfo->Effect[ i ])
		{
			case SPELL_EFFECT_APPLY_GROUP_AREA_AURA:
				eventtype = EVENT_GROUP_AREA_AURA_UPDATE;
				break;
			case SPELL_EFFECT_APPLY_RAID_AREA_AURA:
				eventtype = EVENT_RAID_AREA_AURA_UPDATE;
				break;
			case SPELL_EFFECT_APPLY_PET_AREA_AURA:
				eventtype = EVENT_PET_AREA_AURA_UPDATE;
				break;
			case SPELL_EFFECT_APPLY_FRIEND_AREA_AURA:
				eventtype = EVENT_FRIEND_AREA_AURA_UPDATE;
				break;
			case SPELL_EFFECT_APPLY_ENEMY_AREA_AURA:
				eventtype = EVENT_ENEMY_AREA_AURA_UPDATE;
				break;
			case SPELL_EFFECT_APPLY_OWNER_AREA_AURA:
				eventtype = EVENT_ENEMY_AREA_AURA_UPDATE;
				break;
		}

	//	if(!sEventMgr.HasEvent(pAura, eventtype))		/* only add it once */

		unitTarget->tmpAura [GetProto()->Id]= pAura;

	//	float r = GetRadius(i);
		if(!sEventMgr.HasEvent(pAura, eventtype))		/* only add it once */
			sEventMgr.AddEvent(pAura, &Aura::EventUpdateAA, r * r, eventtype, 1000, 0, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);

		AddRef();
		sEventMgr.AddEvent(this, &Spell::HandleAddAura, unitTarget->GetGUID(), EVENT_SPELL_HIT, 100, 1, 0);

	}
	else
	{
		pAura = itr->second;
	}

	pAura->AddMod(GetProto()->EffectApplyAuraName[i],damage,GetProto()->EffectMiscValue[i],i);
}


void Spell::SpellEffectNULL(uint32 i)
{
	LOG_DEBUG("Unhandled spell effect %u in spell %u.", GetProto()->Effect[i], GetProto()->Id);
}

void Spell::SpellEffectInstantKill(uint32 i)
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	//Sacrifice: if spell caster has "void walker" pet, pet dies and spell caster gets a
	/*Sacrifices the Voidwalker, giving its owner a shield that will absorb
	305 damage for 30 sec. While the shield holds, spellcasting will not be \
	interrupted by damage.*/

	/*
	Demonic Sacrifice

	When activated, sacrifices your summoned demon to grant you an effect that lasts
	30 minutes. The effect is canceled if any Demon is summoned.
	Imp: Increases your Fire damage by 15%.
	Voidwalker: Restores 3% of total Health every 4 sec.
	Succubus: Increases your Shadow damage by 15%.
	Felhunter: Restores 2% of total Mana every 4 sec.

	When activated, sacrifices your summoned demon to grant you an effect that lasts $18789d.  The effect is canceled if any Demon is summoned.

	Imp: Increases your Fire damage by $18789s1%.

	Voidwalker: Restores $18790s1% of total Health every $18790t1 sec.

	Succubus: Increases your Shadow damage by $18791s1%.

	Felhunter: Restores $18792s1% of total Mana every $18792t1 sec.

	*/
	uint32 spellId = GetProto()->Id;

	switch(spellId)
	{
		case 48743:
			{
				// retarget? some one test this spell.
				return;
			}
			break;
		case 18788: //Demonic Sacrifice (508745)
			uint32 DemonicSacEffectSpellId = 0;
			switch(unitTarget->GetEntry())
			{
				case 416:
					DemonicSacEffectSpellId = 18789;
					break; //Imp
				case 417:
					DemonicSacEffectSpellId = 18792;
					break; //Felhunter
				case 1860:
					DemonicSacEffectSpellId = 18790;
					break; //VoidWalker
				case 1863:
					DemonicSacEffectSpellId = 18791;
					break; //Succubus
				case 17252:
					DemonicSacEffectSpellId = 35701;
					break; //felguard
			}
			if(DemonicSacEffectSpellId)
			{
				SpellEntry* se = dbcSpell.LookupEntryForced(DemonicSacEffectSpellId);
				if(se && u_caster)
					u_caster->CastSpell(u_caster, se, true);
			}
	}

	switch(GetProto()->NameHash)
	{
		case SPELL_HASH_SACRIFICE:
			{
				if(!u_caster || !u_caster->IsPet())
					return;

				//TO< Pet* >(u_caster)->Dismiss( true );

				SpellEntry* se = dbcSpell.LookupEntry(5);
				if(TO< Pet* >(u_caster)->GetPetOwner() == NULL)
					return;

				SpellCastTargets targets(u_caster->GetGUID());
				Spell* sp = sSpellFactoryMgr.NewSpell(TO< Pet* >(u_caster)->GetPetOwner(), se, true, 0);
				sp->prepare(&targets);
				return;
			}
			break;
		case SPELL_HASH_DEMONIC_SACRIFICE:
			{
				if(!p_caster || !unitTarget || !unitTarget->IsPet())
					return;

				//TO< Pet* >(unitTarget)->Dismiss( true );

				SpellEntry* se = dbcSpell.LookupEntry(5);

				SpellCastTargets targets(unitTarget->GetGUID());
				Spell* sp = sSpellFactoryMgr.NewSpell(p_caster, se, true, 0);
				sp->prepare(&targets);
				return;
			}
			break;

		default:
			{
				// moar cheaters
				if(!p_caster || (u_caster && u_caster->IsPet()))
					return;

				if(p_caster->GetSession()->GetPermissionCount() == 0)
					return;
			}
	}
	//instant kill effects don't have a log
	//m_caster->SpellNonMeleeDamageLog(unitTarget, GetProto()->Id, unitTarget->GetHealth(), true);
	// cebernic: the value of instant kill must be higher than normal health,cuz anti health regenerated.
	m_caster->DealDamage(unitTarget, unitTarget->GetUInt32Value(UNIT_FIELD_HEALTH) << 1, 0, 0, 0);
}

void Spell::SpellEffectSchoolDMG(uint32 i) // dmg school
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	if(unitTarget->SchoolImmunityList[GetProto()->School])
	{
		SendCastResult(SPELL_FAILED_IMMUNE);
		return;
	}

	uint32 dmg = 0;
	bool static_damage = false;
	bool force_crit = false;

	if(GetProto()->EffectChainTarget[i])//chain
	{
		if(GetProto()->Id == 32445 || GetProto()->Id == 28883)
		{
			int32 reduce = (int32)(GetProto()->dmg_multiplier[i] * 100.0f);
			reduce -= 100;

			if(reduce && chaindamage)
			{
				if(GetProto()->SpellGroupType && u_caster)
				{
					SM_FIValue(u_caster->SM_PJumpReduce, &reduce, GetProto()->SpellGroupType);
				}
				chaindamage += ((GetProto()->EffectBasePoints[i] + 51) * reduce / 100);
			}
			else
			{
				chaindamage = damage;
			}
			dmg = chaindamage;
		}
		else
		{
			int32 reduce = (int32)(GetProto()->dmg_multiplier[i] * 100.0f);

			if(reduce && chaindamage)
			{
				if(GetProto()->SpellGroupType && u_caster)
				{
					SM_FIValue(u_caster->SM_PJumpReduce, &reduce, GetProto()->SpellGroupType);
				}
				chaindamage = chaindamage * reduce / 100;
			}
			else
			{
				chaindamage = damage;
			}
			dmg = chaindamage;
		}
	}
	else
	{
		dmg = damage;
		switch(GetProto()->NameHash)
		{
			case SPELL_HASH_METEOR_SLASH:
				{
					uint32 splitCount = 0;
					for(std::set<Object*>::iterator itr = u_caster->GetInRangeOppFactsSetBegin(); itr != u_caster->GetInRangeOppFactsSetEnd(); ++itr)
					{
						if((*itr)->isInFront(u_caster) && u_caster->CalcDistance((*itr)) <= 65)
							splitCount++;
					};

					if(splitCount > 1)
						dmg = dmg / splitCount;
				}
				break;
			case SPELL_HASH_PULSING_SHOCKWAVE: // loken Pulsing shockwave
				{
					float _distance = u_caster->CalcDistance(unitTarget);
					if(_distance >= 2.0f)
						dmg = static_cast<uint32>(dmg * _distance);
				}
				break;
			case SPELL_HASH_ICE_LANCE: // Ice Lance
				{
					if(unitTarget->HasFlag(UNIT_FIELD_AURASTATE, AURASTATE_FLAG_FROZEN))
						dmg *= 3;
					//	if (dmg>300)   //dirty bugfix.
					//		dmg = (int32)(damage >> 1);

				}
				break;
			case SPELL_HASH_INCINERATE:	// Incinerate -> Deals x-x extra damage if the target is affected by immolate
				{
					if(unitTarget->HasFlag(UNIT_FIELD_AURASTATE, AURASTATE_FLAG_IMMOLATE))
					{
						// random extra damage
						uint32 extra_dmg = 111 + (GetProto()->RankNumber * 11) + RandomUInt(GetProto()->RankNumber * 11);
						dmg += extra_dmg;
					}
				}
				break;
			case SPELL_HASH_ARCANE_SHOT: //hunter - arcane shot
				{
					if(u_caster)
						dmg += float2int32(u_caster->GetRAP() * 0.15f);
					dmg = float2int32(dmg * (0.9f + RandomFloat(0.2f)));      // randomized damage
				}
				break;
			case SPELL_HASH_GORE: // boar/ravager: Gore (50% chance of double damage)
				{
					dmg *= Rand(50) ? 2 : 1;
				}
				break;
			case SPELL_HASH_THUNDER_CLAP: // Thunderclap
				{
					if(u_caster)
						dmg = (GetProto()->EffectBasePoints[0] + 1) + float2int32(u_caster->GetAP() * 0.12f);
				}
				break;
			case SPELL_HASH_INTERCEPT: // Warrior - Intercept
				{
					if(u_caster)
						dmg = float2int32(u_caster->GetAP() * 0.12f);
				}
				break;
			case SPELL_HASH_SHOCKWAVE:		// Shockwave
				{
					if(u_caster)
						dmg = u_caster->GetAP() * (GetProto()->EffectBasePoints[2] + 1) / 100;
				}
				break;
			case SPELL_HASH_CONCUSSION_BLOW:
				{
					//3.2.2
					//[Concussion Blow]: The damage done by this ability has been reduced by 50%,
					//but its threat generation will remain approximately the same.
					dmg = u_caster->GetAP() * (GetProto()->EffectBasePoints[2] + 1) / 100;
				}
				break;
			case SPELL_HASH_HEROIC_THROW:   // Heroic Throw
				{
					if(u_caster)
						dmg = u_caster->GetAP() / 2 + 12;
					// hardcoded value are faster I guess
					// GetProto()->EffectBasePoints[0]+1 == 12 future reference
				}
				break;
			case SPELL_HASH_BLOODTHIRST:	// Bloodthirst
				{
					dmg = u_caster->GetAP() * (GetProto()->EffectBasePoints[0] + 1) / 100;
				}
				break;
			case SPELL_HASH_SHIELD_OF_RIGHTEOUSNESS: // Shield of Righteousness - a bit like "shield slam", OK for both ranks
				{
					if(p_caster != NULL)
					{
						dmg += float2int32(1.30f * p_caster->GetUInt32Value(PLAYER_RATING_MODIFIER_BLOCK) + GetProto()->EffectBasePoints[0]);
					}
				}
				break;
			case SPELL_HASH_SHIELD_SLAM:	// Shield Slam - damage is increased by block value
				{
					if(p_caster != NULL)
					{
						Item* it = p_caster->GetItemInterface()->GetInventoryItem(EQUIPMENT_SLOT_OFFHAND);
						if(it && it->GetProto()->InventoryType == INVTYPE_SHIELD)
						{
							float block_multiplier = (100.0f + p_caster->m_modblockabsorbvalue) / 100.0f;
							if(block_multiplier < 1.0f)block_multiplier = 1.0f;

							int32 blockable_damage = float2int32((it->GetProto()->Block + p_caster->m_modblockvaluefromspells + p_caster->GetUInt32Value(PLAYER_RATING_MODIFIER_BLOCK) + ((p_caster->GetStat(STAT_STRENGTH) / 2.0f) - 1.0f)) * block_multiplier);

							/*
								3.2.0:
							    The benefit from additional block value this ability gains is now subject
								to diminishing returns. Diminishing returns occur once block value exceeds
								30 times the player's level and caps the maximum damage benefit from shield
								block value at 34.5 times the player's level.
							*/
							int32 max_blockable_damage = static_cast< int32 >(p_caster->getLevel() * 34.5f);
							if(blockable_damage > max_blockable_damage)
							{
								blockable_damage = max_blockable_damage;
							}

							dmg += blockable_damage;

						}
					}
				}
				break;
			case SPELL_HASH_FIRE_STRIKE:
			case SPELL_HASH_LIGHTNING_STRIKE:
			case SPELL_HASH_MOLTEN_ARMOR:		// fire armor, is static damage
				static_damage = true;
				break;

			case SPELL_HASH_CONFLAGRATE:
				unitTarget->RemoveFlag(UNIT_FIELD_AURASTATE, AURASTATE_FLAG_IMMOLATE);
				break;

			case SPELL_HASH_JUDGEMENT_OF_COMMAND:
				{
					if(!unitTarget->IsStunned())
						dmg = dmg >> 1;
				}
				break;

			case SPELL_HASH_EXORCISM:
				{
					if(p_caster != NULL)
					{
						uint32 sph = p_caster->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + 1);
						int32 ap = p_caster->GetAP();
						dmg += float2int32((0.15f * sph) + (0.15f * ap));
						if(unitTarget && unitTarget->IsCreature())
						{
							uint32 type = TO_CREATURE(unitTarget)->GetCreatureInfo()->Type;
							if(type == UNIT_TYPE_UNDEAD || type == UNIT_TYPE_DEMON)
								force_crit = true;
						}
					}
				}
				break;

			default:
				break;
		}

		switch(GetProto()->Id)
		{
			case 64422: // Sonic Screech, Auriaya encounter
			case 64688:
				{
					int splitCount = 0;
					for(std::set<Object*>::iterator itr = u_caster->GetInRangeOppFactsSetBegin(); itr != u_caster->GetInRangeOppFactsSetEnd(); ++itr)
					{
						if((*itr)->isInFront(u_caster))
							splitCount++;
					};
					if(splitCount > 1)
						dmg /= splitCount;
				}
				break;

			default:
				break;
		};
	}

	if(p_caster && !static_damage)   //this is wrong but with current spell coef system it has to be here...
	{
		switch(p_caster->getClass())
		{
			case WARRIOR:
			case ROGUE:
			case HUNTER:
			case DEATHKNIGHT:
				static_damage = true; //No spells from these classes benefit from spell damage. Prevents Arc hunters, frost DKs, etc.
				break;
			default:
				break;
		}
	}


	// check for no more damage left (chains)
	if(!dmg)
		dmg = GetProto()->EffectBasePoints[i];

	if(!dmg)
		return;

	if(GetProto()->speed > 0 && m_triggeredSpell == false)
	{
		m_caster->SpellNonMeleeDamageLog(unitTarget, GetProto()->Id, dmg, pSpellId == 0);
	}
	else
	{
		if(GetType() == SPELL_DMG_TYPE_MAGIC)
		{
			m_caster->SpellNonMeleeDamageLog(unitTarget, GetProto()->Id, dmg, !m_triggeredSpell, static_damage);
		}
		else
		{
			if(u_caster != NULL)
			{
				uint32 _type;
				if(GetType() == SPELL_DMG_TYPE_RANGED)
					_type = RANGED;
				else
				{
					if(GetProto()->AttributesExC & FLAGS4_TYPE_OFFHAND)
						_type =  OFFHAND;
					else
						_type = MELEE;
				}

				u_caster->Strike(unitTarget, _type, GetProto(), 0, 0, dmg, !m_triggeredSpell, true, force_crit);
			}
		}
	}
}


void Spell::SpellEffectDummy(uint32 i) // Dummy(Scripted events)
{
	uint32 spellId = m_spellInfo->Id;
	
	switch( m_spellInfo->NameHash )
	{
	case SPELL_HASH_STEADY_SHOT:
		{
			if( p_caster != NULL && unitTarget != NULL )
				if ( unitTarget->IsDazed() )
					p_caster->Strike( unitTarget, RANGED, NULL, 0, 0, damage, false, false );
		}break;
	case SPELL_HASH_SLAM:
		{
			if(p_caster != NULL && unitTarget != NULL )
				p_caster->Strike( unitTarget, MELEE, NULL, damage, 0, 0, false, false);
		}break;
	case SPELL_HASH_SAVAGE_ROAR:
		{
			if(p_caster != NULL && unitTarget != NULL )
				p_caster->Strike( unitTarget, MELEE, m_spellInfo, 0, 0, 0, false, false);
		}break;
	case SPELL_HASH_PENANCE:
		{
			if( p_caster != NULL && unitTarget != NULL )
			{
				uint32 hostileSpell[] = {0, 0};
				uint32 friendlySpell[] = {0, 0};
				switch( m_spellInfo->Id )
				{
					case 47540: //Rank 1
						hostileSpell[0] = 47666;
						hostileSpell[1] = 47758;

						friendlySpell[0] = 47750;
						friendlySpell[1] = 47757;
						break;
					case 53005:
						hostileSpell[0] = 52998;
						hostileSpell[1] = 53001;

						friendlySpell[0] = 52983;
						friendlySpell[1] = 52986;
						break;
					case 53006:
						hostileSpell[0] = 52999;
						hostileSpell[1] = 53002;

						friendlySpell[0] = 52984;
						friendlySpell[1] = 52987;
						break;
					case 53007:
						hostileSpell[0] = 53000;
						hostileSpell[1] = 53003;

						friendlySpell[0] = 52985;
						friendlySpell[1] = 52988;
						break;
				}
				if( isAttackable(p_caster, unitTarget) ) // Do holy damage
				{
					// First tick is instant.
					p_caster->CastSpell(unitTarget, hostileSpell[0], true);
					p_caster->CastSpell(unitTarget, hostileSpell[1], false);
				}
				else // Heal
				{ 
					p_caster->CastSpell(unitTarget, friendlySpell[0], true);
					p_caster->CastSpell(unitTarget, friendlySpell[1], false);
				}
			}
		}break;
	case SPELL_HASH_STARFALL:
		{
			if( p_caster != NULL)
			{
				SpellEntry* spellInfo= dbcSpell.LookupEntryForced( damage );
				Spell* sp (new Spell(p_caster, spellInfo, true, NULL));
				SpellCastTargets targets;
				sp->FillAllTargetsInArea(i,m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),GetRadius(i));
				sp->prepare(&targets);
			}
		}break;
	}

	switch(spellId)
	{
	/*****************************************
	 *	Class Spells
	 *****************************************/	
	case 51858:						// Siphon of Acherus - Complete Quest
		{
			if (!m_caster || !static_cast<Unit*>(m_caster)->isAlive())
				return;

		//	((Player*)p_caster->GetUInt64Value(UNIT_FIELD_CHARMEDBY));
			unitTarget->CastSpell(unitTarget, 51859, true);

		}break;

//	case 35844:
//		{
//
//		}break;

	case 49576:
		{
			if( p_caster == NULL || unitTarget == NULL )
				return;

			// Move Effect
			unitTarget->CastSpellAoF( p_caster->GetPositionX(), p_caster->GetPositionY(), p_caster->GetPositionZ(), dbcSpell.LookupEntryForced(49575), true); 
			p_caster->CastSpell( unitTarget, 51399, true ); // Taunt Effect
			p_caster->DealDamage(unitTarget,1,0,0,49576);
		}break;

	/*************************
	 * WARRIOR SPELLS
	 *************************/
	case 60970: // Heroic Fury
		{
			if( p_caster == NULL)
				return;

			if( p_caster->HasSpell( 20252 ) )
					p_caster->ClearCooldownForSpell( 20252 );
		}break;
	case 50227: // Sword and Board
		{
			if( p_caster == NULL)
				return;

			uint32 ClearSpellId[8] =
			{
			23922,  /* Shield Slam - Rank 1 */
			23923,  /* Shield Slam - Rank 2 */
			23924,  /* Shield Slam - Rank 3 */
			23925,  /* Shield Slam - Rank 4 */
			25258,  /* Shield Slam - Rank 5 */
			30356,  /* Shield Slam - Rank 6 */
			47487,  /* Shield Slam - Rank 7 */
			47488,  /* Shield Slam - Rank 8 */
			};

			for(i = 0; i < 8; i++)
			{
				if( p_caster->HasSpell( ClearSpellId[i] ) )
					p_caster->ClearCooldownForSpell( ClearSpellId[i] );
			}
		}break;

	case 5308:
	case 20658:
	case 20660:
	case 20661:
	case 20662:
	case 25234:
	case 25236:
	case 47470:
	case 47471:// Execute
		{
			if( u_caster == NULL|| !u_caster->IsInWorld() || !unitTarget || !unitTarget->IsInWorld() || !m_spellInfo)
				return;

			int32 value = m_spellInfo->EffectBasePoints[i]+1;
			int32 rageUsed = p_caster->GetUInt32Value(UNIT_FIELD_POWER2);

			int32 rageLeft = 10; // We use all available rage by default
			Aura* suddenDeath = NULL;
			suddenDeath = u_caster->FindAura(52437);

			if(suddenDeath != NULL && unitTarget->GetHealthPct() > 20)
			{		
				SpellEntry * sd = NULL;
				sd = dbcSpell.LookupEntry(suddenDeath->pSpellId);
				if(sd!=NULL)

					rageLeft = sd->RankNumber > 1 ? sd->RankNumber * 30 + 10 : sd->RankNumber * 30;
				unitTarget->RemoveAura(suddenDeath); // Sudden Death is removed after 1 execute
				// With Sudden Death can only use up to 30 total rage. so 30-15 = 15 goes to execute damage
				rageLeft = std::max(rageLeft, rageUsed - 150);
				rageUsed = std::min(rageUsed, 150);
			}

			if( u_caster->HasDummyAura(SPELL_HASH_GLYPH_OF_EXECUTION) )
				rageUsed += 100; //Your Execute ability deals damage as if you had 10 additional rage.
			
			value += (int32) (rageUsed * m_spellInfo->dmg_multiplier[0]); 
			u_caster->SetPower(POWER_TYPE_RAGE, rageLeft);
			SpellEntry *spellInfo = dbcSpell.LookupEntry(20647);
			u_caster->Strike(unitTarget,MELEE,spellInfo,0,0,value,false,false);
		}break;
	/*************************
	 * MAGE SPELLS
	 *************************
	 * IDs:
	 *	11189 Frost Warding   -	RANK 1,		STATUS: DONE
	 *  28332 Frost Warding   -	RANK 2,		STATUS: DONE
	 *  --------------------------------------------
	 *************************/
	
	/*
		Frost Warding
		Increases the armor and resistances given by your Frost Armor and Ice Armor spells by X%.  In addition, gives your Frost Ward a X% chance to reflect Frost spells and effects while active.
		
		Effect #1	Apply Aura: Add % Modifier (8)

		Effect #2	Apply Aura: Dummy
		11189, 28332
	*/
	case 11189:
	case 28332:
		{
			if(unitTarget == NULL)
				break;
			for(std::list<struct ReflectSpellSchool*>::iterator i = unitTarget->m_reflectSpellSchool.begin(), i2;i != unitTarget->m_reflectSpellSchool.end();)
				if(m_spellInfo->Id == (*i)->spellId)
				{
					i2 = i++;
					unitTarget->m_reflectSpellSchool.erase(i2);
				}
				else
					++i;

			ReflectSpellSchool *rss = new ReflectSpellSchool;
			rss->chance = m_spellInfo->procChance;
			rss->spellId = m_spellInfo->Id;
			rss->require_aura_hash = 2161224959UL; 
			rss->school = m_spellInfo->School;		

			unitTarget->m_reflectSpellSchool.push_back(rss);
		}break;


	/*************************
	 * ROGUE SPELLS
	 *************************
	 * IDs:
	 * 14185 Preparation		STATUS: DONE
	 *  --------------------------------------------
	 * 35729 Cloak of Shadows	STATUS: DONE
	 *  --------------------------------------------
	 *************************/
		/*
		Hunger For Blood
		Enrages you, increasing all damage caused by 3%.  If used while a Bleed effect is afflicting you, it will attempt to remove it and refund 15 energy.  This effect can be stacked up to 3 times.  Lasts 30 sec.
		*/
	case 51662:
		{
			if( p_caster == NULL)
				return;

			if( p_caster->RemoveAllAurasByMechanic( MECHANIC_BLEEDING , 1 , true ) )
			{
				// Give 15 energy.
				p_caster->Energize(p_caster, 51662, 15, POWER_TYPE_ENERGY);
			}
		}break;

		//Disarm Trap
	case 1842:
		{
			if( p_caster == NULL || gameObjTarget == NULL )
				return;

			if( gameObjTarget->GetTypeId() == TYPEID_GAMEOBJECT )
			{
				if( gameObjTarget->GetByte(GAMEOBJECT_BYTES_1, GAMEOBJECT_BYTES_TYPE_ID) == GAMEOBJECT_TYPE_TRAP )
					gameObjTarget->_Expire();
			}
		}break;
	/*
		Preparation
		When activated, this ability immediately finishes the cooldown on your Evasion, Sprint, Vanish, Cold Blood and Shadowstep abilities.
		
		Effect	Dummy
	*/
	case 14185:
		{
			if( p_caster == NULL )
				return;

			uint32 ClearSpellId[10] =
			{
			5277,  /* Evasion - Rank 1 */
			26669, /* Evasion - Rank 2 */
			2983,  /* Sprint  - Rank 1 */
			8696,  /* Sprint  - Rank 2 */
			11305, /* Sprint  - Rank 3 */
			1856,  /* Vanish  - Rank 1 */
			1857,  /* Vanish  - Rank 2 */
			26889, /* Vanish  - Rank 3 */
			14177, /* Cold Blood       */
			36554  /* Shadowstep       */
			};

			for(i = 0; i < 10; ++i)
			{
				if( p_caster->HasSpell( ClearSpellId[i] ) )
					p_caster->ClearCooldownForSpell( ClearSpellId[i] );
			}
		}break;
	/*
		Cloak of Shadows
		Instantly removes all existing harmful spell effects and increases your chance to resist all spells by 90% for 5 sec.  Does not remove effects that prevent you from using Cloak of Shadows.
		
		Effect #1	Apply Aura: Mod Attacker Spell Hit Chance (126)
			Value: -90
		Effect #2	Trigger Spell
			Spell #35729 <--- THIS SPELL
	*/
	case 35729:
		{
			if( unitTarget == NULL || !unitTarget->isAlive())
				return;

			Aura* pAura = NULL;
			for(uint32 i = MAX_NEGATIVE_VISUAL_AURAS_START; i < MAX_NEGATIVE_VISUAL_AURAS_END; ++i)
			{
				pAura = unitTarget->m_auras[i];
				if( pAura != NULL && !pAura->IsPassive() && !pAura->IsPositive() && !(pAura->GetSpellProto()->Attributes & ATTRIBUTES_IGNORE_INVULNERABILITY) &&
					pAura->GetSpellProto()->School != 0 )
				{
				//	unitTarget->RemoveAuraBySlot(i);
					unitTarget->m_auras[i]->Remove();
					unitTarget->m_auras[i] = NULL;
				}
			}
		}break;
	 case 5938:
		{
			if( p_caster == NULL || unitTarget == NULL || !unitTarget->isAlive())
				return;

			Item* Offhand = p_caster->GetItemInterface()->GetInventoryItem( EQUIPMENT_SLOT_OFFHAND);

			if( Offhand == NULL || Offhand->GetEnchantment( 1 ) == NULL )
				return;

			SpellEntry* spellInfo = dbcSpell.LookupEntry(Offhand->GetEnchantment( 1 )->Enchantment->spell[0]);

			if(spellInfo && spellInfo->c_is_flags & SPELL_FLAG_IS_POISON )
			{
				Spell* spell(new Spell( p_caster, spellInfo, true, NULL));
				SpellCastTargets targets;
				targets.m_unitTarget = unitTarget->GetGUID();
				spell->prepare( &targets );
			}
		}break;
	/*************************
	 * DRUID SPELLS
	 *************************
	 * IDs:
	 * 34297 Improved Leader of the Pack RANK 1		STATUS: DONE
	 * 34300 Improved Leader of the Pack RANK 2		STATUS: DONE
	 *  --------------------------------------------
	 *************************/

	/*
		Improved Leader of the Pack
		Your Leader of the Pack ability also causes affected targets to have a X% chance to heal themselves for X% of their total health when they critically hit with a melee or ranged attack.  The healing effect cannot occur more than once every 6 sec.
		
		Effect #1	Apply Aura: Add Flat Modifier (12)
			Value: X
		Effect #2	Dummy
			Value: 100
	*/
	/*************************
	 * HUNTER SPELLS
	 *************************
	 * IDs:
	 * 35029 Focused Fire RANK 1		STATUS: ToDo
	 * 35030 Focused Fire RANK 2		STATUS: ToDo
	 *  --------------------------------------------
	 *************************/

		//Disengage
		case 781:
		{
			if( p_caster == NULL )
				return;

			WorldPacket data(SMSG_MOVE_KNOCK_BACK, 39);
			data << p_caster->GetNewGUID();
			data << getMSTime();
			float co = p_caster->GetOrientation() < 3.15f ? 6.3f - ( 3.15f - p_caster->GetOrientation()) : p_caster->GetOrientation() - 3.15f;
			data << cosf(co) << sinf(co);
			data << float(15.0f);
			data << float(-9.0f);
			p_caster->GetSession()->SendPacket(&data);
			p_caster->SpeedCheatDelay( 10000 );
		}break;

	/*************************
	 * PALADIN SPELLS
	 *************************
	 * IDs:
	 * 31789 Righteous Defense		STATUS: DONE
	 *  --------------------------------------------
	 * 18350 illumination			STATUS: DONE
	 *  --------------------------------------------
	 *************************/

	/*
		Righteous Defense
		Come to the defense of a friendly target, commanding up to 3 enemies attacking the target to attack the Paladin instead.
		
		Effect #1	Dummy
			Radius: 5 yards

		Effect #2	Trigger Spell
			Spell #31980
	*/
	case 31789:
		{
			//we will try to lure 3 enemies from our target
			if( unitTarget == NULL || u_caster == NULL)
				break;
			Unit* targets[3];
			int targets_got=0;
			for(set<Object* >::iterator itr = unitTarget->GetInRangeSetBegin(), i2; itr != unitTarget->GetInRangeSetEnd(); )
			{
				i2 = itr++;
				// don't add objects that are not units and that are dead
				if((*i2)->GetTypeId()!= TYPEID_UNIT || !TO_UNIT(*i2)->isAlive())
					continue;
		        
				Creature* cr=TO_CREATURE((*i2));
				if(cr->GetAIInterface()->getNextTarget()==unitTarget)
					targets[targets_got++]=cr;
				if(targets_got==3)
					break;
			}
			for(int i=0;i<targets_got;i++)
			{
				//set threat to this target so we are the msot hated
				uint32 threat_to_him = targets[i]->GetAIInterface()->getThreatByPtr( unitTarget );
				uint32 threat_to_us = targets[i]->GetAIInterface()->getThreatByPtr(u_caster);
				int threat_dif = threat_to_him - threat_to_us;
				if(threat_dif>0)//should nto happen
					targets[i]->GetAIInterface()->modThreatByPtr(u_caster,threat_dif);
				targets[i]->GetAIInterface()->AttackReaction(u_caster,1,0);
				targets[i]->GetAIInterface()->setNextTarget(u_caster);
			}
		}break;
	/*
		Divine Storm
	*/
	
	case 53385:
		{
		  if( p_caster != NULL && ModeratedTargets.size())
			{
				uint32 amt = float2int32( 0.25f * ModeratedTargets.size() * CalculateDamage(p_caster, unitTarget, MELEE, m_spellInfo->SpellGroupType, m_spellInfo) );
				uint32 count = 0;

				if( p_caster->GetGroup() )
				{
					p_caster->GetGroup()->Lock();
					for(uint32 x = 0; x < p_caster->GetGroup()->GetSubGroupCount(); ++x)
					{
						if( count == 3 ) break;
						for(GroupMembersSet::iterator itr = p_caster->GetGroup()->GetSubGroup( x )->GetGroupMembersBegin(); itr != p_caster->GetGroup()->GetSubGroup( x )->GetGroupMembersEnd(); ++itr)
						{
						if( (*itr) && (*itr)->m_loggedInPlayer && (*itr)->m_loggedInPlayer->GetPowerType() == POWER_TYPE_MANA && count != 3)
							{
							SpellEntry *spellInfo = dbcSpell.LookupEntry( 54172 );
							Spell* sp(new Spell( p_caster, spellInfo, true, NULL ));
							sp->forced_basepoints[0] = amt;
							SpellCastTargets tgt;
							tgt.m_unitTarget = (*itr)->m_loggedInPlayer->GetGUID();
							sp->prepare(&tgt);
							count++;
							}
						}
					}
					p_caster->GetGroup()->Unlock();
				}
				else
				{
					SpellEntry *spellInfo = dbcSpell.LookupEntry( 54172 );
					Spell* sp(new Spell( p_caster, spellInfo, true, NULL ));
					sp->forced_basepoints[0] = amt;
					SpellCastTargets tgt;
					tgt.m_unitTarget = p_caster->GetGUID();
					sp->prepare(&tgt);
				}
		  }
	}break;

	/*************************
	 * PRIEST SPELLS
	 *************************
	 * IDs:
	 * 33076 - Prayer of mending master spell
	 * 41637 - Prayer of mending
	 *  --------------------------------------------
	 *************************/

	/*************************
	 * SHAMAN SPELLS
	 *************************
	 * IDs:
	 * NO SPELLS
	 *  --------------------------------------------
	 *************************/
	case 55198:	// Tidal Force
		{
			SpellEffectTriggerSpell(i);
			SpellEffectTriggerSpell(i);
			SpellEffectTriggerSpell(i);	// want stack of 3 so cast it 3 times. hacky :/
		}break;

	/*************************
	 * WARLOCK SPELLS
	 *************************
	 * IDs:
	 * 19028 soul link effect		STATUS: DONE
	 *  --------------------------------------------
	 *************************/
	/*
		Soul Link - EFFECT
		20% of damage taken by master is split with demon. All damage increased by 5%.
	*/
	case 25228:
		{
			if( u_caster == NULL || !u_caster->isAlive() || unitTarget == NULL || !unitTarget->isAlive())
				return;
			uint32 pet_dmg = this->forced_basepoints[0]*20/100;
			unitTarget->ModUnsigned32Value(UNIT_FIELD_HEALTH,pet_dmg);
			unitTarget->DealDamage(u_caster,pet_dmg,0,0,25228);
		}break;
		//Demonic Circle
	case 48020:
		{
			if( p_caster == NULL )
				return;
		
			GameObject* DemonicCircle = p_caster->GetMapMgr()->GetGameObject( p_caster->m_ObjectSlots[0] );
			if( DemonicCircle )
			{
				p_caster->SafeTeleport( DemonicCircle->GetMapId(), DemonicCircle->GetInstanceID(), DemonicCircle->GetPosition());
			}
		}break;
	/*************************
	 * DEATH KNIGHT SPELLS
	 *************************/

//	case 52375:
	case 47541:
	case 47632:
	case 47633:
	case 49892:
	case 49893:
	case 49894:
	case 49895:
	case 62900:
	case 62901:
	case 62902:
	case 62903:
	case 62904://Death Coil
		{
			if( u_caster == NULL || unitTarget == NULL)
				return;
			if(spellId == 52375)
				damage = damage * 2 / 5;	// 40% for rank 1
			if(isAttackable(u_caster, unitTarget, false))
				u_caster->SpellNonMeleeDamageLog(unitTarget, spellId, damage, true);
			else if(unitTarget->IsCreature())
			{
				CreatureInfo * ci = TO_CREATURE(unitTarget)->GetCreatureInfo();
				if(ci && ci->Type == UNIT_TYPE_UNDEAD)
					u_caster->Heal(unitTarget, spellId, float2int32(damage * 1.5f));
			}
			else if(unitTarget->IsPlayer())
			{	// TODO: Check if player is considered undead (Lichborne)
				//TO_PLAYER(unitTarget)->
			}
		}break;

	/*************************
		Non-Class spells
		- Done
	 *************************/
	/*
		Living Root of the Wildheart
		Your spells and attacks in each form have a chance to grant you a blessing for 15 sec.
	*/
	case 37336:
		{
			if( p_caster == NULL || playerTarget == NULL )
				return;

			uint32 NewSpell = 0;
			uint8 shape = playerTarget->GetShapeShift();
			switch( shape )
			{
			case FORM_NORMAL:
				NewSpell = 37344; break;
			case FORM_BEAR:
				NewSpell = 37340; break;
			case FORM_DIREBEAR:
				NewSpell = 37340; break;
			case FORM_CAT:
				NewSpell = 37341; break;
			case FORM_TREE:
				NewSpell = 37342; break;
			case FORM_MOONKIN:
				NewSpell = 37343; break;
			}
			if( NewSpell != 0 )
				p_caster->CastSpell(playerTarget,NewSpell,true);
		}break;
	/*
		Poultryizer
		Turns the target into a chicken for 15 sec.   Well, that is assuming the transmogrification polarity has not been reversed...
	*/
	case 30507:
		{
			if( unitTarget == NULL || !unitTarget->isAlive())
				return;

			u_caster->CastSpell(unitTarget->GetGUID(),30501,true);
		}break;
	/*
		Six Demon Bag
		Blasts enemies in front of you with the power of wind, fire, all that kind of thing!
	*/
	case 14537:
		{
			if( unitTarget == NULL || !unitTarget->isAlive())
				return;

			uint32 ClearSpellId[6] = { 8401,8408,930,118,1680,10159 };
			int min = 1;
			uint32 effect = min + int( ((6-min)+1) * rand() / (RAND_MAX + 1.0) );
			
			u_caster->CastSpell(unitTarget, ClearSpellId[effect] ,true);
		}break;

	case 30427: // Extract Gas
		{
			bool check = false;
			uint32 cloudtype;
			Creature* creature = NULL;

			if(p_caster == NULL)
				return;

			for(Object::InRangeSet::iterator i = p_caster->GetInRangeSetBegin(); i != p_caster->GetInRangeSetEnd(); ++i)
			{
				if((*i)->GetTypeId() == TYPEID_UNIT)
				{
					creature= TO_CREATURE(*i);
					cloudtype=creature->GetEntry();
					if(cloudtype == 24222 || cloudtype == 17408 || cloudtype == 17407 || cloudtype == 17378)
					{
						if(p_caster->GetDistance2dSq((*i)) < 400)
						{
							p_caster->SetSelection(creature->GetGUID());
							check = true;
							break;
						}
					}
				}
			}
			
			if(check)
			{
				uint32 item,count = 3+(rand()%3);
			
				if (cloudtype==24222) item=22572;//-air
				if (cloudtype==17408) item=22576;//-mana
				if (cloudtype==17407) item=22577;//-shadow
				if (cloudtype==17378) item=22578;//-water

				Item* add = p_caster->GetItemInterface()->FindItemLessMax(item, count, false);
				if (!add)
				{
					ItemPrototype* proto = ItemPrototypeStorage.LookupEntry(item);
					SlotResult slotresult;

					slotresult = p_caster->GetItemInterface()->FindFreeInventorySlot(proto);
					if(!slotresult.Result)
					{
						p_caster->GetItemInterface()->BuildInventoryChangeError(NULL, NULL, INV_ERR_INVENTORY_FULL);
						return;
					}
					Item* it=objmgr.CreateItem(item,p_caster);  
					it->SetUInt32Value( ITEM_FIELD_STACK_COUNT, count);
					p_caster->GetItemInterface()->SafeAddItem(it,slotresult.ContainerSlot, slotresult.Slot);
					creature->Despawn(3500,creature->GetProto()->RespawnTime);
				}
				else
				{
					add->SetStackCount(add->GetUInt32Value(ITEM_FIELD_STACK_COUNT) + count);
					add->m_isDirty = true;
					creature->Despawn(3500,creature->GetProto()->RespawnTime);
				}
			}
		}break;

	//curse of agony(18230) = periodic damage increased in 
	//flag 2031678
	case 1454://life tap
	case 1455:
	case 1456:
	case 11687:
	case 11688:
	case 11689:
	case 27222:
	case 57946:
		{//converts base+1+spirit*x points of health into mana
			if(p_caster == NULL|| playerTarget== NULL )
				return;

			uint32 mod;	// spirit bonus coefficient multiplied by 2
			if(m_spellInfo->Id == 1454) mod = 2;
			else if(m_spellInfo->Id == 1455) mod = 3;
			else if(m_spellInfo->Id == 1456) mod = 4;
			else if(m_spellInfo->Id == 11687) mod = 5;
			else mod = 6;

			uint32 damage = m_spellInfo->EffectBasePoints[i] + 1 + mod * playerTarget->GetUInt32Value(UNIT_FIELD_STAT4) / 2;
			if (damage >= playerTarget->GetUInt32Value(UNIT_FIELD_HEALTH))
				return;
			p_caster->DealDamage(playerTarget,damage,0,0,spellId);
			damage = damage * (100 + playerTarget->m_lifetapbonus) / 100;	// Apply improved life tap
			p_caster->Energize(playerTarget, pSpellId ? pSpellId : m_spellInfo->Id, damage, POWER_TYPE_MANA);
		}break;
	case 39610://Mana Tide
		{
			if(unitTarget == NULL || unitTarget->IsDead() || unitTarget->getClass() == WARRIOR || unitTarget->getClass() == ROGUE)
 				return;
 			uint32 gain = (uint32) (unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1)*0.06);
			unitTarget->Energize(unitTarget,16191,gain,POWER_TYPE_MANA);
		}break;
	case 20577:// Cannibalize
		{
			if(p_caster == NULL)
				return;
			p_caster->CastSpell( p_caster, 20578, true);
			p_caster->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_CANNIBALIZE);
		}break;
	case 23074:// Arcanite Dragonling
	case 23075:// Mithril Mechanical Dragonling
	case 23076:// Mechanical Dragonling
	case 23133:// Gnomish Battle Chicken
		{
			uint32 spell_id;
			switch(m_spellInfo->Id)
			{
                case 23074: spell_id = 19804; break;
                case 23075: spell_id = 12749; break;
                case 23076: spell_id =  4073; break;
                case 23133: spell_id = 13166; break;
				default: 
					return;
			}
			u_caster->CastSpell(u_caster,spell_id,true);
		}break;
	case 23725:// Gift of Life
		{
			if(playerTarget == NULL)
				break;

			SpellCastTargets tgt;
			tgt.m_unitTarget = playerTarget->GetGUID();
			SpellEntry * inf =dbcSpell.LookupEntry(23782);
			Spell* spe = new Spell(u_caster,inf,true,NULL);
			spe->prepare(&tgt);

		}break;
	case 12975:// Last Stand
		{
			if(playerTarget == NULL)
				break;
			SpellCastTargets tgt;
			tgt.m_unitTarget = playerTarget->GetGUID();
			SpellEntry * inf =dbcSpell.LookupEntry(12976);
			Spell* spe = new Spell(u_caster,inf,true,NULL);
			spe->prepare(&tgt);

		}break;
	/*************************
		Non-Class spells
		- ToDo
	 *************************/
	case 6668:// Red Firework
		{
			// Shoots a firework into the air that bursts into a thousand red stars
		}break;
	case 8344:// Universal Remote
		{
			//FIXME:Allows control of a mechanical target for a short time.  It may not always work and may just root the machine or make it very very angry.  Gnomish engineering at its finest.
		}break;
	case 9976:// Polly Eats the E.C.A.C.
		{
			//FIXME: Don't know what this does
		}break;
	case 10137:// Fizzule's Whistle
		{
			//FIXME:Blow on the whistle to let Fizzule know you're an ally
			//This item comes after a finish of quest at venture co.
			//You must whistle this every time you reach there to make Fizzule
			//ally to you.
		}break;
	case 11540:// Blue Firework
		{
			//Shoots a firework into the air that bursts into a thousand blue stars
		}break;
	case 11541:// Green Firework
		{
			//Shoots a firework into the air that bursts into a thousand green stars
		}break;
	case 11542:// Red Streaks Firework
		{
			//Shoots a firework into the air that bursts into a thousand red streaks
		}break;
	case 11543:// Red, White and Blue Firework
		{
			//Shoots a firework into the air that bursts into red, white and blue stars
		}break;
	case 11544:// Yellow Rose Firework
		{
			//Shoots a firework into the air that bursts in a yellow pattern
		}break;
	case 12151:// Summon Atal'ai Skeleton
		{
			//8324	Atal'ai Skeleton

			//FIXME:Add here remove in time event
		}break;
	case 13535:// Tame Beast
		{
			
		}break;
	case 13006:// Shrink Ray
		{
			//FIXME:Schematic is learned from the gnomish engineering trainer. The gnomish/gobblin engineering decision is made when you are lvl40+ and your engineering is 200+. Interestingly, however, when this item fails to shrink the target, it can do a variety of things, such as...
			//-Make you bigger (attack power +250)
			//-Make you smaller (attack power -250)
			//-Make them bigger (same effect as above)
			//-Make your entire party bigger
			//-Make your entire party smaller
			//-Make every attacking enemy bigger
			//-Make ever attacking enemy smaller
			//Works to your advantage for the most part (about 70% of the time), but don't use in high-pressure situations, unless you're going to die if you don't. Could tip the scales the wrong way.
			//Search for spells of this


			//13004 - grow <- this one
			//13010 - shrink <-this one
			//
		}break;
	case 13180:// Gnomish Mind Control Cap
		{
			// FIXME:Take control of humanoid target by chance(it can be player)
		}break;
	case 13278:// Gnomish Death Ray
		{
			// FIXME:The devices charges over time using your life force and then directs a burst of energy at your opponent
			//Drops life			
		}break;
	case 13280:// Gnomish Death Ray
		{
			//FIXME: Drop life
		}break;
	case 17816:// Sharp Dresser
		{
			//Impress others with your fashion sense
		}break;
	case 21343:// Snowball
		{
		}break;
	case 23645:// Hourglass Sand
		{
			//Indeed used at the Chromo fight in BWL. Chromo has a stunning debuff, uncleansable, unless you have hourglass sand. This debuff will stun you every 4 seconds, for 4 seconds. It is resisted a lot though. Mage's and other casters usually have to do this fight with the debuff on, healers, tanks and hunters will get some to cure themselves from the debuff
		}break;
	case 24325:// Pagle's Point Cast - Create Mudskunk Lure
		{
			//FIXME:Load with 5 Zulian Mudskunks, and then cast from Pagle's Point in Zul'Gurub
		}
	case 24392:// Frosty Zap
		{
			//FIXME:Your Frostbolt spells have a 6% chance to restore 50 mana when cast.
			//damage == 50
		}break;
	case 25822:// Firecrackers
		{
			//FIXME:Find firecrackers
		}break;
	case 26373:// Lunar Invititation
		{
			//FIXME: Teleports the caster from within Greater Moonlight
		}break;
	case 26374:// Elune's Candle
		{
			if(u_caster == NULL)
				return;
			u_caster->CastSpell(unitTarget,26622,true);
		}break;
	case 26889:// Give Friendship Bracelet
		{
			//Give to a Heartbroken player to cheer them up
			//laugh emote
		}break;
	case 27662:// Throw Cupid's Dart
		{
			//FIXME:Shoot a player, and Kwee Q. Peddlefeet will find them! (Only works on players with no current critter pets.)
		}break;
	case 28414:// Call Ashbringer
		{
			//http://www.thottbot.com/?i=53974
			if(p_caster == NULL)
			 	return;
			
			uint32 ashcall = RandomUInt(12);

			WorldPacket data;
			data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);

			WorldPacket *crap;
			std::stringstream Reply;

			switch(ashcall)
			{
			case 1:
				{
						data << uint32(8906) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "I... was... pure... once.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 2:
				{
						data << uint32(8907) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Fought... for... righteousness.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 3:
				{
						data << uint32(8908) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "I... was... once... called... Ashbringer.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 4:
				{
						data << uint32(8920) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Betrayed... by... my... order.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 5:
				{
						data << uint32(8921) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Destroyed... by... Kel'Thuzad.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 6:
				{
						data << uint32(8922) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Made... to serve.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 7:
				{
						data << uint32(8923) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "My... son... watched... me... die.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 8:
				{
						data << uint32(8924) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Crusades... fed his rage.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 9:
				{
						data << uint32(8925) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Truth... is... unknown... to him.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 10:
				{
						data << uint32(8926) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Scarlet... Crusade... is pure... no longer.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 11:
				{
						data << uint32(8927) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Balnazzar's... crusade... corrupted... my son.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 12:
				{
						data << uint32(8928) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Kill... them... all!";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			}			
			p_caster->GetSession()->SendPacket(crap);
		}break;
	case 28806:// Toss Fuel on Bonfire
		{
			//FIXME:Dont know what this dummy does
		}break;
	case 7669:// Bethor's Potion
		{
			// related to Hex of Ravenclaw,
			// its a dispell spell.
			//FIXME:Dont know whats the usage of this dummy
		}break;
	case 8283:// Snufflenose Command
		{
			//FIXME:Quest Blueleaf Tubers
			//For use on a Snufflenose Gopher
		}break;
	case 8913:// Sacred Cleansing
		{
			//FIXME:Removes the protective enchantments around Morbent Fel
			//Quest Morbent Fel
		}break;
	case 9962://Capture Treant
		{
			//Quest Treant Muisek 
		}break;
	case 10113:// Flare Gun's flare
		{
			//FIXME:Quest Deep Cover
			//1543 may need to cast this
			//2 flares and the /salute
		}break;
	case 10617:// Release Rageclaw
		{
			//Quest Druid of the Claw
			//Use on the fallen body of Rageclaw
		}break;
	case 11402:// Shay's Bell
		{
			//FIXME:Quest Wandering Shay
			//Ring to call Shay back to you
		}break;
	case 11548:// Summon Spider God
		{
			float SSX = p_caster->GetPositionX();
			float SSY = p_caster->GetPositionY();
			float SSZ = p_caster->GetPositionZ();
			float SSO = p_caster->GetOrientation();

			p_caster->GetMapMgr()->GetInterface()->SpawnCreature(2707, SSX, SSY, SSZ, SSO, true, false, 0, 0)->Despawn(60000, 0);
		}break;
	case 11610:// Gammerita Turtle Camera
		{
			//Quest The Super Snapper FX 
		}break;
	case 11886:// Capture Wildkin
		{
			//Quest Testing the Vessel
			//Shrink and Capture a Fallen Wildkin
		}break;
	case 11887:// Capture Hippogryph
		{
			//FIXME:Same with 11888
			//Quest Hippogryph Muisek 
		}break;
	case 11888:// Capture Faerie Dragon
		{
			//FIXME:Check Faerie Dragon Muisek is killed or not if its killed update quest
			//And allow create of fearie Dragon which is effect 1
			//Quest: Faerie Dragon Muisek
		}break;
	case 11889:// Capture Mountain Giant
		{
			//FIXME:Same with 11888
			//Quest: Mountain Giant Muisek
		}break;
	case 12189:// Summon Echeyakee
		{
			//3475	Echeyakee

			//FIXME:Quest Echeyakee
		}break;
	case 12283:// Xiggs Signal Flare
		{
			//Quest Signal for Pickup
			//To be used at the makeshift helipad in Azshara. It will summon Pilot Xiggs Fuselighter to pick up the tablet rubbings
		}break;
	case 12938:// Fel Curse
		{
			//FIXME:Makes near target killable(servants of Razelikh the Defiler)
		}break;
	case 14247:// Blazerunner Dispel
		{
			//FIXME:Quest Aquementas and some more
		}break;
	case 14250:// Capture Grark
		{
			//Quest Precarious Predicament
		}break;
	case 14813:// Rocknot's Ale
		{
			//you throw the mug
			//and the guy gets pissed well everyone gets pissed and he crushes the door so you can get past
			//maybe after like 30 seconds so you can get past.  but lke I said I have never done it myself 
			//so i am not 100% sure what happens.
		}break;
	case 15991://Revive Ringo
		{
			//Quest A Little Help From My Friends 
			//Revive Ringo with water
		}break;
	case 15998:// Capture Worg Pup
		{
			//FIXME:Ends Kibler's Exotic Pets  (Dungeon) quest
		}break;
	case 16031:// Releasing Corrupt Ooze
		{
			//FIXME:Released ooze moves to master ooze and "Merged Ooze Sample"
			//occurs after some time.This item helps to finish quest
		}break;
	case 16378:// Temperature Reading
		{
			//FIXME:Quest Finding the Source
			//Take a reading of the temperature at a hot spot.
		}break;
	case 17166:// Release Umi's Yeti
		{
			//Quest Are We There, Yeti?
			//Select Umi's friend and click to release the Mechanical Yeti
		}break;
	case 17271:// Test Fetid Skull
		{
			//FIXME:Marauders of Darrowshire
			//Wave over a Fetid skull to test its resonance
		}break;
	case 18153:// Kodo Kombobulator
		{
			//FIXME:Kodo Roundup Quest
			//Kodo Kombobulator on any Ancient, Aged, or Dying Kodo to lure the Kodo to follow (one at a time)
		}break;
	case 19250:// Placing Smokey's Explosives
		{
			//This is something related to quest i think
		}break;
	case 19512:// Apply Salve
		{
			//FIXME:Cure a sickly animal afflicted by the taint of poisoning
			if(unitTarget->GetEntry() == 12298 && unitTarget->HasBuff(19502))
			{
				//unitTarget->AddAuraVisual(19502, -1, true);
				unitTarget->SetUInt32Value(UNIT_FIELD_DISPLAYID, 347);
				sQuestMgr._OnPlayerKill(p_caster, TO_CREATURE(unitTarget)->GetLowGUID(), false);
				TO_CREATURE(unitTarget)->Despawn(5000, 360000);
			}else
				if(unitTarget->GetEntry() == 12296 && unitTarget->HasBuff(19502))
				{
					//unitTarget->AddAuraVisual(19502, -1, true);
					unitTarget->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1547);
					sQuestMgr._OnPlayerKill(p_caster, TO_CREATURE(unitTarget)->GetLowGUID(), false);
					TO_CREATURE(unitTarget)->Despawn(5000, 360000);
				}else
				{
					SendCastResult(SPELL_FAILED_BAD_TARGETS);
					return;
				}
		}break;
	case 20804:// Triage 
		{
			//Quest Triage
			//Use on Injured, Badly Injured, and Critically Injured Soldiers
		}break;
	case 21050:// Melodious Rapture
		{
			//Quest Deeprun Rat Roundup 
		}break;
	case 21332:// Aspect of Neptulon
		{
			//FIXME:Used on plagued water elementals in Eastern Plaguelands
			//Quest:Poisoned Water
		}break;
	case 21960:// Manifest Spirit
		{
			//FIXME:Forces the spirits of the first centaur Kahns to manifest in the physical world
			//thats a quest
			//its for maraudon i think
			//u use that on the spirit mobs
			//to release them
		}break;
	case 23359:// Transmogrify!
		{
			//Quest Zapped Giants 
			//Zap a Feralas giant into a more manageable form
		}break;
	case 27184:// Summon Mor Grayhoof
		{
			//16044	Mor Grayhoof Trigger
			//16080	Mor Grayhoof

			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27190:// Summon Isalien
		{
			//16045	Isalien Trigger
			//16097	Isalien

			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27191:// Summon the remains of Jarien and Sothos
		{
			/*
			16046	Jarien and Sothos Trigger
			16101	Jarien
			16103	Spirit of Jarien
			
			16102	Sothos
			16104	Spirit of Sothos
			*/

			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27201:// Summon the spirit of Kormok
		{
			/*16047	Kormok Trigger
			16118	Kormok
			*/
			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27202:// Summon Lord Valthalak
		{
			/*
			16042	Lord Valthalak
			16048	Lord Valthalak Trigger
			16073	Spirit of Lord Valthalak

			*/
			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27203:// Summon the spirits of the dead at haunted locations
		{
			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27517:// Use this banner at the Arena in Blackrock Depths to challenge Theldren
		{
			//This is used to make Theldren spawn at the place where it used
			//I couldnt find theldrin, and his men in creature names database
			//Someone has to write this and this is related to The Challange quest
			/*By moving to the center grate, you trigger the arena event. 
			A random group of mobs (spiders, worms, bats, raptors) spawns, 
			and you have to kill them. After the last one dies, and a small 
			break, a boss mob spawns. Successfully completing this event 
			turns the arena spectators from red to yellow*/
		}break;
	case 34026: //Kill Command
		{
			if( p_caster == NULL  || p_caster->GetSummon() == NULL )
				return;
			Unit* petunit = TO_UNIT(p_caster->GetSummon());
			if( petunit != NULL )
			{
				p_caster->CastSpell(petunit, 34027, true);
				p_caster->CastSpell(petunit, 34027, true);
				p_caster->CastSpell(petunit, 34027, true);
			}
		}break;
	//Berserking Troll Racial
	case  20554:
	case  26296:
	case  26297:
	case  50621:
		{
			if(playerTarget == NULL)
				break;
			SpellCastTargets tgt;
			tgt.m_unitTarget = playerTarget->GetGUID();
			SpellEntry * inf =dbcSpell.LookupEntry(26635);
			Spell* spe = new Spell(u_caster,inf,true,NULL);
			spe->prepare(&tgt);
		}break;
	}
	if(sScriptMgr.CallScriptedDummySpell(spellId, i, this))
		return;

	sLog.outDetail("Spell ID: %u ( %s ) has a dummy effect ( %u ) but no handler for it.", spellId, m_spellInfo->Name, i);
}

void Spell::SpellEffectTeleportUnits(uint32 i)    // Teleport Units
{
	if(unitTarget == NULL || m_caster == NULL)
		return;

	uint32 spellId = GetProto()->Id;

	// [2010-11-7 18:30] <@dfighter> a.) teleport to bindpoint
	// [2010-11-7 18:30] <@dfighter> b.) teleport to somewhere in world
	// [2010-11-7 18:30] <@dfighter> c.) teleport behind the target
	// [2010-11-7 18:34] <@dfighter> d.) teleport to caster's position

	if(m_spellInfo->EffectCustomFlag == 0)
	{
		LOG_ERROR("Spell %u ( %s ) has a teleport effect, but has no teleport flag.", spellId, m_spellInfo->Name);
		return;
	}

	// Portals
	if(m_spellInfo->HasCustomFlagForEffect(i, TELEPORT_TO_COORDINATES))
	{
		TeleportCoords* TC = ::TeleportCoordStorage.LookupEntry(spellId);

		if(TC == NULL)
		{
			LOG_ERROR("Spell %u ( %s ) has a TELEPORT TO COORDINATES effect, but has no coordinates to teleport to. ", spellId, m_spellInfo->Name);
			return;
		}

		HandleTeleport(TC->x, TC->y, TC->z, TC->mapId, unitTarget);
		return;
	}

	// Hearthstone and co.
	if(m_spellInfo->HasCustomFlagForEffect(i, TELEPORT_TO_BINDPOINT))
	{
		if(unitTarget->IsPlayer())
		{
			Player* p = TO_PLAYER(unitTarget);

			HandleTeleport(p->GetBindPositionX(), p->GetBindPositionY(), p->GetBindPositionZ(), p->GetBindMapId(), p);
		}
		return;
	}

	// Summon
	if(m_spellInfo->HasCustomFlagForEffect(i, TELEPORT_TO_CASTER))
	{
		if(u_caster == NULL)
			return;

		HandleTeleport(m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetMapId(), unitTarget);
		return;
	}

	// Shadowstep for example
	if(m_spellInfo->HasCustomFlagForEffect(i, TELEPORT_BEHIND_TARGET))
	{
		if(p_caster == NULL)
			return;

		///////////////////////////////////////////////// Code taken from the Shadowstep dummy script /////////////////////////////////////////////////////////////////////

		/* this is rather tricky actually. we have to calculate the orientation of the creature/player, and then calculate a little bit of distance behind that. */
		float ang;

		if(unitTarget == m_caster)
		{
			/* try to get a selection */
			unitTarget = m_caster->GetMapMgr()->GetUnit(m_targets.m_unitTarget);
			if((!unitTarget) || !isAttackable(p_caster, unitTarget, !(GetProto()->c_is_flags & SPELL_FLAG_IS_TARGETINGSTEALTHED)) || (unitTarget->CalcDistance(p_caster) > 28.0f))
			{
				return;
			}
		}

		if(unitTarget->IsCreature())
		{
			if(unitTarget->GetTargetGUID() != 0)
			{
				/* We're chasing a target. We have to calculate the angle to this target, this is our orientation. */
				ang = m_caster->calcAngle(m_caster->GetPositionX(), m_caster->GetPositionY(), unitTarget->GetPositionX(), unitTarget->GetPositionY());
				/* convert degree angle to radians */
				ang = ang * M_PI_FLOAT / 180.0f;
			}
			else
			{
				/* Our orientation has already been set. */
				ang = unitTarget->GetOrientation();
			}
		}
		else
		{
			/* Players orientation is sent in movement packets */
			ang = unitTarget->GetOrientation();
		}
		// avoid teleporting into the model on scaled models
		const static float shadowstep_distance = 1.6f * unitTarget->GetFloatValue(OBJECT_FIELD_SCALE_X);
		float new_x = unitTarget->GetPositionX() - (shadowstep_distance * cosf(ang));
		float new_y = unitTarget->GetPositionY() - (shadowstep_distance * sinf(ang));
		/* Send a movement packet to "charge" at this target. Similar to warrior charge. */
		p_caster->z_axisposition = 0.0f;
		p_caster->SafeTeleport(p_caster->GetMapId(), p_caster->GetInstanceID(), LocationVector(new_x, new_y, (unitTarget->GetPositionZ() + 0.1f), ang));


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		return;
	}

	// For those special teleport spells
	if(sScriptMgr.CallScriptedDummySpell(m_spellInfo->Id, i, this))
		return;

	/* LOG_ERROR */ LOG_DEBUG("Unhandled Teleport effect %u for Spell %u ( %s ).", i, m_spellInfo->Id, m_spellInfo->Name);
}

void Spell::SpellEffectApplyAura(uint32 i)  // Apply Aura
{
	if( unitTarget == NULL )
		return;
	// can't apply stuns/fear/polymorph/root etc on boss
	if( unitTarget->IsCreature() )
	{
		if( u_caster != NULL && ( u_caster != unitTarget ) )
		{
			Creature * c = static_cast< Creature * >( unitTarget );
			/*
			Charm (Mind Control, enslave demon): 1
			Confuse (Blind etc): 2
			Fear: 4
			Root: 8
			Silence : 16
			Stun: 32
			Sheep: 64
			Banish: 128
			Sap: 256
			Frozen : 512
			Ensnared 1024
			Sleep 2048
			Taunt (aura): 4096
			Decrease Speed (Hamstring) (aura): 8192
			Spell Haste (Curse of Tongues) (aura): 16384
			Interrupt Cast: 32768
			Mod Healing % (Mortal Strike) (aura): 65536
			Total Stats % (Vindication) (aura): 131072
			*/

			//Spells with Mechanic also add other ugly auras, but if the main aura is the effect --> immune to whole spell
			if (c->GetProto() && c->GetProto()->modImmunities)
			{
				bool immune = false;
				if (m_spellInfo->MechanicsType)
				{
					switch(m_spellInfo->MechanicsType)
					{
					case MECHANIC_CHARMED:
						if (c->GetProto()->modImmunities & 1)
							immune = true;
						break;
					case MECHANIC_DISORIENTED:
						if (c->GetProto()->modImmunities & 2)
							immune = true;
						break;
					case MECHANIC_FLEEING:
						if (c->GetProto()->modImmunities & 4)
							immune = true;
						break;
					case MECHANIC_ROOTED:
						if (c->GetProto()->modImmunities & 8)
							immune = true;
						break;
					case MECHANIC_SILENCED:
						if ( c->GetProto()->modImmunities & 16)
							immune = true;
						break;
					case MECHANIC_STUNNED:
						if (c->GetProto()->modImmunities & 32)
							immune = true;
						break;
					case MECHANIC_POLYMORPHED:
						if (c->GetProto()->modImmunities & 64)
							immune = true;
						break;
					case MECHANIC_BANISHED:
						if (c->GetProto()->modImmunities & 128)
							immune = true;
						break;
					case MECHANIC_SAPPED:
						if (c->GetProto()->modImmunities & 256)
							immune = true;
						break;
					case MECHANIC_FROZEN:
						if (c->GetProto()->modImmunities & 512)
							immune = true;
						break;
					case MECHANIC_ENSNARED:
						if (c->GetProto()->modImmunities & 1024)
							immune = true;
						break;
					case MECHANIC_ASLEEP:
						if (c->GetProto()->modImmunities & 2048)
							immune = true;
						break;
					}
				}
				if (!immune)
				{
					// Spells that do more than just one thing (damage and the effect) don't have a mechanic and we should only cancel the aura to be placed
					switch (m_spellInfo->EffectApplyAuraName[i])
					{
					case SPELL_AURA_MOD_CONFUSE:
						if (c->GetProto()->modImmunities & 2)
							immune = true;
						break;
					case SPELL_AURA_MOD_FEAR:
						if (c->GetProto()->modImmunities & 4)
							immune = true;
						break;
					case SPELL_AURA_MOD_TAUNT:
						if (c->GetProto()->modImmunities & 4096)
							immune = true;
						break;
					case SPELL_AURA_MOD_STUN:
						if (c->GetProto()->modImmunities & 32)
							immune = true;
						break;
					case SPELL_AURA_MOD_SILENCE:
						if ((c->GetProto()->modImmunities & 32768) || (c->GetProto()->modImmunities & 16))
							immune = true;
						break;
					case SPELL_AURA_MOD_DECREASE_SPEED:
						if (c->GetProto()->modImmunities & 8192)
							immune = true;
						break;
					case SPELL_AURA_INCREASE_CASTING_TIME_PCT:
						if (c->GetProto()->modImmunities & 16384)
							immune = true;
						break;
					case SPELL_AURA_MOD_LANGUAGE: //hacky way to prefer that the COT icon is set to mob
						if (c->GetProto()->modImmunities & 16384)
							immune = true;
						break;
					case SPELL_AURA_MOD_HEALING_DONE_PERCENT:
						if (c->GetProto()->modImmunities & 65536)
							immune = true;
						break;
					case SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE:
						if (c->GetProto()->modImmunities & 131072)
							immune = true;
						break;
					}
				}
				if( immune )
					return;
			}
		}
	}

#ifdef GM_Z_DEBUG_DIRECTLY
	else {
		if( unitTarget->IsPlayer() && unitTarget->IsInWorld() && static_cast< Player* >( unitTarget )->GetSession() && static_cast< Player* >( unitTarget )->GetSession()->CanUseCommand('z')  ) {
			sChatHandler.BlueSystemMessage( static_cast< Player* >( unitTarget  )->GetSession(), "[%sSystem%s] |rSpell::SpellEffectApplyAura: %s EffectApplyAuraName [%u] .", MSG_COLOR_WHITE, MSG_COLOR_LIGHTBLUE, MSG_COLOR_SUBWHITE,
				i );
		}
	}
#endif

	// avoid map corruption.
	if(unitTarget->GetInstanceID() != m_caster->GetInstanceID())
		return;

	//check if we already have stronger aura
	Aura *pAura;

	std::map<uint32,Aura*>::iterator itr=unitTarget->tmpAura.find(GetProto()->Id);
	//if we do not make a check to see if the aura owner is the same as the caster then we will stack the 2 auras and they will not be visible client sided
	if(itr == unitTarget->tmpAura.end())
	{
		if( GetProto()->NameHash == SPELL_HASH_BLOOD_FRENZY && ProcedOnSpell )//Warrior's Blood Frenzy
			GetProto()->DurationIndex = ProcedOnSpell->DurationIndex;

		uint32 Duration = GetDuration();

		// Handle diminishing returns, if it should be resisted, it'll make duration 0 here.
		if(!(GetProto()->Attributes & ATTRIBUTES_PASSIVE)) // Passive
			::ApplyDiminishingReturnTimer(&Duration, unitTarget, GetProto());

		if(!Duration)
		{
			SendCastResult(SPELL_FAILED_IMMUNE);
			return;
		}

		if(g_caster && g_caster->GetUInt32Value(OBJECT_FIELD_CREATED_BY) && g_caster->m_summoner)
			pAura = sSpellFactoryMgr.NewAura(GetProto(), Duration, g_caster->m_summoner, unitTarget, m_triggeredSpell, i_caster);
		else
			pAura = sSpellFactoryMgr.NewAura(GetProto(), Duration, m_caster, unitTarget, m_triggeredSpell, i_caster);

		pAura->pSpellId = pSpellId; //this is required for triggered spells

		unitTarget->tmpAura[GetProto()->Id] = pAura;
		AddRef();
		sEventMgr.AddEvent(this, &Spell::HandleAddAura, unitTarget->GetGUID(), EVENT_SPELL_HIT, 100, 1, 0);
	}
	else
	{
		pAura=itr->second;
	}
	pAura->AddMod( GetProto()->EffectApplyAuraName[i], damage, GetProto()->EffectMiscValue[i], i );
}

void Spell::SpellEffectEnvironmentalDamage(uint32 i)
{
	if(!playerTarget) return;

	if(playerTarget->SchoolImmunityList[GetProto()->School])
	{
		SendCastResult(SPELL_FAILED_IMMUNE);
		return;
	}
	//this is GO, not unit
	m_caster->SpellNonMeleeDamageLog(playerTarget, GetProto()->Id, damage, pSpellId == 0);
	playerTarget->SendEnvironmentalDamageLog( playerTarget->GetGUID(), DAMAGE_FIRE, damage );
}

void Spell::SpellEffectPowerDrain(uint32 i)  // Power Drain
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	uint32 powerField = UNIT_FIELD_POWER1 + GetProto()->EffectMiscValue[i];
	uint32 curPower = unitTarget->GetUInt32Value(powerField);
	if(powerField == UNIT_FIELD_POWER1 && unitTarget->IsPlayer())
	{
		Player* mPlayer = TO< Player* >(unitTarget);
		if(mPlayer->IsInFeralForm())
			return;

		// Resilience - reduces the effect of mana drains by (CalcRating*2)%.
		damage = float2int32(damage * (1 - ((TO< Player* >(unitTarget)->CalcRating(PLAYER_RATING_MODIFIER_SPELL_CRIT_RESILIENCE) * 2) / 100.0f)));
	}
	uint32 amt = damage + ((u_caster->GetDamageDoneMod(GetProto()->School) * 80) / 100);
	if(amt > curPower)
		amt = curPower;
	unitTarget->SetUInt32Value(powerField, curPower - amt);
	u_caster->Energize(u_caster, GetProto()->Id, amt, GetProto()->EffectMiscValue[i]);
}

void Spell::SpellEffectHealthLeech(uint32 i) // Health Leech
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	uint32 curHealth = unitTarget->GetHealth();
	uint32 amt = damage;
	if(amt > curHealth)
	{
		amt = curHealth;
	}
	m_caster->DealDamage(unitTarget, damage, 0, 0, GetProto()->Id);

	if(!u_caster)
		return;
	uint32 playerCurHealth = u_caster->GetUInt32Value(UNIT_FIELD_HEALTH);
	uint32 playerMaxHealth = u_caster->GetUInt32Value(UNIT_FIELD_MAXHEALTH);

	if(playerCurHealth + amt > playerMaxHealth)
	{
		u_caster->SetHealth(playerMaxHealth);
	}
	else
	{
		u_caster->ModHealth(amt);
	}
}

void Spell::SpellEffectHeal(uint32 i) // Heal
{
	if(p_caster != NULL)
	{
		// HACKY but with SM_FEffect2_bonus it doesnt work

		// Apply this only on targets, which have one of paladins auras
		if(unitTarget && (unitTarget->HasAurasWithNameHash(SPELL_HASH_DEVOTION_AURA) || unitTarget->HasAurasWithNameHash(SPELL_HASH_RETRIBUTION_AURA) ||
		                  unitTarget->HasAurasWithNameHash(SPELL_HASH_CONCENTRATION_AURA) || unitTarget->HasAurasWithNameHash(SPELL_HASH_CRUSADER_AURA) ||  unitTarget->HasAurasWithNameHash(SPELL_HASH_FIRE_RESISTANCE_AURA) ||
		                  unitTarget->HasAurasWithNameHash(SPELL_HASH_FROST_RESISTANCE_AURA) || unitTarget->HasAurasWithNameHash(SPELL_HASH_SHADOW_RESISTANCE_AURA)))
		{
			if(p_caster->HasSpell(20140))     // Improved Devotion Aura Rank 3
				damage = (int32)(damage * 1.06);
			else if(p_caster->HasSpell(20139))     // Improved Devotion Aura Rank 2
				damage = (int32)(damage * 1.04);
			else if(p_caster->HasSpell(20138))     // Improved Devotion Aura Rank 1
				damage = (int32)(damage * 1.02);
		}

		if(p_caster->HasSpell(54943) && p_caster->HasAura(20165))       // Glyph of Seal of Light
			damage = (int32)(damage * 1.05);
	}

	if(GetProto()->EffectChainTarget[i])//chain
	{
		if(!chaindamage)
		{
			chaindamage = damage;
			Heal((int32)chaindamage);
		}
		else
		{
			int32 reduce = GetProto()->EffectDieSides[i] + 1;
			if(GetProto()->SpellGroupType && u_caster)
			{
				SM_FIValue(u_caster->SM_PJumpReduce, &reduce, GetProto()->SpellGroupType);
			}
			chaindamage -= (reduce * chaindamage) / 100;
			Heal((int32)chaindamage);
		}
	}
	else
	{
		//yep, the usual special case. This one is shaman talent : Nature's guardian
		//health is below 30%, we have a mother spell to get value from
		switch(GetProto()->Id)
		{
			case 31616:
				{
					if(unitTarget && unitTarget->IsPlayer() && pSpellId && unitTarget->GetHealthPct() < 30)
					{
						//check for that 10 second cooldown
						SpellEntry* spellInfo = dbcSpell.LookupEntryForced(pSpellId);
						if(spellInfo)
						{
							//heal value is received by the level of current active talent :s
							//maybe we should use CalculateEffect(uint32 i) to gain SM benefits
							int32 value = 0;
							int32 basePoints = spellInfo->EffectBasePoints[i] + 1; //+(m_caster->getLevel()*basePointsPerLevel);
							int32 randomPoints = spellInfo->EffectDieSides[i];
							if(randomPoints <= 1)
								value = basePoints;
							else
								value = basePoints + rand() % randomPoints;
							//the value is in percent. Until now it's a fixed 10%
							Heal(unitTarget->GetMaxHealth()*value / 100);
						}
					}
				}
				break;
				//Bloodthirst
			case 23880:
				{
					if(unitTarget)
					{
						Heal(unitTarget->GetMaxHealth() / 100);
					}
				}
				break;

			case 34299: //Druid: Improved Leader of the PAck
				{
					if(!unitTarget->IsPlayer() || !unitTarget->isAlive())
						break;

					Player* mPlayer = TO< Player* >(unitTarget);
					if(!mPlayer->IsInFeralForm() || (
					            mPlayer->GetShapeShift() != FORM_CAT &&
					            mPlayer->GetShapeShift() != FORM_BEAR &&
					            mPlayer->GetShapeShift() != FORM_DIREBEAR))
						break;
					uint32 max = mPlayer->GetUInt32Value(UNIT_FIELD_MAXHEALTH);
					uint32 val = float2int32(((mPlayer->FindAura(34300)) ? 0.04f : 0.02f) * max);
					if(val)
						mPlayer->Heal(mPlayer, 34299, (uint32)(val));
				}
				break;
			case 22845: // Druid: Frenzied Regeneration
				{
					if(!unitTarget->IsPlayer() || !unitTarget->isAlive())
						break;
					Player* mPlayer = TO< Player* >(unitTarget);
					if(!mPlayer->IsInFeralForm() ||
					        (mPlayer->GetShapeShift() != FORM_BEAR &&
					         mPlayer->GetShapeShift() != FORM_DIREBEAR))
						break;
					uint32 val = mPlayer->GetPower(POWER_TYPE_RAGE);
					if(val > 100)
						val = 100;
					uint32 HpPerPoint = float2int32((mPlayer->GetUInt32Value(UNIT_FIELD_MAXHEALTH) * 0.003f));   //0.3% of hp per point of rage
					uint32 heal = HpPerPoint * (val / 10); //1 point of rage = 0.3% of max hp
					mPlayer->ModPower(POWER_TYPE_RAGE, -1 * val);

					if(val)
						mPlayer->Heal(mPlayer, 22845, heal);
				}
				break;
			case 18562: //druid - swiftmend
				{
					if(unitTarget)
					{
						uint32 new_dmg = 0;
						//consume rejuvenetaion and regrowth
						Aura* taura = unitTarget->FindAuraByNameHash(SPELL_HASH_REGROWTH);    //Regrowth
						if(taura && taura->GetSpellProto())
						{
							uint32 amplitude = taura->GetSpellProto()->EffectAmplitude[1] / 1000;
							if(!amplitude)
								amplitude = 3;

							//our hapiness is that we did not store the aura mod amount so we have to recalc it
							Spell* spell = sSpellFactoryMgr.NewSpell(m_caster, taura->GetSpellProto(), false, NULL);
							uint32 healamount = spell->CalculateEffect(1, unitTarget);
							delete spell;
							spell = NULL;
							new_dmg = healamount * 18 / amplitude;

							unitTarget->RemoveAura(taura);

							//do not remove flag if we still can cast it again
							if(!unitTarget->HasAurasWithNameHash(SPELL_HASH_REJUVENATION))
							{
								unitTarget->RemoveFlag(UNIT_FIELD_AURASTATE, AURASTATE_FLAG_REJUVENATE);
								sEventMgr.RemoveEvents(unitTarget, EVENT_REJUVENATION_FLAG_EXPIRE);
							}
						}
						else
						{
							taura = unitTarget->FindAuraByNameHash(SPELL_HASH_REJUVENATION);  //Rejuvenation
							if(taura  && taura->GetSpellProto())
							{
								uint32 amplitude = taura->GetSpellProto()->EffectAmplitude[0] / 1000;
								if(!amplitude) amplitude = 3;

								//our happiness is that we did not store the aura mod amount so we have to recalc it
								Spell* spell = sSpellFactoryMgr.NewSpell(m_caster, taura->GetSpellProto(), false, NULL);
								uint32 healamount = spell->CalculateEffect(0, unitTarget);
								delete spell;
								spell = NULL;
								new_dmg = healamount * 12 / amplitude;

								unitTarget->RemoveAura(taura);

								unitTarget->RemoveFlag(UNIT_FIELD_AURASTATE, AURASTATE_FLAG_REJUVENATE);
								sEventMgr.RemoveEvents(unitTarget, EVENT_REJUVENATION_FLAG_EXPIRE);
							}
						}

						if(new_dmg > 0)
						{
							SpellEntry* spellInfo = dbcSpell.LookupEntry(18562);
							Spell* spell = sSpellFactoryMgr.NewSpell(unitTarget, spellInfo, true, NULL);
							spell->SetUnitTarget(unitTarget);
							spell->Heal((int32)new_dmg);
							delete spell;
						}
					}
				}
				break;
			default:
				Heal(damage);
				break;
		}
	}
}

void Spell::SpellEffectBind(uint32 i)
{
	if(!playerTarget || !playerTarget->isAlive() || !m_caster)
		return;

	WorldPacket data(45);
	uint32 areaid = playerTarget->GetZoneId();
	uint32 mapid = playerTarget->GetMapId();
	if(GetProto()->EffectMiscValue[i])
	{
		areaid = GetProto()->EffectMiscValue[i];
		AreaTable* at = dbcArea.LookupEntryForced(areaid);
		if(!at)
			return;
		mapid = at->mapId;
	}

	playerTarget->SetBindPoint(playerTarget->GetPositionX(), playerTarget->GetPositionY(), playerTarget->GetPositionZ(), mapid, areaid);

	data.Initialize(SMSG_BINDPOINTUPDATE);
	data << playerTarget->GetBindPositionX() << playerTarget->GetBindPositionY() << playerTarget->GetBindPositionZ() << playerTarget->GetBindMapId() << playerTarget->GetBindZoneId();
	playerTarget->GetSession()->SendPacket(&data);

	data.Initialize(SMSG_PLAYERBOUND);
	data << m_caster->GetGUID() << playerTarget->GetBindZoneId();
	playerTarget->GetSession()->SendPacket(&data);
}
/*
void Spell::SpellEffectQuestComplete(uint32 i) // Quest Complete
{
	if( playerTarget != NULL )
	{
		QuestLogEntry *qle = playerTarget->GetQuestLogForEntry(GetProto()->EffectMiscValue[i]);
		if( qle == NULL )
			return;

		qle->Complete();
		qle->UpdatePlayerFields();
		qle->SendQuestComplete();
	}
}
*/
void Spell::SpellEffectQuestComplete(uint32 i) // Quest Complete
{
	if( !unitTarget || !unitTarget->IsPlayer())
	{
		return;
	}

	if( QuestLogEntry* en = TO_PLAYER(unitTarget)->GetQuestLogForEntry(m_spellInfo->EffectMiscValue[i]))
	{

		en->Complete();
		en->UpdatePlayerFields();
		en->SendQuestComplete();
	}
}

//wand->
void Spell::SpellEffectWeapondamageNoschool(uint32 i) // Weapon damage + (no School)
{
	if(!unitTarget || !u_caster)
		return;

	u_caster->Strike(unitTarget, (GetType() == SPELL_DMG_TYPE_RANGED ? RANGED : MELEE), GetProto(), damage, 0, 0, false, true);
}

void Spell::SpellEffectResurrect(uint32 i) // Resurrect (Flat)
{
	if(!playerTarget)
	{
		if(!corpseTarget)
		{
			// unit resurrection handler
			if(unitTarget)
			{
				if(unitTarget->IsCreature() && unitTarget->IsPet() && unitTarget->IsDead())
				{
					uint32 hlth = ((uint32)GetProto()->EffectBasePoints[i] > unitTarget->GetMaxHealth()) ? unitTarget->GetMaxHealth() : (uint32)GetProto()->EffectBasePoints[i];
					uint32 mana = ((uint32)GetProto()->EffectBasePoints[i] > unitTarget->GetMaxPower(POWER_TYPE_MANA)) ? unitTarget->GetMaxPower(POWER_TYPE_MANA) : (uint32)GetProto()->EffectBasePoints[i];

					if(!unitTarget->IsPet())
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					else
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_PET_DELAYED_REMOVE);
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					unitTarget->SetHealth(hlth);
					unitTarget->SetPower(POWER_TYPE_MANA, mana);
					unitTarget->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
					unitTarget->setDeathState(ALIVE);
					TO< Creature* >(unitTarget)->UnTag();
					TO< Creature* >(unitTarget)->loot.gold = 0;
					TO< Creature* >(unitTarget)->loot.looters.clear();
					TO< Creature* >(unitTarget)->loot.items.clear();
					TO< Creature* >(unitTarget)->SetLimboState(false); // we can regenerate health now
				}
			}

			return;
		}
		playerTarget = objmgr.GetPlayer(GET_LOWGUID_PART(corpseTarget->GetOwner()));
		if(!playerTarget) return;
	}

	if(playerTarget->isAlive() || !playerTarget->IsInWorld())
		return;

	uint32 health = GetProto()->EffectBasePoints[i];
	uint32 mana = GetProto()->EffectMiscValue[i];

	playerTarget->m_resurrectHealth = health;
	playerTarget->m_resurrectMana = mana;

	SendResurrectRequest(playerTarget);
	playerTarget->SetMovement(MOVE_UNROOT, 1);
}

void Spell::SpellEffectAddExtraAttacks(uint32 i) // Add Extra Attacks
{
	if(!u_caster)
		return;
	u_caster->m_extraattacks += damage;
}

void Spell::SpellEffectDodge(uint32 i)
{
	//i think this actually enables the skill to be able to dodge melee+ranged attacks
	//value is static and sets value directly which will be modified by other factors
	//this is only basic value and will be overwritten elsewhere !!!
	//	if(unitTarget->IsPlayer())
	//		unitTarget->SetFloatValue(PLAYER_DODGE_PERCENTAGE,damage);
}

void Spell::SpellEffectParry(uint32 i)
{
	if(unitTarget)
		unitTarget->setcanparry(true);
}

void Spell::SpellEffectBlock(uint32 i)
{
	//i think this actually enables the skill to be able to block melee+ranged attacks
	//value is static and sets value directly which will be modified by other factors
	//	if(unitTarget->IsPlayer())
	//		unitTarget->SetFloatValue(PLAYER_BLOCK_PERCENTAGE,damage);
}

void Spell::SpellEffectCreateItem(uint32 i)
{
	uint32 spellid = m_spellInfo->Id;

	if(playerTarget == NULL)
	{
		LOG_ERROR("Spell %u ( %s ) has a create item effect but no player target!", spellid, m_spellInfo->Name);
		return;
	}


	uint32 itemid = m_spellInfo->EffectItemType[ i ];
	uint32 count = 0;
	uint32 basecount = m_spellInfo->EffectDieSides[ i ];
	uint32 difference = m_spellInfo->EffectBasePoints[ i ];

	if(itemid == 0)
	{
		LOG_ERROR("Spell %u ( %s ) has a create item effect but no itemid to add, Spell needs to be fixed!", spellid, m_spellInfo->Name);
		return;
	}

	ItemPrototype* m_itemProto = ItemPrototypeStorage.LookupEntry(itemid);
	if(m_itemProto == NULL)
	{
		LOG_ERROR("Spell %u ( %s ) has a create item effect but the itemid is invalid!", spellid, m_spellInfo->Name);
		return;
	}

	if(difference > basecount)
	{
		count = basecount + difference;

	}
	else
	{
		uint32 mincount = basecount - difference;
		uint32 maxcount = basecount + difference;
		uint32 variablecount  = maxcount - mincount;
		uint32 randcount = RandomUInt(variablecount);

		count = mincount + randcount;
	}

	uint32 countperlevel = static_cast< uint32 >(Arcemu::round(m_spellInfo->EffectRealPointsPerLevel[ i ]));

	if(countperlevel != 0)
	{
		uint32 leveldiff = m_spellInfo->maxLevel - m_spellInfo->baseLevel;
		uint32 countforlevel = leveldiff * countperlevel;

		count += countforlevel;
	}


	if(count <= 0)
	{
		LOG_ERROR("Spell %u ( %s ) has a create item effect but no item count to add, Spell needs to be fixed! Count overriden to 1.", spellid, m_spellInfo->Name);
		count = 1;
	}

	if(p_caster != NULL)
	{

		skilllinespell* skill = objmgr.GetSpellSkill(spellid);

		// potions learned by discovery variables
		uint32 cast_chance = 5;
		uint32 learn_spell = 0;

		// tailoring specializations get +1 cloth bonus
		switch(spellid)
		{

			case 36686: //Shadowcloth
				if(p_caster->HasSpell(26801)) count++;
				break;

			case 26751: // Primal Mooncloth
				if(p_caster->HasSpell(26798)) count++;
				break;

			case 31373: //Spellcloth
				if(p_caster->HasSpell(26797)) count++;
				break;
		}

		if((skill != NULL) && (skill->skilline == SKILL_ALCHEMY))
		{
			//Potion Master
			if(strstr(m_itemProto->Name1, "Potion"))
			{
				if(p_caster->HasSpell(28675))
					while(Rand(20) && (count < 5))
						count++;

				// Super Rejuvenation Potion
				cast_chance = 2;
				learn_spell = 28586;
			}

			//Elixir Master
			if(strstr(m_itemProto->Name1, "Elixir") || strstr(m_itemProto->Name1, "Flask"))
			{
				if(p_caster->HasSpell(28677))
					while(Rand(20) && (count < 5))
						count++;

				uint32 spList[] = { 28590, 28587, 28588, 28591, 28589 };
				cast_chance = 2;
				learn_spell = spList[ RandomUInt(4) ];
			}

			//Transmutation Master
			if(m_spellInfo->Category == 310)
			{

				//rate for primal might is lower than for anything else
				if(m_spellInfo->Id == 29688)
				{
					if(p_caster->HasSpell(28672))
						while(Rand(40) && (count < 5))
							count++;
				}
				else
				{
					if(p_caster->HasSpell(28672))
						while(Rand(20) && (count < 5))
							count++;
				}

				uint32 spList[] = { 28581, 28585, 28585, 28584, 28582, 28580 };
				cast_chance = 5;
				learn_spell = spList[ RandomUInt(5) ];
			}
		}

		if(!playerTarget->GetItemInterface()->AddItemById(itemid, count, 0))
		{
			SendCastResult(SPELL_FAILED_TOO_MANY_OF_ITEM);
			return;
		}

		if(p_caster != NULL)
		{

			//random discovery by crafter item id
			switch(itemid)
			{

				case 22845: //Major Arcane Protection Potion
					cast_chance = 20;
					learn_spell = 41458;
					break;

				case 22841: //Major Fire Protection Potion
					cast_chance = 20;
					learn_spell = 41500;
					break;

				case 22842: //Major Frost Protection Potion
					cast_chance = 20;
					learn_spell = 41501;
					break;

				case 22847: //Major Holy Protection Potion
					// there is none
					break;

				case 22844: //Major Nature Protection Potion
					cast_chance = 20;
					learn_spell = 41502;
					break;

				case 22846: //Major Shadow Protection Potion
					cast_chance = 20;
					learn_spell = 41503;
					break;
			}

			if((learn_spell != 0) && (p_caster->getLevel() > 60) && !p_caster->HasSpell(learn_spell) && Rand(cast_chance))
			{
				SpellEntry* dspellproto = dbcSpell.LookupEntryForced(learn_spell);

				if(dspellproto != NULL)
				{
					p_caster->BroadcastMessage("%sDISCOVERY! You discovered the %s !|r", MSG_COLOR_YELLOW, dspellproto->Name);
					p_caster->addSpell(learn_spell);
				}
				else
				{
					LOG_ERROR("Spell %u ( %s ) Effect %u tried to teach a non-existing Spell %u in %s:%u", spellid, m_spellInfo->Name, i, learn_spell, __FILE__, __LINE__);
				}
			}
		}

		if(skill != 0)
		{
			DetermineSkillUp(skill->skilline);

			uint32 discovered_recipe = 0;

			for(std::set<ProfessionDiscovery*>::iterator itr = objmgr.ProfessionDiscoveryTable.begin(); itr != objmgr.ProfessionDiscoveryTable.end(); itr++)
			{
				ProfessionDiscovery* pf = *itr;
				if(spellid == pf->SpellId && p_caster->_GetSkillLineCurrent(skill->skilline) >= pf->SkillValue && !p_caster->HasSpell(pf->SpellToDiscover) && Rand(pf->Chance))
				{
					discovered_recipe = pf->SpellToDiscover;
					break;
				}
			}

			// if something was discovered teach player that recipe and broadcast message
			if(discovered_recipe != 0)
			{
				SpellEntry* se = dbcSpell.LookupEntryForced(discovered_recipe);

				if(se != NULL)
				{
					p_caster->addSpell(discovered_recipe);

					WorldPacket* data;
					char msg[256];
					sprintf(msg, "%sDISCOVERY! %s has discovered how to create %s.|r", MSG_COLOR_GOLD, p_caster->GetName(), se->Name);
					data = sChatHandler.FillMessageData(CHAT_MSG_SYSTEM, LANG_UNIVERSAL,  msg, p_caster->GetGUID(), 0);
					p_caster->GetMapMgr()->SendChatMessageToCellPlayers(p_caster, data, 2, 1, LANG_UNIVERSAL, p_caster->GetSession());
					delete data;
				}
				else
				{
					LOG_ERROR("Spell %u ( %s ) Effect %u tried to teach a non-existing Spell %u in %s:%u", spellid, m_spellInfo->Name, i, learn_spell, __FILE__, __LINE__);
				}
			}
		}
	}
}

void Spell::SpellEffectWeapon(uint32 i)
{
	if(!playerTarget)
		return;

	uint32 skill = 0;
	uint32 spell = 0;

	switch(this->GetProto()->Id)
	{
		case 201:    // one-handed swords
			{
				skill = SKILL_SWORDS;
			}
			break;
		case 202:   // two-handed swords
			{
				skill = SKILL_2H_SWORDS;
			}
			break;
		case 203:   // Unarmed
			{
				skill = SKILL_UNARMED;
			}
			break;
		case 199:   // two-handed maces
			{
				skill = SKILL_2H_MACES;
			}
			break;
		case 198:   // one-handed maces
			{
				skill = SKILL_MACES;
			}
			break;
		case 197:   // two-handed axes
			{
				skill = SKILL_2H_AXES;
			}
			break;
		case 196:   // one-handed axes
			{
				skill = SKILL_AXES;
			}
			break;
		case 5011: // crossbows
			{
				skill = SKILL_CROSSBOWS;
				spell = SPELL_RANGED_GENERAL;
			}
			break;
		case 227:   // staves
			{
				skill = SKILL_STAVES;
			}
			break;
		case 1180:  // daggers
			{
				skill = SKILL_DAGGERS;
			}
			break;
		case 200:   // polearms
			{
				skill = SKILL_POLEARMS;
			}
			break;
		case 15590: // fist weapons
			{
				skill = SKILL_UNARMED;
			}
			break;
		case 264:   // bows
			{
				skill = SKILL_BOWS;
				spell = SPELL_RANGED_GENERAL;
			}
			break;
		case 266: // guns
			{
				skill = SKILL_GUNS;
				spell = SPELL_RANGED_GENERAL;
			}
			break;
		case 2567:  // thrown
			{
				skill = SKILL_THROWN;
			}
			break;
		case 5009:  // wands
			{
				skill = SKILL_WANDS;
			}
			break;
		default:
			{
				skill = 0;
				LOG_DEBUG("WARNING: Could not determine skill for spell id %d (SPELL_EFFECT_WEAPON)", this->GetProto()->Id);
			}
			break;
	}

	if(skill)
	{
		if(spell)
			playerTarget->addSpell(spell);

		// if we do not have the skill line
		if(!playerTarget->_HasSkillLine(skill))
		{
			playerTarget->_AddSkillLine(skill, 1, playerTarget->getLevel() * 5);
		}
		else // unhandled.... if we have the skill line
		{
		}
	}
}

void Spell::SpellEffectDefense(uint32 i)
{
	//i think this actually enables the skill to be able to use defense
	//value is static and sets value directly which will be modified by other factors
	//this is only basic value and will be overwritten elsewhere !!!
	//	if(unitTarget->IsPlayer())
	//		unitTarget->SetFloatValue(UNIT_FIELD_RESISTANCES,damage);
}

void Spell::SpellEffectPersistentAA(uint32 i) // Persistent Area Aura
{
	if(m_AreaAura || !m_caster->IsInWorld())
		return;
	//create only 1 dyn object
	uint32 dur = GetDuration();
	float r = GetRadius(i);

	//Note: this code seems to be useless
	//this must be only source point or dest point
	//this AREA aura it's applied on area
	//it can'be on unit or self or item or object
	//uncomment it if I'm wrong
	//We are thinking in general so it might be useful later DK

	// grep: this is a hack!
	// our shitty dynobj system doesn't support GO casters, so we gotta
	// kinda have 2 summoners for traps that apply AA.
	DynamicObject* dynObj = m_caster->GetMapMgr()->CreateDynamicObject();

	if(g_caster != NULL && g_caster->m_summoner && !unitTarget)
	{
		Unit* caster = g_caster->m_summoner;
		dynObj->Create(caster, this, g_caster->GetPositionX(), g_caster->GetPositionY(),
		               g_caster->GetPositionZ(), dur, r);
		m_AreaAura = true;
		return;
	}

	switch(m_targets.m_targetMask)
	{
		case TARGET_FLAG_SELF:
			{
				dynObj->Create(u_caster, this,	m_caster->GetPositionX(),
				               m_caster->GetPositionY(), m_caster->GetPositionZ(), dur, r);
			}
			break;
		case TARGET_FLAG_UNIT:
			{
				if(!unitTarget || !unitTarget->isAlive())
				{
					dynObj->Remove();
					return;
				}

				dynObj->Create(u_caster, this, unitTarget->GetPositionX(), unitTarget->GetPositionY(), unitTarget->GetPositionZ(),
				               dur, r);
			}
			break;
		case TARGET_FLAG_OBJECT:
			{
				if(!unitTarget || !unitTarget->isAlive())
				{
					dynObj->Remove();
					return;
				}

				dynObj->Create(u_caster, this, unitTarget->GetPositionX(), unitTarget->GetPositionY(), unitTarget->GetPositionZ(),
				               dur, r);
			}
			break;
		case TARGET_FLAG_SOURCE_LOCATION:
			{
				dynObj->Create(u_caster, this, m_targets.m_srcX,
				               m_targets.m_srcY, m_targets.m_srcZ, dur, r);
			}
			break;
		case TARGET_FLAG_DEST_LOCATION:
			{
				dynObj->Create(u_caster ? u_caster : g_caster->m_summoner, this,
				               m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, dur, r);
			}
			break;
		default:
			dynObj->Remove();
			return;
	}

	if(u_caster != NULL)
		if(GetProto()->ChannelInterruptFlags > 0)
		{
			u_caster->SetChannelSpellTargetGUID(dynObj->GetGUID());
			u_caster->SetChannelSpellId(GetProto()->Id);
		}

	m_AreaAura = true;
}

void Spell::SpellEffectSummon(uint32 i)
{
	uint32 summonpropid = m_spellInfo->EffectMiscValueB[ i ];

	SummonPropertiesEntry* spe = dbcSummonProperties.LookupEntry(summonpropid);
	if(spe == NULL)
	{
		sLog.outError("No SummonPropertiesEntry for Spell %u ( %s )", m_spellInfo->Id, m_spellInfo->Name);
		return;
	}

	m_summonProperties = spe;

	uint32 entry = m_spellInfo->EffectMiscValue[ i ];

	CreatureInfo* ci = CreatureNameStorage.LookupEntry(entry);
	CreatureProto* cp = CreatureProtoStorage.LookupEntry(entry);

	if((ci == NULL) || (cp == NULL))
	{
		sLog.outError("Spell %u ( %s ) tried to summon creature %u without database data", m_spellInfo->Id, m_spellInfo->Name, entry);
		return;
	}

	LocationVector v(0.0f, 0.0f, 0.0f, 0.0f);

	if((m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION) != 0)
		v = LocationVector(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ);
	else
		v = m_caster->GetPosition();

	// Ugly hack to make sure we always summon at least 1
	if(damage == 0)
		damage = 1;

	// Client adds these spells to the companion window, it's weird but then it happens anyways
	if(spe->Slot == 5)
	{
		SummonNonCombatPet(i);
		return;
	}

	// Delete any objects in my slots. Slot 0 can have unlimited objects.
	if( spe->Slot < 7 && u_caster->m_SummonSlots[ spe->Slot ] != NULL )
	{
		u_caster->SummonExpireSlot(spe->Slot);

		if( i_caster ) // Assume this is the 'toggle off' mode since we had one already.
			return;
	}

	switch(spe->ControlType)
	{
		case SUMMON_CONTROL_TYPE_GUARDIAN:
			if(spe->ID == 121)
			{
				SummonTotem(i);
				return;
			}
			break;

		case SUMMON_CONTROL_TYPE_PET:
		//	SummonNonCombatPet(i);
			SpellEffectSummonPet(i);
			return;

		case SUMMON_CONTROL_TYPE_POSSESSED:
			SummonPossessed(i);
			return;

		case SUMMON_CONTROL_TYPE_VEHICLE:
			SummonGuardian( i );
			return;
	}

	switch(spe->Type)
	{
		case SUMMON_TYPE_NONE:
		case SUMMON_TYPE_CONSTRUCT:
		case SUMMON_TYPE_OPPONENT:

			if(spe->ControlType == SUMMON_CONTROL_TYPE_GUARDIAN)
				SummonGuardian(i);
			else
				SpellEffectSummonWield(i);

			return;

		case SUMMON_TYPE_PET:
			SpellEffectSummonPet(i);
			return;

		case SUMMON_TYPE_GUARDIAN:
		case SUMMON_TYPE_MINION:
		case SUMMON_TYPE_RUNEBLADE:
			SummonGuardian(i);
			return;

		case SUMMON_TYPE_TOTEM:
			SummonTotem(i);
			return;

		case SUMMON_TYPE_COMPANION:
			// These are used as guardians in some quests
			if(spe->Slot == 6)
				SummonGuardian(i);
			else
				SpellEffectSummonCritter(i);
			return;

		case SUMMON_TYPE_VEHICLE:
		case SUMMON_TYPE_MOUNT:
			SummonGuardian(i);
			return;

		case SUMMON_TYPE_LIGHTWELL:
			SummonGuardian(i);
			return;
	}

//	switch( m_spellInfo->EffectMiscValueB[ i ] )
//	switch( spe->ID )
	switch( summonpropid )
	{
	case SUMMON_TYPEID_POSSESSED:
	case SUMMON_TYPEID_POSSESSED2:
		{
			SummonPossessed(i);
			return;
		}break;
	case 161:
	case 607:
	case SUMMON_TYPEID_GUARDIAN:
	case SUMMON_TYPEID_FORCE_OF_NATURE:
	case SUMMON_TYPEID_UNKNOWN12:
	case SUMMON_TYPEID_UNKNOWN13:
		{
			SummonGuardian(i);
			return;
		}break;
	case SUMMON_TYPEID_UNKNOWN4:
	case SUMMON_TYPEID_WILD:
		{

			if(spe->ControlType == SUMMON_CONTROL_TYPE_GUARDIAN)
				SummonGuardian(i);
			else
				SpellEffectSummonWield(i);
			return;
		}break;
	case SUMMON_TYPEID_DEMON:
		{
			SpellEffectSummonDemon(i);
			return;
		}break;
	case SUMMON_TYPEID_TOTEM:
	case SUMMON_TYPEID_TOTEM_1:
	case SUMMON_TYPEID_TOTEM_2:
	case SUMMON_TYPEID_TOTEM_3:
	case SUMMON_TYPEID_TOTEM_4:
		{
			SummonTotem(i);
			return;
		}break;
	case SUMMON_TYPEID_GHOUL:
	case SUMMON_TYPEID_SUMMON:
	case SUMMON_TYPEID_WATER_ELEMENTAL:
		{
			SummonCreature(i);
			return;
		}break;
	case SUMMON_TYPEID_CRITTER:
	case SUMMON_TYPEID_CRITTER2:
	case SUMMON_TYPEID_LIGHTWELL:
		{
			// These are used as guardians in some quests
			if(spe->Slot == 6)
				SummonGuardian(i);
			else
				SpellEffectSummonCritter(i);
			return;
		}break;
	default:
		{
			SummonGuardian(i);
			return;
		}break;
	}

	sLog.outError("Unk Summon ControlType %u and Type %u TypeID %u With Spell %u in Summon Property of %s",spe->ControlType, spe->Type, summonpropid, m_spellInfo->Id, m_spellInfo->Name);
}

void Spell::SummonPossessed(uint32 i) // eye of kilrog
{
	if( m_spellInfo->EffectMiscValue[i] == 28511)
	{
		CreatureProto * proto = CreatureProtoStorage.LookupEntry(28511);
		if ( !proto )
			return;

		uint32 summonpropid = m_spellInfo->EffectMiscValueB[ i ];
		SummonPropertiesEntry * spe = dbcSummonProperties.LookupEntry( summonpropid );
		if ( !spe )
			return;

		p_caster->DismissActivePets();
		p_caster->RemoveFieldSummon();
		
		Summon * s = p_caster->GetMapMgr()->CreateSummon(proto->Id, SUMMONTYPE_POSSESSED);
		if (s == NULL)
			return;

		LocationVector v(2362.81f, -5659.71f, 502.31f, 3.776f);

		s->Load(proto, p_caster, v, m_spellInfo->Id, spe->Slot - 1);
		s->SetUInt32Value(UNIT_FIELD_DISPLAYID, s->GetCreatureInfo()->Female_DisplayID);
		s->SetUInt32Value(UNIT_CREATED_BY_SPELL, m_spellInfo->Id);
		s->PushToWorld(p_caster->GetMapMgr());
	
		p_caster->m_eyeofacherus = s;

		p_caster->Possess(s , 1000);
	}
	else if( m_spellInfo->EffectMiscValue[i] == 4277)
	{
		CreatureProto * proto = CreatureProtoStorage.LookupEntry(4277);
		if ( !proto )
			return;

		uint32 summonpropid = m_spellInfo->EffectMiscValueB[ i ];
		SummonPropertiesEntry * spe = dbcSummonProperties.LookupEntry( summonpropid );
		if ( !spe )
			return;

		p_caster->DismissActivePets();
		p_caster->RemoveFieldSummon();
		
		Summon * NewSummon = p_caster->GetMapMgr()->CreateSummon(proto->Id, SUMMONTYPE_POSSESSED);
		if (NewSummon == NULL)
			return;

		LocationVector v(p_caster->GetPositionX()+(3*(cos((float(M_PI)/2)+p_caster->GetOrientation()))), p_caster->GetPositionY()+(3*(cos((float(M_PI)/2)+p_caster->GetOrientation()))), p_caster->GetPositionZ(), p_caster->GetOrientation());

		NewSummon->Load(proto, p_caster, v, m_spellInfo->Id, spe->Slot - 1);
		NewSummon->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2421);
		NewSummon->SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, 2421);
		NewSummon->SetUInt32Value(UNIT_CREATED_BY_SPELL, m_spellInfo->Id);
		NewSummon->PushToWorld(p_caster->GetMapMgr());
	
		p_caster->m_eyeofkilrogg = NewSummon;


		p_caster->Possess(NewSummon);
	/*	if (NewSummon != p_caster->m_CurrentCharm)
		{
			p_caster->Unroot();

		//	p_caster->DismissActivePets();
		//	p_caster->RemoveFieldSummon();
			p_caster->UnPossessed(NewSummon);
		//	NewSummon->RemoveFromWorld(true);
		//	TO_CREATURE( NewSummon )->DeleteMe();
		}*/
	}
/*	else if( m_spellInfo->EffectMiscValue[i] == 4277)
	{
		Creature* NewSummon = m_caster->GetMapMgr()->CreateCreature(m_spellInfo->EffectMiscValue[i]);
		// Create
		NewSummon->SetInstanceID(m_caster->GetInstanceID());
		NewSummon->Create( "Eye of Kilrogg", m_caster->GetMapId(), m_caster->GetPositionX()+(3*(cos((float(M_PI)/2)+m_caster->GetOrientation()))), m_caster->GetPositionY()+(3*(cos((float(M_PI)/2)+m_caster->GetOrientation()))), m_caster->GetPositionZ(), m_caster->GetOrientation());

		// Fields
		NewSummon->SetCreatureInfo( CreatureNameStorage.LookupEntry( m_spellInfo->EffectMiscValue[i] ) );
		NewSummon->SetCreatureProto( CreatureProtoStorage.LookupEntry( m_spellInfo->EffectMiscValue[i] ) );
		NewSummon->SetUInt32Value(OBJECT_FIELD_ENTRY, m_spellInfo->EffectMiscValue[i]);
		NewSummon->SetUInt32Value(UNIT_FIELD_LEVEL, u_caster->getLevel() );
		NewSummon->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2421);
		NewSummon->SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, 2421);
		NewSummon->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, m_caster->GetGUID());
		NewSummon->SetUInt64Value(UNIT_FIELD_CREATEDBY, m_caster->GetGUID());
		NewSummon->SetUInt32Value(UNIT_FIELD_HEALTH, 12375);
		NewSummon->SetUInt32Value(UNIT_FIELD_MAXHEALTH, 12375);
		NewSummon->SetFaction( p_caster->GetFaction());
		NewSummon->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);

		if(p_caster->IsPvPFlagged())
			NewSummon->SetByteFlag(UNIT_FIELD_BYTES_2, 1, U_FIELD_BYTES_FLAG_PVP);
		if(p_caster->IsFFAPvPFlagged())
			NewSummon->SetByteFlag(UNIT_FIELD_BYTES_2, 1, U_FIELD_BYTES_FLAG_FFA_PVP);

		NewSummon->m_temp_summon=true;

		// Add To World
		NewSummon->PushToWorld(m_caster->GetMapMgr());

		// Force an update on the player to create this guid.
		p_caster->ProcessPendingUpdates();

		p_caster->m_eyeofkilrogg = NewSummon;

		//p_caster->SetUInt64Value(UNIT_FIELD_SUMMON, NewSummon->GetGUID());
		p_caster->SetUInt64Value(PLAYER_FARSIGHT, NewSummon->GetGUID());
		//p_caster->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOCK_PLAYER);
		p_caster->Possess(NewSummon);
	}*/
}

void Spell::SummonGuardian(uint32 i) // Summon Guardian
{
	if ( u_caster == NULL )
		return;

	uint32 cr_entry = m_spellInfo->EffectMiscValue[i];
	uint32 level = u_caster->getLevel();

	//
	if( i != 0 && m_spellInfo->Effect[i-1] == SPELL_EFFECT_APPLY_AURA && m_spellInfo->EffectApplyAuraName[i-1] == SPELL_AURA_MOUNTED )
	{
		CreatureProto * cp = NULL;
		cp = CreatureProtoStorage.LookupEntry(cr_entry);
		if(cp == NULL )
			return;

		if(cp->vehicleid < 0)
		{
			Log.Error("SpellEffect", "Creature %u, has invalid vehicle_entry, please check your creature_proto table", cr_entry);
			return;
		}

		Vehicle* veh = NULL;
		veh = u_caster->GetMapMgr()->CreateVehicle( cr_entry );
		if(veh == NULL)
			return;
		veh->m_CreatedFromSpell = true;
		veh->m_mountSpell = m_spellInfo->EffectBasePoints[i];
		veh->Load( cp, u_caster->GetPositionX(), u_caster->GetPositionY(), u_caster->GetPositionZ(), u_caster->GetOrientation());
		veh->SetInstanceID( u_caster->GetInstanceID() );
		veh->PushToWorld( u_caster->GetMapMgr() ); // we can do this safely since we're in the mapmgr's context
		veh->InitSeats( cp->vehicleid, p_caster );
	}
/*	else if( m_spellInfo->EffectMiscValue[i] == 28864)
	{
		CreatureProto * proto = CreatureProtoStorage.LookupEntry(28864);
		if ( !proto )
			return;

		LocationVector v(0.0f, 0.0f, 0.0f, 0.0f);

		if((m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION) != 0)
			v = LocationVector(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ);
		else
			v = m_caster->GetPosition();

		// If it has no vehicle id, then we can't really do anything with it as a vehicle :/
	//	if( ( proto->vehicle_entry == 0 ) && ( p_caster == NULL ) && ( !p_caster->GetSession()->HasGMPermissions() ) )
		if( ( proto->vehicleid == 0 ) && ( p_caster == NULL )  )
			return;

		Vehicle *c = u_caster->GetMapMgr()->CreateVehicle( 28864 );
		c->m_CreatedFromSpell = true;
		c->m_mountSpell = m_spellInfo->EffectBasePoints[i];
		c->Load( proto,v.x, v.y, v.z, v.o );
		c->Phase(PHASE_SET, u_caster->GetPhase() );
		c->SetUInt32Value(UNIT_CREATED_BY_SPELL,  m_spellInfo->Id );
		c->SetUInt64Value(UNIT_FIELD_CREATEDBY, u_caster->GetGUID() );
		c->SetUInt64Value(UNIT_FIELD_SUMMONEDBY,  u_caster->GetGUID() );
		c->SetFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK );
		c->SetUInt32Value(UNIT_FIELD_BYTES_1, 33554432);
		c->SetInstanceID( u_caster->GetInstanceID() );
		c->PushToWorld( u_caster->GetMapMgr() );

		Player * plr = u_caster->GetMapMgrPlayer( u_caster->GetCharmedByGUID() );

		if(u_caster->IsVehicle())
		{
			TO<Vehicle*>(u_caster)->RemoveAllPassengers();
		}

		// Need to delay this a bit since first the client needs to see the vehicle
		plr->EnterVehicle( c->GetGUID(), 1 * 1000 );
/*
		if(c->IsVehicle())
		{
			c->GetAIInterface()->StopMovement(1500);
			c->CreateWayPoint(1, 609, 2174.84f, -6178.00f, 38.339f, 1.279632f);
			c->GetAIInterface()->StopMovement(1);
			c->CreateWayPoint(2, 609, 2214.33f, -6057.11f, 159.58f, 1.850000f);
			c->GetAIInterface()->StopMovement(1);
			c->CreateWayPoint(3, 609, 2299.84f, -5878.27f, 227.58f, 1.274340f);
			c->GetAIInterface()->StopMovement(1);
			c->CreateWayPoint(4, 609, 2367.83f, -5706.59f, 153.58f, 1.245244f);
		}
/*
		if(plr)
		{
		//	plr->EnterVehicle( c->GetGUID(), 1 * 1000 );
			c->GetAIInterface()->StopMovement(1500);
			c->SetPosition(2174.84f, -6178.00f, 38.339f, 1.279632f, true);
			c->GetAIInterface()->StopMovement(1);
			c->SetPosition(2214.33f, -6057.11f, 159.58f, 1.850000f, true);
			c->GetAIInterface()->StopMovement(1);
			c->SetPosition(2299.84f, -5878.27f, 227.58f, 1.274340f, true);
			c->GetAIInterface()->StopMovement(1);
			c->SetPosition(2367.83f, -5706.59f, 153.58f, 1.245244f, true);
			return;
		} */
//	}
	else if( m_spellInfo->EffectMiscValue[i] == 28670)
	{
		CreatureProto * proto = CreatureProtoStorage.LookupEntry(28670);
		if ( !proto )
			return;

		LocationVector v(0.0f, 0.0f, 0.0f, 0.0f);

		if((m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION) != 0)
			v = LocationVector(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, u_caster->GetOrientation());
		else
			v = m_caster->GetPosition();

		// If it has no vehicle id, then we can't really do anything with it as a vehicle :/
	//	if( ( proto->vehicle_entry == 0 ) && ( p_caster == NULL ) && ( !p_caster->GetSession()->HasGMPermissions() ) )
		if( ( proto->vehicleid == 0 ) && ( p_caster == NULL )  )
			return;

		Vehicle *c = u_caster->GetMapMgr()->CreateVehicle( 28670 );
		c->m_CreatedFromSpell = true;
		c->m_mountSpell = m_spellInfo->EffectBasePoints[i];
		c->Load( proto,v.x, v.y, v.z, v.o );
		c->Phase( PHASE_SET, u_caster->GetPhase() );
		c->SetUInt32Value(UNIT_CREATED_BY_SPELL,  m_spellInfo->Id );
		c->SetUInt64Value(UNIT_FIELD_CREATEDBY, u_caster->GetGUID() );
		c->SetUInt64Value(UNIT_FIELD_SUMMONEDBY,  u_caster->GetGUID() );
		c->SetFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK );
		c->SetUInt32Value(UNIT_FIELD_BYTES_1, 33554432);
		c->SetInstanceID( u_caster->GetInstanceID() );
		c->PushToWorld( u_caster->GetMapMgr() );

//		c->GetAIInterface()->SetFly();

		// Need to delay this a bit since first the client needs to see the vehicle
		u_caster->EnterVehicle( c->GetGUID(), 1 * 1000 );
	}
	else
	{
		//we only have 7 summon slots
		damage = damage > 6 ? 6 : damage;

		// it's health., or a fucked up infernal.
		if( m_summonProperties->Flags & 2 || m_summonProperties->ID == 711)
			damage = 1;

		//Spread spawns equally around summoner
		float angle_for_each_spawn = damage ? - float(M_PI * 2.0f)/damage : - float(M_PI * 2.0f);

		for( uint8 d = 0; d < damage; d++ )
		{
			//skip already filled slots
			if(u_caster->m_SummonSlots[ d ] != NULL)
				continue;

			float m_fallowAngle = angle_for_each_spawn * d;
			uint32 duration = GetDuration();
			duration = duration <= 3600000 ? duration : 3600000; //limit to 1hr max.
			if ( g_caster ) 
			{
				u_caster = g_caster->m_summoner;
				u_caster->m_SummonSlots[d] = TO_CREATURE(g_caster->CreateTemporaryGuardian(cr_entry, duration, m_fallowAngle, u_caster, d));
			}
			else
				u_caster->m_SummonSlots[d ] = TO_CREATURE(u_caster->CreateTemporaryGuardian(cr_entry, duration, m_fallowAngle, level, d));

			if(u_caster->m_SummonSlots[d]!=NULL)
				u_caster->m_SummonSlots[d]->SetSummonOwnerSlot(u_caster->GetGUID(),d);
		}
	}
}

void Spell::SpellEffectSummonCritter(uint32 i)
{
	if(!u_caster || !u_caster->IsInWorld())
		return;

	uint32 SummonCritterID = m_spellInfo->EffectMiscValue[i];

	// GetProto()->EffectDieSides[i] has something to do with dismissing our critter
	// when it is 1, it means to just dismiss it if we already have it
	// when it is 0, it could mean to always summon a new critter, but there seems to be exceptions

	if(u_caster->critterPet)
	{
		// if we already have this critter, we will just dismiss it and return
		if(u_caster->critterPet->GetCreatureInfo() && u_caster->critterPet->GetCreatureInfo()->Id == SummonCritterID)
		{
			u_caster->critterPet->RemoveFromWorld(false,true);
			u_caster->critterPet = NULL;
			return;
		}
		// this is a different critter, so we will dismiss our current critter and then go on to summon the new one
		else
		{
			u_caster->critterPet->RemoveFromWorld(false,true);
			u_caster->critterPet = NULL;
		}
	}

	if(!SummonCritterID) return;

	CreatureInfo * ci = CreatureNameStorage.LookupEntry(SummonCritterID);
	CreatureProto * cp = CreatureProtoStorage.LookupEntry(SummonCritterID);

	if(!ci || !cp) return;

	Creature * pCreature = u_caster->GetMapMgr()->CreateCreature(SummonCritterID);
	pCreature->SetInstanceID(u_caster->GetMapMgr()->GetInstanceID());
	pCreature->Load(cp, m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ());
	pCreature->SetFaction(35);
	pCreature->_setFaction();
	pCreature->SetUInt32Value(UNIT_FIELD_LEVEL, 1);
	pCreature->SetUInt32Value( UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE );
	pCreature->GetAIInterface()->Init(pCreature,AITYPE_PET,MOVEMENTTYPE_NONE,u_caster);
	pCreature->SetUInt64Value( UNIT_FIELD_CREATEDBY, u_caster->GetGUID() );
	pCreature->SetUInt32Value(UNIT_CREATED_BY_SPELL, this->m_spellInfo->Id );
	pCreature->GetAIInterface()->SetUnitToFollow(u_caster);
	pCreature->GetAIInterface()->SetUnitToFollowAngle(float(-(M_PI/2)));
	pCreature->GetAIInterface()->SetFollowDistance( GetRadius( i ) );
	pCreature->GetAIInterface()->disable_melee = true;
	pCreature->bInvincible = true;
	pCreature->PushToWorld(u_caster->GetMapMgr());
	u_caster->critterPet = pCreature;
}

void Spell::SpellEffectSummonDemon(uint32 i)
{
	if(!p_caster/* ||  p_caster->getClass() != WARLOCK */) //summoning a demon shouldn't be warlock only, see spells 25005, 24934, 24810 etc etc
		return;
	Pet *pPet = p_caster->GetSummon();
	if( pPet != NULL )
	{
		pPet->Dismiss();
		pPet = NULL;
	}

	CreatureInfo *ci = CreatureNameStorage.LookupEntry(m_spellInfo->EffectMiscValue[i]);
	if( ci != NULL )
	{
		LocationVector *vec = NULL;
		if( m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION && m_targets.m_destX && m_targets.m_destY && m_targets.m_destZ )
		{
			vec = new LocationVector(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ);
		}
		pPet = objmgr.CreatePet( m_spellInfo->EffectMiscValue[i] );
	//	pPet = objmgr.CreatePet();
		pPet->CreateAsSummon(m_spellInfo->EffectMiscValue[i], ci, NULL, p_caster, GetProto(), 1, 300000);
		if (vec) delete vec;
	}
	//Create Enslave Aura if its inferno spell
	if( m_spellInfo->Id == 1122 && pPet != NULL )
	{
		SpellEntry *spellInfo = dbcSpell.LookupEntry(11726);

		Spell *sp = new Spell( static_cast<Object*>(pPet), spellInfo, true, NULL );

		SpellCastTargets tgt;
		tgt.m_unitTarget = pPet->GetGUID();
		sp->prepare( &tgt );
	}
}

void Spell::SpellEffectSummonWield(uint32 i)  // Summon Wild
{
	//these are some cretures that have your faction and do not respawn
	//number of creatures is actualy dmg (the usual formula), sometimes =3 sometimes =1
	uint32 cr_entry=m_spellInfo->EffectMiscValue[i];
	CreatureProto * proto = CreatureProtoStorage.LookupEntry(cr_entry);
	CreatureInfo * info = CreatureNameStorage.LookupEntry(cr_entry);
	if(!proto || !info)
	{
		sLog.outDetail("Warning : Missing summon creature template %u used by spell %u!",cr_entry,m_spellInfo->Id);
		return;
	}
	for(int i=0;i<damage;i++)
	{
		float m_fallowAngle=-(M_PI/2*i);
		float x = u_caster->GetPositionX()+(3*(cosf(m_fallowAngle+u_caster->GetOrientation())));
		float y = u_caster->GetPositionY()+(3*(sinf(m_fallowAngle+u_caster->GetOrientation())));
		float z = u_caster->GetPositionZ();
		Creature * p = u_caster->GetMapMgr()->CreateCreature(proto->Id );
		//ASSERT(p);
		p->Load(proto, x, y, z);
		p->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, m_caster->GetGUID());
        p->SetUInt64Value(UNIT_FIELD_CREATEDBY, m_caster->GetGUID());
        p->SetZoneId(m_caster->GetZoneId());

		if ( p->GetProto() && p->GetProto()->Faction == 35 )
		{
			p->SetUInt64Value( UNIT_FIELD_SUMMONEDBY, m_caster->GetGUID() );
			p->SetUInt64Value( UNIT_FIELD_CREATEDBY,  m_caster->GetGUID() );
			p->SetFaction(u_caster->GetFaction( ) );
		}
		else
		{
			p->SetFaction(proto->Faction );
		}

		p->m_faction = dbcFactionTemplate.LookupEntry(proto->Faction);
		if(p->m_faction)
			p->m_factionDBC = dbcFaction.LookupEntry(p->m_faction->Faction);
		p->PushToWorld(u_caster->GetMapMgr());
		//make sure they will be desumonized (roxor)
		sEventMgr.AddEvent(p, &Creature::SummonExpire, EVENT_SUMMON_EXPIRE, GetDuration(), 1,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
	}
}

void Spell::SummonCreature(uint32 i) // Summon
{
	if( p_caster == NULL || !p_caster->IsInWorld())
		return;

	/* This is for summon water elemenal, etc */
	CreatureInfo * ci = CreatureNameStorage.LookupEntry(m_spellInfo->EffectMiscValue[i]);
	CreatureProto * cp = CreatureProtoStorage.LookupEntry(m_spellInfo->EffectMiscValue[i]);
	if( !ci || !cp )
		return;

	
	if(m_spellInfo->EffectMiscValue[i] == 510)	// Water Elemental
	{
		Pet* summon = NULL;
		summon = objmgr.CreatePet(m_spellInfo->EffectMiscValue[i]);
		summon->SetInstanceID(m_caster->GetInstanceID());
		summon->CreateAsSummon(m_spellInfo->EffectMiscValue[i], ci, NULL, p_caster, m_spellInfo, 1, 45000);
		summon->SetUInt32Value(UNIT_FIELD_LEVEL, p_caster->getLevel());
		summon->AddSpell(dbcSpell.LookupEntry(31707), true, false); //dont need to send the spell packet yet
		summon->AddSpell(dbcSpell.LookupEntry(33395), true, true); //now we can send it
		summon->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, p_caster->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE));
		summon->_setFaction();
		if(p_caster->IsPvPFlagged())
			summon->SetPvPFlag();
		if( m_summonProperties->Slot < 7 )
		{
			//record our owner guid and slotid
			summon->SetSummonOwnerSlot(p_caster->GetGUID(),m_summonProperties->Slot);
			p_caster->m_SummonSlots[ m_summonProperties->Slot ] = summon;
		}
	}
	else
	{
		float x, y, z;
		if( m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION && m_targets.m_destX && m_targets.m_destY && m_targets.m_destZ )
		{
			x = m_targets.m_destX;
			y = m_targets.m_destY;
			z = m_targets.m_destZ;
		}
		else
		{
			x = u_caster->GetPositionX();
			y = u_caster->GetPositionY();
			z = u_caster->GetPositionZ();
		}
		uint32 health = 0;
		uint32 count = m_spellInfo->EffectBasePoints[i] + 1;
		if( m_summonProperties->Flags & 2 ) // one, please.
		{
			count = 1;
			health = m_spellInfo->EffectBasePoints[i] + 1;
		}

		for (uint32 j=0; j<count; j++)
		{
			float m_fallowAngle=-((float(M_PI)/2)*j);
			x += (GetRadius(i)*(cosf(m_fallowAngle+u_caster->GetOrientation())));
			y += (GetRadius(i)*(sinf(m_fallowAngle+u_caster->GetOrientation())));

			Creature* pCreature = NULL;
			pCreature = p_caster->GetMapMgr()->CreateCreature(cp->Id);
			if(pCreature == NULL)
				continue;
			pCreature->Load(cp, x, y, z, p_caster->GetOrientation());
			if(health)
			{
				pCreature->SetUInt32Value(UNIT_FIELD_MAXHEALTH, health);
				pCreature->SetUInt32Value(UNIT_FIELD_HEALTH, health);
			}
			pCreature->_setFaction();
			pCreature->GetAIInterface()->Init(pCreature,AITYPE_PET,MOVEMENTTYPE_NONE,u_caster);
			pCreature->GetAIInterface()->SetUnitToFollow(u_caster);
			pCreature->GetAIInterface()->SetUnitToFollowAngle(float(-(M_PI/2)));
			pCreature->GetAIInterface()->SetFollowDistance(3.0f);
			pCreature->SetUInt32Value(UNIT_FIELD_LEVEL, p_caster->getLevel());
			pCreature->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, p_caster->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE));
			pCreature->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, p_caster->GetGUID());
			pCreature->_setFaction();
			p_caster->SetUInt64Value(UNIT_FIELD_SUMMON, pCreature->GetGUID());

			if( m_summonProperties->Slot < 7 )
			{
				//record our owner guid and slotid
				pCreature->SetSummonOwnerSlot(p_caster->GetGUID(),m_summonProperties->Slot);
				p_caster->m_SummonSlots[ m_summonProperties->Slot ] = pCreature;
			}

			if ( m_spellInfo->EffectMiscValue[i] == 19668 ) //shadowfiend
			{
				float parent_bonus = (float)(p_caster->GetDamageDoneMod(SCHOOL_SHADOW)*0.065f);
				pCreature->SetFloatValue(UNIT_FIELD_MINDAMAGE, pCreature->GetFloatValue(UNIT_FIELD_MINDAMAGE) + parent_bonus);
				pCreature->SetFloatValue(UNIT_FIELD_MAXDAMAGE, pCreature->GetFloatValue(UNIT_FIELD_MAXDAMAGE) + parent_bonus);
				pCreature->BaseDamage[0] += parent_bonus;
				pCreature->BaseDamage[1] += parent_bonus;
			}		

			pCreature->PushToWorld(p_caster->GetMapMgr());
			sEventMgr.AddEvent(pCreature, &Creature::DeleteMe, EVENT_CREATURE_REMOVE_CORPSE, GetDuration(), 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
		}
	}
}

void Spell::SummonTotem(uint32 i) // Summon Totem
{
	if(p_caster== NULL)  
		return;

	uint32 entry = m_spellInfo->EffectMiscValue[i];

	CreatureInfo* ci = CreatureNameStorage.LookupEntry(entry);
	if(!ci)
	{
		OUT_DEBUG("Missing totem creature entry : %u \n",entry);
		return;
	}

	// Obtain the spell we will be casting.
	SpellEntry * TotemSpell = ObjectMgr::getSingleton().GetTotemSpell(m_spellInfo->Id);
	if(TotemSpell == 0) 
	{
		OUT_DEBUG("Totem %u does not have any spells to cast, exiting\n",entry);
		return;
	}

	Creature* pTotem = NULL;
	pTotem = p_caster->GetMapMgr()->CreateCreature(entry);
	if(pTotem == NULL)
		return;

	float x = p_caster->GetPositionX();
	float y = p_caster->GetPositionY();
	uint32 slot = m_summonProperties->Slot;

	switch(m_spellInfo->EffectMiscValueB[i])
	{
	case SUMMON_TYPEID_TOTEM_1: 
		{
			x -= 1.5f;
			y -= 1.5f;
		}break;
	case SUMMON_TYPEID_TOTEM_2: 
		{
			x -= 1.5f;
			y += 1.5f;
		}break;
	case SUMMON_TYPEID_TOTEM_3:  
		{
			x += 1.5f;
			y -= 1.5f;
		}break;
	case SUMMON_TYPEID_TOTEM_4: 
		{
			x += 1.5f;
			y += 1.5f;
		}break;
	}
	//1.5 distance from caster only, don't bother getting height (it's unreliable since 3xx anyway).
	float landh = p_caster->GetPositionZ() + 1.5f;

	//We already emptied this slot in SpellEffectSummon
	if( slot < 7 )
		p_caster->m_SummonSlots[slot] = pTotem;

	//record our owner guid and slotid
	pTotem->SetSummonOwnerSlot(u_caster->GetGUID(),int8(slot));

	//Make it a Totem
	pTotem->SetTotem(true);

	pTotem->Create(ci->Name, p_caster->GetMapId(), x, y, landh, p_caster->GetOrientation());

	uint32 displayID = 0;

	if( p_caster->GetTeam() == 0 )
	{
		if ( ci->Female_DisplayID != 0 )
		{
			displayID = ci->Female_DisplayID; //this is the nice solution provided by emsy
		}
		else //this is the case when you are using a blizzlike db
		{
			if( ci->Male_DisplayID == 4587 )
				displayID = 19075;
			else if( ci->Male_DisplayID == 4588 )
				displayID = 19073;
			else if( ci->Male_DisplayID == 4589 )
				displayID = 19074;
			else if( ci->Male_DisplayID == 4590 )
				displayID = 19071;
			else if( ci->Male_DisplayID == 4683 )
				displayID = 19074;
			else
				displayID = ci->Male_DisplayID;
		}
	}
	else
	{
		displayID = ci->Male_DisplayID;
	}

	// Set up the creature.
	pTotem->SetUInt32Value(OBJECT_FIELD_ENTRY, entry);
	pTotem->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
	pTotem->SetUInt64Value(UNIT_FIELD_CREATEDBY, p_caster->GetGUID());
	pTotem->SetUInt32Value(UNIT_FIELD_HEALTH, damage > 1 ? damage: 5 );
	pTotem->SetUInt32Value(UNIT_FIELD_MAXHEALTH, damage > 1 ? damage: 5);
	pTotem->SetUInt32Value(UNIT_FIELD_POWER3, p_caster->getLevel() * 30);
	pTotem->SetUInt32Value(UNIT_FIELD_MAXPOWER3, p_caster->getLevel() * 30);
	pTotem->SetUInt32Value(UNIT_FIELD_LEVEL, p_caster->getLevel());
	pTotem->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, p_caster->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE));
	pTotem->SetUInt32Value(UNIT_FIELD_BYTES_0, (1 << 8) | (2 << 16) | (1 << 24));
	pTotem->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE | UNIT_FLAG_SELF_RES);
	pTotem->SetUInt32Value(UNIT_FIELD_BASEATTACKTIME, 2000);
	pTotem->SetUInt32Value(UNIT_FIELD_RANGEDATTACKTIME, 2000);
	pTotem->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 1.0f);
	pTotem->SetFloatValue(UNIT_FIELD_COMBATREACH, 1.0f);
	pTotem->SetUInt32Value(UNIT_FIELD_DISPLAYID, displayID);
	pTotem->SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, ci->Male_DisplayID); //blizzlike :P
	pTotem->SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);
	pTotem->SetUInt32Value(UNIT_CREATED_BY_SPELL, m_spellInfo->Id);
	if( p_caster->IsPvPFlagged() )
		pTotem->SetPvPFlag();

	if( p_caster->IsFFAPvPFlagged() )
		pTotem->SetFFAPvPFlag();

	// Initialize faction stuff.
	pTotem->m_faction = p_caster->m_faction;
	pTotem->m_factionDBC = p_caster->m_factionDBC;

	//added by Zack : Some shaman talents are casted on player but it should be inherited or something by totems
	pTotem->InheritSMMods(p_caster);
	// Totems get spell damage and healing bonus from the Shaman
	for(int school=0;school<7;school++){
		pTotem->ModDamageDone[school] = (int32)(p_caster->GetUInt32Value( PLAYER_FIELD_MOD_DAMAGE_DONE_POS + school ) - (int32)p_caster->GetUInt32Value( PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + school ));
		pTotem->HealDoneMod[school] = p_caster->HealDoneMod[school];
	}

	// Set up AI, depending on our spells.
	uint32 j;
	for( j = 0; j < 3; ++j )
	{
		if( TotemSpell->Effect[j] == SPELL_EFFECT_APPLY_GROUP_AREA_AURA || TotemSpell->Effect[j] == SPELL_EFFECT_PERSISTENT_AREA_AURA || TotemSpell->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_TRIGGER_SPELL )
		{
			break;
		}
	}
	// Setup complete. Add us to the world.
	pTotem->PushToWorld(m_caster->GetMapMgr());

	//And set expiring time
	sEventMgr.AddEvent( pTotem, &Creature::DeleteMe, EVENT_CREATURE_SAFE_DELETE, GetDuration(), 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT );

	if(j != 3)
	{
		// We're an area aura. Simple. Disable AI and cast the spell.
		pTotem->DisableAI();
		pTotem->GetAIInterface()->totemspell = m_spellInfo;

		Spell* pSpell(new Spell(pTotem, TotemSpell, true, NULL));

		SpellCastTargets targets;
		targets.m_destX = pTotem->GetPositionX();
		targets.m_destY = pTotem->GetPositionY();
		targets.m_destZ = pTotem->GetPositionZ();
		targets.m_targetMask = TARGET_FLAG_DEST_LOCATION;

		pSpell->prepare(&targets);

		if( TotemSpell->NameHash == SPELL_HASH_TOTEM_OF_WRATH )
			pTotem->CastSpell(pTotem, dbcSpell.LookupEntry(30708), true);
		else if( TotemSpell->NameHash == SPELL_HASH_FIRE_NOVA_TOTEM )
		{
			if( p_caster->HasDummyAura(SPELL_HASH_FIRE_NOVA_TOTEM) && Rand(p_caster->GetDummyAura(SPELL_HASH_FIRE_NOVA_TOTEM)->RankNumber * 50) )
				sEventMgr.AddEvent( TO_UNIT(pTotem), &Unit::EventCastSpell, TO_UNIT(pTotem), dbcSpell.LookupEntry(51880), EVENT_AURA_PERIODIC_TRIGGERSPELL, 4000, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT );
		}	
	}
	else
	{
		// We're a casting totem. Switch AI on, and tell it to cast this spell.
		pTotem->EnableAI();
		pTotem->GetAIInterface()->Init(pTotem, AITYPE_TOTEM, MOVEMENTTYPE_NONE, p_caster);
		pTotem->GetAIInterface()->totemspell = TotemSpell;
		int32 totemspelltimer = 3000, totemspelltime = 3000;	// need a proper resource for this.

		switch(TotemSpell->Id)
		{
		case 51975: //Poison Cleansing Totem
		case 52025: //Disease Cleansing Totem
			{
				totemspelltime =  5000;
				totemspelltimer = 0; //First tick done immediately
				break;
			}
		case 8146: //Tremor Totem
			{
				totemspelltime = 1000;	// not sure about correctness, but spell amplitude = 1000
				totemspelltimer = 0; //First tick done immediately
				break;
			}
		default:break;
		}
		switch(m_spellInfo->NameHash)
		{
		case SPELL_HASH_STONECLAW_TOTEM:
			{
				totemspelltime = 30000; // Should be casted only once
				totemspelltimer = 0; // Casted immediately
				break;
			}
		case SPELL_HASH_MAGMA_TOTEM:
		case SPELL_HASH_MANA_SPRING_TOTEM:
		case SPELL_HASH_HEALING_STREAM_TOTEM:
			{
				totemspelltimer = totemspelltime = 2000;
				break;
			}
		case SPELL_HASH_SEARING_TOTEM:
			{
				totemspelltimer = totemspelltime = 2200;
				break;
			}
		default:break;
		}

		pTotem->GetAIInterface()->m_totemspelltimer = totemspelltimer;
		pTotem->GetAIInterface()->m_totemspelltime = totemspelltime;
	}

	//in case these are our elemental totems then we should set them up
	switch (m_spellInfo->Id)
	{
	case 2062: //Earth Elemental Totem
		{
			pTotem->GetAIInterface()->Event_Summon_Elemental(GetDuration(), 15352, NATURE_DAMAGE, 0);
			pTotem->DisableAI();
		}break;
	case 2894://Fire Elemental Totem
		{
			pTotem->GetAIInterface()->Event_Summon_Elemental(GetDuration(), 15438, FIRE_DAMAGE, 0);
			pTotem->DisableAI();
		}break;
	}

	if( p_caster != NULL)

	{
		WorldPacket data(SMSG_TOTEM_CREATED, 20);
		data << uint8(m_summonProperties->Slot - 1);
		data << pTotem->GetGUID();
		data << GetDuration();
		data << m_spellInfo->Id;
		p_caster->CopyAndSendDelayedPacket(&data);
	}
	
}

void Spell::SummonNonCombatPet(uint32 i)
{
	if( u_caster == NULL|| !u_caster->IsInWorld())
		return;

	uint32 SummonCritterID = m_spellInfo->EffectMiscValue[i];

	// m_spellInfo->EffectDieSides[i] has something to do with dismissing our critter
	// when it is 1, it means to just dismiss it if we already have it
	// when it is 0, it could mean to always summon a new critter, but there seems to be exceptions

	if(!SummonCritterID)
		return;

	CreatureInfo * ci = CreatureNameStorage.LookupEntry(SummonCritterID);
	CreatureProto * cp = CreatureProtoStorage.LookupEntry(SummonCritterID);

	if(!ci || !cp)
		return;

	Creature* pCreature = NULL;
	pCreature = u_caster->GetMapMgr()->CreateCreature(SummonCritterID);
	if(pCreature == NULL)
		return;
	pCreature->SetInstanceID(u_caster->GetMapMgr()->GetInstanceID());
	pCreature->Load(cp, m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetOrientation());
	pCreature->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 35);
	pCreature->_setFaction();
	pCreature->SetUInt32Value(UNIT_FIELD_LEVEL, 1);
	pCreature->GetAIInterface()->Init(pCreature,AITYPE_PET,MOVEMENTTYPE_NONE,u_caster);
	pCreature->GetAIInterface()->SetUnitToFollow(u_caster);
	pCreature->GetAIInterface()->SetUnitToFollowAngle(float(-(M_PI/2)));
	pCreature->GetAIInterface()->SetFollowDistance(3.0f);
	pCreature->GetAIInterface()->disable_melee = true;
	pCreature->bInvincible = true;
	pCreature->PushToWorld(u_caster->GetMapMgr());
	if( m_summonProperties->Slot < 7 )
	{
		pCreature->SetSummonOwnerSlot(u_caster->GetGUID(), m_summonProperties->Slot);
		u_caster->m_SummonSlots[ m_summonProperties->Slot ] = pCreature;
	}
}
/*
void Spell::SpellEffectLeap(uint32 i) // Leap
{
	if(unitTarget == NULL)
		return;
	float radius = GetRadius(i);
	unitTarget->RemoveAurasByInterruptFlag(AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN);

	NavMeshData* nav = CollideInterface.GetNavMesh(m_caster->GetMapId());

	if(nav != NULL)
	{
		float destx, desty, destz;
		unitTarget->GetPoint(unitTarget->GetOrientation(), radius, destx, desty, destz);
		if(playerTarget != NULL)
			playerTarget->SafeTeleport(playerTarget->GetMapId(), playerTarget->GetInstanceID(), LocationVector(destx, desty, destz, playerTarget->GetOrientation()));
		else if(unitTarget != NULL)
			unitTarget->GetAIInterface()->MoveTeleport(destx, desty, destz, unitTarget->GetOrientation());
	}
	else
	{
		if(playerTarget == NULL)  //let client handle this for players
			return;

		WorldPacket data(SMSG_MOVE_KNOCK_BACK, 50);
		data << playerTarget->GetNewGUID();
		data << getMSTime();
		data << cosf(playerTarget->GetOrientation()) << sinf(playerTarget->GetOrientation());
		data << radius;
		data << float(-10.0f);
		playerTarget->GetSession()->SendPacket(&data);
	}
}*/

void Spell::SpellEffectLeap(uint32 i) // Leap
{
    if (unitTarget == nullptr)
        return;
    float radius = GetRadius(i);
    unitTarget->RemoveAurasByInterruptFlag(AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN);

    MMAP::MMapManager* mmap = MMAP::MMapFactory::createOrGetMMapManager();
    dtNavMesh* nav = const_cast<dtNavMesh*>(mmap->GetNavMesh(m_caster->GetMapId()));
    dtNavMeshQuery* nav_query = const_cast<dtNavMeshQuery*>(mmap->GetNavMeshQuery(m_caster->GetMapId(), m_caster->GetInstanceID()));
    //NavMeshData* nav = CollideInterface.GetNavMesh(m_caster->GetMapId());

    if (nav != nullptr)
    {
        float destx, desty, destz;
        unitTarget->GetPoint(unitTarget->GetOrientation(), radius, destx, desty, destz);
        if (playerTarget != nullptr)
            playerTarget->SafeTeleport(playerTarget->GetMapId(), playerTarget->GetInstanceID(), LocationVector(destx, desty, destz, playerTarget->GetOrientation()));
        else if (unitTarget != nullptr)
            unitTarget->GetAIInterface()->MoveTeleport(destx, desty, destz, unitTarget->GetOrientation());
    }
    else
    {
        if (playerTarget == nullptr)  //let client handle this for players
            return;

        WorldPacket data(SMSG_MOVE_KNOCK_BACK, 50);
        data << playerTarget->GetNewGUID();
        data << getMSTime();
        data << cosf(playerTarget->GetOrientation());
        data << sinf(playerTarget->GetOrientation());
        data << radius;
        data << float(-10.0f);
        playerTarget->GetSession()->SendPacket(&data);
    }
}

void Spell::SpellEffectEnergize(uint32 i) // Energize
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	uint32 modEnergy = 0;
	switch(GetProto()->Id)
	{
		case 30824: // Shamanistic Rage
			modEnergy = damage * GetUnitTarget()->GetAP() / 100;
			break;
		case 31786: // Paladin - Spiritual Attunement
			if(ProcedOnSpell)
			{
				SpellEntry* motherspell = dbcSpell.LookupEntryForced(pSpellId);
				if(motherspell)
				{
					//heal amount from procspell (we only proceed on a heal spell)
					uint32 healamt = 0;
					if(ProcedOnSpell->Effect[0] == SPELL_EFFECT_HEAL || ProcedOnSpell->Effect[0] == SPELL_EFFECT_SCRIPT_EFFECT)
						healamt = ProcedOnSpell->EffectBasePoints[0] + 1;
					else if(ProcedOnSpell->Effect[1] == SPELL_EFFECT_HEAL || ProcedOnSpell->Effect[1] == SPELL_EFFECT_SCRIPT_EFFECT)
						healamt = ProcedOnSpell->EffectBasePoints[1] + 1;
					else if(ProcedOnSpell->Effect[2] == SPELL_EFFECT_HEAL || ProcedOnSpell->Effect[2] == SPELL_EFFECT_SCRIPT_EFFECT)
						healamt = ProcedOnSpell->EffectBasePoints[2] + 1;
					modEnergy = (motherspell->EffectBasePoints[0] + 1) * (healamt) / 100;
				}
			}
			break;
		case 57669:
			{
				modEnergy = float2int32(0.01f * unitTarget->GetUInt32Value(UNIT_FIELD_BASE_MANA));
			}
			break;
		case 31930:
			{
				if(u_caster)
					modEnergy = float2int32(0.25f * unitTarget->GetUInt32Value(UNIT_FIELD_BASE_MANA));
			}
			break;
		case 2687: // Improved Bloodrage, dirty fix
			{
				modEnergy = damage;
				if(p_caster)
				{
					if(p_caster->mSpells.find(12818) != p_caster->mSpells.end())
						modEnergy += 110; //60
					if(p_caster->mSpells.find(12301) != p_caster->mSpells.end())
						modEnergy += 60; //30
				}
			}
			break;
		default:
			modEnergy = damage;
			break;
	}

	if(unitTarget->HasAura(17619))
	{
		modEnergy = uint32(modEnergy * 1.4f);
	}

	u_caster->Energize(unitTarget, GetProto()->Id, modEnergy, GetProto()->EffectMiscValue[i]);
}

void Spell::SpellEffectWeaponDmgPerc(uint32 i) // Weapon Percent damage
{
	if(!unitTarget || !u_caster) return;

	if(GetType() == SPELL_DMG_TYPE_MAGIC)
	{
		uint32 dmg = CalculateDamage(u_caster, unitTarget, MELEE, 0, GetProto()) * damage / 100;
		u_caster->SpellNonMeleeDamageLog(unitTarget, GetProto()->Id, dmg, false, false, false);
	}
	else
	{
		uint32 _type;
		if(GetType() == SPELL_DMG_TYPE_RANGED)
			_type = RANGED;
		else
		{
			if(GetProto()->AttributesExC & 0x1000000)
				_type =  OFFHAND;
			else
				_type = MELEE;
		}

		u_caster->Strike(unitTarget, _type, GetProto(), add_damage, damage, 0, false, true);

		if(GetProto()->NameHash == SPELL_HASH_FAN_OF_KNIVES && p_caster != NULL)   // rogue - fan of knives
		{
			Item* oit = p_caster->GetItemInterface()->GetInventoryItem(EQUIPMENT_SLOT_OFFHAND);
			if(oit != NULL)
			{
				if(oit->GetDurability() != 0)
				{
					if(oit->GetProto()->Class == 2 && oit->GetProto()->SubClass == 15)   // daggers
						damage = 105; //causing 105% weapon damage with daggers
					else
						damage = GetProto()->EffectBasePoints[i] + 1;// and 70% weapon damage with all other weapons.

					u_caster->Strike(unitTarget, OFFHAND, GetProto(), add_damage, damage, 0, false, true);
				}
			}
		}
	}
}

void Spell::SpellEffectTriggerMissile(uint32 i) // Trigger Missile
{
	//Used by mortar team
	//Triggers area effect spell at destinatiom

	uint32 spellid = GetProto()->EffectTriggerSpell[i];
	if(spellid == 0)
	{
		LOG_ERROR("Spell %u ( %s ) has a trigger missle effect ( %u ) but no trigger spell ID. Spell needs fixing.", m_spellInfo->Id, m_spellInfo->Name, i);
		return;
	}

	SpellEntry* spInfo = dbcSpell.LookupEntryForced(spellid);
	if(spInfo == NULL)
	{
		LOG_ERROR("Spell %u ( %s ) has a trigger missle effect ( %u ) but has an invalid trigger spell ID. Spell needs fixing.", m_spellInfo->Id, m_spellInfo->Name, i);
		return;
	}

	// Cast the triggered spell on the destination location, spells like Freezing Arrow use it
	if((u_caster != NULL) && (m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION))
	{
		u_caster->CastSpellAoF(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, spInfo, true);
		return;
	}

	float spellRadius = GetRadius(i);

	// TODO: Following should be / is probably in SpellTarget code
	for(std::set<Object*>::iterator itr = m_caster->GetInRangeSetBegin(); itr != m_caster->GetInRangeSetEnd(); itr++)
	{
		if(!((*itr)->IsUnit()) || !TO< Unit* >((*itr))->isAlive())
			continue;
		Unit* t = TO< Unit* >((*itr));

		float r;
		float d = m_targets.m_destX - t->GetPositionX();
		r = d * d;
		d = m_targets.m_destY - t->GetPositionY();
		r += d * d;
		d = m_targets.m_destZ - t->GetPositionZ();
		r += d * d;

		if(sqrt(r) > spellRadius) continue;

		if(!isAttackable(m_caster, *itr))//Fix Me: only enemy targets?
			continue;

		Spell* sp = sSpellFactoryMgr.NewSpell(m_caster, spInfo, true, NULL);
		SpellCastTargets tgt;
		tgt.m_unitTarget = (*itr)->GetGUID();
		sp->prepare(&tgt);
	}
}

void Spell::SpellEffectOpenLock(uint32 i) // Open Lock
{
	if(!p_caster) return;

	uint8 loottype = 0;

	uint32 locktype = GetProto()->EffectMiscValue[i];
	switch(locktype)
	{
		case LOCKTYPE_PICKLOCK:
			{
				uint32 v = 0;
				uint32 lockskill = p_caster->_GetSkillLineCurrent(SKILL_LOCKPICKING);

				if(itemTarget)
				{
					if(!itemTarget->locked)
						return;

					Lock* lock = dbcLock.LookupEntryForced(itemTarget->GetProto()->LockId);
					if(!lock) return;
					for(int j = 0; j < LOCK_NUM_CASES; j++)
					{
						if(lock->locktype[j] == 2 && lock->minlockskill[j] && lockskill >= lock->minlockskill[j])
						{
							v = lock->minlockskill[j];
							itemTarget->locked = false;
							itemTarget->UnLock();
							DetermineSkillUp(SKILL_LOCKPICKING, v / 5);
							break;
						}
					}
				}
				else if(gameObjTarget)
				{
					GameObjectInfo* info = gameObjTarget->GetInfo();
					if(gameObjTarget->GetByte(GAMEOBJECT_BYTES_1, 0) == 0)
						return;

					Lock* lock = dbcLock.LookupEntry(info->SpellFocus);
					if(lock == 0)
						return;

					for(int j = 0; j < LOCK_NUM_CASES; j++)
					{
						if(lock->locktype[j] == 2 && lock->minlockskill[j] && lockskill >= lock->minlockskill[j])
						{
							v = lock->minlockskill[j];
							gameObjTarget->SetUInt32Value(GAMEOBJECT_FLAGS, 0);
							gameObjTarget->SetByte(GAMEOBJECT_BYTES_1, 0, 1);
							//Add Fill GO loot here
							if(gameObjTarget->loot.items.size() == 0)
							{
								if(gameObjTarget->GetMapMgr() != NULL)
									lootmgr.FillGOLoot(&gameObjTarget->loot, gameObjTarget->GetInfo()->sound1,  gameObjTarget->GetMapMgr()->iInstanceMode);
								else
									lootmgr.FillGOLoot(&gameObjTarget->loot, gameObjTarget->GetInfo()->sound1,  0);


								DetermineSkillUp(SKILL_LOCKPICKING, v / 5); //to prevent free skill up
							}
							loottype = LOOT_CORPSE;
							//End of it
							break;
						}
					}
				}
			}
			break;
		case LOCKTYPE_HERBALISM:
			{
				if(!gameObjTarget) return;

				uint32 v = gameObjTarget->GetGOReqSkill();
				bool bAlreadyUsed = false;

				if(Rand(100.0f)) // 3% chance to fail//why?
				{
					if(TO< Player* >(m_caster)->_GetSkillLineCurrent(SKILL_HERBALISM) < v)
					{
						//SendCastResult(SPELL_FAILED_LOW_CASTLEVEL);
						return;
					}
					else
					{
						if(gameObjTarget->loot.items.size() == 0)
						{
							if(gameObjTarget->GetMapMgr() != NULL)
								lootmgr.FillGOLoot(&gameObjTarget->loot, gameObjTarget->GetInfo()->sound1,  gameObjTarget->GetMapMgr()->iInstanceMode);
							else
								lootmgr.FillGOLoot(&gameObjTarget->loot, gameObjTarget->GetInfo()->sound1,  0);
						}
						else
							bAlreadyUsed = true;
					}
					loottype = LOOT_SKINNING;
				}
				else
				{
					SendCastResult(SPELL_FAILED_TRY_AGAIN);
				}
				//Skill up
				if(!bAlreadyUsed) //Avoid cheats with opening/closing without taking the loot
					DetermineSkillUp(SKILL_HERBALISM, v / 5);
			}
			break;
		case LOCKTYPE_MINING:
			{
				if(!gameObjTarget) return;

				uint32 v = gameObjTarget->GetGOReqSkill();
				bool bAlreadyUsed = false;

				if(Rand(100.0f))     // 3% chance to fail//why?
				{
					if(TO< Player* >(m_caster)->_GetSkillLineCurrent(SKILL_MINING) < v)
					{
						//SendCastResult(SPELL_FAILED_LOW_CASTLEVEL);
						return;
					}
					else if(gameObjTarget->loot.items.size() == 0)
					{
						if(gameObjTarget->GetMapMgr() != NULL)
							lootmgr.FillGOLoot(&gameObjTarget->loot, gameObjTarget->GetInfo()->sound1,  gameObjTarget->GetMapMgr()->iInstanceMode);
						else
							lootmgr.FillGOLoot(&gameObjTarget->loot, gameObjTarget->GetInfo()->sound1,  0);
					}
					else
						bAlreadyUsed = true;

					loottype = LOOT_SKINNING;
				}
				else
				{
					SendCastResult(SPELL_FAILED_TRY_AGAIN);
				}
				//Skill up
				if(!bAlreadyUsed) //Avoid cheats with opening/closing without taking the loot
					DetermineSkillUp(SKILL_MINING, v / 5);
			}
			break;
		case LOCKTYPE_SLOW_OPEN: // used for BG go's
			{
				if(!gameObjTarget) return;
				if(p_caster && p_caster->m_bg)
					if(p_caster->m_bg->HookSlowLockOpen(gameObjTarget, p_caster, this))
						return;

				uint32 spellid = !gameObjTarget->GetInfo()->Unknown1 ? 23932 : gameObjTarget->GetInfo()->Unknown1;
				SpellEntry* en = dbcSpell.LookupEntry(spellid);
				Spell* sp = sSpellFactoryMgr.NewSpell(p_caster, en, true, NULL);
				SpellCastTargets tgt;
				tgt.m_unitTarget = gameObjTarget->GetGUID();
				sp->prepare(&tgt);
				return;
			}
			break;
		case LOCKTYPE_QUICK_CLOSE:
			{
				if(!gameObjTarget) return;
				gameObjTarget->EventCloseDoor();
			}
			break;

		case LOCKTYPE_QUICK_OPEN:
			if( gameObjTarget == NULL )
				return;

			if( ( p_caster != NULL ) && ( p_caster->m_bg != NULL ) )
				p_caster->m_bg->HookQuickLockOpen( gameObjTarget, p_caster, this );

			// there is no break here on purpose

		default://not profession
			{
				if(!gameObjTarget)
					return;

				CALL_GO_SCRIPT_EVENT(gameObjTarget, OnActivate)(p_caster);
				CALL_INSTANCE_SCRIPT_EVENT(gameObjTarget->GetMapMgr(), OnGameObjectActivate)(gameObjTarget, p_caster);

				if(sQuestMgr.OnActivateQuestGiver(gameObjTarget, p_caster))
					return;

				if(sQuestMgr.OnGameObjectActivate(p_caster, gameObjTarget))
				{
					p_caster->UpdateNearbyGameObjects();
					return;
				}

				if(gameObjTarget->loot.items.size() == 0)
				{
					if(gameObjTarget->GetMapMgr() != NULL)
						lootmgr.FillGOLoot(&gameObjTarget->loot, gameObjTarget->GetInfo()->sound1,  gameObjTarget->GetMapMgr()->iInstanceMode);
					else
						lootmgr.FillGOLoot(&gameObjTarget->loot, gameObjTarget->GetInfo()->sound1,  0);
				}
				loottype = LOOT_CORPSE ;
			}
			break;
	};
	if(gameObjTarget && gameObjTarget->GetType() == GAMEOBJECT_TYPE_CHEST)
		TO< Player* >(m_caster)->SendLoot(gameObjTarget->GetGUID(), loottype, gameObjTarget->GetMapId());
}

void Spell::SpellEffectTransformItem(uint32 i)
{
	bool result;
	AddItemResult result2;

	if(!i_caster) return;
	uint32 itemid = GetProto()->EffectItemType[i];
	if(!itemid) return;

	//Save durability of the old item
	Player* owner = i_caster->GetOwner();
	uint32 dur = i_caster->GetDurability();

	result  = owner->GetItemInterface()->SafeFullRemoveItemByGuid(i_caster->GetGUID());
	if(!result)
	{
		//something went wrong if this happen, item doesn't exist, so it wasn't destroyed.
		return;
	}

	i_caster = NULL;

	Item* it = objmgr.CreateItem(itemid, owner);
	if(!it) return;

	it->SetDurability(dur);
	//additem

	//additem
	result2 = owner->GetItemInterface()->AddItemToFreeSlot(it);
	if(!result2) //should never get here
	{
		owner->GetItemInterface()->BuildInventoryChangeError(NULL, NULL, INV_ERR_BAG_FULL);
		it->DeleteMe();
	}
}

void Spell::SpellEffectApplyGroupAA(uint32 i)
{
	ApplyAA(i);
}

void Spell::SpellEffectLearnSpell(uint32 i) // Learn Spell
{
	if(playerTarget == 0 && unitTarget && unitTarget->IsPet()) // something's wrong with this logic here.
	{
		// bug in target map fill?
		//playerTarget = m_caster->GetMapMgr()->GetPlayer((uint32)m_targets.m_unitTarget);
		SpellEffectLearnPetSpell(i);
		return;
	}

	if(GetProto()->Id == 483 || GetProto()->Id == 55884)          // "Learning"
	{
		if(!i_caster || !p_caster) return;

		uint32 spellid = 0;
		for(int j = 0; j < 5; ++j)
		{
			if(i_caster->GetProto()->Spells[j].Trigger == LEARNING && i_caster->GetProto()->Spells[j].Id != 0)
			{
				spellid = i_caster->GetProto()->Spells[j].Id;
				break;
			}
		}

		if(!spellid || !dbcSpell.LookupEntryForced(spellid)) return;

		// learn me!
		p_caster->addSpell(spellid);

		// no normal handler
		return;
	}

	if(playerTarget)
	{
		/*if(u_caster && isHostile(playerTarget, u_caster))
		return;*/

		uint32 spellToLearn = GetProto()->EffectTriggerSpell[i];
		playerTarget->addSpell(spellToLearn);

		if(spellToLearn == 2575)   //hacky fix for mining from creatures
			playerTarget->addSpell(32606);

		if(spellToLearn == 2366)   //hacky fix for herbalism from creatures
			playerTarget->addSpell(32605);

		//smth is wrong here, first we add this spell to player then we may cast it on player...
		SpellEntry* spellinfo = dbcSpell.LookupEntry(spellToLearn);
		//remove specializations
		switch(spellinfo->Id)
		{
			case 26801: //Shadoweave Tailoring
				playerTarget->removeSpell(26798, false, false, 0); //Mooncloth Tailoring
				playerTarget->removeSpell(26797, false, false, 0); //Spellfire Tailoring
				break;
			case 26798: // Mooncloth Tailoring
				playerTarget->removeSpell(26801, false, false, 0); //Shadoweave Tailoring
				playerTarget->removeSpell(26797, false, false, 0); //Spellfire Tailoring
				break;
			case 26797: //Spellfire Tailoring
				playerTarget->removeSpell(26801, false, false, 0); //Shadoweave Tailoring
				playerTarget->removeSpell(26798, false, false, 0); //Mooncloth Tailoring
				break;
			case 10656: //Dragonscale Leatherworking
				playerTarget->removeSpell(10658, false, false, 0); //Elemental Leatherworking
				playerTarget->removeSpell(10660, false, false, 0); //Tribal Leatherworking
				break;
			case 10658: //Elemental Leatherworking
				playerTarget->removeSpell(10656, false, false, 0); //Dragonscale Leatherworking
				playerTarget->removeSpell(10660, false, false, 0); //Tribal Leatherworking
				break;
			case 10660: //Tribal Leatherworking
				playerTarget->removeSpell(10656, false, false, 0); //Dragonscale Leatherworking
				playerTarget->removeSpell(10658, false, false, 0); //Elemental Leatherworking
				break;
			case 28677: //Elixir Master
				playerTarget->removeSpell(28675, false, false, 0); //Potion Master
				playerTarget->removeSpell(28672, false, false, 0); //Transmutation Maste
				break;
			case 28675: //Potion Master
				playerTarget->removeSpell(28677, false, false, 0); //Elixir Master
				playerTarget->removeSpell(28672, false, false, 0); //Transmutation Maste
				break;
			case 28672: //Transmutation Master
				playerTarget->removeSpell(28675, false, false, 0); //Potion Master
				playerTarget->removeSpell(28677, false, false, 0); //Elixir Master
				break;
			case 20219: //Gnomish Engineer
				playerTarget->removeSpell(20222, false, false, 0); //Goblin Engineer
				break;
			case 20222: //Goblin Engineer
				playerTarget->removeSpell(20219, false, false, 0); //Gnomish Engineer
				break;
			case 9788: //Armorsmith
				playerTarget->removeSpell(9787, false, false, 0); //Weaponsmith
				playerTarget->removeSpell(17039, false, false, 0); //Master Swordsmith
				playerTarget->removeSpell(17040, false, false, 0); //Master Hammersmith
				playerTarget->removeSpell(17041, false, false, 0); //Master Axesmith
				break;
			case 9787: //Weaponsmith
				playerTarget->removeSpell(9788, false, false, 0); //Armorsmith
				break;
			case 17041: //Master Axesmith
				playerTarget->removeSpell(9788, false, false, 0); //Armorsmith
				playerTarget->removeSpell(17040, false, false, 0); //Master Hammersmith
				playerTarget->removeSpell(17039, false, false, 0); //Master Swordsmith
				break;
			case 17040: //Master Hammersmith
				playerTarget->removeSpell(9788, false, false, 0); //Armorsmith
				playerTarget->removeSpell(17039, false, false, 0); //Master Swordsmith
				playerTarget->removeSpell(17041, false, false, 0); //Master Axesmith
				break;
			case 17039: //Master Swordsmith
				playerTarget->removeSpell(9788, false, false, 0); //Armorsmith
				playerTarget->removeSpell(17040, false, false, 0); //Master Hammersmith
				playerTarget->removeSpell(17041, false, false, 0); //Master Axesmith
				break;
		}
		for(uint32 j = 0; j < 3; j++)
			if(spellinfo->Effect[j] == SPELL_EFFECT_WEAPON ||
			        spellinfo->Effect[j] == SPELL_EFFECT_PROFICIENCY ||
			        spellinfo->Effect[j] == SPELL_EFFECT_DUAL_WIELD)
			{
				Spell* sp = sSpellFactoryMgr.NewSpell(unitTarget, spellinfo, true, NULL);
				SpellCastTargets targets;
				targets.m_unitTarget = unitTarget->GetGUID();
				targets.m_targetMask = TARGET_FLAG_UNIT;
				sp->prepare(&targets);
				break;
			}
		return;
	}

	// if we got here... try via pet spells..
	SpellEffectLearnPetSpell(i);
}

void Spell::SpellEffectSpellDefense(uint32 i)
{
	//used to enable this ability. We use it all the time ...
}

void Spell::SpellEffectDispel(uint32 i) // Dispel
{
	if(u_caster == NULL || unitTarget == NULL)
		return;

	uint32 start, end;

	if(isAttackable(u_caster, unitTarget) || GetProto()->EffectMiscValue[i] == DISPEL_STEALTH)    // IsAttackable returns false for stealthed
	{
		start = MAX_POSITIVE_AURAS_EXTEDED_START;
		end = MAX_POSITIVE_AURAS_EXTEDED_END;
		if(unitTarget->SchoolImmunityList[GetProto()->School])
			return;
	}
	else
	{
		start = MAX_NEGATIVE_AURAS_EXTEDED_START;
		end = MAX_NEGATIVE_AURAS_EXTEDED_END;
	}

	Aura* aur;
	SpellEntry* aursp;
	std::list< uint32 > dispelledSpells;
	bool finish = false;

	for(uint32 x = start; x < end; x++)
		if(unitTarget->m_auras[x] != NULL)
		{
			bool AuraRemoved = false;
			aur = unitTarget->m_auras[x];
			aursp = aur->GetSpellProto();

			//Nothing can dispel resurrection sickness;
			if(!aur->IsPassive() && !(aursp->Attributes & ATTRIBUTES_IGNORE_INVULNERABILITY))
			{
				if(GetProto()->DispelType == DISPEL_ALL)
				{
					unitTarget->HandleProc(PROC_ON_PRE_DISPELL_AURA_VICTIM, u_caster , GetProto(), m_triggeredSpell, aursp->Id);

					dispelledSpells.push_back(aursp->Id);

					unitTarget->RemoveAura(aur);
					AuraRemoved = true;

					if(--damage <= 0)
						finish = true;
				}
				else if(aursp->DispelType == GetProto()->EffectMiscValue[i])
				{
					unitTarget->HandleProc(PROC_ON_PRE_DISPELL_AURA_VICTIM, u_caster , GetProto(), m_triggeredSpell, aursp->Id);

					dispelledSpells.push_back(aursp->Id);

					unitTarget->RemoveAllAuras(aursp->Id, aur->GetCasterGUID());
					AuraRemoved = true;

					if(--damage <= 0)
						finish = true;
				}

				if(AuraRemoved)
				{
					if(aursp->NameHash == SPELL_HASH_UNSTABLE_AFFLICTION)
					{
						SpellEntry* spellInfo = dbcSpell.LookupEntry(31117);
						Spell* spell = sSpellFactoryMgr.NewSpell(u_caster, spellInfo, true, NULL);
						spell->forced_basepoints[0] = (aursp->EffectBasePoints[0] + 1) * 9;   //damage effect
						spell->ProcedOnSpell = GetProto();
						spell->pSpellId = aursp->Id;
						SpellCastTargets targets;
						targets.m_unitTarget = u_caster->GetGUID();
						spell->prepare(&targets);
					}
					/*else if ( aur->GetSpellProto()->NameHash == SPELL_HASH_LIFEBLOOM )
					{
					Spell* spell= sSpellFactoryMgr.NewSpell(aur->GetCaster(), aur->GetSpellProto(), true, NULL);
					spell->SetUnitTarget( unitTarget );
					spell->Heal( aur->mod->m_amount );
					}*/
				}
			}
			if(finish)
				break;
		}

	// send spell dispell log packet
	if(!dispelledSpells.empty())
	{
		WorldPacket data(SMSG_SPELLDISPELLOG, 25 + dispelledSpells.size() * 5);
		data << m_caster->GetNewGUID();
		data << unitTarget->GetNewGUID();
		data << GetProto()->Id;
		data << uint8(0);				// unused
		data << uint32(dispelledSpells.size());
		for(std::list< uint32 >::iterator itr = dispelledSpells.begin(); itr != dispelledSpells.end(); ++itr)
		{
			data << uint32(*itr);		// dispelled spell id
			data << uint8(0);			// 0 = dispelled, else cleansed
		}

		m_caster->SendMessageToSet(&data, true);
	}
}

void Spell::SpellEffectLanguage(uint32 i)
{
	if(!playerTarget || !GetProto()->EffectMiscValue[i])
		return;

	uint32 skills[15][2] =
	{
		{ 0, 0 },
		{ SKILL_LANG_ORCISH, 669 },
		{ SKILL_LANG_DARNASSIAN, 671 },
		{ SKILL_LANG_TAURAHE, 670 },
		{ SKILL_LANG_DWARVEN, 672 },
		{ SKILL_LANG_COMMON, 668 },
		{ SKILL_LANG_DEMON_TONGUE, 815 },
		{ SKILL_LANG_TITAN, 816 },
		{ SKILL_LANG_THALASSIAN, 813 },
		{ SKILL_LANG_DRACONIC, 814 },
		{ 0, 0 },
		{ SKILL_LANG_GNOMISH, 7340 },
		{ SKILL_LANG_TROLL, 7341 },
		{ SKILL_LANG_GUTTERSPEAK, 17737 },
		{ SKILL_LANG_DRAENEI, 29932 },
	};

	if(skills[GetProto()->EffectMiscValue[i]][0])
	{
		playerTarget->_AddSkillLine(skills[GetProto()->EffectMiscValue[i]][0], 300, 300);
		playerTarget->addSpell(skills[GetProto()->EffectMiscValue[i]][1]);
	}
}

void Spell::SpellEffectDualWield(uint32 i)
{
	if(p_caster == NULL)
		return;

	if(!p_caster->_HasSkillLine(SKILL_DUAL_WIELD))
		p_caster->_AddSkillLine(SKILL_DUAL_WIELD, 1, 1);

	// Increase it by one
	//dual wield is 1/1 , it never increases it's not even displayed in skills tab
}

void Spell::SpellEffectSkillStep(uint32 i) // Skill Step
{
	Player* target;
	if(p_caster == NULL)
	{
		// Check targets
		if(m_targets.m_unitTarget)
		{
			target = objmgr.GetPlayer((uint32)m_targets.m_unitTarget);
			if(!target) return;
		}
		else return;
	}
	else
	{
		target = p_caster;
	}

	uint32 skill = GetProto()->EffectMiscValue[i];
	if(skill == 242)
		skill = SKILL_LOCKPICKING; // somehow for lockpicking misc is different than the skill :s

	skilllineentry* sk = dbcSkillLine.LookupEntryForced(skill);

	if(!sk) return;

	uint32 max = 1;
	switch(sk->type)
	{
		case SKILL_TYPE_PROFESSION:
		case SKILL_TYPE_SECONDARY:
			max = damage * 75;
			break;
		case SKILL_TYPE_WEAPON:
			max = 5 * target->getLevel();
			break;
		case SKILL_TYPE_CLASS:
		case SKILL_TYPE_ARMOR:
			if(skill == SKILL_LOCKPICKING) { max = damage * 75; }
			else { max = 1; }
			break;
		default: //u cant learn other types in game
			return;
	};

	if(target->_HasSkillLine(skill))
	{
		target->_ModifySkillMaximum(skill, max);
	}
	else
	{
		// Don't add skills to players logging in.
		/*if((GetProto()->Attributes & 64) && playerTarget->m_TeleportState == 1)
		return;*/

		if(sk->type == SKILL_TYPE_PROFESSION)
			target->ModPrimaryProfessionPoints(-1);

		if(skill == SKILL_RIDING)
			target->_AddSkillLine(skill, max, max);
		else
			target->_AddSkillLine(skill, 1, max);
	}
}

void Spell::SpellEffectAddHonor(uint32 i)
{
	if(!playerTarget) return;

	uint32 val = GetProto()->EffectBasePoints[i];

	if(GetProto()->AttributesExB & ATTRIBUTESEXB_UNK4) val /= 10;

	val += 1;

	HonorHandler::AddHonorPointsToPlayer(playerTarget, val);

	WorldPacket data(SMSG_PVP_CREDIT, 16);
	data << val;
	data << uint64(0);
	data << uint32(5);
	playerTarget->GetSession()->SendPacket(&data);
}

void Spell::SpellEffectSpawn(uint32 i)
{
	// this effect is mostly for custom teleporting
	switch(GetProto()->Id)
	{
		case 10418: // Arugal spawn-in spell , teleports it to 3 locations randomly sneaking players (bastard ;P)
			{
				//only Creature can cast this spell
				if(u_caster == NULL || p_caster != NULL)
					return;

				static float coord[3][3] = {{ -108.9034f, 2129.5678f, 144.9210f}, { -108.9034f, 2155.5678f, 155.678f}, { -77.9034f, 2155.5678f, 155.678f}};

				int j = rand() % 3;
				//u_caster->GetAIInterface()->SendMoveToPacket(coord[j][0],coord[j][1],coord[j][2],0.0f,0,u_caster->GetAIInterface()->getMoveFlags());
			}
	}
}

void Spell::SpellEffectSummonObject(uint32 i)
{
	if(!u_caster) return;

	uint32 entry = GetProto()->EffectMiscValue[i];

	uint32 mapid = u_caster->GetMapId();
	float px = u_caster->GetPositionX();
	float py = u_caster->GetPositionY();
	float pz = u_caster->GetPositionZ();
	float orient = m_caster->GetOrientation();
	float posx = 0, posy = 0, posz = 0;

	if  (entry == 29076 && p_caster)
	{
		GameObject* go = m_caster->GetMapMgr()->CreateGameObject(191144);

		go->CreateFromProto(191144, mapid, posx, posy, pz, orient);
		go->SetByte(GAMEOBJECT_BYTES_1, 0, 1);
		go->SetUInt64Value(OBJECT_FIELD_CREATED_BY, m_caster->GetGUID());
		go->Phase(PHASE_SET, u_caster->GetPhase());
	//	go->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.65f); // trinity or
		go->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.50f);
		go->PushToWorld(m_caster->GetMapMgr());
		sEventMgr.AddEvent(go, &GameObject::ExpireAndDelete, EVENT_GAMEOBJECT_EXPIRE, GetDuration(), 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);

	}
	else if(entry == GO_FISHING_BOBBER && p_caster)
	{
		float co = cos(orient);
		float si = sin(orient);
		MapMgr* map = m_caster->GetMapMgr();
		Spell* spell = u_caster->GetCurrentSpell();

		float r;
		for(r = 20; r > 10; r--)
		{
			posx = px + r * co;
			posy = py + r * si;
			uint32 liquidtype;
			map->GetLiquidInfo(posx, posy, pz + 2, posz, liquidtype);
			if(!(liquidtype & 1))//water
				continue;
			if(posz > map->GetLandHeight(posx, posy, pz + 2))  //water
				break;
		}

		posx = px + r * co;
		posy = py + r * si;

		// Todo / Fix me: This should be loaded / cached
		uint32 zone = p_caster->GetAreaID();
		if(zone == 0)   // If the player's area ID is 0, use the zone ID instead
			zone = p_caster->GetZoneId();

		uint32 minskill;
		FishingZoneEntry* fishentry = FishingZoneStorage.LookupEntry(zone);
		if(!fishentry)   // Check database if there is fishing area / zone information, if not, return
			return;

		// Todo / Fix me: Add fishskill to the calculations
		minskill = fishentry->MinSkill;
		spell->SendChannelStart(20000);   // 30 seconds
		/*spell->SendSpellStart();
		spell->SendCastResult(SPELL_CANCAST_OK);
		spell->SendSpellGo ();*/

		GameObject* go = u_caster->GetMapMgr()->CreateGameObject(GO_FISHING_BOBBER);

		go->CreateFromProto(GO_FISHING_BOBBER, mapid, posx, posy, posz, orient);
		go->SetUInt32Value(GAMEOBJECT_FLAGS, 0);
		go->SetByte(GAMEOBJECT_BYTES_1, 0, 0);
		go->SetUInt64Value(OBJECT_FIELD_CREATED_BY, m_caster->GetGUID());
		u_caster->SetChannelSpellTargetGUID(go->GetGUID());
		go->Phase(PHASE_SET, u_caster->GetPhase());

		go->PushToWorld(m_caster->GetMapMgr());

		if(lootmgr.IsFishable(zone))     // Only set a 'splash' if there is any loot in this area / zone
		{
			uint32 seconds[] = { 0, 4, 10, 14 };
			uint32 rnd = RandomUInt(3);
			sEventMgr.AddEvent(go, &GameObject::FishHooked, TO< Player* >(m_caster), EVENT_GAMEOBJECT_FISH_HOOKED, seconds[ rnd ] * 1000, 1, 0);
		}
		sEventMgr.AddEvent(go, &GameObject::EndFishing, TO< Player* >(m_caster), false, EVENT_GAMEOBJECT_END_FISHING, 17 * 1000, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
		p_caster->SetSummonedObject(go);
	}
	else
	{
		posx = px;
		posy = py;
		GameObjectInfo* goI = GameObjectNameStorage.LookupEntry(entry);
		if(!goI)
		{
			if(p_caster)
			{
				sChatHandler.BlueSystemMessage(p_caster->GetSession(), "non-existent gameobject %u tried to be created by SpellEffectSummonObject. Report to devs!", entry);
			}
			return;
		}
		if(m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION && m_targets.m_destX && m_targets.m_destY && m_targets.m_destZ)
		{
			posx = m_targets.m_destX;
			posy = m_targets.m_destY;
			pz = m_targets.m_destZ;
		}
		GameObject* go = m_caster->GetMapMgr()->CreateGameObject(entry);

		go->CreateFromProto(entry, mapid, posx, posy, pz, orient);
		go->SetByte(GAMEOBJECT_BYTES_1, 0, 1);
		go->SetUInt64Value(OBJECT_FIELD_CREATED_BY, m_caster->GetGUID());
		go->Phase(PHASE_SET, u_caster->GetPhase());
		go->PushToWorld(m_caster->GetMapMgr());
		sEventMgr.AddEvent(go, &GameObject::ExpireAndDelete, EVENT_GAMEOBJECT_EXPIRE, GetDuration(), 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
		if(entry == 17032 && p_caster)   // this is a portal
		{
			// enable it for party only
			go->SetByte(GAMEOBJECT_BYTES_1, 0, 0);
			//disable by default
			WorldPacket* pkt = go->BuildFieldUpdatePacket(GAMEOBJECT_BYTES_1, 1 << 24);
			SubGroup* pGroup = p_caster->GetGroup() ? p_caster->GetGroup()->GetSubGroup(p_caster->GetSubGroup()) : NULL;

			if(pGroup)
			{
				p_caster->GetGroup()->Lock();
				for(GroupMembersSet::iterator itr = pGroup->GetGroupMembersBegin(); itr != pGroup->GetGroupMembersEnd(); ++itr)
				{
					if((*itr)->m_loggedInPlayer && m_caster != (*itr)->m_loggedInPlayer)
						(*itr)->m_loggedInPlayer->GetSession()->SendPacket(pkt);
				}
				p_caster->GetGroup()->Unlock();
			}
			delete pkt;
		}
		else if(entry == 36727 || entry == 177193 || entry == 194108)    // Portal of Summoning and portal of doom
		{
			if(!p_caster) return;

			//Player * pTarget = p_caster->GetMapMgr()->GetPlayer( p_caster->GetSelection() );
			Player* pTarget = objmgr.GetPlayer((uint32)p_caster->GetSelection());
			if(!pTarget || !pTarget->IsInWorld())
				return;
			go->m_ritualmembers[0] = p_caster->GetLowGUID();
			go->m_ritualcaster = p_caster->GetLowGUID();
			go->m_ritualtarget = pTarget->GetLowGUID();
			go->m_ritualspell = static_cast<uint16>(GetProto()->Id);
		}
		else if(entry == 186811 || entry == 181622)    // ritual of refreshment, ritual of souls
		{
			if(!p_caster) return;

			go->m_ritualmembers[0] = p_caster->GetLowGUID();
			go->m_ritualcaster = p_caster->GetLowGUID();
			go->m_ritualtarget = 0;
			go->m_ritualspell = static_cast<uint16>(GetProto()->Id);
		}
		else if(entry == 186812 || entry == 181621)    // Refreshment Table, Soulwell
		{
			go->charges = goI->sound1;
		}
		else//Lightwell,if there is some other type -- add it
		{
			go->charges = 5;//Max 5 charges
		}
		if(p_caster)
			p_caster->SetSummonedObject(go);//p_caster
	}
}

void Spell::SpellEffectEnchantItem(uint32 i) // Enchant Item Permanent
{
	if(!itemTarget || !p_caster)
		return;

	// Vellums
	if(GetProto()->EffectItemType[i] && (itemTarget->GetEntry() == 39349 ||
	                                     itemTarget->GetEntry() == 39350 || itemTarget->GetEntry() == 43146 ||
	                                     itemTarget->GetEntry() == 38682 || itemTarget->GetEntry() == 37602 ||
	                                     itemTarget->GetEntry() == 43145))
	{
		uint32 itemid = GetProto()->EffectItemType[i];
		ItemPrototype* it = ItemPrototypeStorage.LookupEntry(itemid);
		if(it == NULL)
		{
			p_caster->GetSession()->SystemMessage("Item is missing, report this to devs. Entry: %u", itemid);
			return;
		}

		Item* pItem = objmgr.CreateItem(itemid, p_caster);
		if(pItem == NULL)
			return;

		p_caster->GetItemInterface()->RemoveItemAmt(itemTarget->GetEntry(), 1);
		p_caster->GetItemInterface()->AddItemToFreeSlot(pItem);

		return;
	}

	EnchantEntry* Enchantment = dbcEnchant.LookupEntryForced(GetProto()->EffectMiscValue[i]);

	if(!Enchantment)
	{
		LOG_ERROR("Invalid enchantment entry %u for Spell %u", GetProto()->EffectMiscValue[ i ], GetProto()->Id);
		return;
	}

	if(p_caster->GetSession()->GetPermissionCount() > 0)
		sGMLog.writefromsession(p_caster->GetSession(), "enchanted item for %s", itemTarget->GetOwner()->GetName());

	//remove other perm enchantment that was enchanted by profession
	itemTarget->RemoveProfessionEnchant();
	int32 Slot = itemTarget->AddEnchantment(Enchantment, 0, true, true, false, 0);
	if(Slot < 0)
		return; // Apply failed

	if(!i_caster)
		DetermineSkillUp();
}

void Spell::SpellEffectEnchantItemTemporary(uint32 i)  // Enchant Item Temporary
{
	if((itemTarget == NULL) || (p_caster == NULL))
		return;

	uint32 Duration = m_spellInfo->EffectBasePoints[ i ];
	uint32 EnchantmentID = m_spellInfo->EffectMiscValue[ i ];

	// don't allow temporary enchants unless we're the owner of the item
	if(itemTarget->GetOwner() != p_caster)
		return;

	if(Duration == 0)
	{
		LOG_ERROR("Spell %u ( %s ) has no enchantment duration. Spell needs to be fixed!", m_spellInfo->Id, m_spellInfo->Name);
		return;
	}

	if(EnchantmentID == 0)
	{
		LOG_ERROR("Spell %u ( %s ) has no enchantment ID. Spell needs to be fixed!", m_spellInfo->Id, m_spellInfo->Name);
		return;
	}

	EnchantEntry* Enchantment = dbcEnchant.LookupEntryForced(EnchantmentID);
	if(Enchantment == NULL)
	{
		LOG_ERROR("Invalid enchantment entry %u for Spell %u", EnchantmentID, GetProto()->Id);
		return;
	}

	itemTarget->RemoveEnchantment(TEMP_ENCHANTMENT_SLOT);

	int32 Slot = itemTarget->AddEnchantment(Enchantment, Duration, false, true, false, TEMP_ENCHANTMENT_SLOT);
	if(Slot < 0)
		return; // Apply failed

	skilllinespell* skill = objmgr.GetSpellSkill(GetProto()->Id);
	if(skill != NULL)
		DetermineSkillUp(skill->skilline, itemTarget->GetProto()->ItemLevel);
}

void Spell::SpellEffectTameCreature(uint32 i)
{
	if(unitTarget == NULL || !unitTarget->IsCreature())
		return;
	Creature* tame = TO_CREATURE(unitTarget);

	// Remove target
	tame->GetAIInterface()->HandleEvent(EVENT_LEAVECOMBAT, p_caster, 0);
	Pet* pPet = objmgr.CreatePet(tame->GetEntry());
	if(! pPet->CreateAsSummon(tame->GetEntry(), tame->GetCreatureInfo(), tame, p_caster, NULL, 2, 0))
	{
		pPet->DeleteMe();//CreateAsSummon() returns false if an error occurred.
		pPet = NULL;
	}
	tame->Despawn(0, tame->GetProto()->RespawnTime);
}

void Spell::SpellEffectSummonPet(uint32 i) //summon - pet
{
	if(!p_caster) return;

	if(GetProto()->Id == 883)  // "Call Pet" spell
	{
		if(p_caster->GetSummon())
		{
			SendCastResult(SPELL_FAILED_ALREADY_HAVE_SUMMON);
			return;
		}

		uint32 petno = p_caster->GetUnstabledPetNumber();
		if(petno)
		{
			if(p_caster->GetPlayerPet(petno)->alive)
			{
				p_caster->SpawnPet(petno);
			}
			else
			{
				SendTameFailure(PETTAME_DEAD);
			}
		}
		else
		{
			SendCastResult(SPELL_FAILED_NO_PET);
		}
		return;
	}

	//uint32 entryId = GetProto()->EffectMiscValue[i];

	//VoidWalker:torment, sacrifice, suffering, consume shadows
	//Succubus:lash of pain, soothing kiss, seduce , lesser invisibility
	//felhunter:	 Devour Magic,Paranoia,Spell Lock,	Tainted Blood

	// remove old pet
	Pet* old = TO< Player* >(m_caster)->GetSummon();
	if(old)
		old->Dismiss();

	CreatureInfo* ci = CreatureNameStorage.LookupEntry(GetProto()->EffectMiscValue[i]);
	if(ci)
	{
		if(p_caster->getClass() == WARLOCK)
		{
			//if demonic sacrifice auras are still active, remove them
			p_caster->RemoveAura(18789);
			p_caster->RemoveAura(18790);
			p_caster->RemoveAura(18791);
			p_caster->RemoveAura(18792);
			p_caster->RemoveAura(35701);
		}

		Pet* summon = objmgr.CreatePet(GetProto()->EffectMiscValue[i]);
		if(! summon->CreateAsSummon(GetProto()->EffectMiscValue[i], ci, NULL, p_caster, GetProto(), 2, 0))
		{
			summon->DeleteMe();//CreateAsSummon() returns false if an error occurred.
			summon = NULL;
		}
	}
}

void Spell::SpellEffectLearnPetSpell(uint32 i)
{
	/*if(unitTarget && m_caster->GetTypeId() == TYPEID_PLAYER)
	{
	if(unitTarget->IsPet() && unitTarget->GetTypeId() == TYPEID_UNIT)
	{
	TO< Player* >(m_caster)->AddPetSpell(GetProto()->EffectTriggerSpell[i], unitTarget->GetEntry());
	}
	}*/

	if(unitTarget && unitTarget->IsPet() && p_caster)
	{
		Pet* pPet = TO< Pet* >(unitTarget);
		if(pPet->IsSummonedPet())
			p_caster->AddSummonSpell(unitTarget->GetEntry(), GetProto()->EffectTriggerSpell[i]);

		pPet->AddSpell(dbcSpell.LookupEntry(GetProto()->EffectTriggerSpell[i]), true);

		// Send Packet
		/*		WorldPacket data(SMSG_SET_EXTRA_AURA_INFO_OBSOLETE, 22);
		data << pPet->GetGUID() << uint8(0) << uint32(GetProto()->EffectTriggerSpell[i]) << uint32(-1) << uint32(0);
		p_caster->GetSession()->SendPacket(&data);*/
	}
}

void Spell::SpellEffectWeapondamage(uint32 i)   // Weapon damage +
{
	if(!unitTarget || !u_caster) return;

	//Hackfix for Mangle
	if(GetProto()->NameHash == SPELL_HASH_MANGLE__CAT_ && p_caster != NULL)
		p_caster->AddComboPoints(unitTarget->GetGUID(), 1);

	// Hacky fix for druid spells where it would "double attack".
	if(GetProto()->Effect[2] == SPELL_EFFECT_WEAPON_PERCENT_DAMAGE || GetProto()->Effect[1] == SPELL_EFFECT_WEAPON_PERCENT_DAMAGE)
	{
		add_damage += damage;
		return;
	}

	uint32 _type;
	if(GetType() == SPELL_DMG_TYPE_RANGED)
		_type = RANGED;
	else
	{
		if(hasAttributeExC(FLAGS4_TYPE_OFFHAND))
			_type =  OFFHAND;
		else
			_type = MELEE;
	}
	u_caster->Strike(unitTarget, _type, GetProto(), damage, 0, 0, false, true);
}

void Spell::SpellEffectOpenLockItem(uint32 i)
{
	if(p_caster == NULL || i_caster == NULL)
		return;

	p_caster->HandleSpellLoot(i_caster->GetProto()->ItemId);
}

void Spell::SpellEffectProficiency(uint32 i)
{
	uint32 skill = 0;
	skilllinespell* skillability = objmgr.GetSpellSkill(GetProto()->Id);
	if(skillability)
		skill = skillability->skilline;
	skilllineentry* sk = dbcSkillLine.LookupEntryForced(skill);
	if(skill)
	{
		if(playerTarget)
		{
			if(playerTarget->_HasSkillLine(skill))
			{
				// Increase it by one
				// playerTarget->AdvanceSkillLine(skill);
			}
			else
			{
				// Don't add skills to players logging in.
				/*if((GetProto()->Attributes & 64) && playerTarget->m_TeleportState == 1)
				return;*/

				if(sk && sk->type == SKILL_TYPE_WEAPON)
					playerTarget->_AddSkillLine(skill, 1, 5 * playerTarget->getLevel());
				else
					playerTarget->_AddSkillLine(skill, 1, 1);
			}
		}
	}
}

void Spell::SpellEffectSendEvent(uint32 i) //Send Event
{
	//This is mostly used to trigger events on quests or some places

	if(sScriptMgr.CallScriptedDummySpell(m_spellInfo->Id, i, this))
		return;

	if(sScriptMgr.HandleScriptedSpellEffect(m_spellInfo->Id, i, this))
		return;

	sLog.outDetail("Spell ID: %u ( %s ) has a scripted effect ( %u ) but no handler for it.", m_spellInfo->Id, m_spellInfo->Name, i);

}

void Spell::SpellEffectPowerBurn(uint32 i) // power burn
{
	if(unitTarget == NULL || !unitTarget->isAlive() || unitTarget->GetPowerType() != POWER_TYPE_MANA)
		return;

	if(unitTarget->IsPlayer())
	{
		Player* mPlayer = TO< Player* >(unitTarget);
		if(mPlayer->IsInFeralForm())
			return;

		// Resilience - reduces the effect of mana drains by (CalcRating*2)%.
		damage = float2int32(damage * (1 - ((TO< Player* >(unitTarget)->CalcRating(PLAYER_RATING_MODIFIER_SPELL_CRIT_RESILIENCE) * 2) / 100.0f)));
	}
	int32 mult = damage;
	damage = mult * unitTarget->GetMaxPower(POWER_TYPE_MANA) / 100;
	if(m_caster->IsUnit())  //Spell ctor has ASSERT( m_caster != NULL ) so there's no need to add NULL checks, even if static analysis reports them.
	{
		Unit* caster = TO< Unit* >(m_caster);
		if((uint32) damage > caster->GetMaxPower(POWER_TYPE_MANA) * (mult * 2) / 100)
			damage = caster->GetMaxPower(POWER_TYPE_MANA) * (mult * 2) / 100;
	}

	int32 mana = (int32)min((int32)unitTarget->GetPower(POWER_TYPE_MANA), damage);

	unitTarget->ModPower(POWER_TYPE_MANA, -mana);

	m_caster->SpellNonMeleeDamageLog(unitTarget, GetProto()->Id, (uint32)(mana * GetProto()->EffectMultipleValue[i]), pSpellId == 0, true);
}

void Spell::SpellEffectThreat(uint32 i) // Threat
{
	if(!unitTarget || !unitTarget->isAlive() || !unitTarget->IsCreature())
		return;

	int32 amount = GetProto()->EffectBasePoints[i];
	if(GetProto()->SpellGroupType)
	{
		SM_FIValue(u_caster->SM_FMiscEffect, &amount, GetProto()->SpellGroupType);
		SM_PIValue(u_caster->SM_PMiscEffect, &amount, GetProto()->SpellGroupType);
	}

	bool chck = unitTarget->GetAIInterface()->modThreatByPtr(u_caster, amount);
	if(!chck)
		unitTarget->GetAIInterface()->AttackReaction(u_caster, 1, 0);
}

void Spell::SpellEffectClearQuest(uint32 i)
{
	if(playerTarget == NULL)
	{
		LOG_ERROR("Spell %u ( %s ) was not casted on Player, but Spell requires Player to be a target.", m_spellInfo->Id, m_spellInfo->Name);
		return;
	}

	uint32 questid1 = m_spellInfo->EffectBasePoints[ i ];
	uint32 questid2 = m_spellInfo->EffectMiscValue[ i ];

	playerTarget->ClearQuest(questid1);
	playerTarget->ClearQuest(questid2);
}

void Spell::SpellEffectTriggerSpell(uint32 i) // Trigger Spell
{
	SpellEntry* entry = dbcSpell.LookupEntryForced(GetProto()->EffectTriggerSpell[i]);
	if(entry == NULL)
		return;

	SpellCastTargets targets = m_targets;
	Spell* sp = sSpellFactoryMgr.NewSpell(m_caster, entry, m_triggeredSpell, NULL);
	sp->ProcedOnSpell = GetProto();
	sp->prepare(&targets);
}

void Spell::SpellEffectApplyRaidAA(uint32 i)
{
	ApplyAA(i);
}

void Spell::SpellEffectPowerFunnel(uint32 i) // Power Funnel
{
	if(!unitTarget || !unitTarget->isAlive() || !unitTarget->IsPet())
		return;

	//does not exist
}

void Spell::SpellEffectHealMaxHealth(uint32 i)   // Heal Max Health
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	uint32 dif = unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH) - unitTarget->GetUInt32Value(UNIT_FIELD_HEALTH);
	if(!dif)
	{
		SendCastResult(SPELL_FAILED_ALREADY_AT_FULL_HEALTH);
		return;
	}

	SendHealSpellOnPlayer(m_caster, unitTarget, dif, false, 0, pSpellId ? pSpellId : GetProto()->Id);

	unitTarget->ModHealth(dif);

	if(u_caster != NULL && this->GetProto()->NameHash == SPELL_HASH_LAY_ON_HANDS)
		u_caster->CastSpell(unitTarget, 25771, true);
}

void Spell::SpellEffectInterruptCast(uint32 i) // Interrupt Cast
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

    if (GetProto()->AttributesExG & SP_ATTR_EX_G_INTERRUPT_NPC && unitTarget->IsPlayer())
        return;

	if(!playerTarget)
	{
		if(u_caster && (u_caster != unitTarget))
		{
			unitTarget->GetAIInterface()->AttackReaction(u_caster, 1, m_spellInfo->Id);
			Creature* c = TO< Creature* >(unitTarget);
			if(c->GetProto()->modImmunities & 32768)
				return;
		}
	}

	Spell *TargetSpell = unitTarget->GetCurrentSpell(); // Get target's casting spell
	if(TargetSpell)
	{
		uint32 school = TargetSpell->GetProto()->School; // Get target's casting spell school
		int32 duration = GetDuration(); // Duration of school lockout

		// Check for CastingTime (to prevent interrupting instant casts), PreventionType
		// and InterruptFlags of target's casting spell
		if(school
			&& (TargetSpell->getState() == SPELL_STATE_CASTING
			|| (TargetSpell->getState() == SPELL_STATE_PREPARING && TargetSpell->GetProto()->CastingTimeIndex > 0))
			&& TargetSpell->GetProto()->PreventionType == PREVENTION_TYPE_SILENCE
			&& ((TargetSpell->GetProto()->InterruptFlags & CAST_INTERRUPT_ON_INTERRUPT_SCHOOL)
			|| (TargetSpell->GetProto()->ChannelInterruptFlags & CHANNEL_INTERRUPT_ON_4 )))
		{
			if(unitTarget->IsPlayer())
			{
				// Check for interruption reducing talents
				int32 DurationModifier = TO< Player* >(unitTarget)->MechanicDurationPctMod[MECHANIC_INTERRUPTED];
				if(DurationModifier >= - 100)
					duration = (duration * (100 + DurationModifier)) / 100;

				// Prevent player from casting in that school
				TO_PLAYER(unitTarget)->SendPreventSchoolCast(school, duration);
			}
			else
				// Prevent unit from casting in that school
				unitTarget->SchoolCastPrevent[school] = duration + getMSTime();

			TargetSpell->cancel(); // Interrupt the spell cast
		}
	}
}

void Spell::SpellEffectDistract(uint32 i) // Distract
{
	//spellId 1725 Distract:Throws a distraction attracting the all monsters for ten sec's
	if(!unitTarget || !unitTarget->isAlive())
		return;

	if(m_targets.m_destX != 0.0f || m_targets.m_destY != 0.0f || m_targets.m_destZ != 0.0f)
	{
		//		unitTarget->GetAIInterface()->MoveTo(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, 0);
		uint32 Stare_duration = GetDuration();
		if(Stare_duration > 30 * 60 * 1000)
			Stare_duration = 10000;//if we try to stare for more then a half an hour then better not stare at all :P (bug)
		float newo = unitTarget->calcRadAngle(unitTarget->GetPositionX(), unitTarget->GetPositionY(), m_targets.m_destX, m_targets.m_destY);
		unitTarget->GetAIInterface()->StopMovement(Stare_duration);
		unitTarget->SetFacing(newo);
	}

	//Smoke Emitter 164870
	//Smoke Emitter Big 179066
	//Unit Field Target of
}

void Spell::SpellEffectPickpocket(uint32 i) // pickpocket
{
	//Show random loot based on roll,
	if(!unitTarget || !p_caster || !unitTarget->IsCreature())
		return;

	Creature* target = TO< Creature* >(unitTarget);
	if(target->IsPickPocketed() || (target->GetCreatureInfo()->Type != UNIT_TYPE_HUMANOID))
	{
		SendCastResult(SPELL_FAILED_TARGET_NO_POCKETS);
		return;
	}

	lootmgr.FillPickpocketingLoot(&TO< Creature* >(unitTarget)->loot, unitTarget->GetEntry());

	uint32 _rank = TO< Creature* >(unitTarget)->GetCreatureInfo()->Rank;
	unitTarget->loot.gold = float2int32((_rank + 1) * unitTarget->getLevel() * (RandomUInt(5) + 1) * sWorld.getRate(RATE_MONEY));

	p_caster->SendLoot(unitTarget->GetGUID(), LOOT_PICKPOCKETING, unitTarget->GetMapId());
	target->SetPickPocketed(true);
}
/*
void Spell::SpellEffectAddFarsight(uint32 i) // Add Farsight
{
	if(p_caster == NULL)
		return;

	float x = m_targets.m_destX;
	float y = m_targets.m_destY;
	float z = m_targets.m_destZ;
	if(x == 0) x = m_targets.m_srcX;
	if(y == 0) y = m_targets.m_srcY;
	if(z == 0) z = m_targets.m_srcZ;

	DynamicObject* dynObj = p_caster->GetMapMgr()->CreateDynamicObject();
	dynObj->Create(u_caster, this, x, y, z, GetDuration(), GetRadius(i));

	/*
	if( dynObj == NULL ) //i <3 burlex :P
	{
	delete dynObj;
	return;
	}
	*/
/*	dynObj->SetUInt32Value(OBJECT_FIELD_TYPE, 65);
	dynObj->SetUInt32Value(DYNAMICOBJECT_BYTES, 0x80000002);
	dynObj->SetInstanceID(p_caster->GetInstanceID());
	p_caster->SetFarsightTarget(dynObj->GetGUID());

	p_caster->GetMapMgr()->ChangeFarsightLocation(p_caster, dynObj);
}
*/
void Spell::SpellEffectAddFarsight(uint32 i) // Add Farsight
{
	if( p_caster == NULL )
		return;

	DynamicObject* dyn = NULL;
	dyn = p_caster->GetMapMgr()->CreateDynamicObject();
	if(dyn == NULL)
		return;

	dyn->Create(p_caster, this, m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, GetDuration(), GetRadius(i));
	dyn->SetUInt32Value(OBJECT_FIELD_TYPE, 65);
	dyn->SetUInt32Value(DYNAMICOBJECT_BYTES, 0x80000002);
	dyn->AddToWorld(p_caster->GetMapMgr());
	p_caster->SetUInt64Value(PLAYER_FARSIGHT, dyn->GetGUID());
	p_caster->SetUInt32Value(PLAYER_FARSIGHT, dyn->GetLowGUID());
	p_caster->GetMapMgr()->ChangeFarsightLocation(p_caster, m_targets.m_destX, m_targets.m_destY, true);	
}

void Spell::SpellEffectUseGlyph(uint32 i)
{
	if(!p_caster) return;

	uint32 g_new = m_spellInfo->EffectMiscValue[i];
	GlyphPropertyEntry* gp_new = dbcGlyphProperty.LookupEntryForced(g_new);
	if(!gp_new)
		return;

	// check if glyph is locked (obviously)
	if(!(p_caster->GetUInt32Value(PLAYER_GLYPHS_ENABLED) & (1 << m_glyphslot)))
	{
		SendCastResult(SPELL_FAILED_GLYPH_SOCKET_LOCKED);
		return;
	}

	uint32 g_old = p_caster->GetGlyph(m_glyphslot);
	if(g_old)
	{
		if(g_old == g_new)
			return;
		else
		{
			GlyphPropertyEntry* gp_old = dbcGlyphProperty.LookupEntryForced(g_old);
			if(gp_old)
				p_caster->RemoveAura(gp_old->SpellID);
		}
	}

	GlyphSlotEntry* gs = dbcGlyphSlot.LookupEntryForced(p_caster->GetUInt32Value(PLAYER_FIELD_GLYPH_SLOTS_1 + m_glyphslot));
	if(gs)
	{
		if(gs->Type != gp_new->Type)
		{
			SendCastResult(SPELL_FAILED_INVALID_GLYPH);
			return;
		}
		p_caster->SetGlyph(m_glyphslot, g_new);
		p_caster->CastSpell(p_caster, gp_new->SpellID, true);
		p_caster->m_specs[p_caster->m_talentActiveSpec].glyphs[m_glyphslot] = static_cast< uint16 >(g_new);
		p_caster->smsg_TalentsInfo(false);
	}

}

void Spell::SpellEffectHealMechanical(uint32 i)
{
	if(!unitTarget || !unitTarget->IsCreature() || TO< Creature* >(unitTarget)->GetCreatureInfo()->Type != UNIT_TYPE_MECHANICAL)
		return;

	Heal(damage);
}

void Spell::SpellEffectSummonObjectWild(uint32 i)
{
	if(!u_caster) return;

	// spawn a new one
	GameObject* GoSummon = u_caster->GetMapMgr()->CreateGameObject(GetProto()->EffectMiscValue[i]);
	if(!GoSummon->CreateFromProto(GetProto()->EffectMiscValue[i],
	                              m_caster->GetMapId(), m_caster->GetPositionX() + 1, m_caster->GetPositionY() + 1, m_caster->GetPositionZ(), m_caster->GetOrientation()))
	{
		delete GoSummon;
		return;
	}

	GoSummon->Phase(PHASE_SET, u_caster->GetPhase());
	GoSummon->PushToWorld(u_caster->GetMapMgr());
	GoSummon->SetSummoned(u_caster);

	sEventMgr.AddEvent(GoSummon, &GameObject::ExpireAndDelete, EVENT_GAMEOBJECT_EXPIRE, GetDuration(), 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
}

void Spell::SpellEffectScriptEffect(uint32 i) // Script Effect
{
	uint32 spellId = m_spellInfo->Id;

	switch(spellId)
	{
	case 52694:                                 // Recall Eye of Acherus
		{	
			if(!m_caster || m_caster->GetTypeId() != TYPEID_UNIT)
				return;
			Summon* summoner = ((Summon*)m_caster);
			summoner->RemoveAurasDueToSpell(530);
			summoner->OnPreRemoveFromWorld();
				return;
		}break;

	case 51904:                                 // Summon Ghouls Of Scarlet Crusade
		{
			if(!unitTarget)
			return;

		unitTarget->CastSpell(unitTarget, 54522, false);
			return;
		}break;
		// Death Gate
	case 52751:
		{
			if(!unitTarget || unitTarget->getClass() != DEATHKNIGHT)
				return;
			// triggered spell is stored in m_spellInfo->EffectBasePoints[0]
			unitTarget->CastSpell(unitTarget, damage, false);
				
		}break;
	}
	// Try a dummy SpellHandler
	if(sScriptMgr.CallScriptedDummySpell(m_spellInfo->Id, i, this))
		return;

	if(sScriptMgr.HandleScriptedSpellEffect(m_spellInfo->Id, i, this))
		return;

	sLog.outDetail("Spell ID: %u ( %s ) has a scripted effect ( %u ) but no handler for it.", m_spellInfo->Id, m_spellInfo->Name, i);
}

void Spell::SpellEffectSanctuary(uint32 i) // Stop all attacks made to you
{
	if(!u_caster)
		return;

	//warning this causes crashes !
	//	Object::InRangeSet::iterator itr = u_caster->GetInRangeOppFactsSetBegin();
	//	Object::InRangeSet::iterator itr_end = u_caster->GetInRangeOppFactsSetEnd();
	//use these instead
	Object::InRangeSet::iterator itr = u_caster->GetInRangeSetBegin();
	Object::InRangeSet::iterator itr_end = u_caster->GetInRangeSetEnd();

	if(p_caster != NULL)
		p_caster->RemoveAllAuraType(SPELL_AURA_MOD_ROOT);

	for(; itr != itr_end; ++itr)
	{
		if((*itr)->IsCreature())
			TO_CREATURE(*itr)->GetAIInterface()->RemoveThreatByPtr(unitTarget);
	}
}

void Spell::SpellEffectAddComboPoints(uint32 i) // Add Combo Points
{
	if(!p_caster)
		return;

	//if this is a procspell Ruthlessness (maybe others later)
	if(pSpellId && (GetProto()->Id == 14157 || GetProto()->Id == 70802 || GetProto()->Id == 14181))
	{
		//it seems this combo adding procspell is going to change combopoint count before they will get reset. We add it after the reset
		/* burlex - this is wrong, and exploitable.. :/ if someone uses this they will have unlimited combo points */
		//re-enabled this by Zack. Explained why it is used + rechecked to make sure initialization is good ...
		// while casting a spell talent will trigger upon the spell prepare faze
		// the effect of the talent is to add 1 combo point but when triggering spell finishes it will clear the extra combo point
		p_caster->m_spellcomboPoints += static_cast<int8>(damage);
		return;
	}
	p_caster->AddComboPoints(p_caster->GetSelection(), static_cast<uint8>(damage));
}

void Spell::SpellEffectCreateHouse(uint32 i) // Create House
{


}

void Spell::SpellEffectDuel(uint32 i) // Duel
{
	if(!p_caster || !p_caster->isAlive())
		return;

	if(p_caster->IsStealth())
	{
		SendCastResult(SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED);
		return; // Player is stealth
	}
	if(!playerTarget || playerTarget == p_caster)
		return;

	/* not implemented yet
	TODO: dueling zones ? ( SPELL_FAILED_NO_DUELING )
	if (player->IsInvisible())
	{
	SendCastResult(SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE);
	return;
	}
	*/

	//Player *pTarget = sObjHolder.GetObject<Player>(player->GetSelection());	   //  hacky.. and will screw up if plr is deselected..
	if(!playerTarget)
	{
		SendCastResult(SPELL_FAILED_BAD_TARGETS);
		return; // invalid Target
	}
	if(!playerTarget->isAlive())
	{
		SendCastResult(SPELL_FAILED_TARGETS_DEAD);
		return; // Target not alive
	}
	if(playerTarget->hasStateFlag(UF_ATTACKING))
	{
		SendCastResult(SPELL_FAILED_TARGET_IN_COMBAT);
		return; // Target in combat with another unit
	}
	if(playerTarget->DuelingWith)
	{
		SendCastResult(SPELL_FAILED_TARGET_DUELING);
		return; // Already Dueling
	}

	p_caster->RequestDuel(playerTarget);
}

void Spell::SpellEffectStuck(uint32 i)
{
	if(!playerTarget || playerTarget != p_caster)
		return;

	sEventMgr.AddEvent(playerTarget, &Player::EventTeleport, playerTarget->GetBindMapId(), playerTarget->GetBindPositionX(), playerTarget->GetBindPositionY(),
	                   playerTarget->GetBindPositionZ(), EVENT_PLAYER_TELEPORT, 50, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
	/*
	playerTarget->SafeTeleport(playerTarget->GetBindMapId(), 0, playerTarget->GetBindPositionX(), playerTarget->GetBindPositionY(), playerTarget->GetBindPositionZ(), 3.14f);*/
}

void Spell::SpellEffectSummonPlayer(uint32 i)
{
	if(!playerTarget) return;

	// vojta: from 2.4 players can be summoned on another map
	//if( m_caster->GetMapMgr()->GetMapInfo() && m_caster->GetMapMgr()->GetMapInfo()->type != INSTANCE_NULL && m_caster->GetMapId() != playerTarget->GetMapId())
	//	return;
	if(m_caster->GetMapMgr()->GetMapInfo() && playerTarget->getLevel() < m_caster->GetMapMgr()->GetMapInfo()->minlevel)    // we need some blizzlike message that player needs level xx - feel free to add it ;)
		return;

	playerTarget->SummonRequest(m_caster->GetLowGUID(), m_caster->GetZoneId(), m_caster->GetMapId(), m_caster->GetInstanceID(), m_caster->GetPosition());
}

void Spell::SpellEffectActivateObject(uint32 i) // Activate Object
{
	if(!p_caster)
		return;

	if(!gameObjTarget)
	{
		LOG_ERROR("Spell %u ( %s ) effect %u not handled because no target was found. ", m_spellInfo->Id, m_spellInfo->Name, i);
		return;
	}

	CALL_GO_SCRIPT_EVENT(gameObjTarget, OnActivate)(p_caster);
	gameObjTarget->Activate();

	sEventMgr.AddEvent(gameObjTarget, &GameObject::Deactivate, 0, GetDuration(), 1, 0);
}


void Spell::SpellEffectBuildingDamage(uint32 i){
	if( gameObjTarget == NULL )
		return;

	if( gameObjTarget->GetInfo()->Type != GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING )
		return;

	if( u_caster == NULL )
		return;

	uint32 damage = m_spellInfo->EffectBasePoints[ i ] + 1;
	Unit *controller = NULL;

	if( u_caster->m_CurrentVehicle != NULL )
		controller = u_caster->GetMapMgr()->GetUnit( u_caster->GetCharmedByGUID() );

	if( controller == NULL )
		controller = u_caster;

	// Baaaam
	gameObjTarget->Damage( damage, u_caster->GetGUID(), controller->GetGUID(), m_spellInfo->Id );
}



void Spell::SpellEffectEnchantHeldItem(uint32 i)
{
	if(!playerTarget) return;

	Item* item = playerTarget->GetItemInterface()->GetInventoryItem(EQUIPMENT_SLOT_MAINHAND);
	if(!item)
		return;

	uint32 Duration = 1800; // Needs to be found in dbc.. I guess?
	switch(GetProto()->NameHash)
	{
		case SPELL_HASH_WINDFURY_WEAPON: // Windfury Weapon Effect
			{
				Duration = 10;
			}
		case SPELL_HASH_FLAMETONGUE_WEAPON: // Flametongue Weapon Effect
			{
				Duration = 10;
			}
	}
	EnchantEntry* Enchantment = dbcEnchant.LookupEntryForced(GetProto()->EffectMiscValue[i]);

	if(!Enchantment)
	{
		LOG_ERROR("Invalid enchantment entry %u for Spell %u", GetProto()->EffectMiscValue[ i ], GetProto()->Id);
		return;
	}

	/* Windfury Totem removed in 3.0.2
	if (m_spellInfo->NameHash == SPELL_HASH_WINDFURY_TOTEM_EFFECT && item->HasEnchantmentOnSlot( 1 ) && item->GetEnchantment( 1 )->Enchantment != Enchantment) //dirty fix for Windfury totem not overwriting existing enchantments
	return;
	*/

	item->RemoveEnchantment(1);
	item->AddEnchantment(Enchantment, Duration, false, true, false, 1);
}

void Spell::SpellEffectSelfResurrect(uint32 i)
{
	if(!p_caster || !unitTarget || playerTarget->isAlive()) return;

	uint32 mana;
	uint32 health;
	uint32 class_ = unitTarget->getClass();

	switch(GetProto()->Id)
	{
		case 3026:
		case 20758:
		case 20759:
		case 20760:
		case 20761:
		case 27240:
		case 47882:
			{
				health = GetProto()->EffectMiscValue[i];
				mana = -damage;
			}
			break;
		case 21169: //Reincarnation. Resurrect with 20% health and mana
			{
				int32 amt = 20;
				if(GetProto()->SpellGroupType)
				{
					SM_FIValue(unitTarget->SM_FMiscEffect, &amt, GetProto()->SpellGroupType);
					SM_PIValue(unitTarget->SM_PMiscEffect, &amt, GetProto()->SpellGroupType);
				}
				health = uint32((unitTarget->GetMaxHealth() * amt) / 100);
				mana = uint32((unitTarget->GetMaxPower(POWER_TYPE_MANA) * amt) / 100);
			}
			break;
		default:
			{
				if(damage < 0) return;
				health = uint32(unitTarget->GetMaxHealth() * damage / 100);
				mana = uint32(unitTarget->GetMaxPower(POWER_TYPE_MANA) * damage / 100);
			}
			break;
	}

	if(class_ == WARRIOR || class_ == ROGUE)
		mana = 0;

	playerTarget->m_resurrectHealth = health;
	playerTarget->m_resurrectMana = mana;

	playerTarget->ResurrectPlayer();
	playerTarget->SetMovement(MOVE_UNROOT, 1);

	playerTarget->SetUInt32Value(PLAYER_SELF_RES_SPELL, 0);

	if(GetProto()->Id == 21169)
		AddCooldown();
}

void Spell::SpellEffectSkinning(uint32 i)
{
	if(!unitTarget || !unitTarget->IsCreature())
		return;

	Creature* cr = TO_CREATURE(unitTarget);
	uint32 skill = cr->GetRequiredLootSkill();
	uint32 sk = TO_PLAYER(m_caster)->_GetSkillLineCurrent(skill);
	uint32 lvl = cr->getLevel();

	if((sk >= lvl * 5) || ((sk + 100) >= lvl * 10))
	{
		//Fill loot for Skinning
		lootmgr.FillSkinningLoot(&cr->loot, unitTarget->GetEntry());
		TO_PLAYER(m_caster)->SendLoot(unitTarget->GetGUID(), LOOT_SKINNING, unitTarget->GetMapId());

		//Not skinable again
		cr->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);
		cr->Skinned = true;

		if(cr->GetCreatureInfo()->Rank > 0)
			DetermineSkillUp(skill , sk < lvl * 5 ? sk / 5 : lvl, 2);
		else
			DetermineSkillUp(skill , sk < lvl * 5 ? sk / 5 : lvl, 1);
	}
	else
	{
		SendCastResult(SPELL_FAILED_TARGET_UNSKINNABLE);
	}
}

void Spell::SpellEffectCharge(uint32 i)
{
	if(unitTarget == NULL || !unitTarget->isAlive())
		return;
	if(u_caster->IsStunned() || u_caster->m_rooted || u_caster->IsPacified() || u_caster->IsFeared())
		return;

	float x, y, z;
	float rad = unitTarget->GetBoundingRadius() - u_caster->GetBoundingRadius();

	float dx = m_caster->GetPositionX() - unitTarget->GetPositionX();
	float dy = m_caster->GetPositionY() - unitTarget->GetPositionY();
	if(dx == 0.0f || dy == 0.0f)
		return;
	float alpha = atanf(dy / dx);
	if(dx < 0)
		alpha += M_PI_FLOAT;

	x = rad * cosf(alpha) + unitTarget->GetPositionX();
	y = rad * sinf(alpha) + unitTarget->GetPositionY();
	z = unitTarget->GetPositionZ();

	if(!u_caster->GetAIInterface()->MoveCharge(x, y, z))
	{
		//failed
		SendInterrupted(SPELL_FAILED_NOPATH);
		SendCastResult(SPELL_FAILED_NOPATH);
	}
}

void Spell::SpellEffectKnockBack(uint32 i)
{
	if(unitTarget == NULL || !unitTarget->isAlive())
		return;

	unitTarget->HandleKnockback(m_caster, GetProto()->EffectMiscValue[i] / 10, damage / 10);
}

void Spell::SpellEffectKnockBack2(uint32 i)
{
	if(unitTarget == NULL || !unitTarget->isAlive())
		return;

	unitTarget->HandleKnockback(m_caster, GetProto()->EffectMiscValue[i] / 10, damage / 10);
}

void Spell::SpellEffectDisenchant(uint32 i)
{
	if(!p_caster)
		return;

	Item* it = p_caster->GetItemInterface()->GetItemByGUID(m_targets.m_itemTarget);
	if(!it)
	{
		SendCastResult(SPELL_FAILED_CANT_BE_DISENCHANTED);
		return;
	}

	//Fill disenchanting loot
	p_caster->SetLootGUID(it->GetGUID());
	if(!it->loot)
	{
		it->loot = new Loot;
		lootmgr.FillItemLoot(it->loot, it->GetEntry());
	}

	Log.Debug("SpellEffect", "Successfully disenchanted item %d", uint32(it->GetEntry()));
	p_caster->SendLoot(it->GetGUID(), LOOT_DISENCHANTING, p_caster->GetMapId());

	//We can increase Enchanting skill up to 60
	uint32 skill = p_caster->_GetSkillLineCurrent(SKILL_ENCHANTING);
	if(skill && skill < 60)
	{
		if(Rand(100.0f - skill * 0.75f))
		{
			uint32 SkillUp = float2int32(1.0f * sWorld.getRate(RATE_SKILLRATE));
			if(skill + SkillUp > 60)
				SkillUp = 60 - skill;

			p_caster->_AdvanceSkillLine(SKILL_ENCHANTING, SkillUp);
		}
	}
	if(it == i_caster)
		i_caster = NULL;
}

void Spell::SpellEffectInebriate(uint32 i) // lets get drunk!
{
	if(playerTarget == NULL)
		return;

	// Drunkee!
	uint16 currentDrunk = playerTarget->GetDrunkValue();
	uint16 drunkMod = static_cast<uint16>(damage) * 256;
	if(currentDrunk + drunkMod > 0xFFFF)
		currentDrunk = 0xFFFF;
	else
		currentDrunk += drunkMod;
	playerTarget->SetDrunkValue(currentDrunk, i_caster ? i_caster->GetEntry() : 0);
}

void Spell::SpellEffectFeedPet(uint32 i)  // Feed Pet
{
	// food flags and food level are checked in Spell::CanCast()
	if(!itemTarget || !p_caster)
		return;

	Pet* pPet = p_caster->GetSummon();
	if(!pPet)
		return;

	/**	Cast feed pet effect
	- effect is item level and pet level dependent, aura ticks are 35, 17, 8 (*1000) happiness*/
	int8 deltaLvl = static_cast<int8>(pPet->getLevel() - itemTarget->GetProto()->ItemLevel);
	damage /= 1000; //damage of Feed pet spell is 35000
	if(deltaLvl > 10) damage = damage >> 1;//divide by 2
	if(deltaLvl > 20) damage = damage >> 1;
	damage *= 1000;

	SpellEntry* spellInfo = dbcSpell.LookupEntry(GetProto()->EffectTriggerSpell[i]);
	Spell* sp = sSpellFactoryMgr.NewSpell(p_caster, spellInfo, true, NULL);
	sp->forced_basepoints[0] = damage;
	SpellCastTargets tgt;
	tgt.m_unitTarget = pPet->GetGUID();
	sp->prepare(&tgt);

	if(itemTarget->GetStackCount() > 1)
	{
		itemTarget->ModStackCount(-1);
		itemTarget->m_isDirty = true;
	}
	else
	{
		p_caster->GetItemInterface()->SafeFullRemoveItemByGuid(itemTarget->GetGUID());
		itemTarget = NULL;
	}
}

void Spell::SpellEffectDismissPet(uint32 i)
{
	// remove pet.. but don't delete so it can be called later
	if(!p_caster) return;

	Pet* pPet = p_caster->GetSummon();
	if(!pPet) return;
	pPet->Remove(true, true);
}

void Spell::SpellEffectReputation(uint32 i)
{
	if(!playerTarget)
		return;

	//playerTarget->modReputation(GetProto()->EffectMiscValue[i], damage, true);
	playerTarget->ModStanding(GetProto()->EffectMiscValue[i], damage);
}

void Spell::SpellEffectSummonObjectSlot(uint32 i)
{
	if(!u_caster || !u_caster->IsInWorld())
		return;

	GameObject* GoSummon = NULL;

	uint32 slot = GetProto()->Effect[i] - SPELL_EFFECT_SUMMON_OBJECT_SLOT1;
	GoSummon = u_caster->m_ObjectSlots[slot] ? u_caster->GetMapMgr()->GetGameObject(u_caster->m_ObjectSlots[slot]) : 0;
	u_caster->m_ObjectSlots[slot] = 0;

	if(GoSummon)
	{
		if(GoSummon->GetInstanceID() != u_caster->GetInstanceID())
			GoSummon->ExpireAndDelete();
		else
		{
			if(GoSummon->IsInWorld())
				GoSummon->RemoveFromWorld(true);
			delete GoSummon;
		}
	}


	// spawn a new one
	GoSummon = u_caster->GetMapMgr()->CreateGameObject(GetProto()->EffectMiscValue[i]);

	float dx = 0.0f;
	float dy = 0.0f;
	float dz = 0.0f;

	if(m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION)
	{
		dx = m_targets.m_destX;
		dy = m_targets.m_destY;
		dz = m_targets.m_destZ;
	}
	else
	{
		dx = m_caster->GetPositionX();
		dy = m_caster->GetPositionY();
		dz = m_caster->GetPositionZ();
	}

	if(!GoSummon->CreateFromProto(GetProto()->EffectMiscValue[i], m_caster->GetMapId(), dx, dy, dz, m_caster->GetOrientation()))
	{
		delete GoSummon;
		return;
	}

	GoSummon->SetLevel(u_caster->getLevel());
	GoSummon->SetUInt64Value(OBJECT_FIELD_CREATED_BY, m_caster->GetGUID());
	GoSummon->Phase(PHASE_SET, u_caster->GetPhase());

	GoSummon->PushToWorld(m_caster->GetMapMgr());

	if(GoSummon->GetType() == GAMEOBJECT_TYPE_TRAP)
	{
		GoSummon->invisible = true;
		GoSummon->invisibilityFlag = INVIS_FLAG_TRAP;
		GoSummon->charges = 1;
		GoSummon->checkrate = 1;
		sEventMgr.AddEvent(GoSummon, &GameObject::TrapSearchTarget, EVENT_GAMEOBJECT_TRAP_SEARCH_TARGET, 100, 0, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
	}
	sEventMgr.AddEvent(GoSummon, &GameObject::ExpireAndDelete, EVENT_GAMEOBJECT_EXPIRE, GetDuration(), 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);

	GoSummon->SetSummoned(u_caster);
	u_caster->m_ObjectSlots[slot] = GoSummon->GetUIdFromGUID();
}

void Spell::SpellEffectDispelMechanic(uint32 i)
{
	if(!unitTarget || !unitTarget->isAlive())
		return;
	/* this was already working before...
	uint32 sMisc = GetProto()->EffectMiscValue[i];

	for( uint32 x = 0 ; x<MAX_AURAS ; x++ )
	{
	if( unitTarget->m_auras[x] && !unitTarget->m_auras[x]->IsPositive())
	{
	if( unitTarget->m_auras[x]->GetSpellProto()->MechanicsType == sMisc )
	unitTarget->m_auras[x]->Remove();
	}
	}
	*/
	unitTarget->RemoveAllAurasByMechanic(GetProto()->EffectMiscValue[i] , GetProto()->EffectBasePoints[i] , false);

	/*Shady: if it's about Daze spell - dismount should be done by RemoveAllAurasByMechanic.
	We don't need useless code or hackfixes here, so commented.*/
	//if( playerTarget && GetProto()->NameHash == SPELL_HASH_DAZED && playerTarget->IsMounted() )
	//	playerTarget->RemoveAura(playerTarget->m_MountSpellId);
}

void Spell::SpellEffectSummonDeadPet(uint32 i)
{
	//this is pet resurrect
	if(!p_caster)
		return;
	Pet* pPet = p_caster->GetSummon();
	if(pPet)
	{
		if(GetProto()->SpellGroupType)
		{
			SM_FIValue(p_caster->SM_FMiscEffect, &damage, GetProto()->SpellGroupType);
			SM_PIValue(p_caster->SM_PMiscEffect, &damage, GetProto()->SpellGroupType);
		}

		pPet->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
		pPet->SetHealth((uint32)((pPet->GetMaxHealth() * damage) / 100));
		pPet->setDeathState(ALIVE);
		pPet->GetAIInterface()->HandleEvent(EVENT_FOLLOWOWNER, pPet, 0);
		sEventMgr.RemoveEvents(pPet, EVENT_PET_DELAYED_REMOVE);
		pPet->SendSpellsToOwner();
	}
	else
	{

		p_caster->SpawnPet(p_caster->GetUnstabledPetNumber());
		pPet = p_caster->GetSummon();
		if(pPet == NULL)//no pets to Revive
			return;
		if(GetProto()->SpellGroupType)
		{
			SM_FIValue(p_caster->SM_FMiscEffect, &damage, GetProto()->SpellGroupType);
			SM_PIValue(p_caster->SM_PMiscEffect, &damage, GetProto()->SpellGroupType);
		}
		pPet->SetHealth((uint32)((pPet->GetMaxHealth() * damage) / 100));
	}
}

/* This effect has 2 functions
* 1. It delete's all current totems from the player
* 2. It returns a percentage of the mana back to the player
*
* Bur kick my ass if this is not safe:P
*/

/* This effect has 2 functions
 * 1. It delete's all current totems from the player
 * 2. It returns a percentage of the mana back to the player
 *
 * Bur kick my ass if this is not safe:P
*/

void Spell::SpellEffectDestroyAllTotems(uint32 i)
{
	if(p_caster  == NULL || !p_caster->IsInWorld())
		return;

	uint32 energize_amt = 0;
	for(uint32 x=SUMMON_TYPEID_TOTEM_1;x<SUMMON_TYPEID_TOTEM_4+1;x++)
	{
		SummonPropertiesEntry * spe = NULL;
		switch(x)
		{
		case SUMMON_TYPEID_TOTEM_1:
		case SUMMON_TYPEID_TOTEM_2:
		case SUMMON_TYPEID_TOTEM_3:
		case SUMMON_TYPEID_TOTEM_4:
			{
				spe = dbcSummonProperties.LookupEntryForced(x);
			}break;
		}

		if(spe == NULL)
			continue;

		// atm totems are considert creature's
		if(p_caster->m_SummonSlots[spe->Slot]!= NULL)
		{
			uint32 SpellID = p_caster->m_SummonSlots[spe->Slot]->GetUInt32Value(UNIT_CREATED_BY_SPELL);
			SpellEntry * sp = NULL;
			sp = dbcSpell.LookupEntry(SpellID);
			if (sp == NULL)
				continue;
			if( sp->manaCost )
				energize_amt += float2int32( (sp->manaCost) * (damage/100.0f) );
			else if( sp->ManaCostPercentage )
				energize_amt += float2int32(((p_caster->GetUInt32Value(UNIT_FIELD_BASE_MANA)*sp->ManaCostPercentage)/100.0f) * (damage/100.0f) );

			if(p_caster->m_SummonSlots[spe->Slot]->IsTotem())
				p_caster->SummonExpireSlot(spe->Slot);
			else
			{
				p_caster->m_SummonSlots[spe->Slot]->DeleteMe();
				p_caster->m_SummonSlots[spe->Slot]=NULL;
			}
		}
	}

	if( energize_amt > 0 )
		p_caster->Energize(p_caster, m_spellInfo->Id, energize_amt, POWER_TYPE_MANA);
}

/*
void Spell::SpellEffectDestroyAllTotems(uint32 i)
{

	if(p_caster == NULL || !p_caster->IsInWorld())
		return;

	uint32 RetreivedMana = 0;
	uint32 refundpercent = m_spellInfo->EffectBasePoints[ i ] + 1;

	std::vector< uint32 > spellids;

	p_caster->summonhandler.GetSummonSlotSpellIDs(spellids);

	for(std::vector< uint32 >::iterator itr = spellids.begin(); itr != spellids.end(); ++itr)
	{
		uint32 spellid = *itr;
		SpellEntry* sp = dbcSpell.LookupEntry(spellid);

		if(sp != NULL)
		{
			uint32 cost = 0;

			if(sp->ManaCostPercentage != 0)
				cost = (p_caster->GetBaseMana() * sp->ManaCostPercentage) / 100;
			else
				cost = sp->manaCost;

			RetreivedMana += static_cast< uint32 >((cost * refundpercent) / 100.0f);
		}
	}

	p_caster->summonhandler.ExpireSummonsInSlot();

	p_caster->Energize(p_caster, GetProto()->Id, RetreivedMana, POWER_TYPE_MANA);
}*/

void Spell::SpellEffectResurrectNew(uint32 i)
{
	//base p =hp,misc mana
	if(!playerTarget)
	{
		if(!corpseTarget)
		{
			// unit resurrection handler
			if(unitTarget)
			{
				if(unitTarget->IsCreature() && unitTarget->IsPet() && unitTarget->IsDead())
				{
					uint32 hlth = ((uint32)GetProto()->EffectBasePoints[i] > unitTarget->GetMaxHealth()) ? unitTarget->GetMaxHealth() : (uint32)GetProto()->EffectBasePoints[i];
					uint32 mana = ((uint32)GetProto()->EffectBasePoints[i] > unitTarget->GetMaxPower(POWER_TYPE_MANA)) ? unitTarget->GetMaxPower(POWER_TYPE_MANA) : (uint32)GetProto()->EffectBasePoints[i];

					if(!unitTarget->IsPet())
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					else
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_PET_DELAYED_REMOVE);
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					unitTarget->SetHealth(hlth);
					unitTarget->SetPower(POWER_TYPE_MANA, mana);
					unitTarget->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
					unitTarget->setDeathState(ALIVE);
					TO< Creature* >(unitTarget)->UnTag();
					TO< Creature* >(unitTarget)->loot.gold = 0;
					TO< Creature* >(unitTarget)->loot.looters.clear();
					TO< Creature* >(unitTarget)->loot.items.clear();
				}
			}

			return;
		}
		playerTarget = objmgr.GetPlayer(GET_LOWGUID_PART(corpseTarget->GetOwner()));
		if(!playerTarget) return;
	}

	if(playerTarget->isAlive() || !playerTarget->IsInWorld())
		return;
	//resurrect
	playerTarget->m_resurrectMapId = p_caster->GetMapId();
	playerTarget->m_resurrectInstanceID = p_caster->GetInstanceID();
	playerTarget->m_resurrectPosition = p_caster->GetPosition();
	playerTarget->m_resurrectHealth = damage;
	playerTarget->m_resurrectMana = GetProto()->EffectMiscValue[i];

	SendResurrectRequest(playerTarget);
}

void Spell::SpellEffectAttackMe(uint32 i)
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	unitTarget->GetAIInterface()->AttackReaction(u_caster, 1, 0);
}

void Spell::SpellEffectSkinPlayerCorpse(uint32 i)
{
	Corpse* corpse = 0;
	if(!playerTarget)
	{
		// means we're "skinning" a corpse
		corpse = objmgr.GetCorpse((uint32)m_targets.m_unitTarget);  // hacky
	}
	else if(playerTarget->getDeathState() == CORPSE)	// repopped while we were casting
	{
		corpse = objmgr.GetCorpse(playerTarget->GetLowGUID());
	}

	if(p_caster == NULL)
		return;

	if(playerTarget && !corpse)
	{
		if(!playerTarget->m_bg || !playerTarget->IsDead())
			return;

		// Set all the lootable stuff on the player. If he repops before we've looted, we'll set the flags
		// on corpse then :p

		playerTarget->bShouldHaveLootableOnCorpse = false;
		playerTarget->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);
		playerTarget->SetFlag(UNIT_DYNAMIC_FLAGS, U_DYN_FLAG_LOOTABLE);

		// Send the loot.
		p_caster->SendLoot(playerTarget->GetGUID(), LOOT_SKINNING, playerTarget->GetMapId());

		// Send a message to the died player, telling him he has to resurrect at the graveyard.
		// Send an empty corpse location too, :P

		playerTarget->GetSession()->OutPacket(SMSG_PLAYER_SKINNED, 1, "\x00");
		playerTarget->GetSession()->OutPacket(MSG_CORPSE_QUERY, 1, "\x00");

		// don't allow him to spawn a corpse
		playerTarget->bCorpseCreateable = false;

		// and.. force him to the graveyard and repop him.
		playerTarget->RepopRequestedPlayer();

	}
	else if(corpse)
	{
		// find the corpses' owner
		Player* owner = objmgr.GetPlayer(GET_LOWGUID_PART(corpse->GetOwner()));
		if(owner)
		{
			if(!owner->m_bg) return;

			owner->GetSession()->OutPacket(SMSG_PLAYER_SKINNED, 1, "\x00");
			owner->GetSession()->OutPacket(MSG_CORPSE_QUERY, 1, "\x00");
		}

		if(corpse->GetUInt32Value(CORPSE_FIELD_DYNAMIC_FLAGS) != 1)
			corpse->SetUInt32Value(CORPSE_FIELD_DYNAMIC_FLAGS, 1); // sets it so you can loot the plyr

		// remove skinnable flag
		corpse->SetUInt32Value(CORPSE_FIELD_FLAGS, 5);

		// remove owner association
		corpse->SetOwner(0);
		corpse->SetCorpseState(CORPSE_STATE_BONES);
		corpse->DeleteFromDB();
		objmgr.CorpseAddEventDespawn(corpse);

		// send loot
		p_caster->SendLoot(corpse->GetGUID(), LOOT_SKINNING, corpse->GetMapId());
	}
}

void Spell::SpellEffectSkill(uint32 i)
{
	// Used by professions only
	// Effect should be renamed in RequireSkill

	if(!p_caster || p_caster->_GetSkillLineMax(GetProto()->EffectMiscValue[i]) >= uint32(damage * 75))
		return;

	if(p_caster->_HasSkillLine(GetProto()->EffectMiscValue[i]))
		p_caster->_ModifySkillMaximum(GetProto()->EffectMiscValue[i], uint32(damage * 75));
	else
		p_caster->_AddSkillLine(GetProto()->EffectMiscValue[i], 1, uint32(damage * 75));
}

void Spell::SpellEffectApplyPetAA(uint32 i)
{
	ApplyAA(i);
}

void Spell::SpellEffectDummyMelee(uint32 i)   // Normalized Weapon damage +
{

	if(!unitTarget || !u_caster)
		return;

	if(GetProto()->NameHash == SPELL_HASH_OVERPOWER && p_caster)   //warrior : overpower - let us clear the event and the combopoint count
	{
		p_caster->NullComboPoints(); //some say that we should only remove 1 point per dodge. Due to cooldown you can't cast it twice anyway..
		sEventMgr.RemoveEvents(p_caster, EVENT_COMBO_POINT_CLEAR_FOR_TARGET);
	}
	else if(GetProto()->NameHash == SPELL_HASH_DEVASTATE)
	{
		//count the number of sunder armors on target
		uint32 sunder_count = 0;
		SpellEntry* spellInfo = dbcSpell.LookupEntry(7386);
		for(uint32 x = MAX_NEGATIVE_AURAS_EXTEDED_START; x < MAX_NEGATIVE_AURAS_EXTEDED_END; ++x)
			if(unitTarget->m_auras[x] && unitTarget->m_auras[x]->GetSpellProto()->NameHash == SPELL_HASH_SUNDER_ARMOR)
			{
				sunder_count++;
				spellInfo = unitTarget->m_auras[x]->GetSpellProto();
			}
		if(spellInfo == NULL)
			return; //omg how did this happen ?
		//we should also cast sunder armor effect on target with or without dmg
		Spell* spell = sSpellFactoryMgr.NewSpell(u_caster, spellInfo , true, NULL);
		spell->ProcedOnSpell = GetProto();
		spell->pSpellId = GetProto()->Id;
		SpellCastTargets targets(unitTarget->GetGUID());
		spell->prepare(&targets);
		if(!sunder_count)
			return; //no damage = no joy
		damage = damage * sunder_count;
	}
	//Hemorrhage
	if(p_caster && GetProto()->NameHash == SPELL_HASH_HEMORRHAGE)
		p_caster->AddComboPoints(p_caster->GetSelection(), 1);

	switch(GetProto()->Id)
	{
			// AMBUSH
		case 8676:
			add_damage = 77;
			return;
			break;			// r1
		case 8724:
			add_damage = 110;
			return;
			break;			// r2
		case 8725:
			add_damage = 138;
			return;
			break;			// r3
		case 11267:
			add_damage = 204;
			return;
			break;		// r4
		case 11268:
			add_damage = 253;
			return;
			break;		// r5
		case 11269:
			add_damage = 319;
			return;
			break;		// r6
		case 27441:
			add_damage = 369;
			return;
			break;		// r7
		case 48689:
			add_damage = 509;
			return;
			break;		// r8
		case 48690:
			add_damage = 770;
			return;
			break;		// r9
		case 48691:
			add_damage = 908;
			return;
			break;		// r10

			// BACKSTAB
		case 53:
			add_damage = 15;
			return;
			break;			// r1
		case 2589:
			add_damage = 30;
			return;
			break;			// r2
		case 2590:
			add_damage = 48;
			return;
			break;			// r3
		case 2591:
			add_damage = 69;
			return;
			break;			// r4
		case 8721:
			add_damage = 90;
			return;
			break;			// r5
		case 11279:
			add_damage = 135;
			return;
			break;		// r6
		case 11280:
			add_damage = 165;
			return;
			break;		// r7
		case 11281:
			add_damage = 210;
			return;
			break;		// r8
		case 25300:
			add_damage = 225;
			return;
			break;		// r9
		case 26863:
			add_damage = 255;
			return;
			break;		// r10
		case 48656:
			add_damage = 383;
			return;
			break;		// r11
		case 48657:
			add_damage = 465;
			return;
			break;		// r12
	}

	// rogue ambush etc
	for(uint32 x = 0; x < 3; x++)
		if(GetProto()->Effect[x] == SPELL_EFFECT_WEAPON_PERCENT_DAMAGE)
		{
			add_damage = damage * (GetProto()->EffectBasePoints[x] + 1) / 100;
			return;
		}

	//rogue - mutilate ads dmg if target is poisoned
	uint32 pct_dmg_mod = 100;
	if(GetProto()->NameHash == SPELL_HASH_MUTILATE && unitTarget->IsPoisoned())
		pct_dmg_mod = 120;

	uint32 _type;
	if(GetType() == SPELL_DMG_TYPE_RANGED)
		_type = RANGED;
	else
	{
		if(GetProto()->AttributesExC & 0x1000000)
			_type =  OFFHAND;
		else
			_type = MELEE;
	}
	u_caster->Strike(unitTarget, _type, GetProto(), damage, pct_dmg_mod, 0, false, true);
}

void Spell::SpellEffectStartTaxi(uint32 i)
{
	if(!playerTarget || !playerTarget->isAlive() || !u_caster)
		return;

	if(playerTarget->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOCK_PLAYER))
		return;

	TaxiPath* taxipath = sTaxiMgr.GetTaxiPath(GetProto()->EffectMiscValue[0]);

	if(!taxipath)
		return;

	TaxiNode* taxinode = sTaxiMgr.GetTaxiNode(taxipath->GetSourceNode());

	if(!taxinode)
		return;

	uint32 modelid = 0;

	if(playerTarget->IsTeamHorde())
	{
		CreatureInfo* ci = CreatureNameStorage.LookupEntry(taxinode->horde_mount);
		if(!ci) return;
		modelid = ci->Male_DisplayID;
		if(!modelid) return;
	}
	else
	{
		CreatureInfo* ci = CreatureNameStorage.LookupEntry(taxinode->alliance_mount);
		if(!ci) return;
		modelid = ci->Male_DisplayID;
		if(!modelid) return;
	}

	playerTarget->TaxiStart(taxipath, modelid, 0);
}

void Spell::SpellEffectPlayerPull(uint32 i)
{
	if(!unitTarget || !unitTarget->isAlive() || !unitTarget->IsPlayer())
		return;

	Player* p_target = TO< Player* >(unitTarget);

	// calculate destination
	float pullD = p_target->CalcDistance(m_caster) - p_target->GetBoundingRadius() - (u_caster ? u_caster->GetBoundingRadius() : 0) - 1.0f;
	float pullO = p_target->calcRadAngle(p_target->GetPositionX(), p_target->GetPositionY(), m_caster->GetPositionX(), m_caster->GetPositionY());
	float pullX = p_target->GetPositionX() + pullD * cosf(pullO);
	float pullY = p_target->GetPositionY() + pullD * sinf(pullO);
	float pullZ = m_caster->GetPositionZ() + 0.3f;
	uint32 time = uint32(pullD * 42.0f);

	p_target->SetOrientation(pullO);

	WorldPacket data(SMSG_MONSTER_MOVE, 60);
	data << p_target->GetNewGUID();
	data << uint8(0);
	data << p_target->GetPositionX() << p_target->GetPositionY() << p_target->GetPositionZ();
	data << getMSTime();
	data << uint8(4);
	data << pullO;
	data << uint32(0x00001000);
	data << time;
	data << uint32(1);
	data << pullX << pullY << pullZ;

	p_target->SendMessageToSet(&data, true);
}

void Spell::SpellEffectReduceThreatPercent(uint32 i)
{
	if(!unitTarget || !unitTarget->IsCreature() || !u_caster || unitTarget->GetAIInterface()->getThreatByPtr(u_caster) == 0)
		return;

	unitTarget->GetAIInterface()->modThreatByPtr(u_caster, (int32)unitTarget->GetAIInterface()->getThreatByPtr(u_caster) * damage / 100);
}

void Spell::SpellEffectSpellSteal(uint32 i)
{
	if(unitTarget == NULL || u_caster == NULL || !unitTarget->isAlive())
		return;

	if(playerTarget != NULL && p_caster != NULL && p_caster != playerTarget)
	{
		if(playerTarget->IsPvPFlagged())
			p_caster->PvPToggle();
	}

	uint32 start, end;
	if(isAttackable(u_caster, unitTarget))
	{
		start = MAX_POSITIVE_AURAS_EXTEDED_START;
		end = MAX_POSITIVE_AURAS_EXTEDED_END;
	}
	else
		return;

	Aura* aur;
	SpellEntry* aursp;
	std::list< uint32 > stealedSpells;

	for(uint32 x = start; x < end; x++)
	{
		if(unitTarget->m_auras[x] != NULL)
		{
			aur = unitTarget->m_auras[x];
			aursp = aur->GetSpellProto();

			if(aursp->Id != 15007 && !aur->IsPassive()
			        //				&& aur->IsPositive()	// Zack : We are only checking positive auras. There is no meaning to check again
			  ) //Nothing can dispel resurrection sickness
			{
				if(aursp->DispelType == DISPEL_MAGIC)
				{
					stealedSpells.push_back(aursp->Id);

					uint32 aurdur = (aur->GetDuration() > 120000 ? 120000 : aur->GetDuration());
					Aura* aura = sSpellFactoryMgr.NewAura(aursp, aurdur, u_caster, u_caster);
					uint32 aur_removed = unitTarget->RemoveAllAuraByNameHash(aursp->NameHash);
					for(uint8 j = 0; j < 3; j++)
					{
						if(aura->GetSpellProto()->Effect[j])
						{
							aura->AddMod(aura->GetSpellProto()->EffectApplyAuraName[j], aura->GetSpellProto()->EffectBasePoints[j] + 1, aura->GetSpellProto()->EffectMiscValue[j], j);
						}
					}
					if(aura->GetSpellProto()->procCharges > 0)
					{
						Aura* aur2;
						for(uint32 j = 0; j < aur_removed - 1; j++)
						{
							aur2 = sSpellFactoryMgr.NewAura(aura->GetSpellProto(), aurdur, u_caster, u_caster);
							u_caster->AddAura(aur2);
						}
						if(!(aura->GetSpellProto()->procFlags & PROC_REMOVEONUSE))
						{
							SpellCharge charge;
							charge.count = aur_removed;
							charge.spellId = aura->GetSpellId();
							charge.ProcFlag = aura->GetSpellProto()->procFlags;
							charge.lastproc = 0;
							charge.procdiff = 0;
							u_caster->m_chargeSpells.insert(make_pair(aura->GetSpellId(), charge));
						}
					}
					u_caster->AddAura(aura);
					break;
				}
			}
		}
	}

	if(!stealedSpells.empty())
	{
		WorldPacket data(SMSG_SPELLSTEALLOG, 25 + stealedSpells.size() * 5);
		data << m_caster->GetNewGUID();
		data << unitTarget->GetNewGUID();
		data << GetProto()->Id;
		data << uint8(0);				// unused
		data << uint32(stealedSpells.size());
		for(std::list< uint32 >::iterator itr = stealedSpells.begin(); itr != stealedSpells.end(); ++itr)
		{
			data << uint32(*itr);		// stealed spell id
			data << uint8(1);			// 0 = dispelled, else cleansed
		}

		m_caster->SendMessageToSet(&data, true);
	}
}

void Spell::SpellEffectProspecting(uint32 i)
{
	if(!p_caster) return;

	if(!itemTarget) // this should never happen
	{
		SendCastResult(SPELL_FAILED_CANT_BE_PROSPECTED);
		return;
	}

	//Fill Prospecting loot
	p_caster->SetLootGUID(itemTarget->GetGUID());
	if(!itemTarget->loot)
	{
		itemTarget->loot = new Loot;
		lootmgr.FillItemLoot(itemTarget->loot , itemTarget->GetEntry());
	}

	if(itemTarget->loot->items.size() > 0)
	{
		Log.Debug("SpellEffect", "Successfully prospected item %d", uint32(itemTarget->GetEntry()));
		p_caster->SendLoot(itemTarget->GetGUID(), LOOT_PROSPECTING, p_caster->GetMapId());
	}
	else // this should never happen either
	{
		Log.Debug("SpellEffect", "Prospecting failed, item %d has no loot", uint32(itemTarget->GetEntry()));
		SendCastResult(SPELL_FAILED_CANT_BE_PROSPECTED);
	}
}

void Spell::SpellEffectApplyFriendAA(uint32 i)
{
	if( u_caster->GetTypeId() == TYPEID_UNIT )
	{
		ApplyAA(i);
	}
	else
	{
		if(m_spellInfo->EffectApplyAuraName[i] != 0)
			SpellEffectApplyAura(i);
	}
}

void Spell::SpellEffectApplyEnemyAA(uint32 i)
{
	ApplyAA(i);
}

void Spell::SpellEffectRedirectThreat(uint32 i)
{
	if(!p_caster || !unitTarget)
		return;

	if((unitTarget->IsPlayer() && p_caster->GetGroup() != TO< Player* >(unitTarget)->GetGroup()) || (unitTarget->IsCreature() && !unitTarget->IsPet()))
		return;

	p_caster->SetMisdirectionTarget(unitTarget->GetGUID());
}

void Spell::SpellEffectPlayMusic(uint32 i)
{
	uint32 soundid = m_spellInfo->EffectMiscValue[ i ];

	if(soundid == 0)
	{
		LOG_ERROR("Spell %u ( %s ) has no sound ID to play. Spell needs fixing!", m_spellInfo->Id, m_spellInfo->Name);
		return;
	}

	m_caster->PlaySoundToSet(soundid);
}

void Spell::SpellEffectForgetSpecialization(uint32 i)
{
	if(!playerTarget) return;

	uint32 spellid = GetProto()->EffectTriggerSpell[i];
	playerTarget->removeSpell(spellid, false, false, 0);

	LOG_DEBUG("Player %u have forgot spell %u from spell %u ( caster: %u)", playerTarget->GetLowGUID(), spellid, GetProto()->Id, m_caster->GetLowGUID());
}

void Spell::SpellEffectKillCredit(uint32 i)
{
	CreatureInfo* ci = CreatureNameStorage.LookupEntry(GetProto()->EffectMiscValue[i]);
	if(playerTarget != NULL && ci != NULL)
		sQuestMgr._OnPlayerKill(playerTarget, GetProto()->EffectMiscValue[i], false);
}

void Spell::SpellEffectRestorePowerPct(uint32 i)
{
	if(u_caster == NULL || unitTarget == NULL || !unitTarget->isAlive())
		return;

	uint32 power_type = GetProto()->EffectMiscValue[i];
	if(power_type > POWER_TYPE_HAPPINESS)
	{
		LOG_ERROR("Unhandled power type %u in %s, report this line to devs.", power_type, __FUNCTION__);
		return;
	}

	uint32 amount = damage * unitTarget->GetMaxPower(power_type) / 100;
	u_caster->Energize(unitTarget, GetProto()->Id, amount, power_type);
}

void Spell::SpellEffectTriggerSpellWithValue(uint32 i)
{
	if(!unitTarget) return;

	SpellEntry* TriggeredSpell = dbcSpell.LookupEntryForced(GetProto()->EffectTriggerSpell[i]);
	if(TriggeredSpell == NULL)
		return;

	Spell* sp = sSpellFactoryMgr.NewSpell(m_caster, TriggeredSpell, true, NULL);

	for(uint32 x = 0; x < 3; x++)
	{
		if(i == x)
			sp->forced_basepoints[x] = damage;	//prayer of mending should inherit heal bonus ?
		else
			sp->forced_basepoints[x] = TriggeredSpell->EffectBasePoints[i];

	}

	SpellCastTargets tgt(unitTarget->GetGUID());
	sp->prepare(&tgt);
}

void Spell::SpellEffectApplyOwnerAA(uint32 i)
{
	ApplyAA(i);
}

void Spell::SpellEffectCreatePet(uint32 i)
{
	if(!playerTarget)
		return;

	if(playerTarget->GetSummon())
		playerTarget->GetSummon()->Remove(true, true);
	CreatureInfo* ci = CreatureNameStorage.LookupEntry(GetProto()->EffectMiscValue[i]);
	if(ci)
	{
		Pet* pPet = objmgr.CreatePet(GetProto()->EffectMiscValue[i]);
		if(! pPet->CreateAsSummon(GetProto()->EffectMiscValue[i], ci, NULL, playerTarget, GetProto(), 1, 0))
		{
			pPet->DeleteMe();//CreateAsSummon() returns false if an error occurred.
			pPet = NULL;
		}
	}
}

void Spell::SpellEffectTeachTaxiPath(uint32 i)
{
	if(!playerTarget || !GetProto()->EffectTriggerSpell[i])
		return;

	uint8 field = (uint8)((GetProto()->EffectTriggerSpell[i] - 1) / 32);
	uint32 submask = 1 << ((GetProto()->EffectTriggerSpell[i] - 1) % 32);

	// Check for known nodes
	if(!(playerTarget->GetTaximask(field) & submask))
	{
		playerTarget->SetTaximask(field, (submask | playerTarget->GetTaximask(field)));

		playerTarget->GetSession()->OutPacket(SMSG_NEW_TAXI_PATH);

		//Send packet
		WorldPacket update(SMSG_TAXINODE_STATUS, 9);
		update << uint64(0) << uint8(1);
		playerTarget->GetSession()->SendPacket(&update);
	}
}

void Spell::SpellEffectDualWield2H(uint32 i)
{
	if(!playerTarget)
		return;

	playerTarget->DualWield2H = true;
}

void Spell::SpellEffectEnchantItemPrismatic(uint32 i)
{
	if(!itemTarget || !p_caster)
		return;

	EnchantEntry* Enchantment = dbcEnchant.LookupEntry(m_spellInfo->EffectMiscValue[i]);

	if(!Enchantment)
	{
		LOG_ERROR("Invalid enchantment entry %u for Spell %u", GetProto()->EffectMiscValue[ i ], GetProto()->Id);
		return;
	}

	if(p_caster->GetSession()->GetPermissionCount() > 0)
		sGMLog.writefromsession(p_caster->GetSession(), "enchanted item for %s", itemTarget->GetOwner()->GetName());

	//remove other socket enchant
	itemTarget->RemoveEnchantment(6);
	int32 Slot = itemTarget->AddEnchantment(Enchantment, 0, true, true, false, 6);

	if(Slot < 6)
		return; // Apply failed

	itemTarget->m_isDirty = true;

}

void Spell::SpellEffectCreateItem2(uint32 i) // Create item
{
	//TODO: This spell effect has also a misc value - meaning is unknown yet
	if(p_caster == NULL)
		return;

	uint32 new_item_id = GetProto()->EffectItemType[i];

	if(new_item_id != 0)
	{
		// create item
		CreateItem(new_item_id);
	}
	else if(i_caster)
	{
		// provide player with item loot (clams)
		// TODO: Finish this
	}
}

void Spell::SpellEffectMilling(uint32 i)
{
	if(!p_caster) return;

	if(!itemTarget) // this should never happen
	{
		SendCastResult(SPELL_FAILED_CANT_BE_PROSPECTED);
		return;
	}

	//Fill Prospecting loot
	p_caster->SetLootGUID(itemTarget->GetGUID());
	if(!itemTarget->loot)
	{
		itemTarget->loot = new Loot;
		lootmgr.FillItemLoot(itemTarget->loot, itemTarget->GetEntry());
	}

	if(itemTarget->loot->items.size() > 0)
	{
		Log.Debug("SpellEffect", "Successfully milled item %d", uint32(itemTarget->GetEntry()));
		p_caster->SendLoot(itemTarget->GetGUID(), LOOT_MILLING, p_caster->GetMapId());
	}
	else // this should never happen either
	{
		Log.Debug("SpellEffect", "Milling failed, item %d has no loot", uint32(itemTarget->GetEntry()));
		SendCastResult(SPELL_FAILED_CANT_BE_PROSPECTED);
	}
}

void Spell::SpellEffectRenamePet(uint32 i)
{
	if(!unitTarget || !unitTarget->IsPet() ||
	        !TO< Pet* >(unitTarget)->GetPetOwner() || TO< Pet* >(unitTarget)->GetPetOwner()->getClass() != HUNTER)
		return;

	unitTarget->SetByte(UNIT_FIELD_BYTES_2, 2, PET_RENAME_ALLOWED);
}

void Spell::SpellEffectRestoreHealthPct(uint32 i)
{
	if(unitTarget == NULL || !unitTarget->isAlive())
		return;

	uint32 currentHealth = unitTarget->GetHealth();
	uint32 maxHealth = unitTarget->GetMaxHealth();
	uint32 modHealth = damage * maxHealth / 100;
	uint32 newHealth = modHealth + currentHealth;

	uint32 overheal = 0;
	if(newHealth >= maxHealth)
	{
		unitTarget->SetHealth(maxHealth);
		overheal = newHealth - maxHealth;
	}
	else
		unitTarget->ModHealth(modHealth);

	SendHealSpellOnPlayer(m_caster, unitTarget, modHealth, false, overheal, pSpellId ? pSpellId : GetProto()->Id);
}

void Spell::SpellEffectLearnSpec(uint32 i)
{
	if(p_caster == NULL)
		return;

	p_caster->m_talentSpecsCount = 2;
	p_caster->smsg_TalentsInfo(false);
}

void Spell::SpellEffectActivateSpec(uint32 i)
{
	if(p_caster == NULL)
		return;

	if(p_caster->CombatStatus.IsInCombat())
	{
		SendCastResult(SPELL_FAILED_AFFECTING_COMBAT);
		return;
	}
	else if(p_caster->m_bg)
	{
		uint32 Type = p_caster->m_bg->GetType();
		if(IS_ARENA(Type))
		{
			SendCastResult(SPELL_FAILED_AFFECTING_COMBAT); // does the job
			return;
		}
		else
		{
			if(p_caster->m_bg->HasStarted())
			{
				SendCastResult(SPELL_FAILED_AFFECTING_COMBAT); // does the job
			}
		}
	}

	uint8 NewSpec = p_caster->m_talentActiveSpec == SPEC_PRIMARY ? SPEC_SECONDARY : SPEC_PRIMARY; // Check if primary spec is on or not
	p_caster->ActivateSpec(NewSpec);

	WorldPacket data(SMSG_ACTION_BUTTONS, PLAYER_ACTION_BUTTON_SIZE + 1);

	data << uint8(1); // Force the client to reset the actionbar and use new values

	for(uint32 j = 0; j < PLAYER_ACTION_BUTTON_COUNT; ++j)
	{
		data << p_caster->m_specs[NewSpec].mActions[j].Action;
		data << p_caster->m_specs[NewSpec].mActions[j].Type;
		data << p_caster->m_specs[NewSpec].mActions[j].Misc;
	}

	p_caster->GetSession()->SendPacket(&data);
	p_caster->SetPower(p_caster->GetPowerType(), 0);
	p_caster->SendPowerUpdate(false);
}

void Spell::SpellEffectDurabilityDamage(uint32 i)
{
	if(!unitTarget || !unitTarget->IsPlayer())
		return;

	int16 slot = int16(GetProto()->EffectMiscValue[i]);

	Item* pItem;
	Container* pContainer;
	uint32 j, k;

	// FIXME: some spells effects have value -1/-2
	// Possibly its mean -1 all player equipped items and -2 all items
	if(slot < 0)
	{
		for(k = 0; k < MAX_INVENTORY_SLOT; k++)
		{
			pItem = p_caster->GetItemInterface()->GetInventoryItem(static_cast<uint16>(k));
			if(pItem != NULL)
			{
				if(pItem->IsContainer())
				{
					pContainer = TO< Container* >(pItem);
					for(j = 0; j < pContainer->GetProto()->ContainerSlots; ++j)
					{
						pItem = pContainer->GetItem(static_cast<uint16>(j));
						if(pItem != NULL)
						{
							uint32 maxdur = pItem->GetDurabilityMax();
							uint32 olddur = pItem->GetDurability();
							uint32 newdur = (olddur) - (damage);

							if(static_cast<int32>(newdur) < 0)
								newdur = 0;

							if(newdur > maxdur)
								newdur = maxdur;

							pItem->SetDurability(newdur);
						}
					}
				}
				else
				{
					uint32 maxdur = pItem->GetDurabilityMax();
					uint32 olddur = pItem->GetDurability();
					uint32 newdur = (olddur) - (damage);

					if(static_cast<int32>(newdur) < 0)
						newdur = 0;

					if(newdur > maxdur)
						newdur = maxdur;

					// Apply / Disapply enchantements from this item
					pItem->SetDurability(newdur);
					if(newdur == 0 && olddur > 0)
						p_caster->ApplyItemMods(pItem, static_cast<uint16>(k), false);
					else if(newdur > 0 && olddur == 0)
						p_caster->ApplyItemMods(pItem, static_cast<uint16>(k), true);
				}
			}
		}
		return;
	}

	// invalid slot value
	if(slot >= INVENTORY_SLOT_BAG_END)
		return;

	pItem = p_caster->GetItemInterface()->GetInventoryItem(slot);
	if(pItem)
	{
		uint32 maxdur = pItem->GetDurabilityMax();
		uint32 olddur = pItem->GetDurability();
		uint32 newdur = (olddur) - (damage);

		if(static_cast<int32>(newdur) < 0)
			newdur = 0;

		if(newdur > maxdur)
			newdur = maxdur;

		pItem->SetDurability(newdur);

		// Apply / Disapply enchantements from this item
		if(newdur == 0 && olddur > 0)
			p_caster->ApplyItemMods(pItem, slot, false);
		else if(newdur > 0 && olddur == 0)
			p_caster->ApplyItemMods(pItem, slot, true);
	}
}

void Spell::SpellEffectDurabilityDamagePCT(uint32 i)
{
	if(!unitTarget || !unitTarget->IsPlayer())
		return;

	int16 slot = int16(GetProto()->EffectMiscValue[i]);

	Item* pItem;
	Container* pContainer;
	uint32 j, k;

	// FIXME: some spells effects have value -1/-2
	// Possibly its mean -1 all player equipped items and -2 all items
	if(slot < 0)
	{
		for(k = 0; k < MAX_INVENTORY_SLOT; k++)
		{
			pItem = p_caster->GetItemInterface()->GetInventoryItem(static_cast<uint16>(k));
			if(pItem != NULL)
			{
				if(pItem->IsContainer())
				{
					pContainer = TO< Container* >(pItem);
					for(j = 0; j < pContainer->GetProto()->ContainerSlots; ++j)
					{
						pItem = pContainer->GetItem(static_cast<uint16>(j));
						if(pItem != NULL)
						{
							uint32 maxdur = pItem->GetDurabilityMax();
							uint32 olddur = pItem->GetDurability();
							uint32 newdur = (olddur - (uint32)(maxdur * (damage / 100.0)));

							if(static_cast<int32>(newdur) < 0)
								newdur = 0;

							if(newdur > maxdur)
								newdur = maxdur;

							pItem->SetDurability(newdur);
						}
					}
				}
				else
				{
					uint32 maxdur = pItem->GetDurabilityMax();
					uint32 olddur = pItem->GetDurability();
					uint32 newdur = (olddur - (uint32)(maxdur * (damage / 100.0)));

					if(static_cast<int32>(newdur) < 0)
						newdur = 0;

					if(newdur > maxdur)
						newdur = maxdur;

					// Apply / Disapply enchantements from this item
					pItem->SetDurability(newdur);
					if(newdur == 0 && olddur > 0)
						p_caster->ApplyItemMods(pItem, static_cast<uint16>(k), false);
					else if(newdur > 0 && olddur == 0)
						p_caster->ApplyItemMods(pItem, static_cast<uint16>(k), true);
				}
			}
		}
		return;
	}

	// invalid slot value
	if(slot >= INVENTORY_SLOT_BAG_END)
		return;

	if(damage <= 0)
		return;

	pItem = p_caster->GetItemInterface()->GetInventoryItem(slot);
	if(pItem)
	{
		uint32 maxdur = pItem->GetDurabilityMax();
		uint32 olddur = pItem->GetDurability();
		uint32 newdur = (olddur - (uint32)(maxdur * (damage / 100.0)));

		if(static_cast<int32>(newdur) < 0)
			newdur = 0;

		if(newdur > maxdur)
			newdur = maxdur;

		pItem->SetDurability(newdur);

		// Apply / Disapply enchantements from this item
		if(newdur == 0 && olddur > 0)
			p_caster->ApplyItemMods(pItem, slot, false);
		else if(newdur > 0 && olddur == 0)
			p_caster->ApplyItemMods(pItem, slot, true);
	}
}

void Spell::SpellEffectActivateRunes(uint32 i)
{
	if(p_caster == NULL || ! p_caster->IsDeathKnight())
		return;

	DeathKnight* dk = TO_DK(p_caster);

	uint32 count = damage;
	if(! count)
		count = 1;

	for(uint8 x = 0; x < MAX_RUNES && count; ++x)
	{
		if(dk->GetRuneType(x) == GetProto()->EffectMiscValue[i] && dk->GetRuneIsUsed(x))
		{
			dk->ResetRune(x);
			--count;
		}
	}
}

void Spell::SpellEffectSetMirrorName(uint32 i)
{
	WorldPacket data(SMSG_CLEAR_TARGET, 8);
	data << uint64(m_caster->GetGUID());
	m_caster->SendMessageToSet(&data, true);
}
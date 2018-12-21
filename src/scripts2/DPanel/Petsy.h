/*
 * AUDB MMORPG Database
 * Copyright (C) 2008-2009 <http://www.AUDB.co.cc/>
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

#ifndef Pets_H
#define Pets_h

///////////////////////////////////////////////////////////////////////////////
////////////////////////////Global Script///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define NEUTRAL_ID 80009           // Dj NPC Id
#define NPC_ID3 50002          // Beast Master
#define HORDEBASE_ID 80007    // Horde Base Commander
#define ALLYBASE_ID 80008     // Ally     Base Commander
#define VIPITEM 1337     // Vip Item
#define MOUNTI 1338     // Mountitem
#define BEAST_NPC 50002
#define ARENA_NPC 40008


///////////////////////////////////////////////////////////////////////////////
//////////////////////////// Serverbuffer///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define REWARD_GOLD 2500
#define REWARD_TICK 3600000

///////////////////////////////////////////////////////////////////////////////
////////////////////////////RANDOM/////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
 
 
#define CLEANTIMER 360000
#define BUGANNOUNCE 300000
 
// VIP Appear error
#define FP_ERR(s)\
Plr->BroadcastMessage(s);\
Plr->Gossip_Complete();\
return;\


#define CreatePet(Entry)\
	if(Plr->getClass() != HUNTER)\
	{\
		Plr->Gossip_Complete();\
	}\
	else {\
		CreatureProto * pTemplate = CreatureProtoStorage.LookupEntry(Entry);\
		CreatureInfo * pCreatureInfo = CreatureNameStorage.LookupEntry(Entry);\
		Creature* pCreature(new Creature(0xF1300000));\
		CreatureSpawn * sp = new CreatureSpawn;\
		Player* pPlayer = Plr;\
		sp->id = 1;\
		sp->bytes0 = 0;\
		sp->bytes2 = 0;\
		sp->displayid = pCreatureInfo->Male_DisplayID;\
		sp->emote_state = 0;\
		sp->entry = pCreatureInfo->Id;\
		sp->factionid = 35;\
		sp->flags = 0;\
		sp->form = 0;\
		sp->movetype = 0;\
		sp->o = pPlayer->GetOrientation();\
		sp->x = pPlayer->GetPositionX();\
		sp->y = pPlayer->GetPositionY();\
		sp->channel_spell = sp->channel_target_creature = sp->channel_target_go=0;\
		pCreature->Load(sp, (uint32)NULL, NULL);\
		Pet* old_pet = pPlayer->GetSummon();\
		if(old_pet != NULL)\
			old_pet->Dismiss(true);\
		Pet* pPet = objmgr.CreatePet(Entry);\
		pPet->SetInstanceID(pPlayer->GetInstanceID());\
		pPet->SetMapId(pPlayer->GetMapId());\
		pPet->SetFloatValue(OBJECT_FIELD_SCALE_X, pTemplate->Scale / 2);\
		pPet->CreateAsSummon(Entry, pCreatureInfo, pCreature, pPlayer, NULL, 0x2, 0);\
		pPet->Rename("Pet");\
		Pet->SetUInt32Value(UNIT_FIELD_POWER5, PET_HAPPINESS_UPDATE_VALUE << 3);\
		Pet->SetUInt32Value(UNIT_FIELD_BYTES_1, 0 | (BEST_FRIEND << 8));\
		Pet->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, 0);\
		pPet->SendSpellsToOwner();\
		delete sp;\
		delete pCreature;\
		} 
 /*
// Pet summoning Case
#define CreatePet(E)\
if(Plr->getClass() != HUNTER)\
	{\
		Plr->Gossip_Complete();\
		return;\
	}\
	int HP = 0;\
	if(Plr->GetSummon())\
		{\
			HP = Plr->GetSummon()->GetHealthPct();\
			Plr->GetSummon()->Dismiss(true);\
		}\
		Pet* Pet = objmgr.CreatePet();\
		Pet->SetInstanceID(Plr->GetInstanceID());\
		Pet->CreateAsSummon(E, CreatureNameStorage.LookupEntry(E), NULL, Plr, NULL, 1, 0);\
		if(HP)Pet->SetUInt32Value(UNIT_FIELD_HEALTH, (Pet->GetUInt32Value(UNIT_FIELD_MAXHEALTH) * HP / 100));\
			Pet->SetUInt32Value(UNIT_FIELD_POWER5, PET_HAPPINESS_UPDATE_VALUE << 3);\
			Pet->Rename("Pet Power");\
			Pet->SendSpellsToOwner();\
			Pet->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, 0);\
			Pet->SetUInt32Value(UNIT_FIELD_POWER3, 100);\
			Pet->SetUInt32Value(UNIT_FIELD_MAXPOWER3, 100);\
			Pet->SetUInt32Value(UNIT_FIELD_BYTES_2, 1 | (0x3 << 16));\
			Pet->ResetTalents(true);\
			Pet->SetPowerType(POWER_TYPE_FOCUS);\
			Pet->SetDefaultSpells();\
			Plr->Gossip_Complete();\
/*

#define CreatePet(Entry)\
	if(Plr->getClass() != HUNTER)\
	{\
		Plr->Gossip_Complete();\
	}\
	else {\
		CreatureProto * pTemplate = CreatureProtoStorage.LookupEntry(Entry);\
		CreatureInfo * pCreatureInfo = CreatureNameStorage.LookupEntry(Entry);\
		Creature* pCreature(new Creature(0xF1300000));\
		CreatureSpawn * sp = new CreatureSpawn;\
		Player* pPlayer = Plr;\
		sp->id = 1;\
		sp->bytes0 = 0;\
		sp->bytes2 = 0;\
		sp->displayid = pCreatureInfo->Male_DisplayID;\
		sp->emote_state = 0;\
		sp->entry = pCreatureInfo->Id;\
		sp->factionid = 35;\
		sp->flags = 0;\
		sp->form = 0;\
		sp->movetype = 0;\
		sp->o = pPlayer->GetOrientation();\
		sp->x = pPlayer->GetPositionX();\
		sp->y = pPlayer->GetPositionY();\
		sp->channel_spell = sp->channel_target_creature = sp->channel_target_go=0;\
		pCreature->Load(sp, (uint32)NULL, NULL);\
		Pet* old_pet = pPlayer->GetSummon();\
		if(old_pet != NULL)\
			old_pet->Dismiss(true);\
		Pet* pPet = objmgr.CreatePet();\
		pPet->SetInstanceID(pPlayer->GetInstanceID());\
		pPet->SetMapId(pPlayer->GetMapId());\
		pPet->SetFloatValue(OBJECT_FIELD_SCALE_X, pTemplate->Scale / 2);\
		pPet->CreateAsSummon(Entry, pCreatureInfo, pCreature, pPlayer, NULL, 0x2, 0);\
		pPet->Rename("Pet");\
		Pet->SetUInt32Value(UNIT_FIELD_POWER5, PET_HAPPINESS_UPDATE_VALUE << 3);\
		Pet->SetUInt32Value(UNIT_FIELD_BYTES_1, 0 | (BEST_FRIEND << 8));\
		Pet->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, 0);\
		pPet->SendSpellsToOwner();\
		delete sp;\
		delete pCreature;\
		} 
*/

#define GiveGold(AMOUNT)\
uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);\
uint32 newgold = currentgold + AMOUNT;\
Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);\

/*
case 1:
{
GiveGold(100);
return;
}
*/
	
#define TakeGold(AMOUNT)\
uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);\
uint32 newgold = currentgold - AMOUNT;\
Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);\

/*
case 1:
{
TakeGold(100);
return;
}
*/

///////////////////////////////////////////////////////////////////////////////
////////////////////////////PvP System/////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define PVP_GOLD 100


#endif

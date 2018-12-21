/*
* ArcEmu MMORPG Server
* Copyright (C) 2008-2014 <http://www.ArcEmu.org/>
* Copyright (C) 2008-2009 Sun++ Team <http://www.sunscripting.com/>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "Setup.h"

struct Location EventPreGuardSP[] = //PortalGuard spwns
{
	{ 1888.046265f, 761.654053f, 47.667f, 2.2332f }, // [0] left
	{ 1928.545532f, 803.849731f, 52.411f, 3.1223f }, // [1] center
	{ 1878.080933f, 844.850281f, 43.334f, 4.2376f }  // [2] right
};

struct Location EventPreGuardWP[] = //PortalGuard WPs
{
	{ 1858.386353f, 812.804993f, 42.9995f, 4.2376f }, // [0] left
	{ 1861.916382f, 803.873230f, 43.6728f, 3.1223f }, // [1] center
	{ 1858.678101f, 796.081970f, 43.1944f, 2.2332f }  // [2] right
};

enum DataIndex
{
	TVH_PHASE_1 = 0, // main event
	TVH_PHASE_2 = 1, // 1. portal
	TVH_PHASE_3 = 2, // 2. portal
	TVH_PHASE_4 = 3, // 3. portal
	TVH_PHASE_5 = 4, // 4. portal
	TVH_PHASE_6 = 5, // 5. portal
	TVH_PHASE_DONE = 6, // 6. portal

	TVH_END = 7
};

enum TVH_ENTRIES
{
	//Map stuff
	MAP_VIOLET_HOLD = 608,
	AREA_VIOLET_HOLD = 4415,

	//Main event
	CN_LIEUTNANT_SINCLARI = 30658,
	CN_VIOLET_HOLD_GUARD = 30659,
	CN_PORTAL_GUARDIAN = 30660, //enemies
	CN_PORTAL_INTRO = 31011, //portals, not a go its a creature ;)
	CN_CRYSTAL_SYSTEM = 30837, // NPC with spell arcane spher

	//Portal Guardians (Normal)
	CN_AZURE_INVADER = 30661,
	CN_AZURE_SPELLBREAKER = 30662,
	CN_AZURE_BINDER = 30663,
	CN_AZURE_MAGE_SLAYER = 30664,
	CN_AZURE_CAPTAIN = 30666,
	CN_AZURE_SORCEROR = 30667,
	CN_AZURE_RAIDER = 30668,
	CN_AZURE_STALKER = 32191,

	//Bosses
	CN_EREKEM = 29315,
	CN_MORAGG = 29316,
	CN_ICHORON = 29313,
	CN_XEVOZZ = 29266,
	CN_LAVANTHOR = 29312,
	CN_TURAMAT_THE_OBLITERATOR = 29314,
	CN_CYANIGOSA = 31134,

	//Spell Crytals
	SPELL_ARCANE_LIGHTNING = 57930,

	//Crystals
	GO_INTRO_ACTIVATION_CRYSTAL = 193615,
	GO_ACTIVATION_CRYSTAL = 193611,

	//Door
	GO_PRISON_SEAL = 191723,
	GO_XEVOZZ_DOOR = 191556,
	GO_LAVANTHOR_DOOR = 191566,
	GO_ICHORON_DOOR = 191722,
	GO_ZURAMAT_THE_OBLITERATOR_DOOR = 191565,
	GO_EREKEM_DOOR = 191564,
	GO_MORAGG_DOOR = 191606
};

///////////////////////////////////////////////////////
//TheVioletHold Instance
class TheVioletHoldScript : public MoonInstanceScript
{
	friend class SinclariGossip; // Friendship forever ;-)

private:
	int32 m_numBarrel;
	uint32 m_phaseData[TVH_END];

public:
	MOONSCRIPT_INSTANCE_FACTORY_FUNCTION(TheVioletHoldScript, MoonInstanceScript);
	TheVioletHoldScript(MapMgr* pMapMgr) : MoonInstanceScript(pMapMgr)
	{
		m_numBarrel = 0;

		for (int i = 0; i < TVH_END; ++i)
			m_phaseData[i] = State_NotStarted;
	};

	void SetData(uint32 pIndex, uint32 pData)
	{
		if (pIndex >= TVH_END)
			return;

		// If Data = MainEvent, set state "PreProgress". Gossip Sinclar 1 + 2
		if (pIndex == TVH_PHASE_1)
			mInstance->GetWorldStatesHandler().SetWorldStateForZone(0, AREA_VIOLET_HOLD, WORLDSTATE_VH, State_PreProgress);

		// If Data = second event, set state "InProgress". Gossip Sinclari Case 3
		if (pIndex == TVH_PHASE_2)
			mInstance->GetWorldStatesHandler().SetWorldStateForZone(0, AREA_VIOLET_HOLD, WORLDSTATE_VH, State_InProgress);

		m_phaseData[pIndex] = pData;
	};

	uint32 GetData(uint32 pIndex)
	{
		// If Phase = End/finishes, reset the Phases to 0
		if (pIndex >= TVH_END)
			return 0;

		return m_phaseData[pIndex];
	};

	void SetInstanceData(uint32 pType, uint32 pIndex, uint32 pData)
	{
		if (pType != Data_EncounterState || pIndex == 0)
			return;

		EncounterMap::iterator Iter = mEncounters.find(pIndex);
		if (Iter == mEncounters.end())
			return;

		(*Iter).second.mState = (EncounterState)pData;
	};

	uint32 GetInstanceData(uint32 pType, uint32 pIndex)
	{
		if (pType != Data_EncounterState || pIndex == 0)
			return 0;

		EncounterMap::iterator Iter = mEncounters.find(pIndex);
		if (Iter == mEncounters.end())
			return 0;

		return (*Iter).second.mState;
	};

	void OnGameObjectActivate(GameObject* pGameObject, Player* pPlayer)
	{
	};

	void OnPlayerEnter(Player* pPlayer)
	{
		TheVioletHoldScript* pInstance = (TheVioletHoldScript*)pPlayer->GetMapMgr()->GetScript();
		if (!pInstance)
			return;

		if (pInstance->GetInstanceData(Data_EncounterState, MAP_VIOLET_HOLD) == State_NotStarted || pInstance->GetInstanceData(Data_EncounterState, MAP_VIOLET_HOLD) == NULL)
		{
			mEncounters.insert(EncounterMap::value_type(MAP_VIOLET_HOLD, State_NotStarted));
		}

	}
};

#define SINCLARI_SAY_1 "Prison guards, we are oleaving! These adventurers are taking over! Go go go!"
#define SINCLARY_SAY_2 "I'm locking the door. Good luck, and thank you for doing this."

#define SINCLARI_MAX_WP 4

static LocationExtra SinclariWP[] = // Sinclari WPS
{
	{ },                                // 0
	{ 1829.10f, 798.63f, 44.36345f, 3.97056f, Flag_Walk },    // 1 walkt to crystal activation
	{ 1828.521f, 803.797f, 44.3641f, 0.00f, Flag_Walk },      // 2 sayevent
	{ 1818.361328f, 803.875f, 44.36453f, 3.134f, Flag_Walk }, // 3 walk outside
	{ 1820.027f, 803.97162f, 44.3635f, 0.00f, Flag_Walk }     // 4 walk behind door and locking it
};

///////////////////////////////////////////////////////
//Lieutnant Sinclari StartEvent
class SinclariAI : public MoonScriptCreatureAI
{
public:
	MOONSCRIPT_FACTORY_FUNCTION(SinclariAI, MoonScriptCreatureAI);
	SinclariAI(Creature* pCreature) : MoonScriptCreatureAI(pCreature)
	{
		_unit->GetAIInterface()->setMoveType(MOVEMENTTYPE_WANTEDWP);
		for (int i = 1; i < 4; ++i)
		{
			AddWaypoint(CreateWaypoint(i, 0, SinclariWP[i].addition, SinclariWP[i]));
		}

		phase = 0;
	}

	void OnReachWP(uint32 iWaypointId, bool bForwards)
	{
		switch (iWaypointId)
		{
			case 0:
			{
				phase++;
				sEventMgr.AddEvent(_unit, &Creature::CallScriptUpdate, EVENT_SCRIPT_UPDATE_EVENT, 1000, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
				LOG_DEBUG("SINCLARI OnReachWP:  Case 0!");
			}
			break;
			case 1:
			{
				SetMoveType(Move_WantedWP);
				SetWaypointToMove(2);
				LOG_DEBUG("SINCLARI OnReachWP:  Case 1!");
			}
			break;
			case 2:
			{
				phase++;
				LOG_DEBUG("SINCLARI OnReachWP:  Case 2!");
			}
			break;
			case 3:
			{
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, SINCLARI_SAY_1);
				LOG_DEBUG("SINCLARI OnReachWP:  Case 3!");
			}
			break;
			case 4:
			{
				LOG_DEBUG("SINCLARI OnReachWP:  Case 4!");
			}
			break;
			case 5:
			{
				_unit->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, SINCLARY_SAY_2);
				LOG_DEBUG("SINCLARI OnReachWP:  Case 5!");
			}
			break;
		}
		ParentClass::OnReachWP(iWaypointId, bForwards);
	}

	void AIUpdate()
	{
		switch (phase)
		{
			case 0:
			{
				LOG_DEBUG("SINCLARI AIUpdate:  Case 0!");
			}
			break;
			case 1:
			{
					  SetWaypointToMove(1);
				LOG_DEBUG("SINCLARI AIUpdate:  Case 1!");
			}
			break;
			case 2:
			{
				//After closing the door, instance is in progress
				TheVioletHoldScript* pInstance = (TheVioletHoldScript*)_unit->GetMapMgr()->GetScript();
				pInstance->SetInstanceData(Data_EncounterState, MAP_VIOLET_HOLD, State_InProgress);
				LOG_DEBUG("SINCLARI AIUpdate:  Case 2!");
			}
			break;
		}
	}

	protected:
		uint32 phase;
};

enum eGossipTexts
{
	SINCLARI_ON_HELLO = 13853,
	SINCLARI_ON_FINISH = 13854,
	SINCLARI_OUTSIDE = 14271
};

#define SINCLARI_MENU_1 "Activate the crystals when we get in trouble, right"
#define SINCLARI_MENU_2 "Get your people to safety, we'll keep the Blue Dragonflight's forces at bay."
#define SINCLARI_MENU_3 "I'm not fighting, so send me in now!"

///////////////////////////////////////////////////////
//Lieutnant Sinclari Gossip and init events
//Sinclari Gossip
class SinclariGossip : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* pPlayer)
	{
		TheVioletHoldScript* pInstance = (TheVioletHoldScript*)pPlayer->GetMapMgr()->GetScript();
		if (!pInstance)
			return;

		GossipMenu* menu;

		//Page 1: Textid and first menu item
		if (pInstance->GetInstanceData(Data_EncounterState, MAP_VIOLET_HOLD) == State_NotStarted)
		{
			objmgr.CreateGossipMenuForPlayer(&menu, pObject->GetGUID(), SINCLARI_ON_HELLO, pPlayer);
			menu->AddItem(Arcemu::Gossip::ICON_CHAT, SINCLARI_MENU_1, 1);

			menu->SendTo(pPlayer);
		}

		//If VioletHold is started, Sinclari has this item for people who aould join.
		if (pInstance->GetInstanceData(Data_EncounterState, MAP_VIOLET_HOLD) == State_InProgress)
		{
			objmgr.CreateGossipMenuForPlayer(&menu, pObject->GetGUID(), SINCLARI_OUTSIDE, pPlayer);
			menu->AddItem(Arcemu::Gossip::ICON_CHAT, SINCLARI_MENU_3, 3);

			menu->SendTo(pPlayer);
		}
	};

	void GossipSelectOption(Object* pObject, Player*  pPlayer, uint32 Id, uint32 IntId, const char* Code)
	{

		TheVioletHoldScript* pInstance = (TheVioletHoldScript*)pPlayer->GetMapMgr()->GetScript();

		if (!pInstance)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, pPlayer);
				break;

			case 1:
			{
				  GossipMenu* menu;
				  objmgr.CreateGossipMenuForPlayer(&menu, pObject->GetGUID(), SINCLARI_ON_FINISH, pPlayer);
				  menu->AddItem(Arcemu::Gossip::ICON_CHAT, SINCLARI_MENU_2, 2);
				  menu->SendTo(pPlayer);

				  // New Encounter State included
				  pInstance->SetInstanceData(Data_EncounterState, MAP_VIOLET_HOLD, State_PreProgress);

				  /* Maybe an extra event???
				  - Spawning portals + portalguards
				  - attacking guards */

			}break;

			case 2:
			{
					  TO_CREATURE(pObject)->SetUInt32Value(UNIT_NPC_FLAGS, 0);
					  TO_CREATURE(pObject)->GetScript()->OnReachWP(0, 0);

			}break;

			case 3:
			{
				  Arcemu::Gossip::Menu::Complete(pPlayer);
				  pPlayer->SafeTeleport(pPlayer->GetInstanceID(), MAP_VIOLET_HOLD, 1830.531006f, 803.939758f, 44.340508f, 6.281611f);
			}break;
		}
	}
};

///////////////////////////////////////////////////////
//Boss: Erekem
//class ErekemAI : public CreatureAIScript

///////////////////////////////////////////////////////
//Boss: Moragg
//class MoraggAI : public CreatureAIScript

///////////////////////////////////////////////////////
//Boss: Ichoron
//class IchoronAI : public CreatureAIScript

///////////////////////////////////////////////////////
//Boss: Xevozz
//class XevozzAI : public CreatureAIScript

///////////////////////////////////////////////////////
//Boss: Lavanthos
//class LavanthosAI : public CreatureAIScript

///////////////////////////////////////////////////////
//Boss: Zuramat the Obliterator
//class ZuramatTheObliteratorAI : public CreatureAIScript

///////////////////////////////////////////////////////
//Final Boss: Cyanigosa
//class CyanigosaAI : public CreatureAIScript


void SetupTheVioletHold(ScriptMgr* mgr)
{
	//Instance
	mgr->register_instance_script(MAP_VIOLET_HOLD, &TheVioletHoldScript::Create);

	//Sinclari and Guards
	mgr->register_creature_script(CN_LIEUTNANT_SINCLARI, &SinclariAI::Create);
	//mgr->register_creature_script(CN_VIOLET_HOLD_GUARD, &VHGuardsAI::Create);

	//Bosses
	//mgr->register_creature_script(CN_EREKEM, &ErekemAI::Create);
	//mgr->register_creature_script(CN_MORAGG, &MoraggAI::Create);
	//mgr->register_creature_script(CN_ICHORON, &IchoronAI::Create);
	//mgr->register_creature_script(CN_XEVOZZ, &XevozzAI::Create);
	//mgr->register_creature_script(CN_LAVANTHOR, &LavanthorAI::Create);
	//mgr->register_creature_script(CN_TURAMAT_THE_OBLITERATOR, &ZuramatTheObliteratorAI::Create);
	//mgr->register_creature_script(CN_CYANIGOSA, &CyanigosaAI::Create);

	GossipScript* GSinclari = new SinclariGossip;
	mgr->register_gossip_script(CN_LIEUTNANT_SINCLARI, GSinclari);


}
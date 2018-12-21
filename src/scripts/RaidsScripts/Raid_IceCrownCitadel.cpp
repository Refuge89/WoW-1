/*
 * ArcEmu MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 * Copyright (C) 2008-2014 <http://www.ArcEmu.org/>
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

#include "Setup.h"
#include "Raid_IceCrownCitadel.h"

////////////////////////////////////////////////////////
//ICC zone: 4812
//Prepared creature entry:
//
//#define CN_DEATHBRINGER_SAURFANG    37813
//#define CN_FESTERGUT                36626
//#define CN_ROTFACE                  36627
//#define CN_PROFESSOR_PUTRICIDE      36678
//#define CN_PRINCE_VALANAR           37970
//#define CN_BLOOD_QUEEN_LANATHEL     37955
//#define CN_SINDRAGOSA               36853
//#define CN_THE_LICHKING             36597
//
//ToDo: start boss scripts
////////////////////////////////////////////////////////
//Event: GunshipBattle
//
//Affects:
//Available teleports. If GunshipBattle done -> Teleportlocation 4 available.
//
//Devnotes:
//Far away from implementing this :(
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
//IceCrownCitadel Instance

class IceCrownCitadelScript : public MoonInstanceScript
{
	friend class ICCTeleporterAI; // Friendship forever ;-)

public:
	MOONSCRIPT_INSTANCE_FACTORY_FUNCTION(IceCrownCitadelScript, MoonInstanceScript);

	uint32 mMarrowgarGUID;
	uint32 mColdflameGUID;
	uint32 mDeathwhisperGUID;
	uint32 mDreamwalkerGUID;

	IceCrownCitadelScript(MapMgr* pMapMgr) : MoonInstanceScript(pMapMgr) 
	{
		//NPC states
		mMarrowgarGUID = 0;
		mColdflameGUID = 0;
		mDeathwhisperGUID = 0;
		mDreamwalkerGUID = 0;
		LadyDeathwisperElevatorGUID = 0;
		GunshipGUID = 0;
		EnemyGunshipGUID = 0;
		GunshipArmoryGUID = 0;
		DeathbringerSaurfangGUID = 0;
		DeathbringerSaurfangDoorGUID = 0;
		DeathbringerSaurfangEventGUID = 0;
		DeathbringersCacheGUID = 0;
		SaurfangTeleportGUID = 0;
		PlagueSigilGUID = 0;
		BloodwingSigilGUID = 0;
		FrostwingSigilGUID = 0;
		memset(PutricidePipeGUIDs, 0, 2 * sizeof(uint64));
		memset(PutricideGateGUIDs, 0, 2 * sizeof(uint64));
		PutricideCollisionGUID = 0;
		FestergutGUID = 0;
		RotfaceGUID = 0;
		ProfessorPutricideGUID = 0;
		PutricideTableGUID = 0;
		memset(BloodCouncilGUIDs, 0, 3 * sizeof(uint64));
		BloodCouncilControllerGUID = 0;
		BloodQueenLanaThelGUID = 0;
		CrokScourgebaneGUID = 0;
		memset(CrokCaptainGUIDs, 0, 4 * sizeof(uint64));
		SisterSvalnaGUID = 0;
		ValithriaDreamwalkerGUID = 0;
		ValithriaLichKingGUID = 0;
		ValithriaTriggerGUID = 0;
		SindragosaGUID = 0;
		SpinestalkerGUID = 0;
		RimefangGUID = 0;
		TheLichKingTeleportGUID = 0;
		TheLichKingGUID = 0;
		HighlordTirionFordringGUID = 0;
		TerenasMenethilGUID = 0;
		ArthasPlatformGUID = 0;
		ArthasPrecipiceGUID = 0;
		FrozenThroneEdgeGUID = 0;
		FrozenThroneWindGUID = 0;
		FrozenThroneWarningGUID = 0;
		BloodQuickeningMinutes = 0;
		KorKronGeneralGUID = 0;
		KorKronLieutnantGUID = 0;
		TurTunokGUID = 0;
		GeradoTheSuaveGUID = 0;
		UvulusBanefireGUID = 0;
		IkifirusTheVileGUID = 0;
		VolGukGUID = 0;
		HaraggTheUnseenGUID = 0;
		GarroshHellscreamGUID = 0;
		HighOverlordSaurfangGUID = 0;
		KorKronReaverGUID = 0;
		AllianceCommanderGUID = 0;
		SkybreakerLieutnantGUID = 0;
		AlanaMoonstrikeGUID = 0;
		TalanMoonstrikeGUID = 0;
		MalfusGrimfrostGUID = 0;
		YiliGUID = 0;
		JedebiaGUID = 0;
		NibyTheAlmightyGUID = 0;
		KingVarianWrymGUID = 0;
		MuradinBronzebardGUID = 0;
		SkybreakerMarineGUID = 0;
		//GO states
		mMarrowIceDoor1_GUID = 0;
		mMarrowIceDoor2_GUID = 0;
		mMarrowDoor_GUID = 0;

		// Set Team to 0
		InstanceTeam = 0;
	}

	// Get Playerteam for spawns (TODO: despawn horde or alli) 
	void OnPlayerEnter(Player* pPlayer)
	{
		if(!InstanceTeam)
			InstanceTeam = pPlayer->GetTeam();
	}

	void OnGameObjectPushToWorld(GameObject* pGameObject)
	{
		switch(pGameObject->GetEntry())
		{
			case GO_MARROWGAR_ICEWALL_1:
				mMarrowIceDoor1_GUID = pGameObject->GetGUID();
				break;
			case GO_MARROWGAR_ICEWALL_2:
				mMarrowIceDoor2_GUID = pGameObject->GetGUID();
				break;
			case GO_MARROWGAR_DOOR:
				mMarrowDoor_GUID = pGameObject->GetGUID();
				break;
		}
	}

	void OnCreaturePushToWorld(Creature* pCreature)
	{
		switch(pCreature->GetEntry())
		{
			// First set state
			case CN_LORD_MARROWGAR:
				{
					mMarrowgarGUID = pCreature->GetLowGUID();
					mEncounters.insert(EncounterMap::value_type(CN_LORD_MARROWGAR, BossData(0, mMarrowgarGUID)));

				}break;

			case CN_LADY_DEATHWHISPER:
				{
					mDeathwhisperGUID = pCreature->GetLowGUID();
					mEncounters.insert(EncounterMap::value_type(CN_LADY_DEATHWHISPER, BossData(0, mDeathwhisperGUID)));

				}break;

			case CN_VALITHRIA_DREAMWALKER:
				{
					mDreamwalkerGUID = pCreature->GetLowGUID();
					mEncounters.insert(EncounterMap::value_type(CN_VALITHRIA_DREAMWALKER, BossData(0, mDreamwalkerGUID)));

				}break;

			case CN_COLDFLAME:
				{
					mColdflameGUID = pCreature->GetLowGUID();
					mEncounters.insert(EncounterMap::value_type(CN_COLDFLAME, BossData(0, mColdflameGUID)));

				}break;

			// Check if team = 0 horde
			if(InstanceTeam = TEAM_HORDE)
			{
				case CN_KOR_KRON_GENERAL: 
					KorKronGeneralGUID = pCreature->GetLowGUID();
					break;
				case CN_KOR_KRON_LIEUTENANT:
					KorKronLieutnantGUID = pCreature->GetLowGUID();
					break;
				case CN_TORTUNOK: 
					TurTunokGUID = pCreature->GetLowGUID();
					break;
				case CN_GERARDO_THE_SUAVE: 
					GeradoTheSuaveGUID = pCreature->GetLowGUID();
					break;
				case CN_UVLUS_BANEFIRE: 
					UvulusBanefireGUID = pCreature->GetLowGUID();
					break;
				case CN_IKFIRUS_THE_VILE: 
					IkifirusTheVileGUID = pCreature->GetLowGUID();
					break;
				case CN_VOL_GUK: 
					VolGukGUID = pCreature->GetLowGUID();
					break;
				case CN_HARAGG_THE_UNSEEN: 
					HaraggTheUnseenGUID = pCreature->GetLowGUID();
					break;
				case CN_GARROSH_HELLSCREAM: 
					GarroshHellscreamGUID = pCreature->GetLowGUID();
					break;
				case CN_SE_HIGH_OVERLORD_SAURFANG: 
					HighOverlordSaurfangGUID = pCreature->GetLowGUID();
					break;
				case CN_SE_KOR_KRON_REAVER: 
					KorKronReaverGUID = pCreature->GetLowGUID();
					break;
			}else{
				case CN_ALLIANCE_COMMANDER: 
					AllianceCommanderGUID = pCreature->GetLowGUID();
					break;
				case CN_SKYBREAKER_LIEUTENANT: 
					SkybreakerLieutnantGUID = pCreature->GetLowGUID();
					break;
				case CN_ALANA_MOONSTRIKE: 
					AlanaMoonstrikeGUID = pCreature->GetLowGUID();
					break;
				case CN_TALAN_MOONSTRIKE: 
					TalanMoonstrikeGUID = pCreature->GetLowGUID();
					break;
				case CN_MALFUS_GRIMFROST: 
					MalfusGrimfrostGUID = pCreature->GetLowGUID();
					break;
				case CN_YILI: 
					YiliGUID = pCreature->GetLowGUID();
					break;
				case CN_JEDEBIA: 
					JedebiaGUID = pCreature->GetLowGUID();
					break;
				case CN_NIBY_THE_ALMIGHTY: 
					NibyTheAlmightyGUID = pCreature->GetLowGUID();
					break;
				case CN_KING_VARIAN_WRYNN: 
					KingVarianWrymGUID = pCreature->GetLowGUID();
					break;
				case CN_SE_MURADIN_BRONZEBEARD: 
					MuradinBronzebardGUID = pCreature->GetLowGUID();
					break;
				case CN_SE_SKYBREAKER_MARINE: 
					SkybreakerMarineGUID = pCreature->GetLowGUID();
					break;
			}
			default:
				break;
		}
	};

	void OnCreatureRemoveFromWorld(Creature* pCreature)
	{
		switch(pCreature->GetEntry())
		{
			if(InstanceTeam = TEAM_HORDE)
			{
				case CN_ALLIANCE_COMMANDER:
					AllianceCommanderGUID = 0;
					break;
				case CN_SKYBREAKER_LIEUTENANT:
					SkybreakerLieutnantGUID = 0;
					break;
				case CN_ALANA_MOONSTRIKE:
					AlanaMoonstrikeGUID = 0;
					break;
				case CN_TALAN_MOONSTRIKE:
					TalanMoonstrikeGUID = 0;
					break;
				case CN_MALFUS_GRIMFROST:
					MalfusGrimfrostGUID = 0;
					break;
				case CN_YILI:
					YiliGUID = 0;
					break;
				case CN_JEDEBIA:
					JedebiaGUID = 0;
					break;
				case CN_NIBY_THE_ALMIGHTY:
					NibyTheAlmightyGUID = 0;
					break;
				case CN_KING_VARIAN_WRYNN:
					KingVarianWrymGUID = 0;
					break;
				case CN_SE_MURADIN_BRONZEBEARD:
					MuradinBronzebardGUID = 0;
					break;
				case CN_SE_SKYBREAKER_MARINE:
					SkybreakerMarineGUID = 0;
					break;
			}else{
				case CN_KOR_KRON_GENERAL:
					KorKronGeneralGUID = 0;
					break;
				case CN_KOR_KRON_LIEUTENANT:
					KorKronLieutnantGUID = 0;
					break;
				case CN_TORTUNOK:
					TurTunokGUID = 0;
					break;
				case CN_GERARDO_THE_SUAVE:
					GeradoTheSuaveGUID = 0;
					break;
				case CN_UVLUS_BANEFIRE:
					UvulusBanefireGUID = 0;
					break;
				case CN_IKFIRUS_THE_VILE:
					IkifirusTheVileGUID = 0;
					break;
				case CN_VOL_GUK:
					VolGukGUID = 0;
					break;
				case CN_HARAGG_THE_UNSEEN:
					HaraggTheUnseenGUID = 0;
					break;
				case CN_GARROSH_HELLSCREAM:
					GarroshHellscreamGUID = 0;
					break;
				case CN_SE_HIGH_OVERLORD_SAURFANG:
					HighOverlordSaurfangGUID = 0;
					break;
				case CN_SE_KOR_KRON_REAVER:
					KorKronReaverGUID = 0;
					break;
			}
		}
	}

	void SetInstanceData(uint32 pType, uint32 pIndex, uint32 pData)
	{
		if(pType != Data_EncounterState || pIndex == 0)
			return;

		EncounterMap::iterator Iter = mEncounters.find(pIndex);
		if(Iter == mEncounters.end())
			return;

		(*Iter).second.mState = (EncounterState)pData;
	};

	uint32 GetInstanceData(uint32 pType, uint32 pIndex)
	{
		if(pType != Data_EncounterState || pIndex == 0)
			return 0;

		EncounterMap::iterator Iter = mEncounters.find(pIndex);
		if(Iter == mEncounters.end())
			return 0;

		return (*Iter).second.mState;
	};

	void OnCreatureDeath(Creature* pCreature, Unit* pUnit)
	{
		EncounterMap::iterator Iter = mEncounters.find(pCreature->GetEntry());
		if(Iter == mEncounters.end())
			return;

		(*Iter).second.mState = State_Finished;

		switch(pCreature->GetEntry())
		{
			case CN_LORD_MARROWGAR:
			{
				SetInstanceData(Data_EncounterState, CN_LORD_MARROWGAR, State_Finished);

				GameObject* pMarrowIceDoor1 = FindClosestGameObjectOnMap(GO_MARROWGAR_ICEWALL_1, Doors[0].x, Doors[0].y, Doors[0].z);
				if(pMarrowIceDoor1 != NULL)
					pMarrowIceDoor1->SetState(GAMEOBJECT_STATE_OPEN);

				GameObject* pMarrowIceDoor2 = FindClosestGameObjectOnMap(GO_MARROWGAR_ICEWALL_2, Doors[1].x, Doors[1].y, Doors[1].z);
				if(pMarrowIceDoor2 != NULL)
					pMarrowIceDoor2->SetState(GAMEOBJECT_STATE_OPEN);

				GameObject* pMarrowDoor = FindClosestGameObjectOnMap(GO_MARROWGAR_DOOR, Doors[2].x, Doors[2].y, Doors[2].z);
				if(pMarrowDoor != NULL)
					pMarrowDoor->SetState(GAMEOBJECT_STATE_OPEN);

			}break;

			case CN_LADY_DEATHWHISPER:
				SetInstanceData(Data_EncounterState, CN_LADY_DEATHWHISPER, State_Finished);
				break;

			case CN_VALITHRIA_DREAMWALKER:
				SetInstanceData(Data_EncounterState, CN_VALITHRIA_DREAMWALKER, State_Finished);
				break;

			case CN_COLDFLAME:
				SetInstanceData(Data_EncounterState, CN_COLDFLAME, State_Finished);
				break;

			default:
				break;
		}
		return;
	}


protected:
	uint32 mMarrowIceDoor1_GUID;
	uint32 mMarrowIceDoor2_GUID;
	uint32 mMarrowDoor_GUID;
	uint64 LadyDeathwisperElevatorGUID;
	uint64 GunshipGUID;
	uint64 EnemyGunshipGUID;
	uint64 GunshipArmoryGUID;
	uint64 DeathbringerSaurfangGUID;
	uint64 DeathbringerSaurfangDoorGUID;
	uint64 DeathbringerSaurfangEventGUID;   // Muradin Bronzebeard or High Overlord Saurfang
	uint64 DeathbringersCacheGUID;
	uint64 SaurfangTeleportGUID;
	uint64 PlagueSigilGUID;
	uint64 BloodwingSigilGUID;
	uint64 FrostwingSigilGUID;
	uint64 PutricidePipeGUIDs[2];
	uint64 PutricideGateGUIDs[2];
	uint64 PutricideCollisionGUID;
	uint64 FestergutGUID;
	uint64 RotfaceGUID;
	uint64 ProfessorPutricideGUID;
	uint64 PutricideTableGUID;
	uint64 BloodCouncilGUIDs[3];
	uint64 BloodCouncilControllerGUID;
	uint64 BloodQueenLanaThelGUID;
	uint64 CrokScourgebaneGUID;
	uint64 CrokCaptainGUIDs[4];
	uint64 SisterSvalnaGUID;
	uint64 ValithriaDreamwalkerGUID;
	uint64 ValithriaLichKingGUID;
	uint64 ValithriaTriggerGUID;
	uint64 SindragosaGUID;
	uint64 SpinestalkerGUID;
	uint64 RimefangGUID;
	uint64 TheLichKingTeleportGUID;
	uint64 TheLichKingGUID;
	uint64 HighlordTirionFordringGUID;
	uint64 TerenasMenethilGUID;
	uint64 ArthasPlatformGUID;
	uint64 ArthasPrecipiceGUID;
	uint64 FrozenThroneEdgeGUID;
	uint64 FrozenThroneWindGUID;
	uint64 FrozenThroneWarningGUID;
	uint64 FrozenBolvarGUID;
	uint64 PillarsChainedGUID;
	uint64 PillarsUnchainedGUID;
	uint32 KorKronGeneralGUID;
	uint32 KorKronLieutnantGUID;
	uint32 TurTunokGUID;
	uint32 GeradoTheSuaveGUID;
	uint32 UvulusBanefireGUID;
	uint32 IkifirusTheVileGUID;
	uint32 VolGukGUID;
	uint32 HaraggTheUnseenGUID;
	uint32 GarroshHellscreamGUID;
	uint32 HighOverlordSaurfangGUID;
	uint32 KorKronReaverGUID;
	uint32 AllianceCommanderGUID;
	uint32 SkybreakerLieutnantGUID;
	uint32 AlanaMoonstrikeGUID;
	uint32 TalanMoonstrikeGUID;
	uint32 MalfusGrimfrostGUID;
	uint32 YiliGUID;
	uint32 JedebiaGUID;
	uint32 NibyTheAlmightyGUID;
	uint32 KingVarianWrymGUID;
	uint32 MuradinBronzebardGUID;
	uint32 SkybreakerMarineGUID;
	uint16 BloodQuickeningMinutes;
	uint32 BloodQuickeningState;
	uint32 InstanceTeam;

};

///////////////////////////////////////////////////////
// IceCrown Teleporter
class ICCTeleporterAI : public GameObjectAIScript
{
public:

	ICCTeleporterAI(GameObject* go) : GameObjectAIScript(go){}

	~ICCTeleporterAI(){}

	static GameObjectAIScript* Create(GameObject* go) { return new ICCTeleporterAI(go); }

	void OnActivate(Player* player)
	{
		IceCrownCitadelScript* pInstance = (IceCrownCitadelScript*)player->GetMapMgr()->GetScript();
		if(!pInstance)
			return;

		GossipMenu* menu = NULL;
		objmgr.CreateGossipMenuForPlayer(&menu, _gameobject->GetGUID(), 1/*Its not one... need to be checked*/, player);
		menu->AddItem(Arcemu::Gossip::ICON_CHAT, "Teleport to Light's Hammer.", 0);

		if(pInstance->GetInstanceData(Data_EncounterState, CN_LORD_MARROWGAR) == State_Finished)
			menu->AddItem(Arcemu::Gossip::ICON_CHAT, "Teleport to Oratory of The Damned.", 1);

		if(pInstance->GetInstanceData(Data_EncounterState, CN_LADY_DEATHWHISPER) == State_Finished)
			menu->AddItem(Arcemu::Gossip::ICON_CHAT, "Teleport to Rampart of Skulls.", 2);

		// GunshipBattle has to be finished...
		//menu->AddItem(Arcemu::Gossip::ICON_CHAT, "Teleport to Deathbringer's Rise.", 3);

		if(pInstance->GetInstanceData(Data_EncounterState, CN_VALITHRIA_DREAMWALKER) == State_Finished)
			menu->AddItem(Arcemu::Gossip::ICON_CHAT, "Teleport to the Upper Spire.", 4);

		if(pInstance->GetInstanceData(Data_EncounterState, CN_COLDFLAME) == State_Finished)
			menu->AddItem(Arcemu::Gossip::ICON_CHAT, "Teleport to Sindragosa's Lair.", 5);

		menu->SendTo(player);
	}

};

class ICCTeleporterGossip : public GossipScript
{
public:
	ICCTeleporterGossip() : GossipScript(){}

	void OnSelectOption(Object* object, Player* player, uint32 Id, const char* enteredcode)
	{
		Arcemu::Gossip::Menu::Complete(player);

		if(Id >= 7)
			return;
		else
			player->SafeTeleport(ICCTeleCoords[Id][0], player->GetInstanceID(), ICCTeleCoords[Id][1], ICCTeleCoords[Id][2], ICCTeleCoords[Id][3], ICCTeleCoords[Id][4]);
	}
};

///////////////////////////////////////////////////////
// Boss: Lord Marrowgar
// LM_BERSERK	= 47008
// BONE_SLICE	= 69055
// BONE_SPIKE	= 69057
// BONE_STORM	= 69076
// SOUL_FEAST	= 71203
// ...

///////////////////////////////////////////////////////
// Boss: Lady Deathwhisper
// MANA_BARRIER = 70842
// DEATH_AND_DECAY = 71001
// TOUCH_OF_INSIGNIFICANCE = 71204
// SHADOW_BOLT = 71254
// DOMINATE_MIND_H = 71289
// SUMMON_SHADE = 71363
// FROSTBOLT = 71420
// FROSTBOLT_VOLLEY = 72905
// ...

///////////////////////////////////////////////////////
// Boss: Valithria Dreamwalker
// ...
//
//
//
//

///////////////////////////////////////////////////////
// Boss: Cold Flame
// ...
//
//
//
//

void SetupICC(ScriptMgr* mgr)
{
	//Instance
	mgr->register_instance_script(MAP_ICECROWNCITADEL, &IceCrownCitadelScript::Create);

	//Teleporters
	mgr->register_gameobject_script(GO_TELE_1, &ICCTeleporterAI::Create);
	mgr->register_go_gossip_script(GO_TELE_1, new ICCTeleporterGossip());

	mgr->register_gameobject_script(GO_TELE_2, &ICCTeleporterAI::Create);
	mgr->register_go_gossip_script(GO_TELE_2, new ICCTeleporterGossip());

	mgr->register_gameobject_script(GO_TELE_3, &ICCTeleporterAI::Create);
	mgr->register_go_gossip_script(GO_TELE_3, new ICCTeleporterGossip());

	mgr->register_gameobject_script(GO_TELE_4, &ICCTeleporterAI::Create);
	mgr->register_go_gossip_script(GO_TELE_4, new ICCTeleporterGossip());

	mgr->register_gameobject_script(GO_TELE_5, &ICCTeleporterAI::Create);
	mgr->register_go_gossip_script(GO_TELE_5, new ICCTeleporterGossip());

	//Bosses
	//mgr->register_creature_script(CN_LORD_MARROWGAR, &LordMarrowgarAI::Create);
	//mgr->register_creature_script(CN_LADY_DEATHWHISPER, &LadyDeathwhisperAI::Create);
	//mgr->register_creature_script(CN_VALITHRIA_DREAMWALKER, &ValithriaDreamwalkerAI::Create);
	//mgr->register_creature_script(CN_COLDFLAME, &ColdFlameAI::Create);
}
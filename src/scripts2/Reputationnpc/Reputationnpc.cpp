//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)
#endif

class SCRIPT_DECL Reputationnpc : public GossipScript
{
public:
	void GossipHello(Object * pObject, Player* Plr, bool AutoSend);
	void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
	void GossipEnd(Object * pObject, Player* Plr);
	void Destroy()
	{
		delete this;
	}
};

void Reputationnpc::GossipHello(Object* pObject, Player * Plr, bool AutoSend)
{
	GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
	Menu->AddItem(0, "One Stop Shop!!!", 100);
	if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
	{
		Menu->AddItem(0, "Horde Factions", 1);
	}
	else
	{
		Menu->AddItem(0, "Alliance Factions", 2);
	}
	Menu->AddItem(0, "Other Factions", 3);
	Menu->AddItem(0, "WotLK Factions", 62);

	if(AutoSend)
		Menu->SendTo(Plr);
}

void Reputationnpc::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
		return;

	GossipMenu * Menu;
	switch(IntId)
	{

	case 0:
		GossipHello(pObject, Plr, true);
		break;

	case 1:     // Horde Factions
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Darkspear Trolls", 6);
			Menu->AddItem(5, "Frostwolf Clan", 7);
			Menu->AddItem(5, "Orgrimmar", 8);
			Menu->AddItem(5, "Silvermoon City", 9);
			Menu->AddItem(5, "The Defilers", 10);
			Menu->AddItem(5, "The Mag'har", 11);
			Menu->AddItem(5, "Thrallmar", 12);
			Menu->AddItem(5, "Thunder Bluff", 13);
			Menu->AddItem(5, "Tranquillien", 14);
			Menu->AddItem(5, "Undercity", 15);
			Menu->AddItem(5, "Warsong Outriders", 16);
			Menu->AddItem(0, "Back", 99);

			Menu->SendTo(Plr);
		}
		break;


	case 2:     // Alliance Factions
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Wintersaber Trainers", 17);
			Menu->AddItem(5, "Darnassus", 18);
			Menu->AddItem(5, "Exodar", 19);
			Menu->AddItem(5, "Gnomeregan Exiles", 20);
			Menu->AddItem(5, "Honor Hold", 21);
			Menu->AddItem(5, "Ironforge", 22);
			Menu->AddItem(5, "Kurenai", 23);
			Menu->AddItem(5, "Silverwing Sentinels", 24);
			Menu->AddItem(5, "Stormpike Guard", 25);
			Menu->AddItem(5, "Stormwind City", 26);
			Menu->AddItem(5, "The League of Arathor", 27);
			Menu->AddItem(5, "Wildhammer Clan", 28);
			Menu->AddItem(0, "Back", 99);

			Menu->SendTo(Plr);
		}
		break;

	case 3:     // Other Factions
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "Next", 4);
			Menu->AddItem(5, "Argent Dawn", 29);
			Menu->AddItem(5, "Ashtongue Deathsworn", 30);
			Menu->AddItem(5, "Booty Bay", 31);
			Menu->AddItem(5, "Cenarion Circle", 32);
			Menu->AddItem(5, "Cenarion Expedition", 33);
			Menu->AddItem(5, "Darkmoon Faire", 34);
			Menu->AddItem(5, "Everlook", 35);
			Menu->AddItem(5, "Gadgetzan", 36);
			Menu->AddItem(5, "Gelkis Clan Centaur", 37);
			Menu->AddItem(5, "Hydraxian Waterlords", 38);
			Menu->AddItem(5, "Keepers of Time", 39);
			Menu->AddItem(5, "Lower City", 40);
			Menu->AddItem(0, "Back", 99);

			Menu->SendTo(Plr);
		}
		break;

	case 4:     // Other Factions
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "Next", 5);
			Menu->AddItem(5, "Magram Clan Centaur", 41);
			Menu->AddItem(5, "Netherwing", 42);
			Menu->AddItem(5, "Ogri'la", 43);
			Menu->AddItem(5, "Ratchet", 44);
			Menu->AddItem(5, "Ravenholdt", 45);
			Menu->AddItem(5, "Sha'tari Skyguard", 46);
			Menu->AddItem(5, "Shattered Sun Offensive", 47);
			Menu->AddItem(5, "Shen'dralar", 48);
			Menu->AddItem(5, "Sporeggar", 49);
			Menu->AddItem(5, "The Aldor", 50);
			Menu->AddItem(5, "The Consortium", 51);
			Menu->AddItem(5, "The Scale of the Sands", 52);
			Menu->AddItem(0, "Back", 99);

			Menu->SendTo(Plr);
		}
		break;

	case 5:     // Other Factions
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "The Scryers", 53);
			Menu->AddItem(5, "The Sha'tar", 54);
			Menu->AddItem(5, "The Violet Eye", 55);
			Menu->AddItem(5, "Thorium Brotherhood", 56);
			Menu->AddItem(5, "Timbermaw Hold", 57);
			Menu->AddItem(5, "Zandalar Tribe", 58);
			Menu->AddItem(5, "Bloodsail Buccaneers", 59);
			Menu->AddItem(5, "Syndicate", 60);
			Menu->AddItem(5, "Brood of Nozdormu", 61);
			Menu->AddItem(0, "Back", 99);

			Menu->SendTo(Plr);
		}
		break;

	case 6://Darkspear Trolls
		{
			uint32 price = 50000; //five gold
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(530, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 7://Frostwolf Clan
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(729, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 8://Orgrimmar
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(76, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 9://Silvermoon City
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(911, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 10://Defilers
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(510, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 11://Mag'har
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(941, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 12://Thrallmar
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(947, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 13://Thunder Bluff
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(81, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 14://Tranquillien
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(922, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 15://Undercity
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(68, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 16://Warsong Outriders
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(889, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 17://Wintersaber Trainers
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(589, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 18://Darnassus
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(69, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 19://Exodar
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(930, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 20://Gnomeregan Exiles
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(54, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 21://Honor Hold
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(946, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 22://Ironforge
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(47, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 23://Kurenai
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(978, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 24://Silverwing Sentinels
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(890, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 25://Stormpike Guard
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(730, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 26://Stormwind
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(72, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 27://The League of Arathor
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(509, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 28://Wildhammer Clan
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(471, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 29://Argent Dawn
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(529, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 30://Ashtongue Deathsworn
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1012, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 31://Booty Bay
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(21, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 32://Cenarion Circle
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(609, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 33://Cenarion Expedition
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(942, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 34://Darkmoon Faire
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(909, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 35://Everlook
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(577, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 36://Gadgetzan
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(369, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 37://Gelkis Clan Centaur
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(92, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 38://Hydraxian Waterlords
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(749, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 39://Keepers of Time
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(989, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 40://Lower City
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1011, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 41://Magram Clan Centaur
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(93, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 42://Netherwing
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1015, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 43://Ogri'la
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1038, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 44://Ratchet
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(470, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 45://Ravenholdt
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(349, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 46://Sha'tari Skyguard
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1031, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 47://Shattered Sun Offensive
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1077, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 48://Shen'dralar
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(809, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 49://Sporeggar
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(970, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 50://The Aldor
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(932, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 51://The Consortium
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(933, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 52://The Scale of the Sands
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(990, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 53://The Scryers
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(934, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 54://The Sha'tar
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(935, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 55://The Violet Eye
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(967, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 56://Thorium Brotherhood
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(59, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 57://Timbermaw Hold
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(576, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 58://Zandalar Tribe
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(270, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 59://Bloodsail Buccaneers
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(87, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 60://Syndicate
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(70, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 61://Brood of Nozdormu
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(910, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 62://Facciones WotLK
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Argent Crusade", 63);
			Menu->AddItem(5, "The Kalu'ak", 64);
			Menu->AddItem(5, "Frenzyheart Tribe", 65);
			Menu->AddItem(5, "The Oracles", 66);
			Menu->AddItem(5, "The Wyrmrest Accord", 67);
			Menu->AddItem(5, "Kirin Tor", 68);
			Menu->AddItem(5, "Knights of the Ebon Blade", 69);
			if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
			{
				Menu->AddItem(5, "Horde Expedition", 70);
			}
			else
			{
				Menu->AddItem(5, "Alliance Vanguard", 71);
			}
			Menu->AddItem(0, "Back", 99);

			Menu->SendTo(Plr);
		}
		break;

	case 63://Argent Crusade
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1106, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 64://The Kalu'ak
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1073, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 65://Frenzyheart Tribe
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1104, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 66://The Oracles
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1105, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 67://The Wyrmrest Accord
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1091, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 68://Kirin Tor
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1090, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 69://Knights of the Ebon Blade
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1098, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 70://Horde Expedition
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1052, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 71://Alliance Vanguard
		{
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(1037, 5000000);}
			Plr->Gossip_Complete();
		}break;

	case 99:     // mains
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "One Stop Shop!! Reputacion con TODO!!!", 100);
			if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
			{
				Menu->AddItem(0, "Facciones Gordas", 1);
			}
			else
			{
				Menu->AddItem(0, "Facciones Ally", 2);
			}
			Menu->AddItem(0, "Otras Facciones", 3);
			Menu->AddItem(0, "Facciones WotLK", 62);

			Menu->SendTo(Plr);
		}
		break;

	case 100:
		{
			/*			uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); //five gold
			if (currentgold >= 100000){
			uint32 newgold = currentgold - 100000;
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, newgold);
			*/
			uint32 price = 50000;
			if (Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) >= price){
				Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) - price);
				Plr->SetStanding(530, 5000000);
				Plr->SetStanding(729, 5000000);
				Plr->SetStanding(76, 5000000);
				Plr->SetStanding(911, 5000000);
				Plr->SetStanding(510, 5000000);
				Plr->SetStanding(941, 5000000);
				Plr->SetStanding(947, 5000000);
				Plr->SetStanding(81, 5000000);
				Plr->SetStanding(922, 5000000);
				Plr->SetStanding(68, 5000000);
				Plr->SetStanding(889, 5000000);
				Plr->SetStanding(589, 5000000);
				Plr->SetStanding(69, 5000000);
				Plr->SetStanding(930, 5000000);
				Plr->SetStanding(54, 5000000);
				Plr->SetStanding(946, 5000000);
				Plr->SetStanding(47, 5000000);
				Plr->SetStanding(978, 5000000);
				Plr->SetStanding(890, 5000000);
				Plr->SetStanding(730, 5000000);
				Plr->SetStanding(72, 5000000);
				Plr->SetStanding(509, 5000000);
				Plr->SetStanding(471, 5000000);
				Plr->SetStanding(529, 5000000);
				Plr->SetStanding(1012, 5000000);
				Plr->SetStanding(21, 5000000);
				Plr->SetStanding(609, 5000000);
				Plr->SetStanding(942, 5000000);
				Plr->SetStanding(909, 5000000);
				Plr->SetStanding(577, 5000000);
				Plr->SetStanding(369, 5000000);
				Plr->SetStanding(92, 5000000);
				Plr->SetStanding(749, 5000000);
				Plr->SetStanding(989, 5000000);
				Plr->SetStanding(1011, 5000000);
				Plr->SetStanding(93, 5000000);
				Plr->SetStanding(1015, 5000000);
				Plr->SetStanding(1038, 5000000);
				Plr->SetStanding(470, 5000000);
				Plr->SetStanding(349, 5000000);
				Plr->SetStanding(1031, 5000000);
				Plr->SetStanding(1077, 5000000);
				Plr->SetStanding(809, 5000000);
				Plr->SetStanding(970, 5000000);
				Plr->SetStanding(932, 5000000);
				Plr->SetStanding(933, 5000000);
				Plr->SetStanding(990, 5000000);
				Plr->SetStanding(934, 5000000);
				Plr->SetStanding(935, 5000000);
				Plr->SetStanding(967, 5000000);
				Plr->SetStanding(59, 5000000);
				Plr->SetStanding(576, 5000000);
				Plr->SetStanding(270, 5000000);
				Plr->SetStanding(87, 5000000);
				Plr->SetStanding(70, 5000000);
				Plr->SetStanding(910, 5000000);
				Plr->SetStanding(1106, 5000000);
				Plr->SetStanding(1073, 5000000);
				Plr->SetStanding(1104, 5000000);
				Plr->SetStanding(1105, 5000000);
				Plr->SetStanding(1091, 5000000);
				Plr->SetStanding(1090, 5000000);
				Plr->SetStanding(1098, 5000000);
				Plr->SetStanding(1052, 5000000);
				Plr->SetStanding(1037, 5000000);
			}
			else
			{
				Plr->BroadcastMessage("You don't have enough gold.");
				Plr->Gossip_Complete();
			}
		}break;
	}
};

void Reputationnpc::GossipEnd(Object * pObject, Player* Plr)
{
	GossipScript::GossipEnd(pObject, Plr);
}

void SetupReputationnpc(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new Reputationnpc();
	mgr->register_gossip_script(90000010,gs);
}
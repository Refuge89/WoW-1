//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)   
#endif

class SCRIPT_DECL Menu : public GossipScript
{
public:
    void GossipHello(Object * pObject, Player* Plr, bool AutoSend);
    void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
    void GossipEnd(Object * pObject, Player* Plr);
    void mLoadItemsFromDatabase(QueryResult * result);
};
void Menu::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
GossipMenu *Menu;
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(4, "DeMorph", 7);
Menu->AddItem(4, "Teleport", 1);
Menu->AddItem(4, "Morph", 2);
Menu->AddItem(4, "Gear", 3);
Menu->AddItem(4, "Player Port", 9);
Menu->AddItem(4, "Reset Talents", 8);
Menu->SendTo(Plr);
}
void Menu::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
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
case 2:
		{
			char Morph[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(Morph, "Enter Morph Name [%u]");
			Menu->AddItem(4, Morph, 4, 1);
			Menu->SendTo(Plr);
		}break;

case 4:
		{
			QueryResult *Morph = WorldDatabase.Query("Select `DisplayID` FROM player_morphs where `Name` = '%s'", Code); 
			
			if(Morph)
			{
				Field *Fields = Morph->Fetch();
				uint32 DisplayID = Fields[0].GetUInt32();
				Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, DisplayID);
			}
			else
			Plr->Gossip_Complete();
		}break;

case 3:
		{
			char pItem5[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(pItem5, "Enter Item Name [%u]");
			Menu->AddItem(4, pItem5, 5, 1);
			Menu->SendTo(Plr);
		}break;

case 5:
		{
QueryResult *pItem5 = WorldDatabase.Query("Select `entryID` FROM Player_items where `Name` = '%s'", Code);

if(pItem5)
{
Field *Fields = pItem5->Fetch();
uint32 entryID = Fields[0].GetUInt32();
Plr->GetItemInterface()->AddItemToFreeSlot(objmgr.CreateItem(entryID, Plr));
Plr->Gossip_Complete();
}
}break;

		case 1:
		{
			char Teleport[225];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(Teleport, "Enter Location Name [%u]");
			Menu->AddItem(4, Teleport, 6, 1);
			Menu->SendTo(Plr);
		}break;

   case 6:
		{
	     QueryResult *Teleport = WorldDatabase.Query("SELECT * FROM `Player_recall` Where `Name` = '%s'", Code);


if(Teleport)
{
Field * fields = Teleport->Fetch();
uint32 MapID = fields[2].GetUInt32();
float X = fields[3].GetFloat();
float Y = fields[4].GetFloat();
float Z = fields[5].GetFloat();
Plr->EventTeleport(MapID, X, Y, Z);
Plr->Gossip_Complete();
		}
		}break;

case 7:
{
Plr->DeMorph();
}break;

case 8:
{
Plr->Reset_Talents();
}break;
                case 9:
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(4, "Port Player", 10, 1);
			Menu->SendTo(Plr);
		}break;
case 10:
{
			Player * pTarget = objmgr.GetPlayer(Code, false);
			if(!pTarget)
			{
				Plr->BroadcastMessage("Player not found.");
				Plr->Gossip_Complete();
				return;
			}
			if(pTarget->GetSession()->HasGMPermissions())
			{
				Plr->BroadcastMessage("Nice try buddy its a GM.");
				Plr->Gossip_Complete();
				return;
			}
			uint32 pMap = pTarget->GetMapId();
			float pX = pTarget->GetPositionX();
			float pY = pTarget->GetPositionY();
			float pZ = pTarget->GetPositionZ();
			float pO = pTarget->GetOrientation();
			Plr->Gossip_Complete();
			pTarget->BroadcastMessage("%s is porting to your location.", Plr->GetName());
			Plr->EventTeleport(pMap, pX, pY, pZ);
			Plr->SetOrientation(pO);
		}break;

}
}

void Menu::GossipEnd(Object * pObject, Player* Plr){
GossipScript::GossipEnd(pObject, Plr);}


void SetupMenu(ScriptMgr * mgr)
{
   GossipScript * gs = (GossipScript*) new Menu();
    mgr->register_gossip_script(90000004, gs);
}

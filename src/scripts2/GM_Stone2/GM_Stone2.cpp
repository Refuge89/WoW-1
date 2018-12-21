// This Code is made by Zellcorp thanks to mmowned and ac-web for all the great posts that help make this possible.


#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)// warning C4305:'argument' :truncation from 'double' to 'float'
#pragma warning(disable:4244)
#endif

//Specifing GM_Stone2
class SCRIPT_DECL GM_Stone2 :public GossipScript
{
public:
void GossipHello(Object * pObject, Player* Plr, bool AutoSend);
void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
void GossipEnd(Object * pObject, Player* Plr){ GossipScript::GossipEnd(pObject, Plr); }
void mLoadItemsFromDatabase(QueryResult * result);
void Destroy(){ delete this; }
};



// Gossip Hello First Page

void GM_Stone2::GossipHello(Object* pObject, Player * Plr, bool AutoSend)
{
Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);
GossipMenu *Menu;
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(4, "|cff800080.char Learn (add spell number)|r", 6530);
Menu->AddItem(4, "|cff800080.char Unlearn (remove spell number)|r", 6540);
Menu->AddItem(5, "|cff800080.removeauras (dispell spell & aura Effects|r", 2003);
Menu->AddItem(3, ".mod Level (leveling)", 129);
Menu->AddItem(4, "|cff800080.char additem (by number)|r", 6503);
Menu->AddItem(4, "|cff800080.char additem (by name)|r", 6501);
Menu->AddItem(2, ".mod Display (by entry number)", 6507);
Menu->AddItem(2, ".mod Display (by display id)", 6516);
Menu->AddItem(2, ".mod Display (by name)", 6505);
Menu->AddItem(2, ".demorph (remove morph)", 2001);
Menu->AddItem(7, "|cff800080.mount (by entry number)|r", 8300);
Menu->AddItem(7, "|cff800080.mount (by display ID)|r", 8200);
Menu->AddItem(7, "|cff800080.dismount|r", 999);
Menu->AddItem(4, "|cff800080---Use Custom Made Mounts---|r", 8000);
Menu->AddItem(4, "|cffffffff-------------------------------NEXT PAGE->|r", 140);
if(AutoSend) Menu->SendTo(Plr);

}
// Start of Cases
void GM_Stone2::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
GossipMenu *Menu;
switch(IntId){

// Page 2
case 140:
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(2, "|cff800080.mod Rage (number)|r", 19014);
Menu->AddItem(2, "|cff800080.mod Energy (number)|r", 19016);
Menu->AddItem(8, "|cff800080.mod Health (by number)|r", 19005);
Menu->AddItem(8, "|cff800080.mod Mana (by number)|r", 19007);
Menu->AddItem(8, "|cff800080.mod Runic (by number)|r", 19018);
Menu->AddItem(8, "|cff800080.mod Speed (changes walk speed)|r", 10000);
Menu->AddItem(8, "|cff800080.mod Reverse speed (changes backwards speed)|r", 10001);
Menu->AddItem(8, "|cff800080.mod Swimspeed (changes swim speed)|r", 10002);
Menu->AddItem(1, ".recall port (by location's name) teleport", 6510);
Menu->AddItem(1, ".appear (to player's name) teleport", 6511);
Menu->AddItem(2, "|cff800080.playall (by number)|r", 7100);
Menu->AddItem(2, "|cff800080.playall (play cool sounds)|r", 7000);
Menu->AddItem(6, "Illumine All Maps", 123);
Menu->AddItem(4, "|cffffffff-------------------------------NEXT PAGE->|r", 141);
Menu->AddItem(4, "|cffffffff<-BACK------------------------------------|r", 142);
Menu->SendTo(Plr);
}break;

// Page 3
case 141:
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(2, ".cheat fly (ON)", 19009);
Menu->AddItem(2, ".cheat fly (OFF)", 19010);
Menu->AddItem(8, "|cff800080.cheat Flyspeed (changes fly speed)|r", 10003);
Menu->AddItem(2, ".cheat god (ON)", 19011);
Menu->AddItem(2, ".cheat god (OFF)", 19012);
Menu->AddItem(1, "|cff800080Open all FlightPaths|r", 124);
Menu->AddItem(5, "Remove Res Sickness", 80);
Menu->AddItem(5, "Remove Cooldowns", 81);
Menu->AddItem(5, "Reset Talentpoints", 83);
Menu->AddItem(4, "|cff800080.saveplr (save Player to DB)|r", 122);
Menu->AddItem(5, ".char advanceallskills (by number)", 10005);
Menu->AddItem(5, "Advance All Skills to 450", 121);
Menu->AddItem(4, "|cff800080---------|Scale Menu|---------|r", 19040);
Menu->AddItem(4, "|cffffffff<-BACK------------------------------------|r", 140);
Menu->SendTo(Plr);
}break;

// Loop to first page
case 142:
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(4, "|cff800080.char learn (add spell number)|r", 6530);
Menu->AddItem(4, "|cff800080.char unlearn (remove spell number)|r", 6540);
Menu->AddItem(5, "|cff800080.removeauras (dispell spell & aura Effects|r", 2003);
Menu->AddItem(3, ".mod level (leveling)", 129);
Menu->AddItem(4, "|cff800080.char additem (by number)|r", 6503);
Menu->AddItem(4, "|cff800080.char additem (by name)|r", 6501);
Menu->AddItem(2, ".mod display (by name)", 6505);
Menu->AddItem(2, ".mod display (by number)", 6507);
Menu->AddItem(2, ".mod display (by display id)", 6516);
Menu->AddItem(2, ".demorph (remove morph)", 2001);
Menu->AddItem(7, "|cff800080.mount (by display ID|r", 8200);
Menu->AddItem(7, "|cff800080.mount (NPC entry ID|r", 8300);
Menu->AddItem(7, "|cff800080.dismount|r", 999);
Menu->AddItem(4, "|cff800080---Use Custom Made Mounts---|r", 8000);
Menu->AddItem(4, "|cffffffff-------------------------------NEXT PAGE->|r", 140);
Menu->SendTo(Plr);
}break;

case 19040:
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(4, "Scale to .0", 19037);
Menu->AddItem(4, "Scale to .1", 19036);
Menu->AddItem(4, "Scale to .5", 19038);
Menu->AddItem(4, "|cff800080Scale to 1 (normal)|r", 19035);
Menu->AddItem(4, "Scale to 1.5", 19031);
Menu->AddItem(4, "Scale to 2", 19032);
Menu->AddItem(4, "Scale to 2.5", 19033);
Menu->AddItem(4, "Scale to 3", 19034);
Menu->SendTo(Plr);
}break;

case 19037:// Scale to .0
{
Plr->RemoveAura(23020);
Plr->RemoveAura(23126);
Plr->RemoveAura(23129);
Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.0f);
Plr->BroadcastMessage("Your scale is .0!!");
Plr->Gossip_Complete();
}break;

case 19036:// Scale to .1
{
Plr->RemoveAura(23020);
Plr->RemoveAura(23126);
Plr->RemoveAura(23129);
Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
Plr->BroadcastMessage("Your scale is .1!!");
Plr->Gossip_Complete();
}break;

case 19038:// Scale to .5
{
Plr->RemoveAura(23020);
Plr->RemoveAura(23126);
Plr->RemoveAura(23129);
Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
Plr->BroadcastMessage("Your scale is .5!!");
Plr->Gossip_Complete();
}break;

case 19035:// Scale to 1 (normal)
{
Plr->RemoveAura(23020);
Plr->RemoveAura(23126);
Plr->RemoveAura(23129);
Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
Plr->BroadcastMessage("Your scale is back to normal!!");
Plr->Gossip_Complete();
}break;

case 19034:// Scale to 3
{
Plr->RemoveAura(23020);
Plr->RemoveAura(23126);
Plr->RemoveAura(23129);
Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 3.0f);
Plr->BroadcastMessage("Your scale is 3!!");
Plr->Gossip_Complete();
}break;

case 19033:// Scale to 2.5
{
Plr->RemoveAura(23020);
Plr->RemoveAura(23126);
Plr->RemoveAura(23129);
Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.5f);
Plr->BroadcastMessage("Your scale is 2.5!!");
Plr->Gossip_Complete();
}break;

case 19032:// Scale to 2
{
Plr->RemoveAura(23020);
Plr->RemoveAura(23126);
Plr->RemoveAura(23129);
Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.0f);
Plr->BroadcastMessage("Your scale is 2!!");
Plr->Gossip_Complete();
}break;

case 19031:// Scale to 1.5
{
Plr->RemoveAura(23020);
Plr->RemoveAura(23126);
Plr->RemoveAura(23129);
Plr->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.5f);
Plr->BroadcastMessage("Your scale is 1.5!!");
Plr->Gossip_Complete();
}break;


case 80:// Remove Resurrection Sickness
{
Plr->addSpell(15007);
Plr->removeSpell(15007,0,0,0);
Plr->BroadcastMessage("Your resurrection Sickness has been Removed!!");
Plr->Gossip_Complete();
}break;

case 81://Remove Cooldowns
{
Plr->ResetAllCooldowns();
Plr->BroadcastMessage("Your cooldowns are removed!");
Plr->Gossip_Complete();
}break;

case 83://Reset Talentpoints
{
Plr->Reset_Talents();
Plr->BroadcastMessage("Your Talents have been reset");
Plr->Gossip_Complete();
}break;

case 121: //Advance all skills
{
if (Plr->_HasSkillLine(43))
{Plr->_AdvanceSkillLine(43, 450);}
if (Plr->_HasSkillLine(55))
{Plr->_AdvanceSkillLine(55, 450);}
if (Plr->_HasSkillLine(44))
{Plr->_AdvanceSkillLine(44, 450);}
if (Plr->_HasSkillLine(95))
{Plr->_AdvanceSkillLine(95, 450);}
if (Plr->_HasSkillLine(54))
{Plr->_AdvanceSkillLine(54, 450);}
if (Plr->_HasSkillLine(45))
{Plr->_AdvanceSkillLine(45, 450);}
if (Plr->_HasSkillLine(46))
{Plr->_AdvanceSkillLine(46, 450);}
if (Plr->_HasSkillLine(136))
{Plr->_AdvanceSkillLine(136, 450);}
if (Plr->_HasSkillLine(160))
{Plr->_AdvanceSkillLine(160, 450);}
if (Plr->_HasSkillLine(162))
{Plr->_AdvanceSkillLine(162, 450);}
if (Plr->_HasSkillLine(172))
{Plr->_AdvanceSkillLine(172, 450);}
if (Plr->_HasSkillLine(173))
{Plr->_AdvanceSkillLine(173, 450);}
if (Plr->_HasSkillLine(176))
{Plr->_AdvanceSkillLine(176, 450);}
if (Plr->_HasSkillLine(226))
{Plr->_AdvanceSkillLine(226, 450);}
if (Plr->_HasSkillLine(228))
{Plr->_AdvanceSkillLine(228, 450);}
if (Plr->_HasSkillLine(229))
{Plr->_AdvanceSkillLine(229, 450);}
if (Plr->_HasSkillLine(473))
{Plr->_AdvanceSkillLine(473, 450);}
Plr->Gossip_Complete(); 
}break;

case 122: //Save Player to DB
{
Plr->SaveToDB(true);
Plr->Emote(EMOTE_ONESHOT_CHEER);
Plr->BroadcastMessage("You have been saved!");
Plr->Gossip_Complete();
}break;

case 123: //Explore all Maps
{
for (uint8 i=0; i<64; i++)
{
Plr->SetFlag(PLAYER_EXPLORED_ZONES_1+i,0xFFFFFFFF);
}
Plr->BroadcastMessage("All Map Locations have been opened!");
Plr->Gossip_Complete();
}break;

case 124: //Open all FlightPaths
{
for (uint8 i=0; i<8; i++)
{
Plr->SetTaximask(i, 0xFFFFFFFF);
}
Plr->BroadcastMessage("All FlightPaths have been opened!");
Plr->Gossip_Complete();
}break;

case 2001: // Demorph
		{
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
        Plr->DeMorph();
Plr->BroadcastMessage("You are now de-morphed!");
Plr->Gossip_Complete();
		}break;

case 2003: // Remove all Auras
		{
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
        Plr->RemoveAllAuras();
Plr->BroadcastMessage("your auras and spell effects have been removed!");
Plr->Gossip_Complete();
		}break;

//Level Options
case 129: 
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(5, ".levelplr (set level by number)", 10004);
Menu->AddItem(5, "Level 19", 1002);
Menu->AddItem(5, "Level 29", 1003);
Menu->AddItem(5, "Level 35", 1004);
Menu->AddItem(5, "Level 39", 1005);
Menu->AddItem(5, "Level 45", 1006);
Menu->AddItem(5, "Level 50", 1007);
Menu->AddItem(5, "Level 60", 1008);
Menu->AddItem(5, "Level 70", 1009);
Menu->AddItem(5, "Level 80", 1010);
Menu->AddItem(5, "Level 90", 1011);
Menu->AddItem(5, "Level 100", 1012);
Menu->AddItem(5, "Level 150", 1013);
Menu->AddItem(5, "Level 200", 1014);
Menu->AddItem(5, "Level 255", 1015);
Menu->SendTo(Plr);
}break;

case 1001: //Level to 10
{
Plr->BroadcastMessage("You are now level 10!" );
uint32 Level = 10;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1002: //Level to 19
{
Plr->BroadcastMessage("You are now level 19!" );
uint32 Level = 19;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1003: //Level to 30
{
Plr->BroadcastMessage("You are now level 29!" );
uint32 Level = 29;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1004: //Level to 35
{
Plr->BroadcastMessage("You are now level 35!" );
uint32 Level = 35;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1005: //Level to 40
{
Plr->BroadcastMessage("You are now level 39!" );
uint32 Level = 39;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1006: //Level to 45
{
Plr->BroadcastMessage("You are now level 45!" );
uint32 Level = 45;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1007: //Level to 50
{
Plr->BroadcastMessage("You are now level 50!" );
uint32 Level = 50;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1008: //Level to 60
{
Plr->BroadcastMessage("You are now level 60!" );
uint32 Level = 60;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1009: //Level to 70
{
Plr->BroadcastMessage("You are now level 70!" );
uint32 Level = 70;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1010: //Level to 80
{
Plr->BroadcastMessage("You are now level 80!" );
uint32 Level = 80;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1011: //Level to 90
{
Plr->BroadcastMessage("You are now level 90!" );
uint32 Level = 90;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1012: //Level to 100
{
Plr->BroadcastMessage("You are now level 100!" );
uint32 Level = 100;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1013: //Level to 150
{
Plr->BroadcastMessage("You are now level 150!" );
uint32 Level = 150;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1014: //Level to 200
{
Plr->BroadcastMessage("You are now level 200!" );
uint32 Level = 200;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 1015: //Level to 255
{
Plr->BroadcastMessage("You are now level 255 you may be too Overpowered Now!" );
uint32 Level = 255;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}break;

case 19012://God Off
	{
		Plr->GodModeCheat = false;
		Plr->BroadcastMessage("God Mode Off!");
		Plr->Gossip_Complete();
}break;

case 19011://God on
	{
		Plr->GodModeCheat = true;
		Plr->BroadcastMessage("God Mod ON!, bloody cheaters!");
		Plr->Gossip_Complete();
}break;

case 19009://Fly on
{
      bool flytf = true; 
	  uint32 eventid = 2;   
      WorldPacket fly(835, 13);
      Plr->m_setflycheat = true;
      fly << Plr->GetNewGUID();
      fly << uint32(eventid);
      Plr->SendMessageToSet(&fly, true);
	  Plr->BroadcastMessage("Reach for the stars baby!!! FLY ON");
      Plr->Gossip_Complete();
}break;

case 19010://Fly off
{

      bool flytf = true; 
	  uint32 eventid = 2; 	      
      WorldPacket fly(836, 13);
      Plr->m_setflycheat = false;
      fly << Plr->GetNewGUID();
      fly << uint32(5);
      Plr->SendMessageToSet(&fly, true);
	  Plr->BroadcastMessage("Come back down to earth man!!! FLY OFF");
      Plr->Gossip_Complete();
}break;

// Auto Mounts

case 8000:														 
	   {
			 GossipMenu *Menu;
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "Mount Polar Bear", 8001);
			Menu->AddItem(0, "Mount Pink Bird", 8002);
			Menu->AddItem(0, "Mount Dragonhawk", 8003);
			Menu->AddItem(0, "Mount Mini Elephant", 8004);
			Menu->AddItem(0, "Mount Egbert", 8005);
			Menu->AddItem(0, "Mount A Reindeer", 8006);
			Menu->AddItem(0, "Mount Nether Drake", 8007);
			Menu->AddItem(0, "Mount FrostWyrm", 8008);
			Menu->AddItem(0, "Mount Proto Drake", 8009);
			Menu->AddItem(0, "Mount Steel Flying Machine", 8025);
			Menu->AddItem(0, "Mount Wooly Mammoth Bull", 8026);
			Menu->AddItem(0, "Mount Dusk", 8027);
			Menu->AddItem(0, "Mount Korkron War Rider", 8028);
			Menu->AddItem(4, "|cffffffffNext Page|r", 8100);
			Menu->AddItem(8, "|cff800080Dismount Me|r", 999);  
			Menu->SendTo(Plr);
	  }
         break;


case 8100:														 //Ground Mounts2
	   {
			 GossipMenu *Menu;
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "Mount a Lynxx", 8013);
			Menu->AddItem(0, "Mount a Rocket Propelled Warhead", 8030);
			Menu->AddItem(0, "Mount a Tatjanas Horse", 8031);
			Menu->AddItem(0, "Mount a Emerald Drake", 8032);
			Menu->AddItem(0, "Mount a Frostsabre Drake", 8033);
			Menu->AddItem(0, "Mount a Wintergarde Gryphon", 8029);
			Menu->AddItem(0, "Mount a Lava Raptor", 8014);
			Menu->AddItem(0, "Mount a Gargoyle", 8015);
			Menu->AddItem(0, "Mount the Queen Dragna", 8018);
			Menu->AddItem(0, "Flying Black Qiraji Battle Tank", 8019);			
			Menu->AddItem(0, "Mount the Dog of the Siege", 8022);
			Menu->AddItem(0, "Mount the Skull", 8023);					
			Menu->AddItem(4, "|cffffffffNext Page|r", 8900);
			Menu->AddItem(4, "|cffffffffLast Page|r", 8000);
			Menu->AddItem(8, "|cff800080Dismount Me|r", 999);
			Menu->SendTo(Plr);
	  }
         break;

case 8900:														 //Ground Mounts2
	   {
			 GossipMenu *Menu;
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "Mount a Wild Elekk", 8034);
			Menu->AddItem(0, "Mount a Wintergrasp Bomber", 8035);
			Menu->AddItem(0, "Mount Theresas frostsaber", 8036);
			Menu->AddItem(0, "Mount Vics Self Replicating Abomination", 8037);
			Menu->AddItem(0, "Mount a Spectral Gryphon", 8024);
			Menu->AddItem(0, "Mount a Magnificent Flying Carpet", 8020);
		    Menu->AddItem(0, "Enter a Malforsis Avatar", 8017);
			Menu->AddItem(0, "Enter the Shaitan Avatar", 8021);
			Menu->AddItem(0, "Mount Turbo-Charged Flying Machine", 8010);
			Menu->AddItem(0, "Robot 55-D Collect-a-tron", 8011);
			Menu->AddItem(0, "Robot Defendo-tank 66D", 8050);
			Menu->AddItem(0, "Robot ED-210", 8012);
			Menu->AddItem(4, "|cffffffffNext Page|r", 8990);
			Menu->AddItem(4, "|cffffffffLast Page|r", 8100);
			Menu->AddItem(8, "|cff800080Dismount Me|r", 999);
			Menu->SendTo(Plr);
	  }
         break;

case 8990:														
	   {
			 GossipMenu *Menu;
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "Mount Its A Chopper Baby Horde", 8038);
			Menu->AddItem(0, "Mount Its A Chopper Baby Alliance", 8039);
			Menu->AddItem(0, "Mechano-hog", 8041);
			Menu->AddItem(0, "Mount to Spectral Tiger", 8048);
			Menu->AddItem(0, "Mount Icefang", 8040);
			Menu->AddItem(0, "Mount Enormos Mammoth", 8042);
			Menu->AddItem(0, "Mount to Snorri", 8043);
			Menu->AddItem(0, "Mount to Nergeld", 8044);
			Menu->AddItem(0, "Mount to Geargrinders Jumpbot", 8045);
			Menu->AddItem(0, "Mount to Thunderbombs Jumpbot", 8046);
			Menu->AddItem(0, "Mount to Albino Drake", 8047);
			Menu->AddItem(0, "Mount to X-51 Nether-Rocket", 8049);
		    Menu->AddItem(4, "|cffffffffNext Page|r", 8995);
			Menu->AddItem(4, "|cffffffffLast Page|r", 8900);
			Menu->AddItem(8, "|cff800080Dismount Me|r", 999);
			Menu->SendTo(Plr);
	  }
         break;

		 case 8995:														
	   {
			 GossipMenu *Menu;
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "Mount to Peep the Phoenix", 8051);
			Menu->AddItem(0, "Mount to Black Deer", 8052);
			Menu->AddItem(0, "Mount to Ice Cat", 8053);
			Menu->AddItem(0, "Mount to a Chicken", 8054);
			Menu->AddItem(0, "Mount to Spider Robot", 8055);
			Menu->AddItem(0, "Mount to Large Spider Robot", 8056);
			Menu->AddItem(0, "Mount to Small Log", 8057);
			Menu->AddItem(0, "Mount to Large Log", 8058);
			Menu->AddItem(0, "Mount to Face Chopper", 8059);
			Menu->AddItem(0, "Mount to Small Spectral Cat", 8060);
			Menu->AddItem(0, "Mount to Space Head", 8061);
			Menu->AddItem(0, "Mount to Cat Fun Ride", 8062);
			Menu->AddItem(4, "|cffffffffLast Page|r", 8990);
			Menu->AddItem(8, "|cff800080Dismount Me|r", 999);
			Menu->SendTo(Plr);
	  }
         break;

case 8001:												          // Polar Bear
		  {
	      
		  uint32 displayid = 26358;
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
  		  Plr->BroadcastMessage("You Are Now Mounted on a Polar Bear");
		  Plr->Gossip_Complete();
		  }
		break;

case 8002:												          // Pink bird
		  {
	      uint32 displayid = 1961;
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
  		  Plr->BroadcastMessage("You Are Now Mounted on a Pimpin Pink Bird");
		  Plr->Gossip_Complete();
		  }
		break;

case 8003:												          // Dragonhawk
		  {
	      uint32 displayid = 17545;
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
  		  Plr->BroadcastMessage("You Are Now Mounted on a Dragonhawk");
		  Plr->Gossip_Complete();
		  }
		break;

case 8004:												          // Mini Elephant
		  {
	      uint32 displayid = 21393;
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
  		  Plr->BroadcastMessage("You Are Now Mounted on a Mini-Elephant");
		  Plr->Gossip_Complete();
		  }
		break;

case 8005:												          // Egbert
		  {
	      uint32 displayid = 21382;
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
  		  Plr->BroadcastMessage("You Are Now Mounted on Egbert");
		  Plr->Gossip_Complete();
		  }
		break;

case 8006:												          // ground reindeer
		  {
	      uint32 displayid = 15902;
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
  		  Plr->BroadcastMessage("You Are Now Mounted on a Non-Flying Reindeer");
		  Plr->Gossip_Complete();
		  }
		break;

case 8007:											           // Nether Drake
          {
	      uint32 displayid = 20344;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now Mounted on a Nether Drake");
		  Plr->Gossip_Complete();
		  }
		 break;

case 8008:											           // Frostwyrm
          {
	      uint32 displayid = 25511;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now Mounted on a FrostWyrm");
		  Plr->Gossip_Complete();
		  }
		 break;

case 8009:											           // Proto Drake
          {
	      uint32 displayid = 26711;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now Mounted on a Proto Drake");
		  Plr->Gossip_Complete();
		  }
		 break;

case 8010:											           // Glitch Ghost
          {
	      uint32 displayid = 22720;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->Gossip_Complete();
		  }
		 break;


case 8011:											           // Glitch Elf
          {
	      uint32 displayid = 27577;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->Gossip_Complete();
		  }
		 break;


case 8012:											           // Ogre Fist
          {
	      uint32 displayid = 23412;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("Cool huh?");
		  Plr->Gossip_Complete();
		  }
		 break;

case 8013:											           // Lynx
          {
	      uint32 displayid = 19705;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now Mounted on a Lynxx");
		  Plr->Gossip_Complete();
		  }
		 break;

case 8014:											           // Raptor
          {
	      uint32 displayid = 19758;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now Mounted on a Lava Raptor");
		  Plr->Gossip_Complete();
		  }
		 break;


case 8015:											           // Gargoyle
          {
	      uint32 displayid = 14710;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now Mounted on a Gargoyle");
		  Plr->Gossip_Complete();
		  }
		 break;


case 8016:											           // Beatle Tank
          {
	      uint32 displayid = 15931;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now In a Beatle Tank");
		  Plr->Gossip_Complete();
		  }
		 break;

case 8017:											           // Malforsis Avatar
          {
	      uint32 displayid = 20513;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now In the Malforsis Avatar");
		  Plr->Gossip_Complete();
		  }
		 break;


case 8018:											           // Queen Dragna
          {
	      uint32 displayid = 17251;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now Mounted on the Queen Dragna from Silverstar");
		  Plr->Gossip_Complete();
		  }
		 break;

case 8019:											           // Tree Avatar
          {
	      uint32 displayid = 18724;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now Flying Black Qiraji Battle Tank");
		  Plr->Gossip_Complete();
		  }
		 break;


case 8020:											           // Evil Tauren Glitch
			 {
	      uint32 displayid = 28117;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->Gossip_Complete();
		  }
		 break;


case 8021:	                          // Shaitan
			 {
	      uint32 displayid = 14706;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;


case 8022:											           // Dog of the Siege
			 {
	      uint32 displayid = 22088;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now Mounted on the Dog of Gun Siege");
		  Plr->Gossip_Complete();
		  }
		 break;


case 8023:											           // Skull
			 {
	      uint32 displayid = 28089;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  Plr->BroadcastMessage("You Are Now Possessed by the Skull");
		  Plr->Gossip_Complete();
		  }
		 break;


case 8024:											           
			 {
	      uint32 displayid = 26691;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8025:											           
			 {
	      uint32 displayid = 22878;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

		 	 break;

case 8026:											           
			 {
	      uint32 displayid = 26425;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8027:											           
			 {
	      uint32 displayid = 26500;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8028:											           
			 {
	      uint32 displayid = 17719;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8029:											           
			 {
	      uint32 displayid = 24472;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8030:											           
			 {
	      uint32 displayid = 26611;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8031:											           
			 {
	      uint32 displayid = 25030;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8032:											           
			 {
	      uint32 displayid = 25853;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8033:											           
			 {
	      uint32 displayid = 9695;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

		 
case 8034:											           
			 {
	      uint32 displayid = 17896;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8035:											           
			 {
	      uint32 displayid = 23365;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8036:											           
			 {
	      uint32 displayid = 10426;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8037:											           
			 {
	      uint32 displayid = 25626;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8038:											           
			 {
	      uint32 displayid = 25871;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8039:											           
			 {
	      uint32 displayid = 25870;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8040:											           
			 {
	      uint32 displayid = 26323;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8041:											           
			 {
	      uint32 displayid = 25871;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8042:											           
			 {
	      uint32 displayid = 26510;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8043:											           
			 {
	      uint32 displayid = 26772;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8044:											           
			 {
	      uint32 displayid = 27102;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8045:											           
			 {
	      uint32 displayid = 27703;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8046:											           
			 {
	      uint32 displayid = 27701;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8047:											           
			 {
	      uint32 displayid = 25836;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8048:											           
			 {
	      uint32 displayid = 21973;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8049:											           
			 {
	      uint32 displayid = 23656;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8050:											           
			 {
	      uint32 displayid = 24948;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

		 case 8051:											           
			 {
	      uint32 displayid = 17784;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8052:											           
			 {
	      uint32 displayid = 23952;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8053:											           
			 {
	      uint32 displayid = 28010;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8054:											           
			 {
	      uint32 displayid = 29378;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8055:											           
			 {
	      uint32 displayid = 29115;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8056:											           
			 {
	      uint32 displayid = 29104;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8057:											           
			 {
	      uint32 displayid = 26610;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8058:											           
			 {
	      uint32 displayid = 26609;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8059:											           
			 {
	      uint32 displayid = 28890;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8060:											           
			 {
	      uint32 displayid = 28866;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8061:											           
			 {
	      uint32 displayid = 28841;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

case 8062:											           
			 {
	      uint32 displayid = 28811;  // Display ID
		  Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, displayid);
		  
		  Plr->Gossip_Complete();
		  }
		 break;

        case 999:														 //DisMount
            {
			bool flytf = false; 
			Plr->SetSpeeds(RUN, 7);
		    Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);
			  Plr->BroadcastMessage("You Are Now Dis-Mounted");
		    Plr->Gossip_Complete();
		    }
		break;



 // Custom Sound Effects
case 7000:
		{

GossipMenu *Menu;
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(0, "Illidan 1", 99);
Menu->AddItem(0, "Illidan 2", 98);
Menu->AddItem(0, "Kil Jaeden", 97);
Menu->AddItem(0, "Misc 1", 96);
Menu->AddItem(0, "Misc 2", 95);
Menu->SendTo(Plr);
 }
         break;

case 99:
		{
 GossipMenu *Menu;
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(1,"Play Illidan 1", 1);
Menu->AddItem(1,"Play Illidan 2", 2);
Menu->AddItem(1,"Play Illidan 3", 3);
Menu->AddItem(1,"Play Illidan 4", 4);
Menu->AddItem(1,"Play Illidan 5", 5);
Menu->AddItem(1,"Play Illidan 6", 6);
Menu->AddItem(1,"Play Illidan 7", 7);
Menu->AddItem(1,"Play Illidan 8", 8);
Menu->AddItem(1,"Play Illidan 9", 9);
Menu->AddItem(1,"Play Illidan 10", 10);
Menu->AddItem(1,"Play Illidan 11", 11);
Menu->AddItem(1,"Play Illidan 12", 12);
Menu->AddItem(1,"Play Illidan 13", 13);
Menu->AddItem(1,"Play Illidan 14", 14);
Menu->AddItem(1,"Play Illidan 15", 15);
Menu->SendTo(Plr);
}
break;

case 98:
{
 GossipMenu *Menu;
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(1,"Play Illidan 16", 16);
Menu->AddItem(1,"Play Illidan 17", 17);
Menu->AddItem(1,"Play Illidan 18", 18);
Menu->AddItem(1,"Play Illidan 19", 19);
Menu->SendTo(Plr);
}
break;

case 97:
{
 GossipMenu *Menu;
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(1,"Play Kil Jaeden 1", 20);
Menu->AddItem(1,"Play Kil Jaeden 2", 21);
Menu->AddItem(1,"Play Kil Jaeden 3", 22);
Menu->AddItem(1,"Play Kil Jaeden 4", 23);
Menu->AddItem(1,"Play Kil Jaeden 5", 24);
Menu->AddItem(1,"Play Kil Jaeden 6", 25);
Menu->AddItem(1,"Play Kil Jaeden 7", 26);
Menu->AddItem(1,"Play Kil Jaeden 8", 27);
Menu->AddItem(1,"Play Aveena 1", 28);
Menu->AddItem(1,"Play Aveena 2", 29);
Menu->AddItem(1,"Play Aveena 3", 30);
Menu->AddItem(1,"Play Kalecgos", 31);
Menu->SendTo(Plr);
}
break;

case 96:
{
 GossipMenu *Menu;
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(1,"Play MURLOC", 32);
Menu->AddItem(1,"Play Shade of Akama", 33);
Menu->AddItem(1,"Play Night Elf Female Joke", 34);
Menu->AddItem(1,"Play Pissed Orc Peon", 35);
Menu->AddItem(1,"Play Thrall Greeting", 36);
Menu->AddItem(1,"Play Headless Horseman Laugh", 37);
Menu->AddItem(1,"Play Headless Horseman Failed When all of you is dead", 38);
Menu->AddItem(1,"Play Headless Horseman He Dies!", 39);
Menu->AddItem(1,"Play Mr. Smith Deadmines 1", 40);
Menu->AddItem(1,"Play Mr. Smith Deadmines 2", 41);
Menu->AddItem(1,"Play Mr. Smith Deadmines 3", 42);
Menu->AddItem(1,"Play Mr. Smith Deadmines 4", 43);
Menu->AddItem(1,"Play Thrall - Aggroing", 44);
Menu->AddItem(1,"Play Thrall - Greeting", 45);
Menu->AddItem(1,"Play Jaina Proudmoore", 46);
Menu->SendTo(Plr);
}
break;

case 95:
{
 GossipMenu *Menu;
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(1,"Play Summon Succubus", 47);
Menu->AddItem(1,"Play Succubus Buttslap whip", 48);
Menu->AddItem(1,"Play Horde Talk", 49);
Menu->AddItem(1,"Play Baby Murloc", 50);
Menu->AddItem(1,"Play Whissle", 51, 0);
Menu->SendTo(Plr);
}
break;

case 51:
{
Plr->PlaySoundToSet(10027);
Plr->BroadcastMessage("Whisling");
Plr->Gossip_Complete();
}
break;

case 50: 
{
Plr->PlaySoundToSet(8475);
Plr->BroadcastMessage("Awwww isnt it cute, wait...get it off me!!! KILL IT");
Plr->Gossip_Complete();
}
break;

case 49: 
{
Plr->PlaySoundToSet(7120);
Plr->BroadcastMessage("Horde Talk");
Plr->Gossip_Complete();
}
break;

case 48: 
{
Plr->PlaySoundToSet(7096);
Plr->BroadcastMessage("Buttslap - whip");
Plr->Gossip_Complete();
}break;

case 47: 
{
Plr->PlaySoundToSet(6099);
Plr->BroadcastMessage("Summon Succubus - Now What? Mhmmm, you're in trouble now! Don't touch what you can't afford Couldn't resist, Could you?");
Plr->Gossip_Complete();
}break;

case 46: 
{
Plr->PlaySoundToSet(5882);
Plr->BroadcastMessage("You asked for it!/I hate resolving to violence");
Plr->Gossip_Complete();
}break;

case 45: 
{
Plr->PlaySoundToSet(6004);
Plr->BroadcastMessage("Welcome to Orgrimmar, have you come to serve the horde? Lok'Thar fri}, What is it you wish?");
Plr->Gossip_Complete();
}break;

case 44: 
{
Plr->PlaySoundToSet(5880);
Plr->BroadcastMessage("Lok'Narosh Your Time has come! For Doomhammer");
Plr->Gossip_Complete();
}break;

case 43: 
{
Plr->PlaySoundToSet(5779);
Plr->BroadcastMessage("Thuh, now you are making me angry!");
Plr->Gossip_Complete();
}break;

case 42: 
{
Plr->PlaySoundToSet(5778);
Plr->BroadcastMessage("...bla...bla... all I have to do is to improvise");
Plr->Gossip_Complete();
}break;

case 41: 
{
Plr->PlaySoundToSet(5777);
Plr->BroadcastMessage("We're under attack...");
Plr->Gossip_Complete();
}break;

case 40:
{ 
Plr->PlaySoundToSet(5775 );
Plr->BroadcastMessage("You there, check you that noise!");
Plr->Gossip_Complete();
}
break;

case 39: 
{
Plr->PlaySoundToSet(11964);
Plr->BroadcastMessage("Headless Horseman He Dies!");
Plr->Gossip_Complete();
}
break;

case 38: 
{
Plr->PlaySoundToSet(11967);
Plr->BroadcastMessage("Failed When all of you is dead");
Plr->Gossip_Complete();
}
break;

case 37: 
{
Plr->PlaySoundToSet(11965);
Plr->BroadcastMessage("HA HA HA HA HA HA HA LOL");
Plr->Gossip_Complete();
}
break;

case 36: 
{
Plr->PlaySoundToSet(7214);
Plr->BroadcastMessage("Lo Tar Fri} What Do you Wish?");
Plr->Gossip_Complete();
}
break;

case 35: 
{
Plr->PlaySoundToSet(7195);
Plr->BroadcastMessage("Pissed Orc Peon");
Plr->Gossip_Complete();
}
break;

case 34: 
{
Plr->PlaySoundToSet(6179);
Plr->BroadcastMessage("Your not funny");
Plr->Gossip_Complete();
}
break;

case 33: 
{
Plr->PlaySoundToSet(11389);
Plr->BroadcastMessage("Shade of Akama");
Plr->Gossip_Complete();
}
break;

case 32: 
{
Plr->PlaySoundToSet(11802);
Plr->BroadcastMessage("Rgrglrgrlgrl");
Plr->Gossip_Complete();
}
break;

case 31: 
{
Plr->PlaySoundToSet(12541);
Plr->BroadcastMessage("There is no time to waste The faith of the world hangs in the balance Kil Jaeden must be destroyed!");
Plr->Gossip_Complete();
}
break;

case 30: 
{
Plr->PlaySoundToSet(12513);
Plr->BroadcastMessage("Kalec? Kalec?!");
Plr->Gossip_Complete();
}
break;

case 29: 
{
Plr->PlaySoundToSet(12512);
Plr->BroadcastMessage("But I am... lost... I can not find my way back!");
Plr->Gossip_Complete();
}
break;

case 28: 
{
Plr->PlaySoundToSet(12511);
Plr->BroadcastMessage("I serve only the master now!");
Plr->Gossip_Complete();
}
break;

case 27: 
{
Plr->PlaySoundToSet(12501);
Plr->BroadcastMessage("Another step towards destruction!");
Plr->Gossip_Complete();
}
break;

case 26: 
{
Plr->PlaySoundToSet(12500);
Plr->BroadcastMessage("Very long thing, basiclly he tells us that he will take control over the Burning Legion");
Plr->Gossip_Complete();
}
break;


case 25: 
{
Plr->PlaySoundToSet(12499);
Plr->BroadcastMessage("Drain the girl, drain her power, untill there is nothing but an ...something... shell");
Plr->Gossip_Complete();
}
break;

case 24: 
{
Plr->PlaySoundToSet(12498);
Plr->BroadcastMessage("Fail me, and suffer for eternity!");
Plr->Gossip_Complete();
}
break;

case 23: 
{
Plr->PlaySoundToSet(12497);
Plr->BroadcastMessage("I've waited long enough");
Plr->Gossip_Complete();
}
break;

case 22: 
{
Plr->PlaySoundToSet(12496);
Plr->BroadcastMessage("Stay on task, do not waste time");
Plr->Gossip_Complete();
}
break;

case 21: 
{
Plr->PlaySoundToSet(12495);
Plr->BroadcastMessage("All my plans have led to this");
Plr->Gossip_Complete();
}
break;

case 20: 
{
Plr->PlaySoundToSet(12527);
Plr->BroadcastMessage("Kil Jaeden Spawning");
Plr->Gossip_Complete();
}
break;

case 1: 
{
Plr->PlaySoundToSet(11463);
Plr->BroadcastMessage("Akama your duplicity is hardly surprising I should of slaughtered you and your malformed brethren long ago");
Plr->Gossip_Complete();
}
break;

case 2:
{
Plr->PlaySoundToSet(11464);
Plr->BroadcastMessage("Boldly said but I remain unconvinced");
Plr->Gossip_Complete();
}
break;

case 3:
{
Plr->PlaySoundToSet(11465);
Plr->BroadcastMessage("Come my minions, deal with this traitor as he deserves");
Plr->Gossip_Complete();
}
break;

case 4:
{
Plr->PlaySoundToSet(11466);
Plr->BroadcastMessage("You are not prepared!!");
Plr->Gossip_Complete();
}
break;

case 5:
{
Plr->PlaySoundToSet(11467);
Plr->BroadcastMessage("I can feel your hatred");
Plr->Gossip_Complete();
}
break;

case 6:
{
Plr->PlaySoundToSet(11468 );
Plr->BroadcastMessage("Give into your fear");
Plr->Gossip_Complete();
}
break;

case 7:
{
Plr->PlaySoundToSet(11469);
Plr->BroadcastMessage("You know nothing of power");
Plr->Gossip_Complete();
}
break;

case 8:
{
Plr->PlaySoundToSet(11470);
Plr->BroadcastMessage("Feel the hatred of 10,000 years");
Plr->Gossip_Complete();
}
break;

case 9:
{
Plr->PlaySoundToSet(11471);
Plr->BroadcastMessage("Such arrogance");
Plr->Gossip_Complete();
}
break;

case 10:
{
Plr->PlaySoundToSet(11472);
Plr->BroadcastMessage("This is to easy");
Plr->Gossip_Complete();
}
break;

case 11:
{
Plr->PlaySoundToSet(11473);
Plr->BroadcastMessage("Who shall be next to taste my blades?");
Plr->Gossip_Complete();
}
break;

case 12:
{
Plr->PlaySoundToSet(11474);
Plr->BroadcastMessage("You have wasted to much time mortals. Now you shall fall");
Plr->Gossip_Complete();
}
break;

case 13:
{
Plr->PlaySoundToSet(11475);
Plr->BroadcastMessage("Behold the power of the Demon within");
Plr->Gossip_Complete();
}
break;

case 14:
{
Plr->PlaySoundToSet(11476);
Plr->BroadcastMessage("Is this it mortals? Is this all the fury you can muster?");
Plr->Gossip_Complete();
}
break;

case 15:
{
Plr->PlaySoundToSet(11477);
Plr->BroadcastMessage("Maiev. How is it even possible?");
Plr->Gossip_Complete();
}
break;

case 16:
{
Plr->PlaySoundToSet(11478);
Plr->BroadcastMessage("You have won ... Maiev , but the huntress is nothing without the hunt. You are nothing without me");
Plr->Gossip_Complete();
}
break;

case 17:
{
Plr->PlaySoundToSet(11479);
Plr->BroadcastMessage("I will not be touched by a rebel such as you");
Plr->Gossip_Complete();
}
break;

case 18:
{
Plr->PlaySoundToSet(11480);
Plr->BroadcastMessage("Behold the flames of Azzinoth!");
Plr->Gossip_Complete();
}
break;

// Codebox Mounts

case 8300:
		{
			char pItem5[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(pItem5, "Code [%u]");
			Menu->AddItem(4, pItem5, 8301, 1);
			Menu->SendTo(Plr);
		}break;

case 8301:
		{
QueryResult *pItem5 = WorldDatabase.Query("Select `male_displayid` FROM creature_names where `entry` = '%s'", Code);

if(pItem5)
{
Field *Fields = pItem5->Fetch();
uint32 male_displayid = Fields[0].GetUInt32();
Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, male_displayid);
Plr->Gossip_Complete();
}
}break;

case 8200:
		{
			char pItem5[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(pItem5, "Code [%u]");
			Menu->AddItem(4, pItem5, 8201, 1);
			Menu->SendTo(Plr);
		}break;

case 8201:
		{
QueryResult *pItem5 = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(pItem5)
{
Field *Fields = pItem5->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, entry);
Plr->Gossip_Complete();
}
}break;

case 6540:
		{
			char pItem5[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(pItem5, "Code [%u]");
			Menu->AddItem(4, pItem5, 6541, 1);
			Menu->SendTo(Plr);
		}break;

case 6541:
		{
QueryResult *pItem5 = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(pItem5)
{
Field *Fields = pItem5->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->removeSpell(entry,0,0,0);
Plr->Gossip_Complete();
}
}break;

case 6530:
		{
			char pItem5[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(pItem5, "Code [%u]");
			Menu->AddItem(4, pItem5, 6531, 1);
			Menu->SendTo(Plr);
		}break;

case 6531:
		{
QueryResult *pItem5 = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(pItem5)
{
Field *Fields = pItem5->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->addSpell(entry);
Plr->Gossip_Complete();
}
}break;

		// codebox playsoundtoset

		case 7100:
		{
			char psound[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(psound, "Code [%u]");
			Menu->AddItem(4, psound, 7110, 1);
			Menu->SendTo(Plr);
		}break;

case 7110:
		{
QueryResult *psound = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(psound)
{
Field *Fields = psound->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->PlaySoundToSet(entry);
Plr->Gossip_Complete();
}
}break;

						case 10005:
		{
			char advance[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(advance, "Code [%u]");
			Menu->AddItem(4, advance, 10105, 1);
			Menu->SendTo(Plr);
		}break;

// Codebox Advance Skills
case 10105:
		{
QueryResult *advance = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(advance)
{
Field *Fields = advance->Fetch();
uint32 entry = Fields[0].GetUInt32();
if (Plr->_HasSkillLine(43))
{Plr->_AdvanceSkillLine(43, entry);}
if (Plr->_HasSkillLine(55))
{Plr->_AdvanceSkillLine(55, entry);}
if (Plr->_HasSkillLine(44))
{Plr->_AdvanceSkillLine(44, entry);}
if (Plr->_HasSkillLine(95))
{Plr->_AdvanceSkillLine(95, entry);}
if (Plr->_HasSkillLine(54))
{Plr->_AdvanceSkillLine(54, entry);}
if (Plr->_HasSkillLine(45))
{Plr->_AdvanceSkillLine(45, entry);}
if (Plr->_HasSkillLine(46))
{Plr->_AdvanceSkillLine(46, entry);}
if (Plr->_HasSkillLine(136))
{Plr->_AdvanceSkillLine(136, entry);}
if (Plr->_HasSkillLine(160))
{Plr->_AdvanceSkillLine(160, entry);}
if (Plr->_HasSkillLine(162))
{Plr->_AdvanceSkillLine(162, entry);}
if (Plr->_HasSkillLine(172))
{Plr->_AdvanceSkillLine(172, entry);}
if (Plr->_HasSkillLine(173))
{Plr->_AdvanceSkillLine(173, entry);}
if (Plr->_HasSkillLine(176))
{Plr->_AdvanceSkillLine(176, entry);}
if (Plr->_HasSkillLine(226))
{Plr->_AdvanceSkillLine(226, entry);}
if (Plr->_HasSkillLine(228))
{Plr->_AdvanceSkillLine(228, entry);}
if (Plr->_HasSkillLine(229))
{Plr->_AdvanceSkillLine(229, entry);}
if (Plr->_HasSkillLine(473))
{Plr->_AdvanceSkillLine(473, entry);}
Plr->Gossip_Complete();
}
}break;

					// Codebox Runic Set
		case 19018:
		{
			char runic1[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(runic1, "Code [%u]");
			Menu->AddItem(4, runic1, 19019, 1);
			Menu->SendTo(Plr);
		}break;

case 19019:
		{
QueryResult *runic1 = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(runic1)
{
Field *Fields = runic1->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->SetUInt32Value(UNIT_FIELD_POWER7, entry);
Plr->SetUInt32Value(UNIT_FIELD_MAXPOWER7, entry);
Plr->Gossip_Complete();
}
}break;

			// Codebox Energy Set
		case 19016:
		{
			char energy1[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(energy1, "Code [%u]");
			Menu->AddItem(4, energy1, 19017, 1);
			Menu->SendTo(Plr);
		}break;

case 19017:
		{
QueryResult *energy1 = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(energy1)
{
Field *Fields = energy1->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->SetUInt32Value(UNIT_FIELD_POWER4, entry);
Plr->SetUInt32Value(UNIT_FIELD_MAXPOWER4, entry);
Plr->Gossip_Complete();
}
}break;


		// Codebox rage Set
		case 19014:
		{
			char rage1[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(rage1, "Code [%u]");
			Menu->AddItem(4, rage1, 19015, 1);
			Menu->SendTo(Plr);
		}break;

case 19015:
		{
QueryResult *rage1 = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(rage1)
{
Field *Fields = rage1->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->SetUInt32Value(UNIT_FIELD_POWER2, entry);
Plr->SetUInt32Value(UNIT_FIELD_MAXPOWER2, entry);
CharacterDatabase.Execute("UPDATE characters SET current_power = %u WHERE guid = %u", entry, Plr->GetGUID());
Plr->Gossip_Complete();
}
}break;

// Codebox Mana Set
		case 19007:
		{
			char mana[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(mana, "Code [%u]");
			Menu->AddItem(4, mana, 19008, 1);
			Menu->SendTo(Plr);
		}break;

case 19008:
		{
QueryResult *mana = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(mana)
{
Field *Fields = mana->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->SetUInt32Value(UNIT_FIELD_POWER1, entry);
Plr->SetUInt32Value(UNIT_FIELD_MAXPOWER1, entry);
Plr->SetUInt32Value(UNIT_FIELD_BASE_MANA, entry);
CharacterDatabase.Execute("UPDATE characters SET current_power = %u WHERE guid = %u", entry, Plr->GetGUID());
Plr->Gossip_Complete();
}
}break;

// Codebox Health Set
case 19005:
		{
			char health[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(health, "Code [%u]");
			Menu->AddItem(4, health, 19006, 1);
			Menu->SendTo(Plr);
		}break;

case 19006:
		{

QueryResult *health = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(health)
{
Field *Fields = health->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->SetUInt32Value( UNIT_FIELD_HEALTH, entry );
Plr->SetUInt32Value( UNIT_FIELD_MAXHEALTH, entry );
Plr->SetUInt32Value(UNIT_FIELD_BASE_HEALTH, entry);
CharacterDatabase.Execute("UPDATE characters SET current_hp = %u WHERE guid = %u", entry, Plr->GetGUID());
Plr->Gossip_Complete();
}
}break;

// Codebox Level

case 10004:
		{
			char level[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(level, "Code [%u]");
			Menu->AddItem(4, level, 10104, 1);
			Menu->SendTo(Plr);
		}break;

case 10104:
		{
QueryResult *level = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(level)
{
Field *Fields = level->Fetch();
uint32 entry = Fields[0].GetUInt32();
uint32 Level = entry;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
}
}break;


//Codebox FlySpeed
case 10003:
		{
			char fly[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(fly, "Code [%u]");
			Menu->AddItem(4, fly, 10103, 1);
			Menu->SendTo(Plr);
		}break;

case 10103:
		{
QueryResult *fly = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(fly)
{
Field *Fields = fly->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->SetSpeeds(FLY,     entry);
Plr->Gossip_Complete();
}
}break;

//Codebox Swim
case 10002:
		{
			char swim[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(swim, "Code [%u]");
			Menu->AddItem(4, swim, 10102, 1);
			Menu->SendTo(Plr);
		}break;

case 10102:
		{
QueryResult *swim = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(swim)
{
Field *Fields = swim->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->SetSpeeds(SWIM,     entry);
Plr->Gossip_Complete();
}
}break;

//Codebox Backwards
case 10001:
		{
			char backward[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(backward, "Code [%u]");
			Menu->AddItem(4, backward, 10101, 1);
			Menu->SendTo(Plr);
		}break;

case 10101:
		{
QueryResult *backward = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(backward)
{
Field *Fields = backward->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->SetSpeeds(RUNBACK,     entry);
Plr->Gossip_Complete();
}
}break;

//Codebox Speed
case 10000:
		{
			char pspeed[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(pspeed, "Code [%u]");
			Menu->AddItem(4, pspeed, 10100, 1);
			Menu->SendTo(Plr);
		}break;

case 10100:
		{
QueryResult *pspeed = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(pspeed)
{
Field *Fields = pspeed->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->SetSpeeds(RUN,     entry);
Plr->Gossip_Complete();
}
}break;

//Codebox Morph 

case 6507:
		{
			char Morph[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(Morph, "Code [%u]");
			Menu->AddItem(4, Morph, 6508, 1);
			Menu->SendTo(Plr);
			
		}break;

case 6508:
		{
			QueryResult *Morph = WorldDatabase.Query("Select `male_displayid` FROM creature_names where `entry` = '%s'", Code); 
			
			if(Morph)
			{
				Field *Fields = Morph->Fetch();
				uint32 male_displayid = Fields[0].GetUInt32();
				Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, male_displayid);
				}
			else
			Plr->Gossip_Complete();
				Plr->Gossip_Complete();
		}break;

case 6505:
		{
			char Morph[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(Morph, "Code [%u]");
			Menu->AddItem(4, Morph, 6506, 1);
			Menu->SendTo(Plr);
		}break;

case 6506:
		{
			QueryResult *Morph = WorldDatabase.Query("Select `male_displayid` FROM creature_names where `name` = '%s'", Code); 
			
			if(Morph)
			{
				Field *Fields = Morph->Fetch();
				uint32 male_displayid = Fields[0].GetUInt32();
				Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, male_displayid);
				}
			else
			Plr->Gossip_Complete();
				Plr->Gossip_Complete();
		}break;


		// Add Items Codeboxes
case 6501:
		{
			char pItem5[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(pItem5, "Code [%u]");
			Menu->AddItem(4, pItem5, 6502, 1);
			Menu->SendTo(Plr);
		}break;

case 6502:
		{
QueryResult *pItem5 = WorldDatabase.Query("Select `entry` FROM items where `name1` = '%s'", Code);

if(pItem5)
{
Field *Fields = pItem5->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->GetItemInterface()->AddItemToFreeSlot(objmgr.CreateItem(entry, Plr));
Plr->Gossip_Complete();
}
}break;

		case 6503:
		{
			char pItem5[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(pItem5, "Code [%u]");
			Menu->AddItem(4, pItem5, 6504, 1);
			Menu->SendTo(Plr);
		}break;

case 6504:
		{
QueryResult *pItem5 = WorldDatabase.Query("Select `entry` FROM items where `entry` = '%s'", Code);

if(pItem5)
{
Field *Fields = pItem5->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->GetItemInterface()->AddItemToFreeSlot(objmgr.CreateItem(entry, Plr));
Plr->Gossip_Complete();
}
}break;

case 6516:
		{
			char pItem5[100];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(pItem5, "Code [%u]");
			Menu->AddItem(4, pItem5, 6517, 1);
			Menu->SendTo(Plr);
		}break;

case 6517:
		{
QueryResult *pItem5 = WorldDatabase.Query("Select `entry` FROM numbers where `entry` = '%s'", Code);

if(pItem5)
{
Field *Fields = pItem5->Fetch();
uint32 entry = Fields[0].GetUInt32();
Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, entry);
Plr->Gossip_Complete();
}
}break;

		


		case 6510:
		{
			char Teleport[225];
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			sprintf(Teleport, "Code [%u]");
			Menu->AddItem(4, Teleport, 6513, 1);
			Menu->SendTo(Plr);
		}break;

   case 6513:
		{
	     QueryResult *Teleport = WorldDatabase.Query("SELECT * FROM `recall` Where `name` = '%s'", Code);


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

case 6509:
{
Plr->DeMorph();
}break;

case 6512:
{
Plr->Reset_Talents();
}break;
                case 6511:
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(4, "Port Player", 6514, 1);
			Menu->SendTo(Plr);
		}break;
case 6514:
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


void SetupGM_Stone2(ScriptMgr * mgr)
{
GossipScript * gs = (GossipScript*) new GM_Stone2();
mgr->register_item_gossip_script(189999, gs);
}
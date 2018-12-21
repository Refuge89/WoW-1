
#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)// warning C4305:'argument' :truncation from 'double' to 'float'
#endif

//Specifing WishingStone
class SCRIPT_DECL WishingStone :public GossipScript
{
public:
void GossipHello(Object * pObject, Player* Plr, bool AutoSend);
void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
void GossipEnd(Object * pObject, Player* Plr){ GossipScript::GossipEnd(pObject, Plr); }
void Destroy(){ delete this; }
};

void WishingStone::GossipHello(Object* pObject, Player * Plr, bool AutoSend)
{
if(Plr->CombatStatus.IsInCombat())
{
Plr->BroadcastMessage("You are in combat!");
return;
}
GossipMenu *Menu;
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(2, "Teleport Service", 84);
Menu->AddItem(5, "Player Store", 82);
Menu->AddItem(5, "Save Player to DB", 122);
if(AutoSend) Menu->SendTo(Plr);


}

void WishingStone::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
GossipMenu *Menu;
switch(IntId){
case 1: // Horde
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(0, "Horde Mall", 150);
Menu->AddItem(0, "Silvermoon", 4);
Menu->AddItem(0, "Orgrimmar", 5);
Menu->AddItem(0, "Thunderbluff", 6);
Menu->AddItem(0, "UnderCity", 7);
Menu->AddItem(0, "[Back]", 99);
Menu->SendTo(Plr);
}
break;

case 2: // Alliance
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(0, "Alliance Mall", 151);
Menu->AddItem(0, "The Exodar", 8);
Menu->AddItem(0, "Stormwind", 9);
Menu->AddItem(0, "Ironforge", 10);
Menu->AddItem(0, "Darnassus", 11);
Menu->AddItem(0, "[Back]", 99);
Menu->SendTo(Plr);
}
break;

case 3: // Outland
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(0, "Hellfire Peninsula", 12);
Menu->AddItem(0, "Zangermarsh", 13);
Menu->AddItem(0, "Nagrand", 14);
Menu->AddItem(0, "Blades Edge Mountains", 15);
Menu->AddItem(0, "Netherstorm", 16);
Menu->AddItem(0, "Terokkar Forest", 17);
Menu->AddItem(0, "Shadowmoon Valley", 18);
Menu->AddItem(0, "[Back]", 99);
Menu->SendTo(Plr);
}
break;

case 4:
{
Plr->SafeTeleport(530, 0, 9400.486328, -7278.376953, 14.206780, 0);
Plr->Gossip_Complete();
}break; //Silvermoon

case 5:
{
Plr->SafeTeleport(1, 0, 1371.068970, -4370.801758, 26.052483, 0);
Plr->Gossip_Complete();
}break; //Orgrimmar
case 6:
{
Plr->SafeTeleport(1, 0, -1304.569946, 205.285004, 68.681396, 0);
Plr->Gossip_Complete();
}break; //ThunderBluff
case 7:
{
Plr->SafeTeleport(0, 0, 2050.203125, 285.650604, 56.994549, 0);
Plr->Gossip_Complete();
}break; //UnderCity
case 8:
{
Plr->SafeTeleport(530, 0, -4072.202393, -12014.337891, -1.277277, 0);
Plr->Gossip_Complete();
}break; //Exodar
case 9:
{
Plr->SafeTeleport(0, 0, -9100.480469, 406.950745, 92.594185, 0);
Plr->Gossip_Complete();
}break; //Stormwind
case 10:
{
Plr->SafeTeleport(0, 0, -5028.265137, -825.976563, 495.301575, 0);
Plr->Gossip_Complete();
}break; //Ironforge
case 11:
{
Plr->SafeTeleport(1, 0, 9985.907227, 1971.155640, 1326.815674, 0);
Plr->Gossip_Complete();
}break; //Darnassus
case 150: 
{
Plr->SafeTeleport(1, 0, -3788.360107, 806.765991, 110.051010, 0);
Plr->Gossip_Complete();
}break; //Horde Mall
case 151: 
{
Plr->SafeTeleport(0, 0, -4818.500000, -974.010010, 464.709999, 0);
Plr->Gossip_Complete();
}break; //Alliance Mall
case 12:
{
Plr->SafeTeleport(530, 0, -248.160004, 922.348999, 84.379799, 0);
Plr->Gossip_Complete();
}break; //Hellfire Peninsula
case 13:
{
Plr->SafeTeleport(530, 0, -225.863632, 5405.927246, 22.346397, 0);
Plr->Gossip_Complete();
}break; //Zangermarsh
case 14:
{
Plr->SafeTeleport(530, 0, -468.232330, 8418.666016, 28.031298, 0);
Plr->Gossip_Complete();
}break; //Nagrand
case 15:
{
Plr->SafeTeleport(530, 0, 1471.672852, 6828.047852, 107.759239, 0);
Plr->Gossip_Complete();
}break; //Blades Edge Mountains
case 16:
{
Plr->SafeTeleport(530, 0, 3396.123779, 4182.208008, 137.097992, 0);
Plr->Gossip_Complete();
}break; //Netherstorm
case 17:
{
Plr->SafeTeleport(530, 0, -1202.426636, 5313.692871, 33.774723, 0);
Plr->Gossip_Complete();
}break; //Terokkar Forest
case 18:
{
Plr->SafeTeleport(530, 0, -2859.522461, 3182.34773, 10.008426, 0);
Plr->Gossip_Complete();
}break; //Shadowmoon Valley
case 20:
{
Plr->SafeTeleport(530, 0, -1887.510010, 5359.379883, -12.427300, 0);
Plr->Gossip_Complete();
}break; //Shattrath

case 30:// Primary Instances
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(0, "Ragefire Chasm", 100);
Menu->AddItem(0, "Deadmines", 101);
Menu->AddItem(0, "Wailing Caverns", 102);
Menu->AddItem(0, "Shadowfang Keep", 31);
Menu->AddItem(0, "Blackfathom Deep", 103);
Menu->AddItem(0, "Stockades", 104);
Menu->AddItem(0, "Razorfen Down", 105);
Menu->AddItem(0, "Gnomer", 106);
Menu->AddItem(0, "Scarlet Monastery", 32);
Menu->AddItem(0, "Uldaman", 107);
Menu->AddItem(0, "[Back]", 99);
Menu->SendTo(Plr);
}
break;

case 31:
{
Plr->SafeTeleport(0, 0, -234.495087, 1561.946411, 76.892143, 0);
Plr->Gossip_Complete();
}break; // Shadowfang Keep
case 32:
{
Plr->SafeTeleport(0, 0, 2870.442627, -819.985229, 160.331085, 0);
Plr->Gossip_Complete();
}break; // Scarlet Monastery
case 33:
{
Plr->SafeTeleport(1, 0, -6797.278809, -2903.917969, 9.953360, 0);
Plr->Gossip_Complete();
}break; // Zul'Farrak
case 34:
{
Plr->SafeTeleport(0, 0, -11919.073242, -1202.459374, 92.298744, 0);
Plr->Gossip_Complete();
}break; // Zul'Gurub
case 35:
{
Plr->SafeTeleport(1, 0, -8394.730469, 1485.658447, 21.038563, 0);
Plr->Gossip_Complete();
}break; // Ahn'Qirai 20
case 36:
{
Plr->SafeTeleport(1, 0, -8247.316406, 1970.156860, 129.071472, 0);
Plr->Gossip_Complete();
}break; // Ahn'Qirai 40
case 37:
{
Plr->SafeTeleport(0, 0, -7515.409668, -1045.369629, 182.301208, 0);
Plr->Gossip_Complete();
}break; // Molten Core
case 38:
{
Plr->SafeTeleport(1, 0, -4708.491699, -3727.672363, 54.535076, 0);
Plr->Gossip_Complete();
}break; // Onyxia
case 39:
{
Plr->SafeTeleport(0, 0, 3132.915283, -3731.012939, 138.658371, 0);
Plr->Gossip_Complete();
}break; // Naxxramas
case 40:
{
Plr->SafeTeleport(0, 0, 1267.468628, -2556.651367, 94.127983, 0);
Plr->Gossip_Complete();
}break; //Scholomance
case 41:
{
Plr->SafeTeleport(0, 0, 3359.111572, -3380.8444238, 144.781860, 0);
Plr->Gossip_Complete();
}break; //Stratholme
case 42:
{
Plr->SafeTeleport(0, 0, -7527.129883, -1224.997437, 285.733002, 0);
Plr->Gossip_Complete();
}break; // Black ROck Spire
case 43:
{
Plr->SafeTeleport(0, 0, -11122.913086, -2014.498779, 47.079350, 0);
Plr->Gossip_Complete();
}break; // Kharazan
case 44:
{
Plr->SafeTeleport(1, 0, -8519.718750, -4297.542480, -208.441376, 0);
Plr->Gossip_Complete();
}break; // Caverns of Times

case 60:// Outland Instances
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(0, "Outland Raids", 74);
Menu->AddItem(5, "Hellfire Ramparts", 61);
Menu->AddItem(5, "The Blood Furnace", 62);
Menu->AddItem(5, "The Shattered Halls", 63);
Menu->AddItem(5, "The Underbog", 64);
Menu->AddItem(5, "The Slave Pens", 65);
Menu->AddItem(5, "The Steamvault", 66);
Menu->AddItem(5, "Mana-Tombs", 57);
Menu->AddItem(5, "Auchenai Crypts", 68);
Menu->AddItem(5, "Sethekk Halls", 69);
Menu->AddItem(5, "Shadow Labyrinth", 70);
Menu->AddItem(5, "The Mechanar", 71);
Menu->AddItem(5, "The Botanica", 72);
Menu->AddItem(5, "The Arcatraz", 73);
Menu->AddItem(0, "[Back]", 99);
Menu->SendTo(Plr);
}
break;

case 61:
{
Plr->SafeTeleport(530, 0, -360.670990, 3071.899902, -15.097700, 0);
Plr->Gossip_Complete();
}break; // Hellfire Ramparts
case 62:
{
Plr->SafeTeleport(530, 0, -303.506012, 3164.820068, 31.742500, 0);
Plr->Gossip_Complete();
}break; // The Blood Furnace
case 63:
{
Plr->SafeTeleport(530, 0, -311.083527, 3083.291748, -3.745923, 0);
Plr->Gossip_Complete();
}break; // The Shattered Halls
case 64:
{
Plr->SafeTeleport(530, 0, 777.088989, 6763.450195, -72.062561, 0);
Plr->Gossip_Complete();
}break; // The Underbog
case 65:
{
Plr->SafeTeleport(530, 0, 719.507996, 6999.339844, -73.074303, 0);
Plr->Gossip_Complete();
}break; // The Slave Pens
case 66:
{
Plr->SafeTeleport(530, 0, 816.590027, 6934.669922, -80.544601, 0);
Plr->Gossip_Complete();
}break; // The Steamvault
case 67:
{
Plr->SafeTeleport(530, 0, -3079.810059, 4943.040039, -101.046997, 0);
Plr->Gossip_Complete();
}break; // Mana-Tombs
case 68:
{
Plr->SafeTeleport(530, 0, -3361.959961, 5225.770020, -101.047997, 0);
Plr->Gossip_Complete();
}break; // Auchenai Crypts
case 69:
{
Plr->SafeTeleport(530, 0, -3362.219971, 4660.410156, -101.049004 , 0);
Plr->Gossip_Complete();
}break; // Sethekk Halls
case 70:
{
Plr->SafeTeleport(530, 0, -3645.060059, 4943.620117, -101.047997, 0);
Plr->Gossip_Complete();
}break; // Shadow Labyrinth
case 71:
{
Plr->SafeTeleport(530, 0, 2862.409912, 1546.089966, 252.158691, 0);
Plr->Gossip_Complete();
}break; // The Mechanar
case 72:
{
Plr->SafeTeleport(530, 0, 3413.649902, 1483.319946, 182.837997, 0);
Plr->Gossip_Complete();
}break; // The Botanica
case 73:
{
Plr->SafeTeleport(530, 0, 3311.598145, 1332.745117, 505.557251, 0);
Plr->Gossip_Complete();
}break; // The Arcatraz


case 74:// Outland Raids
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(5, "Magtheridon's Lair", 75);
Menu->AddItem(5, "Serpentshrine Cavern", 76);
Menu->AddItem(5, "Gruul's Lair", 77);
Menu->AddItem(5, "The Eye", 78);
Menu->AddItem(5, "Black Temple", 79);
Menu->AddItem(0, "[Back]", 99);
Menu->SendTo(Plr);
}
break;

case 75:
{
Plr->SafeTeleport(530, 0, -313.678986, 3088.350098, -116.501999, 0);
Plr->Gossip_Complete();
}break; // Magtheridon's Lair
case 76:
{
Plr->SafeTeleport(530, 0, 830.542908, 6865.445801, -63.785503, 0);
Plr->Gossip_Complete();
}break; // Serpentshrine Cavern
case 77:
{
Plr->SafeTeleport(530, 0, 3549.424072, 5179.854004, -4.430779, 0);
Plr->Gossip_Complete();
}break; // Gruul's Lair
case 78:
{
Plr->SafeTeleport(530, 0, 3087.310059, 1373.790039, 184.643005, 0);
Plr->Gossip_Complete();
}break; // The Eye
case 79:
{
Plr->SafeTeleport(530, 0, -3609.739990, 328.252014, 37.307701, 0);
Plr->Gossip_Complete();
}break; //Black Temple


case 80:// Remove Resurrection Sickness
{
uint32 price = 10000;
uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
if (currentgold>=price){
int32 newgold = currentgold - price;
Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
Plr->BroadcastMessage("Your resurrection Sickness has been Removed!");
Plr->addSpell(15007);
Plr->removeSpell(15007,0,0,0);
}
}break;

case 81://Remove Cooldowns
{
uint32 price = 10000;
uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
if (currentgold>=price){
int32 newgold = currentgold - price;
Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
Plr->BroadcastMessage("Your cooldowns are removed!");
Plr->ResetAllCooldowns();
}else{
Plr->BroadcastMessage("You don't have enough money to afford a cooldown reset!");
}
}break;

case 82://Extra Options
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(0, "Welcome to the Store!");
Menu->AddItem(6, "Things for 1 gold", 125);
Menu->AddItem(6, "Things for 5 gold", 126);
Menu->AddItem(6, "Things for 10 gold", 127);
Menu->AddItem(6, "Things for 50 gold", 128);
Menu->AddItem(6, "Things for 100K gold", 129);
Menu->SendTo(Plr);
}break;

case 83://Reset Talentpoints
{
uint32 price = 10000;
uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
if (currentgold>=price){
int32 newgold = currentgold - price;
Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
Plr->BroadcastMessage("Your talentpoints are reset!");
Plr->Reset_Talents();
} else {
Plr->BroadcastMessage("You don't have enough money to afford a talent reset!");
}
}break;

case 84://Teleport Services
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
if (Plr->GetTeam() == 0) Menu->AddItem(2, "Main Cities", 2);
else Menu->AddItem(2, "Main Cities", 1);
Menu->AddItem(3, "Outland Locations", 3);
Menu->AddItem(8, "Shattrath", 20);
Menu->AddItem(3, "Primary Instances", 30);
Menu->AddItem(3, "Intermediate Instances", 85);
Menu->AddItem(3, "Advanced Instances", 86);
Menu->SendTo(Plr);
}
break;

case 85:// Intermediate Instances
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
Menu->AddItem(0, "Zul'Farrak", 33);
Menu->AddItem(0, "Mauradon", 108);
Menu->AddItem(0, "Temple of Atal'Hakkar", 109);
Menu->AddItem(0, "Scholomance", 40);
Menu->AddItem(0, "Dire Maul", 110);
Menu->AddItem(0, "Stratholme", 41);
Menu->AddItem(0, "[Back]", 99);
Menu->SendTo(Plr);
}
break;

case 86:// Advanced Instances
{
Menu->AddItem(0, "Blackrock Spire", 42);
Menu->AddItem(0, "Onyxia's Lair", 38);
Menu->AddItem(0, "Molten Core", 37);
Menu->AddItem(0, "Zul'Gurub", 34);
Menu->AddItem(0, "Karazhan", 43);
Menu->AddItem(0, "Ahn'Qirai 20", 35);
Menu->AddItem(0, "Ahn'Qirai 40", 36);
Menu->AddItem(0, "Naxxramas", 39);
Menu->AddItem(0, "Caverns of Times", 44);
Menu->AddItem(0, "[Back]", 99);
Menu->SendTo(Plr);
}
break;

case 99://main menu
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(2, "Teleport Service", 84);
Menu->AddItem(5, "Extra Options", 82);
Menu->AddItem(5, "Save Player to DB", 122);
Menu->SendTo(Plr);
}
break;

case 100://RFC
{
Plr->SafeTeleport(1, 0, 1896.162720, -4400.815918, 18.51077, 0);
Plr->Gossip_Complete();
}break;

case 101://Deadmines
{
Plr->SafeTeleport(0, 40, -11208.168945, 1672.513306, 24.660862, 0);
Plr->Gossip_Complete();
}break;

case 102://Wailing Caverns
{
Plr->SafeTeleport(1, 0, -738.963562, -2216.060059, 16.452505, 0);
Plr->Gossip_Complete();
}break;

case 103://BFD
{
Plr->SafeTeleport(1, 148, 4248.078125, 740.658142, 25.492624, 0);
Plr->Gossip_Complete();
}break;

case 104://Stocks
{
Plr->SafeTeleport(0, 0, -8764.830078, 846.075012, 87.484200, 0);
Plr->Gossip_Complete();
}break;

case 105://RFD
{
Plr->SafeTeleport(1, 17, -4656.239746, -2522.215820, 81.238213, 0);
Plr->Gossip_Complete();
}break;

case 106://Gnomer
{
Plr->SafeTeleport(0, 1, -5184.184570, 588.946289, 405.412659, 0);
Plr->Gossip_Complete();
}break;

case 107://Uldaman
{
Plr->SafeTeleport(0, 38, -6817.786133, -2890.666260, 8.881607, 0);
Plr->Gossip_Complete();
}break;

case 108://Mauradon
{
Plr->SafeTeleport(1, 405, -1184.042236, 2896.036621, 86.25505, 0);
Plr->Gossip_Complete();
}break;

case 109://Temp. Atal'Hakkar
{
Plr->SafeTeleport(0, 8, -10418.310547, -3831.932617, -34.974613, 0);
Plr->Gossip_Complete();
}break;

case 110://Dire Maul
{
Plr->SafeTeleport(1, 0, -3520.061279, 1089.627319, 161.066696, 0);
Plr->Gossip_Complete();
}break;

case 120: //Level to 120
{
uint32 price = 100000000;
uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
if (currentgold>=price){
int32 newgold = currentgold - price;
Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
Plr->BroadcastMessage("You are now level 120!" );
uint32 Level = 120;
LevelInfo * Info = objmgr.GetLevelInfo(Plr->getRace(), Plr->getClass(), Level);
Plr->ApplyLevelInfo(Info, Level);
Plr->Gossip_Complete();
} else {
Plr->BroadcastMessage("You don't have enough money to afford to be Leveled to 120!");
}
}break;

case 121: //Advance all skills
{
uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
if(currentgold>50000){
int32 newgold = currentgold - 50000;
Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
if (Plr->_HasSkillLine(43))
{Plr->_AdvanceSkillLine(43, 350);}
if (Plr->_HasSkillLine(55))
{Plr->_AdvanceSkillLine(55, 350);}
if (Plr->_HasSkillLine(44))
{Plr->_AdvanceSkillLine(44, 350);}
if (Plr->_HasSkillLine(95))
{Plr->_AdvanceSkillLine(95, 350);}
if (Plr->_HasSkillLine(54))
{Plr->_AdvanceSkillLine(54, 350);}
if (Plr->_HasSkillLine(45))
{Plr->_AdvanceSkillLine(45, 350);}
if (Plr->_HasSkillLine(46))
{Plr->_AdvanceSkillLine(46, 350);}
if (Plr->_HasSkillLine(136))
{Plr->_AdvanceSkillLine(136, 350);}
if (Plr->_HasSkillLine(160))
{Plr->_AdvanceSkillLine(160, 350);}
if (Plr->_HasSkillLine(162))
{Plr->_AdvanceSkillLine(162, 350);}
if (Plr->_HasSkillLine(172))
{Plr->_AdvanceSkillLine(172, 350);}
if (Plr->_HasSkillLine(173))
{Plr->_AdvanceSkillLine(173, 350);}
if (Plr->_HasSkillLine(176))
{Plr->_AdvanceSkillLine(176, 350);}
if (Plr->_HasSkillLine(226))
{Plr->_AdvanceSkillLine(226, 350);}
if (Plr->_HasSkillLine(228))
{Plr->_AdvanceSkillLine(228, 350);}
if (Plr->_HasSkillLine(229))
{Plr->_AdvanceSkillLine(229, 350);}
if (Plr->_HasSkillLine(473))
{Plr->_AdvanceSkillLine(473, 350);}
Plr->Gossip_Complete(); 
}else{
Plr->BroadcastMessage("Sorry, you don't have enought gold.");
Plr->Gossip_Complete(); 
}
}break;

case 122: //Save Player to DB
{
Plr->SaveToDB(true);
Plr->BroadcastMessage("Player Saved to DB");
Plr->Emote(EMOTE_ONESHOT_CHEER);
}break;

case 123: //Explore all Maps
{
uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
if(currentgold>100000){
int32 newgold = currentgold - 100000;
Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
for (uint8 i=0; i<64; i++)
{
Plr->SetFlag(PLAYER_EXPLORED_ZONES_1+i,0xFFFFFFFF);
}
Plr->BroadcastMessage("All Map Locations have been opened!");
Plr->Gossip_Complete();
}else{
Plr->BroadcastMessage("Sorry, you don't have enough gold.");
Plr->Gossip_Complete();
}
}break;

case 124: //Open all FlightPaths
{
uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE);
if(currentgold>500000){
int32 newgold = currentgold - 500000;
Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold);
for (uint8 i=0; i<8; i++)
{
Plr->SetTaximask(i, 0xFFFFFFFF);
}
Plr->BroadcastMessage("All FlightPaths have been opened!");
Plr->Gossip_Complete();
}else{
Plr->BroadcastMessage("Sorry, you don't have enough gold.");
Plr->Gossip_Complete();
}
}break;

case 125: //Things for 1gold
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(0, "Everything here is 1 gold");
Menu->AddItem(5, "Remove Resurrection Sickness", 80);
Menu->AddItem(5, "Remove Cooldowns", 81);
Menu->AddItem(5, "Reset Talentpoints", 83);
Menu->SendTo(Plr);
}break;

case 126: //Things for 5gold
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(0, "Everything here is 5 gold");
Menu->AddItem(5, "Advance All Skills", 121);
Menu->SendTo(Plr);
}break;

case 127: //Things for 10gold
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(0, "Everything here is 10 gold");
Menu->AddItem(5, "Illumine All Maps", 123);
Menu->SendTo(Plr);
}break;

case 128: //Things for 50gold
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(0, "Everything here is 50 gold");
Menu->AddItem(5, "Open all FlightPaths", 124);
Menu->SendTo(Plr);
}break;

case 129: //Things for 100Kgold
{
objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
Menu->AddItem(0, "Everything here is 100K gold");
Menu->AddItem(5, "Pay for Level 75", 75);
}break;

case 59:{ //Hearth
Plr->SafeTeleport(Plr->GetBindMapId(), Plr->GetBindZoneId(), Plr->GetBindPositionX(),
Plr->GetBindPositionY(), Plr->GetBindPositionZ(), 0);
}break;
}//switch
}


void SetupWishingStone(ScriptMgr * mgr)
{
GossipScript * gs = (GossipScript*) new WishingStone();
mgr->register_item_gossip_script(88888, gs);
}
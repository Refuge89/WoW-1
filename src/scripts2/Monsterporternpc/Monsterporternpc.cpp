//Projectfile remade by Keazain

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)// warning C4305: 'argument' : truncation from 'double' to 'float'
#endif


class SCRIPT_DECL Monsterporternpc : public GossipScript
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

void Monsterporternpc::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
	GossipMenu *Menu;
    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
	if(Plr->GetTeam() == 1)
	{
		Menu->AddItem(1, "Horde Cities", 1);
	}
	else
	{
		Menu->AddItem(1, "Alliance Cities", 2);
	}
		Menu->AddItem(2, "Global Locations", 80);				
		Menu->AddItem(3, "Azeroth Instances", 30);
		Menu->AddItem(4, "Outland Instances", 50);
		Menu->AddItem(7, "Northrend Instances", 250);
		Menu->AddItem(5, "Shattrath", 20);
		Menu->AddItem(5, "Dalaran", 400);
		Menu->AddItem(6, "Gurubashi Arena", 21);
		Menu->AddItem(7, "Ebon Hold", 401);

	if(AutoSend)
        Menu->SendTo(Plr);
}

void Monsterporternpc::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
		return;

    GossipMenu * Menu;
	switch(IntId)
	{
	case 0:
		{
			GossipHello(pObject, Plr, true);
		}
		break;

	case 1:		// Horde Cities
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Silvermoon", 4);
            Menu->AddItem(5, "Orgrimmar", 5);
            Menu->AddItem(5, "Thunder Bluff", 6);
            Menu->AddItem(5, "Undercity", 7);
			Menu->SendTo(Plr);
		}
		break;

	case 2:		// Alliance Cities
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(5, "The Exodar", 8);
            Menu->AddItem(5, "Stormwind", 9);
            Menu->AddItem(5, "Ironforge", 10);
            Menu->AddItem(5, "Darnassus", 11);
			Menu->SendTo(Plr);
		}
        break;
	
	case 3:		// Outland Locations
	    {
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(5, "Hellfire Peninsula", 12);
            Menu->AddItem(5, "Zangarmarsh", 13);
            Menu->AddItem(5, "Nagrand", 14);
            Menu->AddItem(5, "Blades Edge Mountains", 15);
            Menu->AddItem(5, "Netherstorm", 16);
            Menu->AddItem(5, "Terokkar Forest", 17);
            Menu->AddItem(5, "Shadowmoon Valley", 18);
			Menu->SendTo(Plr);
		}
        break;

	case 4:		//Silvermoon
        {
			Plr->EventTeleport(530, 9400.486328, -7278.376953, 14.206780);
        }
		break;

	case 5:		//Orgrimmar
        {
			Plr->EventTeleport(1, 1371.068970, -4370.801758, 26.052483);
        }
		break;
	
	case 6:		//ThunderBluff
        {
			Plr->EventTeleport(1, -1304.569946, 205.285004, 68.681396);
        }
		break;

	case 7:		//Undercity
        {
			Plr->EventTeleport(0, 2050.203125, 285.650604, 56.994549);
        }
		break;

	case 8:		//Exodar
        {
			Plr->EventTeleport(530, -4072.202393, -12014.337891, -1.277277);
        }
		break;

	case 9:		//Stormwind
        {
            Plr->EventTeleport(0, -9100.480469, 406.950745, 92.594185);
        }
		break;

	case 10:	//Ironforge
        {
            Plr->EventTeleport(0, -5028.265137, -825.976563, 495.301575);
        }
		break;

	case 11:	//Darnassus
        {
            Plr->EventTeleport(1, 9985.907227, 1971.155640, 1326.815674);
        }
		break;

    case 12:	//Hellfire Peninsula
        {
            Plr->EventTeleport(530, -248.160004, 922.348999, 84.379799);
        }
		break;

    case 13:	//Zangermarsh
        {
            Plr->EventTeleport(530, -225.863632, 5405.927246, 22.346397);
        }
		break;

    case 14:	//Nagrand
        {
            Plr->EventTeleport(530, -468.232330, 8418.666016, 28.031298);
        }
		break;

    case 15:	//Blades Edge Mountains
        {
            Plr->EventTeleport(530, 1471.672852, 6828.047852, 107.759239);
        }
		break;

    case 16:	//Netherstorm
        {
			Plr->EventTeleport(530, 3396.123779, 4182.208008, 137.097992);
        }
		break;

    case 17:	//Terokkar Forest
        {
            Plr->EventTeleport(530, -1202.426636, 5313.692871, 33.774723);
        }
		break;

    case 18:	//Shadowmoon Valley
        {
            Plr->EventTeleport(530, -2859.522461, 3182.34773, 10.008426);
        }
		break;

	case 20:	//Shattrath
		{
            Plr->EventTeleport(530, -1887.510010, 5359.379883, -12.427300);
		}
		break;

	case 21:	// Gurubsahi Arena
		{
            Plr->EventTeleport(0, -13271.959961, 149.105515, 34.464458);
		}
		break;
           
	case 30:	// Azeroth Instances 
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Shadowfang Keep", 31);
			Menu->AddItem(5, "Scarlet Monastery", 32);
			Menu->AddItem(5, "Zul'Farrak", 33);
			Menu->AddItem(5, "Stratholme", 41);
            Menu->AddItem(5, "Scholomance", 40);
			Menu->AddItem(5, "Blackrock Spire", 42);
			Menu->AddItem(5, "Onyxia's Lair", 38);
			Menu->AddItem(5, "Molten Core", 37);
			Menu->AddItem(5, "Zul'Gurub", 34);
			Menu->AddItem(5, "Karazhan", 43);
			Menu->AddItem(5, "Ahn'Qirai 20", 35);
            Menu->AddItem(5, "Ahn'Qirai 40", 36);
            Menu->AddItem(5, "Naxxramas", 39);
			Menu->AddItem(5, "Caverns of Time", 44);
            Menu->SendTo(Plr);
		}
		break;

	case 31:	// Shadowfang Keep
		{
			Plr->EventTeleport(0, -234.495087, 1561.946411, 76.892143);
		}
		break;

	case 32:	// Scarlet Monastery
		{
            Plr->EventTeleport(0, 2870.442627, -819.985229, 160.331085);
		}
		break;

	case 33:	// Zul'Farrak
		{
            Plr->EventTeleport(1, -6797.278809, -2903.917969, 9.953360);
		}
		break;

	case 34:	// Zul'Gurub
		{
            Plr->EventTeleport(0, -11919.073242, -1202.459374, 92.298744);
		}
		break;

	case 35:	// Ahn'Qirai 20
		{
            Plr->EventTeleport(1, -8394.730469, 1485.658447, 21.038563);
		}
		break;

	case 36:	// Ahn'Qirai 40
		{
			Plr->EventTeleport(1, -8247.316406, 1970.156860, 129.071472);
		}
		break;

	case 37:	// Molten Core
		{
            Plr->EventTeleport(409, 1089.6, -470.19, -106.41);
		}
		break;
     
	case 38:	// Onyxia
		{
			Plr->EventTeleport(249, 30.0, -64.0, -5.0);
		}
		break;

	case 39:	// Naxxramas
		{
			Plr->EventTeleport(533, 3006.06, -3436.72, 293.891);
		}
		break;

	case 40:	//Scholomance
		{ 
			Plr->EventTeleport(0, 1267.468628, -2556.651367, 94.127983);
		}
		break;

	case 41:	//Stratholme
		{ 
			Plr->EventTeleport(0, 3359.111572, -3380.8444238, 144.781860);
		}
		break;
     
	case 42:	// Black Rock Spire
		{ 
			Plr->EventTeleport(0, -7527.129883, -1224.997437, 285.733002);
		}
		break;
	
	case 43:	// Kharazan
		{ 
			Plr->EventTeleport(0, -11120.89, -2012.627, 48);
		}
		break;
			
	case 44:	// Caverns of Times
		{ 
			Plr->EventTeleport(1, -8519.718750, -4297.542480, -208.441376);
		}
		break;

	case 50:	// Outland Instances
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "Outland Raids", 64);
			Menu->AddItem(5, "Hellfire Ramparts", 51);
        	Menu->AddItem(5, "The Blood Furnace", 52);
        	Menu->AddItem(5, "The Shattered Halls", 53);
        	Menu->AddItem(5, "The Underbog", 54);
        	Menu->AddItem(5, "The Slave Pens", 55);
        	Menu->AddItem(5, "The Steamvault", 56);
        	Menu->AddItem(5, "Mana-Tombs", 57);
        	Menu->AddItem(5, "Auchenai Crypts", 58);
        	Menu->AddItem(5, "Sethekk Halls", 59);
        	Menu->AddItem(5, "Shadow Labyrinth", 60);
        	Menu->AddItem(5, "The Mechanar", 61);
			Menu->AddItem(5, "The Botanica", 62);
			Menu->AddItem(5, "The Arcatraz", 63);
			Menu->SendTo(Plr);
		}
		break;
				
	case 51:	// Hellfire Ramparts
		{ 
			Plr->EventTeleport(530, -360.670990, 3071.899902, -15.097700);
		}
		break;
	
	case 52:	// The Blood Furnace
		{ 
			Plr->EventTeleport(530, -303.506012, 3164.820068, 31.742500);
		}
		break;

	case 53:	// The Shattered Halls
		{ 
			Plr->EventTeleport(530, -311.083527, 3083.291748, -3.745923);
		}
		break;

	case 54:	// The Underbog
		{ 
			Plr->EventTeleport(530, 777.088989, 6763.450195, -72.062561);
		}
		break;

	case 55:	// The Slave Pens
		{ 
			Plr->EventTeleport(530, 719.507996, 6999.339844, -73.074303);
		}
		break;

	case 56:	// The Steamvault
		{ 
			Plr->EventTeleport(530, 816.590027, 6934.669922, -80.544601);
		}
		break;

	case 57:	// Mana-Tombs
		{ 
			Plr->EventTeleport(530, -3079.810059, 4943.040039, -101.046997);
		}
		break;

	case 58:	// Auchenai Crypts
		{ 
			Plr->EventTeleport(530, -3361.959961, 5225.770020, -101.047997);
		}
		break;

	case 59:	// Sethekk Halls
		{ 
			Plr->EventTeleport(530, -3362.219971, 4660.410156, -101.049004 );
		}
		break;

	case 60:	// Shadow Labyrinth
		{ 
			Plr->EventTeleport(530, -3645.060059, 4943.620117, -101.047997);
		}
		break;

	case 61:	// The Mechanar
		{ 
			Plr->EventTeleport(530, 2862.409912, 1546.089966, 252.158691);
		}
		break;

	case 62:	// The Botanica
		{ 
			Plr->EventTeleport(530, 3413.649902, 1483.319946, 182.837997);
		}
		break;
	
	case 63:	// The Arcatraz
		{ 
			Plr->EventTeleport(530, 3311.598145, 1332.745117, 505.557251);
		}
		break;

	case 64:	// Outland Raids
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(5, "Magtheridon's Lair", 65);
			Menu->AddItem(5, "Serpentshrine Cavern", 66);
            Menu->AddItem(5, "Gruul's Lair", 67);
			Menu->AddItem(5, "The Eye", 68);
			Menu->AddItem(5, "Black Temple", 69);
			Menu->SendTo(Plr);
		}
		break;

	case 65:	// Magtheridon's Lair
		{
			Plr->EventTeleport(530, -313.678986, 3088.350098, -116.501999);
		}
		break;

	case 66:	// Serpentshrine Cavern
		{ 
			Plr->EventTeleport(530, 830.542908, 6865.445801, -63.785503);
		}
		break;

	case 67:	// Gruul's Lair
		{ 
			Plr->EventTeleport(530, 3549.424072, 5179.854004, -4.430779);
		}
		break;

	case 68:	// The Eye
		{ 
			Plr->EventTeleport(530, 3087.310059, 1373.790039, 184.643005);
		}
		break;

	case 69:	// Black Temple
		{
			Plr->EventTeleport(564, 97.0894, 1001.96, -86.8798 );
		}
		break;
				
	case 80:	// Sub Menu
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Eastern Kingdoms", 81);
			Menu->AddItem(5, "Kalimdor", 82);
			Menu->AddItem(5, "Outland", 3);
			Menu->AddItem(5, "Northrend", 340);
            Menu->SendTo(Plr);
		}
		break;

	case 81:	// Eastern Kingdoms
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Eastern Plaguelands", 70);
			Menu->AddItem(5, "Western Plaguelands", 71);
			Menu->AddItem(5, "Tristfal Glades", 72);
			Menu->AddItem(5, "Alterac Mountains", 73);
			Menu->AddItem(5, "Silverpine Forest", 74);
			Menu->AddItem(5, "Hillsbrad Foothills", 75);
			Menu->AddItem(5, "The Hinterlands", 76);
			Menu->AddItem(5, "Arathi Highlands", 77);
			Menu->AddItem(5, "Dun Morogh", 79);
			Menu->AddItem(5, "Badlands", 101);
			Menu->AddItem(5, "Redridge Mountain", 103);
			Menu->AddItem(5, "Elwynn Forest", 104);
			Menu->AddItem(5, "Duskwood", 105);
			Menu->AddItem(5, "Westfall", 106);
			Menu->AddItem(5, "Stranglethorn Vale", 110);
            Menu->SendTo(Plr);
		}
		break;

	case 82:	// KALIMDOR
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Moonglade", 111);
			Menu->AddItem(5, "Winterspring", 112);
			Menu->AddItem(5, "Felwood", 113);
			Menu->AddItem(5, "Darkshore", 114);
			Menu->AddItem(5, "Azshara", 115);
			Menu->AddItem(5, "Ashenvale", 116);
			Menu->AddItem(5, "Stonetalon Mountains", 117);
			Menu->AddItem(5, "The Barrens", 118);
			Menu->AddItem(5, "Durotar", 119);
			Menu->AddItem(5, "Mulgore", 120);
			Menu->AddItem(5, "Dustwallow Marsh", 122);
			Menu->AddItem(5, "Feralas", 123);
			Menu->AddItem(5, "Thousand Needles", 124);
			Menu->AddItem(5, "Un'Goro Crater", 126);
			Menu->AddItem(5, "Silithus", 127);
            Menu->SendTo(Plr);
		}
		break;
	/*/////////////////////////*/
	/*//  Eastern Kingdoms   //*/
	/*/////////////////////////*/

	case 70:	// WesternPlaguelands
		{
			Plr->EventTeleport( 0, 1855, -1569, 61);
		}
		break;
		
	case 71:	// EasternPlaguelands 
		{
			Plr->EventTeleport( 0, 2278, -5311, 89);
		}
		break;

	case 72:	// TristfallGlades
		{
			Plr->EventTeleport( 0, 2032, -432, 37);
		}
		break;

	case 73:	// AlteracMountains
		{
			Plr->EventTeleport( 0, 552, -275, 152);
		}
		break;

	case 74:	// Silverpine Forest
		{
			Plr->EventTeleport( 0, -126, 815, 68);
		}
		break;

	case 75:	// Hillsbrad
		{
			Plr->EventTeleport( 0, -502, 91, 61);
		}
		break;

	case 76:	// TheHinterlands
		{
			Plr->EventTeleport( 0, -678, -4018, 240);
		}
		break;

	case 77:	// ArathiHighlands
		{
			Plr->EventTeleport( 0, -797, -2068, 35);
		}
		break;

	case 78:	// Wetlands
		{
			Plr->EventTeleport( 0, -3256, -2718, 11);
		}
		break;

	case 79:	// Dunmorogh
		{
			Plr->EventTeleport( 0, -5826, -1586, 366);
		}
		break;

	case 100:	// Lochmodan
		{
			Plr->EventTeleport( 0, -4771, -3329, 347);
		}
		break;

	case 101:	// Badlands
		{
			Plr->EventTeleport( 0, -7027, -3330, 243);
		}
		break;

	case 102:	// Blackrockmountain
		{
			Plr->EventTeleport( 0, -7317, -1072, 279);
		}
		break;

	case 103:	// Redridgemountain
		{
			Plr->EventTeleport( 0, -9168, -2726, 92);
		}
		break;

	case 104:	// ElwynnForest
		{
			Plr->EventTeleport( 0, -9325, -1038, 67);
		}
		break;

	case 105:	// Duskwood
		{
			Plr->EventTeleport( 0, -10557.251953, -1184.351074, 27.989096);
		}
		break;

	case 106:	// Westfall
		{
			Plr->EventTeleport( 0, -11018, 1513, 45);
		}
		break;

	case 107:	// SwampofSorrows
		{
			Plr->EventTeleport( 0, -10429, -3828, -29);
		}
		break;

	case 108:	// BlastedLands
		{
			Plr->EventTeleport( 0, -11853, -3197, -25);
		}
		break;

	case 109:	// DeadwindPass
		{
			Plr->EventTeleport( 0, -10435, -1809, 101);
		}
		break;

	case 110:	// Stranglethornvale
		{
			Plr->EventTeleport( 0, -13245, -117, 19);
		}
		break;

	/*/////////////////////////*/
	/*//      Kalimdor       //*/
	/*/////////////////////////*/

	case 111:	// Moonglade
		{
			Plr->EventTeleport( 1, 7978, -2501, 490);
		}
		break;

	case 112:	// winterspring
		{
			Plr->EventTeleport( 1, 6721, -4659, 722);
		}
		break;

	case 113:	// felwood
		{
			Plr->EventTeleport( 1, 4878, -614, 362);
		}
		break;

	case 114:	// darkshore
		{
			Plr->EventTeleport( 1, 4565, 438, 34);
		}
		break;

	case 115:	// azshara
		{
			Plr->EventTeleport( 1, 2717, -5968, 108);
		}
		break;

	case 116:	// ashenvale
		{
			Plr->EventTeleport( 1, 3469, 847, 7);
		}
		break;

	case 117:	// Stonetalon
		{
			Plr->EventTeleport( 1, 898, 922, 128);
		}
		break;

	case 118:	// TheBarrens
		{
			Plr->EventTeleport( 1, -1330, -3120, 93);
		}
		break;

	case 119:	// Durotar
		{
			Plr->EventTeleport( 1, 242, -5151, 3);
		}
		break;

	case 120:	// Mulgore
		{
			Plr->EventTeleport( 1, -2326, -367, -6);
		}
		break;

	case 121:	// Desolace
		{
			Plr->EventTeleport( 1, -939, 1091, 95);
		}
		break;

	case 122:	// Dustwallow
		{
			Plr->EventTeleport( 1, -3719, -2530, 71);
		}
		break;

	case 123:	// Feralas
		{
			Plr->EventTeleport( 1, -4508, 2041, 53);
		}
		break;

	case 124:	// ThousandNeedles
		{
			Plr->EventTeleport( 1, -4619, -1850, 88);
		}
		break;

	case 125:	// Tanaris
		{
			Plr->EventTeleport( 1, -7373, -2950, 12);
		}
		break;

	case 126:	// Ungoro
		{
			Plr->EventTeleport( 1, -6186, -1106, -215);
		}
		break;

	case 127:	// Silithus
		{
			Plr->EventTeleport( 1, -6824, 821, 51);
		}
		break;

	case 200:	// horde mall
		{
			Plr->EventTeleport(1,7438.579102,-1578.503906,177.678391);
		}
		break;

	case 201:	// alliance mall
		{
			Plr->EventTeleport(0,-3993.089111,-1300.504272,147.221375);
		}
		break;
	
	case 250:	// Northrend Instances
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(2, "Raids", 270);
			Menu->AddItem(1, "Utgarde Keep", 251);
			Menu->AddItem(1, "Azjol-Nerub", 252);
			Menu->AddItem(1, "Ahn'kahet: The Old Kingdom", 253);
			Menu->AddItem(1, "The Nexus", 254);
			Menu->AddItem(1, "Drak'tharon Keep", 255);
			Menu->AddItem(1, "The Oculus", 256);
			Menu->AddItem(1, "Utgarde Pinnacle", 257);
			Menu->AddItem(1, "Halls of Lightning", 258);
			Menu->AddItem(1, "Halls of Stone", 259);
			Menu->AddItem(1, "Caverns of Time: Stratholme", 260);
			Menu->SendTo(Plr);
		}
		break;

	case 251:	// Utgarde Keep
		{
			Plr->EventTeleport(571, 1221.322632, -4863.814941, 41.248299);
		}
		break;

	case 252:	// Azjol-Nerub
		{
			Plr->EventTeleport(571, 3701.362305, 2153.350830, 36.178722);
		}
		break;

	case 253:	// Ahn'lahet: The Old Kingdom
		{
			Plr->EventTeleport(571, 3701.362305, 2153.350830, 36.178722);
		}
		break;

	case 254:	// The Nexus
		{
			Plr->EventTeleport(571, 3869.806641, 6983.833984, 79.450546);
		}
		break;

	case 255:	// Drak'tharon Keep
		{
			Plr->EventTeleport(571, 4778.303223, -2037.986572, 229.416977);
		}
		break;

	case 256:	// The Oculus
		{
			Plr->EventTeleport(571, 3880.103516, 6984.548828, 106.320435);
		}
		break;

	case 257:	// Utgarde Pinnacle
		{
			Plr->EventTeleport(571, 1251.779175, -4853.859375, 215.808105);
		}
		break;

	case 258:	// Halls of Lightning
		{
			Plr->EventTeleport(571, 9184.712891, -1386.436523, 110.215820);
		}
		break;

	case 259:	// Halls of Stone
		{
			Plr->EventTeleport(571, 8922.276367, -978.684509, 1039.279663);
		}
		break;

	case 260:	// Strat
		{
			Plr->EventTeleport(1, -8669.609375, -4396.958984, -207.080170);
		}
		break;

	case 270:	// Raids
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(1, "Naxxramas", 271);
			Menu->AddItem(1, "Obsidian Sanctum", 272);
			Menu->AddItem(1, "The Eye of Eternity", 273);
			Menu->SendTo(Plr);
		}
		break;

	case 271:	// Naxxramas
		{
			Plr->EventTeleport(571, 3666.149902, -1268.829956, 243.509003);
		}
		break;

	case 272:	// Obsidian Sanctum
		{
			Plr->EventTeleport(571, 3456.954590, 262.589355, -113.760834);
		}
		break;

	case 273:	// The Eye of Eternity
		{
			Plr->EventTeleport(571, 3860.425537, 6989.365234, 152.042938);
		}
		break;

	case 340:	// Northrend Places
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(1, "Borean Tundra", 341);
			Menu->AddItem(1, "Howling Fjord", 342);
			Menu->AddItem(1, "Dragonblight", 343);
			Menu->AddItem(1, "Grizzly Hills", 344);
			Menu->AddItem(1, "Zul'Drak", 350);
			Menu->AddItem(1, "Sholazar Basin", 345);
			Menu->AddItem(1, "Wintergrasp", 346);
			Menu->AddItem(1, "Crystalsong Forest", 347);
			Menu->AddItem(1, "The Storm Peaks", 348);
			Menu->AddItem(1, "Icecrown", 349);
			Menu->SendTo(Plr);
		}
		break;

	case 341:	// Borean Tundra
		{
			Plr->EventTeleport(571, 2115.623779, 5895.858398, 52.914154);
		}
		break;

	case 342:	// Howling Fjord
		{
			Plr->EventTeleport(571, 1306.546021, -4441.364258, 155.933655);
		}
		break;

	case 343:	// Dragonblight
		{
			Plr->EventTeleport(571, 4021.174072, 385.383759, 43.490700);
		}
		break;

	case 344:	// Grizzly Hills
		{
			Plr->EventTeleport(571, 3229.770264, -3100.481445, 156.359146);
		}
		break;

	case 345:	// Sholazar Basin
		{
			Plr->EventTeleport(571, 4948.726074, 4941.384277, -101.473122);
		}
		break;

	case 346:	// Wintergrasp
		{
			Plr->EventTeleport(571, 5022.753418, 2734.057617, 374.284180);
		}
		break;

	case 347:	// Crystalsong Forest
		{
			Plr->EventTeleport(571, 5578.790039, -37.320599, 150.171005);
		}
		break;

	case 348:	// The Storm Peaks
		{
			Plr->EventTeleport(571, 6120.010254, -1014.306702, 408.463745);
		}
		break;

	case 349:	// Icecrown
		{
			Plr->EventTeleport(571, 7585.503418, 2060.755371, 500.262878);
		}
		break;

	case 350:	// Zul'drak
		{
			Plr->EventTeleport(571, 5514.670410, -3600.238037, 363.166321);
		}
		break;

	case 400:	// Dalaran
		{
			Plr->BroadcastMessage("Dalaran is buggy at the moment, Please check back later");
		}
		break;

	case 401:	// Ebon Hold
		{
			Plr->EventTeleport(609, 2359.870117, -5663.620117, 426.027008);
		}
		break;
      
	case 99:	// Main Menu
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		if(Plr->GetTeam() == 1)
		{
			Menu->AddItem(1, "Horde Mall", 200);
		}
		else
		{
			Menu->AddItem(1, "Alliance Mall", 201);
		}
			Menu->AddItem(2, "Global Locations", 80);				
			Menu->AddItem(3, "Azeroth Instances", 30);
			Menu->AddItem(4, "Outland Instances", 50);
			Menu->AddItem(5, "Shattrath", 20);
			Menu->AddItem(5, "Dalaran", 400);
			Menu->AddItem(6, "Gurubashi Arena", 21);
			Menu->AddItem(7, "Ebon Hold", 401);
			Menu->SendTo(Plr);
		}
		break;
	}
}

void Monsterporternpc::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupMonsterporternpc(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new Monsterporternpc();
    mgr->register_gossip_script(99000064, gs); 
}
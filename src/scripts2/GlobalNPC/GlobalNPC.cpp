#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)
#endif


class SCRIPT_DECL GlobalNPC : public GossipScript
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
void GlobalNPC::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(0, "Horde Cities", 1);}else{Menu->AddItem(1, "Alliance Cities", 2);}
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(9, "Horde Mall", 1000);}else{Menu->AddItem(9, "Alliance Mall", 1001);}
		Menu->AddItem(2, "Global Locations", 80);				
		Menu->AddItem(3, "Azeroth Instances", 30);
		Menu->AddItem(4, "Outland Instances", 50);
		Menu->AddItem(5, "Shattrath", 20);
		Menu->AddItem(10, "Isle of Quel'Danas", 22);
		Menu->AddItem(11, "Northrend Locations", 22222);
		Menu->AddItem(6, "Gurubashi Arena", 21);
		Menu->AddItem(8, "Buff me up, baby!", 96);
		Menu->AddItem(7, "Make This Place Your Home", 95);		
		Menu->AddItem(9, "Remove Resurrection Sickness", 97);

		if(AutoSend)
            Menu->SendTo(Plr);
    }

void GlobalNPC::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
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
	                
        case 1:     // Hord Cities
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		        Menu->AddItem(5, "Silvermoon", 4);
                Menu->AddItem(5, "Orgrimmar", 5);
                Menu->AddItem(5, "Thunder Bluff", 6);
                Menu->AddItem(5, "Undercity", 7);
                Menu->AddItem(5, "Hyjal Horde Leveling up", 1111);

                Menu->SendTo(Plr);
				}
		break;


        case 2:     // Alliance Cities
				{
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                Menu->AddItem(5, "The Exodar", 8);
                Menu->AddItem(5, "Stormwind", 9);
                Menu->AddItem(5, "Ironforge", 10);
                Menu->AddItem(5, "Darnassus", 11);
                Menu->AddItem(5, "Hyjal Alliance Leveling up", 3333);

                Menu->SendTo(Plr);
				}
            break;

        case 3:     // Outland Locations
	        	{
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                Menu->AddItem(5, "Hellfire Peninsula", 12);
                Menu->AddItem(5, "Zangermarsh", 13);
                Menu->AddItem(5, "Nagrand", 14);
                Menu->AddItem(5, "Blades Edge Mountains", 15);
                Menu->AddItem(5, "Netherstorm", 16);
                Menu->AddItem(5, "Terokkar Forest", 17);
                Menu->AddItem(5, "Shadowmoon Valley", 18);

                Menu->SendTo(Plr);
				}
            break;

        case 4://Silvermoon
        {
        Plr->EventTeleport(530, 9400.486328, -7278.376953, 14.206780);
        }break;

        case 5://Orgrimmar
        {
        Plr->EventTeleport(1, 1371.068970, -4370.801758, 26.052483);
        }break;

        case 6://ThunderBluff
            {
                Plr->EventTeleport(1, -1304.569946, 205.285004, 68.681396);
            }
			break;

        case 7://Undercity
            {
                Plr->EventTeleport(0, 2050.203125, 285.650604, 56.994549);
            }
			break;

        case 1111://Hyjal Horde Leveling up
            {
                Plr->EventTeleport(1, 4621.73, -3857.79, 944.318);
            }
			break;

        case 8: //Exodar
            {
                Plr->EventTeleport(530, -4072.202393, -12014.337891, -1.277277);
            }
			break;

        case 9: //Stormwind
            {
                Plr->EventTeleport(0, -9100.480469, 406.950745, 92.594185);
            }
			break;

        case 10: //Ironforge
            {
                Plr->EventTeleport(0, -5028.265137, -825.976563, 495.301575);
            }
			break;

        case 11: //Darnassus
            {
                Plr->EventTeleport(1, 9985.907227, 1971.155640, 1326.815674);
            }
			break;

        case 3333: //Hyjal Alliance Leveling up
            {
                Plr->EventTeleport(1, 4372.62, -3241.74, 1040.21);
            }
			break;

        case 12: //Hellfire Peninsula
            {
                Plr->EventTeleport(530, -248.160004, 922.348999, 84.379799);
            }
			break;

        case 13: //Zangermarsh
            {
                Plr->EventTeleport(530, -225.863632, 5405.927246, 22.346397);
            }
			break;

        case 14: //Nagrand
            {
                Plr->EventTeleport(530, -468.232330, 8418.666016, 28.031298);

            }
			break;

        case 15: //Blades Edge Mountains
            {
                Plr->EventTeleport(530, 1471.672852, 6828.047852, 107.759239);

            }
			break;

        case 16: //Netherstorm
            {
                Plr->EventTeleport(530, 3396.123779, 4182.208008, 137.097992);

            }
			break;

        case 17: //Terokkar Forest
            {
                Plr->EventTeleport(530, -1202.426636, 5313.692871, 33.774723);

            }
			break;

        case 18: //Shadowmoon Valley
            {
                Plr->EventTeleport(530, -2859.522461, 3182.34773, 10.008426);

            }
			break;

		case 20: //Shattrath
			 {
                Plr->EventTeleport(530, -1887.510010, 5359.379883, -12.427300);

			 }
			 break;
		case 21: // Gurubsahi Arena
			 {
                Plr->EventTeleport(0, -13271.959961, 149.105515, 34.464458);

			 }
			 break;
           	case 22: // Isle of Quel'Danas
			 {
		Plr->EventTeleport(530, 13004.644531, -6910.463867, 9.584230);

			 }
			 break;
		case 30: // Azeroth Instances 
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

		case 31: // Shadowfang Keep
			 {
                             Plr->EventTeleport(0, -234.495087, 1561.946411, 76.892143);
			 }
			 break;
		case 32: // Scarlet Monastery
			 {
                             Plr->EventTeleport(0, 2870.442627, -819.985229, 160.331085);
			 }
			 break;
		case 33: // Zul'Farrak
			 {
                             Plr->EventTeleport(1, -6797.278809, -2903.917969, 9.953360);
			 }
			 break;
		case 34: // Zul'Gurub
			 {
                             Plr->EventTeleport(0, -11919.073242, -1202.459374, 92.298744);
			 }
			 break;
		case 35: // Ahn'Qirai 20
			 {
                             Plr->EventTeleport(1, -8394.730469, 1485.658447, 21.038563);
			 }
			 break;
		case 36: // Ahn'Qirai 40
			 {
                             Plr->EventTeleport(1, -8247.316406, 1970.156860, 129.071472);
			}
			 break;
		case 37: // Molten Core
			 {
              Plr->EventTeleport(0, -7515.409668, -1045.369629, 182.301208);

			 }
			 break;
        case 38: // Onyxia
				 {
			   Plr->EventTeleport(1, -4708.491699, -3727.672363, 54.535076);

				 }
				 break;
		case 39: // Naxxramas
				 {
				Plr->EventTeleport(0, 3132.915283, -3731.012939, 138.658371);

				 }
				 break;
		case 40: //Scholomance
				{ 
					Plr->EventTeleport(0, 1267.468628, -2556.651367, 94.127983);
				}
				break;
		case 41: //Stratholme
				{ 
					Plr->EventTeleport(0, 3359.111572, -3380.8444238, 144.781860);
				}break;
            case 42: // Black Rock Spire
				{ 
					Plr->EventTeleport(0, -7527.129883, -1224.997437, 285.733002);
				}break;
			case 43: // Kharazan
				{ 
				     Plr->EventTeleport(0, -11122.913086, -2014.498779, 47.079350);

				}break;
			case 44: // Caverns of Times
				{ 
					Plr->EventTeleport(1, -8519.718750, -4297.542480, -208.441376);
				}break;


		case 50: // Outland Instances
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
				
		case 51: // Hellfire Ramparts
				{ 
					Plr->EventTeleport(530, -360.670990, 3071.899902, -15.097700);
				}break;
		case 52: // The Blood Furnace
				{ 
					Plr->EventTeleport(530, -303.506012, 3164.820068, 31.742500);
				}break;
		case 53: // The Shattered Halls
				{ 
					Plr->EventTeleport(530, -311.083527, 3083.291748, -3.745923);
				}break;
		case 54: // The Underbog
				{ 
					Plr->EventTeleport(530, 777.088989, 6763.450195, -72.062561);
				}break;
		case 55: // The Slave Pens
				{ 
					Plr->EventTeleport(530, 719.507996, 6999.339844, -73.074303);
				}break;
		case 56: // The Steamvault
				{ 
					Plr->EventTeleport(530, 816.590027, 6934.669922, -80.544601);
				}break;
		case 57: // Mana-Tombs
				{ 
					Plr->EventTeleport(530, -3079.810059, 4943.040039, -101.046997);
				}break;
		case 58: // Auchenai Crypts
				{ 
					Plr->EventTeleport(530, -3361.959961, 5225.770020, -101.047997);
				}break;
		case 59: // Sethekk Halls
				{ 
					Plr->EventTeleport(530, -3362.219971, 4660.410156, -101.049004 );
				}break;
		case 60: // Shadow Labyrinth
				{ 
					Plr->EventTeleport(530, -3645.060059, 4943.620117, -101.047997);
				}break;
		case 61: // The Mechanar
				{ 
					Plr->EventTeleport(530, 2862.409912, 1546.089966, 252.158691);
				}break;
		case 62: // The Botanica
				{ 
					Plr->EventTeleport(530, 3413.649902, 1483.319946, 182.837997);
				}break;
		case 63: // The Arcatraz
				{ 
					Plr->EventTeleport(530, 3311.598145, 1332.745117, 505.557251);
				}break;


		case 64: // Outland Raids
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

		case 65: // Magtheridon's Lair
				{
					Plr->EventTeleport(530, -313.678986, 3088.350098, -116.501999);
				}break;
		case 66: // Serpentshrine Cavern
				{ 
					Plr->EventTeleport(530, 830.542908, 6865.445801, -63.785503);
				}break;
		case 67: // Gruul's Lair
				{ 
					Plr->EventTeleport(530, 3549.424072, 5179.854004, -4.430779);
				}break;
		case 68: // The Eye
				{ 
					Plr->EventTeleport(530, 3087.310059, 1373.790039, 184.643005);
				}break;
		case 69: // Black Temple
				{
					 Plr->EventTeleport(530, -3609.739990, 328.252014, 37.307701 );

				}break;
				
		
				
				case 80: //SUB MENU
				{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(5, "Eastern Kingdoms", 81);
						Menu->AddItem(5, "Kalimdor", 82);
						Menu->AddItem(5, "Outland", 3);
                		
               			Menu->SendTo(Plr);
				}
				break;

				case 81: // EASTERN KINGDOM
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
                        Menu->AddItem(5, "Wetlands", 78);
                        Menu->AddItem(5, "Dun Morogh", 79);
                        Menu->AddItem(5, "Loch Modan", 100);
                        Menu->AddItem(5, "--> Second Page -->", 151);
                           Menu->SendTo(Plr);
                }
                break;

                case 151:
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                        Menu->AddItem(5, "Badlands", 101);
                        Menu->AddItem(5, "Blackrock Mountain", 102);
                        Menu->AddItem(5, "Redridge Mountain", 103);
                        Menu->AddItem(5, "Elwynn Forest", 104);
                        Menu->AddItem(5, "Duskwood", 105);
                        Menu->AddItem(5, "Westfall", 106);
                        Menu->AddItem(5, "Swamp of Sorrows", 107);
                        Menu->AddItem(5, "The Blasted Lands", 108);
                        Menu->AddItem(5, "Deadwind Pass", 109);
                        Menu->AddItem(5, "Stranglethorn Vale", 110);
                		
               			Menu->SendTo(Plr);
				}
				break;

				case 82: // KALIMDOR
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
                        Menu->AddItem(5, "--> Second Page -->", 152);

                        Menu->SendTo(Plr);
                }
                break;

                case 152:
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                        Menu->AddItem(5, "Mulgore", 120);
                        Menu->AddItem(5, "Desolace", 121);
                        Menu->AddItem(5, "Dustwallow Marsh", 122);
                        Menu->AddItem(5, "Feralas", 123);
                        Menu->AddItem(5, "Thousand Needles", 124);
                        Menu->AddItem(5, "Tanaris Desert", 125);
                        Menu->AddItem(5, "Un'Goro Crater", 126);
                        Menu->AddItem(5, "Silithus", 127);
                        
                        Menu->SendTo(Plr);
                }
                break;

// EASTERN KINGDOMS [case] //
				case 70: // WesternPlaguelands
				{
					Plr->EventTeleport( 0, 1855, -1569, 61);
				}break;

				case 71: // EasternPlaguelands 
				{
					Plr->EventTeleport( 0, 2278, -5311, 89);
				}break;

				case 72: // TristfallGlades
				{
					Plr->EventTeleport( 0, 2032, -432, 37);
				}break;

				case 73: // AlteracMountains
				{
					Plr->EventTeleport( 0, 552, -275, 152);
				}break;

				case 74: // Silverpine Forest
				{
					Plr->EventTeleport( 0, -126, 815, 68);
				}break;

				case 75: // Hillsbrad
				{
					Plr->EventTeleport( 0, -502, 91, 61);
				}break;

				case 76: // TheHinterlands
				{
					Plr->EventTeleport( 0, -678, -4018, 240);
				}break;

				case 77: // ArathiHighlands
				{
					Plr->EventTeleport( 0, -797, -2068, 35);
				}break;

				case 78: // Wetlands
				{
					Plr->EventTeleport( 0, -3256, -2718, 11);
				}break;

				case 79: // Dunmorogh
				{
					Plr->EventTeleport( 0, -5826, -1586, 366);
				}break;

				case 100: // Lochmodan
				{
					Plr->EventTeleport( 0, -4771, -3329, 347);
				}break;

				case 101: // Badlands
				{
					Plr->EventTeleport( 0, -7027, -3330, 243);
				}break;

				case 102: // Blackrockmountain
				{
					Plr->EventTeleport( 0, -7317, -1072, 279);
				}break;

				case 103: // Redridgemountain
				{
					Plr->EventTeleport( 0, -9168, -2726, 92);
				}break;

				case 104: // ElwynnForest
				{
					Plr->EventTeleport( 0, -9325, -1038, 67);
				}break;

				case 105: // Duskwood
				{
					Plr->EventTeleport( 0, -10694, -884, 52);
				}break;

				case 106: // Westfall
				{
					Plr->EventTeleport( 0, -11018, 1513, 45);
				}break;

				case 107: // SwampofSorrows
				{
					Plr->EventTeleport( 0, -10429, -3828, -29);
				}break;

				case 108: // BlastedLands
				{
					Plr->EventTeleport( 0, -11853, -3197, -25);
				}break;

				case 109: // DeadwindPass
				{
					Plr->EventTeleport( 0, -10435, -1809, 101);
				}break;

				case 110: // Stranglethornvale
				{
					Plr->EventTeleport( 0, -13382, 2, 23);
				}break;



// KALIMDOR [case] //

				case 111: // Moonglade
				{
					Plr->EventTeleport( 1, 7978, -2501, 490);
				}break;

				case 112: // winterspring
				{
					Plr->EventTeleport( 1, 6721, -4659, 722);
				}break;

				case 113: // felwood
				{
					Plr->EventTeleport( 1, 4878, -614, 362);
				}break;

				case 114: // darkshore
				{
					Plr->EventTeleport( 1, 4565, 438, 34);
				}break;

				case 115: // azshara
				{
					Plr->EventTeleport( 1, 2717, -5968, 108);
				}break;

				case 116: // ashenvale
				{
					Plr->EventTeleport( 1, 3469, 847, 7);
				}break;

				case 117: // Stonetalon
				{
					Plr->EventTeleport( 1, 898, 922, 128);
				}break;

				case 118: // TheBarrens
				{
					Plr->EventTeleport( 1, -1330, -3120, 93);
				}break;

				case 119: // Durotar
				{
					Plr->EventTeleport( 1, 242, -5151, 3);
				}break;

				case 120: // Mulgore
				{
					Plr->EventTeleport( 1, -2326, -367, -6);
				}break;

				case 121: // Desolace
				{
					Plr->EventTeleport( 1, -939, 1091, 95);
				}break;

				case 122: // Dustwallow
				{
					Plr->EventTeleport( 1, -3719, -2530, 71);
				}break;

				case 123: // Feralas
				{
					Plr->EventTeleport( 1, -4508, 2041, 53);
				}break;

				case 124: // ThousandNeedles
				{
					Plr->EventTeleport( 1, -4619, -1850, 88);
				}break;

				case 125: // Tanaris
				{
					Plr->EventTeleport( 1, -7373, -2950, 12);
				}break;

				case 126: // Ungoro
				{
					Plr->EventTeleport( 1, -6186, -1106, -215);
				}break;

				case 127: // Silithus
				{
					Plr->EventTeleport( 1, -6824, 821, 51);
				}break;

case 22222: // Northrend Locations 
			    {
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(5, "Borean Tundra", 22223);
				Menu->AddItem(5, "Crystalsong Forest", 22224);
				Menu->AddItem(5, "Dalaran (City)", 22225);
				Menu->AddItem(5, "Dragonblight", 22226);
                Menu->AddItem(5, "Grizzly Hills", 22227);
				Menu->AddItem(5, "Howling Fjord", 22228);
				Menu->AddItem(5, "Icecrown", 22229);
				Menu->AddItem(5, "Sholazar Basin", 22230);
				Menu->AddItem(5, "The Storm Peaks", 22231);
				Menu->AddItem(5, "Zul'Dark", 22232);
				Menu->AddItem(5, "DK Start Zone", 22233);
                
                Menu->SendTo(Plr);
				}
				break;

// Northrend Locations [case] //

				case 22223: // Borean Tundra
				{
					Plr->EventTeleport( 571, 2087.0109, 6508.6171, 1.4727);
				}break;

				case 22224: // Crystalsong Forest
				{
					Plr->EventTeleport( 571, 5434.8281, -1022.4812, 175.0125);
				}break;

				case 22225: // Dalaran (City)
				{
					Plr->EventTeleport( 571, 5811.4067, 647.7883, 647.4152);
				}break;

				case 22226: // Dragonblight
				{
					Plr->EventTeleport( 571, 3511.6850, 2841.8454, 36.7473);
				}break;

				case 22227: // Grizzly Hills
				{
					Plr->EventTeleport( 571, 3346.2551, -4486.8173, 259.2319);
				}break;

				case 22228: // Howling Fjord
				{
					Plr->EventTeleport( 571, 2195.3654, -4526.7729, 216.7943);
				}break;

				case 22229: // Icecrown
				{
					Plr->EventTeleport( 571, 6729.2387, 2510.4931, 427.7868);
				}break;

				case 22230: // Sholazar Basin
				{
					Plr->EventTeleport( 571, 5572.933594, 5533.583496, -96.344063);
				}break;

				case 22231: // The Storm Peaks
				{
					Plr->EventTeleport( 571, 6196.4174, -776.7462, 402.3688);
				}break;

				case 22232: // Zul'Dark
				{
					Plr->EventTeleport( 571, 5443.4326, -1259.7487, 248.7494);
				}break;

				case 22233: // DK Start Zone
				{
					Plr->EventTeleport( 609, 2355.7048, -5662.7075, 426.0274);
				}break;

		case 95: // Bind Position
            {
                Plr->GetSession()->SendInnkeeperBind(pCreature);

                
                }break;
                
    
        case 96: // Buff me up
		{
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		pCreature->CastSpell(Plr, 15366, 0);
		pCreature->CastSpell(Plr, 33077, 0);
		pCreature->CastSpell(Plr, 33078, 0);
		pCreature->CastSpell(Plr, 33079, 0);
		pCreature->CastSpell(Plr, 33080, 0);
		pCreature->CastSpell(Plr, 33081, 0);
		pCreature->CastSpell(Plr, 33082, 0);
		pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "By all that is wrong in this world, I bless you." );
		
        Menu->SendTo(Plr);
		}break;
				
				
				
		case 97: // REMOVE RESSURECTION SICKNESS
		{
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
        Plr->addSpell(15007);
		Plr->removeSpell(15007,0,0,0);
		pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You have been cured of that dreaded sickness." );
		
        Menu->SendTo(Plr);
		}break;

                
                
		case 99: //main menu
		{
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(0, "Horde Cities", 1);}else{Menu->AddItem(1, "Alliance Cities", 2);}
		if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
		{Menu->AddItem(9, "Horde Mall", 1000);}else{Menu->AddItem(9, "Alliance Mall", 1001);}
		Menu->AddItem(2, "Global Locations", 80);				
		Menu->AddItem(3, "Azeroth Instances", 30);
		Menu->AddItem(4, "Outland Instances", 50);
		Menu->AddItem(5, "Shattrath", 20);
		Menu->AddItem(10, "Isle of Quel'Danas", 22);
		Menu->AddItem(11, "Northrend Locations", 22222);
		Menu->AddItem(6, "Gurubashi Arena", 21);
		Menu->AddItem(8, "Buff me up, baby!", 96);
		Menu->AddItem(7, "Make This Place Your Home", 95);		
		Menu->AddItem(9, "Remove Resurrection Sickness", 97);
		Menu->SendTo(Plr);
		}break;
			

		case 1000: //Horde Mall
			{
				Plr->EventTeleport(1, 7444.66, -1690.38, 194.64);
			}break;

		case 1001: //Alliance Mall
			{
				Plr->EventTeleport(0, -8638.7, -553.833, 145.207);
			}break;

}
};

void GlobalNPC::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupGlobalNPC(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new GlobalNPC();
    mgr->register_gossip_script(99000055, gs);
}

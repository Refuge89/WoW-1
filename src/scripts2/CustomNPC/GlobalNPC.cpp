//ArcEmu Modded Team :D
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
            {Menu->AddItem(6, "|CFF8B0000Horde Cities", 1);}else{Menu->AddItem(6, "|CFF191970Alliance Cities", 2);}
            Menu->AddItem(6, "|CFF191970Mall |CFF8B0000- NO PVP", 1000);
            Menu->AddItem(6, "|CFF191970Leveling |CFF8B0000Zone", 4040);
            Menu->AddItem(5, "|cFF006400Azeroth Instances", 30);
            Menu->AddItem(5, "|cFFA52A2AOutland Instances", 50);
            Menu->AddItem(5, "|cFFFFFAFANorthrend Instances", 500);
            Menu->AddItem(5, "|cFF800080Global Locations", 80);
            Menu->AddItem(5, "|cFF9370DBIsle of Quel'Danas", 200);
            Menu->AddItem(2, "|cFF008B8BShattrath", 20);
            Menu->AddItem(2, "|cFFC0C0C0Dalaran", 550);
            Menu->AddItem(8, "|cFF8B0000Gurubsahi Arena", 21);
			Menu->AddItem(8, "|cFF8B0000Extra Stuff", 393);
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
                    
        case 1:     // Horde Cities
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(5, "Silvermoon", 4);
            Menu->AddItem(5, "Orgrimmar", 5);
            Menu->AddItem(5, "Thunder Bluff", 6);
            Menu->AddItem(5, "Undercity", 7);
            Menu->AddItem(1, "|CFF800080Back", 99);
            
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
            Menu->AddItem(1, "|CFF800080Back", 99);

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
            Menu->AddItem(1, "|CFF800080Back", 99);

            Menu->SendTo(Plr);
            }
            break;

        
        case 4040://Leveling Zone
            {
                Plr->EventTeleport(1, 4617.614258, -3851.083984, 944.031799);
            }
            break;
            
        case 550://Dalaran
            {
                Plr->EventTeleport(571, 5804.700195, 633.228027, 647.729980);
            }
            break;

        case 5://Orgrimmar
            {
                Plr->EventTeleport(1, 1371.068970, -4370.801758, 26.052483);
            }
            break;

        case 6://ThunderBluff
            {
                Plr->EventTeleport(1, -1274.246216, 121.371109, 131.207657);
            }
            break;

        case 7://Undercity
            {
                Plr->EventTeleport(0, 2050.203125, 285.650604, 56.994549);
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

        case 1012: //racetrack
            {
                Plr->EventTeleport(1, -5647.770020, -2823.115753, 91.564011);

            }
            break;

        case 1234: //metal maze
            {
                Plr->EventTeleport(1, -6515.910156, -4291.020020, 87.371300);

            }



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

        case 20: // Shattrath
             {
                Plr->EventTeleport(530, -1887.510010, 5359.379883, -12.427300);

             }
             break;

        case 200: // Isle of Quel'Danas
             {
                Plr->EventTeleport(530, 13008, -6912.490, 9.583710);

             }
             break;

        case 203: // Snow Event
             {
                Plr->EventTeleport(1, 7754, -4838, 696);

             }
             break;

        case 204: // stairway to hell
             {
                Plr->EventTeleport(0, -10916.056641, 1508.490356, 50.009552);

             }
             break;

        case 206: // Mad Cow Event
             {
                Plr->EventTeleport(1, 7326.164551, -1535.058105, 161);

             }
             break;

        case 21: // Gurubsahi Arena
             {
                Plr->EventTeleport(0, -13271.959961, 149.105515, 34.464458);

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
            Menu->AddItem(1, "|CFF800080Back", 99);
                
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
                Plr->EventTeleport(409, 1089.6, -470.19, -106.41);
            }
            break;
        case 38: // Onyxia
            {
                Plr->EventTeleport(249, 30.0, -64.0, -5.0);
            }
            break;
        case 39: // Naxxramas
            {
                Plr->EventTeleport(533, 3006.06, -3436.72, 293.891);
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
            }
            break;
        case 42: // Black Rock Spire
            { 
                Plr->EventTeleport(0, -7527.129883, -1224.997437, 285.733002);
            }
            break;
        case 43: // Kharazan
            {
                Plr->EventTeleport(532, -11087.3, -1977.47, 49.6135);
            }
            break;
        case 44: // Caverns of Times
            { 
                Plr->EventTeleport(1, -8519.718750, -4297.542480, -208.441376);
            }
            break;

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
            Menu->AddItem(1, "|CFF800080Back", 99);
            
            Menu->SendTo(Plr);
            }
            break;
                
        case 51: // Hellfire Ramparts
            { 
                Plr->EventTeleport(530, -360.670990, 3071.899902, -15.097700);
            }
            break;
        case 52: // The Blood Furnace
            { 
                Plr->EventTeleport(530, -303.506012, 3164.820068, 31.742500);
            }
            break;
        case 53: // The Shattered Halls
            { 
                Plr->EventTeleport(530, -311.083527, 3083.291748, -3.745923);
            }
            break;
        case 54: // The Underbog
            { 
                Plr->EventTeleport(530, 777.088989, 6763.450195, -72.062561);
            }
            break;
        case 55: // The Slave Pens
            { 
                Plr->EventTeleport(530, 719.507996, 6999.339844, -73.074303);
            }
            break;
        case 56: // The Steamvault
            { 
                Plr->EventTeleport(530, 816.590027, 6934.669922, -80.544601);
            }
            break;
        case 57: // Mana-Tombs
            { 
                Plr->EventTeleport(530, -3079.810059, 4943.040039, -101.046997);
            }
            break;
        case 58: // Auchenai Crypts
            { 
                Plr->EventTeleport(530, -3361.959961, 5225.770020, -101.047997);
            }
            break;
        case 59: // Sethekk Halls
            { 
                Plr->EventTeleport(530, -3362.219971, 4660.410156, -101.049004 );
            }
            break;
        case 60: // Shadow Labyrinth
            { 
                Plr->EventTeleport(530, -3645.060059, 4943.620117, -101.047997);
            }
            break;
        case 61: // The Mechanar
            { 
                Plr->EventTeleport(530, 2862.409912, 1546.089966, 252.158691);
            }
            break;
        case 62: // The Botanica
            { 
                Plr->EventTeleport(530, 3413.649902, 1483.319946, 182.837997);
            }
            break;
        case 63: // The Arcatraz
            { 
                Plr->EventTeleport(530, 3311.598145, 1332.745117, 505.557251);
            }
            break;

        case 64: // Outland Raids
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(5, "Magtheridon's Lair", 65);
            Menu->AddItem(5, "Serpentshrine Cavern", 66);
            Menu->AddItem(5, "Gruul's Lair", 67);
            Menu->AddItem(5, "The Eye", 68);
            Menu->AddItem(5, "Black Temple", 69);
            Menu->AddItem(1, "|CFF800080Back", 50);

            Menu->SendTo(Plr);
            }
            break;

        case 65: // Magtheridon's Lair
            {
            Plr->EventTeleport(530, -313.678986, 3088.350098, -116.501999);
            }
            break;
        case 66: // Serpentshrine Cavern
            { 
                Plr->EventTeleport(530, 830.542908, 6865.445801, -63.785503);
            }
            break;
        case 67: // Gruul's Lair
            { 
                Plr->EventTeleport(530, 3549.424072, 5179.854004, -4.430779);
            }
            break;
        case 68: // The Eye
            { 
                Plr->EventTeleport(530, 3087.310059, 1373.790039, 184.643005);
            }
            break;
        case 69: // Black Temple
            {
                Plr->EventTeleport(564, 97.0894, 1001.96, -86.8798 );
            }
            break;
            
        case 80: //SUB MENU
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(5, "Eastern Kingdoms", 81);
            Menu->AddItem(5, "Kalimdor", 82);
            Menu->AddItem(5, "Outland", 3);
            Menu->AddItem(5, "Northrend", 700);
            Menu->AddItem(1, "|CFF800080Back", 99);
                       
            Menu->SendTo(Plr);
            }
            break;
            
        case 700: // Northrend Locations
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(5, "Borean Tundra", 501);
            Menu->AddItem(5, "Crystalsong Forest", 503);
            Menu->AddItem(5, "Grizzly Hills", 504);
            Menu->AddItem(5, "Howling Fjord", 505);
            Menu->AddItem(5, "Icecrown Glacier", 506);
            Menu->AddItem(5, "Sholazar Basin", 507);
            Menu->AddItem(5, "The Dragonblight", 508);
            Menu->AddItem(5, "The Storm Peaks", 509);
            Menu->AddItem(5, "Wintergrasp", 510);
            Menu->AddItem(5, "Zul'Drak", 511);
            Menu->AddItem(1, "|CFF800080Back", 80);

            Menu->SendTo(Plr);
            }
            break;
            
        case 500: // Northrend instances
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(5, "The Nexus", 512);
            Menu->AddItem(5, "Utgarde Keep", 513);
            Menu->AddItem(5, "Azjol Nerub", 514);
            Menu->AddItem(5, "Drak'tharon Keep", 515);
            Menu->AddItem(5, "Violet Hold", 516);
            Menu->AddItem(5, "Ulduar", 517);
            Menu->AddItem(5, "Caverns of Time", 518);
            Menu->AddItem(5, "Naxxramas", 519);
            Menu->AddItem(1, "|CFF800080Back", 99);

            Menu->SendTo(Plr);
            }
            break;

        case 81: // EASTERN KINGDOM
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(1, "|CFF800080Back", 80);
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
            Menu->AddItem(5, "Badlands", 101);
            Menu->AddItem(5, "Blackrock Mountain", 102);
            Menu->AddItem(1, "|CFF000080Next Page", 1005);
                     
            Menu->SendTo(Plr);
            }
            break;

        case 1005: //PAGE TWO EASTERN KINGDOM
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(5, "Redridge Mountain", 103);
            Menu->AddItem(5, "Elwynn Forest", 104);
            Menu->AddItem(5, "Duskwood", 105);
            Menu->AddItem(5, "Westfall", 106);
            Menu->AddItem(5, "Swamp of Sorrows", 107);
            Menu->AddItem(5, "The Blasted Lands", 108);
            Menu->AddItem(5, "Deadwind Pass", 109);
            Menu->AddItem(5, "Stranglethorn Vale", 110);
            Menu->AddItem(1, "|CFF800080Back", 81);

            Menu->SendTo(Plr);
            }
            break;

        case 82: // KALIMDOR
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(1, "|CFF800080Back", 80);
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
            Menu->AddItem(5, "Desolace", 121);
            Menu->AddItem(5, "Dustwallow Marsh", 122);
            Menu->AddItem(5, "Feralas", 123);
            Menu->AddItem(1, "|CFF000080Next Page", 1006);
                        
            Menu->SendTo(Plr);
            }
            break;

        case 1006: //PAGE TWO KALIMDOR
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(5, "Thousand Needles", 124);
            Menu->AddItem(5, "Tanaris Desert", 125);
            Menu->AddItem(5, "Un'Goro Crater", 126);
            Menu->AddItem(5, "Silithus", 127);
            Menu->AddItem(1, "|CFF800080Back", 82);

               Menu->SendTo(Plr);
            }
            break;
		case 393: //Extra Stuff
			{
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Menu->AddItem(10, "|CFF006400Buff me up!", 96); 
            Menu->AddItem(10, "|CFF006400Remove Resurrection Sickness", 97);
            Menu->AddItem(11, "|CFF008B8BMake This Place Your Home", 95);
            Menu->AddItem(5, "|cffff0000Disconnect Me Now!|r", 223);
            Menu->AddItem(1, "|CFF800080Back", 99);

               Menu->SendTo(Plr);
            }
            break;
		case 223: // Disconnect
            {
                Plr->GetGUID();
				Plr->SaveToDB(1);    // Saves the character before the logout
				Plr->SoftDisconnect();   // Free Disconnect Logout
            }
            break;
// EASTERN KINGDOMS [case] //

        case 70: // WesternPlaguelands
            {
                Plr->EventTeleport( 0, 1855, -1569, 61);
            }
            break;

        case 71: // EasternPlaguelands 
            {
                Plr->EventTeleport( 0, 2278, -5311, 89);
            }
            break;

        case 72: // TristfallGlades
            {
                Plr->EventTeleport( 0, 2032, -432, 37);
            }
            break;

        case 73: // AlteracMountains
            {
                Plr->EventTeleport( 0, 552, -275, 152);
            }
            break;

        case 74: // Silverpine Forest
            {
                Plr->EventTeleport( 0, -126, 815, 68);
            }
            break;

        case 75: // Hillsbrad
            {
                Plr->EventTeleport( 0, -502, 91, 61);
            }
            break;

        case 76: // TheHinterlands
            {
                Plr->EventTeleport( 0, -678, -4018, 240);
            }
            break;

        case 77: // ArathiHighlands
            {
                Plr->EventTeleport( 0, -797, -2068, 35);
            }
            break;

        case 78: // Wetlands
            {
                Plr->EventTeleport( 0, -3256, -2718, 11);
            }
            break;

        case 79: // Dunmorogh
            {
                Plr->EventTeleport( 0, -5826, -1586, 366);
            }
            break;

        case 100: // Lochmodan
            {
                Plr->EventTeleport( 0, -4771, -3329, 347);
            }
            break;

        case 101: // Badlands
            {
                Plr->EventTeleport( 0, -7027, -3330, 243);
            }
            break;

        case 102: // Blackrockmountain
            {
                Plr->EventTeleport( 0, -7317, -1072, 279);
            }
            break;

        case 103: // Redridgemountain
            {
                Plr->EventTeleport( 0, -9168, -2726, 92);
            }
            break;

        case 104: // ElwynnForest
            {
                Plr->EventTeleport( 0, -9325, -1038, 67);
            }
            break;

        case 105: // Duskwood
            {
                Plr->EventTeleport( 0, -10694, -884, 52);
            }
            break;

        case 106: // Westfall
            {
                Plr->EventTeleport( 0, -11018, 1513, 45);
            }
            break;

        case 107: // SwampofSorrows
            {
                Plr->EventTeleport( 0, -10429, -3828, -29);
            }
            break;

        case 108: // BlastedLands
            {
                Plr->EventTeleport( 0, -11853, -3197, -25);
            }
            break;

        case 109: // DeadwindPass
            {
                Plr->EventTeleport( 0, -10435, -1809, 101);
            }
            break;

        case 110: // Stranglethornvale
            {
                Plr->EventTeleport( 0, -13382, 2, 23);
            }
            break;



// KALIMDOR [case] //

        case 111: // Moonglade
            {
                Plr->EventTeleport( 1, 7978, -2501, 490);
            }
            break;

        case 112: // winterspring
            {
                Plr->EventTeleport( 1, 6721, -4659, 722);
            }
            break;

        case 113: // felwood
            {
                Plr->EventTeleport( 1, 4878, -614, 362);
            }
            break;

        case 114: // darkshore
            {
                Plr->EventTeleport( 1, 4565, 438, 34);
            }
            break;

        case 115: // azshara
            {
                Plr->EventTeleport( 1, 2717, -5968, 108);
            }
            break;

        case 116: // ashenvale
            {
                Plr->EventTeleport( 1, 3469, 847, 7);
            }
            break;

        case 117: // Stonetalon
            {
                Plr->EventTeleport( 1, 898, 922, 128);
            }
            break;

        case 118: // TheBarrens
            {
                Plr->EventTeleport( 1, -1330, -3120, 93);
            }
            break;

        case 119: // Durotar
            {
                Plr->EventTeleport( 1, 242, -5151, 3);
            }
            break;

        case 120: // Mulgore
            {
                Plr->EventTeleport( 1, -2326, -367, -6);
            }
            break;
            
        case 121: // Desolace
            {
                Plr->EventTeleport( 1, -939, 1091, 95);
            }
            break;

        case 122: // Dustwallow
            {
                Plr->EventTeleport( 1, -3719, -2530, 71);
            }
            break;

        case 123: // Feralas
            {
                Plr->EventTeleport( 1, -4508, 2041, 53);
            }
            break;

        case 124: // ThousandNeedles
            {
                Plr->EventTeleport( 1, -4619, -1850, 88);
            }
            break;

        case 125: // Tanaris
            {
                Plr->EventTeleport( 1, -7373, -2950, 12);
            }
            break;

        case 126: // Ungoro
            {
                Plr->EventTeleport( 1, -6186, -1106, -215);
            }
            break;

        case 127: // Silithus
            {
                Plr->EventTeleport( 1, -6824, 821, 51);
            }
            break;

        case 95: // Bind Position
            {
                Plr->GetSession()->SendInnkeeperBind(pCreature);
            }
            break;
    
        case 96: // Buff me up
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            pCreature->CastSpell(Plr, 15366, 0);
			pCreature->CastSpell(Plr, 33079, 0);
			pCreature->CastSpell(Plr, 33077, 0);
			pCreature->CastSpell(Plr, 33080, 0);
			pCreature->CastSpell(Plr, 33081, 0);
			pCreature->CastSpell(Plr, 33078, 0);
			pCreature->CastSpell(Plr, 33082, 0);
			pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "By all that is wrong in this world, I bless you." );
        
            Menu->SendTo(Plr);
            }
            break;
                
                
        case 97: // REMOVE RESSURECTION SICKNESS
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            Plr->addSpell(15007);
            Plr->removeSpell(15007,0,0,0);
            pCreature->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, "You have been cured of that dreaded sickness." );
        
            Menu->SendTo(Plr);
            }
            break;

// NORTHREND LOCATIONS [case] //

        case 501: // Borean Tundra
            {
                Plr->EventTeleport( 571, 3249.02, 5688.4, 50.2965);
            }
            break;

        case 503: // Crystalsong Forest
            {
                Plr->EventTeleport( 571, 5678.1, -115.016, 178.964);
            }
            break;

        case 504: // Grizzly Hills
            {
                Plr->EventTeleport( 571, 3753.79, -3851.63, 182.325);
            }
            break;

        case 505: // Howling Fjord
            {
                Plr->EventTeleport( 571, 592, -5095, 6);
            }
            break;

        case 506: // Icecrown Glacier
            {
                Plr->EventTeleport( 571, 7295.7, 1380.01, 310.741);
            }
            break;

        case 507: // Sholazar Basin
            {
                Plr->EventTeleport( 571, 5498.23, 4869.99, -196.17);
            }
            break;

        case 508: // The Dragonblight
            {
                Plr->EventTeleport( 571, 2981.363, 291.109, 85);
            }
            break;

        case 509: // The Storm Peaks
            {
                Plr->EventTeleport( 571, 7301.21, -1393.86, 907.589);
            }
            break;

        case 510: // Wintergrasp
            {
                Plr->EventTeleport( 571, 5213.69, 2820.99, 409.617);
            }
            break;

        case 511: // Zul'Drak
            {
                Plr->EventTeleport( 571, 5537.45, -3186.92, 352.266);
            }
            break;

        case 512: // The Nexus
            {
                Plr->EventTeleport( 571, 3790.109619, 6932.677734, 104.194321);
            }
            break;

        case 513: // Utgarde Keep
            {
                Plr->EventTeleport( 571, 1268.807861, -4855.125000, 215.763794);
            }
            break;

        case 514: // Azjol Nerub
            {
                Plr->EventTeleport( 571, 3710.987549, 2141.171875, 54.617020);
            }
            break;

        case 515: // Drak'tharon Keep
            {
                Plr->EventTeleport( 571, 4765.397461, -2045.016113, 229.994766);
            }
            break;

        case 516: // Violet Hold
            {
                Plr->EventTeleport( 571, 5724.774902, 541.784363, 653.525160);
            }
            break;

        case 517: // Ulduar
            {
                Plr->EventTeleport( 571, 8951.563477, -1270.476318, 1025.500244);
            }
            break;

        case 518: // Caverns of Time
            {
                Plr->EventTeleport( 1, -8189.310059, -4713.979980, 23.503336);
            }
            break;

        case 519: // Naxxramas
            {
                Plr->EventTeleport( 571, 3669.469971, -1261.760010, 245.527603);
            }
            break;
        case 99: //main menu
            {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
            if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
            {Menu->AddItem(6, "|CFF8B0000Horde Cities", 1);}else{Menu->AddItem(6, "|CFF191970Alliance Cities", 2);}
            Menu->AddItem(6, "|CFF191970Mall |CFF8B0000- NO PVP", 1000);
            Menu->AddItem(6, "|CFF191970Leveling |CFF8B0000Zone", 4040);
            Menu->AddItem(5, "|cFF006400Azeroth Instances", 30);
            Menu->AddItem(5, "|cFFA52A2AOutland Instances", 50);
            Menu->AddItem(5, "|cFFFFFAFANorthrend Instances", 500);
            Menu->AddItem(5, "|cFF800080Global Locations", 80);
            Menu->AddItem(5, "|cFF9370DBIsle of Quel'Danas", 200);
            Menu->AddItem(2, "|cFF008B8BShattrath", 20);
            Menu->AddItem(2, "|cFFC0C0C0Dalaran", 550);
            Menu->AddItem(8, "|cFF8B0000Gurubsahi Arena", 21);
			Menu->AddItem(8, "|cFF8B0000Extra Stuff", 393);    
            Menu->SendTo(Plr);
            }
            break;

        case 1000: // Mall
            {
                Plr->EventTeleport(1, -8502.6, 2021.9, 106);
            }
            break;

        
}
}

void GlobalNPC::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupGlobalNPC(ScriptMgr * mgr)
{
    GossipScript * gs = (GossipScript*) new GlobalNPC();
    mgr->register_gossip_script(90000005, gs);
}
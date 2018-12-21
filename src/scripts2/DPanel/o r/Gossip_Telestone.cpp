#include "StdAfx.h"
       #include "Setup.h"
#include "Pets.h"
          //---------Defines-----------//
              #define DPanelID 6948   //

              #define COST 0      // 100 Gold.
          //                           //
          //                           //

           #ifdef WIN32
         #pragma warning(disable:4305)
        #endif

         class SCRIPT_DECL DPanel : public GossipScript
		  {
		   public:

	       void GossipHello(Object * pObject, Player* Plr , bool AutoSend);
            void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
             void GossipEnd(Object* pObject, Player* Plr);
            void Destroy()

		  {

            delete this;

          }
			/*struct CodeBoxes;*/
        };

/*struct DPanel::CodeBoxes
{
    const char * OptionText; //String for gossip to display
    uint32 ItemId;            //Item Id for reward
};*/

		 void DPanel::GossipHello(Object* pObject, Player* Plr, bool AutoSend)
		 {
			 if(Plr->CombatStatus.IsInCombat())
			 {
				 Plr->BroadcastMessage("You're in Combat, sorry!.\n When you are in combat, you can't use the Control Panel.");

				   return;
			 }

		     GossipMenu *Menu;
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);

			//Menu->AddItem(8, "[Thanks for donating, enjoy this D Panel.]");
             if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
			  {Menu->AddItem(6, "|cff00ff00|TInterface\\icons\\inv_misc_rune_06:24|t|r Horde Teleports.", 1);}else{Menu->AddItem(0, "|cff00ff00|TInterface\\icons\\inv_misc_rune_06:24|t|r Alliance Teleports.", 2);}
			    Menu->AddItem(0, "|cff00ff00|TInterface\\icons\\ability_parry:24|t|r PvP.", 3);
				 Menu->AddItem(7, "|cff00ff00|TInterface\\icons\\spell_holy_holyguidance:24|t|r Show Online Players, please.", 4);
			      Menu->AddItem(8, "|cff00ff00|TInterface\\icons\\achievement_zone_kalimdor_01:24|t|r Exploring.", 5);
				   Menu->AddItem(0, "|cff00ff00|TInterface\\icons\\spell_holy_prayerofmendingtga:24|t|r Server Options.", 7);
				   Menu->AddItem(80, "|cff800080Scale Menu|r", 205);
					if(Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) < COST)
					{
				       Plr->BroadcastMessage("You don't have enough gold to teleport to another player.");
		               return;
				    }
					else
					{
					  Menu->AddItem(0, "Port to a Player", 34, 1);

					 if(AutoSend)
                      Menu->SendTo(Plr);
					}

		 }

		 void DPanel::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
		 {
			 GossipMenu *Menu;

			/* CodeBoxes CodeBoxes[2];
        int codes = 2;//must be equal to integer inside brackets
        //Define Code Options 1- ect.
        CodeBoxes[1].OptionText = "Test1";
        CodeBoxes[1].ItemId = 22253;
        CodeBoxes[2].OptionText = "Test2";
        CodeBoxes[2].ItemId = 4325;*/

			 switch(IntId)

			 {
				 case 1: // Horde Ports
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
					 Menu->AddItem(0, "|cff00ff00|TInterface\\icons\\inv_misc_map02:24|t|r Main Cities", 8);
					   Menu->AddItem(1, "|cff00ff00|TInterface\\icons\\achievement_zone_sholazar_01:24|t|r Eden Garden", 9);
						Menu->AddItem(4, "|cff00ff00|TInterface\\icons\\achievement_zone_northrend_01:24|t|r Northrend Locations", 10);
			             Menu->AddItem(4, "|cff00ff00|TInterface\\icons\\achievement_zone_outland_01:24|t|r BC Locations", 11);
						 Menu->AddItem(6, "|cff00ff00|TInterface\\icons\\achievement_zone_easternkingdoms_01:24|t|r Easter Kingdom/Kalimdor Locations", 651);
				          Menu->AddItem(7, "|cff00ff00|TInterface\\icons\\trade_engineering:24|t|r Mystical Instances", 12);
						   Menu->SendTo(Plr);
					}break;

				case 2: // Alliance Ports
					{
					objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(0, "|cff00ff00|TInterface\\icons\\inv_misc_map02:24|t|r Main Cities", 13);
						Menu->AddItem(1, "|cff00ff00|TInterface\\icons\\achievement_zone_sholazar_01:24|t|r Eden Garden", 9);
						Menu->AddItem(4, "|cff00ff00|TInterface\\icons\\achievement_zone_northrend_01:24|t|r Northrend Locations", 10);
			             Menu->AddItem(4, "|cff00ff00|TInterface\\icons\\achievement_zone_outland_01:24|t|r BC Locations", 11);
						 Menu->AddItem(6, "|cff00ff00|TInterface\\icons\\achievement_zone_easternkingdoms_01:24|t|r Easter Kingdom/Kalimdor Locations", 651);
				          Menu->AddItem(7, "|cff00ff00|TInterface\\icons\\trade_engineering:24|t|r Mystical Instances", 12);
				   Menu->SendTo(Plr);
					}break;


                case 3: // The Arenas Anner
				 {
				 objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				  Menu->AddItem(8, "Teleport: Gurubashi Arena", 18);
				   Menu->AddItem(6, "Announce to the world that you're waiting in the Gurubashi Arena.", 19);
                    Menu->SendTo(Plr);
				 }break;

				 case 5: // Explore
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(9, "Explore all flight paths.", 24); // 16
						 Menu->AddItem(9, "Explore all Maps.", 25); // 17
						  Menu->SendTo(Plr);
					}break;



				case 7: // Advanced  Options
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(6, "Reset My Talent Points.", 30); // 24
						 Menu->AddItem(6, "Remove Resurrection Sickness.", 31); // 25
						  Menu->AddItem(6, "Advance My Skills", 32); // 26
						   Menu->AddItem(6, "Save My Character", 33); // 27
						   Menu->AddItem(6, "|cff800080.playall (by number)|r", 7100);
						   Menu->AddItem(6, "Buff Me", 7268);
						    Menu->SendTo(Plr);
					}break;

				case 8: // Horde Main Cities
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(2, "Teleport: Silvermoon", 20); // 11
                         Menu->AddItem(2, "Teleport: Orgrimmar", 21);   // 12
                          Menu->AddItem(2, "Teleport: Thunderbluff", 22);  // 13
                           Menu->AddItem(2, "Teleport: UnderCity", 23);  //14
						   Menu->AddItem(2, "Teleport: Shattrath",  111);
						   Menu->AddItem(2, "Teleport: Horde Mall", 435);
						   Menu->SendTo(Plr);
					}break;

				case 13: // Alliance Main Cities
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
					   Menu->AddItem(2, "Teleport: The Exodar", 303); // 22
                        Menu->AddItem(2, "Teleport: Stormwind", 27); // 28
                       Menu->AddItem(2, "Teleport: Ironforge", 28); // 29
                      Menu->AddItem(2, "Teleport: Darnassus", 29); // 20
					  Menu->AddItem(2, "Teleport: Shattrath", 111);
					 // Menu->AddItem(2, "Teleport: Alliance Mall", 434);
				     Menu->SendTo(Plr);
					}break;

				case 10: // Northrend Locations (Horde)
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(2, "Borean Tundra", 38);
						Menu->AddItem(2, "Dalaran", 35);
						Menu->AddItem(2, "DragonBlight", 40);
						Menu->AddItem(2, "DK Start Zone", 114);
						Menu->AddItem(2, "Crystalsong Forest", 42);
						Menu->AddItem(2, "Grizzly Hills", 44);
						Menu->AddItem(2, "Howling Fjord", 46);
						Menu->AddItem(2, "Icecrown", 48);
						Menu->AddItem(2, "Sholazar Basin", 50);
						Menu->AddItem(2, "Storm Peaks", 52);
						Menu->AddItem(2, "Wintergrasp", 54);
						Menu->AddItem(2, "Zul'Drak", 56);
						Menu->AddItem(2, "Northrend Instances", 37);
						Menu->SendTo(Plr);
					}break;
               case 650: // Easter Kingdom+ Kalimdoor Location Ally
			    {
				  objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				    Menu->AddItem(6, "Alterac Mountains", 308);
                    Menu->AddItem(6, "Arathi Highlands", 309);
                    Menu->AddItem(6, "Badlands", 310);
                    Menu->AddItem(6, "Burning Steppes", 311);
                    Menu->AddItem(6, "Deadwind Pass", 312);
                    Menu->AddItem(6, "Dun Morogh", 313);
                    Menu->AddItem(6, "Duskwood", 314);
                    Menu->AddItem(6, "Eastern Plaguelands", 315);
                    Menu->AddItem(6, "Elwynn Forest", 316);
                   Menu->AddItem(6, "Eversong Woods", 317);
                   Menu->AddItem(6, "Ghostlands", 318);
                    Menu->AddItem(6, "Hillsbrad Foothills", 319);
                   Menu->AddItem(6, "Hinterlands", 320);
                    Menu->AddItem(6, "Loch Modan", 321);
                    Menu->AddItem(0, "--> Page 2 -->", 652);
					Menu->SendTo(Plr);
				}break;
				
			   case 651: // Easter Kingdom+ Kalimdoor Locations Horde
			       {
				    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
				    Menu->AddItem(6, "Alterac Mountains", 308);
                    Menu->AddItem(6, "Arathi Highlands", 309);
                   Menu->AddItem(6, "Badlands", 310);
                    Menu->AddItem(6, "Burning Steppes", 311);
                    Menu->AddItem(6, "Deadwind Pass", 312);
                    Menu->AddItem(6, "Dun Morogh", 313);
                    Menu->AddItem(6, "Duskwood", 314);
                    Menu->AddItem(6, "Eastern Plaguelands", 315);
                    Menu->AddItem(6, "Elwynn Forest", 316);
                    Menu->AddItem(6, "Eversong Woods", 317);
                    Menu->AddItem(6, "Ghostlands", 318);
                    Menu->AddItem(6, "Hillsbrad Foothills", 319);
                    Menu->AddItem(6, "Hinterlands", 320);
                    Menu->AddItem(6, "Loch Modan", 321);
                    Menu->AddItem(0, "--> Page 2 -->", 652);
					Menu->SendTo(Plr);
				}break;
			  case 652: // Easter Kingdom+ Kalimdor Locations II
			    {
				    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
					Menu->AddItem(6, "Searing Gorge", 322);
                    Menu->AddItem(6, "Silverpine Forest", 323);
                    Menu->AddItem(6, "Stranglethorn Vale", 324);
                    Menu->AddItem(6, "Swamp of Sorrows", 325);
                    Menu->AddItem(6, "The Blasted Lands", 326);
                    Menu->AddItem(6, "Trisfal Glades", 327);
                    Menu->AddItem(6, "Western Plaguelands", 328);
                    Menu->AddItem(6, "Westfall", 329);
                    Menu->AddItem(6, "Wetlands", 330);
					Menu->AddItem(6, "--> Page 3 -->", 653);
					Menu->SendTo(Plr);
				}break;
				
			   case 653: // Kalimdoor Locations I
			    {
					objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
					Menu->AddItem(1, "Ashenvale", 331);
                    Menu->AddItem(1, "Azshara", 332);
                    Menu->AddItem(1, "Azuremyst Isle", 333);
                    Menu->AddItem(1, "Bloodmyst Isle", 334);
                    Menu->AddItem(1, "Darkshore", 335);
                   Menu->AddItem(1, "Durotar", 336);
                   Menu->AddItem(1, "Desolace", 337);
                  Menu->AddItem(1, "Dustwallow Marsh", 338);
                  Menu->AddItem(1, "Felwood", 339);
                  Menu->AddItem(1, "Feralas", 340);
                  Menu->AddItem(1, "Moonglade", 341);
                  Menu->AddItem(1, "Mulgore", 342);
                  Menu->AddItem(1, "Silithus", 343);
                  Menu->AddItem(1, "Stonetalon Mountains", 344);
				  Menu->AddItem(12, "--> Page 4 -->", 654);
				  Menu->SendTo(Plr);
				}break;
				 
			   case 654: // Kalimdor part II
			    {
				    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
					Menu->AddItem(1, "Tanaris", 345);
                    Menu->AddItem(1, "Teldrassil", 346);
                    Menu->AddItem(1, "The Barrens", 347);
                    Menu->AddItem(1, "Thousand Needles", 348);
                    Menu->AddItem(1, "Un Goro Crater", 349);
                    Menu->AddItem(1, "Winterspring", 350);
					Menu->SendTo(Plr);
				}break;
				
               case 205: // Scale Menu
					{
                  objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
                   Menu->AddItem(4, "|cff800080Scale to 1 (normal)|r", 19035);
                   Menu->AddItem(4, "Scale to 1.5", 19031);
                   Menu->AddItem(4, "Scale to 2", 19032);
                   Menu->AddItem(4, "Scale to 2.5", 19033);
                   Menu->AddItem(4, "Scale to 3", 19034);
                   Menu->SendTo(Plr);
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
                        uint32 entry = atoi(Code);

                        if( !entry ) return;
                        Plr->PlaySoundToSet(entry);
                        Plr->Gossip_Complete();
                    }break;
					
				case 7265:
				   {
					  Plr->Gossip_Complete();
				   }break;
				   
				case 7266:
				    {
					   Plr->Gossip_Complete();
					}break;
					
				/*case 7263:
					{
            
                       for(int i=1;i<codes;i++)
                        {     
                       QueryResult * qres = WorldDatabase.Query("SELECT * FROM entry_codes WHERE code = '%s'", Code);
                        if(qres != NULL)
                    {
                    Item * item = objmgr.CreateItem(CodeBoxes[i].ItemId, Plr);
                    Plr->GetItemInterface()->AddItemToFreeSlot(item);
                    WorldDatabase.Query("DELETE * FROM entry_codes WHERE code = '%s'", Code);
                       }
                        else
                    {
                        Plr->BroadcastMessage("Incorrect Code");
                   }
                      }
					}break;

                  case 7264:
                   {
                        int length;
                        length = strlen(Code);
                        if(length == 14)
                        {
                            WorldDatabase.Query("INSERT INTO `entry_codes` VALUES ('%s')", Code);
                       }
                        else
                       {
                             Plr->BroadcastMessage("Code entry must be 14 characters long");
                       }
                    }break;*/

				case 11: // BC Locations (Horde)
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(2, "Blade's Edge Mountains", 58);
						Menu->AddItem(2, "Hellfire Peninsula", 60);
						Menu->AddItem(2, "Nagrand", 62);
						Menu->AddItem(2, "Netherstorm", 64);
						Menu->AddItem(2, "Shadowmoon Valley", 66);
						Menu->AddItem(2, "Shattrath City", 68);
						Menu->AddItem(2, "Terokkar Forest", 70);
						Menu->AddItem(2, "Zangarmarsh", 72);
						Menu->AddItem(2, "BC Instances", 74);
						Menu->SendTo(Plr);
					}break;

				case 12: // Infinity Instances
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
                        Menu->AddItem(8, "|cff00ff00|TInterface\\icons\\achievement_guildperk_mobilebanking:24|t|r Solomon's Vault", 102);
						Menu->AddItem(8, "|cff00ff00|TInterface\\icons\\achievement_boss_thorim:24|t|r Wrath of Norse Gods", 103);
						/*Menu->AddItem(8, "The Forlorn Forest", 104);
						Menu->AddItem(8, "The Elemental Towers", 105);
						Menu->AddItem(8, "Skywall", 106);
						Menu->AddItem(8, "Uldum", 107);*/
						Menu->SendTo(Plr);
					}break;

				case 15: // Northrend Locations (Alliance)
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(2, "Borean Tundra", 39);
						Menu->AddItem(2, "Dalaran", 36);
						Menu->AddItem(2, "DragonBlight", 41);
						Menu->AddItem(2, "DK Start Zone", 114);
						Menu->AddItem(2, "Crystalsong Forest", 43);
						Menu->AddItem(2, "Grizzly Hills", 45);
						Menu->AddItem(2, "Howling Fjord", 47);
						Menu->AddItem(2, "Icecrown", 49);
						Menu->AddItem(2, "Sholazar Basin", 51);
						Menu->AddItem(2, "Storm Peaks", 53);
						Menu->AddItem(2, "Wintergrasp", 55);
						Menu->AddItem(2, "Zul'Drak", 57);
						Menu->AddItem(2, "Northrend Instances", 37);
						Menu->SendTo(Plr);
					}break;

				case 16: // BC Locations (Alliance)
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(2, "Blade's Edge Mountains", 59);
						Menu->AddItem(2, "Hellfire Peninsula", 61);
						Menu->AddItem(2, "Nagrand", 63);
						Menu->AddItem(2, "Netherstorm", 65);
						Menu->AddItem(2, "Shadowmoon Valley", 67);
						Menu->AddItem(2, "Shattrath City", 69);
						Menu->AddItem(2, "Terokkar Forest", 71);
						Menu->AddItem(2, "Zangarmarsh", 73);
						Menu->AddItem(2, "BC Instances", 74);
						Menu->SendTo(Plr);
					}break;

				case 17: // Infinity Instances
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(8, "Solomon's Vault", 102);
						Menu->AddItem(8, "Wrath of Norse Gods", 103);
						/*Menu->AddItem(8, "The Forlorn Forest", 104);
						Menu->AddItem(8, "The Elemental Towers", 105);
						Menu->AddItem(8, "Skywall", 106);
						Menu->AddItem(8, "Uldum", 107);*/
						Menu->SendTo(Plr);
					}break;


				case 37: // Northrend Instances (Horde/Alliance)
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
					     Menu->AddItem(3, "Azjol-Nerub: Ahn'kahet: The Old Kingdom", 75);
						 Menu->AddItem(3, "Azjol-Nerub: Azjol-Nerub", 76);
						 Menu->AddItem(3, "Caverns of Time: The Culling of Stratholme", 77);
						 Menu->AddItem(3, "Drak'Tharon Keep", 78); 
						 Menu->AddItem(3, "Gundrak", 79);
						 Menu->AddItem(3, "The Nexus: The Nexus", 80); 
						 Menu->AddItem(3, "The Nexus: The Oculus", 81); 
						 Menu->AddItem(3, "The Violet Hold", 82); 
						 Menu->AddItem(3, "Ulduar: Halls of Lightning", 83); 
						 Menu->AddItem(3, "Ulduar: Halls of Stone", 84); 
						 Menu->AddItem(3, "Utgarde Keep: Utgarde Keep", 85); 
						 Menu->AddItem(3, "Ulduar", 101);
						 Menu->AddItem(3, "Utgarde Keep: Utgarde Pinnacle", 86); 
						 Menu->AddItem(3, "Icecrown:Halls of Reflection", 108);
						 Menu->AddItem(3, "Icecrown:The Forge of Souls", 109);
						 Menu->AddItem(3, "Icecornw Citadel", 110);
						 Menu->AddItem(3, "The Ruby Sanctum", 117);
					   Menu->SendTo(Plr);
					}break;

				case 74: // BC Instances (Horde/Alliance)
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(5, "Auchenai Crypts", 87); // Not Finished.
                        Menu->AddItem(5, "Mana-Tombs", 88); // Not Finished.
                        Menu->AddItem(5, "Sethekk Halls", 89); // Not Finished.
                        Menu->AddItem(5, "Shadow Labyrinth", 90); // Not Finished.
                        Menu->AddItem(5, "Old Hillsbrad Foothills", 91); // Not Finished.
                        Menu->AddItem(5, "The Slave Pens", 92); // Not Finished.
                        Menu->AddItem(5, "The Steamvault", 93); // Not Finished.
                        Menu->AddItem(5, "The Underbog", 94); // Not Finished.
                        Menu->AddItem(5, "Hellfire Ramparts", 95); // Not Finished.
                        Menu->AddItem(5, "The Blood Furnace", 96); // Not Finished.
                        Menu->AddItem(5, "The Shattered Halls", 97); // Not Finished.
                        Menu->AddItem(5, "The Arcatraz", 98); // Not Finished.
                        Menu->AddItem(5, "The Botanica", 99); // Not Finished.
                        Menu->AddItem(5, "The Mechanar", 100); // Not Finished.
						Menu->AddItem(5, " Ahn'Qiraj ", 358);
						Menu->AddItem(5, "Blackfathom Depths", 359);
						Menu->AddItem(5, " Blackrock Depths ", 360);
						Menu->AddItem(5, " Next Page", 370);
						Menu->SendTo(Plr);
					}break;

				case 370: // BC Instances part II
				{
				  objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				  Menu->AddItem(10, " Blackrock Spire ", 361);
				  Menu->AddItem(10, " Blackwing Lair ", 362);
				  Menu->AddItem(10, " Caverns of Time ", 363);
				  Menu->AddItem(10, " Deadmines ", 364);
				  Menu->AddItem(10, " Onyxia's Lair ", 365);
				  Menu->SendTo(Plr);
				}break;
				
                 case 4: // Show Online Players
				   {
                    uint32 clientsNum = (uint32)sWorld.GetSessionCount();
                    Plr->BroadcastMessage("Current Players Online: %d", clientsNum);
                    Plr->Gossip_Complete();
				   }break;
               
			   case 7268: // Buff Me
				{
				  Plr->CastSpell(Plr, 58450, true);
				  Plr->CastSpell(Plr, 48100, true);
				  Plr->CastSpell(Plr, 48104, true);
				  Plr->CastSpell(Plr, 48102, true);
				  Plr->CastSpell(Plr, 58449, true);
				  Plr->CastSpell(Plr, 58452, true);
				}break;
				 
				case 9: // Eden Garden
				 {
				  objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				  if(Plr->GetItemInterface()->GetItemCount(55867) > 1)
				  {
				    Menu->AddItem(10, " New Dawn Order ", 461);
				    Menu->AddItem(10, " City of the Lost Souls ", 462);
				    Menu->AddItem(10, " Aphrodiats Temple ", 463);
				    Menu->AddItem(10, " Temple of Sudan ", 464);
				    Menu->AddItem(10, " Forbidden City ", 465);
				    Menu->SendTo(Plr);
				  }
				  else
		          {
		            Menu->AddItem(0, "Buy Ticket Before you take a flight", 9962);
					Menu->SendTo(Plr);
		          }
				  
				 }break;


				 case 14: // Eden Garden
					 {
					    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				  Menu->AddItem(10, " New Dawn Order ", 461);
				  Menu->AddItem(10, " City of the Lost Souls ", 462);
				  Menu->AddItem(10, " Aphrodiats Temple ", 463);
				  Menu->AddItem(10, " Temple of Sudan ", 464);
				  Menu->AddItem(10, " Forbidden City ", 465);
				  Menu->SendTo(Plr);
				     }break;


				 case 18: // Gurubashi Port
					 {
						 Plr->SendAreaTriggerMessage("PvP activated.");
						 Plr->EventTeleport(0, -13226.732422, 231.588669, 34.537);
					 }break;

				 case 19: // Announce that you're in the gurubashu arena
					 {
					   char announce[255];
			            sprintf(announce, "[|cffff0000PvP Announcer|r]|cff00ff00 %s |r|cffffffff is waiting in the arena for more players.|r", Plr->GetName());
			             sWorld.SendWorldText(announce);
			            Plr->Gossip_Complete();
					 }break;

					 case 20:
                      {
                      Plr->EventTeleport(530, 9400.486328, -7278.376953, 14.206780);
			         }break;

					 case 21:
                      {
                       Plr->EventTeleport(1, 1371.068970, -4370.801758, 26.052483);
			          }break;


					 case 22:
                      {
                       Plr->EventTeleport(530, -4072.202393, -12014.337891, -1.277277);
					  }break;


					 case 23:
                      {
                      Plr->EventTeleport(0, 2050.203125, 285.650604, 56.994549);
					  }break;

					  case 24:
							{
                              for (uint8 i=0; i<8; i++)
                            {
                            Plr->SetTaximask(i, 0xFFFFFFFF);
                            }
                             Plr->BroadcastMessage("All flight paths have been opened!");
                             Plr->Gossip_Complete();
							}break;

					   case 25: // Explore All Maps
						   {
							for (uint8 i=0; i<64; i++)
                            {
                              Plr->SetFlag(PLAYER_EXPLORED_ZONES_1+i,0xFFFFFFFF);
                              }
                              Plr->BroadcastMessage("All Map Locations have been opened!");
                              Plr->Gossip_Complete();
                           }break;

					case 303:
                      {
                        Plr->EventTeleport(530, -4014, -11895, -1.5);
					  }break;

					  case 27:
                      {
                     Plr->EventTeleport(0, -9100.480469, 406.950745, 92.594185);
					  }break;

					  case 28:
                       {
                      Plr->EventTeleport(0, -5028.265137, -825.976563, 495.301575);
				      }break;

                       case 29:
                         {
                            Plr->EventTeleport(1, 9985.907227, 1971.155640, 1326.815674);
						 }break;

					   case 30: // Reset Talents
							{
							   Plr->BroadcastMessage("Your Talents have now been reset.");
								Plr->Reset_Talents();
								 Plr->Gossip_Complete();
							}break;

						case 31: // Remove Sickness
							{
								Plr->addSpell(15007);
                                 Plr->removeSpell(15007,0,0,0);
                                  Plr->BroadcastMessage("Your sickness is gone...!" );
                                   Plr->Gossip_Complete();
							}break;

						case 32: // Advance All Skills
							{
								if (Plr->_HasSkillLine(43))
                                 {Plr->_AdvanceSkillLine(43, 600);}
                                   if (Plr->_HasSkillLine(55))
                                    {Plr->_AdvanceSkillLine(55, 600);}
                                       if (Plr->_HasSkillLine(44))
									    {Plr->_AdvanceSkillLine(44, 600);}
                                           if (Plr->_HasSkillLine(95))
                                            {Plr->_AdvanceSkillLine(95, 600);}
                                           if (Plr->_HasSkillLine(54))
                                         {Plr->_AdvanceSkillLine(54, 600);}
                                        if (Plr->_HasSkillLine(45))
                                     {Plr->_AdvanceSkillLine(45, 600);}
                                    if (Plr->_HasSkillLine(46))
                                 {Plr->_AdvanceSkillLine(46, 600);}
                                if (Plr->_HasSkillLine(136))
                              {Plr->_AdvanceSkillLine(136, 600);}
                             if (Plr->_HasSkillLine(160))
                           {Plr->_AdvanceSkillLine(160, 600);}
                          if (Plr->_HasSkillLine(162))
                           {Plr->_AdvanceSkillLine(162, 600);}
                             if (Plr->_HasSkillLine(172))
                              {Plr->_AdvanceSkillLine(172, 600);}
                                if (Plr->_HasSkillLine(173))
                                 {Plr->_AdvanceSkillLine(173, 600);}
                                   if (Plr->_HasSkillLine(176))
                                    {Plr->_AdvanceSkillLine(176, 600);}
                                      if (Plr->_HasSkillLine(226))
                                       {Plr->_AdvanceSkillLine(226, 600);}
                                         if (Plr->_HasSkillLine(228))
                                          {Plr->_AdvanceSkillLine(228, 600);}
                                            if (Plr->_HasSkillLine(229))
                                              {Plr->_AdvanceSkillLine(229, 600);}
                                             if (Plr->_HasSkillLine(473))
                                           {Plr->_AdvanceSkillLine(473, 600);}
                                          Plr->BroadcastMessage("All skills are now advanced to 400");
                                        Plr->Gossip_Complete();
							}break;

						case 33: // Save Character
							{
								Plr->SaveToDB(true);
                                 Plr->BroadcastMessage("Your Character Has Been Succesfully Saved to the Database");
                                  Plr->Gossip_Complete();
							 }break;

						case 34:
						{
			             if(!Code)
				          return;

			        if(Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) < COST)
				    return;

			      Player* pTarget = objmgr.GetPlayer(Code, false);
			       if(!pTarget)
			         {
				     Plr->BroadcastMessage("Player does not exist.");
				     Plr->Gossip_Complete();
				     return;
			       }
			     if(Plr->CombatStatus.IsInCombat())
			      {
				     Plr->BroadcastMessage("You cannot teleport while in combat.");
				     Plr->Gossip_Complete();
				     return;
			        }
			      if(pTarget->CombatStatus.IsInCombat())
			      {
				  Plr->BroadcastMessage("Your friend is in combat, you cannot teleport to him now.");
				  Plr->Gossip_Complete();
				  return;
			      }
			      if(Plr->HasFlag(PLAYER_FLAGS, PLAYER_FLAG_FREE_FOR_ALL_PVP))
			        {
				   Plr->BroadcastMessage("You can't port while in a PvP zone.");
				   Plr->Gossip_Complete();
				   return;
			       }
			if(pTarget->HasFlag(PLAYER_FLAGS, PLAYER_FLAG_FREE_FOR_ALL_PVP))
			{
				Plr->BroadcastMessage("You can't port to a player in a PvP zone.");
				Plr->Gossip_Complete();
				return;
			}
			if(pTarget->GetSession()->HasGMPermissions())
			{
				Plr->BroadcastMessage("You cannot port to a Gamemaster.");
				Plr->Gossip_Complete();
				return;
			}
			if(pTarget->GetTeam() != Plr->GetTeam())
			{
				Plr->BroadcastMessage("Player is from the opposing faction.");
				Plr->Gossip_Complete();
				return;
			}
			uint32 pMap = pTarget->GetMapId();
			if(pMap != 0 && pMap != 1 && pMap != 530 && pMap != 571)
			{
				Plr->BroadcastMessage("Cannot port to a player inside an instance.");
				Plr->Gossip_Complete();
				return;
			}
			Plr->SetUInt32Value(PLAYER_FIELD_COINAGE, Plr->GetUInt32Value(PLAYER_FIELD_COINAGE)-COST);
			float pX = pTarget->GetPositionX();
			float pY = pTarget->GetPositionY();
			float pZ = pTarget->GetPositionZ();
			float pO = pTarget->GetOrientation();
			Plr->Gossip_Complete();
			pTarget->BroadcastMessage("%s is porting to your location.", Plr->GetName());
			Plr->EventTeleport(pMap, pX, pY, pZ);
			Plr->SetOrientation(pO);
		       }break;
                     /*World Ports*/
						case 35: // Horde Dalaran
							{
								Plr->EventTeleport(571, 5935.255371, 511.038635, 650.178406);
							}break;

						case 36: // Alliance Dalaran
							{
								Plr->EventTeleport(571, 5724.215332, 741.515137, 641.768982);
							}break;

						case 38: // Borean Tundra Horde
							{
								Plr->EventTeleport(571, 3452, 3836, 29);
							}break;

						case 39: // Borean Tundra Alliance
							{
								Plr->EventTeleport(571, 3452, 3836, 29);
							}break;

						case 40: // DragonBlight Horde
							{
								Plr->EventTeleport(571, 3577, 656, 77);
							}break;

						case 41: // DragonBlight Alliance
							{
							 Plr->EventTeleport(571, 3577, 656, 77);
							}break;

						case 42: // Crystalsong Forest Horde
							{
								Plr->EventTeleport(571, 5398, -743, 163);
							}break;

						case 43: // Crystalsong Forest Alliance
							{
								Plr->EventTeleport(571, 5398, -743, 163);
							}break;

						case 44: // Grizzly Hills Horde
							{
								Plr->EventTeleport(571, 2767, -2889, 64);
							}break;

						case 45: // Grizzly Hills Alliance
							{
								Plr->EventTeleport(571, 2767, -2889, 64);
							}break;

						case 46: // Howling Fjord Horde
							{
								Plr->EventTeleport(571, 592, -5095, 6);
							}break;

						case 47: // Howling Fjord Alliance
							{
								Plr->EventTeleport(571, 592, -5095, 6);
							}break;

						case 48: // Icecrown Horde
							{
								Plr->EventTeleport(571, 6434, 1151, 283);
							}break;
							
                        case 434: // Ally Mall
						    {
							    Plr->EventTeleport(571, 5751, 3049, 288);
							}break;
							
						case 435: // Horde Mall
						    {
							    Plr->EventTeleport(571, 4020, -3778, 116);
							}break;
							
						case 49: // Icecrown Alliance
							{
								Plr->EventTeleport(571, 6434, 1151, 283);
							}break;

						case 50: // Sholazar Basin Horde
							{
								Plr->EventTeleport(571, 6516, 4824, -55);
							}break;

						case 51: // Sholazar Basin Alliance
							{
								Plr->EventTeleport(571, 6516, 4824, -55);
							}break;

						case 52: // Storm Peaks Horde
							{
								Plr->EventTeleport(571, 7343, -927, 910);
							}break;

						case 53: // Storm Peaks Alliance
							{
								Plr->EventTeleport(571, 7343, -927, 910);
							}break;

						case 56: // Zul'Drak Horde
							{
								Plr->EventTeleport(571, 5441, -2304, 298);
							}break;

						case 57: // Zul'Drak Alliance
							{
								Plr->EventTeleport(571, 5441, -2304, 298);
							}break;

						case 58: //Blade's Edge Mountains Horde
                           {
                                Plr->EventTeleport(530, 2924, 5982, -1);
                           }break;

						case 59: // Blade's Edge Mountains Alliance
							{
								Plr->EventTeleport(530, 2924, 5982, -1);
							}break;

						case 60: // Hellfire Peninsula Horde
							{
								Plr->EventTeleport(530, 192.5650, 2640.600, 87.89410);
							}break;

						case 61: // Hellfire Peninsula Alliance
							{
								Plr->EventTeleport(530, 192.5650, 2640.600, 87.89410);
							}break;

						case 62: // Nagrand Horde
							{
								Plr->EventTeleport(530, -1361.54, 7218.860, 33.81410);
							}break;

						case 63: // Nagrand Alliance
							{
								Plr->EventTeleport(530, -1361.54, 7218.860, 33.81410);
							}break;

						case 64: // Netherstorm Horde
							{
								Plr->EventTeleport(530, 3041.380, 3675.990, 143.3900);
							}break;

						case 65: // Netherstorm Alliance
							{
								Plr->EventTeleport(530, 3041.380, 3675.990, 143.3900);
							}break;

						case 66: // Shadowmoon Valley Horde
							{
								Plr->EventTeleport(530, -3693, 2344, 77);
							}break;

						case 67: // Shadowmoon Valley Alliance
							{
								Plr->EventTeleport(530, -3693, 2344, 77);
							}break;

						case 68: // Shattrath City Horde
							{
								Plr->EventTeleport(530, -1913.24, 5446.760, -12.4279);
							}break;

						case 69: // Shattrath City Alliance
							{
								Plr->EventTeleport(530, -1913.24, 5446.760, -12.4279);
							}break;

						case 70: // Terokkar Forest Horde
							{
								Plr->EventTeleport(530, -1975, 4516, 13);
							}break;

						case 71: // Terokkar Forest Alliance
							{
								Plr->EventTeleport(530, -1975, 4516, 13);
							}break;

						case 72: //Zangarmarsh Horde
							{
								Plr->EventTeleport(530, 291.2870, 7861.100, 21.26430);
							}break;

						case 73: // Zangarmarsh Alliance
							{
								Plr->EventTeleport(530, 291.2870, 7861.100, 21.26430);
							}break;
						/* End of World Ports */

						/* Instance Ports */
						case 75: // Azjol-Nerub: Ahn'kahet: The Old Kingdom
							{
                             Plr->EventTeleport(571, 3714.200, 2155.091, 37.228306);
							}break;

						case 76: //  Azjol-Nerub: Azjol-Nerub
						{
                         Plr->EventTeleport(571, 3714.200, 2155.091, 37.228306);
						}break;

                        case 77: // Culling of Stratoholme
							{
							 Plr->EventTeleport(0, 3345, -3380, 145);
							}break;

						case 78: // Drak'Tharon Keep
							{
								Plr->EventTeleport(571, 4897, 2046, 249);
							}break;

						case 79: // Gundrak
							{
								Plr->EventTeleport(571, 6954, -4417, 451);
							}break;

						case 80: // The Nexus: The Nexus
							{
								Plr->EventTeleport(571, 3783, 6942, 105);
							}break;

						case 81: // The Nexus: The Oculus
							{
								Plr->EventTeleport(571, 3783, 6942, 105);
							}break;

						case 82: // The Violet Hold
							{
								Plr->EventTeleport(571, 5708, 521, 650);
							}break;

						case 83: // Ulduar: Halls of Lightning
							{
								Plr->EventTeleport(571, 8937, 1266, 1026);
							}break;

						case 84: // Ulduar: Halls of Stone
							{
								Plr->EventTeleport(571, 8937, 1266, 1026);
							}break;

						case 85: // Utgarde Keep: Utgarde Keep
							{
								Plr->EventTeleport(571, 1228, -4943, 36);
							}break;

						case 86: // Utgarde Keep: Utgarde Pinnacle
							{
								Plr->EventTeleport(571, 1274, -4857, 216);
							}break;

						case 87: // Auchenai Crypts
							{
								Plr->EventTeleport(530, -3367, 5216, -101);
							}break;

						case 88: // Mana-Tombs
							{
								Plr->EventTeleport(530, -3100, 4950, -100);
							}break;

						case 89: // Sethekk Halls
							{
								Plr->EventTeleport(530, -3364, 4675, -101);
							}break;

						case 90: // Shadow Labyrinth
							{
								Plr->EventTeleport(530, -3630, 4941, -101);
							}break;

						case 91: // Old Hillsbrad Foothills
							{
								Plr->EventTeleport(1, -8568, -4260, -213);
							}break;

						case 92: // The Slave Pens
                           {
                                Plr->EventTeleport(530, 719, 6999, -73);
                           }break;

						case 93: // The Steamvault
							{
								Plr->EventTeleport(530, 816, 6934, -80);
							}break;

						case 94: // The Underbog
							{
								Plr->EventTeleport(530, 777, 6763, -72);
							}break;

						case 95: // Hellfire Ramparts
							{
								Plr->EventTeleport(530, -362, 3076, -16);
							}break;

						case 96: // The Blood Furnace
							{
								Plr->EventTeleport(530, -303, 3164, 32);
							}break;

						case 97: // The Shattered Halls
							{
								Plr->EventTeleport(530, -311, 3083, -3);
							}break;

						case 98: // The Arcatraz
							{
								Plr->EventTeleport(1, -2705.108154, -4680.062500, 11.797676);
							}break;

						case 99: // The Botanica
							{
								Plr->EventTeleport(530, 3404, 1488, 183);
							}break;

						case 100: // The Mechanar
							{
								Plr->EventTeleport(530, 2870, 1557, 252);
							}break;

						case 101: // Ulduar: Raid
							{
								Plr->EventTeleport(603, -811.151978, -143.679916, 432.848022);
							}break;

						case 102: // Valley of Decay
							{
								Plr->EventTeleport(574, 413, -430, 206);
							}break;

						case 103: // Medusa's Lair
							{
								Plr->EventTeleport(13, -917.356, 568.036, 715.948);
							}break;

						case 104: // The Forlorn Forest
							{
								Plr->EventTeleport(600, -735, 448, -124);
							}break;

						case 105: // The Elemental Towers
						    {
							    Plr->EventTeleport(568, 1041, 1769, 1);
							}break;
						case 106: // Skywall
						    {
							    Plr->EventTeleport(13, 0 , 0, 0);
							}break;
						case 107: // Uldum
						    {
							    Plr->EventTeleport(43, 0, 0, 0);
							}break;
						/*case 108: // Icecrown:Halls of Reflection
						    {
							    Plr->EventTeleport();
							}break;
						case 109: // Icecrown:The Forge of Souls
						    {
							   Plr->EventTeleport();
							}break;
						case 110: // Icecrown Citadel
						    {
							   Plr->EventTeleport();
							}break;*/
						case 111: // Shattrath
						    {
							    Plr->EventTeleport(530, -1868, 5440, -11);
							}break;
						case 112: // Raid Stormwind
						    {
							    Plr->EventTeleport(0, -9421, 523, 59);
							}break;
						case 113: // Raid Orgrimmar
						    {
							   Plr->EventTeleport( 1, 1221, -3841, 29);
							}break;
						case 114: // DK Start Zone
						    {
							    Plr->EventTeleport( 609, 2353, -5666, 427);
							}break;
	
						case 117: // The Ruby Sanctum
						    {
							    Plr->EventTeleport(724, 3167.1, 527.865, 72.8897);
							}break;
				
						case 359: // Blackfathom Depths
						    {
							    Plr->EventTeleport(1, 4248, 736, -26);
							}break;
						case 360: // Blackrock Depths
						    {
							    Plr->EventTeleport(0, -7187, -914, 166);
							}break;
						case 361: //  Blackrock Spire
						    {
							    Plr->EventTeleport(0, -7532, -1221, 286);
							}break;
						case 362: // Blackwing Lair
						    {
							    Plr->EventTeleport(229, 137, -474, 117);
							}break;
						case 363: // Caverns of Time
						    {
							    Plr->EventTeleport(1, -8568, -4260, -213);
							}break;
						case 364: // Deadmines
						    {
							    Plr->EventTeleport(0, -11211, 1671, 26);
							}break;
						case 365: // Onyxia's Lair
						    {
							    Plr->EventTeleport(1, -4709, -3729, 55);
							}break;
						case 308: // Alterac Mountains
						    {
							    Plr->EventTeleport(0, 237, -652, 119);
							}break;
						case 309: // Arathi Highlands
						    {
							    Plr->EventTeleport(0, -1550, -2495, 55);
							}break;
						case 310: // Badlands
						    {
							    Plr->EventTeleport(0, -6775, -3286, 242);
							}break;	
						case 311: // Burning Steppes
						    {
							   Plr->EventTeleport(0, -7975, -1786, 133.5);
							}break;
						case 312: // Deadwind Pass
						    {
							   Plr->EventTeleport(0, -10447, -1872, 105);
							}break;
						case 313: // Dun Morogh
						    {
							   Plr->EventTeleport(0, -5709, -1339, 395);
							}break;
						case 314: // Duskwood
						    {
							   Plr->EventTeleport(0, -10914, -528, 54);
							}break;
						case 315: // Eastern Plaguelands
						    {
							   Plr->EventTeleport(0, 1739, -3623, 120);
							}break;
						case 316: // Elwynn Forest
						    {
							    Plr->EventTeleport(0, -9591, -463, 58);
							}break;
						case 317: // Eversong Woods
						    {
							    Plr->EventTeleport(530, 8250, -7214, 140);
							}break;
						case 318: // Ghostlands
						    {
							    Plr->EventTeleport(530, 6396, -6848, 101);
							}break;
						case 319: // Hillsbrad Foothills
						    {
							    Plr->EventTeleport(0, -440, -582, 54);
							}break;
						case 320: // Hinterlands
						    {
							    Plr->EventTeleport(0, 235, -3298, 110);
							}break;
						case 321: // Loch Modan
						    {
							    Plr->EventTeleport(0, -5853, -3251, 303);
							}break;
						case 322: // Searing Gorge
						    {
							    Plr->EventTeleport(0, -6645, -1918, 245);
							}break;
						case 323: // Silverpine Forest
						    {
							    Plr->EventTeleport(0, 628, 1291, 87);
							}break;
						case 324: // Stranglethorn Vale
						    {
							    Plr->EventTeleport(0, -14246, 301, 28);
							}break;
						case 325: // Swamp of Sorrows
						    {
							    Plr->EventTeleport(0, -10476, -2408, 74);
							}break;
						case 326: // The Blasted Lands
						    { 
							    Plr->EventTeleport(0, -11189, -3023, 8);
							}break;
						case 327: // Tirisfal Glades
						    {
							    Plr->EventTeleport(0, 1599, 569, 38);
							}break;
						case 328: // Western Plaguelands
						    {
							    Plr->EventTeleport(0, 1676, -1366, 70);
							}break;
						case 329: // Westfall
						    {
							    Plr->EventTeleport(0, -10922, 998, 36);
							}break;
						case 330: // Wetlands
						    {
							    Plr->EventTeleport(0, -3604, -2711, 20);
							}break;
						case 331: // Ashenvale
						    {
							    Plr->EventTeleport(1, 2319, -1672, 124);
							}break;
						case 332: // Azshara
						    {
							    Plr->EventTeleport(1, 3336, -4599, 93);
							}break;
						case 333: // Azuremyst Isle
						    {
							    Plr->EventTeleport(530, -4540, -11933, 28);
							}break;
						case 334: // Bloodmyst Isle
						    {
							    Plr->EventTeleport(530, -2721, -12206, 10);
							}break;
						case 335: // Darkshore
						    {
							    Plr->EventTeleport(1, 5084, 242, 29);
							}break;
						case 336: // Desolace
						    {
							    Plr->EventTeleport(1, -548, 1276, 90);
							}break;
						case 337: // Durotar
						    {
							    Plr->EventTeleport(1, 301, -4184, 28);
							}break;
						case 338: // Dustwallow Marsh
						    {
							    Plr->EventTeleport(1, -3345, -3078, 33);
							}break;
						case 339: // Felwood
						    {
							    Plr->EventTeleport(1, 5537, -585, 359);
							}break;
						case 340: // Feralas
						    {
							    Plr->EventTeleport(1, -4811, 1037, 105);
							}break;
						case 341: // Moonglade
						    {
							    Plr->EventTeleport(1, 7931, -2616, 493);
							}break;
						case 342: // Mulgore
						    {
							    Plr->EventTeleport(1, -2372, -893, -9);
							}break;
						case 343: // Silithus
						    {
							    Plr->EventTeleport(1, -6839, 763, 43);
							}break;
						case 344: // Stonetalon Mountains
						    {
							    Plr->EventTeleport(1, 588, 330, 48);
							}break;
						case 345: // Tanaris
						    {
							    Plr->EventTeleport(1, -7149, -3746, 9);
							}break;
						case 346: // Teldrassil
						    {
							    Plr->EventTeleport(1, 9947, 649, 1310);
							}break;
						case 347: // The Barrens
						    {
							    Plr->EventTeleport(1, 567, -2573, 96);
							}break;
						case 348: // Thousand Needles
						    {
							    Plr->EventTeleport(1, -4969, -1723, -61);
							}break;
						case 349: // Un Goro Crater
						    {
							    Plr->EventTeleport(1, -7932, -2139, -230);
							}break;
						case 350: // Winterspring
						    {
							    Plr->EventTeleport(1, 6719, -4646, 722);
							}break;
						/*case 666:  //Halloween Event
							{
								Plr->EventTeleport(0, -11067, -1816, 56);
							}break;*/
						case 461 : // New Dawn
						{
						  Plr->GetItemInterface()->RemoveItemAmt(55867, 1);
						  Plr->EventTeleport(169, 1656, 2692, 27);
						}break;
						
						case 462: // City of the Lost Souls
						{
						   Plr->GetItemInterface()->RemoveItemAmt(55867, 1);
						   Plr->EventTeleport(169, 1100, 2051, 24);
						}break;
						
						case 463:
						{
						   Plr->GetItemInterface()->RemoveItemAmt(55867, 1);
						   Plr->EventTeleport(169, 2435, 2532, 26);
						}break;
						
						case 464:
						{
						  Plr->GetItemInterface()->RemoveItemAmt(55867, 1);
						  Plr->EventTeleport(169, 2382.288, 2920.809, 6.828);
						}break;
						
						case 465:
						{
						  Plr->GetItemInterface()->RemoveItemAmt(55867, 1);
						  Plr->EventTeleport(169, 1318.467, 3782.229, 28.850);
						}break;
						
						case 580: // Pet Giver
							{
								objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				               Menu->AddItem(8, "Bat", 466);
				               Menu->AddItem(8, "Bear", 467);
				               Menu->AddItem(8, "Boar", 468);
				               Menu->AddItem(8, "Carrion Bird", 469);
				                Menu->AddItem(8, "Cat", 470);
				                Menu->AddItem(8, "Crocolisk", 471);
				               Menu->AddItem(8, "Dragonhawk", 472);
				               Menu->AddItem(8, "Nether Ray", 473);
				                Menu->AddItem(8, "Owl", 474);
				                Menu->AddItem(8, "Raptor", 475);
				                Menu->AddItem(8, "Ravager", 476);
				                Menu->AddItem(8, "Scorpion", 477);
				               Menu->AddItem(8, "Exotic Pets", 471);
				              Menu->SendTo(Plr);
				            }break;
              
               case 466: //---------------------------------------------------------------Bat
				{
					CreatePet(16173); return;
				}break;
				case 467: //---------------------------------------------------------------Bear
				{
					CreatePet(7446); return;
				}break;
				case 468: //---------------------------------------------------------------Boar
				{
					CreatePet(16117); return;
				}break;
				case 469: //---------------------------------------------------------------Carrion Bird
				{
					CreatePet(21042); return;
				}break;
				case 470: //---------------------------------------------------------------Cat
				{
					CreatePet(21723); return;
				}break;
				case 471: //---------------------------------------------------------------Crocolisk
				{
					CreatePet(24047); return;
				}break;
				case 472: //---------------------------------------------------------------Dragonhawk
				{
					CreatePet(20038); return;
				}break;
				case 473: //---------------------------------------------------------------Nether ray
				{
					CreatePet(17731); return;
				}break;
				case 474: //---------------------------------------------------------------Owl
				{
					CreatePet(21804); return;
				}break;
				case 475: //---------------------------------------------------------------Raptor
				{
					CreatePet(20634); return;
				}break;
				case 476: //---------------------------------------------------------------Ravager
				{
					CreatePet(23326); return;
				}break;
				case 477: //----------------------------------------------------------------Scorpion
				{
					CreatePet(21864); return;
				}break;
				case 478: //----------------------------------------------------------------Tallstrider
				{
					CreatePet(22807); return;
				}break;
				case 479: //----------------------------------------------------------------Warp Stalker
				{
					CreatePet(23219); return;
				}break;
				case 480: //-----------------------------------------------------------------Wolf
				{
					CreatePet(20330); return;
				}break;
				case 482: // Skoll
					{
						 CreatePet(35189); return;
					}break;
				case 483: // Acturis
					{
						 CreatePet(38453); return;
					}break;
				case 484: // Gondria
					{
						 CreatePet(33776); return;
					}break;
				case 485: //Spirit Wolf
					{
						 CreatePet(55002); return;
					}break;
				case 486: // Loque
					{
						CreatePet(32517); return;
					}break;
				case 481: //-------------------------------Exotic Pets---------------//
				{
						GossipMenu* Menu;
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				        Menu->AddItem(8, "Skoll",482);
				        Menu->AddItem(8, "Acturis", 483);
				        Menu->AddItem(8, "Gondria", 484);
				        Menu->AddItem(8, "Spirit Wolf", 485);
				        Menu->AddItem(8, "Loque'nahak", 486);
					    Menu->SendTo(Plr);
				}break;

  }
  
};

void DPanel::GossipEnd(Object* pObject, Player* Plr)
{

	GossipScript::GossipEnd(pObject, Plr);

}

void SetupDPanel(ScriptMgr * mgr)
{
     GossipScript * gs = (GossipScript*) new DPanel();
     mgr->register_item_gossip_script(DPanelID, gs);
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//##################################
//$#   Donator Control Panel      #$
//$#     D2-link.org              #$
//$#       Made By Easelm         #$
//##################################
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

      #include "StdAfx.h"
       #include "Setup.h"
          //---------Defines-----------//
              #define DPanelID 68888   //
                 
              #define COST 100000      // 100 Gold.
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
  
        };

		 void DPanel::GossipHello(Object* pObject, Player* Plr, bool AutoSend)
		 {
			 if(Plr->CombatStatus.IsInCombat())
			 {
				 Plr->BroadcastMessage("You're in Combat, sorry!");

				   return;
			 }
		 
		     GossipMenu *Menu;
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);

			Menu->AddItem(8, "[Thanks for donating, enjoy this D Panel.]");
		     if ( Plr->getLevel()> 80 )
			 {
			 
				 Plr->BroadcastMessage("You're not level 80.");
			 
			 }else{
             if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
			  {Menu->AddItem(6, "Horde Teleports.", 1);}else{Menu->AddItem(0, "Alliance Teleports.", 2);}
			    Menu->AddItem(0, "PvP.", 3);
				 Menu->AddItem(7, "Show Online Players, please.", 4);
			      Menu->AddItem(8, "Exploring.", 5);
				   Menu->AddItem(0, "Server Options.", 7);
					if(Plr->GetUInt32Value(PLAYER_FIELD_COINAGE) < COST)
					{
				   Plr->BroadcastMessage("You don't have enough gold to teleport to another player.");
		            return;
				     }else{
					  Menu->AddItem(0, "Port to a Player", 34, 1);
                    
					 if(AutoSend)
                      Menu->SendTo(Plr);
			 }
			 }  
		 }

		 void DPanel::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
		 {
			 GossipMenu *Menu;

			 switch(IntId)

			 {
				 case 1: // Horde Ports
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
					 Menu->AddItem(0, "Main Cities", 8);
					   Menu->AddItem(1, "Teleport to the Mall.", 9);
						Menu->AddItem(4, "Northrend Locations", 10);
			             Menu->AddItem(4, "BC Locations", 11);
				          Menu->AddItem(7, "Custom Ports", 12);
						   Menu->SendTo(Plr);
					}break;

				case 2: // Alliance Ports
					{
					objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(0, "Main Cities", 13);
					   Menu->AddItem(1, "Teleport to the Mall.", 14);
					  Menu->AddItem(4, "Northrend Locations", 15);
			         Menu->AddItem(4, "BC Locations", 16);
				    Menu->AddItem(7, "Custom Ports", 17);
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

					

				case 7: // Conan Options
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(6, "Reset My Talent Points.", 30); // 24
						 Menu->AddItem(6, "Remove Resurrection Sickness.", 31); // 25
						  Menu->AddItem(6, "Advance My Skills", 32); // 26
						   Menu->AddItem(6, "Save My Character", 33); // 27
						    Menu->SendTo(Plr);
					}break;

				case 8: // Horde Main Cities
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(2, "Teleport: Silvermoon", 20); // 11              
                         Menu->AddItem(2, "Teleport: Orgrimmar", 21);   // 12            
                          Menu->AddItem(2, "Teleport: Thunderbluff", 22);  // 13             
                           Menu->AddItem(2, "Teleport: UnderCity", 23);  //14
						   Menu->SendTo(Plr);
					}break;

				case 13: // Alliance Main Cities
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
					   Menu->AddItem(2, "Teleport: The Exodar", 26); // 22
                        Menu->AddItem(2, "Teleport: Stormwind", 27); // 28
                       Menu->AddItem(2, "Teleport: Ironforge", 28); // 29
                      Menu->AddItem(2, "Teleport: Darnassus", 29); // 20
				     Menu->SendTo(Plr);
					}break;

				case 10: // Northrend Locations (Horde)
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(2, "Borean Tundra", 38);
						Menu->AddItem(2, "Dalaran", 35);
						Menu->AddItem(2, "DragonBlight", 40);
						Menu->AddItem(2, "Crystalsong Forest", 42);
						Menu->AddItem(2, "Grizzly Hills", 44);
						Menu->AddItem(2, "Howling Fjord", 46);
						Menu->AddItem(2, "Icecrown", 48);
						Menu->AddItem(2, "Sholazar Basin", 50);
						Menu->AddItem(2, "Storm Peaks", 52);
						//Menu->AddItem(2, "Wintergrasp", 54);
						Menu->AddItem(2, "Zul'Drak", 56);
						Menu->AddItem(2, "Northrend Instances", 37);
						Menu->SendTo(Plr);
					}break;

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

				case 12: // Custom Conan Port Locations (Horde)
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->SendTo(Plr);
					}break;

				case 15: // Northrend Locations (Alliance)
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->AddItem(2, "Borean Tundra", 39);
						Menu->AddItem(2, "Dalaran", 36);
						Menu->AddItem(2, "DragonBlight", 41);
						Menu->AddItem(2, "Crystalsong Forest", 43);
						Menu->AddItem(2, "Grizzly Hills", 45);
						Menu->AddItem(2, "Howling Fjord", 47);
						Menu->AddItem(2, "Icecrown", 49);
						Menu->AddItem(2, "Sholazar Basin", 51);
						Menu->AddItem(2, "Storm Peaks", 53);
						//Menu->AddItem(2, "Wintergrasp", 55);
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

				case 17: // Custom Conan Port Locations (Alliance)
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
						Menu->SendTo(Plr);
					}break;
				
				
				case 37: // Northrend Instances (Horde/Alliance)
					{
						objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
					     Menu->AddItem(3, "Azjol-Nerub: Ahn'kahet: The Old Kingdom", 75);
						 Menu->AddItem(3, "Azjol-Nerub: Azjol-Nerub", 76);
						 Menu->AddItem(3, "Caverns of Time: The Culling of Stratholme", 77); // Not Finished.
						 Menu->AddItem(3, "Drak'Tharon Keep", 78); // Not Finished.
						 Menu->AddItem(3, "Gundrak", 79); // Not Finished.
						 Menu->AddItem(3, "The Nexus: The Nexus", 80); // Not Finished.
						 Menu->AddItem(3, "The Nexus: The Oculus", 81); // Not Finished.
						 Menu->AddItem(3, "The Violet Hold", 82); // Not Finished.
						 Menu->AddItem(3, "Ulduar: Halls of Lightning", 83); // Not Finished.
						 Menu->AddItem(3, "Ulduar: Halls of Stone", 84); // Not Finished.
						 Menu->AddItem(3, "Utgarde Keep: Utgarde Keep", 85); // Not Finished.
						 Menu->AddItem(3, "Utgarde Keep: Utgarde Pinnacle", 86); // Not Finished.
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
						Menu->SendTo(Plr);
					}break;
			
                 case 4: // Show Online Players
				   {						
                    uint32 clientsNum = (uint32)sWorld.GetSessionCount();
                    Plr->BroadcastMessage("Current Players Online: %d", clientsNum);
                    Plr->Gossip_Complete();
				   }break;
				 
				 case 9: // Port to the mall
				 {
					Plr->EventTeleport(571, 8431.166992, 933.211365, 544.674500);
				 }break;

				 
				 case 14: // Mall
					 {
					Plr->EventTeleport(571, 8431.166992, 933.211365, 544.674500);
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

					case 26:
                      {
                        Plr->EventTeleport(1, -1304.569946, 205.285004, 68.681396);
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
								Plr->EventTeleport(571, 5449, -1442, 248);
							}break;

						case 57: // Zul'Drak Alliance
							{
								Plr->EventTeleport(571, 5449, -1442, 248);
							}break;

						case 58: //Blade's Edge Mountains Horde
                           {
                                Plr->EventTeleport(530, 2382.940, -5994.690, 151.7300);
                           }break;

						case 59: // Blade's Edge Mountains Alliance
							{
								Plr->EventTeleport(530, 2382.940, -5994.690, 151.7300);
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
								Plr->EventTeleport(530, -2987.89, 2565.330, 76.54310);
							}break;

						case 67: // Shadowmoon Valley Alliance
							{
								Plr->EventTeleport(530, -2987.89, 2565.330, 76.54310);
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
								Plr->EventTeleport(530, -2660.56, 4399.920, 36.92200);
							}break;

						case 71: // Terokkar Forest Alliance
							{
								Plr->EventTeleport(530, -2660.56, 4399.920, 36.92200);
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
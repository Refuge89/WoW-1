/* Database Reloader - By, Easelm.

    Sup! This is a database reloader(duh), any who, this item will basically reload
	your tables without you having to type .server reload blah blah. This is a lazy
	way, but it actually is a quick way. You can make macros, but macros can always
	dissappear out of nowhere, if you're playing retail or you had to reinstall -
	World of warcraft. Or by deleting your WTF folder because something has gotten
	errors. Either way this is a unique kinda thing, maybe not to you, but it is
	to me.
	You do not have permission to release this on another site, unless you get my
	permission first. You also do not have permission to use it in a repack, unless
	you have my permission first.
	
	Copyright (C) 2009, 
    7/16/09
	d2-link.org 
*/

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)
#endif

/* Item ID */
#define ReloaderID 86974


class SCRIPT_DECL Reloader : public GossipScript
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

		 void Reloader::GossipHello(Object* pObject, Player* Plr, bool AutoSend)
		 {
			 GossipMenu *Menu;
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			
		    if (!Plr->GetSession()->HasGMPermissions()) // Just incase it goes to the wrong hands.
              {
               Plr->BroadcastMessage("You're not a Gamemaster. So you cannot use this item.");
              }
                if (Plr->GetSession()->HasGMPermissions())
                  { 
			           Menu->AddItem(3, " Reload Items Table. ", 1);				   
                 		   Menu->AddItem(3, " Reload Creature Tables. ", 2); // static..
				   Menu->AddItem(3, " Reload Gameobject_names Table. ", 4);
				   Menu->AddItem(3, " Reload Areatriggers Table. ", 5);
				   Menu->AddItem(3, " Reload Itempages Table. ", 6);
				   Menu->AddItem(3, " Reload Worldstring_tables. ", 7);
				   Menu->AddItem(3, " Reload Worldbroadcast Table.", 8);
				   Menu->AddItem(3, " Reload Quests Table. ", 9);
				   Menu->AddItem(3, " Reload Npc_Text Table. ", 10);
				   Menu->AddItem(3, " Reload Fishing Table. ", 11);
				   Menu->AddItem(3, " Reload Teleport_Coords Table. ", 12);
				   Menu->AddItem(3, " Reload Graveyards Table.", 13);
				   Menu->AddItem(3, " Reload Worldmap_Info Table.", 14);
				   Menu->AddItem(3, " Reload Zoneguards Table. ", 15);
				   Menu->AddItem(3, " Reload Unit_display_size Table.", 16);
				   Menu->AddItem(3, " Reload Vendors Table. ", 17);

		if(AutoSend)
                      Menu->SendTo(Plr);
			 }
		}  
		

		 void Reloader::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
		 {
			GossipMenu *Menu;

			 switch(IntId)

			 {
				 case 1: // Items
					{
					    char itemmsg[200];
						snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''items''. Lag may occur during this reload.|r");
						sWorld.SendWorldText(itemmsg, 0);
						ItemPrototypeStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
					}break;

				 case 2: // Creature Tables
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''creature_names''. Lag may occur during this reload.|r");
                         sWorld.SendWorldText(itemmsg, 0);
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''creature_proto''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						CreatureProtoStorage.Reload();
						CreatureNameStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;
                    /*
					 case 3: // Creature_names
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''creature_names''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						CreatureNameStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;*/

					 case 4: // gameobject_names
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''gameobject_names''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						GameObjectNameStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 5: // Areatriggers
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''areatriggers''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						AreaTriggerStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 6: // itempages
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''itempages''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						ItemPageStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 7: // Worldstring_tables
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''worldstring_tables''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						WorldStringTableStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 8: // worldbroadcast
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''worldbroadcast''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						WorldBroadCastStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 9: // quests
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''quests''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						QuestStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 10: // npc_text
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''npc_text''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						NpcTextStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 11: // fishing
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''fishing''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						FishingZoneStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 12: // teleport_coords
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''teleport_coords''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						TeleportCoordStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 13: // graveyards
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''graveyards''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						GraveyardStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 14: // worldmap_info
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''worldmap_info''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						WorldMapInfoStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 15: // zoneguards
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''zoneguards''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						ZoneGuardStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 16: // unit_display_sizes
					 {
						 char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''unit_display_sizes''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						UnitModelSizeStorage.Reload();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					 case 17: // Vendors
						 {
						  char itemmsg[200];
						 snprintf(itemmsg, 200, "|cff6495EDRefreshing the cache of table ''Vendors''. Lag may occur during this reload.|r");
                        sWorld.SendWorldText(itemmsg, 0);
						objmgr.ReloadVendors();
						Plr->BroadcastMessage("|cff9ACD32 Please wait 10 seconds for your table to reload.|r");
						}break;

					case 30: // back to menue
				 {  
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			           Menu->AddItem(3, " Reload Items Table. ", 1);				   
                   		   Menu->AddItem(3, " Reload Creature Tables. ", 2); // static..
				   Menu->AddItem(3, " Reload Gameobject_names Table. ", 4);
				   Menu->AddItem(3, " Reload Areatriggers Table. ", 5);
				   Menu->AddItem(3, " Reload Itempages Table. ", 6);
				   Menu->AddItem(3, " Reload Worldstring_tables. ", 7);
				   Menu->AddItem(3, " Reload Worldbroadcast Table.", 8);
				   Menu->AddItem(3, " Reload Quests Table. ", 9);
				   Menu->AddItem(3, " Reload Npc_Text Table. ", 10);
				   Menu->AddItem(3, " Reload Fishing Table. ", 11);
				   Menu->AddItem(3, " Reload Teleport_Coords Table. ", 12);
				   Menu->AddItem(3, " Reload Graveyards Table.", 13);
				   Menu->AddItem(3, " Reload Worldmap_Info Table.", 14);
				   Menu->AddItem(3, " Reload Zoneguards Table. ", 15);
				   Menu->AddItem(3, " Reload Unit_display_size Table.", 16);
				   Menu->AddItem(3, " Reload Vendors Table. ", 17);
				   Menu->AddItem(3, " Reload creature_names Table. ", 18);
				   Menu->AddItem(3, " Reload creature_proto. ", 19);
                      			Menu->SendTo(Plr);
			 }break;

			 }
};

void Reloader::GossipEnd(Object* pObject, Player* Plr)
{
      
	GossipScript::GossipEnd(pObject, Plr);
        
}
      
void SetupReloader(ScriptMgr * mgr)
{
     GossipScript * gs = (GossipScript*) new Reloader();
     mgr->register_item_gossip_script(ReloaderID, gs);
}



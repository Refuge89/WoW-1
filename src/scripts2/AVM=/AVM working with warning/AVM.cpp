/*
 Automated Vendor Machine (AVM)
 
 Description:
 An NPC who, when talked to, allows you to enter an item NAME or ID, and will present you with all items matching that name or ID.
 The user is then able to purchase the found items.
 
 By Jotox/Classic
 
 Copyright (c) 2009
 */

//---------------------------
//CONFIG!!
//---------------------------

//Max item quality allowed to be purchased.
//Green = 2, Blue = 3, Epic = 4, Legendary = 5, Artifact(GM item) = 6, Heirloom = 7
#define MAX_QUALITY 4	//Default: Legendaries and above cannot be purchased. Epic and below can.

#define CREATE_QUESTSCRIPT(cl) (QuestScript*)new cl
#define CREATE_GOSSIPSCRIPT(cl) (GossipScript*)new cl
#define CREATE_GAMEOBJECT_SCRIPT(cl) &cl::Create
#define CREATE_CREATURESCRIPT(cl) &cl::Create


#define CreaturePointer				Creature *
#define UnitPointer					Unit *
#define PlayerPointer				Player *
#define GameObjectPointer			GameObject *
#define ObjectPointer				Object *
#define SpellPointer				Spell *
#define MapMgrPointer				MapMgr *
#define PetPointer					Pet *
#define AuraPointer					Aura *
#define ItemPointer					Item *
//Allow item sets (such as tier 7), conjured items, or quest items to be purchased?
//Default: no for all. Change the 0 to 1 to allow.
#define ALLOW_ITEM_SETS 0
#define ALLOW_CONJURED 0
#define ALLOW_QUEST 0
#define ALLOW_FREE 0
//Note: Free means no extended cost or gold cost. If you allow this, items which sell for more than they are purchased for will be allowed as well.

//Enable Extended Cost items. Disabling causes extended cost items to be free (unless you add a gold price to them in your database).
#define ENABLE_EXTENDED_COSTS 1

//Enable the banning of items via the "avm_banned_items" table.
#define ENABLE_ITEM_BANNING 1

//Maximum number of items found per search. Do not set above 100.
#define MAX_RESULTS 30	//Suggested value for efficiency.

//NPC ID
#define NPC_ID 993311

//Are you Arcemu? (Set to 1 if you're on arcemu. 0 for aspire.)
#define ARCEMU 0

//---------------------------
//END CONFIG -- Do not edit below this if you do not know what you're doing.
//---------------------------

#include "StdAfx.h"
#include "Setup.h"
using namespace std;

//Arcemu support.
#if ARCEMU > 0
typedef Object* ObjectPointer;
typedef Player* PlayerPointer;
typedef Unit* UnitPointer;
typedef Creature* CreaturePointer;
#define arcemu_TOLOWER(x) arcemu_TOLOWER(x)
#endif

map< uint32, bool> CItems;//Global list to keep track of items. Map should? be faster than vector looping for finding items in it. Not sure though. W/e.
map< uint32, uint32 > Extended_Cost_List;//List to keep track of extended cost.
map< uint32, bool > banned_items;//List to keep track of banned items.

void LoadItemTables()
{
	QueryResult * result;
	
	if( ENABLE_EXTENDED_COSTS )
	{
#if ARCEMU==0
		result = WorldDatabase.Query("SELECT DISTINCT item, extendedcost FROM vendors WHERE extendedcost > 0");
#else
		result = WorldDatabase.Query("SELECT DISTINCT item, extended_cost FROM vendors WHERE extended_cost > 0");
#endif
		if( !result )
			printf("(Automated Item Vendor): Error loading extended costs.");
		else
		{
			do 
			{
				uint32 id = result->Fetch()[0].GetUInt32();
				uint32 ec = result->Fetch()[1].GetUInt32();	
				if( dbcItemExtendedCost.LookupEntryForced(ec) )
					Extended_Cost_List[ id ] = ec;
				
			} while (result->NextRow());
			delete result;
		}
	}
	
	if( ENABLE_ITEM_BANNING )
	{
		result = WorldDatabase.Query("SELECT * FROM avm_banned_items");
		if( !result )
			printf("(Automated Item Vendor): Error loading banned items.");
		else
		{
			do 
			{
				banned_items[ result->Fetch()[0].GetUInt32() ] = true;
			} while (result->NextRow());
			
			delete result;
		}
	}
}

void AddItemsToCreature( CreaturePointer unit, vector<ItemPrototype*> &items )
{
	for( vector<ItemPrototype*>::iterator itr = items.begin(); itr != items.end(); itr++ )
	{
		if( !CItems[ (*itr)->ItemId ] )
		{
#if ARCEMU > 0
			unit->AddVendorItem( (*itr)->ItemId, (*itr)->MaxCount /*Full stack by default.*/,  ( (Extended_Cost_List[(*itr)->ItemId ] ) ? dbcItemExtendedCost.LookupEntryForced( Extended_Cost_List[ (*itr)->ItemId ] ) : NULL) );//If we don't add this, when the player tries to buy it will give an error.
else
			unit->AddVendorItem( (*itr)->ItemId, (*itr)->MaxCount /*Full stack by default.*/ );//If we don't add this, when the player tries to buy it will give an error.
			if( Extended_Cost_List[ (*itr)->ItemId ] )
			{
				CreatureItem ci;
				unit->GetSellItemByItemId( (*itr)->ItemId , ci);
				ci.extended_cost = dbcItemExtendedCost.LookupEntryForced( Extended_Cost_List[ (*itr)->ItemId ] );
			}
#endif
			
			CItems[ (*itr)->ItemId ] = true;//May as well just keep track of this, to prevent duplication.
		}
	}
}

void SendItemList( CreaturePointer unit, PlayerPointer plr, vector<ItemPrototype*> &items )//Sends a vendor window with only the items in the "items" vector
{
	if( items.size() < 1 )
		return;//.......we shouldn't get here.
	if( !unit || !plr || !plr->IsInWorld() || !plr->GetSession() )
		return;//AHH
	
	WorldPacket data(((items.size() * 28) + 9));	   // allocate
	
	data.SetOpcode( SMSG_LIST_INVENTORY );
	data << unit->GetGUID();
	data << uint8( 0 ); // placeholder for item count
	
	uint32 counter = 0;
	
	ItemPrototype * curItem;
	
	for( vector<ItemPrototype*>::iterator itr = items.begin(); itr != items.end(); itr++ )
	{
		curItem = *itr;
		data << (counter + 1);//Count
		data << curItem->ItemId;//Item id
		data << curItem->DisplayInfoID;//Display id
		data << int32(-1);//Available amount
		data << curItem->BuyPrice;//Buyprice
		data << int32(-1);			// ???
		data << curItem->MaxCount;
		
		if( Extended_Cost_List[ curItem->ItemId ] )
			data << Extended_Cost_List[ curItem->ItemId ];
		else
			data << uint32(0);//Extended cost
		
		counter++;
	}
	
	const_cast<uint8*>(data.contents())[8] = (uint8)counter;	// set count
	
	plr->GetSession()->SendPacket( &data );
}

bool stringtest( string thing )//Tests whether a string consists SOLELY of numbers or not. returns true if the string is all numbers.
{
	char str[256];
	sprintf(str, "%d", atoi(thing.c_str()) );//If the string stays the same when all non-number characters are removed, it's only numbrs. duh.
	return str == thing;
}

bool TestItem( ItemPrototype * it, PlayerPointer plr )
{
	if( !it )
		return false;
	
	if( !(ALLOW_ITEM_SETS) && it->ItemSet )//item sets
		return false;
	
	if( ( ( !(ALLOW_FREE) && (!it->BuyPrice) || it->BuyPrice < it->SellPrice) ) && !Extended_Cost_List[ it->ItemId ] )// free / sell for more than bought and no extended cost
		return false;
	
	if( it->Quality > MAX_QUALITY )//quality
		return false;
	
	if( (!(ALLOW_QUEST) && it->Flags & ITEM_FLAG_QUEST) || (!(ALLOW_CONJURED) && it->Flags & ITEM_FLAG_CONJURED) )//quest / conjured
		return false;
	
	if( !(ALLOW_QUEST) && it->QuestId )//Quest again
		return false;
	
	if( banned_items[ it->ItemId ] && !plr->GetSession()->HasGMPermissions() )//only GMs can get banned items.
		return false;
	
	return true;
}

void FindItem( UnitPointer unit, PlayerPointer plr, const char* nameC, vector<ItemPrototype*> &items )
{
	
	string name( nameC );
	
	int itemid = atoi(name.c_str());
	if( itemid && !(itemid==INT_MIN || itemid==INT_MAX) && stringtest(name) )
	{
		ItemPrototype * it = ItemPrototypeStorage.LookupEntry(itemid);//If it's just an item id, no point in using SQL. eh?
		
		if( it && TestItem(it, plr) )
			items.push_back(it);
		
		if( !items.size() )
			unit->SendChatMessageToPlayer(15, 0, "Your item was not found, or was not available for purchase. Please check you have the correct Item I.D. and try again.", plr);//Whisper, in universal language.
		
		return;
	}
	
	string x = name;
	arcemu_TOLOWER(x);
	if(x.length() < 4)
	{
		unit->SendChatMessageToPlayer(15, 0, "Please enter a name 4 or more letters in length.", plr);
		return;
	}
	
	ItemPrototype * it;
	uint32 count = 0;
	
	QueryResult * result = WorldDatabase.Query("SELECT entry FROM items WHERE quality <= %u %s AND name1 like '%s' ORDER BY quality DESC, itemlevel DESC LIMIT %u", MAX_QUALITY, ((ALLOW_ITEM_SETS) ? "" : "AND itemset = 0") ,("%" + WorldDatabase.EscapeString(x) + "%").c_str(), MAX_RESULTS );
	
	if( !result )
	{
		unit->SendChatMessageToPlayer(15, 0, "I'm sorry, I could not find your item. Please check the name and try again.", plr);
		return;
	}
	
	do 
	{
		uint32 entry = result->Fetch()[0].GetUInt32();
		it = ItemPrototypeStorage.LookupEntry( entry );
		
		if( !it || !TestItem(it, plr) )
			continue;
		
		items.push_back(it);
	} while (result->NextRow());
	
	delete result;	
	
	if( !items.size() )
		unit->SendChatMessageToPlayer(15, 0, "I'm sorry, that item is unavailable for purchase.", plr);
	
	return;
}

class SCRIPT_DECL AVM : public GossipScript
{
public:
	
    void GossipHello(ObjectPointer  pObject, PlayerPointer plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 44333220, plr);
		
#if ARCEMU == 0
		Menu->AddItem( 1, "Search for an item to purchase.", 1, true);
 		Menu->AddItem( 2, "Enter the Name or Item ID:",0,0);
#else
		Menu->AddItem( 1, "Search for an item to purchase.", 1, 1);
#endif
		
		Menu->AddItem( 0, "How does this vendor work?", 99);
		
        if(AutoSend)
            Menu->SendTo(plr);
    }
	
    void GossipSelectOption(ObjectPointer  pObject, PlayerPointer  plr, uint32 Id, uint32 IntId, const char * Code)
    {
		GossipMenu * Menu;
		switch (IntId)
		{
			case 99://Help pl0x
			{
				string msg = "This vendor is an automated vendor made for your benefit. Simply click on the first option in the menu and enter the name or ID of an item ";
				msg += "that you wish to purchase.";
				TO_UNIT(pObject)->SendChatMessageToPlayer(15, 0, msg.c_str(), plr);//Whisper, in universal language.
				TO_UNIT(pObject)->SendChatMessageToPlayer(15, 0, "I will then find all items with that name, and present them for you to purchase.", plr);
				GossipHello(pObject, plr, true);
			}break;
				
			default://We're looking for an item.
			{
				vector<ItemPrototype*> items;
				FindItem(TO_UNIT(pObject), plr, Code, items);
				if( !items.size() )
				{
					GossipHello(pObject, plr, true);
					return;
				}		
				
				AddItemsToCreature( TO_CREATURE( pObject ), items );//Add the items to the creature's vendor list, so the player can actually buy the items instead of just view them
				
				SendItemList( TO_CREATURE(pObject), plr, items );//Show him the list of items.
				
				items.clear();
			}break;
				
		}
	}
	
	void GossipEnd(ObjectPointer pObject, PlayerPointer Plr)
	{
		TO_UNIT(pObject)->SendChatMessageToPlayer(15, 0, "Thank you for using the Automated Item Vendor. Please Come Again!", Plr);//If you want, you may as well add your own message about voting on your server's website or somethin.
		Plr->CleanupGossipMenu();
	}
	
    void Destroy()
    {
        delete this;
    }
};


void SetupAVM(ScriptMgr * mgr)
{
    mgr->register_gossip_script(NPC_ID, (GossipScript*) new AVM() );
	
	LoadItemTables();
	
	printf("\nAutomated Item Vendor Loaded Successfully.\n");
}
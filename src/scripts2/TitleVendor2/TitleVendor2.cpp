//Scripted by lollardo
//Title Npc
//12 june 2009 22:23
//Feel free to share. But do not claim that its yours :)

#include "StdAfx.h"
#include "Setup.h"

#define CoinId	66088 //Event coin id change here for yours.
#define SellerId	99000085 //The Npc id
#define AmountOfCoins	5 // the amount of "coins" it costs :)

class SCRIPT_DECL TitleVendor2 : public GossipScript
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

void TitleVendor2::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
    GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 823920, Plr);
	Menu->AddItem(1, "Titles cost 5 Event coins each no more no less :) If you get to many titles the title bar can get full and you wont see em.");
	Menu->AddItem(9, "What do you have to offer?", 1);
	Menu->AddItem(5, "Goodbye!", 500);
	if(AutoSend)
    Menu->SendTo(Plr);
}

void TitleVendor2::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
		return;

    switch(IntId)
 {
    case 1:{
    GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 823920, Plr);
	Menu->AddItem(9, "Gladiator %s", 29);
	Menu->AddItem(9, "Duelist %s", 30);
	Menu->AddItem(9, "Rival %s", 31);
	Menu->AddItem(9, "Challenger %s", 32);
	Menu->AddItem(9, "Scarab Lord%s", 33);
	Menu->AddItem(9, "conqueror %s", 34);
	Menu->AddItem(9, "Justicar %s", 35);
	Menu->AddItem(9, "%s, Champion of the Naaru", 36);
	Menu->AddItem(9, "Merciless Gladiator %s", 37);
	Menu->AddItem(9, "%s of the Shattred Sun", 38);
	Menu->AddItem(9, "%s Hand of A'dal", 39);
	Menu->AddItem(9, "What more do you have?", 2);
	Menu->SendTo(Plr);
	          }break;

	case 2:{
    GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 823920, Plr);
	Menu->AddItem(9, "Vengeful Gladiator %s", 40);
	Menu->AddItem(9, "Battlemaster %s", 41);
	Menu->AddItem(9, "%s the Seeker", 42);
	Menu->AddItem(9, "Elder %s", 43);
	Menu->AddItem(9, "Flame Warden %s", 44);
	Menu->AddItem(9, "Flame Keeper %s", 45);
	Menu->AddItem(9, "%s the Exalted", 46);
	Menu->AddItem(9, "%s the Explorer", 47);
	Menu->AddItem(9, "%s the Diplomat", 48);
	Menu->AddItem(9, "Brutal Gladiator %s", 49);
	Menu->AddItem(9, "Arena Master %s", 50);
	Menu->AddItem(9, "Back", 1);
	Menu->AddItem(9, "What more do you have?", 3);
	Menu->SendTo(Plr);
	          }break;

	case 3:{
    GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 823920, Plr);
	Menu->AddItem(9, "Salty %s", 51);
	Menu->AddItem(9, "Chef %s", 52);
	Menu->AddItem(9, "%s the Supreme", 53);
	Menu->AddItem(9, "%s of the Ten Storms", 54);
	Menu->AddItem(9, "%s of the Emerald Dream", 55);
	Menu->AddItem(9, "Crusader %s", 56);
	Menu->AddItem(9, "Prophet %s", 57);
	Menu->AddItem(9, "%s the Malefic", 58);
	Menu->AddItem(9, "Stalker %s", 59);
	Menu->AddItem(9, "%s of the Ebon Blade", 60);
	Menu->AddItem(9, "Archmage %s", 61);
	Menu->AddItem(9, "Back", 2);
	Menu->AddItem(9, "What more do you have?", 4);
	Menu->SendTo(Plr);
	          }break;

	case 4:{
    GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 823920, Plr);
	Menu->AddItem(9, "Warbringer %s", 62);
	Menu->AddItem(9, "Assassin %s", 63);
	Menu->AddItem(9, "Grand Master Alchemist %s", 64);
	Menu->AddItem(9, "Grand Master Blacksmith %s", 65);
	Menu->AddItem(9, "Iron Chef %s", 66);
	Menu->AddItem(9, "Grand Master Enchanter %s", 67);
	Menu->AddItem(9, "Grand Master Engineer %s", 68);
	Menu->AddItem(9, "Doctor %s", 69);
	Menu->AddItem(9, "Grand Master Angler %s", 70);
	Menu->AddItem(9, "Grand Master Herbalist %s", 71);
	Menu->AddItem(9, "Grand Master Scribe %s", 72);
	Menu->AddItem(9, "Back", 3);
	Menu->AddItem(9, "What more do you have?", 5);
	Menu->SendTo(Plr);
	          }break;

	case 5:{
    GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 823920, Plr);
	Menu->AddItem(9, "Grand Master Jewelcrafter %s", 73);
	Menu->AddItem(9, "Grand Master Leathworker %s", 74);
	Menu->AddItem(9, "Grand Master Miner %s", 75);
	Menu->AddItem(9, "Grand Master Skinner %s", 76);
	Menu->AddItem(9, "Grand Master Tailor %s", 77);
	Menu->AddItem(9, "%s of Quel'Thalas", 78);
	Menu->AddItem(9, "%s of Argus", 79);
	Menu->AddItem(9, "%s of Khaz Modan", 80);
	Menu->AddItem(9, "%s of Gnomeregan", 81);
	Menu->AddItem(9, "%s of Lion Hearted", 82);
	Menu->AddItem(9, "%s, Champion of Elune", 83);
	Menu->AddItem(9, "Back", 4);
	Menu->AddItem(9, "What more do you have?", 6);
	Menu->SendTo(Plr);
	          }break;

    case 6:{
    GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 823920, Plr);
	Menu->AddItem(9, "%s, Hero of Orgrimmar", 84);
	Menu->AddItem(9, "Plainsrunner %s", 85);
	Menu->AddItem(9, "%s of the Darkspear", 86);
	Menu->AddItem(9, "%s the Forsaken", 87);
	Menu->AddItem(9, "%s the Magic Seeker", 88);
	Menu->AddItem(9, "Twillight Vanquisher %s", 89);
	Menu->AddItem(9, "%s, Conqueror of Naxxramas", 90);
	Menu->AddItem(9, "%s, Hero of Northrend", 91);
	Menu->AddItem(9, "%s the Hallowed", 92);
	Menu->AddItem(9, "Loremaster %s", 93);
	Menu->AddItem(9, "%s of the Alliance", 94);
	Menu->AddItem(9, "Back", 5);
	Menu->AddItem(9, "What more do you have?", 7);
	Menu->SendTo(Plr);
	          }break;

	case 7:{
    GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 823920, Plr);
	Menu->AddItem(9, "%s of the Horde", 95);
	Menu->AddItem(9, "%s the Flawless Victor", 96);
	Menu->AddItem(9, "%s, Champion of the Frozen Wastes", 97);
	Menu->AddItem(9, "Ambassador %s", 98);
	Menu->AddItem(9, "%s the Argent Champion", 99);
	Menu->AddItem(9, "%s, Guardian of Cenarius", 100);
	Menu->AddItem(9, "Brewmaster %s", 101);
	Menu->AddItem(9, "Merrymaker %s", 102);
	Menu->AddItem(9, "%s the Love Fool", 103);
	Menu->AddItem(9, "Matron %s", 104);
	Menu->AddItem(9, "Patron %s", 105);
	Menu->AddItem(9, "Back", 6);
	Menu->AddItem(9, "What more do you have?", 8);
	Menu->SendTo(Plr);
	          }break;

	case 8:{
    GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 823920, Plr);
	Menu->AddItem(9, "Obsidian Slayer %s", 106);
	Menu->AddItem(9, "%s of the Nightfall", 107);
	Menu->AddItem(9, "%s the Immortal", 108);
	Menu->AddItem(9, "%s the Undying", 109);
	Menu->AddItem(9, "%s Jenkins", 110);
	Menu->AddItem(9, "Bloodsail Admiral %s", 111);
	Menu->AddItem(9, "Back", 7);
	Menu->SendTo(Plr);
	          }break;

	case 29:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 29 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

	case 30:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 30 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 31:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 31 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 32:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 32 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 33:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 33 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 34:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 34 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 35:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 35 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 36:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 36 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 37:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 37 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 38:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 38 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 39:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 39 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 40:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 40 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 41:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 41 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 42:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 42 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 43:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 43 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 44:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 44 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 45:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 45 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 46:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 46 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 47:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 47 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 48:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 48 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 49:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 49 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 50:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 50 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 51:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 51 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 52:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 52 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 53:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 53 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 54:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 54 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 55:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 55 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 56:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 56 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 57:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 57 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 58:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 58 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 59:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 59 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 60:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 60 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 61:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 61 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 62:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 62 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 63:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 63 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 64:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 64 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 65:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 65 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 66:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 66 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 67:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 67 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 68:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 68 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 69:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 69 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 70:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 70 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 71:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 71 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 72:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 72 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 73:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 73 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 74:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 74 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 75:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 75 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 76:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 76 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 77:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 77 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 78:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 78 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 79:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 79 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

        case 80:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 80 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 81:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 81 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 82:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 82 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 83:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 83 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 84:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 84 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 85:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 85 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 86:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 86 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 87:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 87 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 88:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 88 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 89:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 89 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 90:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 90 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 91:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 91 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 92:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 92 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 93:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 93 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 94:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 94 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 95:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 95 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 96:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 96 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 97:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 97 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 98:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 98 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 99:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 99 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 100:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 100 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 101:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 101 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 102:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 102 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 103:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 103 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 104:{
	    {
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 104 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 105:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 105 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 106:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 106 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 107:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 107 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 108:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 108 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		       }break;

		case 109:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 109 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		         }break;

		case 110:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 110 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		         }break;

		case 111:{
		if (Plr->GetItemInterface()->GetItemCount(CoinId) >= AmountOfCoins)
		{
		Plr->GetItemInterface()->RemoveItemAmt(CoinId, AmountOfCoins);
		Plr->SetKnownTitle( static_cast< RankTitles >( 111 ), true );
		Plr->Gossip_Complete();
		}
		else
		{
		Plr->BroadcastMessage("You dont have Enough Coins");
		Plr->Gossip_Complete();
		}
		        }break;
		case 500:
	{Plr->Gossip_Complete();}
	break;
 }
}
};

void TitleVendor2::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}
void SetupTitleVendor2(ScriptMgr * mgr)
{
	GossipScript * TITLEVENDOR2 = (GossipScript*) new TitleVendor2();
	mgr->register_gossip_script(SellerId, TITLEVENDOR2);
}        


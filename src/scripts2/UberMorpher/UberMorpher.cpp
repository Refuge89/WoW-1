//Title of Script: WoW-Pwnage UberMorpher
//Description of Script: Morphs the player into Different Players.
//Author of this script: Phantamax
//Special thanks: Phantamax

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)        // warning C4305: 'argument' : truncation from 'double' to 'float'
#endif

  //Start of Script
class SCRIPT_DECL UberMorpher : public GossipScript
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
    void UberMorpher::GossipHello(Object* pObject, Player * Plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
		Menu->AddItem(2, "Welcome to WoW-Pwnage Uber Morpher");
		Menu->AddItem(0, "Lord Deathknight", 90);
		Menu->AddItem(0, "Deathknight", 2);
		Menu->AddItem(0, "Burning Beauty", 3);
		Menu->AddItem(0, "Red Wisp", 4);
		Menu->AddItem(0, "Necromancer", 5);
		Menu->AddItem(0, "Obidian Destroyer", 6);
		Menu->AddItem(0, "Rocket Chicken", 7);
		Menu->AddItem(0, "Magician", 8);
		Menu->AddItem(0, "Uber Deathguard", 9);
		Menu->AddItem(0, "Little Weapons", 10);
		Menu->AddItem(0, "Uber Meteor", 11);
		Menu->AddItem(0, "Giant Monster", 12);
		Menu->AddItem(5, "[Next Page]", 16);
		Menu->AddItem(2, "Demorph", 15);

           if(AutoSend)
            Menu->SendTo(Plr);
    }



//Defining Cases
void UberMorpher::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
    {
        GossipMenu * Menu;
        switch(IntId)
        {
            
        case 90:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 16508);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 2:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11072);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 3:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 23732);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 4:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 22729);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 5:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 16279);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 6:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11914);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 7:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 22903);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 8:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 22906);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 9:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 10546);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 10:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 22769);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;

        case 11:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 22814);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 12:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 21443);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 13:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 21467);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 15:
            {
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->DeMorph();
                Plr->Gossip_Complete();
            }break;


		case 16:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "Machine Guard", 17);
				Menu->AddItem(0, "Elite Guard", 18);
				Menu->AddItem(0, "Shadow Guard", 19);
				Menu->AddItem(0, "Illidari", 20);
				Menu->AddItem(0, "Sprit Healer", 21);
				Menu->AddItem(0, "Blazing Minion", 22);
				Menu->AddItem(0, "Shadow Minion", 23);
				Menu->AddItem(0, "Water Minion", 24);
				Menu->AddItem(0, "Light Minion", 25);
				Menu->AddItem(0, "Nightmare", 26);
				Menu->AddItem(0, "Pink Mage", 13);
				Menu->AddItem(5, "[Back]", 30);
				Menu->AddItem(2, "Demorph", 15);
				Menu->SendTo(Plr);
			}break;


        case 17:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 21349);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 18:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 21353);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 19:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 19070);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 20:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1912);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 21:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 5233);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 22:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 22748);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 23:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 10553);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 24:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 16216);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 25:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 16241);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


        case 26:
            {
                Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 16256);
                Plr->Emote(EMOTE_ONESHOT_CHEER);
                Plr->Gossip_Complete();
            }break;


		case 30:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(2, "Welcome to WoW-Pwnage Uber Morpher");
				Menu->AddItem(0, "Lord Deathknight", 90);
				Menu->AddItem(0, "Deathknight", 2);
				Menu->AddItem(0, "Burning Beauty", 3);
				Menu->AddItem(0, "Red Wisp", 4);
				Menu->AddItem(0, "Necromancer", 5);
				Menu->AddItem(0, "Obidian Destroyer", 6);
				Menu->AddItem(0, "Rocket Chicken", 7);
				Menu->AddItem(0, "Magician", 8);
				Menu->AddItem(0, "Uber Deathguard", 9);
				Menu->AddItem(0, "Little Weapons", 10);
				Menu->AddItem(0, "Uber Meteor", 11);
				Menu->AddItem(0, "Giant Monster", 12);
				Menu->AddItem(5, "[Next Page]", 16);
				Menu->AddItem(2, "Demorph", 15);
				Menu->SendTo(Plr);
			}break;


        }
};

void UberMorpher::GossipEnd(Object * pObject, Player* Plr)
{
GossipScript::GossipEnd(pObject, Plr);
}

void SetupUberMorpher(ScriptMgr * mgr)
{
GossipScript * gs = (GossipScript*) new UberMorpher();
mgr->register_item_gossip_script(99000084,gs);
}
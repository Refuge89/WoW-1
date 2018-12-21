#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)        // warning C4305: 'argument' : truncation from 'double' to 'float'
#endif

  
class SCRIPT_DECL Morph : public GossipScript
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
    void Morph::GossipHello(Object* pObject, Player * Plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
	     Menu->AddItem(0, "Which Morph You Want?", 10000);
	     Menu->AddItem(5, "Flesh Eater", 1);
	     Menu->AddItem(5, "Kobold Vermin", 2);
	     Menu->AddItem(5, "Benny Questgiver", 3);
	     Menu->AddItem(5, "Dragon Spawn", 4);
	     Menu->AddItem(5, "Forest Spider", 5);
	     Menu->AddItem(5, "Furbolg", 6);
	     Menu->AddItem(5, "Harvest Golem", 7);
	     Menu->AddItem(5, "Defias Thug", 8);
	     Menu->AddItem(5, "Kobold Miner", 9);
	     Menu->AddItem(5, "Mine Spider", 10);
	     Menu->AddItem(5, "Murloc Forager", 11);
	     Menu->AddItem(5, "Skeletal Warrior", 12);
		Menu->AddItem(0, "|cff800080Next|r", 14);

           if(AutoSend)
            Menu->SendTo(Plr);
    }




void Morph::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
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

        case 1://Flesh Eater
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 987);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 2://Kobold Vermin
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 10913);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 3://Benny Questgiver
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 6074);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 4://Dragon Spawn
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 143);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 5://Forest Spider
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 382);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 6://Furbolg
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 145);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 7://Harvest Golem
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 367);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 8://Defias Thug
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 5035);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 9://Kobold Miner
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 373);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 10://Mine Spider
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 368);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 11://Murloc Forager
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 441);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 12://Skeletal Warrior
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 200);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 13://Lesser Succubus
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 159);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;
	                
        case 14:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 27);
                Menu->AddItem(5, "Corina Steele", 15);
                Menu->AddItem(5, "Mean Ed the Blacksmith", 16);
                Menu->AddItem(5, "Ruklar the Trapper", 17);
                Menu->AddItem(5, "Thuros Lightfingers", 18);
                Menu->AddItem(5, "Gug Fatcandle", 19);
                Menu->AddItem(5, "Peasant Woman", 20);
                Menu->AddItem(5, "Tharynn Bouden", 21);
                Menu->AddItem(5, "Stormwind City Guard", 22);
                Menu->AddItem(5, "Timber Wolf", 23);
                Menu->AddItem(5, "Rankist", 24);
                Menu->AddItem(5, "Veraina the Apothecary", 25);
                Menu->AddItem(5, "Kurran Steele", 26);
		Menu->AddItem(0, "|cff800080Back|r", 999);

                Menu->SendTo(Plr);
				}
		break;


        case 15://Corina Steele
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1287);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 16://Mean Ed the Blacksmith
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 17);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 17://Ruklar the Trapper
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2153);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 18://Thuros Lightfingers
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3341);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 19://Gug Fatcandle
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 26);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 20://Peasant Woman
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 13);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 21://Tharynn Bouden
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1298);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 22://Stormwind City Guard
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3167);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 23://Timber Wolf
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 604);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 24://Rankist
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 137);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 25://Veraina the Apothecary
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 15);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 26://Kurran Steele
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1289);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 27:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 40);
                Menu->AddItem(5, "Janos Hammerknuckle", 28);
                Menu->AddItem(5, "Narg the Taskmaster", 29);
                Menu->AddItem(5, "Kobold Laborer", 30);
                Menu->AddItem(5, "Crazy Leonetti", 31);
                Menu->AddItem(5, "Forest Troll Berserker", 32);
                Menu->AddItem(5, "Infernal", 33);
                Menu->AddItem(5, "Sea Giant", 34);
                Menu->AddItem(5, "Rock Elemental", 35);
                Menu->AddItem(5, "Centaur", 36);
                Menu->AddItem(5, "Defias Cutpurse", 37);
                Menu->AddItem(5, "Defias Smuggler", 38);
                Menu->AddItem(5, "Riverpaw Runt", 39);
		Menu->AddItem(0, "|cff800080Back|r", 14);

                Menu->SendTo(Plr);
				}
		break;


        case 28://Janos Hammerknuckle
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3275);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 29://Narg the Taskmaster
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 774);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 30://Kobold Laborer
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 365);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 31://Crazy Leonetti
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 16);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 32://Forest Troll Berserker
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 167);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 33://Infernal
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 169);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 34://Sea Giant
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 791);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 35://Rock Elemental
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 171);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 36://Centaur
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 172);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 37://Defias Cutpurse
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2361);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 38://Defias Smuggler
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4418);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 39://Riverpaw Runt
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 10791);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 40:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 53);
                Menu->AddItem(5, "Riverpaw Taskmaster", 41);
                Menu->AddItem(5, "Morgaine the Sly", 42);
                Menu->AddItem(5, "Gruff Swiftbite", 43);
                Menu->AddItem(5, "Bronze Dragonspawn", 44);
                Menu->AddItem(5, "Garrick Padfoot", 45);
                Menu->AddItem(5, "Tall Strider", 46);
                Menu->AddItem(5, "Kodo Beast", 47);
                Menu->AddItem(5, "Raptor", 48);
                Menu->AddItem(5, "Green Dragonspawn", 49);
                Menu->AddItem(5, "White Dragonspawn", 50);
                Menu->AddItem(5, "Priest", 51);
                Menu->AddItem(5, "Priestess", 52);
		Menu->AddItem(0, "|cff800080Back|r", 27);

                Menu->SendTo(Plr);
				}
		break;


        case 41://Riverpaw Taskmaster
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 376);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 42://Morgaine the Sly
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3320);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 43://Gruff Swiftbite
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 177);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 44://Bronze Dragonspawn
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 177);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 45://Garrick Padfoot
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2073);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 46://Tall Strider
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 178);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 47://Kodo Beast
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 179);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 48://Raptor
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 180);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 49://Green Dragonspawn
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 181);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 50://White Dragonspawn
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 182);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 51://Priest
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 20);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 52://Priestess
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 14);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 53:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 67);
                Menu->AddItem(5, "Stonetusk Boar", 54);
                Menu->AddItem(5, "Harvest Watcher", 55);
                Menu->AddItem(5, "Harvest Reaper", 56);
                Menu->AddItem(5, "Defias Bandit", 57);
                Menu->AddItem(5, "Riverpaw Gnoll", 58);
                Menu->AddItem(5, "Prowler", 59);
                Menu->AddItem(5, "Longsnout", 60);
                Menu->AddItem(5, "Forest Stalker", 61);
                Menu->AddItem(5, "Defias Pathstalker", 62);
                Menu->AddItem(5, "Defias Highwayman", 63);
                Menu->AddItem(5, "Riverpaw Mongrel", 64);
                Menu->AddItem(5, "Riverpaw Brute", 65);
		Menu->AddItem(0, "|cff800080Back|r", 40);

                Menu->SendTo(Plr);
				}
		break;


        case 54://Stonetusk Boar
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 503);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 55://Harvest Watcher
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 378);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 56://Harvest Reaper
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 379);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 57://Defias Bandit
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2357);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 58://Riverpaw Gnoll
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 175);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 59://Prowler
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11415);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 60://Longsnout
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 381);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 61://Forest Stalker
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 366);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 62://Defias Pathstalker
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2336);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 63://Defias Highwayman
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2342);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 64://Riverpaw Mongrel
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 383);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 65://Riverpaw Brute
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 384);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 67:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 80);
                Menu->AddItem(5, "Riverpaw Overseer", 68);
                Menu->AddItem(5, "Murloc Coastrunner", 69);
                Menu->AddItem(5, "Murloc Tidehunter", 70);
                Menu->AddItem(5, "Angry Programmer Tweedle Dee", 71);
                Menu->AddItem(5, "Angry Programmer Tweedle Dum", 72);
                Menu->AddItem(5, "Programmer Vendor", 73);
                Menu->AddItem(5, "Brog Hamfist", 74);
                Menu->AddItem(5, "Brother Danil", 75);
                Menu->AddItem(5, "Bethina", 76);
                Menu->AddItem(5, "Greater Fleshripper", 77);
                Menu->AddItem(5, "Goretusk", 78);
                Menu->AddItem(5, "Morhan Coppertongue", 79);
		Menu->AddItem(0, "|cff800080Back|r", 53);

                Menu->SendTo(Plr);
				}
		break;


        case 68://Riverpaw Overseer
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 10790);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 69://Murloc Coastrunner
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 983);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 70://Murloc Tidehunter
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1995);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 71://Angry Programmer Tweedle Dee
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1415);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 72://Angry Programmer Tweedle Dum
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 138);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 73://Programmer Vendor
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 62);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 74://Brog Hamfist
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1292);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 75://Brother Danil
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3277);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 76://Bethina
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 14947);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 77://Greater Fleshripper
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1105);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 78://Goretusk
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3027);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 79://Morhan Coppertongue
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1844);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 80:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 93);
                Menu->AddItem(5, "Murloc Warrior", 81);
                Menu->AddItem(5, "Dermot Johns", 82);
                Menu->AddItem(5, "Ice Troll", 83);
                Menu->AddItem(5, "Blue Dragonspawn", 84);
                Menu->AddItem(5, "Eagan Peltskinner", 85);
                Menu->AddItem(5, "Marshal McBride", 86);
                Menu->AddItem(5, "Khelden Breme", 87);
                Menu->AddItem(5, "Young Fleshripper", 88);
                Menu->AddItem(5, "Brittlebones Skeleton", 89);
                Menu->AddItem(5, "Skeletal Horror", 90);
                Menu->AddItem(5, "Skeletal Mage", 91);
                Menu->AddItem(5, "Nightbane Dark Runner", 92);
		Menu->AddItem(0, "|cff800080Back|r", 67);

                Menu->SendTo(Plr);
				}
		break;


        case 81://Murloc Warrior
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1305);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 82://Dermot Johns
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3276);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 83://Ice Troll
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 195);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 84://Blue Dragonspawn
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 196);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 85://Eagan Peltskinner
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3251);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 86://Marshal McBride
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1859);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 87://Khelden Bremen
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 5001);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 88://Young Fleshripper
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 410);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 89://Brittlebones Skeleton
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 11400);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 90://Skeletal Horror
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 9786);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 91://Skeletal Mage
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 9783);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 92://Nightbane Dark Runner
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 736);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 93:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 106);
                Menu->AddItem(5, "Nightbane Vile Fang", 94);
                Menu->AddItem(5, "Bone Chewer", 95);
                Menu->AddItem(5, "Ogre", 96);
                Menu->AddItem(5, "Splinter Fist Warrior", 97);
                Menu->AddItem(5, "Starving Dire Wolf", 98);
                Menu->AddItem(5, "Defias Night Runner", 99);
                Menu->AddItem(5, "Venom Web Spider", 100);
                Menu->AddItem(5, "Grave Robber", 101);
                Menu->AddItem(5, "Dannus", 102);
                Menu->AddItem(5, "Nillen Andemar", 103);
                Menu->AddItem(5, "Dan Golthas", 104);
                Menu->AddItem(5, "Zek Marston", 105);
		Menu->AddItem(0, "|cff800080Back|r", 80);

                Menu->SendTo(Plr);
				}
		break;


        case 94://Nightbane Vile Fang
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 522);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 95://Bone Chewer
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 570);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 96://Ogre
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 415);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 97://Splinter Fist Warrior
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 610);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 98://Starving Dire Wolf
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 801);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 99://Defias Night Runner
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4276);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 100://Venom Web Spider
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 955);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 101://Grave Robber
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4275);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 102://Dannus
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 23);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 103://Nillen Andemar
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1845);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 104://Dan Golthas
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 10619);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 105://Zek Marston
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 20);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 106:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 119);
                Menu->AddItem(5, "Gavin Gnarltree", 107);
                Menu->AddItem(5, "Morg Gnarltree", 108);
                Menu->AddItem(5, "Mabel Solaj", 109);
                Menu->AddItem(5, "Avette Fellwood", 110);
                Menu->AddItem(5, "Vaious", 111);
                Menu->AddItem(5, "Thornton Fellwood", 112);
                Menu->AddItem(5, "Farmer Ray", 113);
                Menu->AddItem(5, "Farmer Saldean", 114);
                Menu->AddItem(5, "Gryan Stoutmantle", 115);
                Menu->AddItem(5, "Salma Saldean", 116);
                Menu->AddItem(5, "Farmer Furlbrow", 117);
                Menu->AddItem(5, "Verna Furlbrow", 118);
		Menu->AddItem(0, "|cff800080Back|r", 93);

                Menu->SendTo(Plr);
				}
		break;


        case 107://Gavin Gnarltree
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4331);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 108://Morg Gnarltree
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4332);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 109://Mabel Solaj
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4340);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 110://Avette Fellwood
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4334);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 111://Vaious
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 17);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 112://Thornton Fellwood
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4335);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 113://Farmer Ray
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3614);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 114://Farmer Saldean
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1943);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 115://Gryan Stoutmantle
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1690);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 116://Salma Saldean
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1691);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 117://Farmer Furlbrow
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1944);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 118://Verna Furlbrow
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1692);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 119:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 132);
                Menu->AddItem(5, "Grimbooze Thunderbrew", 120);
                Menu->AddItem(5, "Marshal Dughan", 121);
                Menu->AddItem(5, "Remy, Two Times", 122);
                Menu->AddItem(5, "Horras Brackwell", 123);
                Menu->AddItem(5, "Ma Stonefield", 124);
                Menu->AddItem(5, "Auntie, Bernice Stonefield", 125);
                Menu->AddItem(5, "Billy Maclure", 126);
                Menu->AddItem(5, "Gramma Stonefield", 127);
                Menu->AddItem(5, "Pa Maclure", 128);
                Menu->AddItem(5, "Maybell Maclure", 129);
                Menu->AddItem(5, "Tommy Joe Stonefield", 130);
                Menu->AddItem(5, "William Pestle", 131);
		Menu->AddItem(0, "|cff800080Back|r", 106);

                Menu->SendTo(Plr);
				}
		break;


        case 120://Grimbooze Thunderbrew
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3265);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 121://Marshal Dughan
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1985);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 122://Remy \"Two Times
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3254);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 123://Horras Brackwell
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 214);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 124://Ma Stonefield
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3330);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 125://Auntie, Bernice Stonefield
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3329);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 126://Billy Maclure
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 221);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 127://Gramma Stonefield
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2959);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 128://Pa Maclure
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3327);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 129://Maybell Maclure
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3323);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 130://Tommy Joe Stonefield
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3331);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 131://William Pestle
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 5038);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 132:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 145);
                Menu->AddItem(5, "Gerard Tiller", 133);
                Menu->AddItem(5, "Kobold Worker", 134);
                Menu->AddItem(5, "Joshua Maclure", 135);
                Menu->AddItem(5, "Guard Thomas", 136);
                Menu->AddItem(5, "Half-eaten body", 137);
                Menu->AddItem(5, "Lord Ello Ebonlocke", 138);
                Menu->AddItem(5, "Commander Althea Ebonlocke", 139);
                Menu->AddItem(5, "Madame Eva", 140);
                Menu->AddItem(5, "Wiley the Black", 141);
                Menu->AddItem(5, "Clerk Daltry", 142);
                Menu->AddItem(5, "Sirra Von\'Indi", 143);
                Menu->AddItem(5, "Role Dreuger", 144);
		Menu->AddItem(0, "|cff800080Back|r", 119);

                Menu->SendTo(Plr);
				}
		break;


        case 133://Gerard Tiller
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3324);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 134://Kobold Worker
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 10912);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 135://Joshua Maclure
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3328);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 136://Guard Thomas
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1984);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 137://Half-eaten body
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 433);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 138://Lord Ello Ebonlocke
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4321);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 139://Commander Althea Ebonlocke
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4322);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 140://Madame Eva
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4323);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 141://Wiley the Blac
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1741);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 142://Clerk Daltry
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1720);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 143://Sirra Von\'Indi
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4324);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 144://Role Dreuger
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4309);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 145:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 158);
                Menu->AddItem(5, "Councilman Millstipe", 146);
                Menu->AddItem(5, "Ambassador Berrybuck", 147);
                Menu->AddItem(5, "Chef Grual", 148);
                Menu->AddItem(5, "Tavernkeep Smitts", 149);
                Menu->AddItem(5, "Barkeep Hann", 150);
                Menu->AddItem(5, "Whit Wantmal", 151);
                Menu->AddItem(5, "Viktori Prism\'Antras", 152);
                Menu->AddItem(5, "Roberto Pupellyverbos", 153);
                Menu->AddItem(5, "Sara Timberlain", 154);
                Menu->AddItem(5, "Morgan Pestle", 155);
                Menu->AddItem(5, "Placeholder - Jasperlode Mine", 156);
                Menu->AddItem(5, "Kobold Tank", 157);
		Menu->AddItem(0, "|cff800080Back|r", 132);

                Menu->SendTo(Plr);
				}
		break;


        case 146://Councilman Millstipe
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1724);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 147://Ambassador Berrybuck
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1713);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 148://Chef Grual
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1715);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 149://Tavernkeep Smitts
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1731);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 150://Barkeep Hann
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 5039);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 151://Whit Wantmal
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1734);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 152://Viktori Prism\'Antras
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4326);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 153://Roberto Pupellyverbos
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1433);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 154://Sara Timberlain
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3268);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 155://Morgan Pestle
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 5082);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 156://Placeholder - Jasperlode Mine
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 68);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 157://Kobold Tank
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 139);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 158:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 171);
                Menu->AddItem(5, "Kobold Spellcaster", 159);
                Menu->AddItem(5, "Kobold Healer", 160);
                Menu->AddItem(5, "Riding Horse (Brown)", 161);
                Menu->AddItem(5, "Murloc", 162);
                Menu->AddItem(5, "Old Rotten Gill", 163);
                Menu->AddItem(5, "Placeholder - Darkhollow Mine", 164);
                Menu->AddItem(5, "Jitters", 165);
                Menu->AddItem(5, "Abercrombie", 166);
                Menu->AddItem(5, "Placeholder - Fargodeep Mine", 167);
                Menu->AddItem(5, "Placeholder Chest of Drawers", 168);
                Menu->AddItem(5, "Marshal Haggard", 169);
                Menu->AddItem(5, "Innkeeper Farley", 170);
		Menu->AddItem(0, "|cff800080Back|r", 145);

                Menu->SendTo(Plr);
				}
		break;


        case 159://Kobold Spellcaster
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 139);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 160://Kobold Healer
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 139);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 161://Riding Horse (Brown)
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2404);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 162://Murloc
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 617);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 163://Old Rotten Gill
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 346);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 164://Placeholder - Darkhollow Mine
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 68);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 165://Jitters
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4325);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 166://Abercrombie
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4328);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 167://Placeholder - Fargodeep Mine
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 68);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 168://Placeholder Chest of Drawers
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 31);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 169://Marshal Haggard
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1689);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 170://Innkeeper Farley
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1291);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 171:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 183);
                Menu->AddItem(5, "Caretaker Folsom", 172);
                Menu->AddItem(5, "Young Wolf", 173);
                Menu->AddItem(5, "Zzarc\' Vul", 174);
                Menu->AddItem(5, "Blind Mary", 175);
                Menu->AddItem(5, "Placeholder Interactive Doodad - jk", 176);
                Menu->AddItem(5, "Riding Horse (Felsteed)", 177);
                Menu->AddItem(5, "Riding Horse (White Stallion)", 178);
                Menu->AddItem(5, "Riding Horse (Palomino)", 179);
                Menu->AddItem(5, "Riding Horse (Pinto)", 180);
                Menu->AddItem(5, "Riding Horse (Black Stallion)", 181);
                Menu->AddItem(5, "Rolf\'s corpse", 182);
                Menu->AddItem(5, "Sven Yorgen", 183);
		Menu->AddItem(0, "|cff800080Back|r", 158);

                Menu->SendTo(Plr);
				}
		break;


        case 172://Caretaker Folsom
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1756);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 173://Young Wolf
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 447);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 174://Zzarc\' Vul
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 655);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 175://Blind Mary
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 915);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 176://Placeholder Interactive Doodad - jk
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 38);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 177://Riding Horse (Felsteed)
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2346);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 178://Riding Horse (White Stallion)
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2410);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 179://Riding Horse (Palomino)
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2408);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 180://Riding Horse (Pinto)
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2409);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 181://Riding Horse (Black Stallion)
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2402);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 182://Rolf\'s corpse
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 433);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 183://Sven Yorgen
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4327);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 184:     // 
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
				Menu->AddItem(0, "|cff800080Next|r", 196);
                Menu->AddItem(5, "Theocritus", 185);
                Menu->AddItem(5, "Eliza", 186);
                Menu->AddItem(5, "Stalvan Mistmantle", 187);
                Menu->AddItem(5, "Hogan Ference", 188);
                Menu->AddItem(5, "Goldtooth", 189);
                Menu->AddItem(5, "Zaldimar Wefhellt", 190);
                Menu->AddItem(5, "Earth Elemental", 191);
                Menu->AddItem(5, "Princess", 192);
                Menu->AddItem(5, "Maginor Dumas", 193);
                Menu->AddItem(5, "Master Mathias Shaw", 194);
                Menu->AddItem(5, "Gath\'Ilzogg", 195);
                Menu->AddItem(5, "Singe", 196);
		Menu->AddItem(0, "|cff800080Back|r", 171);

                Menu->SendTo(Plr);
				}
		break;


        case 185://Theocritus
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 3348);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 186://Eliza
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 10487);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 187://Stalvan Mistmantle
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1562);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 188://Hogan Ference
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 4320);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 189://Goldtooth
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 2299);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 190://Zaldimar Wefhellt
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1294);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 191://Earth Elemental
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 453);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 192://Princess
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 8871);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 193://Maginor Dumas
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1484);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 194://Master Mathias Shaw
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1736);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 195://Gath\'Ilzogg
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 6050);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 196://Singe
        {
        Plr->SetUInt32Value(UNIT_FIELD_DISPLAYID, 497);
        Plr->Emote(EMOTE_ONESHOT_CHEER);
        Plr->Gossip_Complete();
        }break;

        case 999:     //Main
                {
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
	     Menu->AddItem(0, "Which Morph You Want?", 10000);
	     Menu->AddItem(5, "Flesh Eater", 1);
	     Menu->AddItem(5, "Kobold Vermin", 2);
	     Menu->AddItem(5, "Benny Questgiver", 3);
	     Menu->AddItem(5, "Dragon Spawn", 4);
	     Menu->AddItem(5, "Forest Spider", 5);
	     Menu->AddItem(5, "Furbolg", 6);
	     Menu->AddItem(5, "Harvest Golem", 7);
	     Menu->AddItem(5, "Defias Thug", 8);
	     Menu->AddItem(5, "Kobold Miner", 9);
	     Menu->AddItem(5, "Mine Spider", 10);
	     Menu->AddItem(5, "Murloc Forager", 11);
	     Menu->AddItem(5, "Skeletal Warrior", 12);
		Menu->AddItem(0, "|cff800080Next|r", 14);

                Menu->SendTo(Plr);
				}
		break;


        }
};

void Morph::GossipEnd(Object * pObject, Player* Plr)
{
GossipScript::GossipEnd(pObject, Plr);
}

void SetupMorph(ScriptMgr * mgr)
{
GossipScript * gs = (GossipScript*) new Morph();
mgr->register_gossip_script(99000082,gs);
}
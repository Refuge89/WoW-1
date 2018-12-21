#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)
#endif

class SCRIPT_DECL Professions : public GossipScript
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

void Professions::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
	GossipMenu *Menu;
	objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
	Menu->AddItem(0, "Alchemist", 1);
	Menu->AddItem(0, "Blacksmith", 2);
	Menu->AddItem(5, "Enchanter", 3);
	Menu->AddItem(0, "Engineer", 4);
	Menu->AddItem(5, "Herbalist", 5);
	Menu->AddItem(5, "Jewelcrafter", 6);
	Menu->AddItem(0, "Leatherworker", 7);
	Menu->AddItem(5, "Miner", 8);
	Menu->AddItem(5, "Scribe", 9);
	Menu->AddItem(5, "Skinner", 10);
	Menu->AddItem(0, "Tailor", 11);
	Menu->AddItem(0, "Secondary Skills", 20);

	if(AutoSend)
		Menu->SendTo(Plr);
}

void Professions::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
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

	case 1://Alchelmy Menu
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Alchelmy", 31);
			Menu->AddItem(5, "Potion Master", 32);
			Menu->AddItem(5, "Transmutation", 33);
			Menu->AddItem(5, "Elixir master", 34);
			Menu->AddItem(0, "Back", 30);
			Menu->SendTo(Plr);
		}
		break;

	case 2://Blacksmith Menu
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Blacksmith", 35);
			Menu->AddItem(5, "Armorsmith", 36);
			Menu->AddItem(5, "Weaponsmith", 37);
			Menu->AddItem(5, "Swordsmith", 38);
			Menu->AddItem(5, "Axesmith", 39);
			Menu->AddItem(5, "Hammersmith", 40);
			Menu->AddItem(0, "Back", 30);

			Menu->SendTo(Plr);
		}
		break;

	case 3://Enchanter
		{
			Plr->CastSpell(Plr, 51312, true);
			Plr->_AdvanceSkillLine(333, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 4://Engineer Menu
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Engineer", 41);
			Menu->AddItem(5, "Gnomish", 42);
			Menu->AddItem(5, "Goblin", 43);
			Menu->AddItem(0, "Back", 30);
			Menu->SendTo(Plr);
		}
		break;

	case 5://Herbalist
		{
			Plr->CastSpell(Plr, 50301, true);
			Plr->_AdvanceSkillLine(182, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 6://Jewelcrafter
		{
			Plr->CastSpell(Plr, 51310, true);
			Plr->_AdvanceSkillLine(755, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 7://Leatherworker Menu
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Leatherworker", 44);
			Menu->AddItem(5, "Dragonscale", 45);
			Menu->AddItem(5, "Elemental", 46);
			Menu->AddItem(5, "Tribal", 47);
			Menu->AddItem(0, "Back", 30);
			Menu->SendTo(Plr);
		}
		break;

	case 8://Miner
		{
			Plr->CastSpell(Plr, 50309, true);
			Plr->_AdvanceSkillLine(186, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 9://Scribe
		{
			Plr->CastSpell(Plr, 45380, true);
			Plr->_AdvanceSkillLine(773, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 10://Skinner
		{
			Plr->CastSpell(Plr, 50307, true);
			Plr->_AdvanceSkillLine(393, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 11://Tailor Menu
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Tailor", 48);
			Menu->AddItem(5, "Mooncloth", 49);
			Menu->AddItem(5, "Shadowcloth", 50);
			Menu->AddItem(5, "Spellfire", 51);
			Menu->AddItem(0, "Back", 30);
			Menu->SendTo(Plr);
		}
		break;

	case 20://Secondary Skills Menu
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(5, "Cook", 21);
			Menu->AddItem(5, "First Aid", 22);
			Menu->AddItem(5, "Fishing", 23);
			Menu->AddItem(5, "Riding", 24);
			Menu->AddItem(5, "Cold Weather Flying", 25);
			Menu->AddItem(0, "Back", 30);

			Menu->SendTo(Plr);
		}
		break;

	case 21://Cook
		{
			Plr->CastSpell(Plr, 51295, true);
			Plr->_AdvanceSkillLine(185, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 22://First Aid
		{
			Plr->CastSpell(Plr, 50299, true);
			Plr->_AdvanceSkillLine(129, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 23://Fishing
		{
			Plr->CastSpell(Plr, 51293, true);
			Plr->_AdvanceSkillLine(356, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 24://Riding
		{
			Plr->CastSpell(Plr, 34093, true);
			Plr->_AdvanceSkillLine(762, 300);
			Plr->Gossip_Complete();
		}
		break;

	case 25://Cold Weather Flying
		{
			Plr->addSpell(54197);
			Plr->Gossip_Complete();
		}
		break;

	case 30://Back
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
			Menu->AddItem(0, "Alchemist", 1);
			Menu->AddItem(0, "Blacksmith", 2);
			Menu->AddItem(5, "Enchanter", 3);
			Menu->AddItem(0, "Engineer", 4);
			Menu->AddItem(5, "Herbalist", 5);
			Menu->AddItem(5, "Jewelcrafter", 6);
			Menu->AddItem(0, "Leatherworker", 7);
			Menu->AddItem(5, "Miner", 8);
			Menu->AddItem(5, "Scribe", 9);
			Menu->AddItem(5, "Skinner", 10);
			Menu->AddItem(0, "Tailor", 11);
			Menu->AddItem(0, "Secondary Skills", 20);

			Menu->SendTo(Plr);
		}
		break;

	case 31://Alchelmy
		{
			Plr->CastSpell(Plr, 51303, true);
			Plr->_AdvanceSkillLine(171, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 32://Potion Master
		{
			Plr->addSpell(28676);
			Plr->Gossip_Complete();
		}
		break;

	case 33://Transmutation
		{
			Plr->addSpell(28674);
			Plr->Gossip_Complete();
		}
		break;

	case 34://Elixir Master
		{
			Plr->addSpell(28678);
			Plr->Gossip_Complete();
		}
		break;

	case 35://Blacksmith
		{
			Plr->CastSpell(Plr, 51298, true);
			Plr->_AdvanceSkillLine(164, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 36://Armorsmith
		{
			Plr->addSpell(9790);
			Plr->Gossip_Complete();
		}
		break;

	case 37://Weaponsmith
		{
			Plr->addSpell(9789);
			Plr->Gossip_Complete();
		}
		break;

	case 38://Swordsmith
		{
			Plr->addSpell(39097);
			Plr->Gossip_Complete();
		}
		break;

	case 39://Axesmith
		{
			Plr->addSpell(39098);
			Plr->Gossip_Complete();
		}
		break;

	case 40://Hammersmith
		{
			Plr->addSpell(39099);
			Plr->Gossip_Complete();
		}
		break;

	case 41://Engineer
		{
			Plr->CastSpell(Plr, 51305, true);
			Plr->_AdvanceSkillLine(202, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 42://Gnomish
		{
			Plr->addSpell(20220);
			Plr->Gossip_Complete();
		}
		break;

	case 43://Goblin
		{
			Plr->addSpell(20221);
			Plr->Gossip_Complete();
		}
		break;

	case 44://Leatherworker
		{
			Plr->CastSpell(Plr, 51301, true);
			Plr->_AdvanceSkillLine(165, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 45://Dragonscale
		{
			Plr->addSpell(10657);
			Plr->Gossip_Complete();
		}
		break;

	case 46://Elemental
		{
			Plr->addSpell(10659);
			Plr->Gossip_Complete();
		}
		break;

	case 47://Tribal
		{
			Plr->addSpell(10661);
			Plr->Gossip_Complete();
		}
		break;

	case 48://Tailor
		{
			Plr->CastSpell(Plr, 51308, true);
			Plr->_AdvanceSkillLine(197, 450);
			Plr->Gossip_Complete();
		}
		break;

	case 49://Mooncloth
		{
			Plr->addSpell(26799);
			Plr->Gossip_Complete();
		}
		break;

	case 50://Shadowcloth
		{
			Plr->addSpell(26800);
			Plr->Gossip_Complete();
		}
		break;

	case 51://Spellfire
		{
			Plr->addSpell(26796);
			Plr->Gossip_Complete();
		}
		break;
	}
}

void Professions::GossipEnd(Object * pObject, Player* Plr)
{
	GossipScript::GossipEnd(pObject, Plr);
}

void SetupProfessions(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new Professions();
	mgr->register_gossip_script(90000023,gs);
}
//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)// warning C4305: 'argument' : truncation from 'double' to 'float'
#endif


class SCRIPT_DECL MaxSkill : public GossipScript
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
void MaxSkill::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
		{
		Menu->AddItem(9, "Advance All Weapon Skills", 1);
		}
		if(AutoSend)
            Menu->SendTo(Plr);
    }

void MaxSkill::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
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
				case 1: // Advance Weapon Skills
		{
		if (Plr->_HasSkillLine(43))
			{Plr->_AdvanceSkillLine(43, 1775);}
		if (Plr->_HasSkillLine(55))
			{Plr->_AdvanceSkillLine(55, 1775);}
		if (Plr->_HasSkillLine(44))
			{Plr->_AdvanceSkillLine(44, 1775);}
		if (Plr->_HasSkillLine(95))
			{Plr->_AdvanceSkillLine(95, 1775);}
		if (Plr->_HasSkillLine(54))
			{Plr->_AdvanceSkillLine(54, 1775);}
		if (Plr->_HasSkillLine(45))
			{Plr->_AdvanceSkillLine(45, 1775);}
		if (Plr->_HasSkillLine(46))
			{Plr->_AdvanceSkillLine(46, 1775);}
		if (Plr->_HasSkillLine(136))
			{Plr->_AdvanceSkillLine(136, 1775);}
		if (Plr->_HasSkillLine(160))
			{Plr->_AdvanceSkillLine(160, 1775);}
		if (Plr->_HasSkillLine(162))
			{Plr->_AdvanceSkillLine(162, 1775);}
		if (Plr->_HasSkillLine(172))
			{Plr->_AdvanceSkillLine(172, 1775);}
		if (Plr->_HasSkillLine(173))
			{Plr->_AdvanceSkillLine(173, 1775);}
		if (Plr->_HasSkillLine(176))
			{Plr->_AdvanceSkillLine(176, 1775);}
		if (Plr->_HasSkillLine(226))
			{Plr->_AdvanceSkillLine(226, 1775);}
		if (Plr->_HasSkillLine(228))
			{Plr->_AdvanceSkillLine(228, 1775);}
		if (Plr->_HasSkillLine(229))
			{Plr->_AdvanceSkillLine(229, 1775);}
		if (Plr->_HasSkillLine(473))
			{Plr->_AdvanceSkillLine(473, 1775);}
			Plr->BroadcastMessage("Weapon skills are now completed!");
			Plr->Gossip_Complete();
			}
 }
 }

void MaxSkill::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupMaxSkill(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new MaxSkill();
    mgr->register_gossip_script(90000003, gs);
}

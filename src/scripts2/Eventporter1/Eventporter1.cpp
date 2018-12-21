//Projectfile remade by Keazain

#include "StdAfx.h"
#include "Setup.h"
#include <iostream>
#include <vector>

using namespace std;

#ifdef WIN32
    #pragma warning(disable:4305)        // warning C4305: 'argument' : truncation from 'double' to 'float'
#endif

#define MAX_ENTRIES 80

class SCRIPT_DECL Warper2 : public GossipScript
{
  public:
    void GossipHello(Object * pObject, Player* Plr, bool AutoSend);
    void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);
    void GossipEnd(Object * pObject, Player* Plr);

  private:
    void GetTeleportEntries(uint32 creature,uint32 parent,std::vector<ct_entry> &entries);
    void GetTeleportEntry(uint32 creature,uint32 id, ct_entry &entry);
    bool CanDisplay(ct_entry entry, Player * Plr);
    bool ProcessEntryData(uint32 creature,QueryResult * res,ct_entry &entry);
    bool IsValid(QueryResult * res);
};

void Warper2::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
    {
        Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
        if(pCreature==NULL)
                return;

        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);
	std::vector<ct_entry> entries;
        GetTeleportEntries(pCreature->GetEntry(),0,entries);

	for(std::vector<ct_entry>::iterator itEntry = entries.begin(); itEntry != entries.end(); itEntry++)
	{
		ct_entry entry = *(itEntry);

		if (CanDisplay(entry,Plr))
                        Menu->AddItem(entry.icon,entry.gossip,entry.menuid);
	
	}

        if(AutoSend)
            Menu->SendTo(Plr);

    }

void Warper2::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
	Creature * pCreature = (pObject->GetTypeId()==TYPEID_UNIT)?((Creature*)pObject):NULL;
	if(pCreature==NULL)
		return;

	if (IntId == 9999)
	{
		GossipHello(pObject,Plr,true);
		return;
	}

	ct_entry entry;
	GetTeleportEntry(pCreature->GetEntry(),IntId,entry);

	if (entry.hasChildren)
	{
        	GossipMenu * Menu;
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr);

		std::vector<ct_entry> entries;
		GetTeleportEntries(pCreature->GetEntry(),IntId,entries);
       		std::vector<ct_entry>::iterator itEntry;
       		for(itEntry = entries.begin(); itEntry != entries.end(); itEntry++)
       		{
               		ct_entry entry = *(itEntry);

               		if (CanDisplay(entry,Plr))
                       		Menu->AddItem(entry.icon,entry.gossip,entry.menuid);
       		}

		if (IntId > 0)
			Menu->AddItem(8, "{- Go Back -}", 9999);

		entries.clear();
		Menu->SendTo(Plr);
	}
	else
	{
		Plr->EventTeleport(entry.map,entry.position_x,entry.position_y,entry.position_z);
	}
}

void Warper2::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void Warper2::GetTeleportEntries(uint32 creature, uint32 parent,std::vector<ct_entry> &entries)
{
        QueryResult * res;
        res = WorldDatabase.Query("SELECT * FROM `event1_teleporter` WHERE creature='%u' AND parent='%u' LIMIT %u",creature,parent,MAX_ENTRIES);
        if(res)
        {
                do
                {
                	ct_entry entry;
			if(ProcessEntryData(creature,res,entry)) entries.push_back(entry);	
                } while(res->NextRow());
        }
        delete res;
	
}

void Warper2::GetTeleportEntry(uint32 creature, uint32 id, ct_entry &entry)
{
        QueryResult * res;
        res = WorldDatabase.Query("SELECT * FROM `event1_teleporter` WHERE creature='%u' AND menuid='%u'",creature,id);
	ProcessEntryData(creature,res,entry);
	delete res;
}

bool Warper2::CanDisplay(ct_entry entry, Player * Plr)
{
	if ((entry.team != -1) && (entry.team != Plr->GetTeam())) return false;
	if ((entry.minlevel > 0) && (Plr->getLevel() < entry.minlevel)) return false;
	if ((entry.maxlevel > 0) && (Plr->getLevel() > entry.maxlevel)) return false;

	return true;
}

bool Warper2::ProcessEntryData(uint32 creature, QueryResult * res,ct_entry &entry)
{
	if(res)
	{
		QueryResult * res2;
		bool hasChildren = false;
		res2 = WorldDatabase.Query("SELECT menuid FROM `event1_teleporter` WHERE creature='%u' AND parent='%u'", creature,res->Fetch()[2].GetUInt32());

		if (res2)
		{
			hasChildren = true;
		}
		else
		{
			if (!IsValid(res)) 
			{
				// If it doesn't have children, it must have valid coordinates
                		Log.Color(TRED);
                		printf("[Teleporter] Invalid menu entry (creature='%u',menuid='%u')",creature,res->Fetch()[2].GetUInt32());
                		Log.Color(TNORMAL);
                		Log.Line();
				return false;
			}
		}	

        	entry.creature = res->Fetch()[0].GetUInt32();
        	entry.parent = res->Fetch()[1].GetUInt32();
        	entry.menuid = res->Fetch()[2].GetUInt32();
        	entry.icon = res->Fetch()[3].GetUInt32();
        	entry.gossip = res->Fetch()[4].GetString();
        	entry.map = res->Fetch()[5].GetUInt32();
        	entry.position_x = res->Fetch()[6].GetFloat();
        	entry.position_y = res->Fetch()[7].GetFloat();
        	entry.position_z = res->Fetch()[8].GetFloat();
        	entry.minlevel = res->Fetch()[9].GetUInt32();
        	entry.maxlevel = res->Fetch()[10].GetUInt32();
        	entry.team = res->Fetch()[11].GetInt32();
        	entry.hasChildren = hasChildren;
		
		delete res2;
		return true;
	}
}

bool Warper2::IsValid(QueryResult * res)
{
	return ((res->Fetch()[5].GetString() != 0) &&
		(res->Fetch()[6].GetString() != 0) && 
		(res->Fetch()[7].GetString() != 0) && 
		(res->Fetch()[8].GetString() != 0) 
	       );
}

void SetupWarper2(ScriptMgr * mgr)
{
	GossipScript * gs = (GossipScript*) new Warper2();

	QueryResult * res = WorldDatabase.Query("SELECT DISTINCT(`creature`) FROM `event1_teleporter`");
        if(res)
        {
                do
                {
			mgr->register_gossip_script(res->Fetch()[0].GetUInt32(), gs);
                } while(res->NextRow());
        }
        delete res;

}

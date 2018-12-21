//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

struct Recall
{
	Recall()
	{
		mapid = 0;
		x = 0;
		y = 0;
		z = 0;
		o = 0;
		isSet = false;
	}
	~Recall() {}

	uint32 mapid;
	float x;
	float y;
	float z;
	float o;
	bool isSet;
};

typedef map<uint8, Recall> Recalls;
static map<uint64, Recalls> pRec;

class SCRIPT_DECL Rune : public GossipScript
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


void Rune::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
	uint64 p = Plr->GetGUID();
	GossipMenu *Menu;
    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
	Menu->AddItem(1, "Mark location 1", 1);
	Menu->AddItem(1, "Mark location 2", 2);
	Menu->AddItem(1, "Mark location 3", 3);

	for(uint8 i = 0; i<=2; i++)
	{
		if(pRec[p][i].isSet)
		{
			char msg[256];
			snprintf(msg, 256, "Recall location %u", i+1);
			Menu->AddItem(0, msg, i+101);
		}
	}
    if(AutoSend)
        Menu->SendTo(Plr);
}

void Rune::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
    GossipMenu * Menu;
	uint64 p = Plr->GetGUID();
    switch(IntId)
    {
		case 0:
		{
			GossipHello(pObject, Plr, true);
		}break;
		case 1:
		case 2:
		case 3:
		{
			pRec[p][IntId].isSet = true;
			pRec[p][IntId].mapid = Plr->GetMapId();
			pRec[p][IntId].x = Plr->GetPositionX();
			pRec[p][IntId].y = Plr->GetPositionY();
			pRec[p][IntId].z = Plr->GetPositionZ();
			pRec[p][IntId].o = Plr->GetOrientation();
			Plr->BroadcastMessage("%s You have set this location as recall number %u", MSG_COLOR_LIGHTBLUE, IntId);
			Plr->Gossip_Complete();
		}break;

		case 101:
		case 102:
		case 103:
		{
			uint8 i = IntId - 100;
			if(pRec[p][i].isSet)
			{
				Plr->EventTeleport(pRec[p][i].mapid, pRec[p][i].x, pRec[p][i].y, pRec[p][i].z);
				Plr->SetOrientation(pRec[p][i].o);
			}
		}break;

    }
};

void Rune::GossipEnd(Object * pObject, Player* Plr)
{
	GossipScript::GossipEnd(pObject, Plr);
}

void LoadBook(Player * pPlayer)
{
	uint64 p = pPlayer->GetGUID();
	for(uint8 i = 0; i<=2; i++)
	{
		pRec[p][i].isSet = false;
	}
	QueryResult * res = CharacterDatabase.Query("SELECT * FROM runebook WHERE guid=%u ORDER BY entry", p);
	if(res)
	{
		do
		{
			uint8 entry = res->Fetch()[1].GetUInt8();
			pRec[p][entry].isSet = true;
			pRec[p][entry].mapid = res->Fetch()[2].GetUInt32();
			pRec[p][entry].x = res->Fetch()[3].GetFloat();
			pRec[p][entry].y = res->Fetch()[4].GetFloat();
			pRec[p][entry].z = res->Fetch()[5].GetFloat();
			pRec[p][entry].o = res->Fetch()[6].GetFloat();
		}while(res->NextRow());
		CharacterDatabase.FreeQueryResult(res);
	}
}

void SaveBook(Player * pPlayer)
{
	uint64 p = pPlayer->GetGUID();
	for(uint8 i=0; i<=2; i++)
	{
		if(pRec[p][i].isSet)
		{
			char query[512];
			sprintf(query, "REPLACE INTO runebook(guid, entry, mapid, px, py, pz, po) VALUES(%u, %u, %u, %f, %f, %f, %f);", p, i, pRec[p][i].mapid, pRec[p][i].x, pRec[p][i].y, pRec[p][i].z, pRec[p][i].o);
			CharacterDatabase.Execute(query);
		}
	}

}

void SetupRunebook(ScriptMgr * mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_ENTER_WORLD, &LoadBook);
	mgr->register_hook(SERVER_HOOK_EVENT_ON_LOGOUT, &SaveBook);
	GossipScript * gs = (GossipScript*) new Rune();
	mgr->register_item_gossip_script(90010, gs);
}

#include "Setup.h"


#define INSTANT_MOUNT 0

enum MOUNT_ERROR_TYPE
{
	ERROR_TYPE_NONEXISTANT = 0,
	ERROR_TYPE_CANTFLY = -1,
};

uint32 GetMount(Player * pPlayer, const char * Message)
{
    QueryResult * res = WorldDatabase.Query("SELECT * FROM `mounts` WHERE `name` = '%s';", Message);
    if(res == NULL)
        return ERROR_TYPE_NONEXISTANT;
    Field * mount = res->Fetch();
    if(mount == NULL)
        return ERROR_TYPE_NONEXISTANT;
		
	
    if(mount[0].GetInt32() == NULL)
        return ERROR_TYPE_NONEXISTANT;
		
	if(mount[2].GetInt32() == 1)
	{
		if(pPlayer->GetMapId() == 571||pPlayer->GetMapId() == 530)
		{
		}
		else
		{
		return ERROR_TYPE_CANTFLY;
		}
	}

    return mount[0].GetUInt32();
}


bool MountCommand(Player * pPlayer, uint32 Type, uint32 Lang, const char * Message, const char * Misc)
{
    if(pPlayer->CombatStatus.IsInCombat())
    {
        uint32 sp = GetMount(pPlayer,Message);
        if(sp != ERROR_TYPE_NONEXISTANT && sp != ERROR_TYPE_CANTFLY)
        {
            if(INSTANT_MOUNT == 0)
			{
                pPlayer->CastSpell(pPlayer,dbcSpell.LookupEntry(sp),false);
			}
            else
			{
                pPlayer->CastSpell(pPlayer,dbcSpell.LookupEntry(sp),true);
			}

            pPlayer->BroadcastMessage("Go go %s",Message);
            pPlayer->SendAreaTriggerMessage("Go go %s",Message);
            return false;
        }
    }
    else
    {
        pPlayer->BroadcastMessage("You cant mount in combat");
        pPlayer->SendAreaTriggerMessage("You cant mount in combat");
    }

    return true;

}


void SetupMount(ScriptMgr* mgr)
{
    mgr->register_hook(SERVER_HOOK_EVENT_ON_CHAT, (void*)MountCommand);
}



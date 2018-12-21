//Projectfile remade by Keazain

#include "StdAfx.h"
#include "Setup.h"

void OnGuildCreate(Player * pLeader, Guild * pGuild)
{
    char onGuildCreate[1024];
     snprintf((char*)onGuildCreate, 1024, "The Guild|cff33ff55 [%s]|r has been formed by|cffff00bb %s", pGuild->GetGuildName(), pLeader->GetName());
  
    
        sWorld.SendWorldWideScreenText(onGuildCreate);

    
}

void SetupGuildCreate(ScriptMgr * mgr)
{
   mgr->register_hook(SERVER_HOOK_EVENT_ON_GUILD_CREATE, OnGuildCreate);


}

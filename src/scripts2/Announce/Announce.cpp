//Projectfile remade by Keazain

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305) // warning C4305: 'argument' : truncation from 'double' to 'float'
#endif


void PvPAnnounce (Player* killer, Player* victim)
{

	if(killer->getLevel() <= victim->getLevel() + 5 || killer->getLevel() >= victim->getLevel() - 5)
		{
			char killstro[200];
			sprintf(killstro, "%s Has Killed %s With Honor! Thats the spirit!", killer->GetName(), victim->GetName());
			sWorld.SendWorldWideScreenText(killstro);
			}
else
{
		if(killer->getLevel() <= victim  ->getLevel() + 5 || killer->getLevel() >= victim->getLevel() - 20)
		{
		char killstro[200];
        sprintf(killstro, "%s Has Ganked %s, try picking on someone your own level!", killer->GetName(), victim->GetName());
        sWorld.SendWorldWideScreenText(killstro); }
		else 
		{ 
		
			char killstro[200];
        sprintf(killstro, "%s Has Ganked a lowbie %s, he is now Hated By ALL", killer->GetName(), victim->GetName());
        sWorld.SendWorldWideScreenText(killstro);
killer->SetHealthPct(15);
		}
}
}



void SetupAnnounce(ScriptMgr * mgr)
{
    mgr->register_hook(SERVER_HOOK_EVENT_ON_KILL_PLAYER, PvPAnnounce);
}
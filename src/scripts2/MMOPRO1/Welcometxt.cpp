#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)	// warning C4305: 'argument' : truncation from 'double' to 'float'
#endif

void OnEnterWorld(Player * pPlayer)
{
	bool start = true;

	while (start == true)
	{
		pPlayer->SendAreaTriggerMessage("Welcome! Thanks for using AFusion4WoW Repack, Visit us at http.afusion4wow.no-ip.biz");
		break;
	}
}
		
	


void SetupEnterWorld(ScriptMgr * mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_ENTER_WORLD, OnEnterWorld);
}
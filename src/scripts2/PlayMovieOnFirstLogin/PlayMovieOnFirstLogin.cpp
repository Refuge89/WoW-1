#include "StdAfx.h"
#include "Setup.h"

void PlayMovieOnFirstLogin(Player * pPlayer)
{
	pPlayer->SendTriggerMovie(14);
}

void SetupPlayMovieOnFirstLogin(ScriptMgr * mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_FIRST_ENTER_WORLD, PlayMovieOnFirstLogin);
}

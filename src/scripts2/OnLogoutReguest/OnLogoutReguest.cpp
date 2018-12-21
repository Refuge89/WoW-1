//Projectfile remade by Keazain

#include "StdAfx.h"
#include "Setup.h"


void OnLogoutRequest(Player * Plr)
{
	Plr->GetGUID();
		Plr->SaveToDB(true);
	Plr->SoftDisconnect();
};


void SetupOnLogoutReguest(ScriptMgr * mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_LOGOUT_REQUEST, OnLogoutRequest);
}


//Projectfile remade by Keazain

#include "StdAfx.h"
#include "Setup.h"

void onPvpMoneynpc(Player* plr, Player* victim)
{
	if( plr->GetTeam() != victim->GetTeam())
	{
		char message[200];
		sprintf(message, "%s has killed %s and earned 10 gold", plr->GetName(), victim->GetName());
		sWorld.SendWorldWideScreenText(message);

		int32 gold_check_p = plr->GetUInt32Value( PLAYER_FIELD_COINAGE );
		int32 gold_check_v = victim->GetUInt32Value( PLAYER_FIELD_COINAGE );
		int32 new_gold_p = gold_check_p + 100000;
		int32 new_gold_v;
		if(gold_check_v < 100000)
		{
			new_gold_v = 0;
		}
		else
		{
			new_gold_v = gold_check_v - 100000;
		}

		plr->SetUInt32Value( PLAYER_FIELD_COINAGE, new_gold_p );
		victim->SetUInt32Value( PLAYER_FIELD_COINAGE, new_gold_v );
	}
}

void SetupPvpMoneynpc(ScriptMgr * mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_KILL_PLAYER, (void*)onPvpMoneynpc);
}

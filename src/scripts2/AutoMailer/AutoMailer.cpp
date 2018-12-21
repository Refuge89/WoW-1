#include "StdAfx.h"
#include "Setup.h"
	
//#define TEST_ON

void AutoMailer(Player *plr)
{
	QueryResult *res = WorldDatabase.Query("SELECT * FROM auto_mailer");
	if(res == NULL)
		return;

#ifdef TEST_ON
	plr->SendAreaTriggerMessage("%sYou just leveled up, hook is working.|r", MSG_COLOR_RED);
#endif

	while(res->NextRow())
	{
		Field *f = res->Fetch();
		
		uint32 level = f[0].GetUInt32();
		const char *subject = f[1].GetString();
		const char *message = f[2].GetString();

		if(plr->getLevel() != level)
			continue;

		CharacterDatabase.Execute("INSERT INTO mailbox VALUES(%s, 2, %s, 120, '%s', '%s', 0, NULL, 0, 62, %s, %s, 0, 0, 0)", sMailSystem.Generate_Message_Id(), plr->GetGUID(), subject, message, (uint32)UNIXTIME, ((uint32)UNIXTIME + (TIME_DAY * MAIL_DEFAULT_EXPIRATION_TIME)));
		// sMailSystem.SendAutomatedMessage(x32 type, x64 sender, x64 receiver, subject, body, x32 money, x32 cod, x64 item_guid, x32 stationary)
		// SendAutomatedMessage(1, getguid(), getguid(), subject, body, 0, 0, 0, 0);
	}
}

void SetupAutoMailer(ScriptMgr *mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_POST_LEVELUP, &AutoMailer);
}
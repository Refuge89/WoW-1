#include "StdAfx.h"
#include "Setup.h"

#define RESSURECTION 10880
#define FINGER_DEATH 31984
#define GANKGUARD_ENTRY 35639
#define SICKNESS 15007

void CheckGank(Player * killer, Player * killed)
{
	if((killer->GetMapId() != 571) || (killed->GetMapId() != 571))
		return;

	if(killer->getLevel() < killed->getLevel() + 0)
		return;
	
	//Give the ganker the punnishment :D
	Creature * gankguard = killer->GetMapMgr()->GetInterface()->SpawnCreature(GANKGUARD_ENTRY, killer->GetPositionX(), killer->GetPositionY(), killer->GetPositionZ(), killer->GetOrientation(), true, true, 0, 0);

	//Let's scare the player a little bit by yelling a phrase (randomly)
	switch(rand()%12)
	{
	case 0:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Hey there! Don't kill small stones when there's a mountain right here!");
		break;
	case 1:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You should pick on somone your own height!");
		break;
	case 2:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Say hello to my little friend!");
		break;
	case 3:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Pick on somone your own size!");
		break;
	case 4:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Can't you feel any empathy at all, stop this madness!");
		break;
	case 5:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Enough with the killing!");
		break;
	case 6:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Stop killing less powerful!");
		break;
	case 7:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Why are you beating him up?");
		break;
	case 8:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Let me show you how it's done!");
		break;
	case 9:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Your life can be taken for all of those you have killed.");
		break;
	case 10:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "So brave, Killing a low level! Try to beat me up now!");
		break;
	case 11:
		gankguard->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "You'll regret yourself when I'm done with you!");
		break;
	}

	//Deal the punnishment
	//gankguard->Strike(killer, MELEE, NULL, (1000 * 60 ^ 4), 100, 100, false, true); // finger of death is so more epic
	//killer->DeathDurabilityLoss(0.25); // wont bother with this
	//gankguard->CastSpell(killer, SICKNESS, 0); // not working? Fail -.- Spirit healer way is to complicated for me
	gankguard->CastSpell(killer, FINGER_DEATH, 0); // Works fine
	//gankguard->CastSpell(killed, RESSURECTION, 0); // crashes server
	killed->ResurrectPlayer(); // Doesn't appear to be working
	killed->SetUInt32Value(UNIT_FIELD_HEALTH, killed->GetUInt32Value(UNIT_FIELD_MAXHEALTH)); // Doesn't appear to be working
	killed->SetUInt32Value(UNIT_FIELD_POWER1, killed->GetUInt32Value(UNIT_FIELD_MAXPOWER1)); // Doesn't appear to be working
	killed->SetUInt32Value(UNIT_FIELD_POWER4, killed->GetUInt32Value(UNIT_FIELD_MAXPOWER4)); // Doesn't appear to be working
	gankguard->m_noRespawn = true;
	gankguard->Despawn(5000, 0);
};

void SetupGankGuard(ScriptMgr * mgr)
{
	mgr->register_hook(SERVER_HOOK_EVENT_ON_KILL_PLAYER, &CheckGank);
}

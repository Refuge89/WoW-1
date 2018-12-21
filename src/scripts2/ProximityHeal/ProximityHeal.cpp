//Projectfile remade by Keazain

#include "StdAfx.h"
#include "Setup.h"

#define HEALER_ID 990000013

class ProximityHeal : public CreatureAIScript
{
public:
    ADD_CREATURE_FACTORY_FUNCTION(ProximityHeal);

    ProximityHeal(Creature* pCreature) : CreatureAIScript(pCreature)
    {
		RegisterAIUpdateEvent(1550);
	}

	void OnSpawn()
	{
		RegisterAIUpdateEvent(1550);
	}

    void AIUpdate()
    {
		Player * Plr;
		Object *curObj;
		for (Object::InRangeSet::iterator iter = _unit->GetInRangeSetBegin(); iter != _unit->GetInRangeSetEnd(); ++iter)
		{
			curObj = *iter;

			if(curObj->GetTypeId() == TYPEID_PLAYER)
			{
				{
					Plr = static_cast< Player* >( curObj );
					if(_unit->_getFaction() == 1 && Plr->GetTeam() == 0 || _unit->_getFaction() == 2 && Plr->GetTeam() == 1)
					{
						_unit->CastSpell(Plr, 10917, 0);
					}
				}
			}
		}
	}
};
void SetupProximityHeal(ScriptMgr * mgr)
{
	mgr->register_creature_script(99000069, &ProximityHeal::Create);
	sLog.outColor(TBLUE, "\nProximity Healer Loaded\nby: Keazain");
	sLog.outColor(TNORMAL, "\n");
}

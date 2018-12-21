//Keazain Project

#include "StdAfx.h"
#include "Setup.h"
 
#include "mysql/mysql.h"
#include <stdio.h>
 
#ifdef WIN32
#pragma warning(disable:4305)
#pragma warning(disable:4244)
#endif
 
MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;
 
#define server       "server"
#define user         "user"
#define password     "password"
#define database     "database"
 
 
class SCRIPT_DECL HouseNPC : public GossipScript
{
public:
    #pragma region Hello
    void GossipHello(Object * pObject, Player* plr, bool AutoSend)
    {
        GossipMenu *menu;
        objmgr.CreateGossipMenuForPlayer(&menu, pObject->GetGUID(), 1, plr);
 
 
        if(!plr->CombatStatus.IsInCombat())
        {
            menu->AddItem(1, "Get a GuildHouse", 1);
            menu->AddItem(2, "Teleport to your GuildHouse", 2);
        }
        else
            plr->BroadcastMessage("You are in combat.");
 
        if(AutoSend)
           menu->SendTo(plr);
    };
    #pragma endregion
 
    #pragma region Selection
    void GossipSelectOption(Object * pObject, Player* plr, uint32 id, uint32 intId, const char * code)
    {
       switch(intId)
       {
       case 1: //Get a house
            {
                bool haveHouse = false;
 
                //Init the mysql client
                conn = mysql_init(NULL);
 
                //Connect to the database
                if(!mysql_real_connect(conn, server, user, password, database, 3307, NULL, 0))
                {
                    sLog.outString("HouseNPC: %s.", mysql_error(conn));
                    return;
                }
 
                //Send a query that loads the houses table
                mysql_query(conn, "SELECT * FROM houses");
 
                res = mysql_use_result(conn);
                if(res)
                {
                    while((row = mysql_fetch_row(res)) != NULL)
                    {
                        //Get guids
                        uint32 plr_guid = plr->GetGUID();
                        uint32 r_guid = atol(row[0]);
 
                        if(r_guid == plr_guid)
                            haveHouse = true; break;
                    }
                }
                else
                {
                    sLog.outString("HouseNPC: %s.", mysql_error(conn));
                    return;
                }
 
                if(!haveHouse)
                {
                    char sql[512];
                    snprintf(sql, 512, "INSERT INTO houses(ownerguid, posX, posY, posZ, mapId) VALUES(%u, 255.678116, -0.136763, 9.597258, 598);", plr->GetGUID());
                    mysql_query(conn, sql);
                    plr->BroadcastMessage("You just got a GuildHouse.");
                }
                else
                {
                    plr->BroadcastMessage("You already have a GuildHouse.");
                }
 
                mysql_free_result(res);
                mysql_close(conn);
            }break;
 
       case 2: //Teleport to your house
           {
               bool haveHouse = false;
 
                //Init the mysql client
                conn = mysql_init(NULL);
 
                //Connect to the database
                if(!mysql_real_connect(conn, server, user, password, database, 3307, NULL, 0))
                {
                    sLog.outString("HouseNPC: %s.", mysql_error(conn));
                    return;
                }
 
                //Send a query that loads the houses table
                mysql_query(conn, "SELECT * FROM houses");
 
                res = mysql_use_result(conn);
                if(res)
                {
                    while((row = mysql_fetch_row(res)) != NULL)
                    {
                        //Get guids
                        uint32 plr_guid = plr->GetGUID();
                        uint32 r_guid = atol(row[0]);
 
                        if(r_guid == plr_guid)
                        {
                            plr->EventTeleport(atol(row[4]), atol(row[1]), atol(row[2]), atol(row[3]));
                            haveHouse = true;
                            break;
                        }
                    }
                }
 
                if(!haveHouse)
                {
                    plr->BroadcastMessage("You don't have a house.");
                }
 
                mysql_free_result(res);
                mysql_close(conn);
           }break;
       }
    };
    #pragma endregion
 
    #pragma region Dispose
    void HouseNPC::GossipEnd(Object * pObject, Player* Plr)
    {
        GossipScript::GossipEnd(pObject, Plr);
    };
 
    void Destroy()
    {
        delete this;
    };
    #pragma endregion
};
 
void SetupHouseNPC(ScriptMgr * mgr)
{
    GossipScript * gs = (GossipScript*) new HouseNPC();
    mgr->register_gossip_script(99002222, gs);
};
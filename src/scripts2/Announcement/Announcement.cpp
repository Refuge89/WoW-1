//Projectfile remade by Keazain

#include "StdAfx.h"
#include "Setup.h"
	
//Configure these as you wish
#define BREAKTIME 999000    //The amount of seconds * 1000 you want to wait in between messages
#define HEADERSTR "[Read]"     //The string to place in front of the message
#define HEADERCOLOR MSG_COLOR_GREEN  //The color of the string in front of the message (Example: MSG_COLOR_RED)
#define TEXTCOLOR MSG_COLOR_LIGHTBLUE    //The color of the text (Example: MSG_COLOR_LIGHTBLUE)
class Announcement
{
   public:
      void Run();
};

void Announcement::Run()
{

    char sZprava[500];

       QueryResult * result = CharacterDatabase.Query("SELECT * FROM announcer_txt ORDER BY id ASC");
    if(result)
    {
        do {
            sprintf(sZprava, "%s%s %s%s", HEADERCOLOR, HEADERSTR, TEXTCOLOR, result->Fetch()[1].GetString());
            sWorld.SendWorldText(sZprava);
            
        }while(result->NextRow());
        delete result;
    }

}

void ShowMsg(char * errmsg)
{
   char errstr[255];
   sprintf(errstr, "\nXpack Announcer: %s", errmsg);
   sLog.outString(errstr);
}

void SetupAnnouncer(ScriptMgr * mgr)
{
   Announcement Announcer;

   //If all is good, set up the timer event and lets roll!
   if(BREAKTIME >= 1000)
   {
      TimedEvent * te = TimedEvent::Allocate(&Announcer, new CallbackP0<Announcement>(&Announcer, &Announcement::Run), 1, BREAKTIME, 0);
      sWorld.event_AddEvent(te);
   } else {
      //Someone has their time set under 1 second.;P
      ShowMsg("Announcer has been disabled.  Please insure you have the config set right!");
   }

}
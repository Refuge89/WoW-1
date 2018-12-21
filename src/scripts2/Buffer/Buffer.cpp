#include "StdAfx.h" 
#include "Setup.h" 
 
class SCRIPT_DECL Buffer : public GossipScript 
{ 
public: 
    void GossipHello(Object * pObject, Player* Plr, bool AutoSend); 
    void GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code); 
    void GossipEnd(Object * pObject, Player* Plr); 
   void Destroy() 
   { 
      delete this; 
   } 
}; 
void Buffer::GossipHello(Object * pObject, Player* Plr, bool AutoSend) 
    { 
        GossipMenu *Menu; 
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr); 
 
      Menu->AddItem(0, "Level 10 Buffs - 1 Gold Each", 1);   
      Menu->AddItem(0, "Level 20 Buffs - 2 Gold Each", 2);  
      Menu->AddItem(0, "Level 30 Buffs - 3 Gold Each", 3);  
      Menu->AddItem(0, "Level 40 Buffs - 4 Gold Each", 4);  
      Menu->AddItem(0, "Level 50 Buffs - 5 Gold Each", 5);  
	  Menu->AddItem(9, "Gimme something more and cheap please.", 98);
 
        if(AutoSend) 
            Menu->SendTo(Plr); 
    } 
 
void Buffer::GossipSelectOption(Object * pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code) 
    { 
 
        GossipMenu * Menu; 
        switch(IntId) 
        { 
        case 0:     // Return to start 
            GossipHello(pObject, Plr, true); 
            break; 
 
      case 1:      
   { 
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr); 
      if(Plr->getLevel() >= 10) 
      { 
            Menu->AddItem(5, "Strength", 8); 
                Menu->AddItem(5, "Intelligence", 9); 
                Menu->AddItem(5, "Stamina", 10); 
                Menu->AddItem(5, "Spirit", 11); 
                Menu->AddItem(5, "Agility", 12); 
            Menu->AddItem(5, "Protection", 43); 
                Menu->AddItem(0, "[Back]", 99); 
                Menu->SendTo(Plr); 
      } 
      else{ 
         Plr->BroadcastMessage("You must be at least level 10 to use these buffs." ); 
      } 
   } 
            break; 
 
        case 2:   
   {    
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr); 
      if(Plr->getLevel() >= 20) 
      { 
      Menu->AddItem(5, "Strength", 13); 
                Menu->AddItem(5, "Intelligence", 14); 
                Menu->AddItem(5, "Stamina", 15); 
                Menu->AddItem(5, "Spirit", 16); 
                Menu->AddItem(5, "Agility", 17); 
      Menu->AddItem(5, "Protection", 44); 
                      Menu->AddItem(0, "[Back]", 99); 
                Menu->SendTo(Plr); 
      } 
      else{ 
         Plr->BroadcastMessage("You must be at least level 20 to use these buffs." ); 
      } 
   } 
            break; 
 
        case 3:    
   {   
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr); 
      if(Plr->getLevel() >= 30) 
      { 
      Menu->AddItem(5, "Strength", 18); 
                Menu->AddItem(5, "Intelligence", 19); 
                Menu->AddItem(5, "Stamina", 20); 
                Menu->AddItem(5, "Spirit", 21); 
                Menu->AddItem(5, "Agility", 22); 
      Menu->AddItem(5, "Protection", 45); 
                      Menu->AddItem(0, "[Back]", 99); 
                Menu->SendTo(Plr); 
      } 
      else{ 
         Plr->BroadcastMessage("You must be at least level 30 to use these buffs." ); 
      } 
   } 
            break; 
 
        case 4:     
   {  
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr); 
      if(Plr->getLevel() >= 40) 
      { 
      Menu->AddItem(5, "Strength", 23); 
                Menu->AddItem(5, "Intelligence", 24); 
                Menu->AddItem(5, "Stamina", 25); 
                Menu->AddItem(5, "Spirit", 26); 
                Menu->AddItem(5, "Agility", 27); 
      Menu->AddItem(5, "Protection", 46); 
                      Menu->AddItem(0, "[Back]", 99); 
                Menu->SendTo(Plr); 
      } 
      else{ 
         Plr->BroadcastMessage("You must be at least level 40 to use these buffs." ); 
      } 
   } 
            break; 
 
        case 5:      
   {    
                objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr); 
      if(Plr->getLevel() >= 50) 
      { 
      Menu->AddItem(5, "Strength", 28); 
                Menu->AddItem(5, "Intelligence", 29); 
                Menu->AddItem(5, "Stamina", 30); 
                Menu->AddItem(5, "Spirit", 31); 
                Menu->AddItem(5, "Agility", 32); 
      Menu->AddItem(5, "Protection", 47); 
                      Menu->AddItem(0, "[Back]", 99); 
                Menu->SendTo(Plr); 
      } 
      else{ 
         Plr->BroadcastMessage("You must be at least level 50 to use these buffs." ); 
      } 
   } 
            break; 
 
// Level 10 
 
        case 8:     // Strength 
           { 
      uint32 price=10000;// 1G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8118, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 9:     // Intelligence 
           { 
      uint32 price=10000;// 1G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8096, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 10:     // Stamina 
           { 
      uint32 price=10000;// 1G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8099, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 11:     // Spirit 
           { 
      uint32 price=10000;// 1G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8112, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 12:     // Agility 
           { 
      uint32 price=10000;// 1G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8115, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
// Level 20 
 
        case 13:     // Strength 
           { 
      uint32 price=20000;// 2G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8119, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 14:     // Intelligence 
           { 
      uint32 price=20000;// 2G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8097, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 15:     // Stamina 
           { 
      uint32 price=20000;// 2G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8100, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 16:     // Spirit 
           { 
      uint32 price=20000;// 2G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8113, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 17:     // Agility 
           { 
      uint32 price=20000;// 2G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8116, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
// Level 30 
 
        case 18:     // Strength 
           { 
      uint32 price=30000;// 3G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8120, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 19:     // Intelligence 
           { 
      uint32 price=30000;// 3G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8098, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 20:     // Stamina 
           { 
      uint32 price=30000;// 3G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8101, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 21:     // Spirit 
           { 
      uint32 price=30000;// 3G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8114, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 22:     // Agility 
           { 
      uint32 price=30000;// 3G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8117, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
// Level 40 
 
        case 23:     // Strength 
           { 
      uint32 price=40000;// 4G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 12179, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 24:     // Intelligence 
           { 
      uint32 price=40000;// 4G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 12176, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 25:     // Stamina 
           { 
      uint32 price=40000;// 4G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 12178, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 26:     // Spirit 
           { 
      uint32 price=40000;// 4G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 12177, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 27:     // Agility 
           { 
      uint32 price=40000;// 4G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 12174, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
// Level 50 
 
        case 28:     // Strength 
           { 
      uint32 price=50000;// 5G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 33082, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 29:     // Intelligence 
           { 
      uint32 price=50000;// 5G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 33078, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 30:     // Stamina 
           { 
      uint32 price=50000;// 5G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 33081, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 31:     // Spirit 
           { 
      uint32 price=50000;// 5G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 33080, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 32:     // Agility 
           { 
      uint32 price=50000;// 5G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 33077, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 43:     // Protection 
           { 
      uint32 price=10000;// 1G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8091, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 44:     // Protection 
           { 
      uint32 price=20000;// 2G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8094, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 45:     // Protection 
           { 
      uint32 price=30000;// 3G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 8095, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break; 
 
        case 46:     // Protection 
           { 
      uint32 price=40000;// 4G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 12175, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
            break;

        case 47:     // Protection 
           { 
      uint32 price=50000;// 5G 
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 33079, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
		   break;

        case 98: // Free
           { 
      uint32 price=50000;// 5S
      uint32 currentgold = Plr->GetUInt32Value(PLAYER_FIELD_COINAGE); 
      if (currentgold>=price){ 
      int32 newgold = currentgold - price;  
      Plr->SetUInt32Value(PLAYER_FIELD_COINAGE,newgold); 
                Plr->CastSpell(Plr, 15366, 0); 
      Plr->BroadcastMessage("You have been blessed!" ); 
      }else{ 
         Plr->BroadcastMessage("You don't have enough money ." ); 
      } 
      } 
		   break;
 
      case 99: //main menu 
             { 
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, Plr); 
 
      Menu->AddItem(0, "Level 10 Buffs - 1 Gold Each", 1);   
      Menu->AddItem(0, "Level 20 Buffs - 2 Gold Each", 2);  
      Menu->AddItem(0, "Level 30 Buffs - 3 Gold Each", 3);  
      Menu->AddItem(0, "Level 40 Buffs - 4 Gold Each", 4);  
      Menu->AddItem(0, "Level 50 Buffs - 5 Gold Each", 5);  
	  Menu->AddItem(9, "Gimme something more and cheap please.", 98);
             
      Menu->SendTo(Plr); 
         } 
        } 
    } 
 
void Buffer::GossipEnd(Object * pObject, Player* Plr) 
{ 
    GossipScript::GossipEnd(pObject, Plr); 
} 
 
void SetupBuffer(ScriptMgr * mgr) 
    { 
    GossipScript * gs = (GossipScript*) new Buffer(); 
    mgr->register_item_gossip_script(90000015,gs); 
    }
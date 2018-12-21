//Keazain Project

#include "StdAfx.h"
#include "Setup.h"

#ifdef WIN32
#pragma warning(disable:4305)
#endif

#define NoobHelperID 90000008

class SCRIPT_DECL NoobHelper: public GossipScript
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

void NoobHelper::GossipHello(Object * pObject, Player* Plr, bool AutoSend)
{
    if(Plr->CombatStatus.IsInCombat())
    {
        Plr->BroadcastMessage("You are in combat!");  
        return;
    }
    GossipMenu *Menu;
    objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
		if(Plr->getLevel() < 15)
        {
            Plr->BroadcastMessage("You Must Be Level 15 Before you can use the Noob Helper!" );
            Plr->Gossip_Complete();
        }else{
			if(Plr->getLevel() > 15||Plr->getLevel() <25)
			{Menu->AddItem(5,"Level 15-25", 50);}
			else
			if (Plr->getLevel() > 25||Plr->getLevel() <35)
			{Menu->AddItem(5,"Level 25-35", 51);}
			else 
			if(Plr->getLevel() > 35||Plr->getLevel() <45)
			{Menu->AddItem(5,"Level 35-45", 52);}
			else 
			if(Plr->getLevel() > 45||Plr->getLevel() <55)
			{Menu->AddItem(5,"Level 45-55", 53);}
			else 
			if(Plr->getLevel() > 55||Plr->getLevel() <65)
			{Menu->AddItem(5,"Level 55-65", 54);}
			else 
			if(Plr->getLevel() > 65||Plr->getLevel() <75)
			{Menu->AddItem(5,"Level 65-75", 55);}
			else 
			if(Plr->getLevel() > 75||Plr->getLevel() <80)
			{Menu->AddItem(5,"Level 75-80", 56);}
			if(Plr->getLevel() >79)
			{
				Plr->BroadcastMessage("Somehow you got to 80 you are no longer a noob...leveling-wise that is." );
				Plr->Gossip_Complete();
			}
				if(AutoSend)
				Menu->SendTo(Plr);
		}
}

void NoobHelper::GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code)
{
    GossipMenu * Menu;
    switch(IntId)
    {
    case 0:
        {
            GossipHello(pObject, Plr, true);
        }break;


	case 50://15-25
        {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
			if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
	        {
				Menu->AddItem(2, "Ghostlands (Easy)", 100);
				Menu->AddItem(2, "Silverpine Forest (Easy)", 101);
				Menu->AddItem(2, "The Barrens", 102);
			}
			else
			{
				Menu->AddItem(2, "Westfall (Easy)", 103);
				Menu->AddItem(2, "Loch Modan (Easy)", 104);
				Menu->AddItem(2, "Bloodmyst Isle (Easy)", 105);
				Menu->AddItem(2, "Darkshore (Easy)", 106);

			}
			
			Menu->AddItem(2, "Ashenvale", 107);
			Menu->AddItem(2, "Duskwood", 108);
			Menu->AddItem(2, "Wetlands", 109);
			Menu->AddItem(2, "Redridge Mountains", 110);
			Menu->AddItem(2, "Stonetalon Mountains", 115);
			Menu->SendTo(Plr);
        }break;

	case 51://25-35
        {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
			Menu->AddItem(2, "Ashenvale (Easy)", 106);
			Menu->AddItem(2, "Duskwood (Easy)", 107);
			Menu->AddItem(2, "Wetlands (Easy)", 108);
			Menu->AddItem(2, "Redridge Mountains", 109);
			Menu->AddItem(2, "Stonetalon Mountains", 110);
			Menu->AddItem(2, "Thousand Needles", 111);
			Menu->AddItem(2, "Hillsbrad Foothills", 112);
			Menu->AddItem(2, "Stranglethorn Vale", 113);
			Menu->AddItem(2, "Dustwallow Marsh", 114);
			Menu->AddItem(2, "Arathi Highlands", 116);
			Menu->AddItem(2, "Alterac Mountains", 117);
            Menu->SendTo(Plr);
        }break;

	case 52://35-45
        {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
			Menu->AddItem(2, "Desolace (Easy)", 118);
			Menu->AddItem(2, "Alterac Mountains (Easy)", 117);
			Menu->AddItem(2, "Stranglethorn Vale (Easy)", 115);
			//normal
			Menu->AddItem(2, "Swamp of Sorrows", 119);
			Menu->AddItem(2, "Bad Lands", 120);
			Menu->AddItem(2, "Dustwallow Marsh", 114);
			Menu->AddItem(2, "Searing Gorge", 121);
			Menu->AddItem(2, "Feralas", 122);
			Menu->AddItem(2, "Tanaris", 123);
			Menu->AddItem(2, "Azshara (Hard)", 124);
			Menu->AddItem(2, "Blasted Lands (Hard)", 125);
			Menu->AddItem(2, "The Hinterlands (Hard)", 126);
            Menu->SendTo(Plr);
        }break;


	case 53://45-55
        {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
			Menu->AddItem(2, "Azshara (Easy)", 124);
			Menu->AddItem(2, "Blasted Lands (Easy)", 125);
			Menu->AddItem(2, "The Hinterlands (Easy)", 126);
			Menu->AddItem(2, "Felwood", 127);
			Menu->AddItem(2, "Un'Goro Crater", 128);
			Menu->AddItem(2, "Winterspring", 129);
			Menu->AddItem(2, "Western Plaguelands", 130);
			Menu->AddItem(2, "Eastern Plaguelands", 131);
			Menu->AddItem(2, "Deadwind Pass (Hard)", 132);
			Menu->AddItem(2, "Silithus (Hard)", 133);
            Menu->SendTo(Plr);
        }break;
	
	case 54://55-65
        {
            objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
			Menu->AddItem(2, "Deadwind Pass (Easy)", 132);
			Menu->AddItem(2, "Silithus (Easy)", 133);
			Menu->AddItem(2, "Hellfire Peninsula", 134);
			Menu->AddItem(2, "Zangarmarsh", 135);
			Menu->AddItem(2, "Terokkar Forest", 136);
			Menu->AddItem(2, "Nagrand", 137);
			Menu->AddItem(2, "Blade's Edge Mountains(Hard)", 138);
            Menu->SendTo(Plr);
        }break;

	case 55://65-75
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
			Menu->AddItem(2, "Blade's Edge Mountains", 138);
			Menu->AddItem(2, "Shadowmoon Valley", 139);
			Menu->AddItem(2, "Netherstorm", 140);
			Menu->AddItem(2, "Howling Fjord", 141);
			Menu->AddItem(2, "Borean Tundra", 142);
			Menu->AddItem(2, "Grizzly Hills", 143);
			Menu->AddItem(2, "Zul'Drak", 141);
			//if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
	        //{Menu->AddItem(2, "Hyjal Camp", 150);}else{Menu->AddItem(2, "Hyjal Camp", 149);}  
			Menu->SendTo(Plr);
		}break;
	case 56://75-80
		{
			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2593, Plr);
			Menu->AddItem(2, "Grizzly Hills", 144);
			Menu->AddItem(2, "Sholazar Basin", 145);
			Menu->AddItem(2, "Crystalsong", 146);
			Menu->AddItem(2, "The Storm Peaks", 147);
			Menu->AddItem(2, "Icecrown", 148);
/*	These ports are for my server	//if(Plr->getRace()== 10||Plr->getRace()== 2||Plr->getRace()== 6||Plr->getRace()== 8||Plr->getRace()== 5)
 	although I will leave these in  //{Menu->AddItem(2, "Hyjal Camp", 150);}else{Menu->AddItem(2, "Hyjal Camp", 149);}  
	to see if they can help someone 
*/	 			Menu->SendTo(Plr);
		}break;

	
	case 100:
		{
			Plr->EventTeleport(530, 2922.69, 6871.06, 1.62686);//Ghostlands
		}
	case 101:
		{
			Plr->EventTeleport(0, 511.536, 1638.63, 121.417);//Silverpine Forest
		}
	case 102:
		{
			Plr->EventTeleport(1, 90.1003, -1943.44, 80.4727);//The Barrens
		}
	case 103:
		{
			Plr->EventTeleport(0, -10645.9, 1179.06, 49.1781);//Westfall
		}
	case 104:
		{
			Plr->EventTeleport(0, -4939.1, -3423.74, 306.595);//Loch Modan
		}
	case 105:
		{
			Plr->EventTeleport(530, -2721.68, -12208.9, 10.0882);//Bloodmyst Isle
		}
	case 106:
		{
			Plr->EventTeleport(1, 6207.5, -152.833, 80.8185);//Darkshore
		}
	case 107:
		{
			Plr->EventTeleport(1, 6438.69, 485.38, -100.395);//Ashenvale
		}
	case 108:
		{
			Plr->EventTeleport(0, -10517, -1158.39, 40.0542);//Duskwood
		}
	case 109:
		{
			Plr->EventTeleport(0, -4086.36, -2610.95, 47.0143);//Wetlands
		}
	case 110:
		{
			Plr->EventTeleport(0, -9219.37, -2149.94, 71.606);//Redridge Mountains
		}
	case 115:
		{
			Plr->EventTeleport(1, 1145.85, 664.812, 143);//Stonetalon Mountains
		}
	case 111:
		{
			Plr->EventTeleport(1, -4932.53, -1596.05, 85.8157);//Thousand Needles
		}
	case 112:
		{
			Plr->EventTeleport(0, -852.854, -476.712, 21.0293);//Hillsbrad FootHills
		}
	case 113:
		{
			Plr->EventTeleport(0, -11634.8, -54.0697, 14.4439);//Stranglethorn Vale
		}
	case 114:
		{
			Plr->EventTeleport(1, -3463.26, -4123.13, 18.1043);//Dustwallow Marsh
		}
	case 116:
		{
			Plr->EventTeleport(0, -907.865, -3534.24, 84.7878);//Arathi Highlands
		}
	case 117:
		{
			Plr->EventTeleport(0, 605.154419, -544.123718, 180.993546);//Alterac Mountains
		}
	case 118:
		{
			Plr->EventTeleport(1, -93.1614, 1691.15, 90.0649);//Desolace
		}
	case 119:
		{
			Plr->EventTeleport(0, -10386.364258, -2696.552002, 21.678616);//Swamp of Sorrows
		}
	case 120:
		{
			Plr->EventTeleport(0, -6718.770020, 2897.629883, 240.968994);//Badlands
		}
	case 121:
		{
			Plr->EventTeleport(0, -7176.63, -937.667, 171.206);//Searing Gorge
		}
	case 122:
		{
			Plr->EventTeleport(1, -4458.93, 243.415, 65.6136);//Feralas
		}
	case 123:
		{
			Plr->EventTeleport(1, -7373.69, -2950.2, 11.7598);//Tanaris
		}
	case 124:
		{
			Plr->EventTeleport(1, 2717.1, -5968.91, 107.4);//Azshara
		}
	case 125:
		{
			Plr->EventTeleport(0, -11204.5, -2730.61, 15.8972);//Blasted Lands
		}
	case 126:
		{
			Plr->EventTeleport(0, -1470.011841, -2433.027344, 56.957726);//THe hinterlands
		}
	case 127:
		{
			Plr->EventTeleport(1, 5483.9, -749.881, 335.621);//Felwood
		}
	case 128:
		{
			Plr->EventTeleport(1, -7932.49, -2139.61, -229.728);//Un'goro Crater
		}
	case 129:
		{
			Plr->EventTeleport(1, 6107.62, -4181.6, 853.322);//Winterspring
		}

	case 130:
		{
			Plr->EventTeleport(0, 1681.034424, -1351.699097, 69.970734);//Western Plaguelands
		}
	case 131:
		{
			Plr->EventTeleport(0, 2146.286621, -4612.257324, 73.616341);//Easter Plaguelands
		}
	case 132:
		{
			Plr->EventTeleport(0, -10435.4, -1809.28, 101);//Deadwind Pass
		}
	case 133:
		{
			Plr->EventTeleport(1, -6815.673340, 574.579590, 0.475035);//Silithus
		}
	case 134:
		{
			Plr->EventTeleport(530, -247.451, 940.898, 85.3784);//Hellfire Peninsula
		}
	case 135:
		{
			Plr->EventTeleport(530, 30.4181, 6983.48, 149.681);//Zangarmarsh
		}
	case 136:
		{
			Plr->EventTeleport(530, -1177, 5336, 31);//Terrokar Forest
		}
	case 137:
		{
			Plr->EventTeleport(530,-526, 8440, 48);//Nagrand
		}
	case 138:
		{
			Plr->EventTeleport(530, 114, 7091, 124);//Blades edge
		}
	case 139:
		{
			Plr->EventTeleport(530, -2848, 3190, 9);//SMV
		}
	case 140:
		{
			Plr->EventTeleport(530, 2280.68, 2520.75, 116.278);//Netherstorm
		}
	case 141:
		{
			Plr->EventTeleport(571, 592, -5095, 6);//Howling Fjord
		}
	case 142:
		{
			Plr->EventTeleport(571, 3264.091797, 5284.359375, 39.542316);//Borean Tundra
		}
	case 143:
		{
			Plr->EventTeleport(571, 3663.682129, -2957.966309, 237.322754);//Grizzly Hills
		}
	case 144:
		{
			Plr->EventTeleport(571, 4640.42, -1599.92, 308.369);//Zul'drak
		}
	case 145:
		{
			Plr->EventTeleport(571, 6054.439941, 4615.700195, -93.476799);//Sholazar Basin
		}
	case 146:
		{
			Plr->EventTeleport(571, 5772.079102, 658.282166, 160.944672);//Crystalsong
		}
	case 147:
		{
			Plr->EventTeleport(571, 7031.700195, -1708.569946, 822.164978);//StormPeaks
		}
	case 148:
		{
			Plr->EventTeleport(571, 7757.279785, 2175.031006, 364.403900);//IceCrown
		}
	
	case 149:
			{
				Plr->EventTeleport(1, 4386.642090, -2087.177490, 1206.338); // ALLY HYJAL
			}break;
	case 150:
			{
				Plr->EventTeleport(1, 4680.730469, -2062.343262, 1222.23); // HORDE HYJAL
			}break;
}

}

void NoobHelper::GossipEnd(Object * pObject, Player* Plr)
{
    GossipScript::GossipEnd(pObject, Plr);
}

void SetupNoobHelper(ScriptMgr * mgr)
{
    GossipScript * gs = (GossipScript*) new NoobHelper();
    mgr->register_gossip_script(90000008,gs);
}
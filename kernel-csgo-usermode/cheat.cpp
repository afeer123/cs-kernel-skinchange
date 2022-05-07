#include "cheat.hpp"
#include<array>
#include<thread>
#include"vector.h"

#include <Windows.h>



//HANDLE pHandle;
ULONG process_id;
ULONG engine_base;
ULONG client_base;
//UINT GetModelIndexByID(const short knifeID);
//UINT knifeIndex = 0;
//UINT gloveIndex = 0;
//bool isGetted = false;



constexpr Vector3 CalculateAngle(
    const Vector3& localPosition,
    const Vector3& enemyPosition,
    const Vector3& viewAngles) noexcept
{
    return ((enemyPosition - localPosition).ToAngle() - viewAngles);
}

void Mouse_Move(int x, int y)
{
    double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
    double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
    double fx = x * (65535.0f / fScreenWidth);
    double fy = y * (65535.0f / fScreenHeight);
    mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, fx, fy, 0, 0);
}


void cheat::run()
{
	printf("[提示]: 正在寻找csgo进程...\n");
	process_id = memory::get_process_id_by_name("csgo.exe");

	if (process_id)
	{
		printf("[提示]: CSGO进程: %d\n", process_id);
		printf("[提示]: 寻找client.dll...\n");
		client_base = driver_control::get_client_base(process_id);
		printf("[提示]: 寻找engine.dll...\n");
		engine_base = driver_control::get_engine_base(process_id);
		if (client_base)
		{
			printf("[提示]: client.dll成功: 0x%x\n", client_base);
			
			if(engine_base)
				printf("[提示]: engine.dll成功: 0x%x\n", engine_base);
				printf("[提示]: 启动...\n");


                int flashDur = 0;
                int def = 0;
                int i = 0;

                for (;;)
                {
                    ULONG my_player = driver_control::read_memory<ULONG>(process_id, client_base + dwLocalPlayer);
                    if (my_player <= 0) { continue; }

                    ULONG EnginePointer = driver_control::read_memory<ULONG>(process_id, engine_base + dwClientState);

                    auto GameState = driver_control::read_memory<int>(process_id, EnginePointer + 0x108);

                    const auto& weapons = driver_control::read_memory<std::array<unsigned long, 8>>(process_id, my_player + m_hMyWeapons);

                    ULONG my_team = driver_control::read_memory<ULONG>(process_id, my_player + m_iTeamNum);
                    ULONG my_cross = driver_control::read_memory<ULONG>(process_id, my_player + m_iCrosshairId);

                    if (GameState == clientState.ingame)
                    {
                        for (int i = 0; i < 8; i++)
                        {
                            ULONG weaponEntity = driver_control::read_memory<ULONG>(process_id, my_player + m_hMyWeapons + i * 0x4) & 0xfff;
                            weaponEntity = driver_control::read_memory<ULONG>(process_id, client_base + dwEntityList + (weaponEntity - 1) * 0x10);
                            int accountID = driver_control::read_memory<int>(process_id, weaponEntity + m_OriginalOwnerXuidLow);
                            if (weaponEntity == 0) { continue; }


                            short weaponID = driver_control::read_memory<int>(process_id, weaponEntity + m_iItemDefinitionIndex);

                            printf("",weaponID);
                            ULONG Paintkit = 0;
                            ULONG Seed = 0;
                            ULONG Statrak = 0;
                            ULONG Quality = 0;
                            float Wear = 0;
                            if (weaponID == 0) { continue; } //Weapons
                            else if (weaponID == WEAPON_AK47)
                            {
                                Paintkit = 724;
                                Seed = 513;
                                Statrak = 999;
                                Quality = 3;
                                Wear = 0.3720563881874084f;
                            }
                            else if (weaponID == WEAPON_GLOCK)
                            {
                                Paintkit = 38;
                                Seed = 449;
                                Statrak = 999;
                                Quality = 3;
                                Wear = 0.0003f;
                            }
                            else if (weaponID == WEAPON_USP_SILENCER)
                            {
                                Paintkit = 653;
                                Seed = 125;
                                Statrak = 999;
                                Quality = 3;
                                Wear = 0.0003f;
                            }
                            else if (weaponID == WEAPON_FAMAS)
                            {
                                Paintkit = 919;
                                Seed = 881;
                                Statrak = 999;
                                Quality = 3;
                                Wear = 0.0003f;
                            }
                            else if (weaponID == WEAPON_DEAGLE)
                            {
                                Paintkit = 1090;
                                Seed = 150;
                                Statrak = 1314;
                                Quality = 3;
                                Wear = 0.0680f;
                            }
                            else if (weaponID == WEAPON_MP9)
                            {
                                Paintkit = 1134;
                                Seed = 581;
                                Statrak = 999;
                                Quality = 3;
                                Wear = 0.0003f;
                            }
                            else if (weaponID == WEAPON_MAC10)
                            {
                                Paintkit = 898;
                                Seed = 997;
                                Statrak = 999;
                                Quality = 3;
                                Wear = 0.0003f;
                            }
                            else if (weaponID == WEAPON_GALILAR)
                            {
                                Paintkit = 661;
                                Seed = 739;
                                Statrak = 999;
                                Quality = 3;
                                Wear = 0.0003f;
                            }
                            else if (weaponID == WEAPON_AWP)
                            {
                                Paintkit = 344;
                                Seed = 83;
                                Statrak = 999;
                                Quality = 3;
                                Wear = 0.06983334f;
                            }
                            else if (weaponID == WEAPON_M4A1_SILENCER)
                            {
                                Paintkit = 946;
                                Seed = 938;
                                Statrak = 999;
                                Quality = 3;
                                Wear = 0.06983334f;
                            }
                            else if (weaponID == WEAPON_SSG08)
                            {
                                Paintkit = 624;
                                Seed = 536;
                                Statrak = 999;
                                Quality = 3;
                                Wear = 0.06983334f;
                            }
                            else if (weaponID == WEAPON_M4A1)
                            {
                                Paintkit = 309;
                                Seed = 901;
                                Statrak = 999;
                                Quality = 3;
                                Wear = 0.05983334f;
                            }
                            else if (weaponID == WEAPON_NEGEV)
                            {
                            Paintkit = 763;
                            Seed = 189;
                            Statrak = 999;
                            Quality = 3;
                            Wear = 0.05983334f;
                            }
                            else if (weaponID == WEAPON_MAG7)
                            {
                            Paintkit = 737;
                            Seed = 432;
                            Statrak = 999;
                            Quality = 3;
                            Wear = 0.05983334f;
                            }
                            else if (weaponID == WEAPON_XM1014)
                            {
                            Paintkit = 393;
                            Seed = 456;
                            Statrak = 999;
                            Quality = 3;
                            Wear = 0.05983334f;
                            }
                            else if (weaponID == WEAPON_NOVA)
                            {
                            Paintkit = 537;
                            Seed = 417;
                            Statrak = 999;
                            Quality = 3;
                            Wear = 0.05983334f;
                            }
                            else if (weaponID == WEAPON_BIZON)
                            {
                            Paintkit = 542;
                            Seed = 760;
                            Statrak = 999;
                            Quality = 3;
                            Wear = 0.05983334f;
                            }
                            else if (weaponID == WEAPON_P90)
                            {
                            Paintkit = 156;
                            Seed = 732;
                            Statrak = 999;
                            Quality = 3;
                            Wear = 0.05983334f;
                            }
                            else if (weaponID == WEAPON_SG556)
                            {
                            Paintkit = 750;
                            Seed = 138;
                            Statrak = 999;
                            Quality = 3;
                            Wear = 0.05983334f;
                            }
                            else if (weaponID == WEAPON_AUG)
                            {
                            Paintkit = 455;
                            Seed = 479;
                            Statrak = 999;
                            Quality = 3;
                            Wear = 0.05983334f;
                            }
                            else if (weaponID == WEAPON_TEC9)
                            {
                            Paintkit = 889;
                            Seed = 887;
                            Statrak = 999;
                            Quality = 3;
                            Wear = 0.05983334f;
                            }
                            else if (weaponID == WEAPON_FIVESEVEN)
                            {
                            Paintkit = 295;
                            Seed = 660;
                            Statrak = 999;
                            Quality = 3;
                            Wear = 0.05983334f;
                            }
                            else if (weaponID == WEAPON_P250)
                            {
                            Paintkit = 678;
                            Seed = 852;
                            Statrak = 999;
                            Quality = 3;
                            Wear = 0.05983334f;
                            }
                            //else if (weaponID != WEAPON_KNIFE && weaponID != WEAPON_KNIFE_T && weaponID != WEAPON_KNIFE_M9_BAYONET) { continue; }
                            //else
                            //{
                            //    Paintkit = 413;
                            //    Seed = 152;
                            //    Statrak = 999;
                            //    Quality = 3;
                            //    Wear = 0.0003f;

                            //    driver_control::write_memory<short>(process_id,weaponEntity + m_iItemDefinitionIndex, WEAPON_KNIFE_M9_BAYONET); //Knife Name
                            //    driver_control::write_memory(process_id,weaponEntity + m_nModelIndex, knifeIndex);
                            //}
                            if (driver_control::read_memory<int>(process_id, weaponEntity + m_iItemIDHigh) != -1)
                            {
                                driver_control::write_memory<int>(process_id, weaponEntity + m_iItemIDHigh, -1);
                            }

                            driver_control::write_memory<int>(process_id, weaponEntity + m_iAccountID, accountID);
               
                            driver_control::write_memory<ULONG>(process_id, weaponEntity + m_nFallbackPaintKit, Paintkit);
                            driver_control::write_memory<int>(process_id, weaponEntity + m_nFallbackSeed, Seed);
                            driver_control::write_memory<float>(process_id, weaponEntity + m_flFallbackWear, Wear);
                            driver_control::write_memory<int>(process_id, weaponEntity + m_nFallbackStatTrak, Statrak);
                            driver_control::write_memory<int>(process_id, weaponEntity + m_iEntityQuality, Quality);

                            /*       if (CustomName != "")
                                   {
                                       WriteProcessMemory(pHandle, (LPVOID)(weaponEntity + m_szCustomName), CustomName, sizeof(char[20]), NULL);
                                   }*/
                            //if (isGetted == false)
                            //{
                            //    knifeIndex = GetModelIndexByID(WEAPON_KNIFE_M9_BAYONET); //Knife Model
                            //    isGetted = true;
                            //}


                           /* UINT iCurWeaponAdress = driver_control::read_memory<UINT>(process_id, my_player + m_hActiveWeapon) & 0xFFF;
                            UINT m_iBase = driver_control::read_memory<UINT>(process_id, client_base + m_dwEntityList + (iCurWeaponAdress - 1) * 0x10);
                            short curwpnID = driver_control::read_memory<short>(process_id, m_iBase + m_iItemDefinitionIndex);

                            if (curwpnID == WEAPON_KNIFE || curwpnID == WEAPON_KNIFE_T || curwpnID == WEAPON_KNIFE_M9_BAYONET)
                            {
                                DWORD knifeViewModel = driver_control::read_memory<DWORD>(process_id, my_player + m_hViewModel) & 0xfff;
                                knifeViewModel = driver_control::read_memory<DWORD>(process_id, client_base + m_dwEntityList + (knifeViewModel - 1) * 0x10);

                                if (knifeViewModel == 0) { continue; }

                                driver_control::write_memory<DWORD>(process_id,knifeViewModel + m_nModelIndex, knifeIndex);
                            }*/

                            if (GetAsyncKeyState(VK_HOME) & 1)
                            {
                                ULONG  _dwClientState = driver_control::read_memory<ULONG>(process_id, engine_base + dwClientState);
                                driver_control::write_memory<ULONG>(process_id, _dwClientState + 0x174, -1);
                            }
           

                            /*if (my_cross >= 1 && my_cross <= 64)
                            {
                                ULONG entity = driver_control::read_memory<ULONG>(process_id, client_base + m_dwEntityList + ((my_cross - 1) * 0x10));
                                if (entity <= 0) { continue; }

                                ULONG entity_health = driver_control::read_memory<ULONG>(process_id, entity + m_iHealth);
                                ULONG entity_team = driver_control::read_memory<ULONG>(process_id, entity + m_iTeamNum);

                                if (entity_health > 0 && entity_team != my_team && entity_team > 1 GetAsyncKeyState(VK_HOME))
                                {
                                    Sleep(3);
                                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                                    Sleep(1);
                                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                                }
                            }
                            Sleep(1);*/
                        }
                    }
                   
                }

		}
		else
		{
			printf("[错误]: 没有找到 client.dll\n");
		}
	}
	else
	{
		printf("[错误]: 没有 csgo.exe process\n");
	}
}

//UINT GetModelIndex(const char* modelName)
//{
//    int ClientState = driver_control::read_memory<UINT>(process_id, engine_base + m_dwClientState);
//    int m_pModelPrecacheTable = driver_control::read_memory<UINT>(process_id, ClientState + 0x52A4);
//    int nsd = driver_control::read_memory<UINT>(process_id, m_pModelPrecacheTable + 0x40);
//    int m_pItems = driver_control::read_memory<UINT>(process_id, nsd + 0xC);
//    int xxxxx = m_pItems + 0xC;
//
//    for (UINT i = 0; i < 1024; i++)
//    {
//        int nsdi_i = driver_control::read_memory<UINT>(process_id, xxxxx + (i * 0x34));
//        char str[128] = { 0 };
//        if (ReadProcessMemory(pHandle, (LPCVOID)nsdi_i, str, sizeof(str), NULL))
//        {
//            if (_stricmp(str, modelName) == 0)
//            {
//                return i;
//            }
//        }
//    }
//    return 0;
//}
//
//UINT GetModelIndexByID(const short knifeID)
//{
//    UINT modelIndex = 0;
//    switch (knifeID)
//    {
//    case WEAPON_KNIFE:
//        modelIndex = GetModelIndex("models/weapons/v_knife_default_ct.mdl");
//        break;
//    case WEAPON_KNIFE_T:
//        modelIndex = GetModelIndex("models/weapons/v_knife_default_t.mdl");
//        break;
//    case WEAPON_KNIFE_BAYONET:
//        modelIndex = GetModelIndex("models/weapons/v_knife_bayonet.mdl");
//        break;
//    case WEAPON_KNIFE_BUTTERFLY:
//        modelIndex = GetModelIndex("models/weapons/v_knife_butterfly.mdl");
//        break;
//    case WEAPON_KNIFE_CANIS:
//        modelIndex = GetModelIndex("models/weapons/v_knife_canis.mdl");
//        break;
//    case WEAPON_KNIFE_CORD:
//        modelIndex = GetModelIndex("models/weapons/v_knife_cord.mdl");
//        break;
//    case WEAPON_KNIFE_CSS:
//        modelIndex = GetModelIndex("models/weapons/v_knife_css.mdl");
//        break;
//    case WEAPON_KNIFE_FALCHION:
//        modelIndex = GetModelIndex("models/weapons/v_knife_falchion_advanced.mdl");
//        break;
//    case WEAPON_KNIFE_FLIP:
//        modelIndex = GetModelIndex("models/weapons/v_knife_flip.mdl");
//        break;
//    case WEAPON_KNIFE_GUT:
//        modelIndex = GetModelIndex("models/weapons/v_knife_gut.mdl");
//        break;
//    case WEAPON_KNIFE_GYPSY_JACKKNIFE:
//        modelIndex = GetModelIndex("models/weapons/v_knife_gypsy_jackknife.mdl");
//        break;
//    case WEAPON_KNIFE_KARAMBIT:
//        modelIndex = GetModelIndex("models/weapons/v_knife_karam.mdl");
//        break;
//    case WEAPON_KNIFE_M9_BAYONET:
//        modelIndex = GetModelIndex("models/weapons/v_knife_m9_bay.mdl");
//        break;
//    case WEAPON_KNIFE_OUTDOOR:
//        modelIndex = GetModelIndex("models/weapons/v_knife_outdoor.mdl");
//        break;
//    case WEAPON_KNIFE_PUSH:
//        modelIndex = GetModelIndex("models/weapons/v_knife_push.mdl");
//        break;
//    case WEAPON_KNIFE_SKELETON:
//        modelIndex = GetModelIndex("models/weapons/v_knife_skeleton.mdl");
//        break;
//    case WEAPON_KNIFE_STILETTO:
//        modelIndex = GetModelIndex("models/weapons/v_knife_stiletto.mdl");
//        break;
//    case WEAPON_KNIFE_SURVIVAL_BOWIE:
//        modelIndex = GetModelIndex("models/weapons/v_knife_survival_bowie.mdl");
//        break;
//    case WEAPON_KNIFE_TACTICAL:
//        modelIndex = GetModelIndex("models/weapons/v_knife_tactical.mdl");
//        break;
//    case WEAPON_KNIFE_URSUS:
//        modelIndex = GetModelIndex("models/weapons/v_knife_ursus.mdl");
//        break;
//    case WEAPON_KNIFE_WIDOWMAKER:
//        modelIndex = GetModelIndex("models/weapons/v_knife_widowmaker.mdl");
//        break;
//    case GLOVE_SPORTY:
//        modelIndex = GetModelIndex("models/weapons/v_models/arms/glove_sporty/v_glove_sporty.mdl");
//        break;
//    default:
//        break;
//    }
//    return modelIndex;
//}
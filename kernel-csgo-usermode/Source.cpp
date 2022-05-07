#include "cheat.hpp"
#include<windows.h>
#include "stdio.h"



 //void installDvr()//安装
 //{
	//     SC_HANDLE schSCManager;
	//     schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	//     if (schSCManager)
	//	     {
	//	         SC_HANDLE schService = CreateService(schSCManager,
	//		
	//		
	//		
	//		 "babaHelloDDKk",
	//		
	//		
	//		
	//		 "babaMyHelloDDKk",
	//		
	//		
	//		
	//		 SERVICE_ALL_ACCESS,
	//		
	//		
	//		
	//		 SERVICE_KERNEL_DRIVER, //创建的服务类型1为驱动服务
	//		
	//		
	//		
	//		 SERVICE_DEMAND_START, //用于当有进程调用StartService 函数时由服务控制管理器(SCM)启动的服务

	//		
	//		
	//		
	//		 SERVICE_ERROR_IGNORE,
	//		
	//		
	//		
	//		 "kernel-csgo.sys",//驱动文件存放路径
	//		
	//		
	//		
	//		 NULL,
	//		
	//		
	//		
	//		 NULL,
	//		
	//		
	//		
	//		 NULL,
	//		
	//		
	//		
	//		 NULL,
	//		
	//		
	//		
	//		 NULL);
	//	         CloseServiceHandle(schService); //创建完记得释放句柄
	//	          if (schService)
	//		        {
	//		             printf("按装服务成功\n");
	//		
	//			     }
	//	         else
	//		        {
	//		            printf("按装服务失败\n");
	//		         }
	//	         CloseServiceHandle(schSCManager);
	//	     }
	//
	//	
 //}
 //void startDvr()//启动
 //{
	//     SC_HANDLE schSCManager;
	//     SC_HANDLE hs;
	//     schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	//     if (schSCManager)
	//	     {
	//	         hs = OpenService(schSCManager, "babaHelloDDKk", SERVICE_ALL_ACCESS); //打开服
	//	
	//		
	//		         if (hs)
	//		         {
	//		             StartService(hs, 0, 0);
	//		             printf("启动服务成功\n");
	//		
	//		             CloseServiceHandle(hs);
	//		         }
	//	     CloseServiceHandle(schSCManager);
	//	     }
	// }
 //void stopDvr()//停止
 //{
	//     SC_HANDLE schSCManager;
	//     SC_HANDLE hs;
	//     schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	//     if (schSCManager)
	//	     {
	//	         hs = OpenService(schSCManager, "babaHelloDDKk", SERVICE_ALL_ACCESS); //打开服
	//	
	//		
	//		         if (hs)
	//		         {
	//		             SERVICE_STATUS status;
	//		             int num = 0;
	//		
	//			             QueryServiceStatus(hs, &status);
	//		             if (status.dwCurrentState != SERVICE_STOPPED &&
	//			
	//			             status.dwCurrentState != SERVICE_STOP_PENDING)
	//				           {
	//			                ControlService(hs, SERVICE_CONTROL_STOP, &status);
	//			                 do
	//				                 {
	//				                     Sleep(50);
	//				                     num++;
	//				                     QueryServiceStatus(hs, &status);
	//				                 }while (status.dwCurrentState != SERVICE_STOPPED || num > 80);
	//				             }
	//		
	//			            if (num > 80)
	//			             {
	//			                 printf("停止服务失败\n");
	//			             }
	//						else
	//			             {
	//			                 printf("停止服务成功\n");
	//			             }
	//		             CloseServiceHandle(hs);
	//		         }
	//	     CloseServiceHandle(schSCManager);
	//     }
	//
 //}
 //void unloadDvr()//卸载
 //{
	//     SC_HANDLE schSCManager;
	//     SC_HANDLE hs;
	//     schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	//     if (schSCManager)
	//	  {
	//	         hs = OpenService(schSCManager, "babaHelloDDKk", SERVICE_ALL_ACCESS); //打开服
	//	
	//		
	//		         if (hs)
	//		         {
	//		             bool a = DeleteService(hs);   //删除服务
	//		             if (!a)
	//			             {
	//			                 printf("删除服务失败\n");
	//			             }
	//		             else
	//			             {
	//			                 printf("已删除服务\n");
	//			             }
	//		
	//			             CloseServiceHandle(hs);//释放完后可完服务可从服务表中消失 释放前是
	//		
	//			        }
	//	     CloseServiceHandle(schSCManager);
	//	  }
 //}

int main()
{
	std::cout << R"(
                     
████████╗██╗███╗   ██╗██████╗ ██╗   ██╗ ██████╗     ███████╗██╗  ██╗██╗███╗   ██╗
╚══██╔══╝██║████╗  ██║██╔══██╗██║   ██║██╔═══██╗    ██╔════╝██║ ██╔╝██║████╗  ██║
   ██║   ██║██╔██╗ ██║██████╔╝██║   ██║██║   ██║    ███████╗█████╔╝ ██║██╔██╗ ██║
   ██║   ██║██║╚██╗██║██╔══██╗██║   ██║██║   ██║    ╚════██║██╔═██╗ ██║██║╚██╗██║
   ██║   ██║██║ ╚████║██║  ██║╚██████╔╝╚██████╔╝    ███████║██║  ██╗██║██║ ╚████║
   ╚═╝   ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝     ╚══════╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝
                                                                                 

)" << '\n';
	std::cout << "V 0.1\n";
	std::cout << "听弱制作\n";

	printf("[提示]: 尊贵的定制用户:占得人间一味愚 欢迎使用听弱驱动定制\n");
	printf("[提示]: 打开游戏进服务器在进行下一步\n");
	system("pause");

	printf("[提示]: 听弱驱动换肤DEMO\n");
	printf("[提示]: 正在注入中...\n");
	LoadLibraryA("user32.dll");
	LoadLibraryA("win32u.dll");
	if (GetModuleHandleA("win32u.dll"))
	{
		printf("[提示]: 注入成功\n");
		printf("[提示]: 听弱驱动DEMO 频道:https://kaihei.co/aWpdSu \n");
		cheat::run();
	}
	else
	{
		printf("[提示]: 注入失败！！\n");
	}
	system("pause");
	return 0;
}
#include "cheat.hpp"
#include<windows.h>
#include "stdio.h"



 //void installDvr()//��װ
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
	//		 SERVICE_KERNEL_DRIVER, //�����ķ�������1Ϊ��������
	//		
	//		
	//		
	//		 SERVICE_DEMAND_START, //���ڵ��н��̵���StartService ����ʱ�ɷ�����ƹ�����(SCM)�����ķ���

	//		
	//		
	//		
	//		 SERVICE_ERROR_IGNORE,
	//		
	//		
	//		
	//		 "kernel-csgo.sys",//�����ļ����·��
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
	//	         CloseServiceHandle(schService); //������ǵ��ͷž��
	//	          if (schService)
	//		        {
	//		             printf("��װ����ɹ�\n");
	//		
	//			     }
	//	         else
	//		        {
	//		            printf("��װ����ʧ��\n");
	//		         }
	//	         CloseServiceHandle(schSCManager);
	//	     }
	//
	//	
 //}
 //void startDvr()//����
 //{
	//     SC_HANDLE schSCManager;
	//     SC_HANDLE hs;
	//     schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	//     if (schSCManager)
	//	     {
	//	         hs = OpenService(schSCManager, "babaHelloDDKk", SERVICE_ALL_ACCESS); //�򿪷�
	//	
	//		
	//		         if (hs)
	//		         {
	//		             StartService(hs, 0, 0);
	//		             printf("��������ɹ�\n");
	//		
	//		             CloseServiceHandle(hs);
	//		         }
	//	     CloseServiceHandle(schSCManager);
	//	     }
	// }
 //void stopDvr()//ֹͣ
 //{
	//     SC_HANDLE schSCManager;
	//     SC_HANDLE hs;
	//     schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	//     if (schSCManager)
	//	     {
	//	         hs = OpenService(schSCManager, "babaHelloDDKk", SERVICE_ALL_ACCESS); //�򿪷�
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
	//			                 printf("ֹͣ����ʧ��\n");
	//			             }
	//						else
	//			             {
	//			                 printf("ֹͣ����ɹ�\n");
	//			             }
	//		             CloseServiceHandle(hs);
	//		         }
	//	     CloseServiceHandle(schSCManager);
	//     }
	//
 //}
 //void unloadDvr()//ж��
 //{
	//     SC_HANDLE schSCManager;
	//     SC_HANDLE hs;
	//     schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	//     if (schSCManager)
	//	  {
	//	         hs = OpenService(schSCManager, "babaHelloDDKk", SERVICE_ALL_ACCESS); //�򿪷�
	//	
	//		
	//		         if (hs)
	//		         {
	//		             bool a = DeleteService(hs);   //ɾ������
	//		             if (!a)
	//			             {
	//			                 printf("ɾ������ʧ��\n");
	//			             }
	//		             else
	//			             {
	//			                 printf("��ɾ������\n");
	//			             }
	//		
	//			             CloseServiceHandle(hs);//�ͷ����������ɴӷ��������ʧ �ͷ�ǰ��
	//		
	//			        }
	//	     CloseServiceHandle(schSCManager);
	//	  }
 //}

int main()
{
	std::cout << R"(
                     
�����������������[�����[�������[   �����[�������������[ �����[   �����[ �������������[     ���������������[�����[  �����[�����[�������[   �����[
�^�T�T�����X�T�T�a�����U���������[  �����U�����X�T�T�����[�����U   �����U�����X�T�T�T�����[    �����X�T�T�T�T�a�����U �����X�a�����U���������[  �����U
   �����U   �����U�����X�����[ �����U�������������X�a�����U   �����U�����U   �����U    ���������������[�����������X�a �����U�����X�����[ �����U
   �����U   �����U�����U�^�����[�����U�����X�T�T�����[�����U   �����U�����U   �����U    �^�T�T�T�T�����U�����X�T�����[ �����U�����U�^�����[�����U
   �����U   �����U�����U �^���������U�����U  �����U�^�������������X�a�^�������������X�a    ���������������U�����U  �����[�����U�����U �^���������U
   �^�T�a   �^�T�a�^�T�a  �^�T�T�T�a�^�T�a  �^�T�a �^�T�T�T�T�T�a  �^�T�T�T�T�T�a     �^�T�T�T�T�T�T�a�^�T�a  �^�T�a�^�T�a�^�T�a  �^�T�T�T�a
                                                                                 

)" << '\n';
	std::cout << "V 0.1\n";
	std::cout << "��������\n";

	printf("[��ʾ]: ���Ķ����û�:ռ���˼�һζ�� ��ӭʹ��������������\n");
	printf("[��ʾ]: ����Ϸ���������ڽ�����һ��\n");
	system("pause");

	printf("[��ʾ]: ������������DEMO\n");
	printf("[��ʾ]: ����ע����...\n");
	LoadLibraryA("user32.dll");
	LoadLibraryA("win32u.dll");
	if (GetModuleHandleA("win32u.dll"))
	{
		printf("[��ʾ]: ע��ɹ�\n");
		printf("[��ʾ]: ��������DEMO Ƶ��:https://kaihei.co/aWpdSu \n");
		cheat::run();
	}
	else
	{
		printf("[��ʾ]: ע��ʧ�ܣ���\n");
	}
	system("pause");
	return 0;
}
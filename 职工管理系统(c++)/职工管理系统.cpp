#include <iostream>
using namespace std;
#include "WorkManager(�˵�).h"
#include"Worker(Ա��������).h"
#include"employee(��ͨԱ��).h"
#include"boss.h"
#include"manager(����).h"
int main()
{
	while (1)
	{
		WorkManager wm;
		wm.Show_Menu();
		int choice = 0;
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch(choice)
		{
		//0.�˳�����ϵͳ
		case 0:
			wm.ExitSystem();
			break;
	    //1.����ְ����Ϣ
		case 1:
			wm.Add_Emp();
			break;
		//2.��ʾְ����Ϣ
		case 2:
			wm.Show_Emp();
			break;
		//3.ɾ����ְְ��
		case 3:wm.Del_Emp();
			break;
		//4.�޸�ְ����Ϣ
		case 4:
			wm.Mod_Emp();
			break;
		//5.����ְ����Ϣ
		case 5:
			wm.Find_Emp();
			break;
		//6.���ձ������
		case 6:
			wm.SortEmp();
			break;
		//7.��������ĵ�
		case 7:
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");//��������
	return 0;
}
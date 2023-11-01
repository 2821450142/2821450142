#include <iostream>
using namespace std;
#include "WorkManager(菜单).h"
#include"Worker(员工抽象类).h"
#include"employee(普通员工).h"
#include"boss.h"
#include"manager(经理).h"
int main()
{
	while (1)
	{
		WorkManager wm;
		wm.Show_Menu();
		int choice = 0;
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch(choice)
		{
		//0.退出管理系统
		case 0:
			wm.ExitSystem();
			break;
	    //1.增加职工信息
		case 1:
			wm.Add_Emp();
			break;
		//2.显示职工信息
		case 2:
			wm.Show_Emp();
			break;
		//3.删除离职职工
		case 3:wm.Del_Emp();
			break;
		//4.修改职工信息
		case 4:
			wm.Mod_Emp();
			break;
		//5.查找职工信息
		case 5:
			wm.Find_Emp();
			break;
		//6.按照编号排序
		case 6:
			wm.SortEmp();
			break;
		//7.清空所有文档
		case 7:
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");//清屏操作
	return 0;
}
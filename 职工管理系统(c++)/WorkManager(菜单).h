#pragma once//防止头文件重复包含
#include <iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include "Worker(员工抽象类).h"
#include"boss.h"
#include"employee(普通员工).h"
#include"manager(经理).h"
#include <fstream>
#define FILENAME "Siberian husky.txt" //文件名称
class WorkManager
{
public:
	//构造函数
	WorkManager();
	//展示菜单
	void Show_Menu();
	//关闭页面
	void ExitSystem();
	//记录职工人数
	int m_EmpNum;
	// 添加职工人数
	void Add_Emp();
	//职工数组指针
	Worker** m_EmpArray;
	bool IsId_emp(Worker** New, int id,int k);
	bool IsName_emp(Worker** New, string name,int k);
	//保存文件
	void save();
	//判断文件是否为空 标志
	bool m_FileIsEmpty;
	//统计文件中的人数
	int get_EmpNum();
	//初始化职工
	void init_Emp();
	//显示职工的函数
	void Show_Emp();
	//删除功能
	void Del_Emp();
	//判断职工编号是否存在，不存在返回-1，存在返回1.
	int IsExist(int id);
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//判断职工姓名是否存在，不存在返回false，存在返回true.
	bool IsName_Emp(string name);
	//判断职工Id是否存在，不存在返回false，存在返回true.
	bool IsId_Emp(int id);
	//排序职工
	void SortEmp();
	//清空操作
	void Clean_File();
	//析构函数
	~WorkManager();
};

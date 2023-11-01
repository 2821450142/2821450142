#pragma once
#include <iostream>//包含输入输出流头文件
#include"Worker(员工抽象类).h"
using namespace std;//使用标准命名空间
class Employee :public Worker
{
public:
	//构造函数
	Employee(int id,string name,int dId);
	//显示员工信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getdeptName();
};
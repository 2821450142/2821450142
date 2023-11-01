#pragma once
#include<iostream>
#include"Worker(员工抽象类).h"
#include<string>
using namespace std;

class Boss :public Worker
{
public:
	//构造函数
	Boss(int id, string name, int dId);
	//显示员工信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getdeptName();
};
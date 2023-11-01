#pragma once//防止头文件重复包含
#include <iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
//职工抽象基类
class Worker
{
public:
	//显示员工信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getdeptName() = 0;
	int m_Id;//员工编号
	string m_Name;//员工姓名
	int m_DeptId;//员工所在部门名称编号
};
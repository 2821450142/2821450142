#include"boss.h"
//构造函数
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//显示员工信息
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_Id<<"    ";
	cout << "\t职工姓名：" << this->m_Name<<"    ";
	cout << "\t职工岗位：" << this->getdeptName()<<"    ";
	cout << "\t员工职责：狠狠的殴打不听话员工，压榨老实工作的员工！" << endl;
}
//获取岗位名称
string Boss::getdeptName()
{
	return string("老板");
}
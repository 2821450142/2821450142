#include"manager(经理).h"
//构造函数
Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//显示员工信息
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id << "    ";
	cout << "\t职工姓名：" << this->m_Name << "    ";
	cout << "\t职工岗位：" << this->getdeptName() << "    ";
	cout << "\t员工职责：天天就我挨次，我真的服了！" << endl;
}
//获取岗位名称
string Manager::getdeptName()
{
	return string("经理");
}
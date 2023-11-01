#include"employee(普通员工).h"
//构造函数
Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//显示员工信息
void Employee::showInfo()
{
	cout << "职工编号：" << this->m_Id << "    ";
	cout << "\t职工姓名：" << this->m_Name << "    ";
	cout << "\t职工岗位：" << this->getdeptName() << "    ";
	cout << "\t员工职责：天天加班，不听话就挨揍，一干活就干到晚上，我真的服了！" << endl;
}
//获取岗位名称
string Employee::getdeptName()
{
	return string("员工");
}
#include"employee(��ͨԱ��).h"
//���캯��
Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//��ʾԱ����Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id << "    ";
	cout << "\tְ��������" << this->m_Name << "    ";
	cout << "\tְ����λ��" << this->getdeptName() << "    ";
	cout << "\tԱ��ְ������Ӱ࣬�������Ͱ��ᣬһ�ɻ�͸ɵ����ϣ�����ķ��ˣ�" << endl;
}
//��ȡ��λ����
string Employee::getdeptName()
{
	return string("Ա��");
}
#include"manager(����).h"
//���캯��
Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//��ʾԱ����Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id << "    ";
	cout << "\tְ��������" << this->m_Name << "    ";
	cout << "\tְ����λ��" << this->getdeptName() << "    ";
	cout << "\tԱ��ְ��������Ұ��Σ�����ķ��ˣ�" << endl;
}
//��ȡ��λ����
string Manager::getdeptName()
{
	return string("����");
}
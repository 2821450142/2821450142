#include"boss.h"
//���캯��
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//��ʾԱ����Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id<<"    ";
	cout << "\tְ��������" << this->m_Name<<"    ";
	cout << "\tְ����λ��" << this->getdeptName()<<"    ";
	cout << "\tԱ��ְ�𣺺ݺݵ�Ź������Ա����ѹե��ʵ������Ա����" << endl;
}
//��ȡ��λ����
string Boss::getdeptName()
{
	return string("�ϰ�");
}
#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
//ְ���������
class Worker
{
public:
	//��ʾԱ����Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getdeptName() = 0;
	int m_Id;//Ա�����
	string m_Name;//Ա������
	int m_DeptId;//Ա�����ڲ������Ʊ��
};
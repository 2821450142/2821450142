#pragma once
#include <iostream>//�������������ͷ�ļ�
#include"Worker(Ա��������).h"
using namespace std;//ʹ�ñ�׼�����ռ�
class Employee :public Worker
{
public:
	//���캯��
	Employee(int id,string name,int dId);
	//��ʾԱ����Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getdeptName();
};
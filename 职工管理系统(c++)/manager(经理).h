#pragma once
#include<iostream>
#include"Worker(Ա��������).h"
using namespace std;
class Manager:public Worker
{
public:
	//���캯��
	Manager(int id,string name,int dId);
	//��ʾԱ����Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getdeptName();
};
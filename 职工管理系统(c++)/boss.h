#pragma once
#include<iostream>
#include"Worker(Ա��������).h"
#include<string>
using namespace std;

class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int dId);
	//��ʾԱ����Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getdeptName();
};
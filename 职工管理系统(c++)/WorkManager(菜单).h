#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include "Worker(Ա��������).h"
#include"boss.h"
#include"employee(��ͨԱ��).h"
#include"manager(����).h"
#include <fstream>
#define FILENAME "Siberian husky.txt" //�ļ�����
class WorkManager
{
public:
	//���캯��
	WorkManager();
	//չʾ�˵�
	void Show_Menu();
	//�ر�ҳ��
	void ExitSystem();
	//��¼ְ������
	int m_EmpNum;
	// ���ְ������
	void Add_Emp();
	//ְ������ָ��
	Worker** m_EmpArray;
	bool IsId_emp(Worker** New, int id,int k);
	bool IsName_emp(Worker** New, string name,int k);
	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsEmpty;
	//ͳ���ļ��е�����
	int get_EmpNum();
	//��ʼ��ְ��
	void init_Emp();
	//��ʾְ���ĺ���
	void Show_Emp();
	//ɾ������
	void Del_Emp();
	//�ж�ְ������Ƿ���ڣ������ڷ���-1�����ڷ���1.
	int IsExist(int id);
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//�ж�ְ�������Ƿ���ڣ������ڷ���false�����ڷ���true.
	bool IsName_Emp(string name);
	//�ж�ְ��Id�Ƿ���ڣ������ڷ���false�����ڷ���true.
	bool IsId_Emp(int id);
	//����ְ��
	void SortEmp();
	//��ղ���
	void Clean_File();
	//��������
	~WorkManager();
};

#include"WorkManager(�˵�).h"
WorkManager::WorkManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open())//is_open()���ܴ򿪷��ء��񡰣�
	{
		//��ʼ������
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2���ļ���������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//��ʼ������
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3���ļ����� ���Ҽ�¼����
	int num = this->get_EmpNum();
	this->m_EmpNum= num;
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum]; //�������ָ��ָ����һ��ָ��
	//���ļ����ݣ��浽������
	this->init_Emp();
}
void WorkManager::Show_Menu()
{
	cout << "��������������������������������������������" << endl;
	cout << "        ��ӭʹ��Ź��ְ������ϵͳ            " << endl;
	cout << "            0.�˳�����ϵͳ                  " << endl;
	cout << "   ��       1.����ְ����Ϣ        ��        " << endl;
	cout << "   ��       2.��ʾְ����Ϣ        ��        " << endl;
	cout << "   ��       3.ɾ����ְְ��        ��        " << endl;
	cout << "   ��       4.�޸�ְ����Ϣ        ��        " << endl;
	cout << " (���� ��)   5.����ְ����Ϣ     (���� ��)    " << endl;
	cout << "            6.���ձ������                  " << endl;
	cout << "            7.��������ĵ�                  " << endl;
	cout << "        ��(��������)(��������)��            " << endl;
	cout << endl;
}
//�˳�����
void WorkManager::ExitSystem()
{
	cout << "��ӭ���´�ʹ�ã�" << endl;
	system("pause"); 
	exit(0);//�˳�����
}
//�ж�ְ�������Ƿ���ڣ������ڷ���false�����ڷ���true.
bool WorkManager::IsName_Emp(string name)
{
	bool ret = false;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Name == name)
		{
			ret = true;
			break;
		}
	}
	return ret;
}
bool WorkManager::IsName_emp(Worker **New,string name,int k)
{
	bool ret = false;
	for (int i = 0; i < k; i++)
	{
		if (New[i]->m_Name == name)
		{
			ret = true;
			break;
		}
	}
	return ret;
}
//�ж�ְ��Id�Ƿ���ڣ������ڷ���false�����ڷ���true.
bool WorkManager::IsId_Emp(int id)
{
	bool ret = false;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			ret = true;
			break;
		}
	}
	return ret;
}
bool WorkManager::IsId_emp(Worker **New,int id,int k)
{
	bool ret = false;
	for (int i = 0; i < k; i++)
	{
		if (New[i]->m_Id == id)
		{
			ret = true;
			break;
		}
	}
	return ret;
}
//�ж�ְ���Ƿ���ڣ����ڲ�����-1�����ڷ���1.
int WorkManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
//�����ļ�
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�---д�ļ�
	//��ÿ���˵�����д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl; //��������ļ���Ҳ����
	}
	//�ر��ļ�
	ofs.close();
}
//���ְ��
void WorkManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;
	if (addNum >0)
	{
		//���
		//�����¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;//�¿ռ�Ĵ�С=ԭ����¼����+��������
		//�����¿ռ�
	    Worker ** newSpace=new Worker* [newSize];
	//��ԭ�����ݿ������¿ռ���
	      if (this->m_EmpNum != NULL)
	       {
		     for (int i = 0; i < this->m_EmpNum; i++)
		     {
			    newSpace[i] = this->m_EmpArray[i]; // ��ԭ��������ָ�뿽�����µ�����ָ��
	         }
	       }
		  //�������������
		  for (int i = 0; i < addNum; i++)
		  {
			  int id=0;//ְ�����
			  string name="";//ְ������
			  int dSelect=0;//ְ������
			  cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			  cin >> id;
			  if (this->IsId_emp(newSpace, id,this->m_EmpNum+i))
			  {
				  i--;
				  cout << "����ı�����У����������룡" << endl;
				  continue;
			  }
			  tool:
			  cout << "�������" << i + 1 << "����ְ��������" << endl;
			  cin >> name;
			  if (this->IsName_emp(newSpace, name,this->m_EmpNum+i))
			  {
				  cout << "������������У����������룡" << endl;
				  goto tool;
			  }gangwei:
			  cout << "��ѡ���ְ���ĸ�λ" << endl;
			  cout << "1����ͨԱ��" << endl;
			  cout << "2������" << endl;
			  cout << "3���ϰ�" << endl;
			  cin >> dSelect;
			  if (dSelect != 1 && dSelect != 2 && dSelect != 3)
			  {
				  cout << "�������������������룡" << endl;
				  goto gangwei;
			  }
			  Worker* worker = NULL;
			  switch (dSelect)
			  {
			  case 1:
				  worker = new Employee(id, name, 1);
				  break;
			  case 2:
				  worker = new Manager(id, name, 2);
				  break;
			  case 3:
				  worker = new Boss(id, name, 3);
				  break;
			  default:
				  break;
			  }
			  //������ְ��ָ�룬���浽������
			  newSpace[this->m_EmpNum + i] = worker; //����������� ��ԭ���ĺ��¼���ĺϲ���һ��
		  }
		  //�ͷ�ԭ�ռ�
		  delete[]this->m_EmpArray;
		  //�����¿ռ��ָ��
		  this->m_EmpArray = newSpace;
		  //�����µ�ְ������
		  this->m_EmpNum = newSize;
		  //����ְ����Ϊ�ձ�־
		  this->m_FileIsEmpty = false;
		  //��ʾ��ӳɹ�
		  cout << "�ɹ����" << addNum << "����ְ��" << endl;
		  //���������ļ���
		  this->save();
	}
	else
		cout << "�������" << endl;
	//������� ��������
	system("pause");
	system("cls");
}
//ͳ���ļ��е�����
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//���ļ� ��
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//ͳ������
		num++;
	}
	ifs.close();
	return num;
}
//��ʼ��ְ��
void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//���ļ� ��
	int id;
	int dId; //��˾���
	string name;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker=NULL;
		if (dId == 1)//��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId==2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else 
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	//�ر��ļ� 
	ifs.close();
}
//��ʾְ���ĺ���
void WorkManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ýӿڳ���
			this->m_EmpArray[i]->showInfo();
		}
	}
	//�������������
	system("pause");
	system("cls");
}
//ɾ������
void WorkManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		//����ְ����Ž���ɾ��
		cout << "��������Ҫɾ���˵ı�ţ�" << endl;
		int id=0;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1)//˵��ְ�����ڣ�����Ҫɾ�������
		{
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else//˵��������
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ����ˣ�" << endl;
		}
	}
	//������� ����
	system("pause");
	system("cls");
}
//�޸�ְ��
void WorkManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�������Ϊ��" << endl;
	}
	else
	{
		cout << "���������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;
		int ret=this->IsExist(id);
		if (ret != -1)
		{
			//�޸ı��
			delete this->m_EmpArray[ret];
			int newId=0;
			string newName = " ";
			int dSelect = 0;
			cout << "�鵽��" << id << "��ְ�����������µ�ְ����ţ�" << endl;
			go:
			cin >> newId;
			if (this->IsId_Emp(id))
			{
				cout << "����ı�����У����������룡" << endl;
				goto go;
			}
			tool:
			cout << "�������µ�������" << endl;
			cin >> newName;
			if (this->IsName_Emp(newName))
			{
				cout << "������������У����������룡" << endl;
				goto tool;
			}
			cout << "�������λ��" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch(dSelect)
			{
			case 1: worker = new Employee(newId, newName, dSelect);
				break;
			case 2:worker = new Manager(newId, newName, dSelect);
				break;
			case 3:worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << id << "����޸ĳɹ���" << endl;
			this->save();
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
	//��������
	system("pause");
	system("cls");
}
//����ְ��
void WorkManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�ա�" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "�������ţ�" << endl;
			cin >> id;
			int ret=this->IsExist(id);
			if (ret != -1)
			{
				//�ҵ�ְ��
				cout << "�ҵ�ְ����" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "�鲻�����ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			//������������
			string name;
			cout << "���������ְ����������" << endl;
			cin >> name;
			//����һ���ж��Ƿ�鵽�ı�־
			bool  flag = false;//Ĭ�ϱ�ʾδ�鵽ְ��
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id 
						<<"�ŵ���Ϣ���£�" << endl;
					//������Ϣ�ӿ�
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}

	}
	//������� ��������
	system("pause");
	system("cls");
}
//����ְ��
void WorkManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڣ���������Ϊ�ա�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "����������ʽ��" << endl;
		cout << "1������ְ����Ž�������" << endl;
		cout << "2������ְ����Ž��н���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;//����һ�����ֵ������һ����Сֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			//�ж�һ��ʼ�϶��� ��Сֵ�����ֵ �ǲ��� ��Сֵ�����ֵ ��������ǽ�������
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ��������Ľ����" << endl;
		this->save();//�����Ľ�������浽�ļ���
		this->Show_Emp();
	}
}
//��ղ���
void WorkManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1������ļ�" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽ ɾ���ļ� �����´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			//ɾ����������ָ��
			this->m_EmpNum=0;
			delete [] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}
WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
#include"WorkManager(菜单).h"
WorkManager::WorkManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())//is_open()不能打开返回”否“；
	{
		//初始化属性
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化人数
		this->m_EmpNum = 0;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2、文件存在数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//初始化属性
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化人数
		this->m_EmpNum = 0;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3、文件存在 并且记录数据
	int num = this->get_EmpNum();
	this->m_EmpNum= num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum]; //父类二级指针指向父类一级指针
	//将文件数据，存到数组中
	this->init_Emp();
}
void WorkManager::Show_Menu()
{
	cout << "￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥" << endl;
	cout << "        欢迎使用殴打职工管理系统            " << endl;
	cout << "            0.退出管理系统                  " << endl;
	cout << "   还       1.增加职工信息        别        " << endl;
	cout << "   得       2.显示职工信息        人        " << endl;
	cout << "   是       3.删除离职职工        不        " << endl;
	cout << "   我       4.修改职工信息        行        " << endl;
	cout << " (￣ε ￣)   5.查找职工信息     (￣ε ￣)    " << endl;
	cout << "            6.按照编号排序                  " << endl;
	cout << "            7.清空所有文档                  " << endl;
	cout << "        ～(￣▽￣～)(～￣▽￣)～            " << endl;
	cout << endl;
}
//退出程序
void WorkManager::ExitSystem()
{
	cout << "欢迎您下次使用！" << endl;
	system("pause"); 
	exit(0);//退出程序
}
//判断职工姓名是否存在，不存在返回false，存在返回true.
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
//判断职工Id是否存在，不存在返回false，存在返回true.
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
//判断职工是否存在，存在不返回-1，存在返回1.
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
//保存文件
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件---写文件
	//将每个人的数据写到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl; //这个换行文件中也换行
	}
	//关闭文件
	ofs.close();
}
//添加职工
void WorkManager::Add_Emp()
{
	cout << "请输入添加职工的数量" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;
	if (addNum >0)
	{
		//添加
		//计算新空间的大小
		int newSize = this->m_EmpNum + addNum;//新空间的大小=原来记录人数+新增人数
		//开辟新空间
	    Worker ** newSpace=new Worker* [newSize];
	//将原来数据拷贝到新空间下
	      if (this->m_EmpNum != NULL)
	       {
		     for (int i = 0; i < this->m_EmpNum; i++)
		     {
			    newSpace[i] = this->m_EmpArray[i]; // 将原来的数组指针拷贝到新的数组指针
	         }
	       }
		  //批量添加新数据
		  for (int i = 0; i < addNum; i++)
		  {
			  int id=0;//职工编号
			  string name="";//职工姓名
			  int dSelect=0;//职工部门
			  cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			  cin >> id;
			  if (this->IsId_emp(newSpace, id,this->m_EmpNum+i))
			  {
				  i--;
				  cout << "输入的编号已有，请重新输入！" << endl;
				  continue;
			  }
			  tool:
			  cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			  cin >> name;
			  if (this->IsName_emp(newSpace, name,this->m_EmpNum+i))
			  {
				  cout << "输入的姓名已有，请重新输入！" << endl;
				  goto tool;
			  }gangwei:
			  cout << "请选择该职工的岗位" << endl;
			  cout << "1、普通员工" << endl;
			  cout << "2、经理" << endl;
			  cout << "3、老板" << endl;
			  cin >> dSelect;
			  if (dSelect != 1 && dSelect != 2 && dSelect != 3)
			  {
				  cout << "您输入有误，请重新输入！" << endl;
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
			  //将创建职工指针，保存到数组中
			  newSpace[this->m_EmpNum + i] = worker; //数组的括号内 将原来的和新加入的合并在一起
		  }
		  //释放原空间
		  delete[]this->m_EmpArray;
		  //更改新空间的指向
		  this->m_EmpArray = newSpace;
		  //更新新的职工人数
		  this->m_EmpNum = newSize;
		  //更新职工不为空标志
		  this->m_FileIsEmpty = false;
		  //提示添加成功
		  cout << "成功添加" << addNum << "名新职工" << endl;
		  //保存数据文件中
		  this->save();
	}
	else
		cout << "输入错误。" << endl;
	//按任意键 清屏操作
	system("pause");
	system("cls");
}
//统计文件中的人数
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//打开文件 读
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数
		num++;
	}
	ifs.close();
	return num;
}
//初始化职工
void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//打开文件 读
	int id;
	int dId; //公司编号
	string name;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker=NULL;
		if (dId == 1)//普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId==2)//经理
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
	//关闭文件 
	ifs.close();
}
//显示职工的函数
void WorkManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用接口程序
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}
//删除功能
void WorkManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		//按照职工编号进行删除
		cout << "请输入你要删除人的编号：" << endl;
		int id=0;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1)//说明职工存在，并且要删除这个人
		{
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功！" << endl;
		}
		else//说明不存在
		{
			cout << "删除失败，未找到此人！" << endl;
		}
	}
	//按任意键 清屏
	system("pause");
	system("cls");
}
//修改职工
void WorkManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者数据为空" << endl;
	}
	else
	{
		cout << "请您输入修改职工的编号：" << endl;
		int id;
		cin >> id;
		int ret=this->IsExist(id);
		if (ret != -1)
		{
			//修改编号
			delete this->m_EmpArray[ret];
			int newId=0;
			string newName = " ";
			int dSelect = 0;
			cout << "查到：" << id << "号职工，请输入新的职工编号：" << endl;
			go:
			cin >> newId;
			if (this->IsId_Emp(id))
			{
				cout << "输入的编号已有，请重新输入！" << endl;
				goto go;
			}
			tool:
			cout << "请输入新的姓名：" << endl;
			cin >> newName;
			if (this->IsName_Emp(newName))
			{
				cout << "输入的姓名已有，请重新输入！" << endl;
				goto tool;
			}
			cout << "请输入岗位：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			cout << id << "编号修改成功！" << endl;
			this->save();
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}
	//清屏操作
	system("pause");
	system("cls");
}
//查找职工
void WorkManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空。" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照编号查
			int id;
			cout << "请输入编号：" << endl;
			cin >> id;
			int ret=this->IsExist(id);
			if (ret != -1)
			{
				//找到职工
				cout << "找到职工！" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查不到此人！" << endl;
			}
		}
		else if (select == 2)
		{
			//按照姓名查找
			string name;
			cout << "请输入查找职工的姓名：" << endl;
			cin >> name;
			//加入一个判断是否查到的标志
			bool  flag = false;//默认表示未查到职工
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功！职工编号为：" << this->m_EmpArray[i]->m_Id 
						<<"号的信息如下：" << endl;
					//调用信息接口
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入选项有误。" << endl;
		}

	}
	//按任意键 清屏操作
	system("pause");
	system("cls");
}
//排序职工
void WorkManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在，或者数据为空。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入排序方式：" << endl;
		cout << "1、按照职工编号进行升序。" << endl;
		cout << "2、按照职工编号进行降序。" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;//声明一个最大值或者是一个最小值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			//判断一开始认定的 最小值或最大值 是不是 最小值或最大值 ，如果不是交换数据
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功！排序后的结果：" << endl;
		this->save();//排序后的结果，保存到文件中
		this->Show_Emp();
	}
}
//清空操作
void WorkManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、清空文件" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式 删除文件 并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			//删除堆区数组指针
			this->m_EmpNum=0;
			delete [] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
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
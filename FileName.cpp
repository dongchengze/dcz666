#include<iostream>
#include<string>
#define MAX 1000
#include<fstream>
#define FILENAME "address.txt"
using namespace std;
//联系人结构体
struct Person
{
	string p_name; //姓名
	int p_sex = 0; //性别 男1 女2
	int p_age = 0; //年龄
	string p_phone; //电话
	string p_address; //住址
};

//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX]; //通讯录中保存的联系人数组
	int p_size = 0; //通讯录中联系人个数
};

//保存文件
void save(Addressbooks* abs)
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < abs->p_size; i++)
	{
		ofs << abs->personArray[i].p_name << " "
			<< (abs->personArray[i].p_sex == 1 ? "男" : "女") << " "
			<< abs->personArray[i].p_age << " "
			<< abs->personArray[i].p_phone << " "
			<< abs->personArray[i].p_address << endl;
	}
	ofs.close();
}

// 1.添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->p_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->p_size].p_name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入的是1或2，可以退出循环
			//如果输入错误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->p_size].p_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			//如果输入年龄正常，可以退出循环
			//如果输入错误，重新输入
			cin >> age;
			if (age > 0 || age < 100)
			{
				abs->personArray[abs->p_size].p_age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[abs->p_size].p_phone = phone;

		//住址
		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[abs->p_size].p_address = address;

		//更新通讯录人数
		abs->p_size++;
		save(abs);//保存到文件
		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏操作
	}
}

//2.显示联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->p_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->p_size; i++)
		{
			cout << "姓名： " << abs->personArray[i].p_name << "\t";
			cout << "性别： " << (abs->personArray[i].p_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].p_age << "\t";
			cout << "电话： " << abs->personArray[i].p_phone << "\t";
			cout << "家庭住址： " << abs->personArray[i].p_address << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，如果存在，返回具体位置，否则返回-1
//参数1  通讯录，参数2  要删除的姓名
int ifExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->p_size; i++)
	{
		//找到用户姓名
		if (abs->personArray[i].p_name == name)
		{
			return i;//找到了，返回具体位置
		}
	}
	return -1;//没找到，返回-1
}

//3.删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入要删除的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = ifExist(abs, name);//ret==-1,未查到；ret!=-1,查到了
	if (ret != -1)
	{
		//查到了，删除此人
		for (int i = ret; i < abs->p_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->p_size--;//更新通讯录中人员数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	save(abs);//保存到文件
	system("pause");
	system("cls");
}

//4.查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入要查找的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = ifExist(abs, name);//ret==-1,未查到；ret!=-1,查到了
	if (ret != -1)
	{
		int i = ret;
		//查到了
		cout << "姓名： " << abs->personArray[i].p_name << "\t";
		cout << "性别： " << (abs->personArray[i].p_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[i].p_age << "\t";
		cout << "电话： " << abs->personArray[i].p_phone << "\t";
		cout << "家庭住址： " << abs->personArray[i].p_address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//5.修改联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = ifExist(abs, name);//ret==-1,未查到；ret!=-1,查到了
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入修改后的姓名：" << endl;
		cin >> name;
		abs->personArray[ret].p_name = name;

		//性别
		cout << "请输入修改后的性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入的是1或2，可以退出循环
			//如果输入错误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].p_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		int age = 0;
		cout << "请输入修改后的年龄：" << endl;
		while (true)
		{
			//如果输入年龄正常，可以退出循环
			//如果输入错误，重新输入
			cin >> age;
			if (age > 0 || age < 100)
			{
				abs->personArray[ret].p_age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//电话
		string phone;
		cout << "请输入修改后的联系电话：" << endl;
		cin >> phone;
		abs->personArray[ret].p_phone = phone;

		//住址
		string address;
		cout << "请输入修改后的家庭住址：" << endl;
		cin >> address;
		abs->personArray[ret].p_address = address;
		cout << "修改成功!" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	save(abs);//保存到文件
	system("pause");
	system("cls");
}


//菜单页面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}
int main()
{
	Addressbooks abs;
	int select = 0;
	while (true)
	{
		showMenu();//菜单调用
		cin >> select;
		switch (select)
		{
		case 1: // 1.添加联系人
			addPerson(&abs); //利用地址传递，可以修饰实参
			break;
		case 2: // 2.显示联系人
			showPerson(&abs);
			break;
		case 3: // 3.删除联系人
			deletePerson(&abs);
			break;
		case 4: // 4.查找联系人
			findPerson(&abs);
			break;
		case 5: // 5.修改联系人
			modifyPerson(&abs);
			break;
		case 0: // 0.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
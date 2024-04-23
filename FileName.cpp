#include<iostream>
#include<string>
#define MAX 1000
#include<fstream>
#define FILENAME "address.txt"
using namespace std;
//��ϵ�˽ṹ��
struct Person
{
	string p_name; //����
	int p_sex = 0; //�Ա� ��1 Ů2
	int p_age = 0; //����
	string p_phone; //�绰
	string p_address; //סַ
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX]; //ͨѶ¼�б������ϵ������
	int p_size = 0; //ͨѶ¼����ϵ�˸���
};

//�����ļ�
void save(Addressbooks* abs)
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < abs->p_size; i++)
	{
		ofs << abs->personArray[i].p_name << " "
			<< (abs->personArray[i].p_sex == 1 ? "��" : "Ů") << " "
			<< abs->personArray[i].p_age << " "
			<< abs->personArray[i].p_phone << " "
			<< abs->personArray[i].p_address << endl;
	}
	ofs.close();
}

// 1.������ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ�������
	if (abs->p_size == MAX)
	{
		cout << "ͨѶ¼�������޷����ӣ�" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->p_size].p_name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			//����������1��2�������˳�ѭ��
			//������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->p_size].p_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//����
		int age = 0;
		cout << "���������䣺" << endl;
		while (true)
		{
			//����������������������˳�ѭ��
			//������������������
			cin >> age;
			if (age > 0 || age < 100)
			{
				abs->personArray[abs->p_size].p_age = age;
				break;
			}
			cout << "������������������" << endl;
		}

		//�绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->p_size].p_phone = phone;

		//סַ
		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[abs->p_size].p_address = address;

		//����ͨѶ¼����
		abs->p_size++;
		save(abs);//���浽�ļ�
		cout << "���ӳɹ�" << endl;
		system("pause");
		system("cls");//��������
	}
}

//2.��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->p_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->p_size; i++)
		{
			cout << "������ " << abs->personArray[i].p_name << "\t";
			cout << "�Ա� " << (abs->personArray[i].p_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺 " << abs->personArray[i].p_age << "\t";
			cout << "�绰�� " << abs->personArray[i].p_phone << "\t";
			cout << "��ͥסַ�� " << abs->personArray[i].p_address << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ�������ڣ����ؾ���λ�ã����򷵻�-1
//����1  ͨѶ¼������2  Ҫɾ��������
int ifExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->p_size; i++)
	{
		//�ҵ��û�����
		if (abs->personArray[i].p_name == name)
		{
			return i;//�ҵ��ˣ����ؾ���λ��
		}
	}
	return -1;//û�ҵ�������-1
}

//3.ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "������Ҫɾ������ϵ������" << endl;
	string name;
	cin >> name;
	int ret = ifExist(abs, name);//ret==-1,δ�鵽��ret!=-1,�鵽��
	if (ret != -1)
	{
		//�鵽�ˣ�ɾ������
		for (int i = ret; i < abs->p_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->p_size--;//����ͨѶ¼����Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	save(abs);//���浽�ļ�
	system("pause");
	system("cls");
}

//4.������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = ifExist(abs, name);//ret==-1,δ�鵽��ret!=-1,�鵽��
	if (ret != -1)
	{
		int i = ret;
		//�鵽��
		cout << "������ " << abs->personArray[i].p_name << "\t";
		cout << "�Ա� " << (abs->personArray[i].p_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺 " << abs->personArray[i].p_age << "\t";
		cout << "�绰�� " << abs->personArray[i].p_phone << "\t";
		cout << "��ͥסַ�� " << abs->personArray[i].p_address << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//5.�޸���ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = ifExist(abs, name);//ret==-1,δ�鵽��ret!=-1,�鵽��
	if (ret != -1)
	{
		//����
		string name;
		cout << "�������޸ĺ��������" << endl;
		cin >> name;
		abs->personArray[ret].p_name = name;

		//�Ա�
		cout << "�������޸ĺ���Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			//����������1��2�������˳�ѭ��
			//������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].p_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//����
		int age = 0;
		cout << "�������޸ĺ�����䣺" << endl;
		while (true)
		{
			//����������������������˳�ѭ��
			//������������������
			cin >> age;
			if (age > 0 || age < 100)
			{
				abs->personArray[ret].p_age = age;
				break;
			}
			cout << "������������������" << endl;
		}

		//�绰
		string phone;
		cout << "�������޸ĺ����ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[ret].p_phone = phone;

		//סַ
		string address;
		cout << "�������޸ĺ�ļ�ͥסַ��" << endl;
		cin >> address;
		abs->personArray[ret].p_address = address;
		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	save(abs);//���浽�ļ�
	system("pause");
	system("cls");
}


//�˵�ҳ��
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.������ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}
int main()
{
	Addressbooks abs;
	int select = 0;
	while (true)
	{
		showMenu();//�˵�����
		cin >> select;
		switch (select)
		{
		case 1: // 1.������ϵ��
			addPerson(&abs); //���õ�ַ���ݣ���������ʵ��
			break;
		case 2: // 2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: // 3.ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: // 4.������ϵ��
			findPerson(&abs);
			break;
		case 5: // 5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 0: // 0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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
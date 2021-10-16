#include<iostream>
using namespace std;
#include <string>;
#define max 1000

//*�����ϵ�˽ṹ��


struct person 
{
	string m_name;	//����
	int m_sex;		//�Ա� 1�� 2Ů
	int m_age;		//����
	string m_phone;	//�绰
	string m_addr;	//��ַ
};

//* ���ͨѶ¼�ṹ��
struct addrressboos
{
	//ͨѶ¼�б�������ϵ������
	struct person person_arr [max];

	//ͨѶ¼�е�ǰ��¼��ϵ�˵ĸ���
	int m_size;

};

//�����ϵ��
void addperson(struct addrressboos *abs)
{
	//�ж�ͨѶ¼�Ƿ����������˾Ͳ������
	if (abs->m_size == max)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return ;
	}
	else
	{
		//��Ӿ������ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->person_arr[abs->m_size].m_name = name;

		//�Ա�
		int  sex=0;
		cout << "�������Ա�" << endl;
		cout << "1	--	��  " << endl;
		cout << "2	--	Ů��" << endl;
		while (true)
		{
			//����������һ���߶������˳�ѭ����
			//����������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->person_arr[abs->m_size].m_sex = sex;
				break;
			}
			cout << "��������,���������룺" << endl;
		}
		
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->person_arr[abs->m_size].m_age = age;

		//�绰
		cout << "������绰��" << endl;
		string phone;//string���ø�ֵ0
		cin >> phone;
		abs->person_arr[abs->m_size].m_phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->person_arr[abs->m_size].m_addr = address;

		//����ͨѶ¼����
		abs->m_size++;
		cout << "��ӳɹ���" << endl;
		system("pause");//�밲���������
		system("cls");
	}
}

//��ʾ���е���ϵ��
void showperson(struct addrressboos *abs) 
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0��0��ʾ��¼Ϊ��
	if (abs->m_size == 0) 
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	//ѭ����ӡ
	for (int i = 0; i < abs->m_size; i++)
	{
		cout << "������" << abs->person_arr[i].m_name
			<< "\t	����:" << (abs->person_arr[i].m_age==1?"��":"Ů")
			<< "\t	�Ա�:" << abs->person_arr[i].m_sex
			<< "\t	�绰:" << abs->person_arr[i].m_phone
			<< "\t	��ַ:" << abs->person_arr[i].m_addr << endl;
	}
	system("pause");//�밲���������
	system("cls");//����Ļ
}

//��װ�����ϵ���Ƿ���ڣ�������շ����������еľ���λ�ã������ڷ���-1
int isexist(struct addrressboos *abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		//�ж��Ƿ��������
		if (abs->person_arr[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}


//3.��װɾ����ϵ�˺���
void deleteperson(struct addrressboos *abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	//�ж�������Ƿ����
	if (ret != -1)
	{
		//�鵽�ˣ�ɾ��
		for (int i = ret; i < abs->m_size; i++)
		{
			//����Ǩ��
			abs->person_arr[i] = abs->person_arr[i + 1];
		}
		cout << "ɾ���ɹ�" << endl;
		abs->m_size--;//��������
	}
	else
	{
		cout << "���޴���" << endl;
		
	}
	system("pause");
	system("cls");
}

//4.��װ������ϵ�˺���
void findperson(struct addrressboos *abs)
{
	cout << "����������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)//�ҵ���ϵ��
	{
		cout << "������" << abs->person_arr[ret].m_name
			<< "\t	����:" << (abs->person_arr[ret].m_age == 1 ? "��" : "Ů")
			<< "\t	�Ա�:" << abs->person_arr[ret].m_sex
			<< "\t	�绰:" << abs->person_arr[ret].m_phone
			<< "\t	��ַ:" << abs->person_arr[ret].m_addr << endl;
	}
	else//δ�ҵ�����
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//5\��װ�޸���ϵ�˺���
void modifyperson(struct addrressboos *abs)
{
	cout << "�������޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)//�ҵ���ϵ��
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->person_arr[ret].m_name = name;

		//�Ա�
		int  sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1	--	��  " << endl;
		cout << "2	--	Ů��" << endl;
		while (true)
		{
			//����������һ���߶������˳�ѭ����
			//����������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->person_arr[ret].m_sex = sex;
				break;
			}
			cout << "��������,���������룺" << endl;
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->person_arr[ret].m_age = age;

		//�绰
		cout << "������绰��" << endl;
		string phone;//string���ø�ֵ0
		cin >> phone;
		abs->person_arr[ret].m_phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->person_arr[ret].m_addr = address;

		//����ͨѶ¼����
		cout << "�޸ĳɹ���" << endl;
	}
	else//δ�ҵ�����
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");

}

//6.��װ�����ϵ�˺���
void cleanperson(struct addrressboos *abs)
{
	cout << "���кܶ���ϵ�ˣ��Ƿ�ȷ��ȫ�����" << endl;
	cout << "1.�ǣ�ȫ�����" << endl;
	cout << "2.�����ˣ��˳�" << endl;
	cout << "���������֣�" << endl;
	while (true)
	{
		int cin_on;
		cin >> cin_on;

		if (cin_on == 1)
		{
			abs->m_size = 0;
			cout << "ͨѶ¼�����" << endl;
			break;
		}
		else if (cin_on == 2)
		{
			break;
		}
		else
		{
			cout << "�������" << endl;;
			cout << "���������룺";
		}
	}
	system("pause");
	system("cls");

}



//��װ������ʾ�ý���  �� `void showMenu()`
//��main�����е��÷�װ�õĺ���
//�˵����溯��
void showmenu() 
{
	cout << "*****************************"<< endl;
	cout << "*****	1�������ϵ��	*****" << endl;
	cout << "*****	2����ʾ��ϵ��	*****" << endl;
	cout << "*****	3��ɾ����ϵ��	*****" << endl;
	cout << "*****	4��������ϵ��	*****" << endl;
	cout << "*****	5���޸���ϵ��	*****" << endl;
	cout << "*****	6�������ϵ��	*****" << endl;
	cout << "*****	0���˳���ϵ��	*****" << endl;
	cout << "*****************************" << endl<<endl;
	cout << "���������ֽ���ѡ��" << endl;

}



int main()
{
	//����ͨѶ¼�ṹ�����
	struct addrressboos abs;
	//��ʼ����ǰ��Ա�ĸ���
	abs.m_size = 0;
	int select = 0;	//�����û�����ı���

	while (true) 
	{
		showmenu();	//���ò˵����溯��
		cin >> select;
		switch (select)
		{
		case 1:		//1�������ϵ��
			addperson(&abs);	//	���õ�ַ���ݿ�������ʵ��
			break;
		case 2:	//2����ʾ��ϵ��
			showperson(&abs);	//
			break;
		case 3:		//3��ɾ����ϵ��
			deleteperson(&abs);
			break;
		case 4:		//4��������ϵ��
			findperson(&abs);
			break;
		case 5:		//5���޸���ϵ��
			modifyperson(&abs);
			break;
		case 6:		//6�������ϵ��
			cleanperson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");	//��ͣ
			return 0;			//�˳�main����
			break;//0���˳���ϵ��
		default:break;

		}
	}
	
	system("pause");

	return 0;

}

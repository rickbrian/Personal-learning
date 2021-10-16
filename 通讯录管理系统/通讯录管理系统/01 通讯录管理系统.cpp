#include<iostream>
using namespace std;
#include <string>;
#define max 1000

//*设计联系人结构体


struct person 
{
	string m_name;	//姓名
	int m_sex;		//性别 1男 2女
	int m_age;		//年龄
	string m_phone;	//电话
	string m_addr;	//地址
};

//* 设计通讯录结构体
struct addrressboos
{
	//通讯录中保护的联系人数组
	struct person person_arr [max];

	//通讯录中当前记录联系人的个数
	int m_size;

};

//添加联系人
void addperson(struct addrressboos *abs)
{
	//判断通讯录是否已满，满了就不再添加
	if (abs->m_size == max)
	{
		cout << "通讯录已满，无法添加" << endl;
		return ;
	}
	else
	{
		//添加具体的联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->person_arr[abs->m_size].m_name = name;

		//性别
		int  sex=0;
		cout << "请输入性别：" << endl;
		cout << "1	--	男  " << endl;
		cout << "2	--	女：" << endl;
		while (true)
		{
			//如果输入的是一或者二可以退出循环，
			//输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->person_arr[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误,请重新输入：" << endl;
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->person_arr[abs->m_size].m_age = age;

		//电话
		cout << "请输入电话：" << endl;
		string phone;//string不用赋值0
		cin >> phone;
		abs->person_arr[abs->m_size].m_phone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->person_arr[abs->m_size].m_addr = address;

		//更新通讯录的人
		abs->m_size++;
		cout << "添加成功了" << endl;
		system("pause");//请安任意键继续
		system("cls");
	}
}

//显示所有的联系人
void showperson(struct addrressboos *abs) 
{
	//判断通讯录中人数是否为0，0提示记录为空
	if (abs->m_size == 0) 
	{
		cout << "当前记录为空" << endl;
	}
	//循环打印
	for (int i = 0; i < abs->m_size; i++)
	{
		cout << "姓名：" << abs->person_arr[i].m_name
			<< "\t	年龄:" << (abs->person_arr[i].m_age==1?"男":"女")
			<< "\t	性别:" << abs->person_arr[i].m_sex
			<< "\t	电话:" << abs->person_arr[i].m_phone
			<< "\t	地址:" << abs->person_arr[i].m_addr << endl;
	}
	system("pause");//请安任意键继续
	system("cls");//清屏幕
}

//封装检测联系人是否存在，如果参照返回在数组中的具体位置，不存在返回-1
int isexist(struct addrressboos *abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		//判断是否有这个人
		if (abs->person_arr[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}


//3.封装删除联系人函数
void deleteperson(struct addrressboos *abs)
{
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	//判断这个人是否存在
	if (ret != -1)
	{
		//查到了，删除
		for (int i = ret; i < abs->m_size; i++)
		{
			//数据迁移
			abs->person_arr[i] = abs->person_arr[i + 1];
		}
		cout << "删除成功" << endl;
		abs->m_size--;//更新人数
	}
	else
	{
		cout << "查无此人" << endl;
		
	}
	system("pause");
	system("cls");
}

//4.封装查找联系人函数
void findperson(struct addrressboos *abs)
{
	cout << "请输入那你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)//找到联系人
	{
		cout << "姓名：" << abs->person_arr[ret].m_name
			<< "\t	年龄:" << (abs->person_arr[ret].m_age == 1 ? "男" : "女")
			<< "\t	性别:" << abs->person_arr[ret].m_sex
			<< "\t	电话:" << abs->person_arr[ret].m_phone
			<< "\t	地址:" << abs->person_arr[ret].m_addr << endl;
	}
	else//未找到此人
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//5\封装修改联系人函数
void modifyperson(struct addrressboos *abs)
{
	cout << "请输入修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)//找到联系人
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->person_arr[ret].m_name = name;

		//性别
		int  sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1	--	男  " << endl;
		cout << "2	--	女：" << endl;
		while (true)
		{
			//如果输入的是一或者二可以退出循环，
			//输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->person_arr[ret].m_sex = sex;
				break;
			}
			cout << "输入有误,请重新输入：" << endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->person_arr[ret].m_age = age;

		//电话
		cout << "请输入电话：" << endl;
		string phone;//string不用赋值0
		cin >> phone;
		abs->person_arr[ret].m_phone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->person_arr[ret].m_addr = address;

		//更新通讯录的人
		cout << "修改成功了" << endl;
	}
	else//未找到此人
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");

}

//6.封装清空联系人函数
void cleanperson(struct addrressboos *abs)
{
	cout << "你有很多联系人，是否确定全部清空" << endl;
	cout << "1.是，全部清空" << endl;
	cout << "2.否，算了，退出" << endl;
	cout << "请输入数字：" << endl;
	while (true)
	{
		int cin_on;
		cin >> cin_on;

		if (cin_on == 1)
		{
			abs->m_size = 0;
			cout << "通讯录已清空" << endl;
			break;
		}
		else if (cin_on == 2)
		{
			break;
		}
		else
		{
			cout << "输入错误！" << endl;;
			cout << "请重新输入：";
		}
	}
	system("pause");
	system("cls");

}



//封装函数显示该界面  如 `void showMenu()`
//在main函数中调用封装好的函数
//菜单界面函数
void showmenu() 
{
	cout << "*****************************"<< endl;
	cout << "*****	1、添加联系人	*****" << endl;
	cout << "*****	2、显示联系人	*****" << endl;
	cout << "*****	3、删除联系人	*****" << endl;
	cout << "*****	4、查找联系人	*****" << endl;
	cout << "*****	5、修改联系人	*****" << endl;
	cout << "*****	6、清空联系人	*****" << endl;
	cout << "*****	0、退出联系人	*****" << endl;
	cout << "*****************************" << endl<<endl;
	cout << "请输入数字进行选择" << endl;

}



int main()
{
	//创建通讯录结构体变量
	struct addrressboos abs;
	//初始化当前人员的个数
	abs.m_size = 0;
	int select = 0;	//创建用户输入的变量

	while (true) 
	{
		showmenu();	//调用菜单界面函数
		cin >> select;
		switch (select)
		{
		case 1:		//1、添加联系人
			addperson(&abs);	//	利用地址传递可以修饰实参
			break;
		case 2:	//2、显示联系人
			showperson(&abs);	//
			break;
		case 3:		//3、删除联系人
			deleteperson(&abs);
			break;
		case 4:		//4、查找联系人
			findperson(&abs);
			break;
		case 5:		//5、修改联系人
			modifyperson(&abs);
			break;
		case 6:		//6、清空联系人
			cleanperson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");	//暂停
			return 0;			//退出main函数
			break;//0、退出联系人
		default:break;

		}
	}
	
	system("pause");

	return 0;

}

#include<iostream>
#include<string>
#include<ctime>
#include "WorkerManager.h"
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;
void Enter_sys();

int main() {
	Enter_sys();
	WorkerManager wm;
	while (1) {
		wm.show_Menu();
		string str_choice;
		cout << "请输入你选选择功能对应的标号：";
		cin >> str_choice;
		int choice = 9;
		for (int i = 0; i <= 8; i++) {
			string temp = to_string(i);
			if (temp == str_choice)  choice = i;
		}
		switch (choice) {
		case 0:  //退出系统
			wm.exitsystem();
			break;
		case 1:  //添加职工
			wm.Add_Emp();
			break;
		case 2:  //显示职工
			wm.show_Emp();
			break;
		case 3:  //删除职工
			wm.Del_Emp();
			break;
		case 4:  //修改职工
			wm.Mod_Emp();
			break;
		case 5:  //查找职工
			wm.Find_Emp();
			break;
		case 6:  //排序职工
			wm.Sort_Emp();
			break;
		case 7:  //清空职工
			wm.Clean_File();
			break;
		case 8:  //添加账户
			wm.Add_Accoutant();
			break;
		default:  //异常处理
			wm.Error_Deal();
			break;
		}
	}
	system("pause");
	return 0;
}

string Get_String() {
	char key;
	string password;
	while ((key = _getch()) != '\r')
	{
		if (key != 8)//不是回撤就录入
		{
			password += key;
			putchar('*');//并且输出*号
		}
		else
		{
			putchar('\b');//这里是删除一个，我们通过输出回撤符 /b，回撤一格，
			putchar(' ');//再显示空格符把刚才的*给盖住，
			putchar('\b');//然后再 回撤一格等待录入。
			password.pop_back();
		}
	}
	cout << endl;
	return password;
}

void Enter_sys() {
	cout << "欢迎使用员工信息记录系统。" << endl;
	cout << "请您输入您的账号或者密码！" << endl;
	int num = 0;
	string Account, Keyword;
	bool flag = false;
	while (1) {
		cout << "账号：";
		Account = Get_String();
		cout << "密码：";
		Keyword = Get_String();
		num++;
		ifstream ifs;
		ifs.open(ENTER, ios::in);
		string key_Account, key_Keyword;
		while (ifs >> key_Account >> key_Keyword) {
			if (key_Account == Account && key_Keyword == Keyword) {  //对文件里面的信息进行遍历
				cout << "欢迎你！" << Account << endl;  //输出对应的账号
				cout<< "登陆成功^_^!请稍等..." << endl;
				flag = true;
				ifs.close();  //关闭文件
				break;
			}
		}
		if (flag) {
			clock_t now = clock();
			while (clock() - now <= 3 * 1000) {}
			system("cls");
			break;
		}
		else{
			if (num == 6) {
				cout << "您的错误次数到达5次，系统将自动退出。" << endl;
				system("pause");
				ifs.close();  //关闭文件
				return;
			}
			else {
				 cout << "账号或者密码错误，请重新输入！" << endl;
			}
		}
	}
}
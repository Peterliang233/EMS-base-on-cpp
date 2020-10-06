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
		cout << "��������ѡѡ���ܶ�Ӧ�ı�ţ�";
		cin >> str_choice;
		int choice = 9;
		for (int i = 0; i <= 8; i++) {
			string temp = to_string(i);
			if (temp == str_choice)  choice = i;
		}
		switch (choice) {
		case 0:  //�˳�ϵͳ
			wm.exitsystem();
			break;
		case 1:  //���ְ��
			wm.Add_Emp();
			break;
		case 2:  //��ʾְ��
			wm.show_Emp();
			break;
		case 3:  //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4:  //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:  //����ְ��
			wm.Find_Emp();
			break;
		case 6:  //����ְ��
			wm.Sort_Emp();
			break;
		case 7:  //���ְ��
			wm.Clean_File();
			break;
		case 8:  //����˻�
			wm.Add_Accoutant();
			break;
		default:  //�쳣����
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
		if (key != 8)//���ǻس���¼��
		{
			password += key;
			putchar('*');//�������*��
		}
		else
		{
			putchar('\b');//������ɾ��һ��������ͨ������س��� /b���س�һ��
			putchar(' ');//����ʾ�ո���Ѹղŵ�*����ס��
			putchar('\b');//Ȼ���� �س�һ��ȴ�¼�롣
			password.pop_back();
		}
	}
	cout << endl;
	return password;
}

void Enter_sys() {
	cout << "��ӭʹ��Ա����Ϣ��¼ϵͳ��" << endl;
	cout << "�������������˺Ż������룡" << endl;
	int num = 0;
	string Account, Keyword;
	bool flag = false;
	while (1) {
		cout << "�˺ţ�";
		Account = Get_String();
		cout << "���룺";
		Keyword = Get_String();
		num++;
		ifstream ifs;
		ifs.open(ENTER, ios::in);
		string key_Account, key_Keyword;
		while (ifs >> key_Account >> key_Keyword) {
			if (key_Account == Account && key_Keyword == Keyword) {  //���ļ��������Ϣ���б���
				cout << "��ӭ�㣡" << Account << endl;  //�����Ӧ���˺�
				cout<< "��½�ɹ�^_^!���Ե�..." << endl;
				flag = true;
				ifs.close();  //�ر��ļ�
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
				cout << "���Ĵ����������5�Σ�ϵͳ���Զ��˳���" << endl;
				system("pause");
				ifs.close();  //�ر��ļ�
				return;
			}
			else {
				 cout << "�˺Ż�������������������룡" << endl;
			}
		}
	}
}
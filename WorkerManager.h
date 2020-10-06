#pragma once
#include<iostream>
#include<algorithm>
#include<map>
#include<ctime>
#include<stdlib.h>
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"
#include<fstream>
#include<conio.h>
#define FILENAME "Empfile.txt"
#define ENTER "Enter.txt"
using namespace std;
class WorkerManager{
public:
	//���캯��
	 WorkerManager();
	 //��ʼ������
	 void show_Menu();
	 //�쳣����
	 void Error_Deal();
	 //�˳�ϵͳ
	 void exitsystem();
	 //��¼ְ������
	 int Sum_workers;
	 //��¼ְ��ָ��
	 Worker ** M_Emparray;
	 //�����ְ��
	 void Add_Emp();
	 //�ж��ļ��Ƿ�Ϊ��
	 bool m_FileIsEmpty;
	 //��ȡ�ļ�������
	 int get_EmpNum();
	 void inti_Emp();
	 //��������
	 void save();
	 //���Ա����Ϣ
	 void show_Emp();
	 //���Ա����Ϣ�Ƿ����
	 int Check_Emp(int id);
	 //ɾ��Ա����Ϣ
	 void Del_Emp();
	 //����Ա�����
	 map<int, int> mp;
	 //�޸�ְ����Ϣ
	 void Mod_Emp();
	 //����ְ����Ϣ
	 void Find_Emp();
	 //�����Ž�������
	 void Sort_Emp();
	 //����ļ������������Ϣ
	 void Clean_File();
	 //����µĵ�½�˻�
	 void Add_Accoutant();
	 //�ַ�������
	 string Ret_String();
	 //��������
	~WorkerManager();
};

#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker {  //����һ������
public:
	int m_id;
	string name;
	int depart;
	virtual void show_infor() = 0;
	//��ȡ������Ϣ
	virtual string get_depart() = 0;
	//��ȡ���ڲ���
};
#pragma once
#include "Worker.h"
#include<iostream>
using namespace std;

class Employee :public Worker {
public:
	Employee(int id, string name, int depart);
	virtual void show_infor();
	//��ȡ������Ϣ
	virtual string get_depart();
	//��ȡ����
};
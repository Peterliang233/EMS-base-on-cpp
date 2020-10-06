#pragma once
#include "Worker.h"
#include<iostream>
using namespace std;

class Employee :public Worker {
public:
	Employee(int id, string name, int depart);
	virtual void show_infor();
	//获取个人信息
	virtual string get_depart();
	//获取部门
};
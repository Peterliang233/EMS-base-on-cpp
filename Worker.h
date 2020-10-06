#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker {  //定义一个主类
public:
	int m_id;
	string name;
	int depart;
	virtual void show_infor() = 0;
	//获取个人信息
	virtual string get_depart() = 0;
	//获取所在部门
};
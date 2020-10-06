#pragma once
#include "Worker.h"

class Boss :public Worker {
public:
	Boss(int id,string name,int depart);
	virtual void show_infor();
	//获取个人信息
	virtual string get_depart();
};
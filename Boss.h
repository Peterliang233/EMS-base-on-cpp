#pragma once
#include "Worker.h"

class Boss :public Worker {
public:
	Boss(int id,string name,int depart);
	virtual void show_infor();
	//��ȡ������Ϣ
	virtual string get_depart();
};
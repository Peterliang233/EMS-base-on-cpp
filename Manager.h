#pragma once
#include "Worker.h"

class Manager :public Worker {
public:
	Manager(int id, string name, int depart);
	virtual void show_infor();
	//��ȡ������Ϣ
	virtual string get_depart();
	//��ȡ����
};
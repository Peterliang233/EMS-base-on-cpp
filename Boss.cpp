#include "Boss.h"

Boss::Boss(int id,string name,int depart) {
	this->m_id = id;
	this->name=name;
	this->depart = depart;
}
void Boss::show_infor() {
	cout << "职工名字: " << this->name
		<< "\t职工编号: " << this->m_id
		<< "\t岗位: " << this->get_depart()
		<< "\t岗位职责: 对公司事物进行决策" << endl;
}

string Boss::get_depart() {
	return string("老板");
}
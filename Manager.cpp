#include "Manager.h"

Manager::Manager(int id, string name, int depart) {
	this->m_id = id;
	this->depart = depart;
	this->name = name;
}

void Manager::show_infor(){
	cout << "职工名字: " << this->name
		<< "\t职工编号: " << this->m_id
		<< "\t岗位: " << this->get_depart()
		<< "\t岗位职责: 完成老板交代的任务，并且向员工传达任务" << endl;
}

string Manager::get_depart() {
	return string("经理");
}
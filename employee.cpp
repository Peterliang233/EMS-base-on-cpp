#include "employee.h"

Employee::Employee(int id, string name, int depart) {
	this->m_id =id;
	this->name = name;
	this->depart = depart;
}

void Employee::show_infor() {
	cout << "职工名字: " << this->name
		<< "\t职工编号: " << this->m_id
		<< "\t岗位: " << this->get_depart()
		<< "\t岗位职责: 完成经理交代的任务" << endl;
}

string Employee::get_depart() {
	return string("员工");
}
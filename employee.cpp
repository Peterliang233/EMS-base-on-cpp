#include "employee.h"

Employee::Employee(int id, string name, int depart) {
	this->m_id =id;
	this->name = name;
	this->depart = depart;
}

void Employee::show_infor() {
	cout << "ְ������: " << this->name
		<< "\tְ�����: " << this->m_id
		<< "\t��λ: " << this->get_depart()
		<< "\t��λְ��: ��ɾ�����������" << endl;
}

string Employee::get_depart() {
	return string("Ա��");
}
#include "Manager.h"

Manager::Manager(int id, string name, int depart) {
	this->m_id = id;
	this->depart = depart;
	this->name = name;
}

void Manager::show_infor(){
	cout << "ְ������: " << this->name
		<< "\tְ�����: " << this->m_id
		<< "\t��λ: " << this->get_depart()
		<< "\t��λְ��: ����ϰ彻�������񣬲�����Ա����������" << endl;
}

string Manager::get_depart() {
	return string("����");
}
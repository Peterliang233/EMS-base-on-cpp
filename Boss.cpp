#include "Boss.h"

Boss::Boss(int id,string name,int depart) {
	this->m_id = id;
	this->name=name;
	this->depart = depart;
}
void Boss::show_infor() {
	cout << "ְ������: " << this->name
		<< "\tְ�����: " << this->m_id
		<< "\t��λ: " << this->get_depart()
		<< "\t��λְ��: �Թ�˾������о���" << endl;
}

string Boss::get_depart() {
	return string("�ϰ�");
}
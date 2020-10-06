#include "WorkerManager.h"
string Depart[4] = { "","Ա��","����","�ϰ�" };


WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //���ļ�
	//�ļ�������
	if (!ifs.is_open()) {
		cout << "�ļ��򿪴���" << endl;
		this->Sum_workers = 0;
		this->M_Emparray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->Sum_workers = 0;
		this->M_Emparray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڲ��һ�������
	int num = this->get_EmpNum();
	this->Sum_workers = num;
	this->M_Emparray = new Worker*[this->Sum_workers];
	this->inti_Emp();
	/*for (int i = 0; i < this->Sum_workers; i++) {
		cout << "Ա����ţ� " << this->M_Emparray[i]->m_id
			<< " ������" << this->M_Emparray[i]->name
			<< " ���ű�ţ�" << this->M_Emparray[i]->depart << endl;
	}*/
}

void WorkerManager::show_Menu() {  //ϵͳ��ʼ������
	cout << "*************************************************************************" << endl;
	cout << endl;
	cout << "    ��ӭ��½ְ������ϵͳ�������԰�����ǰ�����ֱ��ѡ������Ҫ�Ĺ���" << endl;
	cout << endl;
	cout << "0.�˳��������" << endl;
	cout << endl;
	cout << "1.����ְ����Ϣ" << endl;
	cout << endl;
	cout << "2.��ʾְ����Ϣ" << endl;
	cout << endl;
	cout << "3.ɾ����ְְ��" << endl;
	cout << endl;
	cout << "4.�޸�ְ����Ϣ" << endl;
	cout << endl;
	cout << "5.����ְ����Ϣ" << endl;
	cout << endl;
	cout << "6.���ձ����ź�" << endl;
	cout << endl;
	cout << "7.��������ĵ�" << endl;
	cout << endl;
	cout << "8.����µ��˻�" << endl;
	cout << endl;
	cout << "*************************************************************************" << endl;
}

void WorkerManager::Error_Deal() { //���������
	cout << "���������������������룡" << endl;
	system("pause");
	system("cls");
}

void WorkerManager::exitsystem() {  //����ϵͳ
	cout << "��ȷ��Ҫ�˳�ϵͳ��" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	cout << "��ѡ��";
	int chose;
	cin >> chose;
	cout << "ף��ʹ�����! ��ӭ�´�ʹ��!^_^" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp() {  //�����ְ��
	cout << "������������ӵ�ְ��������" << endl;
	int num;
	cin >> num;
	if (num <= 0) {
		cout << "������������!" << endl;
	}
	else {
		int newSize = num + this->Sum_workers;  //��¼����Ӻ��Ա����������
		Worker ** newSpace = new Worker*[newSize];  //�����ʵ����ڴ�
		if (this->M_Emparray != NULL) {
			for (int i = 0;i < this->Sum_workers; i++) {  //�ȼ�¼��֮ǰ��ָ��
				newSpace[i] = this->M_Emparray[i];
			}
		}
		//����³�Ա
		for (int i = 0; i < num; i++) {
			int id; //ְ�����
			string name; //����
			int partsel; //���ű��
			cout << "�������" << i + 1 << "��ְ���ı��: ";
			while (cin >> id ) {
				if (!mp[id])  break;
				else {
					cout << "�ñ���Ѿ����ڣ�����������!" << endl;
					cout << "�������" << i + 1 << "��ְ���ı��: ";
				}
			}
			cout << "�������" << i + 1 << "��ְ��������: ";
			cin >> name;
			cout << "�������ְ��������:" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cout << "��ѡ��";
			cin >> partsel;
			Worker *worker = NULL;
			switch (partsel) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			}
			newSpace[this->Sum_workers + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete []this->M_Emparray; 
		this->M_Emparray = newSpace;  //�����µ�ָ��
		this->Sum_workers = newSize; //�����µ�ְ������
		this->m_FileIsEmpty = false;
		cout << "�ɹ����" << num << " ��ְ��" << endl;
		this->save();
		system("pause");
		system("cls");
	}
}

void WorkerManager::inti_Emp() {   //���ļ����������Ϣ������������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int depart;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> depart) {
		mp[id]++;
		Worker *worker = NULL;
		if (depart == 1) {  //Ա��
			worker = new Employee(id, name, depart);
		}
		else if (depart == 2) {  //����
			worker = new Manager(id, name, depart);
		}
		else if (depart == 3) {  //�ϰ�
			worker = new Boss(id, name, depart);
		}
		this->M_Emparray[index++] = worker;
	}
	ifs.close();
}

int WorkerManager::get_EmpNum() {   //��ȡ�ļ������Ա��������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int depart;
	int num = 0;
	while (ifs >> id&&ifs >> name && ifs >> depart) {  //һֱ��ȡ���ļ�β��
		num++;
	}
	return num;
}

void WorkerManager::save() {  //�������������Ϣ�������ļ�����
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->Sum_workers; i++) {
		ofs << this->M_Emparray[i]->m_id << " "
			<< this->M_Emparray[i]->name << " "
			<< this->M_Emparray[i]->depart << endl;
	}
	ofs.close();
}

void WorkerManager::show_Emp() {  //���Ա����Ϣ
	if (m_FileIsEmpty) {  //�ļ�Ϊ�ջ��߲�������
		cout << "�ļ�Ϊ�ջ����ļ������ڣ�" << endl;
		system("pause");
		system("cls");
	}
	for (int i = 0; i < this->Sum_workers; i++) {
		this->M_Emparray[i]->show_infor();
	}
	//�����������
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp() {  //ɾ��Ա����Ϣ
	cout << "����������ɾ����Ա���ı�ţ�";
	int id;
	cin >> id;
	cout << "��ȷ��Ҫɾ��idΪ��" << id << " ��Ա������Ϣ��" << endl;  //����ȷ��
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	cout << "��ѡ��";
	int key;
	cin >> key;
	if (key) {
		int index = Check_Emp(id);
		if (index != -1) {  //�ҵ���ӦԱ���ı��
			mp[id] = 0;
			for (int i = index; i < this->Sum_workers - 1; i++) {
				this->M_Emparray[i] = this->M_Emparray[i + 1];
			}
			this->Sum_workers--;  //�����ļ������Ա��������
			cout << "ɾ���ɹ���" << endl;
			this->save();
		}
		else {
			cout << "��Ǹ��δ�ҵ���Ա����Ϣ!" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

int WorkerManager::Check_Emp(int id) {  //����ļ����Ƿ����ĳλԱ��
	int index = -1;
	for (int i = 0; i < this->Sum_workers; i++) {
		if (this->M_Emparray[i]->m_id == id) {
			index = i;
			break;
		}
	}
	//����Ա���ı��
	return index;
}

void WorkerManager::Mod_Emp() {   //�޸�Ա����Ϣ
	cout << "�����������޸ĵ�Ա���ı�ţ�";
	int id;
	cin >> id;
	cout << "��ȷ��Ҫ�޸�idΪ��" << id << " ��Ա������Ϣ��" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	cout << "��ѡ��";
	int key;
	cin >> key;
	if (key) {
		int index = Check_Emp(id);
		if (index != -1) {  //�ҵ���ӦԱ���ı��
			delete this->M_Emparray[index];  //ɾ����Ա������Ϣ
			int newId;
			string newName;
			int newdepart;
			cout << "���뽫��Ա���ı���޸�Ϊ��";
			while (cin >> newId) {
				if (mp[newId] && newId != id) {
					cout << "��id�ѱ�����Ա��ʹ�ã����������룡" << endl;
					cout << "���뽫��Ա���ı���޸�Ϊ��";
				}
				else {
					break;
				}
			}
			cout << "���뽫��Ա���������޸�Ϊ��";
			cin >> newName;
			cout << "�����޸ĸ�ְ��������Ϊ��" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cout << "��ѡ��";
			cin >> newdepart;
			Worker *worker = NULL;
			switch (newdepart) {
			case 1:
				worker = new Employee(newId,newName,newdepart);
				break;
			case 2:
				worker = new Manager(newId, newName, newdepart);
				break;
			case 3:
				worker = new Boss(newId, newName, newdepart);
				break;
			default:
				break;
			}
			this->M_Emparray[index] = worker;
			this->save();
			cout << "�޸ĳɹ�!" << endl;
		}
		else {
			cout << "��Ǹ��δ�ҵ���Ա����Ϣ!" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp() {  //����Ա����Ϣ
	cout << "������ͨ���������ֲ�������һ����ѯ������" << endl;
	cout << "1.����Ų���" << endl;
	cout << "2.����������" << endl;
	cout << "�������Ӧ����ǰ�����: ";
	int chose;
	cin >> chose;
	if (chose == 1) {
		cout << "������������ҵı�ţ�";
		int id;
		cin >> id;
		if (!mp[id]) {
			cout << "��Ǹ�����޴��ˣ�" << endl;
		}
		else {
			for (int i = 0; i < this->Sum_workers; i++) {
				if (this->M_Emparray[i]->m_id == id) {
					cout << "��ţ�" << this->M_Emparray[i]->m_id
						<< " ������" << this->M_Emparray[i]->name
						<< " ְλ��" << Depart[this->M_Emparray[i]->depart] << endl;
					break;
				}
			}
		}
	}
	else if(chose==2){
		cout << "������������ҵ�������Ϣ��";
		string name;
		cin >> name;
		bool flag = false;
		for (int i = 0; i < this->Sum_workers; i++) {
			if (this->M_Emparray[i]->name == name) {
				flag = true;
				cout << "��ţ�" << this->M_Emparray[i]->m_id
					<< " ������" << this->M_Emparray[i]->name
					<< " ְλ��" << Depart[this->M_Emparray[i]->depart] << endl;
			}
		}
		if (!flag) {
			cout << "��Ǹ��û���ҵ������ֶ�Ӧ��Ա����Ϣ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

string WorkerManager::Ret_String() {
	char key;
	string password;
	while ((key = _getch()) != '\r')
	{
		if (key != 8)//���ǻس���¼��
		{
			password += key;
			putchar('*');//�������*��
		}
		else
		{
			putchar('\b');//������ɾ��һ��������ͨ������س��� /b���س�һ��
			putchar(' ');//����ʾ�ո���Ѹղŵ�*����ס��
			putchar('\b');//Ȼ���� �س�һ��ȴ�¼�롣
			password.pop_back();
		}
	}
	cout << endl;
	return password;
}

void WorkerManager::Add_Accoutant() {
	cout << "���������Ȩ�޵����룺";
	int num = 0;
	while (1) {
		num++;
		string password = Ret_String();
		//if (password != "3607812001lyp") cout << "��Ǹ���������" << endl;
		if (password == "3607812001lyp"){   //�ɹ��������Ȩ������
			cout << "������ȷ��" << endl;
			ofstream ofs;
			ofs.open(ENTER,ios::app);
			cout << "������������ӵ��˻����˺ź����룺" << endl;
			cout << "�˺ţ�";
			string Account, keyword;
			cin >> Account;
			cout << "���룺";
			cin >> keyword;
			ofs <<" "<< Account << " " << keyword << endl;
			ofs.close();
			cout << "����˻��ɹ���" << endl;
			system("pause");
			system("cls");
			break;
		}
		else {
			if (num == 6) {  //�����������ﵽ���
				cout << "���Ĵ����������5�Σ����ʧ�ܣ�" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {
				cout << "�˺Ż�������������������룡" << endl;
				cout << "���������Ȩ�޵����룺";
			}
		}
	}
}

void WorkerManager::Sort_Emp() {  //��Ա����Ϣ��������
	cout << "��ѡ�����������������ͣ�" << endl;
	cout << "1.����Ž�����������" << endl;
	cout << "2.����Ž��н�������" << endl;
	cout << "��ѡ��";
	int select;
	cin >> select;
	for (int i = 0; i < this->Sum_workers; i++) {
		int minOrmax = i;  //�ȱ�Ǻ�������Сֵ
		for (int j = i+1; j < this->Sum_workers; j++) {
			if (select==1) {  //��������
				if (this->M_Emparray[minOrmax]->m_id > this->M_Emparray[j]->m_id) {  //���Ͻ��и���
					minOrmax = j;
				}
			} 
			else {  //��������
				if (this->M_Emparray[minOrmax]->m_id < this->M_Emparray[j]->m_id) {
					minOrmax = j;
				}
			}
		}
		if (minOrmax != i) {
			Worker *worker = this->M_Emparray[minOrmax];
			this->M_Emparray[minOrmax] = this->M_Emparray[i];
			this->M_Emparray[i] = worker;
		}
	}
	cout << "����ɹ��������Ľ��Ϊ��" << endl;
	this->save();  //��������õ���Ϣ
	this->show_Emp();  //����ļ������е�ְ������Ϣ
}

void WorkerManager::Clean_File() {   //����ļ�����
	cout << "��ȷ��������ļ��������Ϣ��" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select;
	cout << "��ѡ��";
	cin >> select;
	if (select==1) {
		//����ļ�
		ofstream ofs (FILENAME, ios::trunc);
		ofs.close();
		if (this->M_Emparray != NULL) {
			for (int i = 0; i < this->Sum_workers; i++) {
				if (this->M_Emparray[i] != NULL) {
					delete this->M_Emparray[i];
					this->M_Emparray[i] = NULL;
				}
			}
			//ɾ����������ָ��
			delete this->M_Emparray;
			this->M_Emparray = NULL;
			this->Sum_workers = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() {  //��������
	if (this->M_Emparray != NULL) {
		for (int i = 0; i < this->Sum_workers; i++) {  //���ͷ����������ָ��
			if (this->M_Emparray[i] != NULL) {
				delete this->M_Emparray[i];
			}
		}
		delete[]this->M_Emparray;
		this->M_Emparray = NULL;
	}
}
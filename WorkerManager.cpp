#include "WorkerManager.h"
string Depart[4] = { "","员工","经理","老板" };


WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //读文件
	//文件不存在
	if (!ifs.is_open()) {
		cout << "文件打开错误" << endl;
		this->Sum_workers = 0;
		this->M_Emparray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->Sum_workers = 0;
		this->M_Emparray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在并且还有数字
	int num = this->get_EmpNum();
	this->Sum_workers = num;
	this->M_Emparray = new Worker*[this->Sum_workers];
	this->inti_Emp();
	/*for (int i = 0; i < this->Sum_workers; i++) {
		cout << "员工编号： " << this->M_Emparray[i]->m_id
			<< " 姓名：" << this->M_Emparray[i]->name
			<< " 部门编号：" << this->M_Emparray[i]->depart << endl;
	}*/
}

void WorkerManager::show_Menu() {  //系统初始化界面
	cout << "*************************************************************************" << endl;
	cout << endl;
	cout << "    欢迎登陆职工管理系统，您可以按操作前的数字标号选择您想要的功能" << endl;
	cout << endl;
	cout << "0.退出管理程序" << endl;
	cout << endl;
	cout << "1.增加职工信息" << endl;
	cout << endl;
	cout << "2.显示职工信息" << endl;
	cout << endl;
	cout << "3.删除离职职工" << endl;
	cout << endl;
	cout << "4.修改职工信息" << endl;
	cout << endl;
	cout << "5.查找职工信息" << endl;
	cout << endl;
	cout << "6.按照编序排号" << endl;
	cout << endl;
	cout << "7.清空所有文档" << endl;
	cout << endl;
	cout << "8.添加新的账户" << endl;
	cout << endl;
	cout << "*************************************************************************" << endl;
}

void WorkerManager::Error_Deal() { //输入错误反馈
	cout << "您的输入有误，请重新输入！" << endl;
	system("pause");
	system("cls");
}

void WorkerManager::exitsystem() {  //重置系统
	cout << "您确定要退出系统吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	cout << "请选择：";
	int chose;
	cin >> chose;
	cout << "祝您使用愉快! 欢迎下次使用!^_^" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp() {  //添加新职工
	cout << "请输入您想添加的职工的数量" << endl;
	int num;
	cin >> num;
	if (num <= 0) {
		cout << "您的输入有误!" << endl;
	}
	else {
		int newSize = num + this->Sum_workers;  //记录新添加后的员工的总数量
		Worker ** newSpace = new Worker*[newSize];  //申请适当的内存
		if (this->M_Emparray != NULL) {
			for (int i = 0;i < this->Sum_workers; i++) {  //先记录下之前的指针
				newSpace[i] = this->M_Emparray[i];
			}
		}
		//添加新成员
		for (int i = 0; i < num; i++) {
			int id; //职工编号
			string name; //姓名
			int partsel; //部门编号
			cout << "请输入第" << i + 1 << "个职工的编号: ";
			while (cin >> id ) {
				if (!mp[id])  break;
				else {
					cout << "该编号已经存在，请重新输入!" << endl;
					cout << "请输入第" << i + 1 << "个职工的编号: ";
				}
			}
			cout << "请输入第" << i + 1 << "个职工的姓名: ";
			cin >> name;
			cout << "请输入该职工的种类:" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cout << "请选择：";
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
		//释放原有空间
		delete []this->M_Emparray; 
		this->M_Emparray = newSpace;  //更新新的指针
		this->Sum_workers = newSize; //更新新的职工人数
		this->m_FileIsEmpty = false;
		cout << "成功添加" << num << " 名职工" << endl;
		this->save();
		system("pause");
		system("cls");
	}
}

void WorkerManager::inti_Emp() {   //从文件里面读入信息存在数组里面
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int depart;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> depart) {
		mp[id]++;
		Worker *worker = NULL;
		if (depart == 1) {  //员工
			worker = new Employee(id, name, depart);
		}
		else if (depart == 2) {  //经理
			worker = new Manager(id, name, depart);
		}
		else if (depart == 3) {  //老板
			worker = new Boss(id, name, depart);
		}
		this->M_Emparray[index++] = worker;
	}
	ifs.close();
}

int WorkerManager::get_EmpNum() {   //获取文件里面的员工的数量
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int depart;
	int num = 0;
	while (ifs >> id&&ifs >> name && ifs >> depart) {  //一直读取到文件尾部
		num++;
	}
	return num;
}

void WorkerManager::save() {  //将本次输入的信息保存在文件里面
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->Sum_workers; i++) {
		ofs << this->M_Emparray[i]->m_id << " "
			<< this->M_Emparray[i]->name << " "
			<< this->M_Emparray[i]->depart << endl;
	}
	ofs.close();
}

void WorkerManager::show_Emp() {  //输出员工信息
	if (m_FileIsEmpty) {  //文件为空或者部不存在
		cout << "文件为空或者文件不存在！" << endl;
		system("pause");
		system("cls");
	}
	for (int i = 0; i < this->Sum_workers; i++) {
		this->M_Emparray[i]->show_infor();
	}
	//按任意键继续
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp() {  //删除员工信息
	cout << "请输入您想删除的员工的编号：";
	int id;
	cin >> id;
	cout << "你确定要删除id为：" << id << " 的员工的信息吗？" << endl;  //二次确认
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	cout << "请选择：";
	int key;
	cin >> key;
	if (key) {
		int index = Check_Emp(id);
		if (index != -1) {  //找到对应员工的编号
			mp[id] = 0;
			for (int i = index; i < this->Sum_workers - 1; i++) {
				this->M_Emparray[i] = this->M_Emparray[i + 1];
			}
			this->Sum_workers--;  //更新文件里面的员工的数量
			cout << "删除成功！" << endl;
			this->save();
		}
		else {
			cout << "抱歉，未找到该员工信息!" << endl;
		}
	}
	//按任意键继续
	system("pause");
	system("cls");
}

int WorkerManager::Check_Emp(int id) {  //检查文件中是否存在某位员工
	int index = -1;
	for (int i = 0; i < this->Sum_workers; i++) {
		if (this->M_Emparray[i]->m_id == id) {
			index = i;
			break;
		}
	}
	//返回员工的编号
	return index;
}

void WorkerManager::Mod_Emp() {   //修改员工信息
	cout << "请输入您想修改的员工的编号：";
	int id;
	cin >> id;
	cout << "你确定要修改id为：" << id << " 的员工的信息吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	cout << "请选择：";
	int key;
	cin >> key;
	if (key) {
		int index = Check_Emp(id);
		if (index != -1) {  //找到对应员工的编号
			delete this->M_Emparray[index];  //删除该员工的信息
			int newId;
			string newName;
			int newdepart;
			cout << "您想将该员工的编号修改为：";
			while (cin >> newId) {
				if (mp[newId] && newId != id) {
					cout << "该id已被其他员工使用，请重新输入！" << endl;
					cout << "您想将该员工的编号修改为：";
				}
				else {
					break;
				}
			}
			cout << "您想将该员工的姓名修改为：";
			cin >> newName;
			cout << "您想修改该职工的种类为：" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cout << "请选择：";
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
			cout << "修改成功!" << endl;
		}
		else {
			cout << "抱歉，未找到该员工信息!" << endl;
		}
	}
	//按任意键继续
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp() {  //查找员工信息
	cout << "您可以通过以下两种操作进行一个查询操作！" << endl;
	cout << "1.按编号查找" << endl;
	cout << "2.按姓名查找" << endl;
	cout << "请输入对应操作前的序号: ";
	int chose;
	cin >> chose;
	if (chose == 1) {
		cout << "请输入您想查找的编号：";
		int id;
		cin >> id;
		if (!mp[id]) {
			cout << "抱歉，查无此人！" << endl;
		}
		else {
			for (int i = 0; i < this->Sum_workers; i++) {
				if (this->M_Emparray[i]->m_id == id) {
					cout << "编号：" << this->M_Emparray[i]->m_id
						<< " 姓名：" << this->M_Emparray[i]->name
						<< " 职位：" << Depart[this->M_Emparray[i]->depart] << endl;
					break;
				}
			}
		}
	}
	else if(chose==2){
		cout << "请输入你想查找的姓名信息：";
		string name;
		cin >> name;
		bool flag = false;
		for (int i = 0; i < this->Sum_workers; i++) {
			if (this->M_Emparray[i]->name == name) {
				flag = true;
				cout << "编号：" << this->M_Emparray[i]->m_id
					<< " 姓名：" << this->M_Emparray[i]->name
					<< " 职位：" << Depart[this->M_Emparray[i]->depart] << endl;
			}
		}
		if (!flag) {
			cout << "抱歉，没有找到该名字对应的员工信息！" << endl;
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
		if (key != 8)//不是回撤就录入
		{
			password += key;
			putchar('*');//并且输出*号
		}
		else
		{
			putchar('\b');//这里是删除一个，我们通过输出回撤符 /b，回撤一格，
			putchar(' ');//再显示空格符把刚才的*给盖住，
			putchar('\b');//然后再 回撤一格等待录入。
			password.pop_back();
		}
	}
	cout << endl;
	return password;
}

void WorkerManager::Add_Accoutant() {
	cout << "请输入最高权限的密码：";
	int num = 0;
	while (1) {
		num++;
		string password = Ret_String();
		//if (password != "3607812001lyp") cout << "抱歉，密码错误！" << endl;
		if (password == "3607812001lyp"){   //成功输入最高权限密码
			cout << "密码正确！" << endl;
			ofstream ofs;
			ofs.open(ENTER,ios::app);
			cout << "请输入你想添加的账户的账号和密码：" << endl;
			cout << "账号：";
			string Account, keyword;
			cin >> Account;
			cout << "密码：";
			cin >> keyword;
			ofs <<" "<< Account << " " << keyword << endl;
			ofs.close();
			cout << "添加账户成功！" << endl;
			system("pause");
			system("cls");
			break;
		}
		else {
			if (num == 6) {  //输入错误次数达到五次
				cout << "您的错误次数到达5次，添加失败！" << endl;
				system("pause");
				system("cls");
				return;
			}
			else {
				cout << "账号或者密码错误，请重新输入！" << endl;
				cout << "请输入最高权限的密码：";
			}
		}
	}
}

void WorkerManager::Sort_Emp() {  //对员工信息进行排序
	cout << "请选择您想进行排序的类型：" << endl;
	cout << "1.按编号进行升序排列" << endl;
	cout << "2.按编号进行降序排列" << endl;
	cout << "请选择：";
	int select;
	cin >> select;
	for (int i = 0; i < this->Sum_workers; i++) {
		int minOrmax = i;  //先标记好最大或最小值
		for (int j = i+1; j < this->Sum_workers; j++) {
			if (select==1) {  //按升序排
				if (this->M_Emparray[minOrmax]->m_id > this->M_Emparray[j]->m_id) {  //不断进行更新
					minOrmax = j;
				}
			} 
			else {  //按降序排
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
	cout << "排序成功！排序后的结果为：" << endl;
	this->save();  //保存排序好的信息
	this->show_Emp();  //输出文件中所有的职工的信息
}

void WorkerManager::Clean_File() {   //清空文件操作
	cout << "您确定想清空文件里面的信息吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select;
	cout << "请选择：";
	cin >> select;
	if (select==1) {
		//清空文件
		ofstream ofs (FILENAME, ios::trunc);
		ofs.close();
		if (this->M_Emparray != NULL) {
			for (int i = 0; i < this->Sum_workers; i++) {
				if (this->M_Emparray[i] != NULL) {
					delete this->M_Emparray[i];
					this->M_Emparray[i] = NULL;
				}
			}
			//删除堆区数组指针
			delete this->M_Emparray;
			this->M_Emparray = NULL;
			this->Sum_workers = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() {  //析构函数
	if (this->M_Emparray != NULL) {
		for (int i = 0; i < this->Sum_workers; i++) {  //先释放数组里面的指针
			if (this->M_Emparray[i] != NULL) {
				delete this->M_Emparray[i];
			}
		}
		delete[]this->M_Emparray;
		this->M_Emparray = NULL;
	}
}
#pragma once
#include<iostream>
#include<algorithm>
#include<map>
#include<ctime>
#include<stdlib.h>
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"
#include<fstream>
#include<conio.h>
#define FILENAME "Empfile.txt"
#define ENTER "Enter.txt"
using namespace std;
class WorkerManager{
public:
	//构造函数
	 WorkerManager();
	 //初始化界面
	 void show_Menu();
	 //异常处理
	 void Error_Deal();
	 //退出系统
	 void exitsystem();
	 //记录职工人数
	 int Sum_workers;
	 //记录职工指针
	 Worker ** M_Emparray;
	 //添加新职工
	 void Add_Emp();
	 //判断文件是否为空
	 bool m_FileIsEmpty;
	 //获取文件的数据
	 int get_EmpNum();
	 void inti_Emp();
	 //保存数据
	 void save();
	 //输出员工信息
	 void show_Emp();
	 //检查员工信息是否存在
	 int Check_Emp(int id);
	 //删除员工信息
	 void Del_Emp();
	 //保存员工编号
	 map<int, int> mp;
	 //修改职工信息
	 void Mod_Emp();
	 //查找职工信息
	 void Find_Emp();
	 //按工号进行排序
	 void Sort_Emp();
	 //清空文件里面的所有信息
	 void Clean_File();
	 //添加新的登陆账户
	 void Add_Accoutant();
	 //字符串加密
	 string Ret_String();
	 //析构函数
	~WorkerManager();
};

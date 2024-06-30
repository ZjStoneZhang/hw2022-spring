#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
using namespace std;

static int basen = 2000;

class person{//person 类 
	protected:
		char name[10];
		int level;
		int number;
		float salary;
		
	public:
		person(){
			strcpy(name,"");
			level = 1;
			number = 0;
			salary = 0;
		}
		
		virtual void putName(const char *n){//输入姓名虚函数 
			strcpy(name, n);
		}
		
		virtual void pay(){//付薪虚函数 
		}
		
		virtual float getSalary(){//返回工资虚函数 
		}
		
		virtual int getNumber(){//编号虚函数 
		}
		
		virtual char* getName(){//姓名虚函数 
		} 
		
		virtual int getLevel(){//等级虚函数 
		}
		
		
};

class Technican: public person{//Technican 类 
	protected:
		float hour;
		
	public:
		Technican(){
			strcpy(name,"");
			level = 3;
			number = ++basen;
			salary = 0;
			hour = 0;
		}
		
		void putHour(float h){
			hour = h;
			salary = 100 * h;
		}
		
		void putName(const char *n){
			strcpy(name, n);
		}
		
		void pay(){
			float h;
			cout << "技术员    职工编号：" << number << ", 姓名：" << name 
			<< ", 月工作小时：";
			cin >> h;
			putHour(h);
		}
		
		int getNumber(){
			return number; 
		}
		
		char* getName(){
			return name;
		}
		
		int getLevel(){
			return level;
		}
		
		float getSalary(){
			return salary;
		}
};

class Manager: virtual public person{//Manager 类 
	public:
		Manager(){
			strcpy(name,"");
			level = 4;
			number = ++basen;
			salary = 8000;
		}
		
	    void putName(const char *n){
			strcpy(name, n);
		}
		
		void pay(){
			cout << "经理      职工编号：" << number << ", 姓名：" << name 
			<< endl; 
		}
		
		int getNumber(){
			return number; 
		}
		
		char* getName(){
			return name;
		}
		
		int getLevel(){
			return level;
		}
		
		float getSalary(){
			return salary;
		}
};

class Saleman: virtual public person{//Saleman 类 
	protected:
		float sale;
	
	public:
		Saleman(){
			strcpy(name,"");
			level = 1;
			number = ++basen;
			salary = 0;
			sale = 0;
		}
		
		virtual void putSale(float s){
			sale = s;
			salary = 0.04*s;
		}
		
		void putName(const char *n){
			strcpy(name, n);
		}

		void pay(){
			float s;
			cout << "推销员    职工编号：" << number << ", 姓名：" << name 
			<< ", 月销售金额：";
			cin >> s;
			putSale(s);
		} 
		
		int getNumber(){
			return number; 
		}
		
		char* getName(){
			return name;
		}
		
		int getLevel(){
			return level;
		}
		
		float getSalary(){
			return salary;
		}
};

class Salesmanager: public Saleman,public Manager{//Salemanager 类 

	public:
		Salesmanager(){
			strcpy(name,"");
			level = 3;
			number = --basen;
			salary = 5000;
			sale = 0;
		}
		
		void putSale(float s){
			sale = s;
			salary = 5000 + 0.015*s;
		}
		
		void putName(const char *n){
			strcpy(name, n);
		}

		void pay(){
			float s;
			cout << "销售经理  职工编号：" << number << ", 姓名：" << name 
			<< ", 月销售金额：";
			cin >> s;
			putSale(s);
		}
		
		int getNumber(){
			return number; 
		}
		
		char* getName(){
			return name;
		}
		
		int getLevel(){
			return level;
		}
		
		float getSalary(){
			return salary;
		}
};

person *p[100];

void menu_display();
void inputInfo();
void monthPay();
void showSalary();

void select(int n){
	if(n == 1) inputInfo();
	else if(n == 2) monthPay();
	else if(n == 3) showSalary();
	else if(n == 0) exit(0);
	else{
		cout << "invalid command!" << endl;
	}
	system("pause");
	menu_display();	
}

void menu_display(){
	
	cout << "    公司薪酬管理系统\n" << "-------------------------\n"
	<< "    1.  录入职工资料\n" << "    2.  月薪发放\n" << "    3.  " 
	<< "显示工资表\n" << "    0.  退出系统\n" << "----------------"
	<< "---------\n" << "请选择:"; 
	select(cin.get()-48);
}

void inputInfo(){
	char name[10];
	cout << "输入职工花名册" << endl;
	
	cout << "    输入经理名字，若输入@表示结束" << endl;
	for (size_t i = basen - 2000; i < 100; ++i ){
		cout << "        经理姓名：";
		cin >> name;
		if (name[0] == '@') {
			cout << "\n";
			--i;
			break;
		}
		p[i] = new Manager;
		p[i]->putName(name);
	}
	
	cout << "    输入销售经理名字，若输入@表示结束" << endl; 
	for (size_t i = basen - 2000; i < 100; ++i ){
		cout << "        销售经理姓名：";
		cin >> name;
		if (name[0] == '@') {
			cout << "\n";
			--i;
			break;
		}
		p[i] = new Salesmanager;
		p[i]->putName(name);
	}
	
	cout << "    输入技术人员名字，若输入@表示结束" << endl; 
	for (size_t i = basen - 2000; i < 100; ++i ){
		cout << "        技术人员姓名：";
		cin >> name;
		if (name[0] == '@') {
			cout << "\n";
			--i;
			break;
		}
		p[i] = new Technican;
		p[i]->putName(name);
	}
	
	cout << "    输入推销人员名字，若输入@表示结束" << endl; 
	for (size_t i = basen - 2000; i < 100; ++i ){
		cout << "        推销人员姓名：";
		cin >> name;
		if (name[0] == '@') {
			cout << "\n";
			--i;
			break;
		}
		p[i] = new Saleman;
		p[i]->putName(name);
	}
	
	cin.clear();
	cin.sync();
	
	cout << endl;
}

void monthPay(){
	for (size_t i = 0; i < basen - 2000; ++i){
		p[i]->pay();
	}
	
	cin.clear();
	cin.sync();//清除缓冲 
	
	cout << endl;
}

void showSalary(){
	float sum = 0;
	cout << "  职工编号  姓名      级别      月工资\n";
	for (size_t i = 0; i < basen - 2000; ++i ) {
		cout << "----------------------------------------\n" 
		<< "  " << p[i]->getNumber() << setw(12) <<p[i]->getName()
		<< setw(5) << p[i]->getLevel() << "         " << p[i]->getSalary()
		<< endl;
		sum += p[i]->getSalary();
	}
	cout << "----------------------------------------\n";
	cout << endl;
	cout << "  合计                          " << sum << endl;
	cout << endl;
	cin.clear();
	cin.sync();
	cout << endl;
}

int main()
{
	menu_display();
	return 0;
}

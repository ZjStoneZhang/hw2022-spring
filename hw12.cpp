#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
using namespace std;

static int basen = 2000;

class person{//person �� 
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
		
		virtual void putName(const char *n){//���������麯�� 
			strcpy(name, n);
		}
		
		virtual void pay(){//��н�麯�� 
		}
		
		virtual float getSalary(){//���ع����麯�� 
		}
		
		virtual int getNumber(){//����麯�� 
		}
		
		virtual char* getName(){//�����麯�� 
		} 
		
		virtual int getLevel(){//�ȼ��麯�� 
		}
		
		
};

class Technican: public person{//Technican �� 
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
			cout << "����Ա    ְ����ţ�" << number << ", ������" << name 
			<< ", �¹���Сʱ��";
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

class Manager: virtual public person{//Manager �� 
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
			cout << "����      ְ����ţ�" << number << ", ������" << name 
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

class Saleman: virtual public person{//Saleman �� 
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
			cout << "����Ա    ְ����ţ�" << number << ", ������" << name 
			<< ", �����۽�";
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

class Salesmanager: public Saleman,public Manager{//Salemanager �� 

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
			cout << "���۾���  ְ����ţ�" << number << ", ������" << name 
			<< ", �����۽�";
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
	
	cout << "    ��˾н�����ϵͳ\n" << "-------------------------\n"
	<< "    1.  ¼��ְ������\n" << "    2.  ��н����\n" << "    3.  " 
	<< "��ʾ���ʱ�\n" << "    0.  �˳�ϵͳ\n" << "----------------"
	<< "---------\n" << "��ѡ��:"; 
	select(cin.get()-48);
}

void inputInfo(){
	char name[10];
	cout << "����ְ��������" << endl;
	
	cout << "    ���뾭�����֣�������@��ʾ����" << endl;
	for (size_t i = basen - 2000; i < 100; ++i ){
		cout << "        ����������";
		cin >> name;
		if (name[0] == '@') {
			cout << "\n";
			--i;
			break;
		}
		p[i] = new Manager;
		p[i]->putName(name);
	}
	
	cout << "    �������۾������֣�������@��ʾ����" << endl; 
	for (size_t i = basen - 2000; i < 100; ++i ){
		cout << "        ���۾���������";
		cin >> name;
		if (name[0] == '@') {
			cout << "\n";
			--i;
			break;
		}
		p[i] = new Salesmanager;
		p[i]->putName(name);
	}
	
	cout << "    ���뼼����Ա���֣�������@��ʾ����" << endl; 
	for (size_t i = basen - 2000; i < 100; ++i ){
		cout << "        ������Ա������";
		cin >> name;
		if (name[0] == '@') {
			cout << "\n";
			--i;
			break;
		}
		p[i] = new Technican;
		p[i]->putName(name);
	}
	
	cout << "    ����������Ա���֣�������@��ʾ����" << endl; 
	for (size_t i = basen - 2000; i < 100; ++i ){
		cout << "        ������Ա������";
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
	cin.sync();//������� 
	
	cout << endl;
}

void showSalary(){
	float sum = 0;
	cout << "  ְ�����  ����      ����      �¹���\n";
	for (size_t i = 0; i < basen - 2000; ++i ) {
		cout << "----------------------------------------\n" 
		<< "  " << p[i]->getNumber() << setw(12) <<p[i]->getName()
		<< setw(5) << p[i]->getLevel() << "         " << p[i]->getSalary()
		<< endl;
		sum += p[i]->getSalary();
	}
	cout << "----------------------------------------\n";
	cout << endl;
	cout << "  �ϼ�                          " << sum << endl;
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

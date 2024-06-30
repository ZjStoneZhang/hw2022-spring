#include <iostream>
#include <cstring>
using namespace std;
class student {
	private:
		string name;
		int InjecTimes;
	    string Type[3];
	public:
		student();
		student(string s_name, string I_Type[3]);
		void KX();
		void SW();
		void DL();
		void showSLF();
		static void showALL();
		~student();
};


static int Inj[4] = {0, 0, 0, 0};//对应0针，1针，2针，3针人数 
static int KeXingInj = 0;//注射科兴总人数 
static int ShengWuInj = 0;//注射生物总人数 
static int DaLianInj = 0;//注射大连生物总人数 

student::student()
{
	name = "";
	InjecTimes = 0;
	for (size_t i = 0; i < 3; ++i){
		Type[i] = {""};
	}
}

student::student(string s_name, string I_Type[3])
{
	name = s_name;
	InjecTimes = 0;
	if(I_Type[0] == "") ++Inj[0];
	for (size_t i = 0; i < 3; ++i){
		Type[i] = I_Type[i];
		if (Type[i] == "KX"){
			++KeXingInj;
			++Inj[i + 1];
			++InjecTimes;
		}
		else if (Type[i] == "SW"){
			++ShengWuInj;
			++Inj[i + 1];
			++InjecTimes;
		} 
		else if (Type[i] == "DL"){
			++DaLianInj;
			++Inj[i + 1];
			++InjecTimes;
		}
	}
}

void student::KX()
{
	if (Type[2] != ""){
		cout << "invalid vaccination!" << endl << endl;//invalid if 3 times vaccinated
		return;
	}
		
	++KeXingInj;
	++InjecTimes;
	for (size_t i = 0; i < 3; ++i){
		if (Type[i] == "") {
			Type[i] = "KX";
			++Inj[i + 1];
			if (i == 0) --Inj[0];
			break;
		}
	}
	cout << name << ":KX vaccinated" << endl << endl;
}

void student::SW()
{
	if (Type[2] != ""){
		cout << "invalid vaccination!" << endl << endl;
		return;
	}
	
	++ShengWuInj;
	++InjecTimes;
	for (size_t i = 0; i < 3; ++i){
		if (Type[i] == "") {
			Type[i] = "SW";
			++Inj[i + 1];
			if (i == 0) --Inj[0];
			break;
		}
	}
	cout << name << ":SW vaccinated" << endl << endl;
}

void student::DL()
{
	if (Type[2] != ""){
		cout << "invalid vaccination!" << endl << endl;
		return;
	}
	
	++DaLianInj;
	++InjecTimes;
	for (size_t i = 0; i < 3; ++i){
		if (Type[i] == "") {
			Type[i] = "DL";
			++Inj[i + 1];
			if (i == 0) --Inj[0];
			break;
		}
	}
	cout << name << ":DL vaccinated" << endl << endl;
}

void student::showSLF()
{
	cout << "Student:" << name << endl;
	if (Type[0] != "") cout << "First vaccination:" << Type[0] << endl;
	if (Type[1] != "") cout << "Second vaccination:" << Type[1] << endl;
	if (Type[2] != "") cout << "Third vaccination:" << Type[2] << endl;
	cout << "Total vaccination:" << InjecTimes << endl << endl;
}

void student::showALL()
{
	cout << "Total no vaccination:" << Inj[0] << endl;
	cout << "Total first vaccination:" << Inj[1] << endl;
	cout << "Total second vaccination:" << Inj[2] << endl;
	cout << "Total third vaccination:" << Inj[3] << endl;
	cout << endl;
}

student::~student()
{
}

int main()
{
	string s1[3] = {"", "", ""};
	string s2[3] = {"KX", "", ""};
	string s3[3] = {"KX", "SW", ""};
	string s4[3] = {"KX", "DL", "DL"};
	student s_1("ZJS", s1), s_2("ZGH", s2), s_3("ZYL", s3), s_4("LZH", s4);
	s_1.showSLF();
	s_2.showSLF();
	s_3.showSLF();
	s_4.showSLF();
	s_1.showALL();
	
	s_1.KX();
	s_1.showSLF();
	s_2.showALL();
	
	s_2.SW();
	s_2.showSLF();
	s_3.showALL();
	
	s_4.DL();
	s_4.showALL();
	return 0;
}

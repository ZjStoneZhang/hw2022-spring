#include <iostream>
using namespace std;
class Date{
	public:
		Date(); 
		Date(int d_y, int d_m, int d_d); 
		~Date(); 
		int operator-(const Date &t) const; // 计算任意两天相隔天数 
	    /*unsigned int Legal() const; */
		int ToEoY() const; // 某日至该年12月31日的天数 
		int YBtw(const Date &t) const; // 两相隔年的相隔天数 
		int Asst() const; // 闰年判断 
	private:
		int year;
		int month;
		int day;
};

Date::Date()
{
	year = 0;
	month = 0;
	day = 0;
}

Date::Date(int d_y, int d_m, int d_d)
{
	year = d_y;
	month = d_m;
	day = d_d;
}

Date::~Date()
{
}

/*unsigned int Date::Legal() const
{
	int month_d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (Asst() == 1) month_d[1] = 29;
	if (month >= 1 && month <= 12) {
		if (day >= 0 && day <= month_d[month - 1]){
			return 1;
		}
		else {
			cout << "Date illegal!" << endl;
			return 0;
		}
	}
	else {
		cout << "Date illegal!" << endl;
		return 0;
	}
}*/

int Date::Asst() const
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return 1;
	else return 0;
}

int Date::YBtw(const Date &t) const
{
	int sum = 0;

	for (size_t i = t.year; i < year; ++i) {
		sum += 365;
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) sum += 1;
	}
	
	return sum;
}

int Date::ToEoY() const
{
	int sum = 0;
	int month_d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (Asst() == 1) month_d[1] = 29;
	sum += month_d[month - 1] - day;
	for (size_t i = month;i < 12; ++i) {
		sum += month_d[i];
	}
	return sum;
}

int Date::operator-(const Date &t) const
{
	Date t1;
	t1.year = year;
	t1.month = month;
	t1.day = day;
	int sum = 0;
	if (t1.year >= t.year){
		sum = t1.ToEoY() + t1.YBtw(t) - t.ToEoY();
	}
	else {
		sum = t.ToEoY() + t.YBtw(t1) - t1.ToEoY();
	}
	return sum;
}

int main()
{

	Date fd(2022, 4, 10);
	Date bd[3] = {Date(2003, 11, 20), Date(2004, 3, 19), Date(2003, 5, 29)};
    for (size_t i = 0; i < 3; ++i) {
    	cout << "日期" << i + 1 << "到2022年4月10日之间共有" << fd - bd[i] << "天！" << endl; 
	}
	return 0;
}

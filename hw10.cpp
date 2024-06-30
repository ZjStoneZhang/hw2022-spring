#include <iostream>
using namespace std;

class Div{
	private:
		int upn;
		int dwn;
	public:
		Div();
		Div(int u, int d);
		int mcf();
		void judge();
		void show();
		Div operator +(Div &d);
		~Div(); 
}; 

void Div::judge()
{
	if(upn*dwn == 0){
	    upn = 0;
		dwn = 1;	
	}
	
	if(mcf() != 0){
		int a = mcf();
		upn /= a;
		dwn /= a;
	}
}

Div::~Div()
{
}

Div::Div()
{
	upn = 0;
	dwn = 0;
}

Div::Div(int u, int d)
{
	upn = u;
	dwn = d;
	judge();
}

void Div::show()
{
	if(upn == 0){
		cout << "Invalid number!" ;
	}
	cout << upn << "/" << dwn << endl;
}

int Div::mcf()
{
	int a, b, c;
	
	if(upn*dwn == 0) return 0;
	
	if(upn > dwn){
		a = upn;
		b = dwn;
	}
	else{
		a = dwn;
		b = upn;
	}
	while(a % b != 0){
		c = b;
		b = a % b;
		a = c;
	}
	return b;
}

Div Div::operator+(Div &d)
{
	Div d1;
	d1.upn = upn * d.dwn + dwn * d.upn;
	d1.dwn = dwn * d.dwn;
	d1.judge();
	return d1;
}

int main()
{
	Div d1(100, 1), d2(6, 8);
	d1.show();
	d2.show();
	d1 = d1 + d2;
	d1.show();
	return 0 ;
} 

#include <iostream>
using namespace std;
class Line{
	protected:
		float length;
	public:
		Line();
		Line(float l_line);
		float getl();
		void showl();
};

class Square:public Line{
	protected:
		Line L;
	public:
		Square();
		Square(Line &l);
		void showc();
		void shows();
};

class Cube:public Square{
	protected:
		Square S;
	public:
		Cube();
		Cube(Square &s);
		void showss();
		void showv();
};

Line::Line()
{
	length = 0;
}

Line::Line(float l_line)
{
	length = l_line;
}

float Line::getl()
{
	return length;
}

void Line::showl()
{
	cout << "Length of line: " << getl() << endl;
}

Square::Square():L(0.0)
{
	length = 0;
}

Square::Square(Line &l):L(l.getl())
{
	length = l.getl();
}

void Square::showc()
{
	cout << "Perimeter of square: " << 4*getl() << endl;
}

void Square::shows()
{
	cout << "Area of square: " << getl()*getl() << endl;
}

Cube::Cube():S()
{
	length = 0;
}

Cube::Cube(Square &s)
{
	S = s;
	length = S.getl();
}

void Cube::showss()
{
	cout << "Surface area of cube: " << 6*getl()*getl()<< endl;
}

void Cube::showv()
{
	cout << "Volume of cube: " << getl()*getl()*getl() << endl;
}

int main()
{
	float lol;
	cout << "Enter length of line: ";
	cin >> lol;
	Line l(lol);
	Square s(l);
	Cube c(s);
	c.showl();
	c.shows();
	c.showss();
	c.showv();
	return 0;
}

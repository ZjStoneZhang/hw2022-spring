#include <iostream>
#include <math.h>
using namespace std;

class Point{
	private:
		float x;
		float y;
		
	public:
		Point(float ux = 0, float uy = 0){
			x = ux;
			y = uy;
		}
		
		float GetX(){
			return x;
		}
		
		float GetY(){
			return y;
		}
};

class Triange{
	private:
		Point p1, p2, p3;
		float c, c1, c2, c3;
		float s;
		float p;
		float temp1, temp2;
		
	public:
		Triange(float x1 = 0, float y1 = 0, float x2 = 0, float y2 = 0, float x3 = 0, float y3 = 0):p1(x1, y1),p2(x2, y2),p3(x3, y3){
			cout << "函数Triange被调用！" << endl;
		}
		
		void GetPerimeter(){
			c1 = sqrt(pow(p1.GetX()-p2.GetX(), 2) + pow(p1.GetY()-p2.GetY(), 2));
			c2 = sqrt(pow(p2.GetX()-p3.GetX(), 2) + pow(p2.GetY()-p3.GetY(), 2));
			c3 = sqrt(pow(p3.GetX()-p1.GetX(), 2) + pow(p3.GetY()-p1.GetY(), 2));
			c = c1 + c2 + c3;
		    cout << "三角形周长为：" << c << endl;
		}
		
		void GetArea(){
			c1 = sqrt(pow(p1.GetX()-p2.GetX(), 2) + pow(p1.GetY()-p2.GetY(), 2));
			c2 = sqrt(pow(p2.GetX()-p3.GetX(), 2) + pow(p2.GetY()-p3.GetY(), 2));
			c3 = sqrt(pow(p3.GetX()-p1.GetX(), 2) + pow(p3.GetY()-p1.GetY(), 2));		
			p = (c1 + c2 + c3)/2;
			s = sqrt(p * (p - c1) * (p - c2) * (p - c3));
			cout << "三角形面积为：" << s << endl;
		}
		
		void Rotate(){
			Triange((p1.GetX()-p1.GetY())/2,(p1.GetX()+p1.GetY())/2,(p2.GetX()-p2.GetY())/2,
			(p2.GetX()+p2.GetY())/2,(p3.GetX()-p3.GetY())/2,(p3.GetX()+p3.GetY())/2);
		}
};

int main()
{
	Triange a(1,1,2,2,3,1);
	a.GetPerimeter();
	a.GetArea();
	a.Rotate();
	a.GetPerimeter();
	a.GetArea();
    return 0;
}




















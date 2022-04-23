/*第十周期中考察2.1题 

/*题目要求：设计一个三角形类（二维空间），该类有一个成员函数：
形参有 x 和 y，返回值为 1 或 0：（x, y）是否在三角形内。*/ 

#include <iostream>
using namespace std;

class Point{
	private:
		float x;
		float y;
	public:
		Point();
		Point(float px, float py);
		Point operator-(Point &p);/*定义重载减法，返回类视为一个向量*/
		float operator*(Point &p);/*定义重载乘法，视为两向量做点乘并返回该值*/
		friend class Triangle;
		~Point();
		/*void show(){cout << "x=" << x << '\n' << "y=" << y << endl;}*//*调试代码*/ 
};

class Triangle{
	private:
		Point p1, p2, p3;
	public:
		Triangle();
		Triangle(Point &p1, Point &p2, Point &p3);
		int Judge(Point &p);
		~Triangle();
		
};

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(float px, float py)
{
	x = px;
	y = py;
}

Point Point::operator-(Point &p)
{
	Point p0;
	p0.x = this->x - p.x;
	p0.y = this->y - p.y;
	return p0;
}

float Point::operator*(Point &p)
{
	return p.x * this->x + p.y * this->y;
}

Point::~Point()
{
}

Triangle::Triangle():p1(0,0),p2(0,0),p3(0,0)
{
}

Triangle::Triangle(Point &p1, Point &p2, Point &p3):p1(p1.x, p1.y), p2(p2.x, p2.y), p3(p3.x, p3.y)
{
}

int Triangle::Judge(Point &p)
{
	Point pa, pb, pc, p_a, p_b, p_c;
	pa = p1 - p2;
	pb = p2 - p3;
	pc = p3 - p1;
	p_a = p - p1;
	p_b = p - p2;
	p_c = p - p3;
	
	/*pa.show();
	pb.show();
	pc.show();
	p_a.show();
	p_b.show();
	p_c.show();
	cout << pa*p_a << '\n' << pb*p_b << '\n' << pc*p_c << endl;*//*调试代码*/ 
	
	if (pa*p_a > 0 && pb*p_b > 0 && pc*p_c > 0){
		cout << "Point(" << p.x << ", " << p.y << ") in triangle!" << endl;/*算法说明：若p在三角形内，p1->p2->p, p2->p3->p, */
		return 1;                                                          /*p3->p1->p三条路径方向（顺时针或逆时针）一定相同。*/
	}                                                                          /*因此每条路径对应的两条向量内积和其他两条路径一定同*/
	else if(pa*p_a < 0 && pb*p_b < 0 && pc*p_c < 0){                           /*号。异号说明p点在三角形外，内积为零说明p在三角形的*/
		cout << "Point(" << p.x << ", " << p.y << ") in triangle!" << endl;/*某条边或顶点上。*/
		return 1;
	}
	else{
		cout << "Point(" << p.x << ", " << p.y << ") not in triangle!" << endl;
	}
}

Triangle::~Triangle()
{
}

int main()
{
	Point p0(0, 0);
	Point p1(0, 0), p2(2, 0), p3(1, 2);
	Triangle tr(p1, p2, p3);
	tr.Judge(p0);
	return 0;
}

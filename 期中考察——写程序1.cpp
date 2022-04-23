/*第十周期中考察2.1题 

/*题目要求：设计一个点类 Point，包含三个坐标数据成员 x, y, z 和一个构造
函数；再设计一个友元函数 distance()用于求两点之间在三维空间的距离。*/ 

#include <iostream>
#include <cmath>
using namespace std;

class Point{
	private:
		float x;
		float y;
		float z;
	public:
		Point();
		Point(float px, float py, float pz);
		~Point();
		friend float distance(Point &p1, Point &p2){
	            return sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2)+pow(p1.z-p2.z, 2));/*两点间距离公式*/
            }
};

Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}

Point::Point(float px, float py, float pz)
{
	x = px;
	y = py;
	z = pz;
}

Point::~Point()
{
}

int main()
{
	/*主函数测试*/
	Point p1(1, 1, 1);
	Point p2(0, 0, 0);
	cout << distance(p1, p2) << endl;
	return 0;
}

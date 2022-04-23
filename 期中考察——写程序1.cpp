/*��ʮ�����п���2.1�� 

/*��ĿҪ�����һ������ Point�����������������ݳ�Ա x, y, z ��һ������
�����������һ����Ԫ���� distance()����������֮������ά�ռ�ľ��롣*/ 

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
	            return sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2)+pow(p1.z-p2.z, 2));
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
	Point p1(1, 1, 1);
	Point p2(0, 0, 0);
	cout << distance(p1, p2) << endl;
	return 0;
}

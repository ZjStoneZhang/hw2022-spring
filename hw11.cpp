#include <iostream>
#include <cmath>
#define M_PI 3.1415927

using namespace std;
class base{
	public:
		virtual float volume()=0;
		virtual float area()=0;
};

class cone:public base{
	protected:
		float r;
		float h;
	public:
		cone(){
		}
		
		cone(float co_r, float co_h){
			r = co_r;
			h = co_h;
		}
		
		float volume(){
			return 1/3*M_PI*r*r*h;
		}
		
		float area(){
			return M_PI*r*(r+sqrt(r*r+h*h));
		}
};

class cylinder:public base{
	protected:
		float r;
		float h;
	public:
		cylinder(){
		}
		
		cylinder(float cy_r, float cy_h){
			r = cy_r;
			h = cy_h;
		}
		
		float volume(){
			return M_PI*r*r*h;
		}
		
		float area(){
			return 2.0*M_PI*r*(r+h);
		}
};

class cube:public base{
	protected:
		float a;
	public:
		cube(){
		}
		
		cube(float cb_a){
			a = cb_a;
		}
		
		float volume(){
			return a*a*a;
		}
		
		float area(){
			return 6.0*a*a;
		}
};

class cuboid:public base{
	protected:
		float a;
		float b;
		float c;
	public:
		cuboid(){
		}
		
		cuboid(float cd_a, float cd_b, float cd_c){
			a = cd_a;
			b = cd_b;
			c = cd_c;
		}
		
		float volume(){
			a*b*c;
		}
		
		float area(){
			return 2*(a*b+b*c+c*a);
		}
};

int main()
{
	float a1, a2, a3, a4, v1, v2, v3, v4;
	float sum_a, sum_v;
	
	base *pt[3];
	cone a[3] = {cone(3, 4), cone(5, 7), cone(1, 2)};
	cylinder b[3] = {cylinder(5, 8), cylinder(2, 6), cylinder(4, 2)};
	cube c[3] = {cube(1), cube(7), cube(9)};
	cuboid d[3] = {cuboid(1, 2, 3), cuboid(4, 5, 6), cuboid(7, 8, 9)};
	
	/*cone a[3] = {cone(0, 0), cone(0, 0), cone(0, 0)};
	cylinder b[3] = {cylinder(0, 0), cylinder(0, 0), cylinder(0, 0)};
	cube c[3] = {cube(0), cube(0), cube(0)};
	cuboid d[3] = {cuboid(0, 0, 0), cuboid(0, 0, 0), cuboid(0, 0, 0)};*/
	
	for (size_t i = 0; i < 3; ++i){
		pt[i] = &a[i];
		a1 += pt[i]->area();
		v1 += pt[i]->volume();
	}
	for (size_t i = 0; i < 3; ++i){
		pt[i] = &b[i];
		a2 += pt[i]->area();
		v2 += pt[i]->volume();
	}
	for (size_t i = 0; i < 3; ++i){
		pt[i] = &c[i];
		a3 += pt[i]->area();
		v3 += pt[i]->volume();
	}
	for (size_t i = 0; i < 3; ++i){
		pt[i] = &d[i];
		a4 += pt[i]->area();
		v4 += pt[i]->volume();
	}
	
	sum_a = a1 + a2 + a3 + a4;
	sum_v = v1 + v2 + v3 + v4;
	
	cout << "Total surface area: " << sum_a << endl;
	cout << "Total volume: " << sum_v << endl;
	
	return 0;
}

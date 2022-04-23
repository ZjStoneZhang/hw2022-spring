/*第十周期中考察1.1题 

/*题目要求：写出以下代码执行结果：*/ 

#include <iostream>
#include <cstring>
using namespace std;

class test{
	public:
		static int n;
		
		test(){
			++n;
		}
		
		~test(){
			--n;
		}
};

int test::n = 0;

int main()
{
	test a;
	test b[5];
	test *c = new test;
	cout << a.n << endl;
	delete c;
	cout << test::n << endl;
	return 0;
}

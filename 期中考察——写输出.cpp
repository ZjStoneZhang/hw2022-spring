/*��ʮ�����п���1.1�� 

/*��ĿҪ��д�����´���ִ�н����*/ 

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

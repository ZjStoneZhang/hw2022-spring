#include <iostream>
#include <math.h>
using namespace std;
void sum1(double &sum, unsigned int N){
	sum = 3*pow(4, N)/pow(3, N);
}

double sum2(unsigned int N){
	if ( N == 1) return 1;
	else return (pow(4, N-2)/pow(3, 2*N-3)) + sum2( N-1);
}

int main(void)
{
    double a, b;
    unsigned int n = 252;
    sum1(a, n);
    b = sum2(n);
    cout << "a="<< a << endl;
    cout << "b="<< b << endl;
}



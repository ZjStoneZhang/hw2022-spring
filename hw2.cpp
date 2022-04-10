#include <stdio.h>

int main(void)
{
	int a;
	int b[200] = {0};
	int m = 0, n = 0;
	while((a = getchar()) != '\n') {

		if (a >= '0' && a <= '9') {
			m = m + 1;
			if (n == 1) {// 通过n的值判断是否出现了下一个整数 
			    m = m - 1;
			}
			n = 1;
			b[m - 1] = 10 * b[m - 1] + a - 48;
		}
		
		else {
			n = 0;
		}
	}
	
	puts("");
	
	for (size_t i = 0; i <m; ++i) {
		printf("%d\n", b[i]);
	}
}


#include <stdio.h>
int main(void)
{
	int a[10];
	int *p = &a[9];
	for (size_t i = 0; i < 10; ++i) {
		scanf ("%d", &a[i]);
	}
	
	for (size_t i = 0; i < 10; ++i, --p) {
		printf("%-4d", *p);
	}
}


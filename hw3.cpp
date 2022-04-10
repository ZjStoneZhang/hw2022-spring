#include <iostream>
using namespace std;
int main(void)
{
	int a[26] = {0};
	char b[26];
	for (size_t i = 0; i < 26; ++i) {
		b[i] = 97 + i;
	}
	char c;
	while ((c = cin.get()) != '\n') {
		for (size_t i = 0; i < 26; ++i) {
			if (i == c - 97) ++a[i];
		}
	}
	
	for (size_t i = 0; i < 26; ++i) {
		cout << b[i] << "=" << a[i] << endl;
	}
	system("pause");
}



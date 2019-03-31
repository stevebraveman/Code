#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool chk_yy(char a) {
	if (a == 'a' || a == 'A' || a == 'e' || a == 'E' || a == 'i' || a == 'I' || a == 'o' || a == 'O' || a == 'u' || a == 'U') {
		return 1;
	}
	else return 0;
}
int main() {
	char a[60], c;
	int r = 0;
	while (1) {
		c=getchar();
		a[r] = c;
		if (a[r] == '\n') {
			break;
		}
		r++;
	}
	int l = strlen(a);
	int t = 0;
	for (int i = 0; i < l; i++) {
		if ((a[i] >= 'a'&&a[i] <= 'z') || (a[i] > 'A'&&a[i] <= 'Z')) {
			t++;
		}
	}
	for (int i = 0; i < l; i++) {
		if ((a[i] >= 'a'&&a[i] <= 'z') || (a[i] > 'A'&&a[i] <= 'Z')) {
			printf(".");
		}
	}
	printf("\n");
	double k = double(t) / 3.0;
	int p;
	if (k - floor(k) >= 0.5) {
		p = ceil(k);
	}
	else {
		p = floor(k);
	}
	for (int i = 0; i < l; i++) {
		if (i < p) {
			cout << a[i];
		}
		else {
			cout << '.';
		}
	}
	printf("\n");
	bool flag = 0;
	for (int i = p; i < l; i++) {
		if (chk_yy(a[i])) {
			flag = 1;
		}
	}
	if (flag) {
		for (int i = 0; i < l; i++) {
			if (i < p) {
				cout << a[i];
				continue;
			}
			if (i > p&&chk_yy(a[i])) {
				cout << a[i];
				continue;
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
	else {
		double q = (double)t * 2.0 / 3.0;
		int y;
		if (q - floor(q) >= 0.5) {
			y = ceil(q);
		}
		else {
			y = floor(q);
		}
		for (int i = 0; i < l; i++) {
			if (i < y) {
				cout << a[i];
			}
			else {
				cout << '.';
			}
		}
	}
	return 0;
}
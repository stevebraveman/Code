#include <iostream>
#include <cstdio>
#include <cstring>
int main() {
	int t;
	long long n;
	scanf("%d", &t);
	for (int j = 1; j <= t; j++) {
		scanf("%lld", &n);
		int tot = 0;
		for (; n > 0; n >>= 1) {
			if (n & 1) {
				tot++;
			}
		}
		if (tot == 2) {
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define euler 0.5772156649
int n;
double ans;
int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("0.00000");
		return 0;
	}
	n--;
	if (n <= 10000000) {
		for (int i = 1; i <= n; i++) {
			ans += 1.0 / i;
		}
		printf("%.5f", ans + 1.0);
		return 0;
	}
	printf("%.5f", log(n * 1.0) + 1.0 + euler);
	return 0;
}
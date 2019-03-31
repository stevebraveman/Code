#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
int a[50000010], b[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, n, k, tot, lg[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= 9; i++) {
		a[i] = b[i];
	}
	for (int i = 0; i <= n; i += 10) {
		a[i] = a[i / 10] + b[i % 10];
	}
	for (int i = 1; i <= n / 2; i++) {
		if (a[i] + a[n - i] + 4 == a[n]) {
			tot++;
		}
	}
	printf("%d", tot);
	return 0;
}
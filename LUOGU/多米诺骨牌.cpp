#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
#define CUP 5000
int f[MAXN][MAXN * 6 * 2], n, a[MAXN], b[MAXN], p, tot = 0x7fffffff;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	memset(f, 0x7f, sizeof(f));
	f[0][CUP] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = -5000; j <= 5000; j++) {
			p = a[i] - b[i];
			f[i][j + CUP] = min(f[i - 1][j - p + CUP], f[i - 1][j + p + CUP] + 1);
		}
	}
	for (int i = 0; i <= 5000; i++) {
		tot = min(f[n][i + CUP], f[n][CUP - i]);
		if (tot <= 1000) {
			printf("%d", tot);
			break;
		}
	}
	return 0;
}
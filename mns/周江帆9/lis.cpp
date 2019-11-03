#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 3000010
int k, a[MAXN], n, m, pos, b[MAXN], c[MAXN], yy[MAXN];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &b[i]);
		c[i] = b[i];
	}
	std::sort(c + 1, c + 1 + n, cmp);
	pos = k + 1;
	for (int i = 1; i <= k; i++) {
		if (c[i] != c[i + 1]) {
			yy[i] = 
		}
	}
	if (pos == 1) {
		puts("No");
		return 0;
	}
	int i;
	// printf("%d\n", k);
	for (i = 1; i < pos && i + k <= n; i++) {
		a[i] = m;
	}
	i--;
	// printf("%d %d %d", i + k, i, k);
	if (i + k == n) {
		puts("Yes");
		for (int j = 1; j <= k; j++) {
			a[j + i] = b[j];
		}
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[j]);
		}
		return 0;
	}
	// puts("OK");
	// int j = 1;
	// i++;
	// int tmp;
	// int oi = tmp = m - 1;
	// // a[i] = tmp;
	// int oo = 0;
	// for (i; i + k <= n; i++) {
	// 	a[i] = oi;
	// 	oo++;
	// 	if (oo == k) {
	// 		oi--;
	// 		oo = 0;
	// 	}
	// 	if (a[i] == b[j]) {
	// 		a[i] = tmp;
	// 		oi = tmp;
	// 		j++;
	// 	}
	// }
	// i--;
	// if (i + k == n) {
	// 	puts("Yes");
	// 	int t = 1;
	// 	for (int p = 1; p <= i; p++) {
	// 		printf("%d ", a[p]);
	// 		if (a[p] < a[p + 1]) {
	// 			printf("%d ", b[t]);
	// 			t++;
	// 		}
	// 	}
	// }
	else {
		puts("No");
	}
}
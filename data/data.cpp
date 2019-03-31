#include <bits/stdc++.h>
#define MAXN 1000100
int cnt = 0;
int x[MAXN], y[MAXN];
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
int main() {
	freopen("data.in", "w", stdout);
	srand(time(NULL));
	int n = 20000;
	for (int i = 2; i <= n; i++) {
		int t = rand() % i + 1;
		while (t == i) {
			t = rand() % i + 1;
		}
		x[i - 1] = t;
		y[i - 1] = i;
	}
	cnt = n - 1;
	int m = rand() % (n * 2 - cnt) + cnt;
	for (int i = cnt + 1; i <= m; i++) {
		int xi = rand() % n + 1;
		int yi = rand() % n + 1;
		while (xi == yi) {
			xi = rand() % n + 1;
			yi = rand() % n + 1;
		}
		x[i] = xi;
		y[i] = yi;
	}
	printf("%d %d\n", n, m);
	for (int i = 1; i <= m; i++) {
		printf("%d %d\n", x[i], y[i]);
	}
	int q = rand() % 100000 + 1;
	printf("%d\n", q);
	for (int i = 1; i <= q; i++) {
		int xi = rand() % n + 1;
		int yi = rand() % n + 1;
		printf("%d %d\n", xi, yi);
	}
}
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1001000
int x[MAXN], y[MAXN], opt;
int main() {
	int opt = rand() % 2;
	int n = rand() % 1000 + 1, m = rand() % 1000 + 1;
	srand(time(NULL));
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) {
		int d = rand() % 10000 + 1;
		printf("%d ", d);
	}
	puts("");
	for (int i = 2; i <= n; i++) {
		int t = rand() % i + 1;
		while (t == i) {
			t = rand() % i + 1;
		}
		x[i - 1] = t;
		y[i - 1] = i;
	}
	for (int i = 1; i < n; i++) {
		printf("%d %d\n", x[i], y[i]);
	}
	for (int i = 1; i <= m; i++) {
		opt = rand() % 2 + 1;
		printf("%d ", opt);
		if (opt == 1) {
			int u = rand() % n + 1;
			int v = rand() % 10000 + 1;
			printf("%d %d\n", u, v);
		}
		else {
			int u = rand() % n + 1;
			int v = rand() % n + 1;
			printf("%d %d\n", u, v);
		}
	}
}
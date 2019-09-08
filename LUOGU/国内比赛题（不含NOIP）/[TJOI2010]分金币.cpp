#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define delta 0.999
#define MAXN 100010
// #define abs(x) ((x) < 0 ? -(x) : x)
int b[3][MAXN], n, T, len[3], tot[3], a[MAXN], p, ans;
void swp(int x, int y) {
	tot[1] -= b[1][x];
	tot[2] -= b[2][y];
	tot[1] += b[2][y];
	tot[2] += b[1][x];
	std::swap(b[1][x], b[2][y]);
}
void SA() {
	double t = 1000.0;
	p = ans;
	while (t > 1e-15) {
		int _x = rand() % len[1] + 1;
		int _y = rand() % len[2] + 1;
		swp(_x, _y);
		int now = abs(tot[1] - tot[2]);
		int dt = now - p;
		if (dt < 0) {
			p = now;
			if (p < ans) {
				ans = p;
			}
		}
		else if (exp(-dt * 1.0 / t) * RAND_MAX > ((rand() % 1000000) / 1000000.0)){
			p = now;
		}
		else {
			swp(_x, _y);
		}
		t *= delta;
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		len[1] = n / 2;
		len[2] = n - len[1];
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		if (n == 1) {
			printf("%d\n", a[1]);
			continue;
		}
		tot[1] = tot[2] = 0;
		for (int i = 1; i <= n; i++) {
			if (i <= len[1]) {
				b[1][i] = a[i];
				tot[1] += a[i];
			}
			else {
				b[2][i - len[1]] = a[i];
				tot[2] += a[i];
			}
		}
		ans = p = abs(tot[1] - tot[2]);
		SA();
		SA();
		SA();
		printf("%d\n", ans);
	}
}
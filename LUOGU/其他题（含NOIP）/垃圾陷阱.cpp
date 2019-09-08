#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
struct rbs {
	int t, f, h;
}a[1010];
int f[110][1010], n, m, ans;
bool cmp(rbs a, rbs b) {
	return a.t < b.t;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a[i].t, &a[i].f, &a[i].h);
	}
	std::sort(a + 1, a + 1 + m, cmp);
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = -0x3f3f3f3f;
		}
	}
	f[0][0] = 10;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (f[i - 1][j] - a[i].t + a[i - 1].t >= 0) {
				f[i][j] = std::max(f[i - 1][j] - a[i].t + a[i - 1].t + a[i].f, f[i][j]);
			}
			if (j - a[i].h >= 0) {
				if (f[i - 1][j - a[i].h] - a[i].t + a[i - 1].t >= 0) {
					f[i][j] = std::max(f[i][j], f[i - 1][j - a[i].h] - a[i].t + a[i - 1].t);
					if (j == n) {
						// printf("%d ", i);
						printf("%d\n", a[i].t);
						return 0;
					}
				}
			}
		}
	}
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			ans = std::max(ans, f[i][j] + a[i].t);
		}
	}
	printf("%d", ans);
}
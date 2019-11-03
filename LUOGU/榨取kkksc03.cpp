#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
int f[210][210], ans, n, m, t, ti[MAXN], v[MAXN];
int main() {
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &v[i], &ti[i]);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= t; j++) {
			f[i][j] = -0x7fffffff;
		}
	}
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= v[i]; j--) {
			for (int k = t; k >= ti[i]; k--) {
				f[j][k] = std::max(f[j][k], f[j - v[i]][k - ti[i]] + 1);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= t; j++) {
			ans = std::max(ans, f[i][j]);
		}
	}
	printf("%d", ans);
}
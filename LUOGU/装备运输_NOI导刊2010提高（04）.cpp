#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 510
int f[510][510], n, w, v, val[MAXN], g[MAXN], vi[MAXN], ans;
int main() {
	scanf("%d%d%d", &v, &w, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &val[i], &vi[i], &g[i]);
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= w; j++) {
			f[i][j] = -0x7fffffff;
		}
	}
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= vi[i]; j--) {
			for (int k = w; k >= g[i]; k--) {
				f[j][k] = std::max(f[j][k], f[j - vi[i]][k - g[i]] + val[i]);
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= w; j++) {
			ans = std::max(f[i][j], ans);
		}
	}
	printf("%d", ans);
}
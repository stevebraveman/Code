#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000100
int ans, n, m, q[MAXN], v[MAXN], w[MAXN], t[MAXN], f[MAXN];
int calc(int p, int u, int k) {
	return f[u + k * w[p]] - k * v[p];
}
int main() {
	scanf("%d%d", &n, &m);
	memset(f, 0xcf, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &v[i], &w[i], &t[i]);
		for (int j = 0; j < w[i]; i++) {
			int l = 1, r = 0;
			int mp = (m - j) / w[i];
			for (int k = mp - 1; k >= std::max(mp - t[k], 0); k--) {
				while (l <= r && calc(i, j, q[r]) <= calc(i, j, k)) r--;
				q[++r] = k; 
			}
			for (int k = mp; k >= 0; k--) {
				while (l <= r && q[l] > k - 1) l++;
				if (l <= r) {
					f[j + k * w[i]] = std::max(f[j + k * w[i]], calc(i, j, q[l]) + k * v[i]);
				}
				if (k - t[i] - 1 >= 0) {
					while (l <= r && calc(i, j, q[r]) <= calc(i, j, k - t[i] - 1)) r--;
					q[++r] = k - t[i] - 1;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		ans = std::max(ans, f[i]);
	}
	printf("%d\n", ans);
}
/*

 */
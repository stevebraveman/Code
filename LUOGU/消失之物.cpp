#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 3010
int a[MAXN], n, m, f[MAXN], g[MAXN];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= a[i]; j--) {
			f[j] = (f[j - a[i]] + f[j]) % 10;
		}
	}
	for (int i = 1; i <= n; i++) {
		memcpy(g, f, sizeof(f));
		for (int j = a[i]; j <= m; j++) {
			g[j] = (g[j] - g[j - a[i]] + 10) % 10;
		}
		for (int j = 1; j <= m; j++) {
			printf("%d", g[j]);
		}
		puts("");
	}
}
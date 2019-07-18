#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 100010
struct Edge {
	int v, nx;
}e[MAXN << 2];
template <typename Tp>
Tp max(Tp a, Tp b) {
	if (a > b) return a;
	else return b;
}
int head[MAXN], ecnt, n, m, size[MAXN], x, y, fa[MAXN], out[MAXN], maxans = 0, ansi, ansj;
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		fa[y] = x;
		out[x]++;
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int k;
			if (fa[j] == i) {
				if (i == 1) {
					k = out[i] + out[j] - 1;
				}
				else {
					k = out[i] + out[j];
				}
				// continue;
				// maxans = max(maxans, );
			}
			else {
				if (i == 1) {
					k = out[i] + out[j];
				}
				else {
					k = out[i] + out[j] + 1;
				}
				// maxans = max(maxans, );
			}
			maxans = max(maxans, k);
		}
	}
	printf("%d", maxans);
	return 0;
}
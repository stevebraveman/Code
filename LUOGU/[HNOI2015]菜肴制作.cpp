#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define MAXN 100010
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, p[MAXN], T, in[MAXN], in2[MAXN];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		memset(head, 0, sizeof(head));
		ecnt = 0;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &x, &y);
			add(y, x);
			in[y]++;
		}
		std::priority_queue <int> q;
		for (int i = 1; i <= n; i++) {
			
		}
	}
}
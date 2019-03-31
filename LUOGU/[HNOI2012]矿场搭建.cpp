#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
struct Edge {
	int v, nx;
}e[MAXN];
int head[MAXN], t, t1, r, ecnt, x, tim, y, dfn[MAXN], low[MAXN], n, m, tot;
bool cut[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
} 
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	int flag = 0;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				flag++;
				if (u != r || flag > 1) cut[u] = 1;
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}
int main() {
	while (1) {
		memset(head, 0, sizeof(head));
		memset(e, 0, sizeof(e));
		memset(low, 0, sizeof(low));
		memset(dfn, 0, sizeof(dfn));
		memset(cut, 0, sizeof(cut));
		ecnt = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &x, &y);
			if (x == y) continue;
			add(x, y);
			add(y, x);
		}
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) r = i, tarjan(i);
		}
		for (int i = 1; i <= n; i++) {
			if (cut[i]) tot++;
		}
		printf("%d\n", tot);
		for (int i = 1; i <= n; i++) {
			if (cut[i]) write(i), sp();
		}
	}
}
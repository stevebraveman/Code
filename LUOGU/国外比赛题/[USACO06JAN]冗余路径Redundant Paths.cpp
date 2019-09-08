#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 1001000
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int f, v, nx;
}e[MAXN];
int head[MAXN], ecnt, dfn[MAXN], low[MAXN], n, m, x, y, tim, st[MAXN], top, g[MAXN];
int num, br, in[MAXN];
bool mp[5005][5005];
void add(int f, int t) {
	e[++ecnt] = (Edge) {f, t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (fa == v) continue;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(dfn[v], low[u]);
	}
	if (low[u] == dfn[u]) {
		int v;
		num++;
		do {
			v = st[top--];
			in[v] = num;
		} while (u != v);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		if (mp[x][y] || mp[y][x]) {
			continue;
		}
		add(x, y);
		add(y, x);
		mp[x][y] = mp[y][x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i, -1);
	}
	for (int i = 1; i <= ecnt; i += 2) {
		int f = e[i].f, v = e[i].v;
		if (in[f] != in[v]) {
			g[in[f]]++;
			g[in[v]]++;
		}
	}
	for (int i = 1; i <= num; i++) {
		if (g[i] == 1) br++;
	}
	printf("%d", (br + 1) >> 1);
	return 0;
}
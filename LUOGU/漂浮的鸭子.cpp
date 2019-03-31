#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000100
struct Edge {
	int v, nx;
}e[MAXN];
inline int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
inline int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int head[MAXN], tim, st[MAXN], top, ecnt, n, m, x, y, dfn[MAXN], low[MAXN], in[MAXN], si[MAXN], num, se[MAXN], ans;
bool vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[v], low[u]);
		}
		else if (vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		int v;
		num++;
		do {
			v = st[top--];
			in[v] = num;
			vis[v] = 0;
			si[num] += se[v];
		} while (u != v);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		add(i, x);
		se[i] = y;
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= num; i++) {
		ans = max(ans, si[i]);
	}
	printf("%d\n", ans);
	return 0;
}
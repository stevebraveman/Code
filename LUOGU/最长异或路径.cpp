#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 400010
struct Trie {
	int e[2], dat;
}t[MAXN * 32];
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int n, m, a[MAXN << 2], f, rt, tot, head[MAXN], ecnt, x, y, z, ans;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs(int u, int f) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		a[to] = a[u] ^ e[i].w;
		dfs(to, u);
	}
}
void insert(int k) {
	int p = 0;
	for (int i = 31; i >= 0; i--) {
		int d = (k >> i) & 1;
		if (!t[p].e[d]) t[p].e[d] = ++rt;
		p = t[p].e[d];
	}
	t[p].dat = k;
}
int ask(int k) {
	int p = 0;
	for (int i = 31; i >= 0; i--) {
		int d = (k >> i) & 1;
		if (t[p].e[d ^ 1]) {
			p = t[p].e[d ^ 1];
		}
		else p = t[p].e[d];
	}
	return t[p].dat ^ k;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		insert(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		ans = std::max(ans, ask(a[i]));
	}
	printf("%d\n", ans);
	return 0;
}
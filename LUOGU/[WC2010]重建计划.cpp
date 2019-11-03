#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define eps 0.00001
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
struct node {
	int dis, len;
}pth[MAXN];
int head[MAXN], ecnt, n, m, x, y, son[MAXN];
bool vis[MAXN], rt, siz[MAXN], size, tot, L, R;
double ty[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
bool cmp(node a, node b) {
	return a.len < b.len;
}
void dfs(int u, int f) {
	siz[u] = 1;
	son[u] = 0;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f || vis[to]) continue;
		dfs(to, u);
		siz[u] += siz[to];
		son[u] = std::max(siz[to], son[u]);
	}
	son[u] = std::max(siz[u], size - son[u]);
	if (son[rt] > son[u]) rt = u;
}
void dfsdis(int u, int f, int len, int k) {
	pth[++tot] = (node) {len, k};
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] || to == f) continue;
		dfs(to, u, len + e[i].w, k + 1);
	}
}
void solve(int u, int val, int fl) {
	tot = 0;
	dfsdis(u, val, 1);
	int l = 1, r = tot;
	sort(p + 1, p + 1 + tot, cmp);
	while (l < r) {
		if (p[r].len > R) r--;
		if (p[l].len + )
	}
}
void divide()
int main() {

}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 200010
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, siz[MAXN], son[MAXN], minn, r, ans[MAXN * 10], size, z, tot, k;
bool vis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
struct path {
	int w, lnum;
}dis[MAXN];
bool cmp(path a, path b) {
	return a.w < b.w;
}
void dfs(int u, int fa) {
	siz[u] = 1;
	son[u] = 0;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] || to == fa) continue;
		dfs(to, u);
		siz[u] += siz[to];
		son[u] = max(son[u], siz[to]);
	}
	son[u] = max(son[u], size - siz[u]);
	if (son[r] > son[u]) r = u;
}
void dfsdis(int u, int fa, int len, int nm) {
	dis[++tot] = (path) {len, nm};
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] || to == fa) continue;
		dfsdis(to, u, len + e[i].w, nm + 1);
	}
}
void solve(int u, int val, int op, int op2) {
	tot = 0;
	dfsdis(u, -1, val, op2);
	int l = 1;
	std::sort(dis + 1, dis + 1 + tot, cmp);
	for (; l <= tot && dis[1].w + dis[l].w <= k; l++);
	for (int i = 1; i <= tot && dis[i].w * 2 < k; i++) {
		int j = l - 1;
		while (j >= i) {
			int yy = dis[i].w + dis[j].w;
			if (yy <= k) {
				l = j + 1;
				if (yy == k) {
					ans[dis[i].lnum + dis[j].lnum] += op;
					while (dis[j - 1].w == dis[j].w && j > i) {
						j--;
						ans[dis[i].lnum + dis[j].lnum] += op;
					}
				}
				break;
			}
			j--;
		}
	}
}
void divide(int u) {
	vis[u] = 1;
	solve(u, 0, 1, 0);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to]) continue;
		solve(to, e[i].w, -1, 1);
		size = siz[to];
		r = 0;
		dfs(to, 0);
		divide(r);
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		x++;
		y++;
		add(x, y, z);
		add(y, x, z);
	}
	size = son[0] = n;
	dfs(1, -1);
	divide(r);
	for (int i = 0; i <= n; i++) {
		if (ans[i]) {
			printf("%d", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
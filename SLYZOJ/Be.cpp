#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define MOD 998244353
#define ll long long
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN * 4], ecnt, n, m, x, y, cnt, wt[MAXN], w[MAXN], r = 1, k;
int dep[MAXN], fa[MAXN], son[MAXN], si[MAXN], id[MAXN], top[MAXN], p[MAXN];
ll dp[52], a[52];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs1(int u, int f, int deep) {
	dep[u] = deep;
	fa[u] = f;
	si[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(to, u, deep + 1);
		si[u] += si[to];
		if (si[to] > si[son[u]]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	id[u] = ++cnt;
	wt[cnt] = p[u];
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (fa[u] == to || to == son[u]) continue;
		dfs2(to, to);
	}
}
inline int query(int x, int y) {
	int ans = 0;
	int dp[2][52] = {0};
	int yy = 1;
	dp[0][0] = 1;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		for (int i = id[top[x]]; i <= id[x]; i++) {
			for (int j = 0; j < k; j++) {
				dp[yy][(j + wt[i]) % k] = (dp[yy ^ 1][(j + wt[i]) % k] + dp[yy ^ 1][j]) % MOD;
			}
			yy ^= 1;
		}
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	for (int i = id[x]; i <= id[y]; i++) {
		for (int j = 0; j < k; j++) {
			dp[yy][(j + wt[i]) % k] = (dp[yy ^ 1][(j + wt[i]) % k] + dp[yy ^ 1][j]) % MOD;
		}
		yy ^= 1;
	}
	return dp[yy ^ 1][0];
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		p[i] %= k;
	}
	dfs1(r, 0, 1);
	dfs2(r, r);
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &x, &y);
		printf("%d\n", query(x, y));
	}
}
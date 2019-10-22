#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 20010
#define LOG 20
#define ll long long
#define int long long
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], m, n, ecnt, x, y, dep[MAXN], anc[MAXN][LOG + 1];
ll a[MAXN], ans[62], alb[MAXN][LOG + 1][62], lb[62], tot;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int f, int d) {
	dep[u] = d;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		anc[to][0] = u;
		dfs(to, u, d + 1);
	}
}
void ins(ll *a, ll b) {
	for (int i = 61; i >= 0; i--) {
		if ((b >> i) & 1) {
			if (!a[i]) {
				a[i] = b;
				break;
			}
			b ^= a[i];
		}
	}
}
void merge(ll *a, ll *b) {
	for (int i = 61; i >= 0; i--) {
		if (b[i]) {
			ins(a, b[i]);
		}
	}
}
void swim(int &x, int y) {
	for (int i = 20; i >= 0; i--) {
		if (dep[anc[x][i]] >= dep[y]) {
			merge(ans, alb[x][i]);
			x = anc[x][i];
		}
	}
}
void lca(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	swim(x, y);
	if (x == y) {
		merge(ans, alb[x][0]);
		return;
	}
	for (int i = LOG; i >= 0; i--) {
		if (anc[x][i] != anc[y][i]) {
			merge(ans, alb[x][i]);
			merge(ans, alb[y][i]);
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	merge(ans, alb[x][0]);
	merge(ans, alb[y][0]);
	merge(ans, alb[anc[x][0]][0]);
	return;
}
signed main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		ins(alb[i][0], a[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%lld%lld", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(1, 1, 1);
	for (int i = 1; i <= LOG; i++) {
		for (int j = 1; j <= n; j++) {
			anc[j][i] = anc[anc[j][i - 1]][i - 1];
			memcpy(alb[j][i], alb[j][i - 1], sizeof(alb[j][i - 1]));
			merge(alb[j][i], alb[anc[j][i - 1]][i - 1]);
		}
	}
	while (m--) {
		scanf("%lld%lld", &x, &y);
		memset(ans, 0, sizeof(ans));
		lca(x, y);
		tot = 0;
		for (int i = 61; i >= 0; i--) {
			tot = std::max(tot, ans[i] ^ tot);
		}
		printf("%lld\n", tot);
	}
}
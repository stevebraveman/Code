#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
#define MOD 1000000007
#define int long long
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, k, x, y, p[MAXN], f[MAXN][4];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int fa) {
	if (p[u]) {
		f[u][p[u]] = 1;
	}
	else {
		f[u][1] = 1;
		f[u][2] = 1;
		f[u][3] = 1;
	}
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
	if (to == fa) continue;
		dfs(to, u);
		f[u][1] = ((f[to][2] + f[to][3]) % MOD) * f[u][1] % MOD;
		f[u][2] = ((f[to][1] + f[to][3]) % MOD) * f[u][2] % MOD;
		f[u][3] = ((f[to][1] + f[to][2]) % MOD) * f[u][3] % MOD;
	}
}
signed main() {
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%lld%lld", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld%lld", &x, &y);
		p[x] = y;
	}
	dfs(1, -1);
	printf("%lld\n", (f[1][1] + f[1][2] + f[1][3]) % MOD);
	return 0;
}
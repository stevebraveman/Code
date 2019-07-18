#include <cstdio>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
#define MAXN 100001
struct Edge {
	int v, nx, w;
} e[MAXN * 2];
template <typename Tp>
Tp gcd(Tp a, Tp b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int f[5001][5001], G[5001][5001], head[MAXN];
int ecnt, n, m, ans;
inline void add(int f, int t, int w){
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs(int x, int fa){
	for (int i = 1; i <= m; i++) {
		f[x][i] = 1;
	}
	for (int i = head[x]; i; i = e[i].nx){
		int to = e[i].v;
		if (to != fa){
			dfs(to, x); 
			for (int j = 1; j <= m; j++) {
				int t = 0;
				for (int k = 1; k <= m; k++) {
					if (G[j][k] != e[i].w) {
						t = (t + f[to][k]) % MOD;
					}
				}
				f[x][j] = 1ll * f[x][j] * t % MOD;
			}
		}
	}
}
int main() {
	int x, y, w;
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w);
		add(y, x, w);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= i; j++) {
			G[j][i] = G[i][j] = std::__gcd(i, j);
		}
	}
	dfs(1, 0);
	for (int i = 1; i <= m; i++) {
		ans = (ans + f[1][i]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}

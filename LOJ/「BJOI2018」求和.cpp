#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXN 1000010
#define LOG 40
#define POW 51
#define MOD 998244353
#define int long long
int anc[MAXN << 1][LOG];
int val[MAXN << 1] , dep[MAXN << 1] , len , ecnt , u , v , s , k , p , q , y , n , m , head[MAXN] , pw[MAXN][POW];
int dis[MAXN];
struct edge {
	int v , nx , w;
}e[MAXN];
inline void add(int f , int t , int w) {
	e[++ecnt] = (edge){t , head[f] , w};
	head[f] = ecnt;
}
inline int qpow(int a , int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * a % MOD) % MOD;
		b >>= 1;
		a = (a * a % MOD) % MOD;
	}
	return res % MOD;
}
void dfs(int u , int p , int d) {
	anc[u][0] = p;
	dep[u] = d;
	for (int i = 1 ; i < POW ; i++) {
		pw[u][i] = (pw[p][i] + qpow(d - 1 , i)) % MOD;
	}
	for (int i = head[u] ; i ; i = e[i].nx) {
		int to = e[i].v;
		if (to == p) continue;
		dis[to] = dis[u] + e[i].w;
		dfs(to , u , d + 1);
	}
}
inline void init(int r , int n) {
	dis[r] = 0;
	dfs(r , 0 , 1);
	for (int j = 1 ; j < LOG ; j++) {
		for (int i = 1 ; i <= n ; i++) {
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
}
inline void swim(int &x , int h) {
	for (int i = 0 ; h > 0 ; i++) {
		if (h & 1) x = anc[x][i];
		h >>= 1;
	}
}
inline int query(int x , int y) {
	if (dep[x] < dep[y]) std::swap(x , y);
	swim(x , dep[x] - dep[y]);
	if (x == y) return x;
	for (int i = LOG - 1 ; i >= 0 ; i--) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}
signed main() {
	scanf("%lld" , &n);
	for (int i = 1 ; i < n ; i++) {
		scanf("%lld%lld" , &u , &v);
		add(u , v , 1);
		add(v , u , 1);
	}
	init(1 , n);
	scanf("%lld" , &m);
	while (m--) {
		scanf("%lld%lld%lld" , &u , &v , &k);
		y = query(u , v);
		printf("%lld\n" , ((((pw[u][k] + pw[v][k]) % MOD) - (pw[y][k] + pw[anc[y][0]][k]) % MOD) + MOD) % MOD);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 2147483647
#define MAXN 1000100
#define LOG 25
struct node {
	int u , v , w;
}a[MAXN];
struct Edge {
	int v , nx , w;
}e[MAXN];
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
inline int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
int anc[MAXN << 1][LOG] , f[MAXN << 1][LOG], dis[MAXN] , dep[MAXN << 1] , len;
int n , m , fa[MAXN] , ecnt , head[MAXN] , g , l , r;
bool vis[MAXN];
inline void add(int f , int t , int w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] == find(fa[x]);
}
int cmp(node a , node b) {
	return a.w > b.w;
}
void dfs(int u) {
	vis[u] = 1;
	for (int i = head[u] ; i ; i = e[i].nx) {
		int to = e[i].v;
		if (vis[1]) continue;
		anc[to][0] = u;
		dep[to] = dep[u] + 1;;
		f[to][0] = e[i].w;
		dfs(to);
	}
}
inline void init(int r , int n) {
	for (int i = 1 ; i <= n ; i++) {
		if (!vis[i]) {
			dep[i] = 1;
			dfs(i);
			anc[i][0] = i;
			f[i][0] = INF;
		}
	}
	for (int j = 1 ; j < LOG ; j++) {
		for (int i = 1 ; i <= n ; i++) {
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
			f[i][j] = min(f[i][j - 1] , f[anc[i][j - 1]][j - 1]);
		}
	}
}
inline int LCA(int x , int y) {
	if (find(x) != find(y)) return -1;
	int ans = INF;
	if (dep[x] < dep[y]) std::swap(x , y);
	int h = dep[x] - dep[y];
	for (int i = 0 ; h > 0 ; i++) {
		if (dep[anc[x][i]] >= dep[y]) {
			ans = min(ans , f[x][i]);
			x = anc[x][i];
		}
	}
	if (x == y) return ans;
	for (int i = LOG - 1 ; i >= 0 ; i--) {
		if (anc[x][i] != anc[y][i]) {
			ans = min(ans , min(f[x][i] , f[y][i]));
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	ans = min(ans , min(f[x][0] , f[y][0]));
	return ans;
}
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d%d" , &a[i].u , &a[i].v , &a[i].w);
	}
	for (int i = 1 ; i <= n ; i++) {
		fa[i] = i;
	}
	std::sort(a + 1 , a + 1 + m , cmp);
	for (int i = 1 ; i <= m ; i++) {
		int x = find(a[i].u);
		int y = find(a[i].v);
		if (x == y) continue;
		else {
			fa[x] = y;
			add(a[i].u , a[i].v , a[i].w);
			add(a[i].v , a[i].u , a[i].w);
		}
	}
	for (int i = 1 ; i < LOG ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			anc[j][i] = anc[anc[j][i - 1]][i - 1];
			f[j][i] = min(f[j][i - 1] , f[anc[j][i - 1]][i - 1]);
		}
	}
	init(1 , n);
	scanf("%d" , &g);
	for (int i = 1 ; i <= g ; i++) {
		scanf("%d%d" , &l , &r);
		printf("%d\n" , LCA(l , r));
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 60005
struct Edge {
	int v , nx;
}e[MAXN];
int ecnt , head[MAXN] , f[MAXN] , n , m , fa[MAXN] , dp[MAXN] , t;
bool vis[MAXN];
void add(int f , int t) {
	e[++ecnt] = (Edge){t , head[f]};
	head[f] = ecnt;
}
void dfs(int x , int y) {
	vis[x] = 1;
	if (y == 0) return;
	for (int i = head[x] ; i ; i = e[i].nx) {
		int go = e[i].v;
		dfs(go , y - 1);
	}
	dfs(fa[x] , y - 1);
}
int main() {
	scanf("%d" , &n);
	fa[1] = 1;
	for (int i = 2 ; i <= n ; i++) {
		scanf("%d" , &m);
		add(m , i);
		fa[i] = m;
	}
	for (int i = 1 ; i <= n ; i++ ) {
		dp[i] = dp[fa[i]] + 1;
	}
	int ans = 0;
	memset(vis , 0 , sizeof(vis));
	while (1) {
		t = 0;
		for (int i = 1 ; i <= n ; i++) {
			if (!vis[i] && dp[i] > dp[t]) t = i;
		}
		if (t == 0) break;
		dfs(fa[fa[t]] , 2);
		ans++;
	}
	printf("%d" , ans);
	return 0;
}
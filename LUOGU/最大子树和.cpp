#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 500000
struct Edge {
	int v , nx;
}e[MAXN];
int head[MAXN] , a[MAXN] , u , v , f[MAXN] , r , ecnt , n , ans;
inline int max (int a , int b) {
	if (a > b) return a;
	else return b;
}
void add(int f , int t) {
	e[++ecnt] = (Edge) {t , head[f]};
	head[f] = ecnt;
}
void dfs(int s , int fr) {
	for (int i = head[s] ; i ; i = e[i].nx) {
		int go = e[i].v;
		if (go == fr) continue;
		dfs(go , s);
		f[s] += f[go];
	}
	f[s] = max(f[s] + a[s] , 0);
}
int main() {
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , &a[i]);
	}
	for (int i = 1 ; i < n ; i++) {
		scanf("%d%d" , &u , &v);
		add(u , v);
		add(v , u);
	}
	dfs(1 , 0);
	for (int i = 1 ; i <= n ; i++) {
		ans = max(ans , f[i]);
	}
	printf("%d" , ans);
	return 0;
}
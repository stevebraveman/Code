#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
struct Edge {
	int v , nx , w;
}e[MAXN];
int ecnt = 0 , head[MAXN] , u , v , w , n , m , t;
bool vis[MAXN] , flag;
void add(int f , int t , int w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
bool dfs(int r , int v , int t) {
	for (int i = head[t] ; i ; i = e[i].nx) {
		int f = e[i].v;
		int y = e[i].w;
		if (f == r && ((y ^ v) != 0)) return 0;
		if (vis[f]) continue;
		vis[f] = 1;
		if (!dfs(r , v ^ y ,f)) return 0;
	}
	return 1;
}
int main() {
	scanf("%d" , &t);
	while (t--) {
		ecnt = 0;
		flag = 0;
		memset(head , 0 , sizeof(head));
		memset(e , 0 , sizeof(e));
		scanf("%d%d" , &n , &m);
		for (int i = 1 ; i <= m ; i++) {
			scanf("%d%d%d" , &u , &v , &w);
			add(u , v , w);
			add(v , u , w);
		}
		for (int i = 1 ; i <= n ; i++) {
			memset(vis , 0 , sizeof(vis));
			vis[i] = 1;
			if (!dfs(i , 0 , i)) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
}

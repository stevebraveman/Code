#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define int long long
#define MAXN 1000005
struct Edge {
	int v , nx , w;
}e[MAXN];
int n , m , ecnt , head[MAXN] , dis[MAXN] , tot[MAXN] , u , v , x , ans = 0;
bool vis[MAXN];
inline void add(int f , int t , int w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
bool spfa() {
	memset(dis , 0 , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	vis[0] = 1;
	dis[0] = 0;
	tot[0] = 1;
	std::queue <int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (tot[u] == n - 1) return 0;
		vis[u] = 0;
		tot[u]++;
		for (int i = head[u] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] < dis[u] + e[i].w) {
				dis[to] = dis[u] + e[i].w;
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
	return 1;
}
signed main() {
	scanf("%lld%lld" , &n , &m);
	while (m--) {
		scanf("%lld%lld%lld" , &x , &u , &v);
		if (x == 1) {
			add(u , v , 0);
			add(v , u , 0);
		}
		if (x == 2) {
			if (u == v) {
				printf("-1");
				return 0;
			}
			add(u , v , 1);
		}
		if (x == 3) {
			add(v , u , 0);
		}
		if (x == 4) {
			if (u == v) {
				printf("-1");
				return 0;
			}
			add(v , u , 1);
		}
		if (x == 5) {
			add(u , v , 0);
		}
	}
	for (int i = n ; i >= 1 ; i--) {
		add(0 , i , 1);
	}
	if (!spfa()) {
		printf("-1");
		return 0;
	}
	else {
		for (int i = 1 ; i <= n ; i++) {
			ans += dis[i];
		}
		printf("%lld" , ans);
		return 0;
	}
}
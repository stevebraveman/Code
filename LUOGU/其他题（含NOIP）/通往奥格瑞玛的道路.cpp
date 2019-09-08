#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000005
#define int long long
#define INF 0x7fffffffffffffff
struct Edge {
	int v , nx , w;
}e[MAXN];
int head[MAXN] , u , v , b , l , r , m , n , p1[MAXN] , p2[MAXN] , ecnt , dis[MAXN] , ans , w;
bool vis[MAXN];
void add(int f , int t , int w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
bool spfa(int p) {
	memset(dis , 0x7f , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	dis[1] = 0;
	vis[1] = 1;
	std::queue <int> q;
	q.push(1);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vis[v] = 0;
		for (int i = head[v] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[v] + e[i].w && p1[to] <= p) {
				dis[to] = dis[v] + e[i].w;
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
	if (dis[n] <= b) {
		return 1;
	}
	else return 0;
}
signed main() {
	scanf("%lld%lld%lld" , &n , &m , &b);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%lld" , &p1[i]);
		p2[i] = p1[i];
	}
	std::sort(p2 + 1 , p2 + 1 + n);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%lld%lld%lld" , &u , &v , &w);
		add(u , v , w);
		add(v , u , w);
	}
	l = 1;
	r = n;
	m = 0;
	if (!spfa(INF)) {
		printf("AFK\n");
		return 0;
	}
	while (l <= r) {
		m = (l + r) >> 1;
		if (spfa(p2[m])) {
			ans = p2[m];
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	printf("%lld\n" , ans);
	return 0;
}

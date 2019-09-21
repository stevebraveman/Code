#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000005
#define int long long
#define INF 0x7fffffffffffffffLL
struct Edge {
	int v , nx , w;
}e[MAXN];
int head[MAXN] , u , v , b , l , r , m , n , p1[MAXN] , p2[MAXN] , ecnt , dis[MAXN] , ans , w , x , ed;
bool vis[MAXN];
void add(int f , int t , int w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
struct node {
	int id , w;
};
bool operator < (node a , node b) {
	return a.w > b.w;
}
bool dijkstra(int s , int p , int r) {
	memset(dis , 0x7f , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	std::priority_queue <node> q;
	dis[s] = 0;
	q.push((node){s , 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int v = f.id;
		if(p1[v] > p)continue;
		if (vis[v]) continue;
		vis[v] = 1;
		for (int i = head[v] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (p1[to] > p) continue;
			if (dis[to] > dis[v] + e[i].w) {
				dis[to] = dis[v] + e[i].w;
				q.push((node){to , dis[to]});
			}
		}
	}
	if (dis[r] <= b) return 1;
	else return 0;
}
signed main() {
	scanf("%lld%lld%lld%lld%lld" , &n , &m , &x , &ed , &b);
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
	if (!dijkstra(x , INF , ed)) {
		printf("-1\n");
		return 0;
	}
	while (l <= r) {
		m = (l + r) >> 1;
		if (dijkstra(x , p2[m] , ed)) {
			ans = p2[m];
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	printf("%lld" , ans);
	return 0;
}
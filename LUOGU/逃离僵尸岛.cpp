#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define ll long long 
#define MAXN 2000005
struct Edge {
	ll v , nx;
}e[MAXN];
ll head[MAXN] , dis[MAXN] , ecnt , u , v , p , qi , k , pt , dan[MAXN] , r , n , m;
bool vis[MAXN];
void add(ll f , ll t) {
	e[++ecnt] = (Edge){t , head[f]};
	head[f] = ecnt;
}
struct node {
	ll id , w;
};
bool operator < (node a , node b) {
	return a.w > b.w;
}
struct ne {
	ll u , di;
};
std::queue <ne> qq;
void dijkstra(ll s) {
	memset(dis , 0x7f , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	std::priority_queue <node> q;
	dis[s] = 0;
	q.push((node){s , 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		ll v = f.id;
		if (vis[v]) continue;
		vis[v] = 1;
		for (ll i = head[v] ; i ; i = e[i].nx) {
			ll to = e[i].v;
			if (dan[to] == -1) continue;
			if (dan[to] == 0) {
				if (dis[to] > dis[v] + p) {
					dis[to] = dis[v] + p;
					q.push((node){to , dis[to]});
				}
			}
			if (dan[to] == 1) {
				if (dis[to] > dis[v] + qi) {
					dis[to] = dis[v] + qi;
					q.push((node){to , dis[to]});
				}
			}
		}
	}
}
void bfs() {
	while (!qq.empty()) {
		ne f = qq.front();
		qq.pop();
		ll x = f.u , y = f.di;
		for (ll i = head[x] ; i ; i = e[i].nx) {
			ll to = e[i].v;
			if (y < r and dan[to] == 0) {
				dan[to] = 1;
				qq.push((ne){to , y + 1});
			}
		}
	}
}
int main() {
	scanf("%lld%lld%lld%lld" , &n , &m , &k , &r);
	scanf("%lld%lld" , &p , &qi);
	memset(dan , 0 , sizeof(0));
	for (ll i = 1 ; i <= k ; i++) {
		scanf("%lld" , &pt);
		dan[pt] = -1;
		qq.push((ne){pt , 0});
	}
	for (ll i = 1 ; i <= m ; i++) {
		scanf("%lld%lld" , &u , &v);
		add(u , v);
		add(v , u);
	}
	bfs();
	dijkstra(1);
	if (dan[n] == 1) dis[n] -= qi;
	else dis[n] -= p;
	printf("%lld" , dis[n]);
	return 0;
}

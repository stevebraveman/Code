#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 100005
#define INF 19260817
struct Edge {
	int v , nx , w;
}e[MAXN];
std::queue <int> q;
int head[MAXN] , dis[MAXN] , ecnt , n , tot[MAXN] , m , t , u , v , w;
bool flag = 0 , vis[MAXN];
void add(int f , int t , int w) {
	e[++ecnt] = (Edge){t , head[f] , w};
	head[f] = ecnt;
}
bool spfa(int s) {
	for (int i = 1 ; i <= n ; i++) {
		dis[i] = -INF;
	}
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		vis[f] = 0;
		tot[f]++;
		if (tot[f] == n) return 0;
		for (int i = head[f] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] < dis[f] + e[i].w) {
				dis[to] = dis[f] + e[i].w;
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
	return 1;
}
int main() {
	scanf("%d" , &t);
	while (t--) {
		while (!q.empty()) q.pop();
		memset(vis , 0 , sizeof(vis));
		memset(head , 0 , sizeof(head));
		memset(tot , 0 , sizeof(tot));
		ecnt = 0;
		scanf("%d%d" , &n , &m);
		while (m--) {
			scanf("%d%d%d" , &u , &v , &w);
			add(u - 1 , v , w);
			add(v , u - 1 , -w);
		}
		flag = 0;
		for (int i = 0 ; i <= n ; i++) {
			if (tot[i] == 0) {
				if (!spfa(i)) {
					flag = 1;
					break;
				}
			}
		}
		if (!flag) {
			printf("true");
		}
		else printf("false");
		puts("");
	}
}
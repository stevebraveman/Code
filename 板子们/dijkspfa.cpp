/*
dijkstra和SPFA结合
 */
#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 50003
using namespace std;
int n , m , ecnt , dis[MAXN] , vis[MAXN] , head[MAXN] , x , y , z , s;
struct Edge {
	int v , nx , w;
}e[MAXN];
struct node {
	int id , d;
};
void add(int from , int to , int w) {
	e[++ecnt] = (Edge){to , head[from] , w};
	head[from] = ecnt;
}
bool operator < (node a , node b) {
	return a.d > b.d;
}
void spfa(int s) {
	memset(dis , 0x7f , sizeof(dis));
	memset(vis , 0 , sizeof(dis));
	queue <int> q;
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].w) {
				dis[to] = dis[u] + e[i].w;
				if (!vis[to]) {
					vis[to] = true;
					q.push(to);
				}
			}
		}
	}
}
void dijkstra(int s) {
	memset(dis , 0x7f , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	priority_queue <node> q;
	dis[s] = 0;
	q.push((node){s , 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int v = f.id;
		if (vis[v]) continue;
		vis[v] = 1;
		for (int i = head[v] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[v] + e[i].w) {
				dis[to] = dis[v] + e[i].w;
				q.push((node){to , dis[to]});
			}
		}
	}
}
int main() {
	scanf("%d%d%d" , &n , &m , &s);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d%d" , &x , &y , &z);
		add(x , y , z);
		// add(y , x , z);
	}
	dijkstra(s);
	for (int i = 1 ; i <= n ; i++) {
		printf("%d " , dis[i]);
	}
	spfa(s);
	puts("");
	for (int i = 1 ; i <= n ; i++) {
		printf("%d " , dis[i]);
	}
	return 0;
}

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define MAXN 500003
using namespace std;
int n , m , ecnt , dis[MAXN] , vis[MAXN] , head[MAXN] , ans[MAXN] , x , y , z , s;
struct Edge {
	int v , nx , w;
}e[MAXN * 4];
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
void dijkstra(int s) {
	memset(dis , 0x7f , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	memset(ans , 0 , sizeof(ans));
	priority_queue <node> q;
	dis[s] = 0;
	ans[s] = 1;
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
				ans[to] = ans[v];
				q.push((node){to , dis[to]});
			}
			else if (dis[to] == dis[v] + e[i].w) {
				ans[to] = (ans[to] + ans[v]);
			}
		}
	}
}
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d%d" , &x , &y , &z);
		add(x , y , z);
	}
	dijkstra(1);
	if (dis[n] >= 2000000000) {
		printf("No answer");
		return 0;
	}
	printf("%d %d", dis[n] , ans[n]);
	return 0;
}
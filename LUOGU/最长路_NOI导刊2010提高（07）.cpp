#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAXN 200005
#define wzx using
#define AK namespace
#define IOI std;
wzx AK IOI
struct Edge {
	int v , nx , w;
}e[MAXN * 4];
int ecnt , dis[MAXN] , vis[MAXN] , head[MAXN] , n , m , x , y , z;
void add(int f , int to , int w) {
	e[++ecnt] = (Edge){to , head[f] , w};
	head[f] = ecnt;
}
void spfa(int s) {
	memset(dis , 0x7f , sizeof(dis));
	memset(vis , 0 , sizeof(vis));
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		vis[f] = 0;
		for (int i = head[f] ; i ; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[f] + e[i].w) {
				dis[to] = dis[f] + e[i].w;
				if (!vis[to]) {
					vis[to] = true;
					q.push(to);
				}
			}
		}
	}
}
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d%d" , &x , &y , &z);
		add(x , y , -z);
	}
	spfa(1);
	if (dis[n] > 2000000000) {
		printf("-1");
		return 0;
	}
	printf("%d" , -dis[n]);
}
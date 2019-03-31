#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define SIZE 1000100
using namespace std;
int head[SIZE],n,m,s,ecnt,dis[SIZE];
bool vis[SIZE];
struct node {
	int id,w;
};
struct edge {
	int v,nxt,dist;
} e[4*SIZE];
bool operator <(node a,node b) {
	return (a.w>b.w);
}
void add_edge(int from,int to,int dis) {
	e[++ecnt]=(edge) {
		to,head[from],dis
	};
	head[from]=ecnt;
}
void dijkstra(int u) {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<node>q;
	dis[u]=0;
	q.push((node) {
		u,0
	});
	while(!q.empty()) {
		node flag=q.top();
		q.pop();
		int v=flag.id;
		if(vis[v]) continue;
		vis[v]=1;
		for(int i=head[v]; i; i=e[i].nxt) {
			int to=e[i].v;
			if(dis[to]>dis[v]+e[i].dist) {
				dis[to]=dis[v]+e[i].dist;
				q.push((node) {
					to,dis[to]
				});
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	dijkstra(1);
//	for(int i=1; i<=n; i++)
		printf("%d",dis[n]);
	return 0;
}

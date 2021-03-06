#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define SIZE 1000100
using namespace std;
int head[SIZE],n,m,s,ecnt,dis[SIZE];
bool vis[SIZE];
int min(int a,int b){
	return a<b?a:b;
}
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
	memset(dis,0x7f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<node>q;
	dis[u]=0;
	q.push((node) {u,0});
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
				q.push((node){to,dis[to]});
			}
		}
	}
}
int main() {
	int p1,p2;
	scanf("%d%d%d%d%d",&m,&n,&s,&p1,&p2);
	int x,y,z;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	dijkstra(p1);
	int ans1=dis[s]+dis[p2];
	dijkstra(p2);
	int ans2=dis[s]+dis[p1];
	printf("%d",min(ans2,ans1));
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define SIZE 10001
using namespace std;
int head[SIZE],n,m,s,ecnt,dis[SIZE];
bool vis[SIZE];
struct node {
	int id,w;
};
int min(int a,int b) {
	return a<b?a:b;
}
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
	scanf("%d%d%d",&s,&n,&m);
	int a[501];
	for(int i=1; i<=s; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=m; i++) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	int ans=0x7fffffff;
	for(int i=1; i<=n; i++) {
		dijkstra(i);
		int k=0;
		for(int j=1; j<=s; j++) {
			k+=dis[a[j]];
		}
		ans=min(k,ans);
	}
	printf("%d",ans);
	return 0;
}

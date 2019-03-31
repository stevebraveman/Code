#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
struct arr {
	int x,y,w,next;
} edge[2000200];
int ans[1000200];
int ls[1000200];
int dis[1000200];
int v[1000200];
int n,m,s,t;
int edge_m;
struct cmp {
	bool operator ()(int a,int b) {
		return dis[a]>dis[b];
	}
};
void add(int x,int y,int w) {
	edge_m++;
	edge[edge_m]=(arr) {
		x,y,w,ls[x]
	};
	ls[x]=edge_m;
	edge_m++;
	edge[edge_m]=(arr) {
		y,x,w,ls[y]
	};
	ls[y]=edge_m;
}
int main() {
	scanf("%d%d",&n,&m);
	s=1;
	priority_queue<int,vector<int>,cmp> Q;
	memset(dis,63,sizeof(dis));
	for (int i=1; i<=m; i++) {
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
	}
	ans[s]=1;
	dis[s]=0;
	v[s]=1;
	Q.push(s);
	for (int i=1; i<=n; i++) {
		int x=Q.top();
		Q.pop();
		for (int j=ls[x]; j; j=edge[j].next) {
			if (dis[edge[j].y]>dis[x]+edge[j].w) {
				dis[edge[j].y]=dis[x]+edge[j].w;
				ans[edge[j].y]=ans[x];
				if (!v[edge[j].y]) {
					v[edge[j].y]=1;
					Q.push(edge[j].y);
				}
			} else if (dis[edge[j].y]==dis[x]+edge[j].w)
				ans[edge[j].y]=(ans[edge[j].y]+ans[x])%100003;
		}
	}
	for (int i=1; i<=n; i++) {
		printf("%d\n",ans[i]%100003);
	}
}

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define INF 2147483647
using namespace std;
int value[500001],to[500001],next[500001];
int head[500001],total;
int book[500001];
int dis[500001];
int n,m;
void adl(int a,int b,int c) {
	total++;
	to[total]=b;
	value[total]=c;
	next[total]=head[a];
	head[a]=total;
}
//void init(){
//	for(int i=1;i<=m;i++){
//		dis[i]
//	}
//}
void dijkstra(int u) {
//	memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i]=INF;
	}
	memset(book,0,sizeof(book));
	dis[u]=0;
	for(int i=1; i<=n; i++) {
		int start=-1;
		for(int j=1; j<=n; j++)
			if(book[j]==0 && (dis[start]>dis[j] || start==-1))
				start=j;
		book[start]=1;
		for(int e=head[start]; e; e=next[e])
			dis[to[e]]=min(dis[to[e]],dis[start]+value[e]);
	}
}
int main() {
	int k;
	cin>>n>>m>>k;
	
	for(int i=1; i<=m; i++) {
		int a,b,c;
		cin>>a>>b>>c;
		adl(a,b,c);
	}
	dijkstra(k);
	for(int i=1; i<=n; i++)
		cout<<dis[i]<<" ";
}

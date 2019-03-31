#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int map[110][110];
int dis[10010];
int book[10010];
int n,m;
void dijkstra(int u) {
	memset(dis,88,sizeof(dis));
	int start=u;
	book[start]=1;
	for(int i=1; i<=n; i++) {
		dis[i]=min(dis[i],map[start][i]);
	}
	for(int i=1; i<=n-1; i++) {
		int minn=9999999;
		for(int j=1; j<=n; j++)
			if(book[j]==0 && minn>dis[j]) {
				minn=dis[j];
				start=j;
			}
		book[start]=1;
		for(int j=1; j<=n; j++)
			dis[j]=min(dis[j],dis[start]+map[start][j]);
	}
}
int main() {
	cin>>n>>m;
	memset(map,88,sizeof(map));
	for(int i=1; i<=m; i++) {
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=c;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i==j)
				map[i][j]=0;
	dijkstra(1);
	for(int i=1; i<=n; i++)
		cout<<dis[i]<<" ";
}

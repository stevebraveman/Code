#include<iostream>
#include<cstdio>
using namespace std;
int fa[500005],rk[500005];
int find(int x) {
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return x;
}
void un(int r1,int r2) {
	int x=find(r1);
	int y=find(r2);
	if(x==y) return; 
	if(rk[x]<rk[y]) fa[x]=y;
	else{
		fa[y]=x;
		if(rk[x]==rk[y]) rk[x]++;
	}
}
int main() {
	int n,m,x,y,z;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		fa[i]=i;
		rk[i]=0;
	}
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&z,&x,&y);
		if(z==1) {
			un(x,y);
		} else {
			if(find(x)==find(y)) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}

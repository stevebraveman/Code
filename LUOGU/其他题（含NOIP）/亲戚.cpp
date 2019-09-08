#include<iostream>
#include<cstdio>
using namespace std;
int fa[200005];
int find(int x) {
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return x;
}
void un(int r1,int r2) {
	fa[r2]=r1;
}
int main() {
	int n,m,x,y,z,q;
	cin>>n>>m>>q;
	for(int i=1; i<=n; i++) {
		fa[i]=i;
	}
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&x,&y);
		int r1=find(x);
		int r2=find(y);
		if(r1!=r2) un(r1,r2);
	}
	for(int i=1; i<=q; i++) {
		scanf("%d%d",&x,&y);
		if(find(x)==find(y)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

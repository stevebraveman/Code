#include<bits/stdc++.h>
#define MOD 10000019
using namespace std;
int m,ls[1000002*3];
struct node {
	int x,y,e;
} bcj[MOD*2];
int disa=0;
bool cmp(node a,node b) {
	return a.e>b.e;
}
int fa[200005];
int find(int x) {
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return x;
}
void un(int r1,int r2) {
	fa[r1]=r2;
}
int main() {
	int t;
	cin>>t;
	for(int q=1; q<=t; q++) {
		disa=-1;
		bool flag=1;
		memset(ls,0,sizeof(ls));
		memset(fa,0,sizeof(fa));
		cin>>m;
		for(int i=1; i<=m; i++) {
			scanf("%d %d %d",&bcj[i].x,&bcj[i].y,&bcj[i].e);
			ls[disa++]=bcj[i].x;
			ls[disa++]=bcj[i].y;
		}
		sort(ls,ls+disa);
		int x=unique(ls,ls+disa)-ls;
		for(int i=1; i<=m; i++) {
			bcj[i].x=lower_bound(ls,ls+x,bcj[i].x)-ls;
			bcj[i].y=lower_bound(ls,ls+x,bcj[i].y)-ls;
		}
		for(int i=1; i<=x; i++) {
			fa[i]=i;
		}
		sort(bcj+1,bcj+1+m,cmp);
		for(int i=1; i<=m; i++) {
			int g=find(bcj[i].x);
			int h=find(bcj[i].y);
			if(bcj[i].e) {
				un(g,h);
			} else {
				if(g==h) {
					printf("NO\n");
					flag=0;
					break;
				} else {
					flag=1;
				}
			}
		}
		if(flag) printf("YES\n");
	}
	return 0;
}

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int fa[5002];
struct edge {
	int u,v;
	long long w;
} e[400004];
int find(int x) {
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return x;
}
bool un(int a,int b) {
	int aa=find(a);
	int bb=find(b);
	if(aa==bb) return 0;
	fa[bb]=aa;
	return 1;
}
bool cmp(edge a,edge b) {
	return a.w<b.w;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n+1; i++) {
		fa[i]=i;
	}
	for(int i=1; i<=m; i++) {
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
		e[i].u++;
		e[i].v++;
	}
	sort(e+1,e+1+m,cmp);
	long long ans=0;
	int cnt=1;
	for(int i=1; i<=m; i++) {
		if(un(e[i].u,e[i].v)) {
			ans+=e[i].w;
			cnt++;
		}
//		if(cnt==n) break;
	}
	printf("%lld",ans);
	return 0;
}

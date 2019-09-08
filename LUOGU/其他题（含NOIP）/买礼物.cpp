#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
typedef struct {
	int u, v;
	int w;
} Edge;
Edge e[2000002];
int fa[2000002];
bool cmp(const Edge &a, const Edge &b) {
	if (a.w<b.w) return true;
	else return false;
}
int find(int n) {
	if (fa[n]==0)  return n;
	else return find(fa[n]);
}
int un(int r1, int r2) {
	r1=find(r1);
	r2=find(r2);
	if (r1==r2) return 0;
	if (r1<r2) fa[r2]=r1;
	else fa[r1]=r2;
	return 1;
}
int main() {
	int n,q;
	int sum,count;
	int tot=0;
	cin>>n>>q;
	int o=1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++){
			cin>>e[o].w;
			e[o].u=i;
			e[o].v=j;
			o++;
		}
	}
	sort(e+1,e+1+n*n,cmp);
	memset(fa,0,sizeof(fa));
	sum=0;
	count=1;
	for (int i=1; i<=n*n; i++) {
		if (un(e[i].u,e[i].v)) {
			sum+=e[i].w;
			count++;
		}
		if(count==n)break;
	}
	printf("%d",sum+q);
	return 0;
}

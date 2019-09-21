#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point {
	int x;
	int y;
	int v;
};
int min(int a,int b) {
	return a<b?a:b;
}
point a[1000001];
int cmp(const point &a,const point &b) {
	if(a.v<b.v) return 1;
	else return 0;
}
int fa[1000001];
int find(int x) {
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return fa[x];
}
void unionn(int x,int y) {
	int fg=find(x);
	int fh=find(y);
	if(fg!=fh) fa[fg]=fh;
}
int main() {
	int n,m,k=0,ans=0,cnt=0;
	cin>>n;
	int u,mina=0x7fffff;
	for(int i=1; i<=n; i++) {
		scanf("%d",&u);
		mina=min(u,mina);
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>m;
			if(m!=0) {
				k++;
				a[k].x=i;
				a[k].y=j;
				a[k].v=m;
			}
		}
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1; i<=n; i++) {
		fa[i]=i;
	}
	for(int i=1; i<=k; i++) {
		if(find(a[i].x)!=find(a[i].y)) {
			ans+=a[i].v;
			unionn(a[i].x,a[i].y);
			cnt++;
		}
		if(cnt==n-1) break;
	}
	cout<<ans+mina;
	return 0;
}

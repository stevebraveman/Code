#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,c[100005],a[100005]= {0},fs[100005]={0};
int max(int a,int b) {
	return a>b?a:b;
}
ll lowbit(ll x) {
	return x&(-x);
}
void add(ll x,ll d) {
	while(x<=n) {
		c[x]+=d;
		x+=lowbit(x);
	}
}
void up(ll x){
	while(x<=n){
		c[x]=0;
		x+=lowbit(x);
	}
}
ll sum(int x) {
	ll ret=0;
	while(x>=1) {
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}
int main() {
	ll m;
	scanf("%lld%lld",&n,&m);
	memset(c,0,sizeof(c));
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		add(i,a[i]);
	}
	ll maxa=n;
	for(int i=1; i<=m; i++) {
		char op;
		cin>>op;
		switch(op) {
			case 'C': {
				ll x;
				ll k;
				scanf("%lld%lld",&x,&k);
				if(!fs[x])add(x,-k);
				a[x]-=k;
				break;
			}
			case 'Q': {
//				int x,y;
//				scanf("%d%d",&x,&y);
				printf("%lld\n",sum(maxa)-sum(0));
				break;
			}
			case 'D': {
				ll x;
				scanf("%lld",&x);
				add(x,-a[x]);
//				up(x);
				fs[x]=1;
				break;
			}
			case 'I': {
				ll x,y;
				scanf("%lld%lld",&x,&y);
				add(x,-a[x]);
				add(x,y);
				fs[x]=0;
				a[x]=y;
				maxa=max(maxa,x);
				break;
			}
		}
	}
	return 0;
}

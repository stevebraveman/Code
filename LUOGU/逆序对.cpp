#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500010],b[500010],c[500010],n,m,i,j,k;
void discretize() {
	sort(b+1,b+1+n);
	unique(b+1,b+1+n)-b-1;
	for(i=1; i<=n; ++i) a[i]=lower_bound(b+1,b+1+n,a[i])-b;
}
inline int lowbit(int x) {
	return x&-x;
}
int add(int x,int k) {
	for(int i=x; i<=n; i+=lowbit(i))c[i]+=k;
}
int sum(int x) {
	int ret=0;
	for(int i=x; i>0; i-=lowbit(i)) ret+=c[i];
	return ret;
}
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; ++i) {
		scanf("%d",&b[i]);
		a[i]=b[i];
	}
	discretize();
	long long ans=0;
	for(i=n; i>0; --i) {
		add(a[i],1);
		ans+=sum(a[i]-1);
	}
	printf("%lld\n",ans);
	return 0;
}

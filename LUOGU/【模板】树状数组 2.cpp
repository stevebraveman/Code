#include<bits/stdc++.h>
#define MAXN 1000007
using namespace std;
int n,m;
int c[MAXN],a[MAXN];
int lowbit(int k) {
	return k&(-k);
}
void up(int k,int num) {
	if(k==0) return ;
	while(k<=n) {
		c[k]+=num;
		k+=lowbit(k);
	}
	return;
}
int sum(int k) {
	int ans=0;
	while(k>0) {
		ans+=c[k];
		k-=lowbit(k);
	}
	return ans;
}
int main() {
	scanf("%d%d",&n,&m);
	int t;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		up(i,a[i]);
		up(i+1,-a[i]);
	}
	int t1,t2,t3,t4;
	for(int i=1; i<=m; i++) {
		scanf("%d",&t1);
		if(t1==1) {
			scanf("%d%d%d",&t2,&t3,&t4);
			up(t2,t4);
			up(t3+1,-t4);
		}
		if(t1==2) {
			scanf("%d",&t2);
			cout<<sum(t2)<<endl;
		}
	}
	return 0;
}

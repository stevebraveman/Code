#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#define lowbit(x) (x)&(-(x))
using namespace std;
int n,m,a[500009],c[500009];
int up(int pos,int v) {
	for(int i=pos; i<=n; i+=lowbit(i)) {
		c[i]+=v;
	}
	return 0;
}
int sum(int x) {
	int ans=0;
	for(int i=x; i>0; i-=lowbit(i)) {
		ans+=c[i];
	}
	return ans;
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; ++i){
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++) {
		up(i,a[i]);
	}
	for(int i=1; i<=m; ++i) {
		int flag;
		int x,y;
		scanf("%d%d%d",&flag,&x,&y);
		if(flag==1) {
			up(x,y);
		} else {
			cout<<sum(y)-sum(x-1)<<endl;
		}
	}
	return 0;
}

//³Ë»ý×î´ó(cj).cpp
#include<iostream>
#include<cstdio>
using namespace std;
int num[50],chk[50],n,m;
long long maxa=0;
void dfs(int a,int tot) {
	if(tot==m) {
		long long t=0,p=1;
		for(int i=1; i<=n-1; i++) {
			t+=num[i],t*=10;
			if(chk[i]==1) {
				t/=10;
				p*=t;
				t=0;
			}
		}
		t+=num[n];
		p*=t;
		if(p>maxa) maxa=p;
		return;
	}
	if(a==n) return;
	chk[a]=1;
	dfs(a+1,tot+1);
	chk[a]=0;
	dfs(a+1,tot);
}
int main() {
	//freopen("cj.in","r",stdin);
	//freopen("cj.out","w",stdout);
	cin>>n>>m;
	getchar();
	for(int i=1; i<=n; i++) {
		num[i]=getchar();
		num[i]=num[i]-'0';
	}
	dfs(1,0);
	cout<<maxa;
}

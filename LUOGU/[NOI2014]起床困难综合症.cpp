#include<iostream>
#include<bitset>
#include<cmath>
#include<cstdio>
#define re register
using namespace std;
int MAXN=-1,MINN=0,n,m;
int main() {
	scanf("%d%d",&n,&m);
	for (re int i=1; i<=n; i++) {
		char ch[5];
		int x;
		cin>>ch;cin>>x;
		if(ch[0]=='A') {MAXN=MAXN&x;MINN=MINN&x;}
		if(ch[0]=='O') {MAXN=MAXN|x;MINN=MINN|x;}
		if(ch[0]=='X') {MAXN=MAXN^x;MINN=MINN^x;}
	}
	bitset<30> bs1(MAXN),bs2(MINN);
	int ans=0;
	for (re int i=0; i<30; i++) {
		int k=1<<i;
		if((bs1[i]==1&&k<=m)||bs2[i]==1){
			ans+=k;
		}
	}
	cout<<ans;
}
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	int n;
	int x,y,tot=0;
	scanf("%d",&n);
	int a[n+2],b[n+2],g[n+2],k[n+2];
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
	}
	scanf("%d%d",&x,&y);
	for(int i=1;i<=n;i++){
		if(((a[i]<=x)&&(a[i]+g[i]>=x))&&(((b[i]<=y)&&(b[i]+k[i]>=y)))){
			tot++;
		}
	}
	if(tot==0) cout<<"-1";
	else cout<<tot;
	return 0;
}

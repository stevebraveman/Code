#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 2002
using namespace std;
int max(int a,int b) {
	if(a>b) return a;
	else return b;
}
int min(int a,int b) {
	if(a<b) return a;
	else return b;
}

int a[MAXN][MAXN],f[MAXN][MAXN],l[MAXN][MAXN],r[MAXN][MAXN],L[MAXN][MAXN],R[MAXN][MAXN],h[MAXN][MAXN],n,m,ans=0,ansj=0,tmp;
int solve() {
	memset(f,0,sizeof(f));
	memset(l,0,sizeof(f));
	memset(r,0,sizeof(f));
	memset(L,0,sizeof(f));
	memset(R,0,sizeof(f));
	memset(h,0,sizeof(f));
	for (int i=1; i<=n; i++) {
		tmp=0;
		for (int j=1; j<=m; j++){
			if (a[i][j]){
				l[i][j]=tmp;
			}
			else {
				tmp=j;
				L[i][j]=0;
			}
		}
		tmp=m+1;
		for (int j=m; j>=1; j--){
			if (a[i][j]) {
				r[i][j]=tmp;
			}
			else {
				tmp=j;
				R[i][j]=m+1;
			}
		}
	}
	for (int i=1; i<=m; i++) {
		R[0][i]=m+1;
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i][j]) {
				h[i][j]=h[i-1][j]+1;
				L[i][j]=max(L[i-1][j],l[i][j]);
				R[i][j]=min(R[i-1][j],r[i][j]);
				ansj=max(ansj,h[i][j]*(R[i][j]-L[i][j]-1));
			}
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d",&a[i][j]);
			f[i][j]=1;
			if(i>=2&&j>=2) {
				if(((a[i][j-1]^a[i][j])==1)&&(a[i-1][j-1]==a[i][j])&&(a[i-1][j]==a[i][j-1])) {
					f[i][j]=min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1;
					ans=max(ans,f[i][j]*f[i][j]);
				}
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if((i&1)==(j&1)) {
				a[i][j]^=1;
			}
		}
	}
	solve();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			a[i][j]^=1;
		}
	}
	solve();
	printf("%d\n%d",ans,ansj);
	return 0;
}

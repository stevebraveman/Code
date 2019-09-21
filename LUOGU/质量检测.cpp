#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
int d[100002];
int dp1[100002][55];
int dp2[100002][55];
int max(int a,int b) {
	return a>b?a:b;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&d[i]);
	}
	for(int i=1; i<=n; i++) {
		dp1[i][0]=d[i];
		dp2[i][0]=d[i];
	}
	for(int j=1; (1<<j)<=n; j++) {
		for(int i=1; i+(1<<j)-1<=n; i++) {
//			dp1[i][j]=max(dp1[i][j-1],dp1[i+(1<<j-1)][j-1]);
			dp2[i][j]=min(dp2[i][j-1],dp2[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=1;i<=n-m+1;i++){
		int ll=i,rr=i+m-1;
		int k=0;
		while((1<<k+1)<=rr-ll+1)k++;
//		int maxi=max(dp1[ll][k],dp1[rr-(1<<k)+1][k]);
		int mini=min(dp2[ll][k],dp2[rr-(1<<k)+1][k]);
		printf("%d",/*maxi-*/mini);
		printf("\n");
	}
	return 0;
}


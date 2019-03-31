#include<iostream>
#include<cstdio>
using namespace std;
int a[101][101],f[105][105];
int max(int a,int b){
	return a>b?a:b;
}
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
	}
	for(int k=1; k<=n+1; k++) {
		for(int i=1; i<=n+1; i++) {
			for(int j=1; j<=n+1; j++) {
				if(i!=j&&j!=k&&a[i][k]&&a[k][j]) {
					a[i][j]=max(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
	}
	printf("%d\n1 ",a[1][n+1]);
	for(int i=2;i<=n+1;i++){
		if(a[1][i]+a[i][n+1]==a[1][n+1]){
			printf("%d ",i);
		}
	}
}

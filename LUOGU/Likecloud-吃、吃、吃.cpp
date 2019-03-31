#include<iostream>
#include<cstdio>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int n,m,a[201][201]={0},ma[201][201]={0};
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ma[i][j]=max(max(ma[i-1][j],ma[i-1][j-1]),ma[i-1][j+1])+a[i][j];
		}
	}
	printf("%d",max(ma[m][n>>1],max(ma[m][(n>>1)+1],ma[m][(n>>1)+2])));
}

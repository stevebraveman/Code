#include<iostream>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int mp[50][50]={0};
int f[52][52][52][52]={0};
int main(){
	int n,v,m;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>v;
			mp[i][j]=v;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int p=1;p<=m;p++){
				for(int q=1;q<=n;q++){
					f[i][j][p][q]=max(max(f[i-1][j][p-1][q],f[i][j-1][p-1][q]),max(f[i-1][j][p][q-1],f[i][j-1][p][q-1]))+mp[i][j]+mp[p][q];
					if(i==p&&j==q) f[i][j][p][q]-=mp[p][q];
				}
			}
		}
	}
	cout<<f[m][n][m][n]<<endl;
}

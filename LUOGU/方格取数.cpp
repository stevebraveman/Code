#include<iostream>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,x,y,v;
	int mp[15][15]={0};
	int f[15][15][15][15]={0};
	cin>>n;
	while(cin>>x>>y>>v){
		if(x==0&&y==0&&v==0){
			break;
		}
		mp[x][y]=v; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int p=1;p<=n;p++){
				for(int q=1;q<=n;q++){
					f[i][j][p][q]=max(max(f[i-1][j][p-1][q],f[i][j-1][p-1][q]),max(f[i-1][j][p][q-1],f[i][j-1][p][q-1]))+mp[i][j]+mp[p][q];
					if(i==p&&j==q) f[i][j][p][q]-=mp[p][q];
				}
			}
		}
	}
	cout<<f[n][n][n][n]<<endl;
}

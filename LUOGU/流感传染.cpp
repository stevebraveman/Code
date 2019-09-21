#include<bits/stdc++.h>
using namespace std;
char f[101][101];
int m,n,x,y=0,j=0;
bool g[101][101];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
		}
	}
	cin>>x;
	while(x>1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][j]=='@') {
					if(f[i+1][j]=='.') f[i+1][j]='y';
					if(f[i][j+1]=='.') f[i][j+1]='y';
					if(f[i-1][j]=='.') f[i-1][j]='y';
					if(f[i][j-1]=='.') f[i][j-1]='y';
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
					if(f[i][j]=='y') f[i][j]='@';
			}
		}
		x--;
	}
	for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
					if(f[i][j]=='@'||f[i][j]=='w') y++;
			}
	}
	cout<<y;
}

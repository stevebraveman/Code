#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int main(){
	int a[101][101]={0},n,m,p;
	char b[101][101];
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) cin>>b[i][j];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(b[i+1][j]=='*') a[i][j]++;
			if(b[i-1][j]=='*') a[i][j]++;
			if(b[i+1][j+1]=='*') a[i][j]++;
			if(b[i-1][j-1]=='*') a[i][j]++;
			if(b[i+1][j-1]=='*') a[i][j]++;
			if(b[i-1][j+1]=='*') a[i][j]++;
			if(b[i][j+1]=='*') a[i][j]++;
			if(b[i][j-1]=='*') a[i][j]++;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(b[i][j]=='?') {
				p=a[i][j];
				cout<<p;
			}
			else cout<<b[i][j];	
		}
		cout<<endl;
	}
}



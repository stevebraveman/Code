#include<iostream>
using namespace std;
int max(int a,int b) {
	return a>b?a:b;
}
int min(int a,int b) {
	return a<b?a:b;
}
int x,y,a[1002][1002]={0},m[1002][1002],sq=0;
int main() {
	cin>>x>>y;
	for(int i=1; i<=y; i++) {
		int p,q;
		cin>>p>>q;
		a[p][q]=1;
	}
	for(int i=1; i<=x; i++) {
		for(int j=1; j<=x; j++) {
			if(a[i][j]==0) m[i][j]=min(min(m[i-1][j],m[i][j-1]),m[i-1][j-1])+1;
			sq=max(sq,m[i][j]);
		}
	}
	cout<<sq;
}

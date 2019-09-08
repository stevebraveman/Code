#include<bits/stdc++.h>
using namespace std;
int a[10001]={1},n,tot,k;
void dfs(int,int,int);
int main(){
	cin>>n>>k;
	dfs(1,0,0);
	cout<<tot;
}
void dfs(int s,int t,int p){
	if(p==k){
		if(t==n) {
			tot++;
		}
		return;
	}
	for(int i=s;t+i*(k-p)<=n;i++){
		dfs(i,t+i,p+1);
	}
}

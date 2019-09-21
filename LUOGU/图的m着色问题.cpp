#include<iostream>
using namespace std;
int n,k,m,tot=0,a[105]={0};
bool G[105][105]={0};
void dfs(int);
bool pd(int);
int main(){
	cin>>n>>k>>m;
	for(int i=1;i<=k;i++){
		int p,q;
		cin>>p>>q;
		G[p][q]=1;
		G[q][p]=1;
	}
	dfs(1);
	cout<<tot;
	return 0;
}
bool pd(int i){
	for(int l=1;l<=i;l++){
		if(G[l][i]==1&&a[i]==a[l]){
			return 0;
		}
	}
	return 1;
}
void dfs(int i){
	if(i>n){
		tot++;
		return;
	}
	for(int j=1;j<=m;j++){
		a[i]=j;
		if(pd(i)==1){
			dfs(i+1);
		}
		else{
			a[i]=0;
		}
	}
}

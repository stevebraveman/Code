#include<iostream>
#include<iomanip>
using namespace std;
int num=0,n,m,a[25];
bool b[25]={0};
void dfs(int);
int pr();
int main(){
	cin>>n>>m;
	dfs(1);
}
void dfs(int k){
	int i;
	if(k>m){
		pr();
		return;
	}
	for(int i=a[k-1]+1;i<=n;++i){
		if(!b[i]){
			a[k]=i;
			b[i]=1;
			dfs(k+1);
			b[i]=0;
			a[k]=0;
		}
	}
}
int pr(){
	for(int i=1;i<=m;i++){
		cout<<setw(3)<<a[i];
	}
	cout<<endl;
}

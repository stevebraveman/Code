#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool pd[25]={0};
int a[25],tot=0,ans=0;
void dfs(int,int,long long);
int n,k;
int prime(int q){
	if(q==2) return 1;
	if(q==1) return 0;
	for(int i=2;i<=sqrt(q);i++){
		if(q%i==0) return 0; 
	}
	return 1;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout<<ans;
}
void dfs(int t,int p,long long tot){
	if(p==k){
		if(prime(tot)) ans++;
	}
	else 
	{
		for(int i=1;i<=n;i++){
			if(!pd[i]&&i>t){
				pd[i]=1;
				dfs(i,p+1,tot+a[i]);
				pd[i]=0;
			}
		}
	}
}

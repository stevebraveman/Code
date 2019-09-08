#include<bits/stdc++.h>
using namespace std;
int a[10001]={1},n,total;
long long tot=0;
int dfs(int,int);
int pr(int);
int main(){
	cin>>n;
	dfs(n,1);
	cout<<tot;
}
int dfs(int s,int t){
	int i;
	for(i=a[t-1];i<=s;i++){
		if(i<n){
			a[t]=i;
			s-=i;
			if(s==0) pr(t);
			else dfs(s,t+1);
			s+=i;
		}
	}
}
int pr(int t){
	tot++;
	cout<<n<<"=";
	for(int i=1;i<=t-1;i++){
		cout<<a[i]<<"+";
	}
	cout<<a[t]<<endl;
}

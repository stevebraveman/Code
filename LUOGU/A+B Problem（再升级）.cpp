#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,tot=0,a[1005];
bool prime(int);
void dfs(int,int);
int main(){
	cin>>n;
	a[0]=2;
	dfs(n,1);
	cout<<tot;
}
bool prime(int p){
	for(int j=2;j<=sqrt(p);j++){
		if(p%j==0) return 0;
	}
	return 1;
}
void dfs(int h,int t){
	for(int i=a[t-1];i<=h;i++){
		if((i<n)&&(prime(i)==1)){
			a[t]=i;
			h-=i;
			if(a==0) tot++;
			else dfs(h,t+1);
			h+=i;
		}
	}
}

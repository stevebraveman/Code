//[SDOI2008]ргул╤с.cpp
#include<iostream>
#include<cstring>
#define N 40000
int phi[N+2],prime[N+2],tot,ans;
bool mark[N+10];
using namespace std;
void Euler(){
	phi[1]=1;
	for(int i=2;i<=N;i++){
		if(!mark[i]){
			prime[++tot]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=tot;j++){
			if(i*prime[j]>N) break;
			mark[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
int main(){
	int n;
	long long p=0;
	cin>>n;
	Euler();
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++){
		p+=phi[i-1];
	}
	cout<<p*2+1;
}

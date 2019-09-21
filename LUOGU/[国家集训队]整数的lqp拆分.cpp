#include<iostream>
#define MOD 1000000007
using namespace std;
long long f[1000005];
int main(){
	int n;
	cin>>n;
	f[0]=0;
	f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=(f[i-1]*2+f[i-2])%MOD;
	}
	cout<<f[n]<<endl;
}

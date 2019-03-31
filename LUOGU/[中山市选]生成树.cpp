#include<iostream>
#define MOD 2007
using namespace std;
int main(){
	int t;
	int n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int sum=4*n;
		int k=1;
		for(int j=1;j<=n-1;j++){
			k*=5;
			k%=MOD;
		}
		cout<<k*sum%MOD<<endl;
	}
}

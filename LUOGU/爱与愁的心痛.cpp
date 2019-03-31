#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mina=100000;
	for(int i=1;i<=n-m;i++){
		int tot=0;
		for(int j=i;j<=i+m-1;j++){
			tot+=a[j];
		}
		if(mina>tot) mina=tot;
	}
	cout<<mina;
	return 0;
}

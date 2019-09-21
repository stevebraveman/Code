#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	short int a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		cout<<a[i]<<endl;
	}
}

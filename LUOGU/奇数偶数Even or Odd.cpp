#include<iostream>
using namespace std;
int main(){
	long long a;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a%2==0) cout<<"even"<<endl;
		else cout<<"odd"<<endl;
	}
	return 0;
}

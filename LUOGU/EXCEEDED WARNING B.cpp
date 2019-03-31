#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n<=8){
		cout<<"0";
		return 0;
	}
	if(n==9){
		cout<<8;
		return 0;
	}
	if(n>=10){
		cout<<"72";
		for(int i=1;i<=n-10;i++){
			cout<<"0";
		}
	}
}

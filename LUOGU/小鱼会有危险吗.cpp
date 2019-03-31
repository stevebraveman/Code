#include<iostream>
using namespace std;
int main(){
	int s,x;
	cin>>s>>x;
	if(x>s){
		cout<<"y";
		return 0;
	}
	if(2*x>7) cout<<"y";
	if(2*x<=7) cout<<"n";
}

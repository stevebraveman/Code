#include<iostream>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		if(a==0) break;
		if(a%2==0){
			cout<<"Alice\n";
		}
		if(a%2!=0){
			cout<<"Bob\n";
		}
	}
	return 0;
}

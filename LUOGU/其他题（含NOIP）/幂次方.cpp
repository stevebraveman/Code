#include<iostream>
#include<cmath>
using namespace std;
void fj(int n){
	if(n==0) return;
	if(n==1){
		cout<<"2(0)";
		return;
	}
	if(n==2){
		cout<<"2";
		return;
	}
	if(n==3){
		cout<<"2+2(0)";
		return;
	}
	if(n==4){
		cout<<"2(2)";
		return;
	}
	bool fst=1;
	int x=log2(n);
	cout<<"2(";
	fj(x);
	cout<<")";
	if(n==pow(2,x)){
		return;
	}
	cout<<"+";
	fj(n-pow(2,x));
	return;
}
int main(){
	int n;
	cin>>n;
	fj(n);
	return 0;
}

#include<iostream>
using namespace std;
int Fabi(int n);
int main(){
	int n,i=2;
	cin>>n;
	n=Fabi(n);
	cout<<n<<'=';
	while(n!=1){
		while(n%i==0){
			cout<<i;
			n/=i;
			if(n!=1) cout<<'*';
		}
		i++;
	}
}
int Fabi(int n){
	int F0=1,F1=1,F2=0;
	if(n==1) return 1;
	if(n==2) return 1;
	for(int i=3;i<=n;i++){
		F2=F1+F0;
		F0=F1;
		F1=F2;
	}
	return F2;
}

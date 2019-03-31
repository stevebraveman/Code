#include<iostream>
#include<cmath>
using namespace std;
bool p(int a){
	int temp=0;
	if(a==1) return false;
	if(a==2) return true;
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0) {
			temp++;	
		}
	}
	if(temp!=0) return false;
	if(temp==0) return true;
}
int main(){
	int n,k,rp=0;
	cin>>n>>k;
	for(int i=2;i<=n-k;i++){
		if(p(i)==1&&p(i+k)==1){
			cout<<i<<" "<<i+k<<endl;
			rp++;
		}
	}
	if(rp==0) cout<<"empty";
	return 0;
}

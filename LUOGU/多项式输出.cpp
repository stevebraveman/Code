#include<iostream>
using namespace std;
int main(){
	int n,a[104];
	cin>>n;
	for(int i=n;i>=0;i--){
		cin>>a[i];
	}
	for(int i=n;i>=0;i--){
		if(a[i]!=0) {
		if(i!=1) {
		if((i==0)&&(a[i]>0)) cout<<"+"<<a[i];
		if((i==0)&&(a[i]<0)) cout<<a[i];
		if((i==0)&&(a[i]==0)) return 0;
		if((i==n)&&(a[i]>0)){
			if(a[i]==1) cout<<"x"<<"^"<<n;
			else cout<<a[n]<<"x"<<"^"<<n;
		}
		if((i==n)&&(a[n]<0)){
			if(a[i]==-1) cout<<"-"<<"x"<<"^"<<n;
			else cout<<a[n]<<"x"<<"^"<<n;
		}
		if((a[i]>0)&&(i!=n)&&(i!=0)){
			if((a[i]>0)&&(a[i]==1)) cout<<"+"<<"x"<<"^"<<i;
			else cout<<"+"<<a[i]<<"x"<<"^"<<i;
		} 
		if((a[i]<0)&&(i!=n)&&(i!=0)) {
			if((a[i]<0)&&(a[i]==-1)) cout<<"-"<<"x"<<"^"<<i;
			else cout<<a[i]<<"x"<<"^"<<i;
		}
		}
		else {
			if(a[i]>0){
			if(a[i]==1) cout<<"+"<<"x";
			else cout<<"+"<<a[i]<<"x";
			}
			if(a[i]<0){
				if(a[i]==-1) cout<<"-"<<"x";
				else cout<<a[i]<<"x";
			}
		}
		}
		if(a[i]==0) continue;
		
	}
}

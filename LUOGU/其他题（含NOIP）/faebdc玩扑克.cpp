#include<iostream>
using namespace std;
int a[2000005]={0},n;
int main(){
	cin>>n;
	a[1]=n;
	int k=1;
	for(int i=2;i<=2*n;i+=2){
		a[i]=n-i/2;
		a[i+1]=a[k];
		k++;
	}
	int p;
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			p=i;
		}
	}
	for(int i=p+n-1;i>=p;--i){
		cout<<a[i]<<" ";
	}
}

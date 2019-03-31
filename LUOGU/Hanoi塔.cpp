#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[10001]={0},n,j,tot=0;
	cin>>n;
	a[1]=1;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=10001;k++){
			a[k]*=2;
		}
		for(j=1;j<=10001;j++){
			if(a[j]>=10){
				a[j+1]+=a[j]/10;
				a[j]%=10;
			}
		}
	}
	for(int i=1;i<=10001;i++){
		if(a[i]!=0) tot++;
	}
	for(int i=tot;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

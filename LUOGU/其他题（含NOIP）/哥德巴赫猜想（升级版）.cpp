#include<iostream>
#include<cmath>
using namespace std;
bool p(int f){
	int tot=0;
	if(f==0) return 0;
	if(f==1) return 0; 
	for(int i=2;i<=sqrt(f);i++){
		if(f%i==0) tot=1;
	}
	if(tot==0) return 1;
	else return 0;
}
int main(){
	int n,q=0;
	cin>>n;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n-i;j++){
			if(p(i)==1&&p(j)==1&&p(n-i-j)==1){
				cout<<i<<" "<<j<<" "<<n-i-j;
				q++;
				break;
			}
		}
		if(q!=0) break;
	}
}

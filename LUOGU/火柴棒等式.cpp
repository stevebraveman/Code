#include<iostream>
using namespace std;
int sum(int i){
	int ans=0;
	int a[10]={6,2,5,5,4,5,6,3,7,6};
	while(i/10!=0){
		ans+=a[i%10];
		i/=10;
	}
	ans+=a[i];
	return ans;
}
int main(){
	int n,a,b,c,tot=0;
	cin>>n;
	for(a=0;a<=1111;a++){
		for(b=0;b<=1111;b++){
			c=a+b;
			if(sum(a)+sum(b)+sum(c)==n-4){
				tot++;
			}
		}
	}
	cout<<tot;
	return 0;
}

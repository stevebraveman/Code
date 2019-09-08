#include<iostream>
using namespace std;
int main(){
	long long a[101]={0},b[101]={0},i,j,x,y,z;
	cin>>x>>y>>z;
	for(i=1;i<=x;i++){
		a[i]=1;
		b[i]=0;
	}
	for(i=x+1;i<=z+1;i++){
		b[i]=y*a[i-x];
		a[i]=a[i-1]+b[i-2];
	}
	cout<<a[z+1]<<endl;
	return 0;
}

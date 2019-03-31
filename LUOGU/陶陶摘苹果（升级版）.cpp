#include<iostream>
using namespace std;
int main(){
	int n,s,a,b,tot=0,p,u[5001]={0};
	cin>>n>>s>>a>>b;
	int x[n+2],y[n+2],w;
	w=a+b;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(x[i]<=w) u[i]=1;
	}
	int minx;
	while(s>=0){
		minx=100;
		for(int i=1;i<=n;i++){
			if(u[i]==1){
				if(y[i]<minx){
					minx=y[i];
					p=i;
				}
			}
		}
		u[p]=0;
		tot++;
		s=s-minx;
	}
	cout<<tot-1;
	return 0;
}

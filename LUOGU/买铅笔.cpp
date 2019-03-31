#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	int P,a,b,c,d,e,f,g,h,i,j,k,l;
	cin>>P;
	cin>>a>>b;
	cin>>c>>d;
	cin>>e>>f;
	g=ceil(P/float(a));
	h=ceil(P/float(c));
	i=ceil(P/float(e));
	j=g*b;
	k=h*d;
	l=i*f;
	if((j>k)&&(l>k)){
		printf("%1d",k);
	}
	if((l>j)&(k>j)){
		printf("%1d",j);
	}
	if((k>l)&&(j>l)){
		printf("%1d",l);
	}
	return 0;
}
	

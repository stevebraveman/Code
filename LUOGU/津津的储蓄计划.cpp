#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a1,a2,a=0,b=0,c,d,e;
	for(int i=1;i<=7;i++){
		cin>>a1>>a2;
		e=b;
		c=a1+a2;
		b=a;
		a=c;
		if(e>b)
			b=e;
		if((a>b)&&(a>8))
		d=i;
	}
	cout<<d<<endl;
	return 0;
}

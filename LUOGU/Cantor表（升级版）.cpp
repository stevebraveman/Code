#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	scanf("%d/%d",&a,&b);
	scanf("%d/%d",&c,&d);
	e=a*c;
	f=b*d;
	int k=__gcd(e,f);
	e/=k;
	f/=k;
	cout<<f<<" "<<e;
	return 0;
}

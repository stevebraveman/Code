#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char ch1[7],ch2[7];
	long long a,b,i=0,j=0,c=1,d=1;
	gets(ch1);
	gets(ch2);
	for(i;i<=strlen(ch1);i++){
		a=int(ch1[i])-64;
		c=c*a;
	}
	for(j;j<=strlen(ch2);j++){
		b=int(ch2[j])-64;
		d=d*b;
	}
	if((c%47)==(d%47)) cout<<"GO";
	else cout<<"STAY";
}

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a1[500001],b1[500001];
int a[500001],b[500001],c[500001],x,lenc,la,lb,i;
int main(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	gets(a1);
	gets(b1);
	la=strlen(a1);
	lb=strlen(b1);
	for(i=0;i<=la-1;i++){
		a[la-i]=a1[i]-'0';
	}
	for(i=0;i<=lb-1;i++){
		b[lb-i]=b1[i]-'0';
	}
	lenc=1;
	x=0;
	while(lenc<=la||lenc<=lb){
		c[lenc]=a[lenc]+b[lenc]+x;
		x=c[lenc]/10;
		c[lenc]%=10;
		lenc++;
	}
	c[lenc]=x;
	if(c[lenc]==0) lenc--;
	for(i=lenc;i>=1;i--) cout<<int(c[i]);
	return 0;
}

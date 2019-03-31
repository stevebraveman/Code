#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int p(int a){
	int n=0;
	if(a==1) return 0;
	if(a==0) return 0;
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0) n++;
	}
	if(n==0) return 1;
	else return 0;
}
int main(){
	char a[101],x;
	int n,maxa=0,mina=100,tot;
	gets(a);
	for(int i=0;i<strlen(a);i++){
		tot=0;
		x=a[i];
		for(int j=0;j<=strlen(a)-1;j++){
			if(x==a[j]){
				tot++;
			}
		}
		if(maxa<tot) maxa=tot;
		if(mina>tot) mina=tot;
		
	}
	n=maxa-mina;
	if(p(n)==1) cout<<"Lucky Word"<<endl<<n;
	else cout<<"No Answer"<<endl<<"0";
	return 0;
}

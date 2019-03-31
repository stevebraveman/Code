//½øÖÆ×ª»».cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int tran(char p){
	int h;
	if(p>='A') return p-'A'+10;
	else return p-'0';
}
int pow(int a,int b){
	int k=1;
	for(int i=1;i<=b;i++){
		k*=a;
	}
	return k;
}
int main(){
	int n,m,a[103],b[103];
	char x[102],y[102];
	cin>>n;
	int g=0;
	scanf("%s",x);
	cin>>m;
	int l=strlen(x);
	int k=l-1;
	for(int i=0;i<l;i++){
		a[i+1]=tran(x[i]);
	}
	for(int i=1;i<=l;i++){
		g+=a[i+1]*pow(n,k);
		k--;
	}
	cout<<g;
}

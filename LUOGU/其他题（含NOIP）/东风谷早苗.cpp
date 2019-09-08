#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int T,len,b,a,x=0,y=0;
	char c[5001];
	scanf("%s",c);
	cin>>T;
	len=strlen(c);
	a=T/len;
	b=T%len;
	for(int i=0;i<len;i++){
		if(c[i]=='E') x++;
		if(c[i]=='S') y--;
		if(c[i]=='W') x--;
		if(c[i]=='N') y++;
	}
	x*=a;
	y*=a;
	for(int i=0;i<b;i++){
		if(c[i]=='E') x++;
		if(c[i]=='S') y--;
		if(c[i]=='W') x--;
		if(c[i]=='N') y++;
	}
	cout<<x<<" "<<y;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char s[1000001];
	int n,x,y=0,ht;
	cin>>s;
	int l=strlen(s);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		y=y+x;
		if(s[y]=='>'){
			while(s[y]=='>'){
				y++;
			}
		}
		if(s[y]=='*'){
			while(s[y]=='*')
			ht++;
			y=y-ht;
		}
	}
	cout<<y<<" "<<l-y;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char ch1[301],ch2[301];
	float k;
	int l,tot=0;
	cin>>k;
	scanf("%s%s",ch1,ch2);
	l=strlen(ch1);
	for(int i=0;i<=l;i++){
		if(ch1[i]==ch2[i]) tot++;
	}
	if((tot/float(l))>=k) cout<<"yes";
	else cout<<"no";
}

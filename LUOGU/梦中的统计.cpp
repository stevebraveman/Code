#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	long long n,m;
	int b[12]={0};
	char a[11];
	cin>>n>>m;
	for(int i=n;i<=m;i++){
		sprintf(a,"%d",i);
		for(int j=0;j<strlen(a);j++){
			b[a[j]-'0']++;
		}
	}
	for(int i=0;i<=9;i++){
		cout<<b[i]<<" ";
	}
}

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int b,n;
	scanf("%d%d",&n,&b);
	char num[n];
	for(int i=0;i<n;i++){
		num[i]='0';
	}
	for(int i=1;i<=pow(b,n);i++){
		for(int j=1;j<n;j++){
			if(num[n-1]=='0'+n) num[j-1]++,num[j]='0';
		}
		printf("%s\n",num);
		num[n-1]++;
	}
}

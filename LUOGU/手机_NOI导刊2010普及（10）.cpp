#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	int tot=0,a[27]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4,1};
	char c[201];
	gets(c);
	for(int i=0;i<strlen(c);i++){
		if(c[i]>='a'&&c[i]<='z'){
			tot+=a[c[i]-'a'];
		}
		if(c[i]==' '){
			tot+=a[26];
		}
	}
	cout<<tot;
}

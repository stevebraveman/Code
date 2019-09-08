#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char str[81],ch[81];
	gets(str);
	for(int i=0;i<strlen(str);i++){
		if(((str[i]>='a')&&(str[i]<='y'))||((str[i]>='A')&&(str[i]<='Y'))){
			ch[i]=str[i]+1;
		}
		if((str[i]=='Z')||(str[i]=='z')){
			ch[i]=str[i]-25;
		}
		if((!(((str[i]>='a')&&(str[i]<='z'))||((str[i]>='A')&&(str[i]<='Z'))))){
			ch[i]=str[i];
		}
	}
	for(int i=0;i<strlen(str);i++) cout<<ch[i];
	return 0;
}

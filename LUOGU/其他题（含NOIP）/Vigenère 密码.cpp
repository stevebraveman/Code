#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int tr(char a,char b){
	char c;
	int x;
	if(a>='A'&&a<='Z') a=a+32;
	if(b>='A'&&b<='Z'){
		x=b+32-a;
		if(x<0) x+=26; 
		c=x+'A';
		if(x<0) x+=26;
		return c;
	}
	if(b>='a'&&b<='z'){
		x=b-a;
		if(x<0) x+=26;
		c=x+'a';
		return c;
	}
}
int main(){
	char my[101],mw[1001],ming[1001];
	int j=0,la,lb;
	scanf("%s",my);
	scanf("%s",mw);
	la=strlen(my)-1;
	lb=strlen(mw)-1;
	for(int i=0;i<=lb;i++){
		if(j==la+1) j=0;
		ming[i]=tr(my[j],mw[i]);
		j++;
	}
	for(int i=0;i<=lb;i++) cout<<ming[i];
}

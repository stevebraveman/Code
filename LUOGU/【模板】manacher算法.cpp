#include<cstdio>
#include<cstring>
#include<iostream>
#define LENGTH 11000005
using namespace std;
char str[LENGTH],newstr[2*LENGTH];
int p[2*LENGTH];
int min(int a,int b) {
	return a<b?a:b;
}
void add(char str[],char newstr[],int len) {
	int i;
	newstr[0]='.';
	for(i=0; i<len; i++)  {
		newstr[2*i+1]=str[i];
		newstr[2*i+2]='.';
	}
	newstr[2*i+1]='\0';
}
void manacher(char newstr[],int len) {
	int id,ans=1,maxid=0;
	for(int i=0; i<len; i++) {
		if(maxid>i) p[i]=min(p[2*id-i],maxid-i);
		else p[i]=1;
		while((newstr[i+p[i]]==newstr[i-p[i]])&&(i-p[i])>=0&&(i+p[i])<len) p[i]++;
		if(p[i]+i>maxid) {maxid=p[i]+i;id=i;}
		if(ans<p[i]) ans=p[i];
	}
	cout<<ans-1<<endl;
}
int main() {
	int i,l;
	cin>>str;
	l=strlen(str);
	add(str,newstr,l);
	manacher(newstr,l*2+1);
	return 0;
}

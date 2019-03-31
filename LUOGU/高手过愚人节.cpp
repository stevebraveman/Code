#include<stdio.h>  
#include<string.h>  
#include<iostream>  
using namespace std;  
#define LENGTH 10000000  
char str[LENGTH],newstr[2*LENGTH];  
int p[2*LENGTH];
int min(int a,int b){  
	return a<b?a:b;  
}
void Change(char* str,char* newstr,int len){  
	int i;  
	newstr[0]='.';  
	for(i=0;i<len;i++)  {  
		newstr[2*i+1]=str[i];  
		newstr[2*i+2]='.';  
	}
	newstr[2*i+1]='\0';  
}
void Manacher(char* newstr,int len){
	int id,ans=1,maxid=0;  
	for(int i=0;i<len;i++){  
		if(maxid>i){  
			p[i]=min(p[2*id-i],maxid-i);  
		}
		else{  
			p[i]=1;  
		}  
		while((newstr[i+p[i]]==newstr[i-p[i]])&&(i-p[i])>=0&&(i+p[i])<len)    
			p[i]++;    
		if(p[i]+i>maxid){    
			maxid=p[i]+i;   
			id=i;
		}   
		if(ans<p[i]) ans=p[i];  
	}
	cout<<ans-1<<endl;  
}
int main(){  
	int n,i,l;  
	cin>>n;  
	for(int i=1;i<=n;i++){
		cin>>str;  
		l=strlen(str);  
		Change(str,newstr,l);  
		Manacher(newstr,l*2+1);  
	}
	return 0;
}

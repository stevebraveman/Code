#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[101],b[101],c[101],d[101];
int la,lb,lc,ld,tot[50],mat=0,mit=400,k;
int main(){
	gets(a);
	gets(b);
	gets(c);
	gets(d);
	la=strlen(a);
	lb=strlen(b);
	lc=strlen(c);
	ld=strlen(d);
	for(int i=0;i<la;i++){
		if(a[i]>='A'&&a[i]<='Z') tot[a[i]-'A'+1]++;
	}
	for(int i=0;i<lb;i++){
		if(b[i]>='A'&&a[i]<='Z') tot[b[i]-'A'+1]++;
	}
	for(int i=0;i<lc;i++){
		if(c[i]>='A'&&a[i]<='Z') tot[c[i]-'A'+1]++;
	}
	for(int i=0;i<ld;i++){
		if(d[i]>='A'&&a[i]<='Z') tot[d[i]-'A'+1]++; 
	}
	for(int i=1;i<=26;i++){
		if(tot[i]>mat) mat=tot[i];
		if(tot[i]<mit) mit=tot[i];
	}
	while(mat!=0){
		for(int j=1;j<=25;j++){
			if(tot[j]>=mat){
				cout<<'*';
			}
			else{
				cout<<" ";
			}
			cout<<" ";
		}
		if(tot[26]>=mat){
			cout<<'*';
		}
		else{
			cout<<" ";
		}
		cout<<endl;
		mat--;
	}
	for(char i='A';i<='Y';i++){
		cout<<i<<" ";
	}
	cout<<'Z';
	return 0;
}

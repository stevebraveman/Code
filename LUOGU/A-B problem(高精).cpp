#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	int a[10001],b[10001],c[10001],la,lb,lc,i;
	char n[10001],n1[10001],n2[10001];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>n1>>n2;
	if(strlen(n1)<strlen(n2)||(strlen(n1)==strlen(n2)&&strcmp(n1,n2)<0)){
		strcpy(n,n1);
		strcpy(n1,n2);
		strcpy(n2,n);
		cout<<"-";
	}
	la=strlen(n1);
	lb=strlen(n2);
	for(i=0;i<=la-1;i++){
		a[la-i]=int(n1[i]-'0');
	}
	for(i=0;i<=lb-1;i++){
		b[lb-i]=int(n2[i]-'0');
	}
	i=1;
	while(i<=la||i<=lb){
		if(a[i]<b[i]){
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
		i++;
	}
	lc=i;
	while((c[lc]==0)&&(lc>1)) lc--;
	for(i=lc;i>=1;i--) cout<<c[i];
	cout<<endl;
	return 0;
}

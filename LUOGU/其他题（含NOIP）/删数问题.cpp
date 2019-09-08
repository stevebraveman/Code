#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char a[260],b[260],k[260];
	int p;
	scanf("%s",a);
	cin>>p;
	while(p>=1){
		for(int i=0;i<strlen(a);i++){
			strcpy(k,a);
			for(int j=i;j<strlen(a);j++){
				k[j]=k[j+1];
			}
			int j=0;
			int d;
			sscanf(k,"%d",&d);
			if(d!=0){
				while(k[j]=='0'){
				for(int t=j;t<strlen(a)-1;t++){
					k[t]=k[t+1];
				}
				j++;
			}
			}
			if(i==0) {
				strcpy(b,k);
				continue;
			}
			if(strlen(b)>strlen(k)) {
				strcpy(b,k);
				continue;
			}
			if(strcmp(b,k)>0){
				strcpy(b,k);
			}
		}
		strcpy(a,b);
		p--;
	}
	cout<<a;
}

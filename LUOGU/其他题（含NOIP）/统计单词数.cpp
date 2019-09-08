#include<iostream>
#include<cstring>
#include<cstdio>
const int MAXN=1000006;
using namespace std;
bool first=1;
int n;
int main(){
	char word[11],c[MAXN];
	gets(word);
	gets(c);
	int lw=strlen(word);
	int lc=strlen(c);
	for(int i=0;i<lw;i++){
		if(word[i]>='a'){
			word[i]-=32;
		}
	}
	for(int i=0;i<lc;i++){
		if(c[i]>='a'){
			c[i]-=32;
		}
	}
	int tot=0;
	int ans=0;
	int q;
	for(int i=0;i<lc;i++){
		if(word[0]==c[i]&&c[i-1]==' '){
			tot=0;
			for(int j=0;j<lw;j++){
				if(word[j]==c[i+j]){
					tot++;
				}
			}
			if(tot==lw){
				ans++;
				if(first){
					first=0;
					q=i;
				}
			}
		}
	}
	if(ans==0){
		cout<<-1;
	}
	else{
		cout<<ans<<" "<<q;
	}
	return 0;
}

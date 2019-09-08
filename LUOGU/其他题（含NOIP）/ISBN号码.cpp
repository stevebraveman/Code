#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	char s[15],a;
	int k=1,tot=0;
	gets(s);
	for(int i=0;i<12;i++){
		if(s[i]>='0'&&s[i]<='9') {
			tot+=(s[i]-'0')*k;
			k++;
		}
	}
	tot%=11;
	a=tot+'0';
	if(a>'9'){
		a='X';
	}
	if(tot==10) {
		if(s[12]=='X'){
		cout<<"Right";
		return 0;
		}
		else{
			s[12]=a;
			for(int i=0;i<13;i++){
				cout<<s[i];
			}
			return 0;
		}
	}
	else{
		if(s[12]==a){
			cout<<"Right";
			return 0;
		}
		else{
			s[12]=a;
			for(int i=0;i<13;i++){
				cout<<s[i];
			}
			return 0;
		}
	}
}

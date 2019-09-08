#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	char a[1000];
	scanf("%s",a);
	int l=strlen(a);
	int k=0;
	bool flag=0;
	for(int i=0;i<l;i++){
		if(a[i]=='(') k++;
		if(a[i]==')') k--;
		if(k<0){
			flag=1;
		}
	}
	if(k!=0||flag==1){
		cout<<"NO"<<endl;
		return 0;
	}
	else {
		cout<<"YES"<<endl;
		return 0;
	}
	return 0;
}

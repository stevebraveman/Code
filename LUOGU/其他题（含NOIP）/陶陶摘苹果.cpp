#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int a[10],b,tot=0;
	for(int i=1;i<=10;i++){
	cin>>a[i];
	}
	cin>>b;
	for(int i=1;i<=10;i++){
		if(a[i]<=(b+30)) tot++;
	}
	cout<<tot;
	return 0; 
}

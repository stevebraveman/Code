#include<iostream>
using namespace std;
int main(){
	int a;
	bool b[45]={0};
	for(int i=1;i<=10;i++){
		cin>>a;
		b[a%42]=1;
	}
	int tot=0;
	for(int i=0;i<=42;i++){
		if(b[i]==1) tot++;
	}
	cout<<tot;
	return 0;
}

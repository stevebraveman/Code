#include<iostream>
using namespace std;
long long l,m,c,b,tot;
bool a[10001];
int main(){	
	cin>>l>>m;
	for(int i=1;i<=m;i++){
		cin>>c>>b;
		for(int j=c;j<=b;j++) a[j]=1;
	}
	for(int i=0;i<=l;i++) if(a[i]==0) tot++;
	cout<<tot<<endl;
}


#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
struct note{
	bool tow;
	char nam[11];
};
int main(){
	long n,m,p,q,y;
	bool x;
	cin>>n>>m;
	note a[n+2];
	for(int i=0;i<n;i++){
		cin>>a[i].tow>>a[i].nam;
	}
	q=0;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		if(a[q].tow xor x){
		q=(q+y)%n;
		}
		else{
			q=((q-y)%n+n)%n;
		}
	}
	cout<<a[q].nam<<endl;
}


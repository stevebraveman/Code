//ÊýÁÐ·Ö¶ÎSection I.cpp
#include<iostream>
using namespace std;
int n,m,a[100005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int tot=0;
	int b=0;
	for(int i=1;i<=n;i++){
		b+=a[i];
		if(b==m){
			tot++;
			b=0;
			continue;
		}
		if(b>m){
			b=0;
			b+=a[i];
			tot++;
		}
		if(i==n&&b<m){
			tot++;
		}
	}
	cout<<tot;
}

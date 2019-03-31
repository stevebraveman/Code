#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int p[15]={0,10,100,1000,10000,100000,1000000,10000000,10000000}; 
int main(){
	int n,q,l,y;
	cin>>n>>q;
	int a[n+2],b[q+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++){
		cin>>l>>y;
		bool fg=false;
		for(int j=1;j<=n;j++){
			if(a[j]%p[l]==y){
				fg=true;
				b[i]=a[j];
				break;
			}
		}
		if(!fg) b[i]=-1;
	}
	for(int i=1;i<=q;i++){
		cout<<b[i]<<endl;
	}
	return 0;
}

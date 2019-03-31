#include<iostream>
using namespace std;
int main(){
	int n,a,x,b[30001]={0},v=0,maxx;
	cin>>n>>a;
	for(int i=1;i<=n;i++){
		cin>>x;
		b[x]++;
	}
	int j=0;
	while(1){
		j++;
		if(b[j]>0){
			maxx=j;
			v++;
		}
		if(v==a) break;
		if(j==30000) break;
	}
	if(v!=a){
		cout<<"NO RESULT";
		return 0;
	}
	cout<<maxx;
	return 0;
}

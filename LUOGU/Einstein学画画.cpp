#include<iostream>
#include<cstdio>
using namespace std;
int p[1005]={0};
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		p[x]++;
		p[y]++;
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		if(p[i]&1==1) tot++; 
	}
	if(tot==0){
		cout<<"1"<<endl;
		return 0;
	}
	else{
		if(tot&1){
			cout<<tot/2+1<<endl;
		}
		else cout<<tot/2<<endl;
	}
	return 0;
}

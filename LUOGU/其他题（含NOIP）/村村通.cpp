#include<iostream>
#include<cstring>
using namespace std;
int n,m,fa[20005];
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void un(int x,int y){
	x=find(x);
	y=find(y);
	fa[x]=y;
}
void init(){
	memset(fa,0,sizeof(fa));
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int main(){
	while(cin>>n){
		if(n==0) break;
		cin>>m;
		init();
		if(m==0){
			cout<<n-1<<endl;
			continue;
		}
		int x,y;
		int p=0;
		int t=1;
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			if(find(x)==find(y)){
				t=1;
			}
			else{
				un(x,y);
				p++;
			}
		}
		cout<<n-1-p<<endl;
	}
	return 0;
}

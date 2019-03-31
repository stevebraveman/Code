#include<iostream>
#include<cstdio>
using namespace std;
int fa[1000003];
int find(int a){
	if(fa[a]==a) return a;
	else return fa[a]=find(fa[a]);
}
void un(int a,int b){
	a=find(a);
	b=find(b);
	fa[b]=a;
}
int main(){
	int n,a;
	cin>>n;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		un(i,a);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i) ans++;
	}
	cout<<ans<<endl;
}

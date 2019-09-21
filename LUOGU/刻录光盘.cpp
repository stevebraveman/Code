#include<iostream>
#include<cstdio>
#define re register
using namespace std;
int fa[205],n,m,g[205][205]={0};
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void un(int a,int b){
	int aa=find(a);
	int bb=find(b);
	fa[aa]=bb;
}
int main(){
	cin>>n;
	for(re int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(re int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		while(a!=0){
			scanf("%d",&a);
			if(a!=0){
				g[i][a]=1;
			}
		}
	}
	for(re int i=1;i<=n;i++){
		for(re int j=1;j<=n;j++){
			if(g[i][j]==1) un(j,i);
		}
	}
	int ans=0;
	for(re int i=1;i<=n;i++){
		if(fa[i]==i) ans++;
	}
	printf("%d",ans);
}

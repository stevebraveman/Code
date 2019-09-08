#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Edge{
	int u,v,w;
} e[200002];
int fa[200002]={0};
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
int un(int x,int y){
	fa[x]=y;
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int main(){
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	int u=0;
	int p=n-k;
	int q=0;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x,y;
		x=find(e[i].u);
		y=find(e[i].v);
		if(x==y){
			goto exit;
		}
		else{
			un(x,y);
			q++;
			ans+=e[i].w;
		}
		if(q==p){
			break;
		}
		exit:
			u=0;
	}
	cout<<ans;
}

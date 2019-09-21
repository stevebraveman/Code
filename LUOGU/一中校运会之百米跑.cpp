#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
map<string,int> hs;
int fa[200005];
int find(int x) {
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return x;
}
void un(int r1,int r2) {
	fa[r2]=r1;
}
int main() {
	int n,m,x,y,z;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		fa[i]=i;
	}
	for(int i=1; i<=n; i++) {
		string a;
		cin>>a;
		hs[a]=i;
	}
	for(int i=1; i<=m; i++) {
		string a,b;
		cin>>a>>b;
		int r1=find(hs[a]);
		int r2=find(hs[b]);
		if(r1!=r2) un(r1,r2);
	}
	int k;
	cin>>k;
	for(int i=1; i<=k; i++) {
		string a,b;
		cin>>a>>b;
		if(find(hs[a])==find(hs[b])) printf("Yes.\n");
		else printf("No.\n");
	}
	return 0;
}

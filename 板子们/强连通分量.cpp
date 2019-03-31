#include <cstdio>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;
int n,m,idx=0,k=1,Bcnt=0;
int head[100];
int ins[100]= {0};
int dfn[100]= {0},low[100]= {0};
int Belong[100];
stack <int> s;
struct edge {
	int v,next;
} e[100];
int min(int a,int b) {
	return a<b?a:b;
}
void adde(int u,int v) {
	e[k].v=v;
	e[k].next=head[u];
	head[u]=k++;
}
void readdata() {
	int a,b;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&a,&b);
		adde(a,b);
	}
}
void tarjan(int u) {
	int v;
	dfn[u]=low[u]=++idx;
	s.push(u);
	ins[u]=1;
	for(int i=head[u]; i!=-1; i=e[i].next) { 
		v=e[i].v;
		if(!dfn[v]) {
			tarjan(v);
			low[u]=min(low[u],low[v]);
		} else if(ins[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]) {
		Bcnt++;
		do {
			v=s.top();
			s.pop();
			ins[v]=0;
			Belong[v]=Bcnt;
		} while(u != v);
	}
}
void work() {
	for(int i=1; i<=n; i++)if(!dfn[i])tarjan(i);
	printf("\n");
	for(int i = 1; i <= 6; i++)printf("%d %d\n",dfn[i],low[i]);
	printf("共有%d强连通分量，它们是:\n",Bcnt);
	for(int i=1; i<=Bcnt; i++) {
		printf("第%d个:",i);
		for(int j=1; j<=n; j++) {
			if(Belong[j]==i)printf("%d ",j);
		}
		printf("\n");
	}
}
int main() {
	readdata();
	work();
	return 0;
}

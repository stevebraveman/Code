
#include<iostream>

#include<cstring>
#include<cstdio>
using namespace std;
#define N 100
#define M 100
struct Edge {
	int v;
	int next;
};
Edge edge[M];//边的集合

int node[N];//顶点集合
int instack[N];//标记是否在stack中
int stack[N];
int Belong[N];//各顶点属于哪个强连通分量
int DFN[N];//节点u搜索的序号(时间戳)
int LOW[N];//u或u的子树能够追溯到的最早的栈中节点的序号(时间戳)
int n, m;//n：点的个数；m：边的条数
int cnt_edge;//边的计数器
int Index;//序号(时间戳)
int top;
int Bcnt;//有多少个强连通分量

void add_edge(int u, int v) { //邻接表存储
	edge[cnt_edge].next = node[u];
	edge[cnt_edge].v = v;
	node[u] = cnt_edge++;
}
void tarjan(int u) {
	int i,j;
	int v;
	DFN[u]=LOW[u]=++Index;
	instack[u]=true;
	stack[++top]=u;
	for (i = node[u]; i != -1; i = edge[i].next) {
		v=edge[i].v;
		if (!DFN[v]) { //如果点v没被访问
			tarjan(v);
			if (LOW[v]<LOW[u])
				LOW[u]=LOW[v];
		} else //如果点v已经被访问过
			if (instack[v] && DFN[v]<LOW[u])
				LOW[u]=DFN[v];
	}
	if (DFN[u]==LOW[u]) {
		Bcnt++;
		do {
			j=stack[top--];
			instack[j]=false;
			Belong[j]=Bcnt;
		} while (j!=u);
	}
}
void solve() {
	int i;
	top=Bcnt=Index=0;
	memset(DFN,0,sizeof(DFN));
	memset(LOW,0,sizeof(LOW));
	for (i=1; i<=n; i++)
		if (!DFN[i])
			tarjan(i);
}
int main() {
//	freopen("in.txt","r",stdin);
	int i,j,k;
	cnt_edge=0;
	memset(node,-1,sizeof(node));
	scanf("%d%d",&n,&m);
	for(i=1; i<=m; i++) {
		scanf("%d%d",&j,&k);
		add_edge(j,k);
	}
	solve();
	for(i=1; i<=n; i++)
		printf("%d ",Belong[i]);
}


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
Edge edge[M];//�ߵļ���

int node[N];//���㼯��
int instack[N];//����Ƿ���stack��
int stack[N];
int Belong[N];//�����������ĸ�ǿ��ͨ����
int DFN[N];//�ڵ�u���������(ʱ���)
int LOW[N];//u��u�������ܹ�׷�ݵ��������ջ�нڵ�����(ʱ���)
int n, m;//n����ĸ�����m���ߵ�����
int cnt_edge;//�ߵļ�����
int Index;//���(ʱ���)
int top;
int Bcnt;//�ж��ٸ�ǿ��ͨ����

void add_edge(int u, int v) { //�ڽӱ�洢
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
		if (!DFN[v]) { //�����vû������
			tarjan(v);
			if (LOW[v]<LOW[u])
				LOW[u]=LOW[v];
		} else //�����v�Ѿ������ʹ�
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

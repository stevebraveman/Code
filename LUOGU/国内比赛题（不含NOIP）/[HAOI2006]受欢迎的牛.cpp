#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define re register
#define MAXN 100005
int head[MAXN] , x[MAXN] , n , m , y[MAXN] , ecnt;
int dfn[MAXN] , low[MAXN] , size[MAXN] ,bel[MAXN] , mark[MAXN] , num , ans , tim;
bool vis[MAXN];
struct Edge {
	int v , nx;
}e[MAXN];
inline int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
struct stack {
	int head , a[MAXN * 4];
	void clear() {
		head = 0;
	}
	void push(int x) {
		head++;
		a[head] = x;
	}
	int top() {
		return a[head];
	}
	void pop() {
		head--;
	}
	bool empty() {
		if (head == 0) {
			return 1;
		}
		else return 0;
	}
	int size() {
		return head;
	}
}s;
inline void add(int from , int to) {
	e[++ecnt] = (Edge){to , head[from]};
	head[from] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	vis[u] = 1;
	s.push(u);
	for (re int i = head[u] ; i ; i = e[i].nx) {
		int v = e[i].v;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u] , low[v]);
		}
		else if(vis[u]) low[u] = min(low[u] , dfn[v]);
	}
	if (dfn[u] == low[u]) {
		int v;
		num++;
		do {
			v = s.top();
			s.pop();
			vis[v] = 0;
			bel[v] = num;
			size[num]++;
		} while(u != v);
	}
}
int main() {
	int tot = 0;
	scanf("%d%d" , &n , &m);
	for (re int i = 1 ; i <= m ; i++) {
		scanf("%d%d" , &x[i] , &y[i]);
		add(x[i] , y[i]);
	}
	for (re int i = 1 ; i <= n ; i++) {
		if(!dfn[i]) {
			tarjan(i);
		}
	}
	for (re int i = 1 ; i <= m ; i++) {
		if(bel[x[i]] != bel[y[i]]) {
			mark[bel[x[i]]] = 1;
		}
	}
	for (re int i = 1 ; i <= num ; i++) {
		if(!mark[i]) {
			ans = size[i];
			tot++;
		}
	}
	if(tot == 1) printf("%d\n" , ans);
	else printf("0\n");
	return 0;
}
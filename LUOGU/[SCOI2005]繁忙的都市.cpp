#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct edge{
	int u, v;
	int w;
} ;
edge e[200002];
int fa[200002];
bool cmp(edge a, edge b) {
	if (a.w<b.w) return 1;
	else return 0;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int find(int n) {
	if (fa[n] == 0)  return n;
	else return find(fa[n]);
}
bool un(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return 0;
	if (a<b)   fa[b] = a;
	else fa[a] = b;
	return 1;
}
int main() {
	int n, p;
	int sum, ct;
//	scanf("%d%d", &n, &p);
	cin >> n >> p;
	for (int i = 1; i <= p; i++) {
//		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e + 1, e + 1 + p, cmp);
	memset(fa, 0, sizeof(fa));
	sum = 0;
	ct = 1;
	int tot = 0;
	int maxa = 0;
	for (int i = 1; i <= p; i++) {
		if (un(e[i].u, e[i].v)) {
//			sum += e[i].w;
			tot++;
			maxa = max(maxa,e[i].w);
			ct++;
		}
		if (ct == n)  break;
	}
	printf("%d %d", tot,maxa);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
int t[MAXN][26], fa[MAXN], len[MAXN], tot = 1, last = 1, si[MAXN];
long long ans;
int head[MAXN], ecnt;
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void insert(char a) {
	int k = a - 'a';
	int p = last;
	int np = last = ++tot;
	si[np] = 1;
	len[np] = len[p] + 1;
	for (; p && !t[p][k]; p = fa[p]) t[p][k] = np;
	if (!p) fa[np] = 1;
	else {
		int q = t[p][k];
		if (len[p] + 1 == len[q]) fa[np] = q;
		else {
			int nq = ++tot;
			len[nq] = len[p] + 1;
			memcpy(t[nq], t[q], sizeof(t[q]));
			fa[nq] = fa[q];
			fa[q] = fa[np] = nq;
			for (; t[p][k] == q; p = fa[p]) t[p][k] = nq;
		}
	}
}
char s[MAXN];
void dfs(int u) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		dfs(to);
		si[u] += si[to];
	}
}
int l;
int main() {
	scanf("%s", s);
	l = strlen(s);
	for (int i = 0; s[i]; i++) {
		insert(s[i]);
	}
	for (int i = 2; i <= tot; i++) {
		add(fa[i], i, len[i] - len[fa[i]]);
	}
	dfs(1);
	for (int i = 1; i <= ecnt; i++) {
		ans += 1LL * e[i].w * si[e[i].v] * (l - si[e[i].v]);
	}
	printf("%lld\n", ans);
}
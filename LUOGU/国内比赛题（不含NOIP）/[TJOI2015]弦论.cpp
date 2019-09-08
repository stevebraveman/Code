#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 2000100
int len[MAXN], last = 1, tot = 1, e[MAXN][26], fa[MAXN], si[MAXN], c[MAXN], a[MAXN], sum[MAXN];
void insert(char a) {
	int k = a - 'a';
	int p = last;
	int np = last = ++tot;
	si[np] = 1;
	len[np] = len[p] + 1;
	for (; p && !e[p][k]; p = fa[p]) e[p][k] = np;
	if (!p) fa[np] = 1;
	else {
		int q = e[p][k];
		if (len[p] + 1 == len[q]) fa[np] = q;
		else {
			int nq = ++tot;
			len[nq] = len[p] + 1;
			memcpy(e[nq], e[q], sizeof(e[q]));
			fa[nq] = fa[q];
			fa[q] = fa[np] = nq;
			for (; e[p][k] == q; p = fa[p]) e[p][k] = nq;
		}
	}
}
void out(int u, int p) {
	if (p <= si[u]) return;
	p -= si[u];
	for (int i = 0; i < 26; i++) {
		int to = e[u][i];
		if (!to) continue;
		if (p > sum[to]) {
			p -= sum[to];
			continue;
		}
		putchar(i + 'a');
		out(to, p);
		return;
	}
}
void work(int fl, int k) {
	for (int i = 1; i <= tot; i++) c[len[i]]++;
	for (int i = 1; i <= tot; i++) c[i] += c[i - 1];
	for (int i = 1; i <= tot; i++) a[c[len[i]]--] = i;
	for (int i = tot; i >= 1; i--) {
		if (fl)	si[fa[a[i]]] += si[a[i]];
		else si[a[i]] = 1;
	}
	si[1] = 0;
	for (int i = tot; i >= 1; i--) {
		sum[a[i]] = si[a[i]];
		for (int j = 0; j < 26; j++) {
			if (e[a[i]][j]) sum[a[i]] += sum[e[a[i]][j]];
		}
	}
	if (sum[1] < k) puts("-1");
	else out(1, k);
}
char s[MAXN];
int t, k;
int main() {
	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		insert(s[i]);
	}
	scanf("%d%d", &t, &k);
	work(t, k);
	return 0;
}
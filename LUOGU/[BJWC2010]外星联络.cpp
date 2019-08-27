#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 5001000
int t[MAXN][2], tot, ed[MAXN], n;
char s[MAXN];
void insert(char *a, int l, int r) {
	int p = 0;
	for (int i = l; i <= r; i++) {
		int k = a[i] - '0';
		if (!t[p][k]) t[p][k] = ++tot;
		p = t[p][k];
		ed[p]++;
	}
}
void out(int u) {
	if (ed[u] > 1) printf("%d\n", ed[u]);
	if (t[u][0]) out(t[u][0]);
	if (t[u][1]) out(t[u][1]);
	return;
}
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		insert(s, i, n);
	}
	out(0);
	return 0;
}
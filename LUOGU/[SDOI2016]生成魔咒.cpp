#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXN 1000100
using std::map;
map <int, int> t[MAXN];
int len[MAXN], fa[MAXN], si[MAXN], tot = 1, last = 1, n, x;
long long ans;
void insert(int k) {
	int p = last;
	int np = last = ++tot;
	si[np] = 1;
	len[np] = len[p] + 1;
	for (; p && !t[p][k]; p = fa[p]) t[p][k] = np;
	if (!p) fa[np] = 1;
	else {
		int q = t[p][k];
		if (len[q] == len[p] + 1) fa[np] = q;
		else {
			int nq = ++tot;
			len[nq] = len[p] + 1;
			t[nq] = t[q];
			fa[nq] = fa[q];
			fa[q] = fa[np] = nq;
			for (; t[p][k] == q; p = fa[p]) t[p][k] = nq;
		}
	}
	ans += 1LL * (len[np] - len[fa[np]]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		insert(x);
		printf("%lld\n", ans);
	}
}
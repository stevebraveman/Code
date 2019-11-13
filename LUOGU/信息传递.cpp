#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200010
int siz[MAXN], fa[MAXN], x, n, ans = 0x7fffffff;
int find(int x, int &tot) {
	tot++;
	if (fa[x] == x) return x;
	else return find(fa[x], tot);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		// siz[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		int p = 0;
		int t = find(x, p);
		// printf("%d\n", t);
		if (t == i) {
			// puts("OK");
			ans = std::min(p, ans);
		}
		else fa[i] = x;
	}
	printf("%d\n", ans);
}
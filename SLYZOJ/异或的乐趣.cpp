#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 100001
int a[MAXN], n, m, l, r, op, z;
int main() {
	scanf("%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &l, &r);
			a[l] = r;
		}
		if (op == 2) {
			scanf("%d%d%d", &l, &r, &z);
			for (int i = l; i <= r; i++) {
				a[i] ^= z;
			}
		}
		if (op == 3) {
			scanf("%d", &l, &r);
			int ans = 0;
			for (int i = l; i <= r; i++) {
				ans ^= a[i];
			}
			printf("%d\n", ans);
		}
	}
}
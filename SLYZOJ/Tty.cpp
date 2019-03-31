// #pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 500010
int n, m, lastans, ty, op, b[MAXN], t[710], sq, k, a[1010][1010], top[1010];
int l, r;
int main() {
	scanf("%d%d%d", &n, &m, &ty);
	// sq = sqrt(n);
	// for (int i = 1; i <= n; i++) {
	// 	b[i] = (i - 1) / sq + 1;
	// }
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &l, &r);
			l = (l + lastans * ty) % n + 1;
			r = (r + lastans * ty) % n + 1;
			if (l > r) std::swap(l, r);
			lastans = 0;
			for (int i = l; i <= r; i++) {
				lastans += a[i][top[i]];
			}
			printf("%d\n", lastans);
		}
		if (op == 2) {
			scanf("%d", &l);
			l = (l + lastans * ty) % n + 1;
			if (top[l] != 0) {
				top[l]--;
			}
		}
		if (op == 3) {
			scanf("%d%d%d", &l, &r, &k);
			l = (l + lastans * ty) % n + 1;
			r = (r + lastans * ty) % n + 1;
			if (l > r) std::swap(l, r);
			for (int i = l; i <= r; i++) {
				a[i][++top[i]] = k;
			}
		}
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define int long long
int n, m, l, r, ans, q, flag = 0, cf[MAXN], a[MAXN], minx, maxx, p, x, b[MAXN];
char op[5];
signed main() {
	scanf("%lld%lld%lld%lld%lld", &n, &m, &p, &minx, &maxx);
	for (int i = 1; i <= m; i++) {
		scanf("%s", op);
		if (op[0] == 'A') {
			scanf("%lld%lld%lld", &l, &r, &x);
			cf[l] += x;
			cf[r + 1] -= x;
		}
		else {
			scanf("%lld%lld", &l, &r);
			flag = 0, ans = 0;
			for (int i = 1; i <= r; i++) {
				flag += cf[i];
				if (i >= l) ans += ((flag * i * 1LL % p) >= minx && (flag * i * 1LL % p) <= maxx ? 1 : 0);
			}
			printf("%lld\n", ans);
		}
	}
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + cf[i];
		a[i] = a[i - 1] + ((b[i] * i % p) >= minx && (b[i] * i % p) <= maxx ? 1 : 0);
	}
	scanf("%lld", &q);
	while (q--) {
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", a[r] - a[l - 1]);
	}
}
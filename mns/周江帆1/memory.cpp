#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
int a[MAXN], n, m, k, b[MAXN], ans = 0x7fffffff;
bool chk2(int x) {
	int _t = 0, __t = 0;
	for (int i = 1; i <= n; i++) {
		if (__t + b[i] <= x) {
			__t += b[i];
		}
		else {
			__t = b[i];
			_t++;
		}
	}
	return _t >= k;
}
int chk1(int x) {
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++) {
		b[i] = (a[i] + x) % m;
		l = std::max(l, b[i]);
		r += b[i];
	}
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (chk2(mid)) {
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return l;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		ans = std::min(ans, chk1(i));
		// printf("%d\n", chk1(i));
	}
	printf("%d", ans);
}
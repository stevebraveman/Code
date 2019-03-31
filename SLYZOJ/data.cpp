#include <bits/stdc++.h>
#define ll long long
int main() {
	freopen("data.in", "w", stdout);
	int n = 1000;
	int m = 1000;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) {
		ll x = rand() % 10000 + 1;
		ll y = rand() % 10000 + 1;
		ll z = rand() % 10000 + 1;
		ll ans = (x * y * z) % 2147483647;
		printf("%d ", ans);
	}
	puts("");
	while (m--) {
		int op = rand() % 3 + 1;
		int l = rand() % n + 1;
		int r = rand() % n + 1;
		int k = rand() % 100000 + 1;
		if (l > r) {
			std::swap(l, r);
		}
		if (op == 1) {
			printf("%d %d %d %d\n", op, l, k);
		}
		if (op == 2) {
			printf("%d %d %d %d\n", op, l, r, k);
		}
		if (op == 3) {
			printf("%d %d %d\n", op, l, r);
		}
	}
}
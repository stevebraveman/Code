#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
#define ll long long
int n, k, q, x, y;
ll a[MAXN], c[MAXN];
int lowbit(int x) {
	return x & -x;
}
void chg(int x, ll p) {
	for (int i = x; i <= n; i += lowbit(i)) {
		c[i] += p;
	}
}
ll ask(int x) {
	ll res = 0;
	for (; x; x -= lowbit(x)) {
		res += c[x];
	}
	return res;
}
bool chk() {
	for (int i = 1; i <= n - k + 1; i++) {
		ll p = ask(i);
		if (a[i] != p) {
			ll t = a[i] - p;
			chg(i, t);
			chg(i + k, -t);
		}
	}
	for (int i = n - k; i <= n; i++) {
		if (ask(i) != a[i]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	freopen("august.in", "r", stdin);
	freopen("august.out", "w", stdout);
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	if (chk()) {
		puts("Yes");
	}
	else {
		puts("No");
	}
	while (q--) {
		scanf("%d%d", &x, &y);
		a[x] += y;
		if (chk()) {
			puts("Yes");
		}
		else puts("No");
	}
}
/*
5 2 5
1 1 1 2 1
3 -1
1 -1
3 1
3 1
1 -1
 */
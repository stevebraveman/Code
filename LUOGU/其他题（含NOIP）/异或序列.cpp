#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
#define ll long long
ll a[MAXN], n, pre[MAXN], b[50], ans;
int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		// pre[i] = pre[i - 1] ^ a[i];
	}
	for (ll j = 0; j < 32; j++) {
		ll ze = 0, on = 0;
		for (ll i = 1; i <= n; i++) {
			if ((a[i] >> j) & 1) {
				ze = i - ze;
			}
			on += ze;
		}
		ans += on * (1 << j);
	}
	printf("%lld", ans);
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define ll long long
int T;
ll l, r, ans;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d%I64d", &l, &r);
		ans = l;
		for (ll i = 0; i < 62; i++) {
			ll m = 1LL << i;
			ans |= m;
			if (ans > r) {
				ans ^= m;
				break;
			}
		}
		printf("%I64d\n", ans);
	}
}

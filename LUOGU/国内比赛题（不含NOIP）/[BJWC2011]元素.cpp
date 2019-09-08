#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define MAXN 100010
struct num {
	ll id, val;
}m[MAXN];
ll n, ans, p[MAXN];
bool ins(ll k) {
	for (int i = 63; i >= 0; i--) {
		if (!(k >> (ll)i)) {
			continue;
		}
		if (p[i]) {
			k ^= p[i];
		}
		else {
			p[i] = k;
			return 1;
		}
	}
	return 0;
}
bool cmp(num a, num b) {
	return a.val > b.val;
}
int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &m[i].id, &m[i].val);
	}
	std::sort(m + 1, m + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		if (ins(m[i].id)) {
			ans += m[i].val;
		}
	}
	printf("%lld", ans);
	return 0;
}
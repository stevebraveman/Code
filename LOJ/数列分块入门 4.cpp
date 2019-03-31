#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100100
#define ll long long
ll a[MAXN], b[MAXN], t[MAXN], sum[MAXN], n, m, op;
ll min(ll a, ll b) {
	if (a < b) return a;
	else return b;
}
void update(ll l, ll r, ll k) {
	for (ll i = l; i <= min(b[l] * m, r); i++) {
		a[i] += k;
		sum[b[l]] += k;
	}
	if (b[l] != b[r]) {
		for (ll i = (b[r] - 1) * m + 1; i <= r; i++) {
			a[i] += k;
			sum[b[r]] += k;
		}
	}
	for (ll i = b[l] + 1; i <= b[r] - 1; i++) {
		t[i] += k;
	}
}
ll _sum(ll l, ll r) {
	ll ans = 0;
	for (ll i = l; i <= min(b[l] * m, r); i++) {
		ans += a[i] + t[b[l]];
	}
	if (b[l] != b[r]) {
		for (ll i = (b[r] - 1) * m + 1; i <= r; i++) {
			ans += a[i] + t[b[r]];
		}
	}
	for (ll i = b[l] + 1; i <= b[r] - 1; i++) {
		ans += sum[i] + m * t[i];
	}
	return ans;
}
ll l, r, k;
int main() {
	scanf("%d", &n);
	m = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		b[i] = (i - 1) / m + 1;
		sum[b[i]] += a[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &op, &l, &r, &k);
		if (op == 0) {
			update(l, r, k);
		}
		else {
			printf("%lld\n", _sum(l, r) % (k + 1));
		}
	}
}
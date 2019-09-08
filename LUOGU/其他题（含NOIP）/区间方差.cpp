#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 100010
#define ll long long
#define MOD 1000000007
struct Segtree {
	ll a[MAXN], b[MAXN << 2], sqr[MAXN << 2];
	void pd(ll p) {
		b[p] = b[ls(p)] + b[rs(p)];
		sqr[p] = sqr[ls(p)] + sqr[rs(p)];
	}
	void build(ll l, ll r, ll p) {
		if (l == r) {
			b[p] = a[l];
			sqr[p] = a[l] * a[l] % MOD;
			return;
		}
		ll m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void change(ll x, ll l, ll r, ll p, ll k) {
		if (l == r) {
			b[p] = k;
			sqr[p] = k * k % MOD;
			return;
		}
		ll m = (l + r) >> 1;
		if (x <= m) change(x, l, m, ls(p), k);
		else change(x, m + 1, r, rs(p), k);
		pd(p);
	}
	ll asksum(ll x, ll y, ll l, ll r, ll p) {
		ll s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		ll m = (l + r) >> 1;
		if (x <= m) s = (s + asksum(x, y, l, m, ls(p))) % MOD;
		if (y > m) s = (s + asksum(x, y, m + 1, r, rs(p))) % MOD;
		return s % MOD;
	}
	ll asksqr(ll x, ll y, ll l, ll r, ll p) {
		ll s = 0;
		if (x <= l && y >= r) {
			return sqr[p] % MOD;
		}
		ll m = (l + r) >> 1;
		if (x <= m) s = (s + asksqr(x, y, l, m, ls(p))) % MOD;
		if (y > m) s = (s + asksqr(x, y, m + 1, r, rs(p))) % MOD;
		return s % MOD;
	}
} tr;
ll qpow(ll a, ll b, ll mod) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res % MOD;
}
ll n, m, op, l, r, k, ny, ans, aver, ans2, p;
int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &tr.a[i]);
	}
	tr.build(1, n, 1);
	while (m--) {
		scanf("%lld%lld%lld", &op, &l, &r);
		if (op == 1) {
			tr.change(l, 1, n, 1, r);
		}
		else {
			if (l == r) {
				puts("0");
				continue;
			}
			ans = 0;
			aver = 0;
			p = tr.asksum(l, r, 1, n, 1) % MOD;
			ny = qpow(r - l + 1, MOD - 2, MOD);
			aver = (p % MOD * ny) % MOD;
			ans += tr.asksqr(l, r, 1, n, 1);
			ans2 = 2 * (p % MOD * aver) % MOD;
			ans -= ans2;
			ans = (ans % MOD + MOD) % MOD;
			ans += (r - l + 1) * (aver * aver % MOD) % MOD;
			ans = (ans * ny) % MOD;
			printf("%lld\n", ans);
		}
	}
}
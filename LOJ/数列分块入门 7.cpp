#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 1001000
#define MOD 10007
#define ll long long
ll min(ll a, ll b) {
	if (a < b) return a;
	else return b;
}
ll n, m, b[MAXN], a[MAXN], tim[MAXN], tadd[MAXN];
void reset(int x) {
	for (int i = (x - 1) * m + 1; i <= min(n, x * m); i++) {
		a[i] = (tim[x] * a[i] + tadd[x]) % MOD;
	}
	tim[x] = 1, tadd[x] = 0;
}
void update(bool f, ll l, ll r, ll k) {
	reset(b[l]);
	for (int i = l; i <= min(b[l] * m, r); i++) {
		if (f == 0) a[i] += k;
		else a[i] *= k;
		a[i] %= MOD;
	}
	if (b[l] != b[r]) {
		reset(b[r]);
		for (int i = (b[r] - 1) * m + 1; i <= r; i++) {
			if (f == 0) a[i] += k;
			else a[i] *= k;
			a[i] %= MOD;
		}
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		if (f == 0) tadd[i] = (tadd[i] + k) % MOD;
		else {
			tadd[i] = (tadd[i] * k) % MOD;
			tim[i] = (tim[i] * k) % MOD;
		}
	}
}
int l, r, op, k;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] %= MOD;
	}
	m = sqrt(n);
	for (int i = 1; i <= n; i++) {
		b[i] = (i - 1) / m + 1;
	}
	for (int i = 1; i <= b[n]; i++) {
		tim[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &op, &l, &r, &k);
		if (op < 2) {
			update(op, l, r, k);
		}
		else {
			printf("%d\n", (a[r] * tim[b[r]] + tadd[b[r]]) % MOD);
		}
	}
}
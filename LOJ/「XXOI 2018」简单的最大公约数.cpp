#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_map>
#define MAXN 10000010
#define ull unsigned long long
using namespace std;
tr1::unordered_map <ull, ull> h;
ull phi[MAXN], p[MAXN], tot, sum[MAXN], n, m, ans;
bool chk[MAXN];
ull qpow(ull a, ull b) {
	ull res = 1LL;
	while (b) {
		if (b & 1) res = res * a;
		b >>= 1;
		a = a * a;
	}
	return res;
}
void seive(ull n) {
	phi[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= tot && i * p[j] <= n; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				phi[i * p[j]] = phi[i] * phi[p[j]];
			}
			else {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + phi[i];
	}
}
ull djseive(ull n) {
	if (n <= 10000000) return sum[n];
	if (h[n]) return h[n];
	ull ans = (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);
	for (ull l = 2, r; l <= n; l = r + 1) {
		r = n / (n / l);
		ans -= (r - l + 1LL) * djseive(n / l);
	}
	return h[n] = ans;
}
int main() {
	scanf("%llu%llu", &n, &m);
	seive(10000000);
	for (ull l = 1, r; l <= m; l = r + 1) {
		r = m / (m / l);
		ans += (djseive(r) - djseive(l - 1)) * qpow(m / l, n); 
	}
	printf("%llu", ans);
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <tr1/unordered_map>
#define MAXN 10000010
#define MOD 1000000007
using namespace std;
tr1::unordered_map <int, int> h;
int mu[MAXN], p[MAXN], tot, sum[MAXN], n, m, ans;
bool chk[MAXN];
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * res * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return res % MOD;
}
void seive(int n) {
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= tot && i * p[j] <= n; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				mu[i * p[j]] = mu[i] * mu[p[j]];
			}
			else break;
		}
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + mu[i];
	}
}
int djseive(int n) {
	if (n <= 10000000) return sum[n];
	if (h[n]) return h[n];
	int ans = 1;
	for (int l = 2, r; l <= n; l = r + 1) {
		r = n / (n / l);
		ans -= (r - l + 1) * djseive(n / l);
	}
	return h[n] = (ans + MOD) % MOD;
}
using std::min;
int k, t, o;
int main() {
	scanf("%d%d%d%d", &n, &k, &t, &m);
	seive(10000000);
	t = (t - 1) / k;
	m = m / k;
	for (int l = 1, r; l <= m; l = r + 1) {
		r = min(m / (m / l), (t / l) ? t / (t / l) : 0x7fffffff);
		ans += 1LL * ((djseive(r) - djseive(l - 1) + MOD) % MOD) * qpow(m / l - t / l, n) % MOD;
		ans %= MOD;
	}
	printf("%d", ans);
}
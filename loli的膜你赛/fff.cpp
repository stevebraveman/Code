#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#define ll long long
#define MAXN 100010
ll n, p[MAXN], tot, f[MAXN], ans, k = 100, mu[MAXN], phi[MAXN], e[MAXN];
bool chk[MAXN];
void seive(ll li) {
	chk[1] = f[1] = mu[1] = 1;
	for (ll i = 2; i <= li; i++) {
		if (!chk[i]) {
			phi[i] = i - 1;
			f[i] = i - 1;
			if (k % i == 0) f[i]++;
			mu[i] = -1;
			p[++tot] = i;
		}
		for (int j = 1; j <= tot && i * p[j] <= li; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				phi[i * p[j]] = phi[i] * phi[p[j]];
				f[i * p[j]] = f[i] * f[p[j]];
				mu[i * p[j]] = -mu[i];
			}
			else {
				phi[i * p[j]] = phi[i] * p[j];
				if (k % p[j]) f[i * p[j]] = f[i] * p[j];
				else f[i * p[j]] = f[i] * f[p[j]];
				break;
			}
		}
	}
}
template <typename T>
T gcd(T a, T b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main() {
	freopen("test.out", "w", stdout);
	scanf("%lld", &k);
	seive(MAXN - 10);
	for (ll i = 1; i <= 100; i++) {
		ll g = 0;
		// puts("OK");
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				g += f[j];
			}
		}
		printf("%lld\n", g);
	}
}
#include<bits/stdc++.h>
#include <tr1/unordered_map>
#define MAXN 5000100
#define ll long long
#define re register
using namespace std;
tr1::unordered_map<ll, ll> ans2;
int p[MAXN], mu[MAXN], phi[MAXN], tot, t;
int m, n;
ll pre2[MAXN];
bool chk[MAXN];
void getshai() {
	mu[1] = phi[1] = 1;
	chk[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				phi[i * p[j]] = phi[i] * phi[p[j]];
			}
			else {
				phi[i * p[j]] = p[j] * phi[i];
				break;
			}
		}
	}
	for (int i = 1; i <= MAXN; i++) {
		pre2[i] = pre2[i - 1] + (ll)phi[i];
	}
}
ll getphi(ll x) {
	if (x <= MAXN) return pre2[x];
	if (ans2[x]) return ans2[x];
	ll ans = x * (x + 1LL) / 2;
	for (re ll l = 2, r; l <= x; l = r + 1) {
		r = x / (x / l);
		ans -= 1LL * (r - l + 1LL) * getphi(x / l);
	}
	return ans2[x] = ans;
}
int main() {
	getshai();
	scanf("%d", &n);
	printf("%lld", getphi((ll)n));
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 10000000
#define ll long long
ll p[MAXN] , tot , phi[MAXN] , t , pl, k;
bool chk[MAXN];
void euler() {
	phi[1] = 1;
	for (ll i = 2 ; i <= MAXN ; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = i - 1;
		}
		for (ll j = 1; j <= tot ; j++) {
			if (i * p[j] > MAXN) break;
			chk[i * p[j]] = 1;
			if (i % p[j] == 0) {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
			else phi[i * p[j]] = phi[i] * (p[j] - 1);
		}
	}
}
ll qpow(ll a , ll b , ll m) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return ans;
}
ll sol(ll p) {
	if (p == 1) return 0;
	else return qpow(k , sol(phi[p]) + phi[p] , p);
}
int main() {
	euler();
	scanf("%lld" , &t);
	while (t--) {
		scanf("%lld%lld" , &pl, &k);
		printf("%lld\n" , sol(pl));
	}
}

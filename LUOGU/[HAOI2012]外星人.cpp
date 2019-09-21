#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000000
#define ll long long
ll phi[MAXN] , p[MAXN] , tot = 0 , n , ans = 1 , pi , q , t;
bool chk[MAXN];
void euler() {
	phi[1] = 1;
	for (ll i = 2 ; i <= MAXN ; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = phi[i - 1];
		}
		for (ll j = 1 ; j <= tot && i * p[j] <= MAXN ; j++) {
			chk[i * p[j]] = 1;
			phi[i * p[j]] = phi[p[j]] + phi[i];
			if (i % p[j] == 0) break;
		}
	}
}
int main() {
	euler();
	scanf("%lld" , &t);
	while (t--) {
		scanf("%lld" , &n);
		ans = 1;
		for (ll i = 1 ; i <= n ; i++) {
			scanf("%lld%lld" , &pi , &q);
			if (pi == 2) ans--;
			ans += phi[pi] * q;
		}
		printf("%lld\n" , ans);
	}
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdio>
#define MAXN 200005
#define MOD 19260817
#define ll long long
ll d[MAXN] , a[MAXN] , x , l , r , p1 , p2 , sa[MAXN] , sd[MAXN] , sad[MAXN] , n , m;
void swap(ll &a , ll &b) {
	b ^= a;
	a ^= b;
	b ^= a;
}
ll max(ll a , ll b) {
	if (a > b) return a;
	else return b;
}
ll min(ll a , ll b) {
	if (a < b) return a;
	else return b;
}
ll qzh(ll x , ll l , ll r , bool ka) {
	if (l > r) return 0;
	ll k1 = ((sa[r] - sa[l - 1]) % MOD + MOD) % MOD;
	k1 *= (sd[x] % MOD);
	ll k2 = ((sad[r] - sad[l - 1]) % MOD + MOD) % MOD;
	if (!ka) swap(k1 , k2);
	return ((k1 - k2) % MOD + MOD) % MOD;
}
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 2 ; i <= n ; i++) {
		scanf("%d" , &d[i]);
		d[i] %= MOD;
		sd[i] = (sd[i - 1] + d[i] % MOD) % MOD;
	}
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , &a[i]);
		a[i] %= MOD;
		sa[i] = (sa[i - 1] + a[i] % MOD) % MOD;
		sad[i] = (sad[i - 1] + a[i] * sd[i] % MOD) % MOD;
	}
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d%d%d" , &x , &l , &r);
		p1 = qzh(x , l , min(r , x - 1) , 1);
		p2 = qzh(x , max(l , x + 1) , r , 0);
		printf("%lld\n" , (p1 + p2) % MOD);
	}
}

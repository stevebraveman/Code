#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define ll long long
#define MOD 1000000007
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
ll max(ll a, ll b) {
	if (a > b) return a;
	else return b;
}
ll mul(ll x, ll y, ll mod) {
	ll tmp = (x * y - (ll)((long double)x / mod * y + 1.0e-8) * mod);
	return tmp < 0 ? tmp + mod : tmp;
}
ll qpow(ll a, ll b, ll m) {
	ll ans = 1;
	a %= m;
	while(b) {
		if(b & 1) ans = mul(a, ans, m);
		b >>= 1;
		a = mul(a, a, m);
	}
	ans %= m;
	return ans;
}
ll ans = 0;
inline ll pksrand(){
    return rand() << 15 ^ rand() ;
}
inline ll rd(){
    return (((ll)pksrand()) << 30 ^ pksrand()) % MOD;
}
bool Miller_Rabin(ll n, int repeat) {
	if (n == 2 || n == 3 || n == 7 || n == 61 || n == 24251) return true;
	if (!(n % 2) || !(n % 3) || !(n % 7) || !(n % 61) || !(n % 24251) || n == 1 || n == 46856248255981LL) return false;
	ll d = n - 1;
	int s = 0;
	while(!(d & 1)) {
		s++;
		d >>= 1;
	}
	for(int i = 1; i <= repeat; i++) {
		ll a = rd() % (n - 3) + 2;
		ll x = qpow(a, d, n);
		ll y = 0;
		for(int j = 0; j < s; j++) {
			y = mul(x, x, n);
			if (y == 1 && x != 1 && x != (n - 1)) return false;
			x = y;
		}
		if(y != 1) return false;
	}
	return true;
}
ll mns(ll a, ll b) {
  if (a >= b) return a - b;
  else return b - a;
}
ll pollard_rho(ll n, ll c, ll stp){
	if (n % 2 == 0) return 2;
	if (n % 3 == 0) return 3;
	ll x = 2;
	ll y = x;
	ll d = 1;
	while (1) {
		ll _x = x, _y = y;
		for (ll i = 1; i <= stp; i++) {
			x = mul(x, x, n) + c;
			if (x >= n) x -= n;
			y = mul(y, y, n) + c;
			if (y >= n) y -= n;
			y = mul(y, y, n) + c;
			if (y >= n) y -= n;
			d = mul(d, mns(x, y), n);
		}
		d = gcd(d, n);
		if (d == 1) continue;
		if (d != n) return d;
		x = _x;
		y = _y;
		for (ll i = 1; i <= stp; i++) {
			x = mul(x, x, n) + c;
			if (x >= n) x -= n;
			y = mul(y, y, n) + c;
			if (y >= n) y -= n;
			y = mul(y, y, n) + c;
			if (y >= n) y -= n;
			d = gcd(n, mns(x, y));
			if (d != 1) return d % n;
		}
		return 0;
	}
}
ll find(ll n) {
	if(Miller_Rabin(n, 3)) {
		return n;
	}
	ll d = 0;
	ll k = 1;
	ll s = pow(n, 0.1);
	while(d == 0) {
		d = pollard_rho(n, k++, s);
	}
	return max(find(d), find(n / d));
}
ll n;
int main() {
	srand(time(NULL));
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%lld", &n);
		ans = find(n);
		if (ans == n) {
			puts("Prime");
			continue;
		}
		printf("%lld\n", ans);
	}
}
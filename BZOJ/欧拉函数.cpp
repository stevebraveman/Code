#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#define ll long long
#define MOD 1000000007
#define MAXN 100010
ll max(ll a, ll b) {
	if (a > b) return a;
	else return b;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
inline ll mul(const ll a, const ll b, const ll md) {
	ll c = (ll)a * b - (ll)((ll)((long double)a * b / md) * md);
	return c < 0 ? md + c : ((ll)c > md ? c - md : c);
}
ll ans[MAXN], top;
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
ll rd() {
	return ((rand() + rand()) % MOD) * MOD % rand() * rand() % MOD;
}
bool Rabin(ll p, ll x) {
	if(qpow(p, x - 1, x) != 1)
		return false;
	ll k = x - 1;
	while(!(k & 1))
	{
		k >>= 1;
		ll t = qpow(p, k, x);
		if(t != 1 && t != x - 1)
			return false;
		if(t == x - 1)
			return true;
	}
	return true;
}
bool Miller_Rabin(ll x) {
	if(x == 2 || x == 3 || x == 5 || x == 7 || x == 43)
		return true;
	if(x < 2)
		return false;
	return (Rabin(2, x) && Rabin(3, x) && Rabin(5, x) && Rabin(7, x) && Rabin(43, x));
}
ll pollard_rho(ll n, ll c) {
	ll i = 1, k = 2;
	ll x = rd() % (n - 1) + 1;
	ll y = x;
	while (1) {
		i++;
		x = (mul(x, x, n) + c) % n;
		ll d = gcd((y - x + n) % n, n);
		if(d != 1 && d != n) {
			return d;
		}
		if(y == x) {
			return n;
		}
		if(i == k) {
			y = x;
			k <<= 1;
		}
	}
}
void find(ll n, ll c) {
	if(n == 1) {
		return;
	}
	if(Miller_Rabin(n)) {
		ans[++top] = n;
		return;
	}
	ll d = n;
	ll k = c;
	while(d >= n) {
		d = pollard_rho(n, c--);
	}
	find(d, k);
	while(n % d == 0) {
		n /= d;
	}
	find(n, k);
}
ll n;
template <typename Tp>
void read(Tp &x) {
	Tp f = 1;
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	x = x * f;
}
int main() {
	int T;
	read(n);
	find(n, 120);
	std::sort(ans + 1, ans + 1 + top);
	if (ans[1] == n) {
		printf("%lld\n", n - 1);
		// puts("Prime");
		return 0;
	}
	ll k = n;
	ll pp = 1;
	for (int i = 1; i <= top; i++) {
		k /= ans[i];
		pp *= (ans[i] - 1);
	}
	if (k > 1) pp *= k;
	printf("%lld\n", pp);
}
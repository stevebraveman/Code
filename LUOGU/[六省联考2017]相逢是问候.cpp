#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100002
#define ll long long
using namespace std;
ll s[MAXN] , a[MAXN], tj[MAXN][100], c, p, n , sq , m, d[MAXN], zg;
bool v[MAXN];
bool chk[MAXN];
ll euler(ll n){
	ll res = n, a = n;  
	for (ll i = 2; i * i <= a; i++){  
		if (a % i == 0){ 
			res = res / i * (i - 1);
			while (a % i == 0) a /= i;
		}
	}
	if(a > 1) res = res / a * (a - 1);
	return res;
}
ll qpow(ll a, ll b, ll m) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return ans;
}
inline ll max(ll a, ll b) {
	if (a > b) return a;
	else return b;
}
inline ll min(ll a, ll b) {
	if (a < b) return a;
	else return b;
}
inline void quarysqrt(ll x) {
	if (v[x]) return;
	v[x] = 1;a[x] = 0;
	for (ll i = (x - 1) * sq + 1; i <= x * sq; i++) {
		s[i] = sqrt(s[i]);
		a[x] += s[i];
		if (s[i] > 1) v[x] = 0;
	}
}
inline void add(ll x , ll y) {
	if (v[p[x]] == 0) {
		for (ll i = x; i <= min(p[x] * sq , y); i++) {
			a[p[x]] -= s[i];
			s[i] = sqrt(s[i]);
			a[p[x]] += s[i];
		}
		v[p[x]] = 1;
		for (ll i = (p[x] - 1) * sq + 1; i <= p[x] * sq; i++) {
			if (s[i] > 1) {
				v[p[x]] = 0;
				break;
			}
		}
	}
	if (p[x] != p[y] && v[p[y]] == 0) {
		for (ll i = (p[y] - 1) * sq + 1; i <= y; i++) {
			a[p[y]] -= s[i];
			s[i] = sqrt(s[i]);
			a[p[y]] += s[i];
		}
		v[p[y]] = 1;
		for (ll i = (p[y] - 1) * sq + 1; i <= p[y] * sq; i++) {
			if (s[i] > 1) {
				v[p[y]] = 0;
				break;
			}
		}
	}
	for (ll i = p[x] + 1; i < p[y]; i++) {
		quarysqrt(i);
	}
}
ll getsum(ll x , ll y) {
	ll ans = 0;
	for (ll i = x; i <= min(p[x] * sq , y); i++) ans +=s[i];
	if (p[x] != p[y]) {
		for (ll i = (p[y] - 1) * sq + 1; i <= y; i++) {
			ans += s[i];
		}
	}
	for (ll i = p[x] + 1 ; i < p[y] ; i++) {
		ans += a[i];
	}
	return ans;
}
int main() {
	memset(v , 0 , sizeof (v));
	scanf("%lld" , &n, &m, &p, &c);
	ll k = p;
	zg = 1;
	d[zg] = p;
	while (k != 1) {
		k = euler(k);
		zg++;
		d[zg] = k;
	}
	std::reverse(d + 1, d + zg + 1)
	sq = sqrt(n);
	for (ll i = 1 ; i <= n ; i++) {
		scanf("%lld" , &s[i]);
	}
	scanf("%lld" , &m);
	for (ll i = 1 ; i <= n ; i++) {
		p[i] = (i - 1) / sq + 1;
		a[p[i]] += s[i];
	}
	for (ll i = 1 ; i <= m ; i++) {
		ll x , y , c;
		scanf("%lld%lld%lld" , &c , &x , &y);
		if (x > y) {
			swap(x , y);
		}
		if (c == 0) {
			add(x , y);
		}
		else printf("%lld\n" , getsum(x , y));
	}
	return 0;
}
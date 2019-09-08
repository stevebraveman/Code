#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100002
#define ll long long
ll p[MAXN] , n , N , m , t = 0;
ll s[MAXN] , a[MAXN];
bool v[MAXN];
inline ll max(ll a , ll b) {
	if (a > b) return a;
	else return b;
}
inline ll min(ll a , ll b) {
	if (a < b) return a;
	else return b;
}
inline void swap(ll a , ll b) {
	ll t = a;
	a = b;
	b = t;
}
inline void quarysqrt(ll x) {
	if (v[x]) return;
	v[x] = 1;a[x] = 0;
	for (ll i = (x - 1) * N + 1 ; i <= x * N ; i++) {
		s[i] = sqrt(s[i]);
		a[x] += s[i];
		if (s[i] > 1) v[x] = 0;
	}
}
inline void add(ll x , ll y) {
	if (v[p[x]] == 0) {
		for (ll i = x ; i <= min(p[x] * N , y) ; i++) {
			a[p[x]] -= s[i];
			s[i] = sqrt(s[i]);
			a[p[x]] += s[i];
		}
		v[p[x]] = 1;
		for (ll i = (p[x] - 1) * N + 1 ; i <= p[x] * N ; i++) {
			if (s[i] > 1) {
				v[p[x]] = 0;
				break;
			}
		}
	}
	if (p[x] != p[y] && v[p[y]] == 0) {
		for (ll i = (p[y] - 1) * N + 1 ; i <= y ; i++) {
			a[p[y]] -= s[i];
			s[i] = sqrt(s[i]);
			a[p[y]] += s[i];
		}
		v[p[y]] = 1;
		for (ll i = (p[y] - 1) * N + 1 ; i <= p[y] * N ; i++) {
			if (s[i] > 1) {
				v[p[y]] = 0;
				break;
			}
		}
	}
	for (ll i = p[x] + 1 ; i < p[y] ; i++) {
		quarysqrt(i);
	}
}
ll getsum(ll x , ll y) {
	ll ans = 0;
	for (ll i = x ; i <= min(p[x] * N , y) ; i++) ans +=s[i];
	if (p[x] != p[y]) {
		for (ll i = (p[y] - 1) * N + 1 ; i <= y ; i++) {
			ans += s[i];
		}
	}
	for (ll i = p[x] + 1 ; i < p[y] ; i++) {
		ans += a[i];
	}
	return ans;
}
int main() {
	while (scanf("%lld" , &n) != EOF) {
		memset(v , 0 , sizeof (v));
		memset(s , 0 , sizeof (s));
		memset(p , 0 , sizeof (p));
		memset(a , 0 , sizeof (a));
		N = sqrt(n);
		for (ll i = 1 ; i <= n ; i++) {
			scanf("%lld" , &s[i]);
		}
		t++;
		printf("Case #%lld:\n" , t);
		scanf("%lld" , &m);
		for (ll i = 1 ; i <= n ; i++) {
			p[i] = (i - 1) / N + 1;
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
		puts("");
	}
	return 0;
}
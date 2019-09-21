#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
struct L_B {
	ll d[65], p[65];
	int cnt;
	void init() {
		memset(d , 0 , sizeof(d));
		memset(p , 0 , sizeof(d));
		cnt = 0;
	}
	bool in(ll val) {
		for (int i = 60 ; i >= 0 ; i --) {
			if (val & (1ll << i)) {
				if (!d[i]) {
					d[i]=val;
					break;
				}
				val^=d[i];
			}
		}
		return val > 0;
	}
	ll query_max() {
		ll res = 0;
		for (int i = 60 ; i >= 0 ; i --) {
			if ((res^d[i]) > res) res ^= d[i];
		}
		return res;
	}
	ll query_min() {
		for (int i = 0 ; i <= 60 ; i ++) {
			if (d[i]) return d[i];
		}
		return 0;
	}
	void rebuild() {
		for (int i = 60 ; i >= 0 ; i --) {
			for (int j = i-1 ; j >= 0 ; j --) {
				if (d[i] & (1ll<<j)) d[i] ^= d[j];
			}
		}
		for (int i = 0 ; i <= 60 ; i ++) {
			if (d[i]) p[cnt++]=d[i];
		}
	}
	ll kthquery(ll k) {
		ll res = 0;
		if (k >= (1ll << cnt)) return -1;
		for (int i = 60 ; i >= 0 ; i --) {
			if (k & (1LL<<i)) res ^= p[i];
		}
		return res;
	}
}p;
ll n , k , a;
int main() {
	scanf("%lld%lld" , &n , &k);
	p.init();
	for (int i = 1 ; i <= n ; i++) {
		scanf("%lld" , &a);
		p.in(a);
	}
	p.rebuild();
	printf("%lld" , p.kthquery(k));
	return 0;
}
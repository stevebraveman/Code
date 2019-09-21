#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100002
#define ll long long
using namespace std;
int p[MAXN] , n , N , m;
ll s[MAXN] , a[MAXN];
bool v[MAXN];
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
inline int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
inline void quarysqrt(int x) {
	if (v[x]) return;
	v[x] = 1;a[x] = 0;
	for (int i = (x - 1) * N + 1 ; i <= x * N ; i++) {
		s[i] = sqrt(s[i]);
		a[x] += s[i];
		if (s[i] > 1) v[x] = 0;
	}
}
inline void add(int x , int y) {
	if (v[p[x]] == 0) {
		for (int i = x ; i <= min(p[x] * N , y) ; i++) {
			a[p[x]] -= s[i];
			s[i] = sqrt(s[i]);
			a[p[x]] += s[i];
		}
		v[p[x]] = 1;
		for (int i = (p[x] - 1) * N + 1 ; i <= p[x] * N ; i++) {
			if (s[i] > 1) {
				v[p[x]] = 0;
				break;
			}
		}
	}
	if (p[x] != p[y] && v[p[y]] == 0) {
		for (int i = (p[y] - 1) * N + 1 ; i <= y ; i++) {
			a[p[y]] -= s[i];
			s[i] = sqrt(s[i]);
			a[p[y]] += s[i];
		}
		v[p[y]] = 1;
		for (int i = (p[y] - 1) * N + 1 ; i <= p[y] * N ; i++) {
			if (s[i] > 1) {
				v[p[y]] = 0;
				break;
			}
		}
	}
	for (int i = p[x] + 1 ; i < p[y] ; i++) {
		quarysqrt(i);
	}
}
ll getsum(int x , int y) {
	ll ans = 0;
	for (int i = x ; i <= min(p[x] * N , y) ; i++) ans +=s[i];
	if (p[x] != p[y]) {
		for (int i = (p[y] - 1) * N + 1 ; i <= y ; i++) {
			ans += s[i];
		}
	}
	for (int i = p[x] + 1 ; i < p[y] ; i++) {
		ans += a[i];
	}
	return ans;
}
int main() {
	memset(v , 0 , sizeof (v));
	scanf("%d" , &n);
	N = sqrt(n);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%lld" , &s[i]);
	}
	scanf("%d" , &m);
	for (int i = 1 ; i <= n ; i++) {
		p[i] = (i - 1) / N + 1;
		a[p[i]] += s[i];
	}
	for (int i = 1 ; i <= m ; i++) {
		int x , y , c;
		scanf("%d%d%d" , &c , &x , &y);
		if (x > y) {
			swap(x , y);
		}
		if (c == 2) {
			add(x , y);
		}
		else printf("%lld\n" , getsum(x , y));
	}
	return 0;
}
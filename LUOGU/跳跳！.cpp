#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 305
#define sqr(x) ((x) * (x))
#define ll long long
ll h[MAXN] , ans , n , l , r;
bool cmp(ll a , ll b) {
	return a > b;
}
void swap(ll &a , ll &b) {
	if (a == b) return;
	a ^= b;
	b ^= a;
	a ^= b;
}
int main() {
	scanf("%lld" , &n);
	for (ll i = 1 ; i <= n ; i++) {
		scanf("%lld" , &h[i]);
	}
	std::sort(h + 1 , h + 1 + n , cmp);
	l = 1;
	r = n;
	for (int i = 1 ; i < n ; i++) {
		if (i & 1) ans += sqr(h[l] - h[r]) , l++;
		else ans += sqr(h[r] - h[l]) , r--;
	}
	ans += sqr(h[1]);
	printf("%lld\n" , ans);
}
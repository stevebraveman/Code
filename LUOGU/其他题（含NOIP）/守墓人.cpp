#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define ll long long
#define MAXN 200005
ll tag[MAXN], a[MAXN], b[MAXN], sq, n, m;
void update(ll l, ll r, ll c) {
	for (int i = l; i <= min(b[l] * sq, r); i++) {
		a[i] += c;
	}
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			a[i] += c;
		}
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		tag[i] += c;
	}
}
ll ask(ll l, ll r) {
	ll ans = 0
	for (int i = l; i <= min(b[l] * sq, r); i++) {
		ans += tag[i] + a[i];
	}
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			ans += tag[i] + a[i];
		}
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		ans += tag[i] * sq;
	}
}
int main() {
	scanf("%lld%lld" , &n , &m);
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = (i - 1) / sq + 1;
	}
	for (int i = 1 ; i <= m ; i++) {
		scanf("%lld" , &flag);
		if (flag == 1) {
			scanf("%lld%lld%lld" , &l , &r , &k);
			update(l , r , 1 , n , 1 , k);
		}
		if (flag == 2) {
			scanf("%lld" , &k);
			update(1 , 1 , 1 , n , 1 , k);
		}
		if (flag == 3) {
			scanf("%lld" , &k);
			update(1 , 1 , 1 , n , 1 , -k);
		}
		if (flag == 4) {
			scanf("%lld%lld%lld" , &l , &r);
			printf("%lld\n" , tree.sum(l , r , 1 , n , 1));
		}
		if (flag == 5) {
			printf("%lld\n" , tree.sum(1 , 1 , 1 , n , 1));
		}
	}
}
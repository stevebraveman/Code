#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 400010
#define ll long long
bool p1;
struct Trie {
	ll e[2], dat;
}t[MAXN * 32];
ll n, m, a[MAXN << 2], pre[MAXN << 2], siz[MAXN * 32], f, rt, tot;
struct num {
	ll id, rk, w;
};
bool p2;
bool operator < (num a, num b) {
	return a.w < b.w;
}
std::priority_queue <num> q;
void insert(ll k) {
	ll p = 0;
	for (int i = 32; i >= 0; i--) {
		ll d = (k >> (i * 1LL)) & 1;
		siz[p]++;
		if (!t[p].e[d]) t[p].e[d] = ++rt;
		p = t[p].e[d];
	}
	siz[p]++;
	t[p].dat = k;
}
ll ask(ll x, ll k) {
	ll p = 0, ans = 0;
	for (int i = 32; i >= 0; i--) {
		ll d = (x >> (i * 1LL)) & 1;
		if (!t[p].e[d ^ 1]) p = t[p].e[d];
		else if (k <= siz[t[p].e[d ^ 1]]) {
			p = t[p].e[d ^ 1];
			ans |= 1LL << i;
		}
		else {
			k -= siz[t[p].e[d ^ 1]];
			p = t[p].e[d];
		}
	}
	return ans;
}
int main() {
	scanf("%lld%lld", &n, &m);
	m *= 2;
	insert(0);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		pre[i] = pre[i - 1] ^ a[i];
		insert(pre[i]);
	}
	for (int i = 0; i <= n; i++) {
		q.push((num) {i, 1LL, ask(pre[i], 1)});
	}
	for (int i = 1; i <= m; i++) {
		num k = q.top();
		q.pop();
		tot += k.w;
		if (k.rk < n) q.push((num) {k.id, k.rk + 1, ask(pre[k.id], k.rk + 1)});
	}
	printf("%lld", tot >> 1);
	return 0;
}
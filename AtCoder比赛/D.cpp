#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
std::vector<ll> v1;
ll n, m, q, pos1, pos2, p1, p2, v[100010];
ll x, y;
int main() {
	scanf("%lld%lld%lld", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		v1.push_back(x);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &x);
		v[i] = x;
	}
	v[0] = -0x7fffffff;
	v[m + 1] = 0x7fffffff;
	for (int i = 1; i <= q; i++) {
		scanf("%lld", &x);
		y = x;
		puts("---------");
		pos1 = std::lower_bound(v1.begin(), v1.end(), x) - v1.begin();
		// printf("%lld %lld\n", v1[pos1] - x, x - v1[pos1 - 1]);
		// p1 = std::min(v1[pos1] - x, x - v1[pos1 - 1]);
		// pos2 = std::lower_bound(v + 1, v + 1 + m, y) - v;
		// printf("%lld %lld\n", v[pos2] - y, y - v[pos2 - 1]);
		p2 = std::min(v[pos2] - y, y - v[pos2 - 1]);
		printf("%lld %lld\n", pos1, pos2);
		printf("%lld\n", p1 + p2);
		puts("--------");
	}
	return 0;
}
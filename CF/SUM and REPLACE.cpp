#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 3010002
#define MX 1000100
#define ll long long
using namespace std;
int b[MAXN], n, sq, m;
ll s[MAXN], a[MAXN];
bool v[MAXN];
bool chk[MX];
int p[MX], d[MX], tot, num[MX];
inline int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
inline int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void getd() {
	chk[1] = 0;
	d[1] = 1;
	for (int i = 2; i <= MX; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			d[i] = 2;
			num[i] = 1;
		}
		for (int j = 1; j <= tot && i * p[j] <= MX; j++) {
			chk[i * p[j]] = 1;
			if (!(i % p[j])) {
				num[i * p[j]] = num[i] + 1;
				d[i * p[j]] = d[i] / (num[i] + 1) * (num[i * p[j]] + 1);
				break;
			}
			else {
				d[i * p[j]] = d[i] * d[p[j]];
				num[i * p[j]] = 1;
			}
		}
	}
}
inline void quarysqrt(int x) {
	if (v[x]) return;
	v[x] = 1;
	a[x] = 0;
	for (int i = (x - 1) * sq + 1; i <= x * sq; i++) {
		s[i] = d[s[i]];
		a[x] += s[i];
		if (s[i] > 2) v[x] = 0;
	}
}
inline void add(int x, int y) {
	if (v[b[x]] == 0) {
		for (int i = x; i <= min(b[x] * sq, y); i++) {
			a[b[x]] -= s[i];
			s[i] = d[s[i]];
			a[b[x]] += s[i];
		}
		v[b[x]] = 1;
		for (int i = (b[x] - 1) * sq + 1; i <= b[x] * sq; i++) {
			if (s[i] > 2) {
				v[b[x]] = 0;
				break;
			}
		}
	}
	if (b[x] != b[y] && v[b[y]] == 0) {
		for (int i = (b[y] - 1) * sq + 1; i <= y; i++) {
			a[b[y]] -= s[i];
			s[i] = d[s[i]];
			a[b[y]] += s[i];
		}
		v[b[y]] = 1;
		for (int i = (b[y] - 1) * sq + 1; i <= b[y] * sq; i++) {
			if (s[i] > 2) {
				v[b[y]] = 0;
				break;
			}
		}
	}
	for (int i = b[x] + 1; i <= b[y] - 1; i++) {
		quarysqrt(i);
	}
}
ll getsum(int x , int y) {
	ll ans = 0;
	for (int i = x; i <= min(b[x] * sq , y); i++) {
		ans += s[i];
	}
	if (b[x] != b[y]) {
		for (int i = (b[y] - 1) * sq + 1; i <= y; i++) {
			ans += s[i];
		}
	}
	for (int i = b[x] + 1; i < b[y]; i++) {
		ans += a[i];
	}
	return ans;
}
int main() {
	memset(v, 0, sizeof (v));
	scanf("%d%d", &n, &m);
	getd();
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &s[i]);
	}
	for (int i = 1; i <= n; i++) {
		b[i] = (i - 1) / sq + 1;
		a[b[i]] += s[i];
	}
	for (int i = 1; i <= m; i++) {
		int x, y, c;
		scanf("%d%d%d", &c, &x, &y);
		if (x > y) {
			swap(x, y);
		}
		if (c == 1) {
			add(x, y);
		}
		else printf("%lld\n", getsum(x, y));
	}
	return 0;
}
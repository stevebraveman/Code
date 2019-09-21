#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200020
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
long long tmin[MAXN << 2];
int a[MAXN << 2], lazy[MAXN << 2];
void pd(int x) {
	tmin[x] = std::min(tmin[ls(x)], tmin[rs(x)]);
}
void build(int l, int r, int p) {
	lazy[p] = 0;
	if (l == r) {
		tmin[p] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, ls(p));
	build(m + 1, r, rs(p));
	pd(p);
}
void f(int l, int r, int p, int k) {
	lazy[p] += k;
	tmin[p] += k;
}
void pushd(int l, int r, int p) {
	if (lazy[p]) {
		int m = (l + r) >> 1;
		f(l, m, ls(p), lazy[p]);
		f(m + 1, r, rs(p), lazy[p]);
		lazy[p] = 0;
	}
}
void change(int x, int y, int l, int r, int p, int k) {
	if (x <= l && y >= r) {
		lazy[p] += k;
		tmin[p] += k;
		return;
	}
	int m = (l + r) >> 1;
	pushd(l, r, p);
	if (x <= m) change(x, y, l, m, ls(p), k);
	if (y > m) change(x, y, m + 1, r, rs(p), k);
	pd(p);
}
long long ask(int x, int y, int l, int r, int p) {
	long long s = 0x7fffffffffffffLL;
	if (x <= l && y >= r) {
		return tmin[p];
	}
	int m = (l + r) >> 1;
	pushd(l, r, p);
	if (x <= m) s = std::min(s, ask(x, y, l, m, ls(p)));
	if (y > m) s = std::min(s, ask(x, y, m + 1, r, rs(p)));
	return s;
}
int l, r, k, n, m;
long long ans;
char c;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, n, 1);
	scanf("%d", &m);
	while (m--) {
		ans = 0x7fffffffffffffLL;
		scanf("%d%d", &l, &r);
		l++;
		r++;
		c = getchar();
		if (c == ' ') {
			scanf("%d", &k);
			if (l <= r) {
				change(l, r, 1, n, 1, k);
			}
			else {
				change(l, n, 1, n, 1, k);
				change(1, r, 1, n, 1, k);
			}
			
		}
		else {
			if (l <= r) {
				printf("%lld\n", ask(l, r, 1, n, 1));
			}
			else {
				ans = std::min(ask(l, n, 1, n, 1), ask(1, r, 1, n, 1));
				printf("%lld\n", ans);
			}
		}
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 40010
std::vector<int> ve[40010];
int a[MAXN], b[MAXN], tag[MAXN], n, m, sq, cnt, f[410][410], hs[MAXN], zx, p[MAXN], last = 0, lenth;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void init(int x) {
	int ans = 0, maxx = 0;
	memset(p, 0, sizeof(p));
	for (int i = (x - 1) * sq + 1; i <= n; i++) {
		p[a[i]]++;
		if (p[a[i]] > maxx || (p[a[i]] == maxx && hs[a[i]] < hs[ans])) {
			ans = a[i];
			maxx = p[a[i]];
		}
		f[x][b[i]] = ans;
	}
}
int ask(int x, int y, int l) {
	return std::upper_bound(ve[l].begin(), ve[l].end(), y) - std::lower_bound(ve[l].begin(), ve[l].end(), x);
}
void swap(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}
int query(int l, int r) {
	int ans = 0, maxx = 0;
	ans = f[b[l] + 1][b[r] - 1];
	maxx = ask(l, r, ans);
	for (int i = l; i <= min(b[l] * sq, r); i++) {
		int k = ask(l, r, a[i]);
		if (k > maxx || (k == maxx && hs[a[i]] < hs[ans])) {
			ans = a[i];
			maxx = k;
		}
	}
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			int k = ask(l, r, a[i]);
			if (k > maxx || (k == maxx && hs[a[i]] < hs[ans])) {
				ans = a[i];
				maxx = k;
			}
		}
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		hs[i] = a[i];
	}
	std::sort(hs + 1, hs + 1 + n);
	lenth = std::unique(hs + 1, hs + 1 + n) - hs - 1;
	for (int i = 1; i <= n; i++) {
		a[i] = (std::lower_bound(hs + 1, hs + 1 + lenth, a[i]) - hs);
		ve[a[i]].push_back(i);
	}
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		b[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= b[n]; i++) {
		init(i);
	}
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d%d", &x, &y);
		x = (last + x - 1) % n + 1, y = (last + y - 1) % n + 1;
		if (x > y) {
			swap(x, y);
		}
		last = hs[query(x, y)];
		printf("%d\n", last);
	}
}
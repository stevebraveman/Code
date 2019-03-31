#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define MAXN 500100
std::vector<int> ve[500010];
std::vector<int> vec[750][750];
int a[MAXN], b[MAXN], tag[MAXN], n, m, sq, cnt, f[750][750], hs[MAXN], zx, p[MAXN], last = 0, lenth;
bool vis[MAXN];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct node {
	int l, r;
};
void init(int x) {
	int maxx = 0;
	memset(p, 0, sizeof(p));
	for (int i = (x - 1) * sq + 1; i <= n; i++) {
		p[a[i]]++;
		vis[i] = 1;
		if (p[a[i]] > maxx) {
			maxx = p[a[i]];
		}
		f[x][b[i]] = maxx;
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
	int maxx = -0x7fffffff;
	maxx = f[b[l] + 1][b[r] - 1];
	for (int i = l; i <= min(b[l] * sq, r); i++) {
		int k = ask(l, r, a[i]);
		if (k > maxx) {
			maxx = k;
		}
	}
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			int k = ask(l, r, a[i]);
			if (k > maxx) {
				maxx = k;
			}
		}
	}
	return maxx;
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
	sq = sqrt(n * log2(n));
	for (int i = 1; i <= n; i++) {
		b[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= b[n]; i++) {
		init(i);
	}
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d%d", &x, &y);
		x = last ^ x, y = last ^ y;
		last = query(x, y);
		printf("%d\n", last);
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 1001000
#define INF 0x7fffffff
int a[MAXN], tag[MAXN], b[MAXN], n, m, x, y, sq;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int query(int l, int r) {
	int ans = INF;
	for (int i = l; i <= min(b[l] * sq, r); i++) {
		ans = min(a[i], ans);
	}
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			ans = min(a[i], ans);
		}
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		ans = min(tag[i], ans);
	}
	return ans;
}
void init() {
	for (int i = 1; i <= b[n]; i++) {
		tag[i] = INF;
		for (int j = (b[i] - 1) * sq + 1; j <= min(b[i] * sq, n); j++) {
			tag[i] = min(a[j], tag[i]); 
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		b[i] = (i - 1) / sq + 1;
	}
	init();
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		printf("%d\n", query(x, y));
	}
}
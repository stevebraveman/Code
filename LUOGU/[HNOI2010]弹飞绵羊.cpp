#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 2000010
int a[MAXN], n, m, b[MAXN], tag[MAXN], sq, op, x, y, l, r;
int ju[MAXN], nx[MAXN];
bool vis[MAXN];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void modify(int k, int r) {
	a[k] = r;
	int l = min(b[k] * sq, n);
	for (int i = l; i >= (b[k] - 1) * sq + 1; i--) {
		if (i + a[i] > l) {
			nx[i] = i + a[i];
			ju[i] = 1;
		}
		else {
			ju[i] = ju[i + a[i]] + 1;
			nx[i] = nx[i + a[i]];
		}
	}
}
int find(int x) {
	int k = 0;
	while (x <= n) {
		k += ju[x];
		x = nx[x];
	}
	return k;
}
void pre() {
	for (int i = n; i >= 1; i--) {
		if (i + a[i] >= min(b[i] * sq, n)) {
			nx[i] = i + a[i];
			ju[i] = 1;
		}
		else {
			ju[i] = ju[i + a[i]] + 1;
			nx[i] = nx[i + a[i]];
		}
	}
}
int main() {
	scanf("%d", &n);
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = (i - 1) / sq + 1;
	}
	scanf("%d", &m);
	pre();
	for (int i = 1; i <= m; i++) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &l);
			printf("%d\n", find(l + 1));
		}
		else {
			scanf("%d%d", &l, &r);
			modify(l + 1, r);
		}
	}
}
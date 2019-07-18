#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
bool p1;
int fa[MAXN], n, m, op, x, y, k, sq;
int b[MAXN], a[MAXN], num[150][MAXN], ro[150][MAXN];
bool p2;
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
void un(int p) {
	for (int i = (p - 1) * sq + 1; i <= min(n, sq * p); i++) {
		if (!ro[p][a[i]]) ro[p][a[i]] = i;
		else fa[i] = ro[p][a[i]];
	}
}
void change(int l, int r, int k) {
	for (int i = l; i <= min(sq * b[l], r); i++) {
		
	}
}
int ask(int l, int r, int k) {
}
int main() {
#ifdef DEBUG
	printf("%.2f MB", (double)(&p2 - &p1) / (1024 * 1024));
#endif
	scanf("%d%d", &n, &m);
	sq = 700;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= n; i++) {
		num[b[i]][a[i]]++;
	}
	for (int i = 1; i <= 100000; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= b[n]; i++) {
		un(i);
	}
	while (m--) {
		scanf("%d%d%d%d", &op, &x, &y, &k);
		if (op == 1) {
			change(x, y, k);
		}
		else {
			printf("%d\n", ask(x, y, k));
		}
	}
}
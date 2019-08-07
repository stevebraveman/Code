#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define re register
#define MAXN 3000010
struct que {
	int l, r, id;
}q[MAXN];
int n, m, ans[MAXN], tot, a[MAXN], c[MAXN], num[MAXN];
template <typename T>
void read(T &x) {
	T f = 1;
	x = 0;
	char c = getchar();
	while (c > '9' || c < '0') {if (c == '-') f = -1; c = getchar();}
	while (c <= '9' && c >= '0') {x = x * 10 + c - '0'; c = getchar();}
	x = x * f;
}
int sq, l, r, b, ne[MAXN], nex[MAXN], he[MAXN];
int lowbit(int x) {
	return x & (-x);
}
void modi(int x, int y) {
	for (; x <= n; x += lowbit(x)) {
		c[x] += y;
	}
}
int ask(int x) {
	int y = 0;
	for (; x > 0; x -= lowbit(x)) {
		y += c[x];
	}
	return y;
}
bool cmp(que x, que y) {
	return x.l < y.l;
}
int main() {
	read(n), read(b), read(m);
	for (re int i = 1; i <= n; i++) {
		// scanf("%d", &a[i]);
		read(a[i]);
	}
	// puts("OK");
	for (int i = n; i >= 1; i--) {
		ne[i] = he[a[i]];
		he[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		nex[i] = ne[ne[i]];
	}
	for (int i = 1; i <= n; i++) {
		if (++num[a[i]] == 2) modi(i, 1);
	}
	for (re int i = 1; i <= m; i++) {
		read(q[i].l), read(q[i].r);
		q[i].id = i;
	}
	// puts("OK");
	std::sort(q + 1, q + 1 + m, cmp);
	l = 1;
	for (re int i = 1; i <= m; i++) {
		for (; l < q[i].l; l++) {
			if (ne[l]) modi(ne[l], -1);
			if (nex[l]) modi(nex[l], 1);
		}
		ans[q[i].id] = ask(q[i].r) - ask(q[i].l - 1);
	}
	for (re int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
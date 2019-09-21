#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2000100
int a[(int)(MAXN * 9.5)], ls[(int)(MAXN * 9.5)], rs[(int)(MAXN * 9.5)], tot = 1, rt[(int)(MAXN * 9.5)];
int n, m, x, y, pre[MAXN], suf[MAXN];
struct mohatree {
	int ls, rs, s;
}b[(int)(MAXN * 9.5)];
template <typename T>
void read(T &x) {
	T f = 1;
	x = 0;
	char c = getchar();
	while (c > '9' || c < '0') {if (c == '-') f = -1; c = getchar();}
	while (c <= '9' && c >= '0') {x = x * 10 + c - '0'; c = getchar();}
	x *= f;
}
void build(int &p, int x, int l, int r) {
	b[tot++] = b[p];
	p = tot - 1;
	b[p].s++;
	if (l == r) {
		return;
	}
	int m = (l + r) >> 1;
	if (x <= m) build(b[p].ls, x, l, m);
	else build(b[p].rs, x, m + 1, r);
}
int ask(int x, int y, int l, int r, int p) {
	if (r <= p) return b[y].s - b[x].s;
	int m = (l + r) >> 1;
	int f = ask(b[x].ls, b[y].ls, l, m, p);
	if (p > m) f += ask(b[x].rs, b[y].rs, m + 1, r, p);
	return f;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(x);
		pre[i] = suf[x];
		suf[x] = i;
	}
	rt[0] = 0;
	read(m);
	for (int i = 1; i <= n; i++) {
		rt[i] = rt[i - 1];
		build(rt[i], pre[i], 0, n);
	}
	for (int i = 1; i <= m; i++) {
		read(x), read(y);
		printf("%d\n", ask(rt[x - 1], rt[y], 0, n, x - 1));
	}
}
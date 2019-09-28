#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
int s[MAXN][2], fa[MAXN], val[MAXN], cnt[MAXN], tot, siz[MAXN];
int rl(int x) {
	if (x == s[fa[x]][0]) return 0;
	if (x == s[fa[x]][1]) return 1;
}
void upd(int x) {
	siz[x] = siz[s[x][1]] + siz[s[x][0]] + cnt[x];
}
void rotate(int x) {
	int y = fa[x], z = fa[y], k = rl(x), w = s[x][k ^ 1];
	s[y][k] = w;
	fa[w] = y;
	s[z][rl(y)] = x;
	fa[x] = z;
	s[x][k ^ 1] = y;
	fa[y] = z;
	upd(y);
	upd(x);
}
void splay(int x, int to) {
	to = fa[to];
	while (fa[x] != to) {
		int y = fa[x];
		if (fa[y] == to) {
			rotate(x);
		}
		else if (rl(x) == rl(to)) {
			rotate(to);
			rotate(x);
		}
		else {
			rotate(x);
			rotate(to);
		}
	}
}
void 
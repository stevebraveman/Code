#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
struct Heap {
	int v, id;
	int s, xd;
}h[MAXN];
int fa[MAXN], a[MAXN];
bool ifd[MAXN];
int merge(int a, int b) {
	if (h[a].v == 0) return b;
	if (h[b].v == 0) return a;
	if (h[a].v > h[b].v || (h[a].v == h[b].v && a > b)) std::swap(a, b);
	h[b].xd = h[a].s;
	h[a].s = b;
	return a;
}
int merges(int a) {
	if (h[a].v == 0 || h[h[a].xd].v == 0) return a;
	int p = h[a].xd, q = h[p].xd;
	h[a].xd = h[p].xd = 0;
	return merge(merge(a, p), merges(q));
}
int del(int a) {
	printf("%d\n", h[a].v);
	h[a].v = -1;
	return merges(h[a].s);
}
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
bool un(int x, int y) {
	if (x == y) return 0;
	fa[y] = x;
	return 1;
}
int head[MAXN], x, y, n, m;
char op[5];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		fa[i] = i;
	}
	h[0].v = 0;
	for (int i = 1; i <= n; i++) {
		head[i] = i;
		h[i].v = a[i];
		h[i].id = i;
		h[i].s = h[i].xd = 0;
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%s", op);
		if (op[0] == 'M') {
			scanf("%d%d", &x, &y);
			int _x = find(x), _y = find(y);
			if (ifd[x] || ifd[y] || !un(_x, _y)) continue;
			head[_x] = merge(head[_x], head[_y]);
		}
		else {
			scanf("%d", &x);
			if (ifd[x]) {
				puts("0");
				continue;
			}
			int _x = find(x);
			ifd[h[head[_x]].id] = 1;
			head[_x] = del(head[_x]);
		}
	}
}
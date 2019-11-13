#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2000010
struct Heap {
	int v, id;
	int s, xd;
}h[MAXN];
int fa[MAXN], a[MAXN], siz[MAXN];
bool ifd[MAXN];
int merge(int a, int b) {
	if (h[a].v == 0) return b;
	if (h[b].v == 0) return a;
	if (h[a].v < h[b].v || (h[a].v == h[b].v && a < b)) std::swap(a, b);
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
	h[a].v = -1;
	return merges(h[a].s);
}
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
bool un(int x, int y) {
	fa[y] = x;
	return 1;
}
int head[MAXN], x, y, n, m, cnt;
void push(int a, int &p) {
	cnt++;
	head[cnt] = cnt;
	h[cnt].v = a;
	h[cnt].id = cnt;
	h[cnt].s = h[cnt].xd = 0;
	fa[cnt] = cnt;
	siz[cnt] = 1;
	p = merge(cnt, p);
}
char op[5];
int main() {
	while (scanf("%d", &n) != EOF) {
		// scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			fa[i] = i;
		}
		h[0].v = 0;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			head[i] = i;
			h[i].v = a[i];
			h[i].id = i;
			h[i].s = h[i].xd = 0;
			siz[i] = 1;
		}
		cnt = n;
		scanf("%d", &m);
		while (m--) {
			scanf("%d%d", &x, &y);
			int _x = find(x), _y = find(y);
			if (_x == _y) {
				puts("-1");
				continue;
			}
			bool fl1 = 0, fl2 = 0;
			if (siz[head[_x]] == 1) {
				h[head[_x]].v /= 2;
				fl1 = 1;
			}
			if (siz[head[_y]] == 1) {
				h[head[_y]].v /= 2;
				fl2 = 1;
			}
			if (!fl1) {
				int f = h[head[_x]].v;
				head[_x] = del(head[_x]);
				push(f / 2, head[_x]);
			}
			if (!fl2) {
				int g = h[head[_y]].v;
				head[_y] = del(head[_y]);
				push(g / 2, head[_y]);
			}
			un(_x, _y);
			head[_x] = merge(head[_x], head[_y]);
			siz[head[_x]] += siz[head[_y]];
			printf("%d\n", h[head[_x]].v);
		}
	}
}
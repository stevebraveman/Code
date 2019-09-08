#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 0x7fffffff
struct Segtree {
	int b[MAXN << 2], c[MAXN << 2];
	void pushd() {

	}
	void build(int p, int l, int r) {
		if (l == r) {
			b[p] = INF;
			return;
		}
		int m = (l + r) >> 1;
		build(ls(p), l, m);
		build(rs(p), m + 1, r);
		pd()
	}
};
int main() {}
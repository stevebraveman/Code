#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
struct Segtree {
	int a[MAXN], b[MAXN << 2], lazy[MAXN];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void build(int p, int l, int r) {
		lazy[p] = 0;
		if (l == r) {
			
		}
	}
};
int main() {

}
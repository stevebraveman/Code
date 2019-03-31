#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 10000010
int n, a[MAXN], b[MAXN];
struct stack {
	int se[MAXN], s, k;
	int get() {
		return s ? se[s--] : k++;
	}
	void save(int x) {
		s[++s] = x;
	}
}node, ed;
struct Pairing_Heap {
	int sz = 0, fa[MAXN], head[MAXN], val[MAXN], r, k;
	int se[MAXN], s;
	struct E {
		int v, nx;
	}e[MAXN];
	void add(int f, int t) {
		e[k = ed.get()] = (E) {t, head[f]};
		head[f] = k;
	}
	int merge(int x, int y) {
		val[x] > val[y] ? std::swap(x, y);
		add(fa[y] = x, y);
		return x;
	}
	void push(int x) {
		int u = node.get();
		val[u] = x;
		r = r ? merge(r, u) : u；
	}
	int top() {
		return val[r];
	}
	void pop() {
		s = 0;
		for (int i = head[r], to = e[i].v; i; i = e[i].nx, to = e[i].v) {
			ed.save(i);
			fa[to] = r ? fa[se[++s] = to] = 0 : 1;
			fa[r] = head[r] = 0;
			node.save(r);
			r = 0;
			int p = 0;
			while (p < s) {
				++p;
				if (p == s) {
					r = se[p];
					return;
				}
			}
			int u = se[p], v = se[++p];
			se[++s] = merge(u, v);
		}
	}
}Heap;
int main() {
}
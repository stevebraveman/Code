#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
struct node {
	int val, si, tag;
	node *son[2];
	node (int val = 0) : val(val), si(1), tag(0) {son[0] = son[1] = NULL;}
} *root;
void maint(node* p) {
	p -> si = 1;
	if (p -> son[0]) p -> si += p -> son[0] -> si;
	if (p -> son[1]) p -> si += p -> son[1] -> si;
}
void pushd(node* p) {
	if (p -> tag) {
		node *t = p -> son[0];
		p -> son[0] = p -> son[1];
		p -> son[1] = t;
		if (p -> son[0]) p -> son[0] -> tag ^= 1;
		if (p -> son[1]) p -> son[1] -> tag ^= 1;
		p -> tag = 0;
	}
}
void Rotate(node* &p, int t) {
	node* u = p -> son[t];
	pushd(u);
	p -> son[t] = u -> son[t ^ 1];
	u -> son[t ^ 1] = p;
	maint(p);
	maint(u);
	p = u;
}
void insert(node* &p, int v) {
	if (!p) p = new node(v);
	else {
		insert(p -> son[v < p -> val ? 0 : 1], v);
		maint(p);
	}
}
void Splay(node* &p, int k) {
	pushd(p);
	int l = (p -> son[0] ? p -> son[0] -> si : 0);
	if (l + 1 == k) return;
	int d = k <= l ? 0 : 1;
	int k2 = d ? k - l - 1 : k;
	node* &c = p -> son[d];
	pushd(c);
	int l2 = (c -> son[0] ? c -> son[0] -> si : 0);
	if (l2 + 1 != k2) {
		int d2 = k2 <= l2 ? 0 : 1;
		Splay(c -> son[d2], d2 ? k2 - l2 - 1 : k2);
		if (d == d2) Rotate(p, d);
		else Rotate(c, d2);
	}
	Rotate(p, d);
}
int FindK(node* &p, int k) {
	Splay(p, k);
	return p -> val;
}
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		insert(root, i);
		Splay(root, i);
	}
	for (int i = 1, l, r; i <= m; i++) {
		scanf("%d%d", &l, &r);
		if (l == 1 && r == n) root -> tag ^= 1;
		else if (l == 1) {
			Splay(root, r + 1);
			root -> son[0] -> tag ^= 1;
		}
		else if (r == n) {
			Splay(root, l - 1);
			root -> son[1] -> tag ^= 1;
		}
		else {
			Splay(root, l - 1);
			Splay(root -> son[1], r - (root -> son[0] ? root -> son[0] -> si : 0));
			root -> son[1] -> son[0] -> tag ^= 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", FindK(root, i));
	}
	return 0;
}

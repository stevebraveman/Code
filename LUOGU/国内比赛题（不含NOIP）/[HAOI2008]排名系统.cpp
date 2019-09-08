#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#define MAXN 1000010
using std::cout;
using std::cin;
using std::endl;
struct Treap {
	int l, r;
	int val, dat;
	int cnt, size;
}a[MAXN];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
std::map<std::string, int> h1;
std::map<int, std::string> h2;
int tot, root, n, INF = 0x7fffffff, tl;
int New(int val) {
	a[++tot].val = val;
	a[tot].dat = rand();
	a[tot].cnt = a[tot].size = 1;
	return tot;
}
void update(int p) {
	a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
}
void Build() {
	New(-INF), New(INF);
	root = 1, a[1].r = 2;
	update(root);
}
int FindR(int p, int val) {
	if (p == 0) return 0;
	if (val == a[p].val) return a[a[p].l].size + 1;
	if (val < a[p].val) return FindR(a[p].l, val);
	return FindR(a[p].r, val) + a[a[p].l].size + a[p].cnt;
}
int FindN(int p, int r) {
	if (p == 0) return INF;
	if (a[a[p].l].size >= r) return FindN(a[p].l, r);
	if (a[a[p].l].size + a[p].cnt >= r) return a[p].val;
	return FindN(a[p].r, r - a[a[p].l].size - a[p].cnt);
}
void zig(int &p) {
	int q = a[p].l;
	a[p].l = a[q].r, a[q].r = p, p = q;
	update(a[p].r), update(p);
}
void zag(int &p) {
	int q = a[p].r;
	a[p].r = a[q].l, a[q].l = p, p = q;
	update(a[p].l), update(p);
}
void insert(int &p, int val) {
	if (p == 0) {
		p = New(val);
		return;
	}
	if (val < a[p].val) {
		insert(a[p].l, val);
		if (a[p].dat < a[a[p].l].dat) zig(p);
	}
	else {
		insert(a[p].r, val);
		if (a[p].dat < a[a[p].r].dat) zag(p);
	}
	update(p);
}
void Remove(int &p, int val) {
	if (p == 0) return;
	if (val == a[p].val) {
		if (a[p].cnt > 1) {
			a[p].cnt--, update(p);
			return;
		}
		if (a[p].l || a[p].r) {
			if (a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat)
				zig(p), Remove(a[p].r, val);
			else
				zag(p), Remove(a[p].l, val);
			update(p);
		}
		else p = 0;
		return;
	}
	val < a[p].val ? Remove(a[p].l, val) : Remove(a[p].r, val);
	update(p);
}
int x;
std::string k;
char b[50], op;
int main() {
	Build();
	scanf("%d", &n);
	while (n--) {
		std::cin >> op;
		if (op == '+') {
			scanf("%s%d", b, &x);
			int l = strlen(b);
			for (int i = 0; i < l; i++) {
				k[i] = b[i];
			}
			if (h1[k] != 0) {
				Remove(root, h1[k]);
				insert(root, x);
			}
			else {
				insert(root, x);
				tl++;
			}
			h2[x] = k;
			h1[k] = x;
		}
		else {
			memset(b, 0, sizeof(b));
			scanf("%s", b);
			if (b[0] >= '0' && b[0] <= '9') {
				sscanf(b, "%d", x);
				for (int i = x + 1; i <= min(x + 10, tl); i++) {
					std::cout << h2[FindN(root, i)] << " ";
				}
				puts("");
			}
			else {
				std::string g;
				int l = strlen(b);
				for (int i = 0; i < l; i++) {
					g[i] = b[i];
				}
				printf("%d\n", FindR(root, h1[g]));
			}
		}
		printf("%d\n", n);
	}
}
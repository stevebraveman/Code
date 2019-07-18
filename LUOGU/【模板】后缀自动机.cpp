#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 4000100
#define ll long long
char s[MAXN];
struct SAM {
	int fa[MAXN], len[MAXN], e[MAXN][27], size, last, c[MAXN], a[MAXN], si[MAXN];
	void build(char a) {
		int k = a - 'a';
		int p = last, pt = ++size;
		last = pt;
		len[pt] = len[p] + 1;
		for (; p && !e[p][k]; p = fa[p]) {
			e[p][k] = pt;
		}
		if (!p) fa[pt] = 1;
		else {
			int q = e[p][k];
			if (len[p] + 1 == len[q]) fa[pt] = q;
			else {
				int pt2 = ++size;
				len[pt2] = len[p] + 1;
				memcpy(e[pt2], e[q], sizeof(e[q]));
				fa[pt2] = fa[q];
				fa[q] = fa[pt] = pt2;
				for (; e[p][k] == q; p = fa[p]) e[p][k] = pt2;
			}
		}
		si[pt] = 1;
	}
	void insert(char *s) {
		size = last = 1;
		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			build(s[i]);
		}
	}
	ll query() {
		ll max = 0;
		for (int i = 1; i <= size; i++) c[len[i]]++;
		for (int i = 1; i <= size; i++) c[i] += c[i - 1];
		for (int i = 1; i <= size; i++) a[c[len[i]]--] = i;
		for (int i = size; i; i--) {
			int p = a[i];
			// printf("%d\n", p);
			si[fa[p]] += si[p];
			if (si[p] > 1) max = std::max(max, 1LL * si[p] * len[p]);
		}
		return max;
	}
} mach;
int main() {
	scanf("%s", s);
	mach.insert(s);
	printf("%lld", mach.query());
}
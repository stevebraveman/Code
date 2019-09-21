#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 300010
std::vector<int> v[MAXN];
int n, m, op, l, r, x, a[MAXN];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		v[a[i]].push_back(i);
	}
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &l, &r, &x);
			int pos = std::upper_bound(v[x].begin(), v[x].end(), r) - std::lower_bound(v[x].begin(), v[x].end(), l);
			printf("%d\n", pos);
		}
		if (op == 2) {
			scanf("%d", &x);
			int ll = a[x], rr = a[x + 1];
			std::swap(a[x], a[x + 1]);
			if (a[x] == a[x + 1]) continue;
			int pos = std::lower_bound(v[ll].begin(), v[ll].end(), x) - v[ll].begin();
			int _pos = std::lower_bound(v[rr].begin(), v[rr].end(), x + 1) - v[rr].begin();
			v[ll][pos] = x + 1;
			v[rr][_pos] = x;
		}
	}
}
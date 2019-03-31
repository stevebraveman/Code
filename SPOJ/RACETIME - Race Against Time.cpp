#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 100010
int a[MAXN], b[MAXN], t[MAXN];
std::vector<int> ve[350];
int n, sq, l, r, c, m;
char op[5];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void reset(int l) {
	ve[l].clear();
	for (int i = (l - 1) * sq + 1; i <= min(l * sq, n); i++) {
		ve[l].push_back(a[i]);
	}
	sort(ve[l].begin(), ve[l].end());
}
void upd(int x, int y) {
	a[x] = y;
	reset(b[x]);
}
int sum(int l, int r, int k) {
	int ans = 0;
	for (int i = l; i <= min(b[l] * sq, r); i++) {
		if (a[i] <= k) ans++;
	}
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			if (a[i] <= k) ans++;
		}
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		ans += std::upper_bound(ve[i].begin(), ve[i].end(), k) - ve[i].begin();
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		b[i] = (i - 1) / sq + 1;
		ve[b[i]].push_back(a[i]);
	}
	for (int i = 1; i <= b[n]; i++) {
		std::sort(ve[i].begin(), ve[i].end());
	}
	for (int i = 1; i <= m; i++) {
		scanf("%s", op);
		if (op[0] == 'C') {
			scanf("%d%d%d", &l, &r, &c);
			printf("%d\n", sum(l, r, c));
		}
		else {
			scanf("%d%d", &l, &r);
			upd(l, r);
		}
	}
}
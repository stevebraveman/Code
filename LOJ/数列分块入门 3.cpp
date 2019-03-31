#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 100010
#define INF 19260817
int a[MAXN], b[MAXN], t[MAXN];
std::vector<int> ve[1000];
int n, m, l, r, c, op;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
void reset(int l) {
	ve[l].clear();
	for (int i = (l - 1) * m + 1; i <= min(l * m, n); i++) {
		ve[l].push_back(a[i]);
	}
	sort(ve[l].begin(), ve[l].end());
}
void update(int l, int r, int c) {
	for (int i = l; i <= min(b[l] * m, r); i++) {
		a[i] += c;
	}
	reset(b[l]);
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * m + 1; i <= r; i++) {
			a[i] += c;
		}
		reset(b[r]);
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		t[i] += c;
	}
}
int sum(int l, int r, int k) {
	int ans = -1;
	for (int i = l; i <= min(b[l] * m, r); i++) {
		if (a[i] + t[b[l]] < k) ans = max(ans, a[i] + t[b[l]]);
	}
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * m + 1; i <= r; i++) {
			if (a[i] + t[b[r]] < k) ans = max(ans, a[i] + t[b[r]]);
		}
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		int x = k - t[i];
		std::vector<int>::iterator it = (std::lower_bound(ve[i].begin(), ve[i].end(), x));
		if (it == ve[i].begin()) continue;
		it--;
		ans = max(ans, *it + t[i]);
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	m = sqrt(n);
	for (int i = 1; i <= n; i++) {
		b[i] = (i - 1) / m + 1;
		ve[b[i]].push_back(a[i]);
	}
	for (int i = 1; i <= b[n]; i++) {
		std::sort(ve[i].begin(), ve[i].end());
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &op, &l, &r, &c);
		if (op == 0) {
			update(l, r, c);
		}
		else {
			printf("%d\n", sum(l, r, c));
		}
	}
}
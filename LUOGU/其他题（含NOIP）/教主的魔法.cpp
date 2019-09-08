#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 1000010
int a[MAXN], b[MAXN], t[MAXN];
std::vector<int> ve[1011];
int n, sq, l, r, c, m;
char op;
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
void update(int l, int r, int c) {
	for (int i = l; i <= min(b[l] * sq, r); i++) {
		a[i] += c;
	}
	reset(b[l]);
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			a[i] += c;
		}
		reset(b[r]);
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		t[i] += c;
	}
}
int sum(int l, int r, int k) {
	int ans = 0;
	for (int i = l; i <= min(b[l] * sq, r); i++) {
		if (a[i] + t[b[l]] < k) ans++;
	}
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * sq + 1; i <= r; i++) {
			if (a[i] + t[b[r]] < k) ans++;
		}
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		int x = k - t[i];
		ans += ((std::lower_bound(ve[i].begin(), ve[i].end(), x) - ve[i].begin()));
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
		std::cin >> op;
		scanf("%d%d%d", &l, &r, &c);
		if (op == 'M') {
			update(l, r, c);
		}
		else {
			printf("%d\n", r - l + 1 - sum(l, r, c));
		}
	}
}
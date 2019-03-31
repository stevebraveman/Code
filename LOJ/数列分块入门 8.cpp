#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 1000100
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int n, m, tag[MAXN], b[MAXN], a[MAXN];
void reset(int x) {
	if (tag[x] == -1) {
		return;
	}
	for (int i = (x - 1) * m + 1; i <= x * m; i++) {
		a[i] = tag[x];
	}
	tag[x] = -1;
}
int query(int l, int r, int k) {
	int ans = 0;
	reset(b[l]);
	for (int i = l; i <= min(b[l] * m, r); i++) {
		if (a[i] == k) ans++;
		else a[i] = k;
	}
	if (b[l] != b[r]) {
		reset(b[r]);
		for (int i = (b[r] - 1) * m + 1; i <= r; i++) {
			if (a[i] == k) ans++;
			a[i] = k;
		}
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		if (tag[i] != -1) {
			if (tag[i] != k) tag[i] = k;
			else ans += m;
		}
		else {
			for (int j = (i - 1) * m + 1; j <= i * m; j++) {
				if (a[j] == k) ans++;
				else a[j] = k;
			}
			tag[i] = k;
		}
	}
	return ans;
}
int op, l, r, k;
int main() {
	scanf("%d", &n);
	memset(tag, -1, sizeof(tag));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	m = sqrt(n);
	for (int i = 1; i <= n; i++) {
		b[i] = (i - 1) / m + 1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", query(l, r, k));
	}
}
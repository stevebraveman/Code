#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 100010
int n, m, l, r, c, op;
int b[MAXN], t[MAXN], a[MAXN];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void update(int l, int r, int c) {
	for (int i = l; i <= min(b[l] * m, r); i++) {
		a[i] += c;
	}
	if (b[l] != b[r]) {
		for (int i = (b[r] - 1) * m + 1; i <= r; i++) {
			a[i] += c;
		}
	}
	for (int i = b[l] + 1; i <= b[r] - 1; i++) {
		t[i] += c;
	}
}
int main() {
	scanf("%d", &n);
	m = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		b[i] = (i - 1) / m + 1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &op, &l, &r, &c);
		if (op == 0) {
			update(l, r, c);
		}
		else {
			printf("%d\n", a[r] + t[b[r]]);
		}
	}
}
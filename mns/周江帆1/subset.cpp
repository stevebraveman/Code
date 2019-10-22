#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
int n, ifu[25], ans;
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
bool chk(int a) {
	if (a == 1 && n == 1) return 1;

	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (a & (1 << (i - 1))) ifu[++tot] = i;
	}
	if (tot == 0) return 0;
	if (tot == 1) {
		return 0;
	}
	int g = gcd(ifu[1], ifu[2]);
	int l = ifu[1] / g * ifu[2];
	for (int i = 3; i <= tot; i++) {
		g = gcd(g, ifu[i]);
		l = lcm(l, ifu[i]);
	}
	// puts("----");
	// for (int i = 1; i <= tot; i++) {
	// 	printf("%d ", ifu[i]);
	// }
	// puts("");
	// printf("%d %d\n", g, l);
	// puts("----");
	return ((g == 1) && (l == n));
}
int main() {
	scanf("%d", &n);
	ans = 0;
	for (int i = 0; i <= (1 << n) - 1; i++) {
		if (chk(i)) {
			ans++;
		}
	}
	printf("%d\n", ans);
}
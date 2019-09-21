#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define eps 1e-13
#define ld long double
using std::cout;
ld a[55][60];
int n, ans;
ld tmp, tps;
template <typename T>
void swap(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}
int Gauss() {
	for (int i = 1; i <= n; i++) {
		int maxi = i;
		for (int j = i + 1; j <= n; j++) {
			if (fabs(a[j][i]) > fabs(a[maxi][i])) {
				maxi = j;
			}
		}
		for (int j = 1; j <= n + 1; j++) {
			swap(a[maxi][j], a[i][j]);
		}
		if (!a[i][i]) continue;
		tps = a[i][i];
		for (int j = 1; j <= n + 1; j++) {
			a[i][j] /= tps;
		}
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				tmp = a[j][i];
				for (int k = 1; k <= n + 1; k++) {
					a[j][k] -= a[i][k] * tmp;
				}
			}
		}
	}
	bool f1 = 0, f2 = 0;
	for (int i = 1; i <= n; i++) {
		int tot = 0;
		for (int j = 1; j <= n + 1; j++) {
			if (!a[i][j]) tot++;
		}
		if (tot == n && a[i][n + 1]) {
			f1 = 1;
		}
		if (tot == n + 1) {
			f2 = 1;
		}
	}
	if (f1) return -1;
	if (f2) return 0;
	return 1;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1; j++) {
			std::cin >> a[i][j];
		}
	}
	ans = Gauss();
	if (ans <= 0) {
		printf("%d", ans);
		return 0;
	}
	for (int i = n - 1; i; i--) {
		for (int j = i + 1; j <= n; j++) {
			a[i][n + 1] -= a[j][n + 1] * a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		// a[i][n + 1] /= a[i][i];
		if (a[i][n + 1] == 0) printf("x%d=0\n", i);
		else cout << "x" << i << "=" << std::fixed << std::setprecision(2) << a[i][n + 1] << "\n";
	}
}
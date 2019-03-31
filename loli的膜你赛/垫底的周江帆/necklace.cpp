#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2002000
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
char a[MAXN], b[MAXN];
int la, lb, j, nx[MAXN], ans, f[MAXN], w[MAXN];
int main() {
	freopen("necklace.in", "r", stdin);
	freopen("necklace.out", "w", stdout);
	scanf("%s%s", a + 1, b + 1);
	la = strlen(a + 1), lb = strlen(b + 1);
	nx[1] = 0;
	for (int i = 1; i <= la; i++) {
		f[i] = a[i];
	}
	for (int i = 1; i <= la; i++) {
		a[i + la] = a[i];
	}
	for (int i = 2; i <= lb; i++) {
		while (j > 0 && b[i] != b[j + 1]) j = nx[j];
		if (b[i] == b[j + 1]) j++;
		nx[i] = j;
	}
	j = 0;
	for (int i = 1; i <= la * 2; i++) {
		while (j > 0 && a[i] != b[j + 1]) j = nx[j];
		if (a[i] == b[j + 1]) j++;
		if (j == lb) {
			ans = i - lb + 1;
			break;
			j = nx[j];
		}
	}
	if (ans == 0) {
		puts("No");
		return 0;
	}
	puts("Yes");
	int i = 1, j = 2, k = 0, p;
	while (i <= la && j <= la) {
		for (k = 0; k <= la && f[i + k] == f[j + k]; k++);
		if (k == la) break;
		if (f[i + k] > f[j + k]) {
			i = i + k + 1;
			if (i == j) i++;
		}
		else {
			j = j + k + 1;
			if (i == j) j++;
		}
	}
	p = min(i, j);
	for (int h = p; h <= la + p - 1; h++) {
		putchar(a[h]);
	}
	return 0;
}
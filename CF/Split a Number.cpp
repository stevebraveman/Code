#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 100100
int n, pos[MAXN], tot, na[MAXN], nb[MAXN], nc[MAXN];
char a[MAXN];
int main() {
	scanf("%d", &n);
	scanf("%s", a + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] == '0' && a[i + 1] > '0') {
			pos[++tot] = i;
		}
	}
	if (!tot) {
		if (n & 1) {
			for (int i = 1; i <= n; i++) {
			}
		}
	}
}
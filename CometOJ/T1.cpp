#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000100
int a[MAXN], c[MAXN], l, k, mina;
char b[MAXN];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	scanf("%s", b);
	l = strlen(b);
	for (int i = 1; i <= l; i++) {
		a[i] = b[i - 1] - '0';
		c[i] = a[i];
	}
	std::sort(a + 1, a + 1 + l, cmp);
	for (int i = 1; i <= l; i++) {
		a[i] = a[i] - c[i];
	}
	for (int i = l; i >= 1; i--) {
		if (a[i] < 0) a[i] += 10, a[i - 1]--;
	}
	printf("%d", (int)abs(a[l]));
	return 0;
}
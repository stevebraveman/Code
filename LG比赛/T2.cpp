#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1000100
char s[MAXN];
int l, x[MAXN], y[MAXN], fl;
int main() {
	scanf("%s", s + 1);
	l = strlen(s + 1);
	std::reverse(s + 1, s + 1 + l);
	for (int i = 1; i <= l; i++) {
		if (s[i] == 'X') {
			x[i] = 1;
			fl = 1;
		}
		if (s[i] == 'Y') {
			y[i] = 1;
			fl = 1;
		}
		if (s[i] == 'Z') {
			if (fl == 1) {
				puts("-1");
				return 0;
			}
		}
	}
	for (int i = l; i >= 1; i--) {
		printf("%d", x[i]);
	}
	puts("");
	for (int i = l; i >= 1; i--) {
		printf("%d", y[i]);
	}
}
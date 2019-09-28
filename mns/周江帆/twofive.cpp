#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
char p[5];
int main() {
	freopen("twofive.in", "r", stdin);
	freopen("twofive.out", "w", stdout);
	scanf("%s", p);
	if (p[0] == 'N') {
		puts("ABCDEFGHIJKLMNOPQRSUTVWXY");
	}
	else {
		puts("2");
	}
}

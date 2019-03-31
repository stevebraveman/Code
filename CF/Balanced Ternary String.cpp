#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1001000
char s[MAXN], b[5], n;
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		b[s[i] - '0']++;
	}
	
}
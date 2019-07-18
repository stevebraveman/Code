#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
#define MOD 1000000007
#define ll long long
int n, ans, flag;
char c[MAXN];
int main() {
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		int j = i + 1;
		if (s[i] == '+') flag = 1;
		if (s[i] == '-') flag = 2;
		if (s[i] == '*') flag = 3;
		if (s[i] == '%') flag = 4;
		if (s[i] == '^') flag = 5;
		while (1) {

			if (s[j + 1] < '0' || s[j + 1] > '9') break;
		}
		i = j + 1;
	}
	printf("%lld", ans);
	return 0;
}
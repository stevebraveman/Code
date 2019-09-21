#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200100
int x, y, n, a[MAXN], b[MAXN];
char s[MAXN];
int ans;
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 2; i <= n; i += 2) {
		if (s[i - 1] == s[i]) {
			if (s[i] == 'a') {
				s[i] = 'b';
				ans++;
			}
			else if (s[i] == 'b') {
				s[i] = 'a';
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		std::cout << s[i];
	}
	return 0;
}

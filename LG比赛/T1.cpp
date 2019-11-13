#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000010
char a[MAXN];
int l, ans, maxx = 0;
int main() {
	scanf("%s", a);
	l = strlen(a);
	for (int i = 0; i < l; i++) {
		if (a[i] == '0') {
			ans++;
			maxx = std::max(ans, maxx);
		}
		if (a[i] == '1') {
			ans--;
			if (ans < 0) {
				ans = 0;
			}
		}
	}
	if (maxx == 0) {
		puts("-1");
		return 0;
	}
	printf("%d\n", maxx);
}
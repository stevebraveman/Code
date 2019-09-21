#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
struct can {
	int w, id;
}a[MAXN];
int tot, st[MAXN], n;
bool cmp(can a, can b) {
	return a.w > b.w;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].w);
		a[i].id = i;
	}
	std::sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		tot += (i - 1) * a[i].w;
		st[i] = a[i].id;
	}
	tot += n;
	printf("%d\n", tot);
	for (int i = 1; i <= n; i++) {
		printf("%d ", st[i]);
	}
	return 0;
}

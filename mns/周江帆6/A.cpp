#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
int a[MAXN], n, tot = 1, bj[MAXN];
struct node {
	int id, w;
}p[MAXN];
bool cmp(node a, node b) {
	return a.id < b.id;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] < a[i - 1]) tot++;
		p[i].w = tot;
		p[i].id = a[i];
	}
	std::sort(p + 1, p + 1 + n, cmp);
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d %d\n", p[i].id, p[i].w);
	// }
	for (int i = 1; i <= n; i++) {
		if (p[i].w != p[i - 1].w) {
			bj[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (bj[i]) continue;
		p[i].w = ++tot;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", p[i].w);
	}
	return 0;
}
/*
10
6 7 8 9 10 1 2 3 4 5
 */
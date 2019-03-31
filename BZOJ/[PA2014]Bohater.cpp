#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
struct Monster {
	int d, a, id;
}m[MAXN];
bool cmp(Monster a, Monster b) {
	return a.a > b.a || (a.a == b.a && b.d < a.d);
}
int n, z, cnt, ss[MAXN];
int main() {
	scanf("%d%d", &n, &z);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &m[i].d, &m[i].a);
		m[i].id = i;
	}
	std::sort(m + 1, m + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		z -= m[i].d;
		if (m[i].d < 0) break;
		z += m[i].a;
		ss[++cnt] = m[i].id;
	}
	if (cnt == n) {
		printf("TAK\n");
		for (int i = 1; i <= cnt; i++) {
			printf("%d ", ss[i]);
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 30005
int fa[MAXN], n, u, v, size[MAXN], d[MAXN], p, q;
char a;
int find(int x) {
	if (x == fa[x]) return x;
	int r = find(fa[x]);
	d[x] += d[fa[x]];
	return fa[x] = r;
}
inline void un(int x, int y) {
	x = find(x), y = find(y);
	fa[x] = y, d[x] = size[y];
	size[y] += size[x];
}
void init() {
	for (int i = 1; i <= 30000; i++) {
		fa[i] = i;
		size[i] = 1;
	}
}
int main() {
	scanf("%d", &n);
	init();
	for (int i = 1; i <= n; i++) {
		std::cin >> a;
		if (a == 'C') {
			scanf("%d", &u);
			find(u);
			printf("%d\n", d[u] - d[find(u)]);
		}
		else {
			scanf("%d%d", &u, &v);
			un(u, v);
		}
	}
	return 0;
}
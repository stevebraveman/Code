#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 30005
int fa[MAXN] , n , u , v , size[MAXN] , d[MAXN] , p , q;
char a;
inline int abs(int x) {
	if (x < 0) x = -x;
	return x;
}
int find(int x) {
	if (x == fa[x]) return x;
	int r = find(fa[x]);
	d[x] += d[fa[x]];
	return fa[x] = r;
}
inline void un(int x , int y) {
	x = find(x) , y = find(y);
	fa[x] = y , d[x] = size[y];
	size[y] += size[x];
}
void init() {
	for (int i = 1 ; i <= 30000 ; i++) {
		fa[i] = i;
		size[i] = 1;
	}
}
int main() {
	scanf("%d" , &n);
	init();
	for (int i = 1 ; i <= n ; i++) {
		std::cin >> a;
		if (a == 'C') {
			scanf("%d%d" , &u , &v);
			p = find(u);
			q = find(v);
			if (p != q) {
				printf("-1\n");
			}
			else printf("%d\n" , abs(d[u] - d[v]) - 1);
		}
		else {
			scanf("%d%d" , &u , &v);
			un(u , v);
		}
	}
	return 0;
}
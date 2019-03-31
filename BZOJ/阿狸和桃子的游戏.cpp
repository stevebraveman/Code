#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define MAXN 1000010
int p[MAXN] , ans , n , m , u , v , w;
int main() {
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , &p[i]);
		ans -= p[i];
		p[i] <<= 1;
	}
	for (int i = 1 ; i <= m ; i++) {
		scanf("%d%d%d" , &u , &v , &w);
		ans -= w;
		p[u] += w;
		p[v] += w;
	}
	std::sort(p + 1 , p + 1 + n);
	for (int i = n ; i >= 1 ; i -= 2) {
		ans += p[i];
	}
	printf("%d\n" , ans);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define re register
#define FOR(i, l, r) for(re int i = l; i <= r; ++i)
using namespace std;

int n, m, c, r, t, x, y, z;
int a[1000100];

int main() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
	  scanf("%d", &a[i]);
	FOR(i, 1, m) {
		scanf("%d", &t);
		if(t == 1) {
			scanf("%d%d", &x, &y);
			a[x] = y;
		}
		if(t == 2) {
			scanf("%d%d%d", &x, &y, &z);
			FOR(j, x, y)
	          a[j] ^= z;
		}
		if(t == 3) {
			scanf("%d%d", &x, &y);
			int res = 0;
			FOR(j, x, y)
			  res ^= a[j];
			printf("%d\n", res);
		}
	}
}

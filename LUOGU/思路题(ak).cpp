#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
struct num {
	int a, b, id;
}a[MAXN];
int n, d[MAXN], g[MAXN], top, k[MAXN], len;
bool cmp(num a, num b) {
	return a.b > b.b || ((a.b == b.b) && a.a < b.a);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].a);
		a[i].id = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].b);
	}
	std::sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		if (a[i].a >= d[top]) d[++top] = a[i].a, g[a[i].id] = top;
		else {
			int l = 1, r = top, mid;
			while (l < r) {
				mid = (l + r) >> 1;
				if (d[mid] <= a[i].a) {
					l = mid + 1;
				}
				else r = mid;
			}
			// int j = std::upper_bound(d + 1, d + 1 + top, a[i].a) - d;
			d[l] = a[i].a;
			g[a[i].id] = l;
		}
	}
	printf("%d\n", top);
	len = top;
	for (int i = n; i >= 1; i--) {
		if (g[a[i].id] == len){
			k[len--] = a[i].id;
		}
		if (len < 1) {
			break;
		}
	}
	for (int i = 1; i <= top; i++) {
		printf("%d ", k[i]);
	}
}
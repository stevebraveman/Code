#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n , m , le , a[50004];
bool chk (int d) {
	int la = 0 , tot = 0;
	for (int i = 1 ; i <= n ; i++) {
		if (a[i] - la < d) {
			tot++;
		}
		else {
			la = a[i];
		}
	}
	return tot <= m;
}
int main () {
	int ans = 0;
	scanf("%d%d%d" , & le , & n , & m);
	if (n == 0 && m == 0) {
		printf("%d" , le);
		return 0;
	}
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , & a[i]);
	}
	// a[n + 1] = le;
	sort (a + 1 , a + 1 + n);
	int l = 0 , r = le , mid;
	a[n+1] = le;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (chk(mid)) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	if (! chk(le)) l -= 1;
	printf("%d" , l);
	return 0;
}
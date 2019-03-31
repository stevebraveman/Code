#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 100005
#define ll long long
ll a[MAXN] , b[MAXN];
int t , n , m , cnt;
bool y[MAXN];
bool cmp(int a , int b) {
	return a > b;
}
ll prime(ll p) {
	int k = sqrt(p);
	for (int i = 2 ; i <= k ; i++) {
		if (p % i == 0) return 2;
	}
	return 1;
}
ll inline read() {
	ll x = 0;char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
	return x;
}
int main() {
	t = read();
	while (t--) {
		memset(y , 0 , sizeof(y));
		n = read();
		m = read();
		// scanf("%d%d" , &n , &m);
		for (int i = 1 ; i <= n ; i++) {
			a[i] = read();
			// scanf("%lld" , &a[i]);
		}
		std::sort(a + 1 , a + 1 + n , cmp);
		for (int i = 1 ; i <= m ; i++) {
			b[i] = read();
			// scanf("%lld" , &b[i]);
		}
		std::sort(b + 1 , b + 1 + m , cmp);
		for (int i = 1 , r = 1; i <= m ; i++) {
			while (b[i] < a[r]) r++;
			y[r] = 1;
			r++;
		}
		cnt = 0;
		for (int i = 1 ; i <= n ; i++) {
			if (!y[i]) {
				if (a[i] == 1) continue;
				cnt += prime(a[i]);
				if (cnt > 1) {
					break;
				}
			}
		}
		puts(cnt == 1 ? "YES" : "NO");
	}
}
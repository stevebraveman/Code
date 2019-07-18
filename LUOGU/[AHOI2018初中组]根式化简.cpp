#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <cstring>
#define MAXN 2000005
#define ll long long
ll p[2 * MAXN + 10], tot, n, a[MAXN], x;
bool chk[2 * MAXN + 10];
void Sieve() {
	chk[1] = 1;
	for (ll i = 1; i <= MAXN + 10; i++) {
		if (!chk[i]) {
			p[++tot] = i;
		}
		for (int j = 1; j <= tot && i * p[j] <= MAXN + 10; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
int main() {
	scanf("%lld", &n);
	Sieve();
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {

	}
}
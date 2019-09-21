#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10
long double a, b;
long long n, m, j, f[MAXN], tot;
int main() {
	scanf("%lld", &n);
	m = 4 * n - 2;
	n = n * n + n;
	std::swap(n, m);
	printf("%lld.", m / n);
	m = m % n;
	for(int i = 1; i <= MAXN; i++) {
		if(m == 0){ 
			f[++tot] = 0;
			continue;
		}
		j = 10 * m / n;
		f[++tot] = j;
		m = 10 * m % n;
	}
	if (f[10] >= 5) {
		f[9]++;
	}
	for (int i = 1; i <= 9; i++) {
		printf("%lld", f[i]);
	}
	printf("\n");
	return 0;
}
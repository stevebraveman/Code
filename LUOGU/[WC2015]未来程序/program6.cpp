#include <stdio.h>
unsigned long long a, b, c, t, k, n;
unsigned long long rd() {
	t = (t * t * a + b) % c;
	return t;
}

int main() {
	int i;
	for (i = 0; i <= 9; i++) {
		scanf("%llu %llu %llu %llu", &n, &a, &b, &c);
		t = 0;
		k = 1;
		while (k <= n) {
			k = k + 1;
			rd();
		}
		printf("%llu\n", t);
	}
}

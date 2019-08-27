#include <stdio.h>
unsigned long long s0, s1, s2, s3, s4, i, n;
int main() {
	scanf("%llu", &n);
	i = 0;
	while (i <= n) {
		s0 = s0 + 1;
		s1 = s1 + i;
		s2 = s2 + i * i;
		s3 = s3 + i * i * i;
		s4 = s4 + i * i * i * i;
		i = i + 1;
	}
	printf("%llu\n", s0);
	printf("%llu\n", s0);
	printf("%llu\n", s1);
	printf("%llu\n", s1);
	printf("%llu\n", s2);
	printf("%llu\n", s2);
	printf("%llu\n", s3);
	printf("%llu\n", s3);
	printf("%llu\n", s4);
	printf("%llu\n", s4);
	return 0;
}
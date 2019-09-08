#include <stdio.h>
#include <stdlib.h>
void _() {
	unsigned long long a, b, c, d, i;
	scanf("%llu %llu %llu", &a, &b, &c);
	i = 0;
	d = 0;
	while (i < b) {
		d = d + a;
		d = d % c;
		i = i + 1;
	}
	printf("%llu\n", d);
}

int main() {
	_();
	_();
	_();
	_();
	_();
	
	_();
	_();
	_();
	_();
	_();
}


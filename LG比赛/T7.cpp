#include <iostream>
#include <cstdio>
int a[] = {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1};
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", a[n] ^ 1);
}
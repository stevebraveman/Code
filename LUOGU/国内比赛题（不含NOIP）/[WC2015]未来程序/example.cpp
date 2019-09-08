#include <stdio.h>
#include <stdlib.h>
int a, b, c, n;

int main() {
	printf("Hello, National Olympiad in Informatics!\n");
	scanf("%d%d", &a, &b);
	printf("%d\n", a + b);
	printf("%cinter %camp\n", (char)a, (char)b);
	while (a != 0) {
		a += b;
		c += 1;
	}
	printf("%d %d\n", a, c);
	c = c % 10;
	int i = -1;
	while (0 == 0) {
		if (abs(i) <= 0) {
			printf("%d\n", i);
			break;
		}
		i += 641;
	}
	printf(".\n");
	printf(".\n");
	printf(".\n");
	printf(".\n");
	printf(".\n");
	return 0;
}

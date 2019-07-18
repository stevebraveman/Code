#include <bits/stdc++.h>
#define random(a, b) rand() % ((b) - (a) + 1) + (a)
std::vector<int> v[50];
int x[50], y[50], cnt;
int main() {
	srand(time(NULL));
	int n, m;
	printf("1");
	puts("");
	n = random(1, 1000);
	m = random(1, 1000);
	printf("%d %d\n", n, m);
}
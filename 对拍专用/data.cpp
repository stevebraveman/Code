#include <bits/stdc++.h>
#define random(a, b) rand() % ((b) - (a) + 1) + (a)
int p[100005], tot = 1, bj[100005];
bool cmp(int a, int b) {
	return a > b;
}
struct node {
	int id, w;
}a[101000];
bool cmp2(node a, node b) {
	if (a.w != b.w) return a.w < b.w;
	else return a.id < b.id;
}
int main() {
	srand(time(NULL));
	int n, m;
	n = 10000;
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) {
		p[i] = tot;
		// printf("%d\n", i);
		tot += random(0, 1);
	}
	std::sort(p + 1, p + 1 + n, cmp);
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d\n", p[i]);
	// }
	for (int i = 1; i <= n; i++) {
		a[i].id = i;
		a[i].w = p[i];
	}
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d %d\n", a[i].id, a[i].w);
	// }
	// puts("");
	// std::random_shuffle(p + 1, p + 1 + n);
	std::sort(a + 1, a + 1 + n, cmp2);
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d %d\n", a[i].id, a[i].w);
	// }
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i].id);
	}
	return 0;
}
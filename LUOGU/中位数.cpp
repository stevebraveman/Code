#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <queue>
#define MAXN 100010
int n, m, l, a[MAXN];
std::priority_queue <int> q1, q2;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (a[1] > a[2]) {
		q1.push(a[2]);
		q2.push(-a[1]);
	}
	else {
		q1.push(a[1]);
		q2.push(-a[2]);
	}
	printf("%d\n", a[1]);
	for (int i = 3; i <= n; i++) {
		// printf("%d\n", i);
		if (a[i] > q1.top()) {
			q2.push(-a[i]);
		}
		else {
			q1.push(a[i]);
		}
		while ((int)(q2.size() - q1.size()) > 1) {
			int b = q2.top();
			b = -b;
			q2.pop();
			q1.push(b);
		}
		// printf("%d\n", q1.size() - q2.size());
		while ((int)(q1.size() - q2.size()) > 1) {
			int b = q1.top();
			// printf("OK\n");
			q1.pop();
			q2.push(-b);
		}
		// puts("OK");
		if (i & 1) {
			printf("%d\n", (q1.size() > q2.size()) ? q1.top() : -q2.top());
		}
	}
}
/*
7
1 3 5 7 9 11 6
 */
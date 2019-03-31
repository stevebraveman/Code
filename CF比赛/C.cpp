#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
int n, l, r;
int f[200001], a[200001];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
	}
	r = n + 1;
	std::sort(f + 1, f + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			l++;
			a[l] = f[i];
		}
		else {
			r--;
			a[r] = f[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
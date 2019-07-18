#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAXN 100010
std::vector <double> v[2];
int T, a[MAXN], n;
double b[MAXN];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> b[i];
			v[a[i]].push_back(b[i]);
		}
		sort(v[0].begin(), v[0].end());
		sort(v[1].begin(), v[1].end());
		for (int i = 0; i < (int)v[0].size(); i++) {
			std::cout << v[0][i] << " ";
		}
		puts("");
		for (int i = 0; i < (int)v[1].size(); i++) {
			std::cout << v[1][i] << " ";
		}
		puts("");
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAXN 100010
#define SQMAXN 350
#define INF 0x7fffffff
std::vector<int> v[350];
int a[MAXN], b[MAXN], n, sq, bl[MAXN], top[350];
void bubblesort(int p) {
	for (int i = 0; i < (int)v[p].size() - 1; i++) {
		bool flag = 0;
		for (int j = 0; j < (int)v[p].size() - i - 1; j++) {
			if (v[p][j] > v[p][j + 1]) {
				flag = 1;
				int t = v[p][j];
				v[p][j] = v[p][j + 1];
				v[p][j + 1] = t;
			}
		}
		if (flag == 0) break;
	}
	v[p].push_back(INF);
}
void sort() {
	for (int i = 1; i <= bl[n]; i++) {
		bubblesort(i);
	}
	int mina = INF, minj;
	for (int i = 1; i <= n; i++) {
		mina = INF;
		minj = 0;
		for (int j = 1; j <= bl[n]; j++) {
			if (mina > v[j][top[j]]) {
				mina = v[j][top[j]];
				minj = j;
			}
		}
		b[i] = mina;
		top[minj]++;
	}
}
int main() {
	scanf("%d", &n);
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		bl[i] = (i - 1) / sq + 1;
	}
	for (int i = 1; i <= n; i++) {
		v[bl[i]].push_back(a[i]);
	}
	sort();
	for (int i = 1; i <= n; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}
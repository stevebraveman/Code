#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000100
char s[MAXN];
int sa[MAXN], tempra[MAXN], n, m, b[MAXN], a[MAXN], num, y[MAXN];
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	m = 150;
	for (int i = 1; i <= n; i++) {
		s[i + n] = s[i];
	}
	n *= 2;
	for (int i = 1; i <= n; i++) {
		a[i] = (int)s[i];
		b[a[i]]++;
	}
	for (int i = 2; i <= m; i++) {
		b[i] += b[i - 1];
	}
	for (int i = n; i >= 1; i--) {
		sa[b[a[i]]--] = i;
	}
	for (int k = 1; k <= n; k <<= 1) {
		num = 0;
		for (int i = n - k + 1; i <= n; i++) {
			y[++num] = i;
		}
		for (int i = 1; i <= n; i++) {
			if (sa[i] > k) {
				y[++num] = sa[i] - k;
			}
		}
		for (int i = 1; i <= m; i++) {
			b[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			b[a[i]]++;
		}
		for (int i = 2; i <= m; i++) {
			b[i] += b[i - 1];
		}
		for (int i = n; i >= 1; i--) {
			sa[b[a[y[i]]]--] = y[i];
			y[i] = 0;
		}
		std::swap(a, y);
		a[sa[1]] = 1;
		num = 1;
		for (int i = 2; i <= n; i++) {
			a[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++num;
		}
		if (num == n) break;
		m = num;
	}
	for (int i = 1; i <= n; i++) {
		if (sa[i] + n / 2 > n) continue;
		printf("%c", s[sa[i] + n / 2 - 1]);
	}
}
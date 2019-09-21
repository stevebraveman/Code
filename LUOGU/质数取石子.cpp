#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 20000
#define INF 0x7fffffff
#define re register
bool chk[MAXN + 2];
int p[MAXN + 2] , tot;
inline int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
void prime() {
	for (re int i = 2 ; i <= MAXN ; i++) {
		if (!chk[i]) {
			p[++tot] = i;
		}
		for (re int j = 1 ; j <= tot && i * p[j] <= MAXN ; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j] == 0) {
				break;
			}
		}
	}
}
int n , x , g[MAXN] , f[MAXN];
int main() {
	prime();
	for (int i = 0 ; i <= 20000 ; i++) {
		f[i] = -1;
	}
	g[0] = g[1] = 0;
	for (re int i = 2 ; i <= MAXN ; i++) {
		for (re int j = tot ; j >= 1 ; j--) {
			if (p[j] <= i) {
				if (f[i - p[j]] == -1) {
					if (f[i] == -1) {
						f[i] = INF;
					}
					f[i] = min(f[i] , g[i - p[j]] + 1);
				}
			}
		}
		if (f[i] == -1) {
			for (re int j = tot ; j >= 1 ; j--) {
				if (p[j] <= i && f[i - p[j]] > 0) {
					g[i] = max(g[i] , f[i - p[j]] + 1);
				}
			}
		}
	}
	scanf("%d" , &n);
	for (re int i = 1 ; i <= n ; i++) {
		scanf("%d" , &x);
		printf("%d\n" , f[x]);
	}
}
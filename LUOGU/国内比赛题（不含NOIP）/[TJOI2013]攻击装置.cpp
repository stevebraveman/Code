#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 40020
#define re register
namespace STman {
	template <typename Tp>
	inline void read(Tp &x) {
		#define C getchar()
		Tp f = 1;x = 0;
		char k = C;
		while (k < '0' || k > '9') {if (k == '-') f = -1; k = C;}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0'; k = C;}
		x = x * f;
		#undef C
	}
	template <typename Tp>
	inline void write(Tp x) {
		if (x < 0) putchar('-') , x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
	template <typename Tp>
	inline Tp max(Tp a, Tp b) {
		if (a > b) return a;
		else return b;
	}
	template <typename Tp>
	inline Tp min(Tp a, Tp b) {
		if (a < b) return a;
		else return b;
	}
	template <typename Tp>
	inline void swap(Tp &a, Tp &b) {
		Tp t = a;
		a = b;
		b = t;
	}
	template <typename Tp>
	inline Tp abs(Tp &a) {
		if (a < 0) return -a;
		else return a;
	}
	inline void sp() {
		putchar(32);
	}
	inline void et() {
		putchar(10);
	}
}
using namespace STman;
struct Edge {
	int v, nx;
}e[MAXN * 12];
int head[MAXN], ecnt, n, m, tot, mtch[MAXN], ma;
int dx[] = {0, -1, -2, 1, 2, -1, -2, 1, 2}, dy[] = {0, -2, -1, -2, -1, 2, 1, 2, 1};
bool vis[MAXN], mp[302][302];
char s[MAXN];
inline int z(int i, int j) {
	return (i - 1) * n + j;
}
inline void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
bool Hungary(int k) {
	for (re int i = head[k]; i; i = e[i].nx) {
		int to = e[i].v;
		if (!vis[to]) {
			vis[to] = 1;
			if (!mtch[to] || Hungary(mtch[to])) {
				mtch[to] = k;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	read(n);
	for (re int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (re int j = 1; j <= n; j++) {
			if (s[j] == '0') {
				mp[i][j] = 1;
				tot++;
			}
		}
	}
	for (re int i = 1; i <= n; i++) {
		for (re int j = 1; j <= n; j++) {
			if (mp[i][j]) {
				for (int k = 1; k <= 8; k++) {
					int tx = i + dx[k], ty = j + dy[k];
					if (tx > n || tx < 1 || ty > n || ty < 1 || !mp[tx][ty]) continue;
					add(z(i, j), z(tx, ty));
				}
			}
		}
	}
	for (re int i = 1; i <= n; i++) {
		for (re int j = 1; j <= n; j++) {
			if (mp[i][j]) {
				memset(vis, 0, sizeof(vis));
				if (Hungary(z(i, j))) ma++;
			}
		}
	}
	write(tot - (ma >> 1));
	return 0;
}
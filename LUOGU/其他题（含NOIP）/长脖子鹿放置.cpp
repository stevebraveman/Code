#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 1000010
#define re register
namespace STman {
	inline char gc(){
		#ifdef ONLINE_JUDGE
			static char now[1 << 16], *S, *T;
			if (T == S) {T = (S = now) + fread(now, 1, 1 << 16, stdin); if (T == S) return EOF;}
			return *S++;
		#else 
			return getchar();
		#endif
	}
	template <typename Tp>
	inline void read(Tp &x) {
		Tp f = 1;x = 0;
		char k = gc();
		while (k < '0' || k > '9') {if (k == '-') f = -1;k = gc();}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0';k = gc();}
		x = x * f;
	}
	template <typename Tp>
	inline void write(Tp x) {
		if (x < 0) putchar('-') , x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
	template <typename Tp>
	inline Tp max(Tp a , Tp b) {
		if (a > b) return a;
		else return b;
	}
	template <typename Tp>
	inline Tp min(Tp a , Tp b) {
		if (a < b) return a;
		else return b;
	}
	template <typename Tp>
	inline void swap(Tp &a , Tp &b) {
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
}e[MAXN];
int head[MAXN], ecnt, n, m, h, G[210][210], x, y, ans, tot, vis[MAXN], mtch[MAXN], cnt;
int dx[] = {0, -1, -3, 1, 3, -1, -3, 1, 3}, dy[] = {0, -3, -1, -3, -1, 3, 1, 3, 1};
inline int g(re int i, re int j) {
	return (i - 1) * m + j;
}
inline void add(re int f, re int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
int Hungary(re int k, re int t) {
	for (re int i = head[k]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] != t) {
			vis[to] = t;
			if (!mtch[to] || Hungary(mtch[to], t)) {
				mtch[to] = k;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	read(n), read(m), read(h);
	for (re int i = 1; i <= h; i++) {
		read(x), read(y);
		G[x][y] = 1;
	}
	for (re int i = 1; i <= n; i += 2) {
		for (re int j = 1; j <= m; j++) {
			if(!G[i][j]) {
				for (re int k = 1; k <= 8; k++) {
					int tx = i + dx[k], ty = j + dy[k];
					if (tx > n || tx < 1 || ty > m || ty < 1 || G[tx][ty]) continue;
					add((i - 1) * m + j, (tx - 1) * m + ty);
				}
			}
		}
	}
	for (re int i = 1; i <= n; i += 2) {
		for (re int j = 1; j <= m; j++) {
			if (!G[i][j]) {
				if (Hungary((i - 1) * m + j, ++cnt)) {
					ans++;
				}
			}
		}
	}
	write(n * m - h - ans);
	return 0;
}
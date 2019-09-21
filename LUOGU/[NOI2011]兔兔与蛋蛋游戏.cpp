#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100101
namespace STman {
	template <typename Tp>
	inline void read(Tp &x) {
	#define C getchar()
		Tp f = 1;
		x = 0;
		char k = C;
		while (k < '0' || k > '9') {
			if (k == '-') f = -1;
			k = C;
		}
		while (k >= '0' && k <= '9') {
			x = x * 10 + k - '0';
			k = C;
		}
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
		b = a;
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
int head[MAXN], mch[MAXN], ecnt, vis[MAXN / 50], n, m, g[50][50], k, x, y, tot, a[50][50], ma, ans;
bool wa[MAXN], b[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
bool Hungary(int k, int t) {
	if (wa[k]) return 0;
	for (int i = head[k]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] != t && !wa[to]) {
			vis[to] = t;
			if (!mch[to] || Hungary(mch[to], t)) {
				mch[to] = k;
				mch[k] = to;
				return 1;
			}
		}
	}
	return 0;
}

char s[110];
int main() {
	read(n), read(m);
	memset(g, 0, sizeof(g));
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++) {
			if (s[j] == 'O') g[i][j] = 1;
			if (s[j] == 'X') g[i][j] = 2;
			if (s[j] == '.') g[i][j] = 2, x = i, y = j;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j] == 1 ^ (((i + j) & 1) == ((x + y) & 1))) {
				a[i][j] = ++tot;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!a[i][j]) continue;
			if (a[i + 1][j]) {
				add(a[i][j], a[i + 1][j]);
				add(a[i + 1][j], a[i][j]);
			}
			if (a[i][j + 1]) {
				add(a[i][j], a[i][j + 1]);
				add(a[i][j + 1], a[i][j]);
			}
		}
	}
	for (int i = 1; i <= tot; i++) {
		if (!mch[i]) Hungary(i, i);
	}
	read(k);
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= k << 1; i++) {
		int f = a[x][y];
		wa[f] = 1;
		if (mch[f]) {
			ma = mch[f];
			mch[ma] = mch[f] = 0;
			memset(vis, 0, sizeof(vis));
			b[i] = (!Hungary(ma, ma));
		}
		read(x), read(y);
	}
	for (int i = 1; i <= k; i++) {
		ans += (b[i * 2 - 1] & b[i * 2]);
	}
	write(ans), et();
	for (int i = 1; i <= k; i++) {
		if (b[i * 2 - 1] & b[i * 2]) {
			write(i), et();
		}
	}
	return 0;
}
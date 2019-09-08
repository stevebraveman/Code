#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 500010
#define INF 0x7fffffffffLL
#define int long long
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
	int v, w, nx;
}e[MAXN];
int head[MAXN];
bool vis[MAXN];
int ecnt, n, m = INF, x, y, z, dis[MAXN], l, r, a[MAXN], ans, k, g;
inline void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
inline void spfa(int s) {
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	std::queue <int> q;
	dis[s] = 0;
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		vis[f] = 0;
		for (int i = head[f]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[to] + e[i].w) {
				dis[to] = dis[to] + e[i].w;
				if (!vis[to]) {
					q.push(to);
					vis[to] = 1;
				}
			}
		}
	}
}
signed main() {
	read(n), read(l), read(r);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		m = min(a[i], m);
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j <= a[i]; j++) {
			int nxt = i + a[j];
			add(i, nxt % m, nxt / m);
		}
	}
	spfa(0);
	for (int i = 0; i < m; i++) {
		if (l * dis[i] * m + i <= r) {
			k = max(dis[i] * m + i, l),g = r;
		}
		if (k / m < r / m) {
			ans += k / m - r / m - 1;
			if (k <= k / m * m + i && k / m * m + i <= g) ans++;
			if (k <= r / m * m + i && k / m * m + i <= g) ans++;
		}
	}
	printf("%d", ans);
}

#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cstdio>
#define MAXN 100010
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
int a[MAXN], n, m, head[MAXN], ecnt, x, y, cnt = 1, cx[MAXN], vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
std::stack <int> s;
void dfs(int k) {
	s.push(k);
	vis[k] = 1;
	while (!s.empty()) {
		int u = s.top();
		s.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (vis[to] != 0) continue;
			vis[to] = ++cnt;
			s.push(to);
		}
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(x), read(y);
		add(x, y);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		write(vis[i]), sp();
	}
	return 0;
}
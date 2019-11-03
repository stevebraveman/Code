// #pragma comment(linker, "/STACK:102400000,102400000") 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 3000000
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
	int nx, v;
}e[MAXN << 1];
int dfn[MAXN], ecnt, low[MAXN], st[MAXN], top, head[MAXN], tim, cnt, size[MAXN], _siz, a[MAXN], ans;
void add(int f, int t) {
	e[++ecnt] = (Edge) {head[f], t};
	head[f] = ecnt;
}
void tarjan(int u, int fa) {
	low[u] = dfn[u] = ++tim;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			st[++top] = v;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				cnt++;
				do {
					size[cnt]++;
					_siz++;
				} while (st[top--] != v);
				if (size[cnt] == 1) {
					size[cnt--]--;
					_siz--;
				}
				else {
					size[cnt]++;
					_siz++;
				}
			}
		}
		else if (v != fa) low[u] = min(low[u], dfn[v]);
	}
}
bool cmp(int x, int y) {
	return size[x] > size[y];
}
int n, m, k, x, y;
int main() {
	read(n), read(m), read(k);
	for (int i = 1; i <= m; i++) {
		read(x), read(y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			tarjan(i, 0);
			ans++;
		}
	}
	if (k >= m - _siz) {
		k -= m - _siz;
		ans += m - _siz;
	}
	else {
		ans += k;
		k = 0;
		write(ans);
		et();
		return 0;
	}
	for (int i = 1; i <= cnt; i++) {
		a[i] = i;
	}
	std::sort(a + 1, a + 1 + cnt, cmp);
	for (int i = 1; i <= cnt; i++) {
		if (k >= size[a[i]]) {
			k -= size[a[i]];
			ans += size[a[i]] - 1;
		}
		else {
			ans += max(k - 1, 0);
			break;
		}
	}
	write(ans), et();
}
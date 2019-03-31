#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 11000
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
int head[MAXN], ecnt, n, tim, num, in[MAXN], m, u, v, st[MAXN], dfn[MAXN], low[MAXN], top, t;
bool fu, fv, vis[MAXN];
char a[10], b[10];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++top] = u;
	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		num++;
		int v;
		do {
			v = st[top];
			top--;
			in[v] = num;
			vis[v] = 0;
		} while (u != v);
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(head, 0, sizeof(head));
		memset(in, 0, sizeof(in));
		memset(vis, 0, sizeof(vis));
		memset(st, 0, sizeof(st));
		memset(low, 0, sizeof(low));
		memset(dfn, 0, sizeof(dfn));
		memset(e, 0, sizeof(e));
		ecnt = 0, tim = 0, top = 0, num = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			std::cin >> a >> b;
			if (a[0] == 'h') fu = 0;
			if (a[0] == 'm') fu = 1;
			if (b[0] == 'h') fv = 0;
			if (b[0] == 'm') fv = 1;
			u = 0;
			v = 0;
			for (int j = 1; j < strlen(a); j++) {
				u = u * 10 + a[j] - '0';
			}
			for (int j = 1; j < strlen(b); j++) {
				v = v * 10 + b[j] - '0';
			}
			add(u + n * (fu & 1), v + n * (fv ^ 1));
			add(v + n * (fv & 1), u + n * (fu ^ 1));
		}
		for (int i = 1; i <= n * 2; i++) {
			if (!dfn[i]) tarjan(i);
		}
		bool flag = 0;
		for (int i = 1; i <= n; i++) {
			if (in[i] == in[i + n]) {
				puts("BAD");
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			puts("GOOD");
		}
	}
}
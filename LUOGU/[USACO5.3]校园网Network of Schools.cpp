#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5000010
namespace STman {
	template <typename Tp>
	inline void read(Tp &x) {
		#define C getchar()
		Tp f = 1;x = 0;
		char k = C;
		while (k < '0' || k > '9') {if (k == '-') f = -1;k = C;}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0';k = C;}
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
	int v , nx;
}e[MAXN * 4];
int dfn[MAXN] , tot , m , ecnt , st[MAXN] , out[MAXN] , smen;
int hd , in[MAXN] , low[MAXN] , en[MAXN] , head[MAXN] , tim , smout , n;
bool vis[MAXN];
void add(int f , int t) {
	e[++ecnt] = (Edge) {t , head[f]};
	head[f] = ecnt;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	st[++hd] = u;
	vis[u] = 1;
	for (int i = head[u] ; i ; i = e[i].nx) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u] , low[v]);
		}
		else if (vis[v]) {
			low[u] = min(dfn[v] , low[u]);
		}
	}
	if (low[u] == dfn[u]) {
		tot++;
		int v;
		do {
			v = st[hd--];
			vis[v] = 0;
			in[v] = tot;
		} while(v != u);
	}
}
int main() {
	read(n);
	for (int i = 1 ; i <= n ; i++) {
		read(m);
		while (m != 0) {
			add(i , m);
			read(m);
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		if (!dfn[i]) {
			tarjan(i);
		}
	}
	for (int i = n ; i >= 1 ; i--) {
		for (int j = head[i] ; j ; j = e[j].nx) {
			int to = e[j].v;
			if (in[to] != in[i]) {
				out[in[i]] = 1;
				en[in[to]] = 1;
			}
		}
	}
	for (int i = 1 ; i <= tot ; i++) {
		smen += en[i] == 1 ? 0 : 1;
		smout += out[i] == 1 ? 0 : 1;
	}
	if (tot == 1) {
		printf("1\n0");
		return 0;
	}
	printf("%d\n%d" , smen , max(smen , smout));
}
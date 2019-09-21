#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 600010
#define re register
namespace STman {
	template <typename Tp>
	inline void read(Tp &x) {
		Tp f = 1;x = 0;
		char k = getchar();
		while (k < '0' || k > '9') {if (k == '-') f = -1;k = getchar();}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0';k = getchar();}
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
static int tr[MAXN * 24][2], latest[MAXN * 24], s[MAXN], r[MAXN], n, m, tot;
void ins(int i, int k, int p, int q) {
	if (k < 0) {
		latest[q] = i;
		return;
	}
	int c = s[i] >> k & 1;
	if (p) tr[q][c ^ 1] = tr[p][c ^ 1];
	tr[q][c] = ++tot;
	ins(i, k - 1, tr[p][c], tr[q][c]);
	latest[q] = max(latest[tr[q][0]], latest[tr[q][1]]);
}
int ask(int now, int val, int k, int limit) {
	if (k < 0) return s[latest[now]] ^ val;
	int c = val >> k & 1;
	if (latest[tr[now][c ^ 1]] >= limit) return ask(tr[now][c ^ 1], val, k - 1, limit);
	else ask(tr[now][c], val, k - 1, limit);
}
int main() {
	// scanf("%d%d", &n, &m);
	read(n), read(m);
	latest[0] = -1;
	r[0] = ++tot;
	ins(0, 25, 0, r[0]);
	for (re int i = 1; i <= n; i++) {
		int x;
		// scanf("%d", &x);
		read(x);
		s[i] = s[i - 1] ^ x;
		r[i] = ++tot;
		ins(i, 25, r[i - 1], r[i]);
	}
	for (re int i = 1; i <= m; i++) {
		char op[2];
		scanf("%s", op);
		if (op[0] == 'A') {
			static int x;
			// scanf("%d", &x);
			read(x);
			r[++n] = ++tot;
			s[n] = s[n - 1] ^ x;
			ins(n, 25, r[n - 1], r[n]);
		}
		else {
			static int l, ri, x;
			// scanf("%d%d%d", &l, &ri, &x);
			read(l), read(ri), read(x);
			write(ask(r[ri - 1], x ^ s[n], 25, l - 1)), et();
			// printf("%d\n", ask(r[ri - 1], x ^ s[n], 25, l - 1));
		}
	}
}
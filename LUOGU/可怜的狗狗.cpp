#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 3000010
#define INF 100000000
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
struct rec {
	int op, x, y, z;
}q[MAXN << 1], lq[MAXN << 1], rq[MAXN << 1];
int n, m, t, c[MAXN], ans[MAXN], a[MAXN], b[MAXN];
int ask(int x) {
	int y = 0;
	for (; x; x -= x & -x) y += c[x];
	return y;
}
void change(int x, int y) {
	for (; x <= n; x += x & -x) c[x] += y;
}
void solve(int lval, int rval, int st, int ed) {
	if (st > ed) return;
	if (lval == rval) {
		for (int i = st; i <= ed; i++) {
			if (q[i].op > 0) ans[q[i].op] = lval;
		}
		return;
	}
	int mid = (lval + rval) >> 1;
	int lt = 0, rt = 0;
	for (int i = st; i <= ed; i++) {
		if (q[i].op == 0) {
			if (q[i].y <= mid) change(q[i].x, 1), lq[++lt] = q[i];
			else rq[++rt] = q[i];
		}
		else {
			int cnt = ask(q[i].y) - ask(q[i].x - 1);
			if (cnt >= q[i].z) lq[++lt] = q[i];
			else q[i].z -= cnt, rq[++rt] = q[i];
		}
	}
	for (int i = ed; i >= st; i--) {
		if (q[i].op == 0 && q[i].y <= mid) change(q[i].x, -1);
	}
	for (int i = 1; i <= lt; i++) q[st + i - 1] = lq[i];
	for (int i = 1; i <= rt; i++) q[st + lt + i - 1] = rq[i];
	solve(lval, mid, st, st + lt - 1);
	solve(mid + 1, rval, st + lt, ed);
}
int l, r, k;
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		int val;
		read(val);
		q[++t].op = 0, q[t].x = i, q[t].y = val;
	}
	for (int i = 1; i <= m; i++) {
		read(l), read(r), read(k);
		q[++t].op = i, q[t].x = l, q[t].y = r, q[t].z = k;
	}
	solve(-INF, INF, 1, t);
	for (int i = 1; i <= m; i++) {
		write(ans[i]), et();
	}
}
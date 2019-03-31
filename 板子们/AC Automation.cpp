#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAXN 1000101
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
struct AC_Auto {
	int te[MAXN][26], cnt, e[MAXN], f[MAXN];
	void ins(char *s) {
		int p = 0;
		for (int i = 0; s[i]; i++) {
			int k = s[i] - 'a';
			if (!te[p][k]) te[p][k] = ++cnt;
			p = te[p][k];
		}
		e[p]++;
	}
	void build() {
		std::queue <int> q;
		memset(f, 0, sizeof(f));
		for (int i = 0; i < 26; i++) {
			if (te[0][i]) {
				q.push(te[0][i]);
			}
		}
		while (!q.empty()) {
			int k = q.front();
			q.pop();
			for (int i = 0; i < 26; i++) {
				if (te[k][i]) {
					f[te[k][i]] = te[f[k]][i];
					q.push(te[k][i]);
				}
				else te[k][i] = te[f[k]][i];
			}
		}
	}
	int query(char *t) {
		int p = 0, res = 0;
		for (int i = 0; t[i]; i++) {
			p = te[p][t[i] - 'a'];
			for (int j = p; j && ~e[j]; j = f[j]) {
				res += e[j], e[j] = -1;
			}
		}
		return res;
	}
} mach;
char s[MAXN], a[MAXN];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		mach.ins(s);
	}
	mach.build();
	scanf("%s", a);
	write(mach.query(a));
}
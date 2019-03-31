#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 2147483647
#define MAXN 1100
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
int n, la[MAXN], lb[MAXN], mch[MAXN], w[110][110], delta;
bool va[MAXN], vb[MAXN];
bool bgm(int k) {
	va[k] = 1;
	for (int i = 1; i <= n; i++) {
		if (!vb[i]) {
			if (la[k] + lb[i] - w[k][i] == 0) {
				vb[i] = 1;
				if (!mch[i] || bgm(mch[i])) {
					mch[i] = k;
					return 1;
				}
			}
			else delta = min(delta, la[k] + lb[i] - w[k][i]);
		}
	}
	return 0;
}
int KM() {
	for (int i = 1; i <= n; i++) {
		la[i] = -INF;
		lb[i] = 0;
		for (int j = 1; j <= n; j++) {
			la[i] = max(la[i], w[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		while (1) {
			memset(va, 0, sizeof(va));
			memset(vb, 0, sizeof(vb));
			delta = INF;
			if (bgm(i)) break;
			for (int j = 1; j <= n; j++) {
				if (va[j]) la[j] -= delta;
				if (vb[j]) lb[j] += delta;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += w[mch[i]][i];
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &w[i][j]);
			w[i][j] = -w[i][j];
		}
	}
	printf("%d\n", -KM());
	memset(la, 0, sizeof(la));
	memset(lb, 0, sizeof(lb));
	memset(va, 0, sizeof(va));
	memset(vb, 0, sizeof(vb));
	memset(mch, 0, sizeof(mch));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			w[i][j] = -w[i][j];
		}
	}
	printf("%d", KM());
	return 0;
}
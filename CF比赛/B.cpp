#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define MAXN 1000100
namespace STman {
	inline char gc(){
		// #ifdef ONLINE_JUDGE
		// 	static char now[1 << 16], *S, *T;
		// 	if (T == S) {T = (S = now) + fread(now, 1, 1 << 16, stdin); if (T == S) return EOF;}
		// 	return *S++;
		// #else 
			return getchar();
		// #endif
	}
	template <typename Tp>
	inline void read(Tp &x) {
		Tp f = 1;x = 0;
		char k = gc();
		while (k < '0' || k > '9') {if (k == '-') f = -1; k = gc();}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0'; k = gc();}
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
int sum[MAXN], c[MAXN];
int n, m, d, tot, ans, T;
void add(int x) {
	if(!sum[c[x]]) ++tot;
	sum[c[x]]++;
}
void del(int x) {
	if(sum[c[x]] == 1) --tot;
	sum[c[x]]--;
}
int main() {
	read(T);
	while(T--) {
		read(n), read(m), read(d);
		for(int i = 1; i <= n; i++) {
			read(c[i]);
		}
		ans = 0x7fffffff;
		tot = 0;
		for(int i = 1; i <= d; ++i) {
			add(i);
		}
		ans = min(ans, tot);
		for(int i = d + 1; i <= n; i++) {
			del(i - d);
			add(i);
			ans = min(ans, tot);
		}
		for(int i = 1; i <= m; i++) {
			sum[i] = 0;
		}
		write(ans), et();
	}
	return 0;
}

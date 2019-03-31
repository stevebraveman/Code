#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
char a[1000010], b[1000010];
int la, lb, j, nx[1000010];
int main() {
	scanf("%s%s", a + 1, b + 1);
	la = strlen(a + 1), lb = strlen(b + 1);
	nx[1] = 0;
	for (int i = 2; i <= lb; i++) {
		while (j > 0 && b[i] != b[j + 1]) j = nx[j];
		if (b[i] == b[j + 1]) j++;
		nx[i] = j;
	}
	j = 0;
	for (int i = 1; i <= la; i++) {
		while (j > 0 && a[i] != b[j + 1]) j = nx[j];
		if (a[i] == b[j + 1]) j++;
		if (j == lb) {
			write(i - lb + 1), et(), j = nx[j];
		}
	}
	for (int i = 1; i <= lb; i++) {
		write(nx[i]), sp();
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAXN 1000100
#define ll long long
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
struct Heap{
	std::priority_queue<int> x, y;
	void push(int a) {x.push(a);}   
	void del(int a) {y.push(a);}
	int top() {while(!y.empty() && x.top() == y.top()) y.pop(), x.pop(); return x.top(); }
} q;
int a[MAXN], n, m, T, x, y;
ll tot = 0;
int main() {
	read(n), read(m), read(T);
	ll tot = 0;
	for(int i = 1; i <= n; ++i) {
		read(a[i]);
		tot += a[i];
		q.push(a[i]);
	}
	printf("%lld\n", max((ll)q.top(), (tot + m - 1) / m));
	while (T--){
		read(x), read(y);
		q.del(a[x]);
		tot += y - a[x];
		q.push(a[x] = y);
		printf("%lld\n", max((ll)q.top(), (tot + m - 1) / m));
	}
}
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
struct point {
	int x, y;
};
std::queue <point> q;
int mp[1100][1100], n, m, sx, sy, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, cnt;
int vis[100101];
void bfs(int x, int y) {
	q.push((point) {x, y});
	while (!q.empty()) {
		point p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = p.x + dx[i], ty = p.y + dy[i];
			if ((mp[tx][ty] ^ mp[p.x][p.y]) == 1) {
				if (mp[tx][ty] ^ )
			}
		}
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &mp[i][j]);
		}
	}
	while (m--) {
		read(sx), read(sy);
		bfs(sx, sy, ++cnt);
	}
}
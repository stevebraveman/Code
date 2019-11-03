#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXN 100005
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
#define MOD 1000000007
int f[MAXN][11],g[MAXN][11],h[MAXN],k,num;
struct edge {
	int pre,to;
} e[MAXN<<1];
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (1LL * res * a) % MOD;
		b >>= 1;
		a = (1LL * a * a) % MOD;
	}
	return res % MOD;
}
int inv(int x) {
	return qpow(x, MOD - 2);
}
inline void add(int from,int to) {
	e[++num].pre=h[from],h[from]=num,e[num].to=to;
}
void dp(int node=1,int fa=0) {
	for(register int i=0; i<=k; ++i)g[node][i]=f[node][i]=1;
	for(register int i=h[node],x; i; i=e[i].pre) {
		x=e[i].to;
		if(x==fa)continue;
		dp(x,node);
		for(register int j=1; j<=k; ++j)f[node][j]+=f[x][j-1],g[node][j]=1ll*g[node][j]*g[x][j-1]%MOD;
	}
	for(register int i=1; i<=k; ++i)g[node][i]=1ll*g[node][i]*f[node][i]%MOD;
}
void _dp(int node=1,int fa=0) {
	if(node!=1)
		for(register int i=k; i; --i) {
			g[node][i]=1ll*g[node][i]*g[fa][i-1]%MOD*inv(f[node][i])%MOD;
			if(i>1)g[node][i]=1ll*g[node][i]*inv(g[node][i-2])%MOD*inv(f[fa][i-1])%MOD*(f[fa][i-1]-f[node][i-2])%MOD;
			f[node][i]+=f[fa][i-1];
			if(i>1)f[node][i]-=f[node][i-2];
			g[node][i]=1ll*g[node][i]*f[node][i]%MOD;
		}
	for(register int i=h[node],x; i; i=e[i].pre) {
		x=e[i].to;
		if(x==fa)continue;
		_dp(x,node);
	}
}
int n, x, y;
int main() {
	read(n);
	read(k);
	for(register int i=1; i<n; ++i) {
		read(x),read(y);
		add(x,y),add(y,x);
	}
	dp(),_dp();
	for(register int i=1; i<=n; ++i)printf("%d ",f[i][k]);
	puts("");
	for(register int i=1; i<=n; ++i)printf("%d ",g[i][k]);
	puts("");
}
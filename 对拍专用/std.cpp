#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define maxn 100010
#define re register
#define FOR(i, l, r) for(re int i = l; i <= r; ++i)
using namespace std;

int n, m, c, r ,t, x, y, z, cnt, now;
int a[maxn], b[maxn]; 
int main() {
	scanf("%d", &n);int last = n+1;
	FOR(i, 1, n) {
		scanf("%d", &x);
		if(x > last) continue;
		last = x; b[x] = ++cnt;
	}
	FOR(i, 1, n)
	  if(!b[i]) printf("%d ", ++cnt);
	  else  printf("%d ", b[i]);
}

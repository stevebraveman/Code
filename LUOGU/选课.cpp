#include<iostream>
#include<cstdio>
#define MAXN 502
using namespace std;
int a[MAXN][MAXN],n,m,p[MAXN],h[MAXN],cnt;
struct Edge {
	int to , pre;
} e[MAXN];
void add(int from,int to) {
	e[++cnt].pre = h[from];
	e[cnt].to = to;
	h[from] = cnt;
}
void Tree_dp(int p) {
	for(int i = h[p] ; i ; i = e[i].pre) {
		int go = e[i].to;
		Tree_dp(go);
		for(int j = m + 1 ; j >= 1 ; j--) {
			for(int k = 0 ; k < j ; k++) {
				a[p][j] = max(a[p][j] , a[go][k] + a[p][j - k]);
			}
		}
	}
}
int main() {
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++) {
		int x;
		scanf("%d%d" , &x , &a[i][1]);
		add(x , i);
	}
	Tree_dp(0);
	cout << a[0][m + 1];
	return 0;
}

#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#define MOD 1000000007
struct node{
	int nx, to, z;
}w[200001];
std::vector<int> g[1001][1001];
int f[1001][1001], head[100001];
int cnt, n, m, ans;
inline int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
inline void add(int x, int y, int z){
	w[++cnt] = (node) {head[x], y, z};
	head[x] = cnt;
}
void dfs(int x, int fa){
	for (int i = 1; i <= m; i++) {
		f[x][i] = 1;
	}
	for (int i = head[x]; i; i = w[i].nx){
		if (w[i].to != fa){
			dfs(w[i].to, x); 
			for (int j = 1; j <= m; j++) {
				if(j % w[i].z) {
					f[x][j] = 1ll * f[x][j] * f[w[i].to][0] % MOD;
					continue;
				}
				int t = f[w[i].to][0];
				for(int k = 0; k < g[j][w[i].z].size(); k++) 
					t = (t - f[w[i].to][g[j][w[i].z][k]]) % MOD;
				t = (t + MOD) % MOD;
				f[x][j] = 1ll * f[x][j] * t % MOD;
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		f[x][0] = (f[x][0] + f[x][i]) % MOD;
	}
}
int main(){
	int x, y, z;
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++){
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			g[i][gcd(i, j)].push_back(j);
	dfs(1, 0);
	printf("%d\n", f[1][0]);
	return 0;
}
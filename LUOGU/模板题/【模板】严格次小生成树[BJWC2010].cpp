#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
#define N 100010
ll n , m , cnt , ans , sum = 2000000000;
ll fa[N] , deep[N] , head[N] , l[N][20] , m1[N][20] , m2[N][20] , vis[3 * N] , quan[N];
ll max(ll a , ll b) {
	if (a > b) return a;
	else return b;
}
ll min(ll a , ll b) {
	if (a < b) return a;
	else return b;
}
struct node {
	ll x , y , v;
} f[3 * N];
struct Node {
	ll to , next , v;
} edge[2 * N];
bool cmp(node p , node q) {
	return p.v < q.v;
}
ll find(ll x) {
	if (fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
void add(ll x , ll y , ll z) {
	cnt++;
	edge[cnt].to = y;
	edge[cnt].next = head[x];
	edge[cnt].v = z;
	head[x] = cnt;
}
void kruscal() {
	ll ecnt = 0;
	std::sort(f + 1 , f + 1 + m , cmp);
	for (ll i = 1 ; i <= m ; i++) {
		ll x = find(f[i].x) , y = find(f[i].y);
		if (x != y) {
			fa[x] = y;
			ecnt++;
			ans += f[i].v;
			add(f[i].x , f[i].y , f[i].v);
			add(f[i].y , f[i].x , f[i].v);
			vis[i] = 1;
		}
		if (ecnt == n - 1) break;
	}
}
void dfs(ll k) {
	for (ll i = head[k] ; i ; i = edge[i].next) {
		ll v = edge[i].to;
		if (deep[v]) continue;
		deep[v] = deep[k] + 1;
		l[v][0] = k;
		m1[v][0] = edge[i].v;
		dfs(v);
	}
}
void init() {
	for (ll i = 1 ; i <= 19 ; i++) {
		for (ll j = 1 ; j <= n ; j++) {
			l[j][i] = l[l[j][i - 1]][i - 1];
			if (m1[j][i - 1] < m1[l[j][i - 1]][i - 1]) {
				m1[j][i] = m1[l[j][i - 1]][i - 1];
				m2[j][i] = max(m1[j][i - 1] , m2[l[j][i - 1]][i - 1]);
			}
			else if (m1[j][i - 1] > m1[l[j][i - 1]][i - 1]) {
				m1[j][i] = m1[j][i - 1];
				m2[j][i] = max(m1[l[j][i - 1]][i - 1] , m2[j][i - 1]);
			}
			else {
				m1[j][i] = m1[j][i - 1];
				m2[j][i] = max(m2[l[j][i - 1]][i - 1] , m2[j][i - 1]);
			}
		}
	}
}
void change(ll x , ll i , ll &qwe1 , ll &qwe2) {
	if(qwe1 < m1[x][i]) {
		qwe2 = max(qwe1 , m2[x][i]);
		qwe1 = m1[x][i];
	}
	else {
		qwe2 = max(qwe2 , m1[x][i]);
	}
}
ll lca(ll x , ll y , ll v) {
	ll qwe1 = 0 , qwe2 = 0;
	if (deep[x] < deep[y]) std::swap(x , y);
	for (ll i = 19 ; i >= 0 ; i--) {
		if(deep[l[x][i]] >= deep[y]) {
			change(x , i , qwe1 , qwe2);
			x=l[x][i];
		}
	}
	if (x == y) {
		if (qwe1 == v) return qwe2;
		return qwe1;
	}
	for (ll i = 19 ; i >= 0 ; i--)
		if (l[x][i] != l[y][i]) {
			change(x , i , qwe1 , qwe2);
			change(y , i , qwe1 , qwe2);
			x = l[x][i];
			y = l[y][i];
		}
	change(x , 0 , qwe1 , qwe2);
	change(y , 0 , qwe1 , qwe2);
	if (qwe1 == v) {
		return qwe2;
	}
	return qwe1;
}
int main() {
	scanf("%lld%lld" , &n , &m);
	for (ll i = 1 ; i <= n ; i++) {
		fa[i] = i;
	}
	for (ll i = 1 ; i <= m ; i++) {
		scanf("%lld%lld%lld" , &f[i].x , &f[i].y , &f[i].v);	
	}
	kruscal();
	deep[1] = 1;
	dfs(1);
	init();
	for (ll i = 1 ; i <= m ; i++) {
		if (vis[i]) continue;
		sum = min(sum , f[i].v - lca(f[i].x , f[i].y , f[i].v));
	}
	printf("%lld" , ans + sum);
	return 0;
}
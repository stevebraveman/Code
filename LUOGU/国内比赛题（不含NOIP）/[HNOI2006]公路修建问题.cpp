#include <iostream>
#include <cstdio>
#include <algorithm>
int fa[10002] , n , k , m;
struct Edge {
	int u , v , w1 , w2 , id , used;
}e[20002];
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
int min(int a , int b) {
	if (a < b) return a;
	else return b;
}
int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
void un(int a , int b) {
	a = find(a);
	b = find(b);
	fa[b] = a;
}
bool cmp1(Edge a , Edge b) {
	return a.w1 < b.w1;
}
bool cmp2(Edge a , Edge b) {
	return a.w2 < b.w2;
}
bool cmp3(Edge a , Edge b) {
	return a.id < b.id;
}
int kruskal() {
	int cnt = 0 , ans = 0 , t;
	std::sort(e + 1 , e + m , cmp1);
	for (int i = 1 ; i < m ; i++) {
		int u = e[i].u;
		int v = e[i].v;
		if (find(u) == find(v)) continue;
		else {
			un(u , v);
			ans = max(e[i].w1 , ans);
			cnt++;
			e[i].used = 1;
		}
		if (cnt == k){
			k = i;
			break;
		}
	}
	std::sort(e + k , e + m , cmp2);
	for (int i = k ; i < m ; i++) {
		int u = e[i].u;
		int v = e[i].v;
		if (find(u) == find(v)) continue;
		else {
			un(u , v);
			ans = max(ans , e[i].w2);
			e[i].used = 2;
		}
	}
	return ans;
}
int main() {
	scanf("%d%d%d" , &n , &k , &m);
	for(int i = 1 ; i < m ; i++) {
		scanf("%d%d%d%d" , &e[i].u , &e[i].v , &e[i].w1 , &e[i].w2);
		e[i].id = i;
	}
	for (int i = 1 ; i <= n ; i++) {
		fa[i] = i;
	}
	printf("%d\n" , kruskal());
	std::sort(e + 1 , e + m , cmp3);
	for (int i = 1 ; i < m ; i++) {
		if (e[i].used) {
			printf("%d %d\n" , e[i].id , e[i].used);
		}
	}
	return 0;
}
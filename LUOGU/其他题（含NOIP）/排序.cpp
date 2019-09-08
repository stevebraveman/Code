#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100011
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], x, y, ecnt, n, m, top, ent[MAXN], num;
int dfn[MAXN], st[MAXN], siz[MAXN], in[MAXN], tim, low[MAXN], nn, ht;
char p[5], sx[MAXN];
bool vis[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
int main() {
	std::queue <int> q;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%s", p);
		x = p[0] - 'A' + 1;
		y = p[2] - 'A' + 1;
		add(x, y);
		// printf("%d %d\n", x, y);
		ent[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!ent[i]) num++;
	}
	// puts("ok");
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
		// printf("%d", i);
	}
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d ", in[i]);
	// }
	// puts("");
	for (int i = 1; i <= nn; i++) {
		if (siz[i] > 1) {
			puts("Inconsistency found after 2 relations.");
			return 0;
		}
	}
	if (num > 1) {
		puts("Sorted sequence cannot be determined.");
		return 0;
	}
	// printf("Sorted sequence determined after 4 relations: ");
	for (int i = 1; i <= n; i++) {
		if (!ent[i]) {
			q.push(i);
			// printf("%d\n", i);
			break;
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		sx[++top] = u + 'A' - 1;
		// printf("%c", );
		// printf("%d\n", u);
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			ent[to]--;
			if (ent[to] == 0) {
				q.push(to);
			}
		}
	}
	printf("Sorted sequence determined after %d relations: %s", strlen(sx + 1), sx + 1);
}
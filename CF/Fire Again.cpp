#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 4000005
struct node {
	int x , y , h;
};
struct village {
	int x , y , h;
}v[MAXN];
int n , m , x , y , a , b , mp[2010][2100] , dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1} , vn, lst, ansx, ansy, cnt;
std::queue<node> q;
void bfs() {
	while (!q.empty()) {
		node f = q.front();
		q.pop();
		for (int i = 0 ; i < 4 ; i++) {
			int tx = f.x + dx[i] , ty = f.y + dy[i];
			if (tx > 0 && tx <= n && ty > 0 && ty <= m && mp[tx][ty] != -1) {
				if (mp[tx][ty] > 0) {
					v[mp[tx][ty]].h = f.h + 1;
					vn--;
					if (vn == 0) return;
				}
				mp[tx][ty] = -1;
				q.push((node){tx , ty , f.h + 1});
			}
		}
	}
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &a);
	for (int i = 1 ; i <= a ; i++) {
		scanf("%d%d", &x, &y);
		mp[x][y] = -1;
		q.push((node){x , y , 0});
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cnt++;
			v[cnt].x = i;
			v[cnt].y = j;
			if (mp[i][j] == -1) v[cnt].h = 0;
			else mp[i][j] = cnt;
		}
	}
	vn = cnt;
	bfs();
	for (int i = 1 ; i <= cnt ; i++) {
		if (lst <= v[i].h) {
			lst = v[i].h;
			ansx = v[i].x;
			ansy = v[i].y;
		}
	}
	printf("%d %d", ansx, ansy);
	fclose(stdin);
	fclose(stdout);
}
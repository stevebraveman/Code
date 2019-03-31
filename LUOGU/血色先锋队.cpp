#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 250005
struct node {
	int x , y , h;
};
struct village {
	int x , y , h;
}v[MAXN];
int n , m , x , y , a , b , mp[505][505] , dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1} , vn;
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
	scanf("%d%d%d%d" , &n , &m , &a , &b);
	for (int i = 1 ; i <= a ; i++) {
		scanf("%d%d" , &x , &y);
		mp[x][y] = -1;
		q.push((node){x , y , 0});
	}
	for (int i = 1 ; i <= b ; i++) {
		scanf("%d%d" , &v[i].x , &v[i].y);
		if (mp[v[i].x][v[i].y] == -1) {
			v[i].h = 0;
		}
		else mp[v[i].x][v[i].y] = i;
	}
	vn = b;
	bfs();
	for (int i = 1 ; i <= b ; i++) {
		printf("%d\n" , v[i].h);
	}
}
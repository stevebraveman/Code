#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
struct node {
	int x , y , sp;
};
int n , m , sx , sy , ex , ey , dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1} , mp[1001][1001];
char c;
void bfs() {
	std::queue <node> q;
	q.push((node){sx , sy , 0});
	while (!q.empty()) {
		node f = q.front();
		q.pop();
		for (int i = 0 ; i < 4 ; i++) {
			int tx = f.x + dx[i] , ty = f.x + dy[i];
			if ((tx > 0 && tx <= n) && (ty > 0 && ty <= m) && !mp[tx][ty]) {
				if (tx == ex && ty == ey) {
					printf("%d" , f.sp + 1);
					return;
				}
				q.push((node){tx , ty , f.sp + 1});
			}
		}
	}
	printf("No Way!");
}
int main() {
	freopen("data.in" , "r" , stdin);
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			std::cin >> c;
			if (c == '#') {
				mp[i][j] = 1;
			}
			if (c == 'm') {
				sx = i;
				sy = j;
			}
			if (c == 'c') {
				ex = i;
				ey = j;
			}
		}
	}
	bfs();
	return 0;
}
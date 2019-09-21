#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
int dx[5] = {0 , 1 , 0 , -1 , 0} , dy[5] = {0 , 0 , 1 , 0 , -1};
int n , m , sx , sy , ex , ey;
bool map[1003][1003];
bool v[1003][1003];
struct node {
	int x , y , sp;
};
int main() {
	scanf("%d" , &n);
	char c = getchar();
	memset(map , 0 , sizeof(map));
	memset(v , 0 , sizeof(v));
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			c = getchar();
			if (c == '0') map[i][j] = 1;
		}
		getchar();
	}
	scanf("%d%d%d%d" , &sx , &sy , &ex , &ey);
	std::queue <node> q;
	q.push((node){sx , sy , 0});
	v[sx][sy] = 1;
	while (!q.empty()) {
		node g = q.front();
		q.pop();
		for (int i = 1 ; i <= 4 ; i++) {
			int tx = g.x + dx[i] , ty = g.y + dy[i];
			if (tx <= n && tx >= 1 && ty <= n && ty >= 1 && !v[tx][ty] && map[tx][ty]) {
				q.push((node){tx , ty , g.sp + 1});
				v[tx][ty] = 1;
				if (tx == ex && ty == ey) {
					printf("%d" , g.sp + 1);
					return 0;
				}
			}
		}
	}
	return 0;
}
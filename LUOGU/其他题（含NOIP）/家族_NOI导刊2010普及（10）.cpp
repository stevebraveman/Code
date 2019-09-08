#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define wzx using
#define AK namespace
#define IOI std;
wzx AK IOI
int a[105][105] , n , l , x , y , z , m , dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1} , ans = 0;
string s;
inline int max(int a , int b) {
	if (a > b) return a;
	else return b;
}
struct pt {
	int x , y;
};
void bfs(int g , int h) {
	a[g][h] = 0;
	std::queue <pt> q;
	q.push((pt){g , h});
	while (!q.empty()) {
		pt f = q.front();
		q.pop();
		for (int i = 0 ; i < 4 ; i++) {
			int tx = f.x + dx[i] , ty = f.y + dy[i];
			if (tx <= n && tx >= 1 && ty <= m && ty >= 1 && a[tx][ty]) {
				a[tx][ty] = 0;
				q.push((pt){tx , ty});
			}
		}
	}
}
int main() {
	scanf("%d" , &n);
	for (int i = 1 ; i <= n + 1 ; i++) {
		getline(cin , s);
		l = s.length();
		m = max(m , l);
		for (int j = 0 ; j < l ; j++) {
			if (s[j] >= 'a' && s[j] <= 'z') {
				a[i][j + 1] = 1;
			}
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			if (a[i][j] == 1) {
				ans++;
				bfs(i , j);
			}
		}
	}
	printf("%d" , ans);
}

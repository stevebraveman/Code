#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
char s[20][20];
bool check() {
	for (int i = 0; i <= 15; i++) {
		bool v[16];
		memset(v, false, sizeof(v));
		for (int j = 0; j <= 15; j++) {
			v[s[i][j] - 'A'] = true;
		}
		for (int j = 0; j <= 15; j++) {
			if (!v[j]) {
				return false;
			}
		}
	}
	for (int i = 0; i <= 15; i++) {
		bool v[16];
		memset(v, false, sizeof(v));
		for (int j = 0; j <= 15; j++) {
			v[s[j][i] - 'A'] = true;
		}
		for (int j = 0; j <= 15; j++) {
			if (!v[j]) {
				return false;
			}
		}
	}
	for (int i = 0; i <= 15; i++) {
		bool v[16];
		memset(v, false, sizeof(v));
		for (int j = 0; j <= 15; j++) {
			v[s[i / 4 * 4 + j / 4][i % 4 * 4 + j % 4] - 'A'] = true;
		}
		for (int j = 0; j <= 15; j++) {
			if (!v[j]) {
				return false;
			}
		}
	}
	return true;
}

bool dfs(int x, int y) {
	if (x == 16 && y == 0) {
		return check();
	}
	if (s[x][y] == '?') {
		for (char i = 'A'; i <= 'P'; i++) {
			s[x][y] = i;
			if (dfs(x, y)) {
				return true;
			}
			s[x][y] = '?';
		}
		return false;
	} else {
		return dfs(x + (y + 1) / 16, (y + 1) % 16);
	}
}

void solve(int points) {
	for (int i = 0; i <= 15; i++) {
		scanf("%s", s[i]);
	}
	if (dfs(0, 0)) {
		for (int k = 0; k <= points - 1; k++) {
			for (int i = 0; i <= 15; i++) {
				printf("%s", s[i]);
			}
			printf("\n");
		}
	} else {
		for (int k = 0; k <= points - 1; k++) {
			printf("NO SOLUTION.\n");
		}
	}
}
int main() {
	solve(1);
	solve(2);
	solve(3);
	solve(4);
	return 0;
}

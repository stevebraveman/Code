#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 400010
int T, x, l, tot, g;
char s[MAXN];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
void pre() {
	while (l && s[l] == '#') {
		s[l--] = 0;
	}
}
int goahead() {
	int j = 0;
	for (j = 1; j <= l; j++) {
		if (s[j] == '*') {
			x++;
			s[j] = '.';
		}
		tot = max(tot, x);
		if (j + 1 <= l) {
			if (s[j + 1] == '#') {
				if (s[j + 2] == '*') continue;
				else if (s[j] == '#' && s[j + 2] != '*') break;
				else if (s[j] == '.') {
					if (!x) break;
					x--;
					s[j] = '*';
				}
			}
		}
	}
	return j;
}
void back(int j) {
	for (; j > 0; j--) {
		if (s[j] == '*') {
			++x;
			s[j] = '.';
		}
		tot = max(tot, x);
		if (j - 1 >= 1 && s[j - 1] == '#' && (!(j - 2 >= 1 && s[j - 2] == '*'))) {
			x--;
			s[j] = '*';
		}
		if (j + 2 <= l) {
			if (s[j] == '.' && s[j + 1] == '#' && s[j + 2] == '*') {
				if (x > 0) {
					x++;
					s[j + 2] = '.';
				}
			}
		}
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		l = strlen(s + 1);
		tot = x = 0;
		g = goahead();
		g = min(g, l);
		back(g);
		printf("%d\n", tot);
	}
	return 0;
}
/*
4
.*........#.#..
....#.*..*.*..#
.#*.***.**.#.**
......**..##..*
 */
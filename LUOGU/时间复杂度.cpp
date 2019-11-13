#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#define MAXN 100100
struct stack {
	int a[100005], head;
	void clear() {head = 0;}
	int top() {return a[head];}
	void pop() {head--;}
	void push(int x) {a[++head] = x;}
	bool empty() {if (head == 0) return 1; else return 0;}
	int size() {return head;}
}s;
bool digit(char a) {
	if (a >= '0' && a <= '9') return 1;
	else return 0;
}
int zh[MAXN], var, T, n, ans = 0, nm[10], tot = 0, la = 0, flagn = 0, le[MAXN], d1;
char xh, ed, a[10];
char b[105][110];
bool h[200];
int solve() {
	for (int i = 1; i <= n; i++) {
		if (b[i][1] == 'F') {
			var = b[i][3];
			if (h[var]) {
				return 3;
			}
			h[var] = 1;
			s.push((int)var);
		}
		if (b[i][1] == 'E') {
			if (s.empty()) return 3;
			h[s.top()] = 0;
			s.pop();
		}
	}
	if (!s.empty()) return 3;
	s.clear();
	int fzd = 0, y = 0;
	flagn = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i][1] == 'F') {
			if (flagn == 1) {
				y++;
			}
			if (flagn) continue;
			var = b[i][3];
			la = -1;
			for (int j = 4; j <= le[i]; j++) {
				if (b[i][j] == 'n' && la == -1) {
					la = 0;
					continue;
				}
				if (b[i][j] == 'n' && la == 0) {
					int o;
					if (s.empty()) o = 0;
					else o = s.top();
					s.push(o);
					break;
				}
				if (b[i][j] == 'n' && la > 0) {
					int o;
					if (s.empty()) o = 0;
					else o = s.top();
					s.push(o + 1);
					break;
				}
				if (digit(b[i][j])) {
					d1 = 0;
					while (digit(b[i][j])) {
						d1 = d1 * 10 + b[i][j] - '0';
						j++;
					}
					if (la == -1) {
						la = d1;
						continue;
					}
					if (la == 0) {
						flagn = 1;
						y++;
						continue;
					}
					if (la > d1) {
						flagn = 1;
						y++;
						continue;
					}
					if (la <= d1) {
						int o = s.top();
						s.push(o);
					}
				}
			}
		}
		if (b[i][1] == 'E') {
			if (flagn == 1) {
				y--;
				if (y == 0) {
					flagn = 0;
				}
				continue;
			}
			// printf("%d\n", s.top());
			fzd = std::max(fzd, s.top());
			s.pop();
		}
	}
	// printf("%d\n", fzd);
	// puts("OK");
	if (a[2] == '1') {
		if (fzd == 0) return 1;
		else return 2;
	}
	int ddf = 0;
	for (int i = 0; a[i]; i++) {
		if (digit(a[i])) {
			while (digit(a[i])) ddf = ddf * 10 + a[i] - '0', i++;
		}
	}
	if (ddf == fzd) return 1;
	else return 2;
}
int read(char *tp) {
	char c = getchar();
	// c = getchar();
	int top = 0;
	while ((c != ' ') && (c > 'Z' || c < 'A') && (c > 'z' || c < 'a') && (c > '9' || c < '0')) {c = getchar();}
	while ((c == ' ') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {tp[++top] = c; c = getchar();}
	return top;
	// tp[top + 1] = '\n';
}
int main() {
	scanf("%d", &T);
	while (T--) {
		s.clear();
		// s2.clear();
		memset(h, 0, sizeof(h));
		memset(b, 0, sizeof(b));
		scanf("%d", &n);
		scanf("%s", a);
		for (int i = 1 ; i <= n; i++) {
			int l = read(b[i]);
			// printf("%d\n", l);
			le[i] = l;
		}
		int g = solve();
		if (n & 1) g = 3;
		if (g == 1) {
			printf("Yes\n");
		}
		if (g == 2) {
			printf("No\n");
		}
		if (g == 3) {
			printf("ERR\n");
		}
	}
}
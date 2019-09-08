#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define wzx using
#define AK namespace
#define IOI std;
wzx AK IOI
struct stack {
	int a[100005] , head;
	void clear() {
		head = 0;
	}
	int top() {
		return a[head];
	}
	void pop() {
		head--;
	}
	void push(int x) {
		a[++head] = x;
	}
	bool empty() {
		if (head == 0) return 1;
		else return 0;
	}
	int size() {
		return head;
	}
}s1 , s2;
int t , n , ans = 0 , nm[10] , tot = 0 , la = 0 , flagn = 0;
char xh , ed , var , a[10];
char b[105][10];
bool h[50];
int solve() {
	la = -1;
	for (int i = 1 ; i <= n ; i++) {
		if (b[i][0] == 'F') {
			flagn = 0;
			if (!h[b[i][3]]) {
				h[b[i][3]] = 1;
			}
			else return 3;
			for (int j = 1 ; j < strlen(b[i]) ; j++) {
				if (b[i][j] == 'n') {
					flagn++;
				}
			}
			if (flagn & 1) {
				s1.push(2);
				s2.push(1);
				la = s2.size();
			}
			else s1.push(1);
		}
		if (b[i][0] == 'E') {
			int t = s1.top();
			int f;
			s1.pop();
			if (t == 2) {
				if (s2.size() != la) tot++;
				f = s2.top();
				s2.pop();
				la = s2.size();
			}
		}
	}
	if (a == "O(1)" && tot == 0) return 1;
	if (a == "O(1)" && tot != 0) return 2;
	if (a == "O(n)" && tot == 1) return 1;
	else if (a == "O(n)" && tot != 1) return 2;
	if (a[4] - '0' == tot) return 1;
	else {
		return 2;
	}
}
int main() {
	scanf("%d" , &t);
	while (t--) {
		s1.clear();
		s2.clear();
		memset(h , 0 , sizeof(h));
		cin >> n;
		cin >> a;
		for (int i = 1 ; i <= n + 1 ; i++) {
			gets(b[i]);
		}
		int g = solve();
		if (n & 1) g = 3;
		if (g == 1) {
			printf("YES\n");
		}
		if (g == 2) {
			printf("NO\n");
		}
		if (g == 3) {
			printf("ERR\n");
		}
	}
}
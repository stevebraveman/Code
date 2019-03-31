#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdarg>
#define MAXN 1000010
#define ll long long
#define lowbit(x) ((x) & (-x))
template <typename _Tp>
void _read(_Tp &x) {
	x = 0;
	_Tp f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	x *= f;
}
template <typename _Tp>
void read(size_t n, _Tp* i...) {
	va_list args;
	va_start(args, i);
	_read(*i);
	while (--n) _read(*va_arg(args, _Tp*));
	va_end(args);
}
template <typename _Tp>
void _write(_Tp x) {
	if (x < 0) putchar(45);
	if (x > 9) _write(x / 10);
	putchar(x % 10 + '0');
}
template <typename _Tp>
void write(size_t n, _Tp i...) {
	va_list args;
	va_start(args, i);
	_write(i);
	while (--n) putchar(32), _write(va_arg(args, _Tp));
	va_end(args);
}
void sp() {
	putchar(32);
}

ll c[MAXN], a[MAXN], b[MAXN], n, m;
char op[9];
void modify(int x, int y) {
	while (x <= n) {
		c[x] += y;
		x += lowbit(x);
	}
}
void change(int x, int y) {

}
int ask(int x) {
	int ans = 0;
	while (x > 0) {
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
int main() {
	read(2, &n, &m);
	for (int i = 1; i <= n; i++) {
		read(1, &a[i]);
		change
	}
	for (int i = 1; i <= n; i++) {

	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdarg>
#define MAXN 1000100
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

int a[MAXN], l[MAXN], r[MAXN], x, y, sq, 
int query
int main() {

}
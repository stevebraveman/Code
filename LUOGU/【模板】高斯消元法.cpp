#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 1010
#define eps 1e-8
double a[MAXN][MAXN];
template <typename _Tp>
void swap(_Tp &a, _Tp &b) {
	_Tp t = a;
	a = b;
	b = t;
}
int n, p;
bool cmp(double a, double b) {
	if (fabs(a - b) > eps) return 0;
	else if (fabs(a - b) <= eps) return 1;
}
bool cmp2(double a, double b) {

}
bool Gauss() {
	for (int i = 1; i <= n; i++) {
		p = i;
		for (int j = i; j <= n; j++) {
			if ()
		}
	}
}
int main() {

}
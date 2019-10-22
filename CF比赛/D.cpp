#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXN 100010
int n, _[MAXN], __[MAXN];
bool ____[MAXN], ___[MAXN];
char ch[MAXN];
template<typename T>
void swap(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}
template<typename T>
T max(T a, T b) {
	if (a > b) return a;
	else return b;
}
inline int check(){
	int tot = 0, _t = 0;
	for (int i = 1; i <= n; i++){
		__[i] = __[i - 1] + (ch[i] == '(' ? 1 : -1);
		if (ch[i] == '(') _t++;
		else _t = max(_t - 1, 0);
		___[i] = !_t;
	}
	_t = 0;
	for (int i = n; i; i--){
		_[i] = _[i + 1] + (ch[i] == '(' ? 1 : -1);
		if (ch[i] == ')') ++_t;
		else _t = max(_t - 1, 0);
		____[i] = !_t;
	}
	for (int i = 1; i <= n; i++){
		if (___[i] && ____[i + 1]&&__[i] == -_[i + 1]) ++tot;
	}
	return tot;
}
int x, y, tot;
void getans() {
	tot = check();
	x = 1;
	y = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++){
			if (ch[i] == ch[j])continue;
			swap(ch[i], ch[j]);
			int p = check();
			if(p > tot) tot = p, x = i, y = j;
			swap(ch[i], ch[j]);
		}
	}
}
int main(){
	scanf("%d", &n);
	____[n + 1] = 1;
	scanf("%s", ch + 1);
	getans();
	printf("%d\n%d %d", tot, x, y);
}
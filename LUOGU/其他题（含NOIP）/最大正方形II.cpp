#include<iostream>
#include<cstdio>
#define re register
#define F(x , y , p) for (re int x = y ; x <= p ; x++)
inline int max(int a,int b) {
	if (a > b) return a;
	else return b;
}
inline int min(int a,int b) {
	if (a < b) return a;
	else return b;
}
inline void read(int &x) {
	x = 0;
	char c = getchar();
	while (c > '9' || c < '0'){c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0';c = getchar();}
	x = x * 1;
}
int a[1502][1502] , f[1502][1502] , n , m , ans = 0;
int main() {
	read(n);read(m);
	F(i , 1 , n){
		F(j , 1 , m) {
			read(a[i][j]);
			f[i][j] = 1;
			if(i >= 2 && j >= 2) {
				if(((a[i][j - 1] ^ a[i][j]) == 1) && (a[i - 1][j - 1] == a[i][j]) && (a[i - 1][j] == a[i][j - 1])) {
					f[i][j] = min(f[i - 1][j] , min(f[i][j - 1] , f[i - 1][j - 1])) + 1;
					ans = max(ans , f[i][j]);
				}
			}
		}
	}
	printf("%d" , ans);
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int n, m, gcdnm, nc, ans;
char df[1000006], my[1000006];
map< char, int > w;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
char JSB[4]= "JSB";
char kz[4]= "SBJ";
int main() {
	cin >> n >> (df + 1) >> m;
	gcdnm= gcd(n, m), nc= n / gcdnm;
	for(int i= 1; i <= nc; i++) {
		w.clear();
		for(int j= 1; j <= gcdnm; j++) ++w[df[(nc * (j - 1) + i) % n + 1]];
		int tmpi= -1;
		for(int j= 0; j < 3; j++)
			if(w[JSB[j]] - w[kz[j]] > tmpi) tmpi= w[JSB[j]] - w[kz[j]], my[i]= kz[j];
		ans+= tmpi;
	}
	for(int i= 1; i <= m; i++) putchar(my[(i - 1) % nc + 1]);
	return 0;
}
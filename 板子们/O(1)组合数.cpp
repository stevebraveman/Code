#include <iostream>
#include <cstdio>
#define ll long long
const int N = 1000005;
const ll M = 1e9 + 7;
using namespace std;
ll fac[N] = {1 , 1} , inv[N] = {1 , 1} , fi[N] = {1 , 1};
void init() {
	for(int i = 2 ; i < N ; i++) {
		fac[i] = fac[i - 1] * i % M;
		inv[i] = (M - M / i) * inv[M % i] % M;
		fi[i] = inv[i] * fi[i - 1] % M;
	}
}
ll C(ll a , ll b) {
	return fac[a] * fi[b] % M * fi[a - b] % M;
}
int main() {
	init();
	int n , m;
	while(~scanf("%d%d" , &n , &m)) {
		cout << C(m + n - 4 , m - 2) << endl;
	}
	return 0;
}

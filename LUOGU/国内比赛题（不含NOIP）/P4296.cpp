#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#define re register
#define ll long long
ll n , x , a , b;
std::map<ll , bool> h;
std::priority_queue <ll> q;
int main() {
	scanf("%lld" , &n);
	x = sqrt(n);
	for (ll i = 1 ; i <= x ; i++) {
		if (n % i == 0) {
			b = n / i;
			for (re ll j = 1 ; j <= n ; j += b) {
				if ((j + 1) % i == 0 && !h[j]) {
					q.push(-j);
					h[j] = 1;
				}
			}
			for (re ll j = b - 1 ; j <= n ; j += b) {
				if ((j - 1) % i == 0 && !h[j]) {
					q.push(-j);
					h[j] = 1;
				}
			}
		}
	}
	while (!q.empty()) {
		printf("%lld\n" , -q.top());
		q.pop();
	}
}
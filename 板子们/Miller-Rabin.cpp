#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000000+10;
ll mul(ll a, ll b, ll m) {
	ll ans = 0;
	a %= m;
	while(b) {
		if(b & 1)ans = (ans + a) % m;
		b /= 2;
		a = (a + a) % m;
	}
	return ans;
}
ll pow(ll a, ll b, ll m) {
	ll ans = 1;
	a %= m;
	while(b) {
		if(b & 1)ans = mul(a, ans, m);
		b /= 2;
		a = mul(a, a, m);
	}
	ans %= m;
	return ans;
}
bool Miller_Rabin(ll n, int repeat) {
	if(n == 2 || n == 3) return true;
	if(n % 2 == 0 || n == 1) return false;
	ll d = n - 1;
	int s = 0;
	while(!(d & 1)) ++s, d >>= 1;
	srand((unsigned)time(NULL));
	for(int i = 0; i < repeat; i++) {
		ll a = rand() % (n - 3) + 2;
		ll x = pow(a, d, n);
		ll y = 0;
		for(int j = 0; j < s; j++) {
			y = mul(x, x, n);
			if(y == 1 && x != 1 && x != (n - 1))return false;
			x = y;
		}
		if(y != 1)return false;
	}
	return true;
}
int main() {
	int T;
	cin >> T;
	ll n;
	while(T--) {
		cin >> n;
		if(Miller_Rabin(n, 50))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
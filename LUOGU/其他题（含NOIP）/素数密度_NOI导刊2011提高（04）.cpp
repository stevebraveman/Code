#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6+10;
const int MAX_INTERVAL = 2e6+100;
bool sp[MAX_INTERVAL];
bool sps[MAX];
int sieve(ll a , ll b) {
	for(int i = 0; (ll)i * i <= b; i++) sps[i] = true;
	for(int i = 0; i <= b - a; i++) sp[i] = true;
	for(int i = 2; (ll)i * i <= b; i++) {
		if(sps[i]) {
			for(int j = 2 * j; (ll)j * j <= b; j += i) sps[j] = false;
			for(ll j = max(2LL , (a + i - 1 ) / i) * i ; j <= b; j += i) sp[j - a] = false;
		}
	}
	int ans = 0;
	for(int i = 0; i <= b-a; i++) {
		if(sp[i]) ans++;
	}
	return ans;
}
int main() {
	int t , cas = 0;
	ll a , b;
	scanf("%lld%lld" , &a , &b);
	int ans = sieve(a , b);
	if(a == 1) ans--;
	printf("%d\n" , ans);
	return 0;
}

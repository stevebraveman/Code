#include <iostream>
#include <cstdio>
#define MOD 19260817
#define ll long long
using namespace std;
inline void read( ll & x ) {
	int f = 1;
	x = 0;
	char s = getchar();
	while ( s > '9' || s < '0' ) { if (s=='-') f = -1; s = getchar(); }
	while ( s <= '9' && s >= '0' ) { x = x * 10 % MOD + ( s - '0' ) % MOD; s = getchar(); }
	x = x % MOD * f;
}
ll qpow ( ll a , ll b ){
	ll ans = 1;
	while (b) {
		if ( b & 1 ) ans = ( ( ans % MOD ) * ( a % MOD ) ) % MOD;
		b >>= 1;
		a = ( ( a % MOD ) * ( a % MOD ) ) % MOD;
	}
	return ans;
}
int main () {
	ll a , b;
	// scanf ("%lld%lld" , & a , & b );
	read(a);
	read(b);
	if ( b == 0 ) {
		printf( "Angry!" );
		return 0;
	}
	ll f = a * qpow(b , MOD - 2);
	printf("%lld" , ( f % MOD + MOD ) % MOD );
	return 0;
}
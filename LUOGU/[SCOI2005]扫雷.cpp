#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n , ans = 0 , k = 1 , a[10005] = {0} , f[10005] = {0};
void dp () {
	for ( int i = 2 ; i <= n + 1 ; i++ ) {
		f[i] = a[i - 1] - f[i - 2] - f[i - 1];
		if ( f[i] < 0 || f[i] > 1 ) {
			k = 0;
			break;
		}
		if ( f[n + 1] != 0 ) k = 0;
	}
}
int main () {
	scanf( "%d" , & n );
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf( "%d" , & a[i] );
	}
	f[1] = 1;
	dp ();
	ans += k;
	memset( f , 0 , sizeof (f) );
	f[1] = 0;
	k = 1;
	dp ();
	ans += k;
	printf( "%d" , & ans );
	return 0;
}
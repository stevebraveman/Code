#include<iostream>
#include<cstdio>
#define ll long long
#define re register
using namespace std;
ll a[3000006]= {0};
inline void write(int x) {
//	if(x<0) {
//		putchar('-');
//		x=-x;
//	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main() {
	ll n,p;
	scanf("%lld%lld",&n,&p);
	a[1]=1;
	write(a[1]);
	putchar(10);
	for(re ll i=2; i<=n; i++) {
		a[i]=(p-p/i)*a[p%i]%p;
		write(a[i]);
		putchar(10);
	}
	return 0;
}

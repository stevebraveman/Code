#include<cstdio>
using namespace std;
int main(){
	long long a,b,c,d,e,f,g;
	long long p,q,h;
	scanf("%lld:%lld:%lld",&a,&b,&c);
	scanf("%lld:%lld:%lld",&d,&e,&f);
	scanf("%lld",&g);
	p=60*60*a+60*b+c;
	q=60*60*d+60*e+f;
	h=(q-p)*g;
	printf("%lld",h);
	return 0;
}


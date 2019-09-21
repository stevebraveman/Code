#include <cstdio> 
#include <algorithm> 
using namespace std;
int main() {
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld",a*b*c/__gcd(b,c)/__gcd(a,b*c/__gcd(b,c)));
    return 0;
}

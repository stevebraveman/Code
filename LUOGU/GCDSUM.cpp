#include <cstdio>
#include <cstring>
#define MAXN 1000005
#define ll long long
bool vis[MAXN];
ll p[MAXN];
ll phi[MAXN];
ll tot , ans;
ll n;

void euler() {
	memset(vis , 0 , sizeof(vis));
	phi[1] = 1;
	tot = 0;
	for(int i = 2 ; i <= MAXN ; i++) {
		if(!vis[i])	{
			p[++tot] = i;
			phi[i] = i - 1;
		}
		for(int j = 1 ; j <= tot && i * p[j] <= MAXN; j++)	{
			vis[i * p[j]] = 1;
			if(i % p[j] == 0) {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
			phi[i * p[j]] = phi[i] * (p[i] - 1);
		}
	}
	for (ll i = 1 ; i <= n ; i++) {
		phi[i] += phi[i - 1];
	}
}
int main() {
	euler();
	scanf("%lld" , &n);
	for (ll i = 1 ; i <= n ; i++) {
		ll k = min(n / (n / i) , m / (m / i));
	}
	printf("%lld" , ans);
}

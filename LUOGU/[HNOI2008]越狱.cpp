#include<iostream>
#define ll long long
#define MOD 100003
#include<cstdio>
using namespace std;
inline ll qpow(ll a,ll b){
    ll ans=1;
    a%=MOD;
    while (b){
        if (b&1) {
        	ans=(ans*a)%MOD;
        	b^=1;
		}
        a=(a*a)%MOD;
		b>>=1;
    }
    return ans%MOD;
}
int main(){
	ll n,m,k;
	ll a,b;
	cin>>m>>n;
	a=qpow(m,n)%MOD;
	b=(m*(qpow(m-1,n-1)%MOD))%MOD;
	k=(a-b+MOD)%MOD;
	cout<<k;
}

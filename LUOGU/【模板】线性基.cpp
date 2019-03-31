#include <bits/stdc++.h>
#define MAXN 51
#define ll long long
using namespace std;
int n;
ll ans,k,p[101],a[MAXN];
int max(int a,int b) {
	return a>b?a:b;
}
void Liner_Base(ll x) {
	for(int i=62; i>=0; i--) {
		if(!(x>>(ll)i)) {
			continue;
		}
		if(!p[i]) {
			p[i]=x;
			break;
		}
		x^=p[i];
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&k);
		Liner_Base(k);
	}
	for(int i=62; i>=0; i--) {
		ans=max(ans,ans^p[i]);
	}
	cout<<ans;
	return 0;
}

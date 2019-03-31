#include <cstdio>
#include <cstring>
#define ls(a) ((a)<<1)
#define rs(a) ((a)<<1|1)
#define ll long long
#define MAXN 1000005
#define il inline
using namespace std;
struct Segment_Tree {
	ll a[MAXN << 2] , b[MAXN << 2] , lazy[MAXN << 2];
	il void pd(ll p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	il void build(ll l , ll r , ll p) {
		lazy[p] = 0;
		if (l == r) {
			b[p] = a[l];
			return;
		}
		ll m = (l + r) >> 1;
		build(l , m , ls(p));
		build(m + 1 , r , rs(p));
		pd(p);
	}
	il void f(ll p , ll l , ll r , ll k) {
		b[p] += k * (r - l + 1);
		lazy[p] += k;
	}
	il void p_d(ll p , ll l , ll r) {
		ll m = (l + r) >> 1;
		f(ls(p) , l , m , lazy[p]);
		f(rs(p) , m + 1 , r , lazy[p]);
		lazy[p] = 0;
	}
	il void ud(ll x , ll y , ll l , ll r , ll p , ll k) {
		if (x <= l && y >= r) {
			b[p] += k * (r - l + 1);
			lazy[p] += k;
			return;
		}
		p_d(p , l , r);
		ll m = (l + r) >> 1;
		if (x <= m) ud(x , y , l , m , ls(p) , k);
		if (y > m) ud(x , y , m + 1 , r , rs(p) , k);
		pd(p);
	}
	il ll sum(ll x , ll y , ll l , ll r , ll p) {
		ll s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		ll m = (l + r) >> 1;
		p_d(p , l , r);
		if (x <= m) s += sum(x , y , l , m , ls(p));
		if (y > m) s += sum(x , y , m + 1 , r , rs(p));
		return s;
	}
};
Segment_Tree tree;
ll n , m , l , r , k , flag;
int main() {
	scanf("%lld%lld" , &n , &m);
	for (ll i = 1 ; i <= n ; i++) {
		scanf("%lld" , &tree.a[i]);
	}
	tree.build(1 , n , 1);
	for (ll i = 1 ; i <= m ; i++) {
		scanf("%lld" , &flag);
		if (flag == 1) {
			scanf("%lld%lld%lld" , &l , &r , &k);
			tree.ud(l , r , 1 , n , 1 , k);
		}
		else {
			scanf("%lld%lld" , &l , &r);
			printf("%lld\n" , tree.sum(l , r , 1 , n , 1));
		}
	}
}
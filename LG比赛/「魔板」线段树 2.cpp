#include <cstdio>
#include <cstring>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define ll long long
#define MAXN 100010
ll mod , h[MAXN << 2];
struct Segment_Tree {
	ll b[MAXN << 2] , a[MAXN << 2] , mul[MAXN << 2];
	void p_u(ll rt) {
		b[rt] = b[ls(rt)] + b[rs(rt)];
	}
	void p_d(ll rt  ,  ll len) {
		if(a[rt] !=  0 || mul[rt] != 1) {
			a[ls(rt)] = ((a[ls(rt)] % mod) * (mul[rt] % mod) % mod + a[rt] % mod) % mod;
			a[rs(rt)] = ((a[rs(rt)] % mod) * (mul[rt] % mod) % mod + a[rt] % mod) % mod;
			mul[ls(rt)] = ((mul[ls(rt)] % mod) * (mul[rt] % mod) % mod) % mod;
			mul[rs(rt)] = ((mul[rs(rt)] % mod) * (mul[rt] % mod)) % mod;
			b[ls(rt)] = ((a[rt] % mod) * (len - (len >> 1) % mod) % mod + (b[ls(rt)] % mod) * (mul[rt] % mod)) % mod;
			b[rs(rt)] = ((a[rt] % mod) * ((len >> 1) % mod) % mod + (b[rs(rt)] % mod) * (mul[rt] % mod)) % mod;
			a[rt] = 0;
			mul[rt] = 1;
		}
	}
	void build(ll l , ll r , ll rt) {
		a[rt] = 0;
		mul[rt] = 1;
		if(l == r) {
			b[rt] = h[l];
			return ;
		}
		ll m = (l + r) >> 1;
		build(l , m , ls(rt));
		build(m + 1 , r , rs(rt));
		p_u(rt);
	}
	void times(ll L , ll R , ll c , ll l , ll r , ll rt) {
		if(L <= l && r <= R) {
			a[rt] = a[rt] * c % mod;
			mul[rt] = mul[rt] * c % mod;
			b[rt] = b[rt] * c % mod;
			return ;
		}
		p_d(rt , r - l + 1);
		ll m = (l + r) >> 1;
		if(L <= m) times(L , R , c , l , m , ls(rt));
		if(m < R) times(L , R , c , m + 1 , r , rs(rt));
		p_u(rt);
	}
	void add(ll L , ll R , ll c , ll l , ll r , ll rt) {
		if(L <= l && r <= R) {
			a[rt] = (a[rt] + c) % mod;
			b[rt] = (b[rt] + (r - l + 1) * c) % mod;
			return ;
		}
		p_d(rt , r - l + 1);
		ll m = (l + r) >> 1;
		if(L <= m) add(L , R , c , l , m , ls(rt));
		if(m<R) add(L , R , c , m + 1 , r , rs(rt));
		p_u(rt);
	}
	ll sum(ll L , ll R , ll l , ll r , ll rt) {
		if(L <= l && r <= R) return b[rt] % mod;
		p_d(rt , r - l + 1);
		ll ret = 0;
		ll m = (l + r) >> 1;
		if(L <= m) ret = (ret % mod + sum(L, R, l, m, ls(rt)) % mod) % mod;
		if(R > m) ret = (ret % mod + sum(L, R, m + 1, r, rs(rt)) % mod) % mod;
		return ret % mod;
	}
}tree;
ll n , m , op , l , r , k;
int main() {
	scanf("%lld%lld%lld" , &n , &m , &mod);
	for(ll i = 1 ; i <= n ; i++) {
		scanf("%lld" , &h[i]);
		h[i] %= mod;
	}
	tree.build(1 , n , 1);
	while(m--) {
		scanf("%lld" , &op);
		if (op == 2) {
			scanf("%lld%lld%lld" , &l , &r , &k);
			k %= mod;
			tree.times(l , r , k , 1 , n , 1);
		} else if (op == 1) {
			scanf("%lld%lld%lld" , &l , &r , &k);
			k %= mod;
			tree.add(l , r , k , 1 , n , 1);
		} else if (op == 3) {
			scanf("%lld%lld%lld" , &l , &r, &k);
			printf("%lld\n" , (k % mod) * (tree.sum(l , r , 1 , n , 1) % mod) % mod);
		}
	}
	return 0;
}
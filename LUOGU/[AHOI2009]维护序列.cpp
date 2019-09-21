#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ls(x) ((x)<<1)
#define rs(x) (((x)<<1)|(1))
#define MAXN 100010
#define LL long long 
using namespace std;
LL mod;
struct Segment_Tree {
	LL sum[MAXN<<2],add[MAXN<<2],mul[MAXN<<2];
	void p_u(int rt) {
		sum[rt]=sum[ls(rt)]+sum[rs(rt)];
	}
	void p_d(LL rt,LL len) {
		if(add[rt]!=0||mul[rt]!=1) {
			add[ls(rt)]=((add[ls(rt)]%mod)*(mul[rt]%mod)+add[rt])%mod;
			add[rs(rt)]=((add[rs(rt)]%mod)*(mul[rt]%mod)+add[rt])%mod;
			mul[ls(rt)]=(mul[rt<<1]*mul[rt])%mod;
			mul[rs(rt)]=(mul[rs(rt)]*mul[rt])%mod;
			sum[ls(rt)]=((add[rt]%mod)*(len-(len>>1))%mod+(sum[ls(rt)]%mod)*mul[rt]%mod)%mod;
			sum[rs(rt)]=(((add[rt]%mod)*(len>>1))%mod+(sum[rs(rt)]%mod)*mul[rt]%mod)%mod;
			add[rt]=0;
			mul[rt]=1;
		}
	}
	void build(LL l,LL r,LL rt) {
		add[rt]=0;
		mul[rt]=1;
		if(l==r) {
			scanf("%lld",&sum[rt]);
			return ;
		}
		int m=(l+r)>>1;
		build(lson);
		build(rson);
		p_u(rt);
	}
	void update1(LL L,LL R,LL c,LL l,LL r,LL rt) {
		if(L<=l&&r<=R) {
			add[rt]=add[rt]*c%mod;
			mul[rt]=mul[rt]*c%mod;
			sum[rt]=sum[rt]*c%mod;
			return ;
		}
		p_d(rt,r-l+1);
		LL m=(l+r)>>1;
		if(L<=m) update1(L,R,c,lson);
		if(m<R) update1(L,R,c,rson);
		p_u(rt);
	}
	void update2(LL L,LL R,LL c,LL l,LL r,LL rt) {
		if(L<=l&&r<=R) {
			add[rt]=(add[rt]+c)%mod;
			sum[rt]=(sum[rt]+(r-l+1)*c)%mod;
			return ;
		}
		p_d(rt,r-l+1);
		LL m=(l+r)>>1;
		if(L<=m) update2(L,R,c,lson);
		if(m<R) update2(L,R,c,rson);
		p_u(rt);
	}
	LL query(LL L,LL R,LL l,LL r,LL rt) {
		if(L<=l&&r<=R) return sum[rt]%mod;
		p_d(rt,r-l+1);
		LL ret=0;
		int m=(l+r)>>1;
		if(L<=m)ret+=query(L,R,lson)%mod;
		if(R>m) ret+=query(L,R,rson)%mod;
		return ret%mod;
	}
}Tree;
int main() {
	LL n,m;
	scanf("%lld%lld",&n,&mod);
	Tree.build(1,n,1);
	LL op,a,b,c;
	scanf("%lld",&m);
	while(m--) {
		scanf("%lld",&op);
		if(op==1) {
			scanf("%lld%lld%lld",&a,&b,&c);
			Tree.update1(a,b,c,1,n,1);
		} else if(op==2) {
			scanf("%lld%lld%lld",&a,&b,&c);
			Tree.update2(a,b,c,1,n,1);
		} else {
			scanf("%lld%lld",&a,&b);
			printf("%lld\n",Tree.query(a,b,1,n,1)%mod);
		}
	}
	return 0;
}

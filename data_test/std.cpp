#include<algorithm>/*{{{*/
#include<cctype>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<vector>
using namespace std;
typedef long long lld;
typedef long double lf;
typedef unsigned long long uld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
namespace RA{
    int r(int p){return 1ll*rand()*rand()%p;}
    int r(int L,int R){return r(R-L+1)+L;}
}/*}}}*/
/******************heading******************/
//#define int lld
int pw(int a,int m,int p){
    int res=1;
    while(m)m&1?res=1ll*res*a%p:0,a=1ll*a*a%p,m>>=1;
    return res;
}
const int N=1e5+5,P=998244353,Lim=502;

struct qxx{int nex,t,v;};
qxx e[N*2];
int h[N],le=1;
void add_path(int f,int t){e[++le]=(qxx){h[f],t},h[f]=le;}
#define FORe(i,u,v) for(int i=h[u],v;v=e[i].t,i;i=e[i].nex)
int psz[N*2];

int n,q,L;

int fa[N][21],dep[N],sz[N],dg[N];
void dfs1(int u,int p=0){
    fa[u][0]=p,dep[u]=dep[p]+1;
    FOR(j,1,20){
        fa[u][j]=fa[fa[u][j-1]][j-1];
        if(!fa[u][j])break;
    }
    FORe(i,u,v)if(v!=p)dfs1(v,u),dg[u]++;
    dg[u]++;
}
int f[N][Lim];
void back_upd(int *dp,int x){
    ROF(i,L,1){
        dp[i]=(dp[i]+1ll*dp[i-1]*x)%P;
    }
}
int dfs2(int u,int path){
    sz[u]=1;
    f[u][0]=1;
    FORe(i,u,v)if((i^1)!=path)sz[u]+=dfs2(v,i);
    FORe(i,u,v)if((i^1)!=path)back_upd(f[u],sz[v]);
    back_upd(f[u],n-sz[u]);
    //printf("f[%d]: ",u);FOR(i,0,L)printf("%d ",f[u][i]); puts("");
    if(path)psz[path]=sz[u],psz[path^1]=n-sz[u];
    return sz[u];
}
int g[Lim];
void del_item(int *dp,int x,int *g,int lim){
    FOR(i,0,lim)g[i]=0;
    g[0]=1;
    FOR(i,1,lim)g[i]=(dp[i]-1ll*g[i-1]*x)%P;
}
int fac[N],fnv[N];
void init(){
    fac[0]=1;
    FOR(i,1,n)fac[i]=1ll*fac[i-1]*i%P;
    fnv[n]=pw(fac[n],P-2,P);
    ROF(i,n,1)fnv[i-1]=1ll*fnv[i]*i%P;
}
int binom(int a,int b){
    if(a<b)return 0;
    return 1ll*fac[a]*fnv[b]%P*fnv[a-b]%P;
}
int calc(int u,int v,int k){
    if(dep[u]<dep[v])swap(u,v);
    int u1=u,pu,v1=v,pv;
    ROF(j,20,0) if(dep[u]-(1<<j)>dep[v])u=fa[u][j];
    if(fa[u][0]==v)pu=fa[u1][0],pv=u;
    else pu=fa[u1][0],pv=fa[v1][0];
    u=u1,v=v1;
    //printf("u=%d,v=%d,pu=%d,pv=%d\n",u,v,pu,pv);
    int tot1=0,tot2=0;
    //part1
    FORe(i,u,s)if(s==pu){// i:path u -> pu
        int lim=min(k,dg[u]-1);
        del_item(f[u],psz[i],g,lim);
        FOR(x,0,lim)tot1=(tot1+1ll*g[x]*fac[x]%P*binom(k,x))%P;
        break;
    }
    //part2
    FORe(i,v,s)if(s==pv){// i:path u -> pu
        int lim=min(k,dg[v]-1);
        del_item(f[v],psz[i],g,lim);
        FOR(x,0,lim)tot2=(tot2+1ll*g[x]*fac[x]%P*binom(k,x))%P;
        break;
    }
    tot1=(tot1+P)%P;
    tot2=(tot2+P)%P;
    //printf("tot1=%d,tot2=%d\n",tot1,tot2);
    return 1ll*tot1*tot2%P;
}
signed main(){
    scanf("%d%d%d",&n,&q,&L);
    init();
    FOR(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        add_path(u,v);
        add_path(v,u);
    }
    dfs1(1);
    dfs2(1,0);
    FOR(i,1,q){
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        printf("%d\n",calc(u,v,k));
    }
    return 0;
}

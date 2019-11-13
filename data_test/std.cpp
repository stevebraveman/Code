#include<bits/stdc++.h>
#define fi first
#define se second
#define Mp make_pair
#define pb push_back
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int N = 20, States = 1<<15;
int n,states,cnt[States];
ll f[States][N],g[States][N],w[N][N],ans=1ll<<61;

void dfs(int x,int S,int p1,int p2){
    if(x>=n){
        if(!p1||!p2) return;
        rep(i,1,n) if(p1>>(i-1)&1) f[S][i]=min( f[S][i],f[p1][i]+g[p2][i] );
        // rep(i,1,n) if(p1>>(i-1)&1) rep(j,1,n) if(p2>>(j-1)&1)
        //     f[S][i]=min( f[S][i],f[p1][i]+ f[p2][j]+w[i][j]*cnt[p2]*(n-cnt[p2]) );
        return;
    }
    if(S>>x&1) dfs(x+1,S,p1|(1<<x),p2),dfs(x+1,S,p1,p2|(1<<x));
    else dfs(x+1,S,p1,p2);
}

int main(){
    scanf("%d",&n); states=(1<<n)-1;
    rep(i,1,states) cnt[i]=cnt[i>>1]+(i&1);
    rep(i,1,n) rep(j,i+1,n) scanf("%lld",&w[i][j]), w[j][i]=w[i][j];
    rep(i,0,states) rep(j,1,n) f[i][j]=g[i][j]=1ll<<61;
    rep(i,1,n) f[0][i]=f[1<<(i-1)][i]=0;
    rep(i,1,n) rep(j,1,n) if(i!=j) g[1<<(i-1)][j]=f[1<<(i-1)][i]+w[i][j]*(n-1);
    rep(S,1,states) {
        if(cnt[S]==1) continue;
        dfs(0,S,0,0);
        rep(i,1,n) if( !(S>>(i-1)&1) ) rep(j,1,n) if( S>>(j-1)&1 )
            g[S][i]=min( g[S][i],f[S][j]+w[i][j]*cnt[S]*(n-cnt[S]) );
//for(int i=1;i<=n;++i)if(!(S&(1<<i-1))) for(int j=1;j<=n;++j)if(S&(1<<j-1))
    //g[S][i]=min(g[S][i],f[S][j]+w[i][j]*cnt[S]*(n-cnt[S]));
    }
    rep(i,1,n) ans=min(ans,f[states][i]);
    printf("%lld\n",ans);
    return 0;
}

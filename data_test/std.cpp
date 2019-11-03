#include<cstdio>
#include<iostream>
#define N 505
#define il inline
#define rg register
using namespace std;
int n,m,es[N][N],e[N][N];
int ds[N],d[N];
il bool chk(int k)
{
    int cnt=0;
    for(rg int i=1;i<=n;i++)
        d[i]=ds[i],cnt+=(d[i]==n-1);
    for(rg int i=1;i<=n;i++)
        for(rg int j=1;j<=n;j++)e[i][j]=es[i][j];
    bool flag=1;
    while(cnt!=n&&flag)
    {
        flag=0;
        for(rg int x=1;x<=n&&cnt!=n;x++)
            for(rg int y=1;y<=n&&cnt!=n;y++)
                if(x!=y&&d[y]+d[x]>=k&&!e[x][y])
                {
                    flag=1;
                    e[x][y]=e[y][x]=1;
                    d[x]++,d[y]++;
                    cnt+=(d[x]==n-1);
                    cnt+=(d[y]==n-1);
                }
    }
    return cnt==n;
}
int main()
{
//  freopen("test.in","r",stdin);
//  freopen("2.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(rg int i=1,x,y;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        es[x][y]=es[y][x]=1,ds[x]++,ds[y]++;
    }
    int l=0,r=2*(n-1);
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(chk(mid))l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}


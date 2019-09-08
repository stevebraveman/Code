
#include<bits/stdc++.h>
using namespace std;
long long f[25][25];
int n,m,hx,hy;
bool v[25][25];
int main()
{
    scanf("%d%d%d%d",&n,&m,&hx,&hy);
    n+=1,m+=1,hx+=1,hy+=1;
    f[0][1]=1;
    v[hx][hy]=1;
    v[hx-1][hy-2]=1;v[hx+2][hy+1]=1;v[hx+1][hy+2]=1;v[hx-2][hy+1]=1;
    v[hx-1][hy+2]=1;v[hx+2][hy-1]=1;v[hx+1][hy-2]=1;v[hx-2][hy-1]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) 
            if(v[i][j]==1) f[i][j]=0;
            else f[i][j]=f[i-1][j]+f[i][j-1];
    printf("%lld",f[n][m]);
    return 0;
}

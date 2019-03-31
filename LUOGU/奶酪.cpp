#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
ll n,h,r,up[1005],down[1005],fa[1005];
struct sphere {
    ll x,y,z;
} a[1005];
ll find(ll a) {
    if(fa[a]==a) return a;
    else return fa[a]=find(fa[a]);
}
void un(ll a,ll b) {
    ll w=find(a);
    ll e=find(b);
    if(w!=e)
        fa[e]=w;
    return;
}
bool chk(sphere a,sphere b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))<=r*2;
}
int main() {
    int t;
    scanf("%d",&t);
    for(int y=1; y<=t; y++) {
        int k=0,p=0;
        bool flag1=0;
        bool flag2=0;
        memset(up,0,sizeof(up)),
               memset(down,0,sizeof(down));
        scanf("%lld%lld%lld",&n,&h,&r);
        for(int i=1; i<=n; i++) {
            fa[i]=i;
        }
        for(int i=1; i<=n; i++) {
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
            if((a[i].z+r)>=h) {
                k++;
                up[k]=i;
                flag1=1;
            }
            if((a[i].z-r)<=0) {
                p++;
                down[p]=i;
                flag2=1;
            }
        }
        if((flag1==0)||(flag2==0)) {
            printf("No\n");
            continue;
        }
        for(int i=1; i<n; i++) {
            for(int j=i+1; j<=n; j++) {
                if(chk(a[i],a[j])) {
                    un(i,j);
                }
            }
        }
        bool lt=0;
        for(int i=1; i<=k; i++) {
            for(int j=1; j<=p; j++) {
                int aa=find(up[i]);
                int bb=find(down[j]);
                if(aa==bb) {
                    lt=1;
                    break;
                }
            }
            if(lt) break;
        }
        if(lt) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}

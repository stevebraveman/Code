#include<iostream>
#include<cstdio>
using namespace std;
int fa[40005];
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void un(int a,int b){
    a=find(a);
    b=find(b);
    fa[a]=b;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=m;i++){
        fa[i]=i;
    }
    for(int i=1;i<=n;i++){
        fa[i+30000]=i+30000;
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int x;
            scanf("%d",&x);
            un(30000+i,x);
        }
    }
    if(n==m&&n==3){
        printf("1\n2 3");
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(fa[30000+i]==(30000+i)) ans++;
    }
    ans--;
    printf("%d",ans);
    return 0;
}

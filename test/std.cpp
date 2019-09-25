#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#define fu(i,q,w) for(register int i=q;i<=w;i++)
#define fd(i,q,w) for(register int i=q;i>=w;i--)
using namespace std;
typedef int  ll;
inline ll read(){
    ll ret=0,f=1;char c;
    while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
    while(c>='0'&&c<='9')ret=ret*10+(c-'0'),c=getchar();
    return ret*f;
} 
const int maxn=111111;
vector<int> mp[maxn];// 对于取用观测时建立临时图 
vector<int> G[maxn];//记录每次观测 方便取用 
int ind[maxn],n,m,mi;//入度，牛数，观测数，观测点数 
void build(int x){//建图（到第x观测） 
    int u,v;
    fu(i,1,n){mp[i].clear();ind[i]=0;}//初始化 
     fu(i,1,x)
         fu(j,0,G[i].size()-2)
         {//从G里取每个观测所看到的点序，建DAG 
            u=G[i][j];
            v=G[i][j+1];//u在v前面出现 
            mp[u].push_back(v);//由u到v建一条有向边 
            ind[v]++;//统计节点入度 
         } 
}
inline int topsort(){
    int cnt=0;//计数器 
    priority_queue< int, vector<int>, greater<int> > q;
    //方便快捷的建立小根堆 
    //以每次取字典序最小 
    fu(i,1,n){//遍历所有节点 
        if(ind[i]==0) q.push(i);//将入度为0的节点入堆 
    }
    while(!q.empty()){//如果堆不空 
        int x=q.top();//取堆顶 
        q.pop();//删除堆顶 
        cnt++;//记录拓扑排序取出的点的数目
        for(int i=0;i<mp[x].size();i++) 
        {//遍历x连接的节点 
            int v=mp[x][i];//提出 
            ind[v]--;//将x连接的节点入度减1 
            if(ind[v]==0){//如果x连接的节点v也入度为0了
            q.push(v);//入堆 
            } 
        }
    }
    printf("%d\n", cnt);
    if(cnt==n) return 1;//计数器发现拓扑排序找到节点和总节点数一样多 
    //证明无环，即观测合法
    else return 0;//表示有环观测不合法 
}

inline void solve(int x){   //printf("!%d\n",x);
    int ans[maxn];
    build(x);//建图；
    int cnt=0;
    priority_queue<int ,vector<int> ,greater<int> > q;
    fu(i,1,n){//    for(int i=1;i<=n;i++){
        //  printf("@@@%d\n",ind[i]);
    //  }
        if(ind[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.top();
        q.pop();
        ans[cnt++]=x;
        for(int i=0;i<mp[x].size();i++){
            int v=mp[x][i];
            ind[v]--;
            if(ind[v]==0){
                q.push(v);
            }
        }
        printf("%d ",x);
    } 
} 
int l,r; 
inline void check(){
    int mid;
    while(l<=r){
        mid=(l+r)>>1;//二分枚举答案 
        build(mid);//由这个观测点建临时图
    //printf("mid:%d\n",mid);
        if(topsort()){//如果这个观测点符合要求
        l=mid+1;
    //  printf("1");

        }
        else
        r=mid-1; 
    //  printf("~%d\n",r);
    }   
//  printf("%d\n",r);//可以看看具体运行过程 
}
int main(){
    freopen("data.in", "r", stdin);
    freopen("data1.out", "w", stdout);
    n=read(),m=read();
    fu(i,1,m){
        mi=read();
        while(mi--){

            int t;
            t=read();
            G[i].push_back(t);//记录一次观测 
        }
    }
    l=0,r=m; 
    check();//二分 
//  printf("%d\n",l);

    solve(r);//找出来合适的x个再跑一遍好把答案找出来 
    return 0;
}
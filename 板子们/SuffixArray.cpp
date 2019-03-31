#include<iostream>
#include<cstdio>
#include<cstring>
#define inv inline void
#define ini inline int
#define maxn 1000050
using namespace std;
char s[maxn];
int y[maxn],a[maxn],b[maxn],sa[maxn],rk[maxn],height[maxn],wt[30];
int n,m;
inv get_SA()
{
    for (int i=1;i<=n;++i) ++b[a[i]=s[i]];
    //c数组是桶 
    //a[i]是第i个元素的第一关键字 
    for (int i=2;i<=m;++i) b[i]+=b[i-1]; 
    //做c的前缀和，我们就可以得出每个关键字最多是在第几名 
    for (int i=n;i>=1;--i) sa[b[a[i]]--]=i; 
    for (int k=1;k<=n;k<<=1)
    {
        int num=0;
        for (int i=n-k+1;i<=n;++i) y[++num]=i;
        //y[i]表示第二关键字排名为i的数，第一关键字的位置 
        //第n-k+1到第n位是没有第二关键字的 所以排名在最前面 
        for (int i=1;i<=n;++i) if (sa[i]>k) y[++num]=sa[i]-k;
        //排名为i的数 在数组中是否在第k位以后
        //如果满足(sa[i]>k) 那么它可以作为别人的第二关键字，就把它的第一关键字的位置添加进y就行了
        //所以i枚举的是第二关键字的排名，第二关键字靠前的先入队 
        for (int i=1;i<=m;++i) b[i]=0;
        //初始化c桶 
        for (int i=1;i<=n;++i) ++b[a[i]];
        //因为上一次循环已经算出了这次的第一关键字 所以直接加就行了 
        for (int i=2;i<=m;++i) b[i]+=b[i-1];//第一关键字排名为1~i的数有多少个 
        for (int i=n;i>=1;--i) sa[b[a[y[i]]]--]=y[i],y[i]=0;
        //因为y的顺序是按照第二关键字的顺序来排的 
        //第二关键字靠后的，在同一个第一关键字桶中排名越靠后 
        //基数排序 
        swap(a,y);
        //这里不用想太多，因为要生成新的x时要用到旧的，就把旧的复制下来，没别的意思 
        a[sa[1]]=1;num=1;
        for (int i=2;i<=n;++i)
            a[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]) ? num : ++num;
        //因为sa[i]已经排好序了，所以可以按排名枚举，生成下一次的第一关键字 
        if (num==n) break;
        m=num;
        //这里就不用那个122了，因为都有新的编号了 
    }
    for (int i=1;i<=n;++i) putout(sa[i]),putchar(' ');
}
inv get_height()
{
    int k=0;
    for (int i=1;i<=n;++i) rk[sa[i]]=i;
    for (int i=1;i<=n;++i)  
    {
        if (rk[i]==1) continue;//第一名height为0 
        if (k) --k;//h[i]>=h[i-1]+1;
        int j=sa[rk[i]-1];
        while (j+k<=n && i+k<=n && s[i+k]==s[j+k]) ++k;
        height[rk[i]]=k;//h[i]=height[rk[i]];
    }
    putchar(10);for (int i=1;i<=n;++i) putout(height[i]),putchar(' ');
}
int main()
{
    gets(s+1);
    n=strlen(s+1);m=122;
    //因为这个题不读入n和m所以要自己设
    //n表示原字符串长度，m表示字符个数，ascll('z')=122 
    //我们第一次读入字符直接不用转化，按原来的ascll码来就可以了 
    //因为转化数字和大小写字母还得分类讨论，怪麻烦的 
    get_SA();
    //get_height();
}
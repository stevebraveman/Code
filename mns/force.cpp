#define Kafuu signed
#define Chino main

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

#define maxn 200005
#define inf 0x3f3f3f3f
#define px putchar
#define pn px('\n')
#define ps px(' ')
#define pd puts("======================")
#define pj puts("++++++++++++++++++++++")

const int mod = 998244353;

using namespace std;

inline int read(){
	int x=0,y=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return y?-x:x;
}
template<typename T>
inline T read(){
	T x=0;
	int y=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return y?-x:x;
}
int n,a[maxn],b[maxn],la,lb,ans;
char s[maxn];
void dfs(int step=1){
	if(la&&lb&&s[min(la,lb)]!=a[min(la,lb)]>b[min(la,lb)])return;
	if(step>n<<1){++ans;return;}
	if(la<n)a[++la]=step,dfs(step+1),--la;
	if(lb<n)b[++lb]=step,dfs(step+1),--lb;
}
Kafuu Chino(){
	n=read();
	scanf("%s",s+1);
	for(register int i=1;i<=n;++i)s[i]-='0';
	dfs();
	printf("%d\n",ans%mod);
}

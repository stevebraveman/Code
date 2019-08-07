#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 50010
#define INF 1000000000
#define rg register
inline int read(){
	int x=0,t=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*t;
}
struct Node{
	int x,y;
}p[MAX],p0,S[MAX];
int n,top,T;
inline bool cmp(Node a,Node b){
	rg double A=atan2(a.y-p0.y,a.x-p0.x);
	rg double B=atan2(b.y-p0.y,b.x-p0.x);
	if(A!=B)return A<B;
	else    return a.x<b.x;
}
inline long long chaji(int x1,int y1,int x2,int y2){
	return (1LL*x1*y2-1LL*x2*y1);
}
inline long long Compare(Node a,Node b,Node c){
	return chaji((b.x-a.x),(b.y-a.y),(c.x-a.x),(c.y-a.y));
}
inline void Find(){
	p0=(Node){INF,INF};
	rg int k=0;
	for(rg int i=0;i<n;++i)//找到最下方的点 
		if(p0.y>p[i].y||(p0.y==p[i].y&&p0.x>p[i].x))
			p0=p[i],k=i;
	swap(p[k],p[0]);
	sort(&p[1],&p[n],cmp);//关于最下方的点排序
	S[0]=p[0];S[1]=p[1];
	top=1;//栈顶 
	for(rg int i=2;i<n;){
		if(top&&Compare(S[top-1],p[i],S[top])>=0) top--;
		else   S[++top]=p[i++];  
	}
	//for(int i=0;i<=top;++i)printf("(%d,%d)\n",S[i].x,S[i].y);
}
inline long long Dis(Node a,Node b){
	return 1LL*(a.x-b.x)*(a.x-b.x)+1LL*(a.y-b.y)*(a.y-b.y);
}
long long GetMax(){
	rg long long re=0;
	if(top==1)//仅有两个点
	return Dis(S[0],S[1]); 
	S[++top]=S[0];//把第一个点放到最后
	int j=2;
	// for (int i = 1; i < top; i++) {
	// 	printf("%d %d\n", S[i].x, S[i].y);
	// }
	for(int i=0;i<top;++i){
		while(Compare(S[i],S[i+1],S[j])<Compare(S[i],S[i+1],S[j+1]))
		j=(j+1)%top;
		if (re < max(Dis(S[i], S[j]), Dis(S[i + 1], S[j]))) {
			// printf("%d %d %d %d %d %d\n", S[i + 1].x, S[i + 1].y, S[i].x, S[i].y, S[j].x, S[j].y);
			re=max(re,max(Dis(S[i],S[j]),Dis(S[i+1],S[j])));
		}
	}
	return re;
}
int main(){
	freopen("data.in", "r", stdin);
	freopen("data1.out", "w", stdout);
	n=read();
	for(int i=0;i<n;++i){
		p[i].x=read();p[i].y=read();
	}
	long long ans=INF,ss;
	Find();
	ans=GetMax();
	cout<<ans<<endl;
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#define lowbit(x) ((x)&(-(x)))
#define R register
#define ll long long
using namespace std;
inline void read(int &w) {
	int f=1;
	w=0;
	char s=getchar();
	while(s<'0'||s>'9') {if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9') {w=w*10+s-'0';s=getchar();}
	w*=f;
}
inline void write(int x) {
	if(x<0) {putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m;
struct BIT_2D {
	int a[4][2049][2049];
	void up(int x,int y,int delta) {
		if (x<1 || n<x || y<1 || m<y) return;
		for (int i=x; i<=n; i+=lowbit(i)) {
			for (int j=y; j<=m; j+=lowbit(j)) {
				a[0][i][j]+=delta;
				a[1][i][j]+=delta*y;
				a[2][i][j]+=delta*x;
				a[3][i][j]+=delta*x*y;
			}
		}
	}
	int sum(int x,int y) {
		int res=0;
		for (int i=x; i; i-=lowbit(i)) {
			for (int j=y; j; j-=lowbit(j)) {
				res=res+(x+1)*(y+1)*a[0][i][j]-(x+1)*a[1][i][j]-(y+1)*a[2][i][j]+a[3][i][j];
			}
		}
		return res;
	}
}tree;
int main() {
	char flag;
	cin>>flag;
	cin>>n>>m;
	while(scanf("\n%c ",&flag)!=EOF) {
		int x1,y1,x2,y2;
		int k;
		if(flag=='L') {
			read(x1);read(y1);read(x2);read(y2);read(k);
			x1++;x2++;y1++;y2++;
			tree.up(x2,y2,k);
			tree.up(x1-1,y2,-k);
			tree.up(x2,y1-1,-k);
			tree.up(x1-1,y1-1,k);
		} else {
			read(x1);read(y1);read(x2);read(y2);
			int p=tree.sum(x2,y2)-tree.sum(x1-1,y2)-tree.sum(x2,y1-1)+tree.sum(x1-1,y1-1);
			write(p);
			puts("");
		}
	}
	return 0;
}

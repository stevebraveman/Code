#include<iostream>
#include<cstdio>
#include<cstring>
#define MX 5001
#define re register
#define abs(x) ((x)>0)?(x):(-(x))
#define ll long long
#define F(i,n,x) for(re int i=n;i<=x;i++)
using namespace std;
ll x1,x0,a,b,c,d,n,m,q;
int h[MX*MX]= {0},t[MX*MX],rd[MX],Le[MX],Cl[MX];
void sp(int &a,int &b) {
	int t=a;
	a=b;
	b=t;
}
void read(ll &x) {
	int f=1;
	x=0;
	char s=getchar();
	while(s<'0'||s>'9') {if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=x*10+s-'0';s=getchar();}
	x*=f;
}
void write(ll x) {
	if(x<0) {putchar('-');x=-x;}
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
int main() {
	read(x0);
	read(a);
	read(b);
	read(c);
	read(d);
	read(n);
	read(m);
	read(q);
	int nm=n*m;
	F(i,1,nm) {
		h[i]=((a%d)*(x0%d)*(x0%d)+(b%d)*(x0%d)+c%d)%d;
		x0=h[i];
		t[i]=i;
	}
	memset(Le,127,sizeof(Le));
	F(i,1,nm) {
		swap(t[i],t[h[i]%i+1]);
	}
	F(i,1,q) {
		ll u,v;
		read(u);
		read(v);
		swap(t[u],t[v]);
	}

	F(i,1,nm) {
		h[t[i]]=i;
	}
	int ans=0;
	F(i,1,nm) {
		int j,k;
		if(h[i]%m!=0) j=h[i]/m+1;
		else j=h[i]/m;
		k=h[i]%m;
		if(k==0)k+=m;
		if(k<=Le[j]&&k>=Cl[j]) {
			F(p,1,n) {
				if (p<j) Le[p]=min(k,Le[p]);
				else if(p>j) Cl[p]=max(k,Cl[p]);
			}
			ans++;
			write(i);
			printf(" ");
			if(ans==n+m-1) break;
		}
	}
	return 0;
}

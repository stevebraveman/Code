#include<bits/stdc++.h>
using namespace std;
#define re register
#define INF ((int)0x3F3F3F3F)
#define N 100100
namespace STman {
	inline char gc(){
		#ifdef ONLINE_JUDGE
			static char now[1 << 16], *S, *T;
			if (T == S) {T = (S = now) + fread(now, 1, 1 << 16, stdin); if (T == S) return EOF;}
			return *S++;
		#else 
			return getchar();
		#endif
	}
	template <typename Tp>
	inline void read(Tp &x) {
		Tp f = 1;x = 0;
		char k = gc();
		while (k < '0' || k > '9') {if (k == '-') f = -1;k = gc();}
		while (k >= '0' && k <= '9') {x = x * 10 + k - '0';k = gc();}
		x = x * f;
	}
	template <typename Tp>
	inline void write(Tp x) {
		if (x < 0) putchar('-') , x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
	template <typename Tp>
	inline Tp max(Tp a , Tp b) {
		if (a > b) return a;
		else return b;
	}
	template <typename Tp>
	inline Tp min(Tp a , Tp b) {
		if (a < b) return a;
		else return b;
	}
	template <typename Tp>
	inline void swap(Tp &a , Tp &b) {
		Tp t = a;
		a = b;
		b = t;
	}
	template <typename Tp>
	inline Tp abs(Tp &a) {
		if (a < 0) return -a;
		else return a;
	}
	inline void sp() {
		putchar(32);
	}
	inline void et() {
		putchar(10);
	}
}
using namespace STman;
struct Node {
	int l;
	mutable int r, v;
	Node(int l, int r, int v) : l(l), r(r), v(v) {}
	bool operator < (const Node& x)const {
		return l < x.l;
	}
};
int n, m, f;
set<Node>s;
typedef set<Node>::iterator IT;
IT split(int p) {
	IT it = s.lower_bound(Node(p, 0, 0));
	if (it->l == p)return it;
	--it;
	int r = it->r;
	it->r = p - 1;
	return s.insert(Node(p, r, it->v)).first;
}
void assign(int l, int r, int v) {
	IT it = split(l), end = split(r + 1);
	s.erase(it, end);
	s.insert(Node(l, r, v));
}
int query(int x, int y) {
	IT it = split(1), end = split(n + 1);
	int ret = INF;
	for (IT i = it; i != end; ++i) {
		for (IT j = i; j != end; ++j) {
			if ((i->v == x && j->v == y)||(i->v == y && j->v == x)) {
				ret = min(ret, j->l - i->r);
			}
		}
	}
	return ret == INF ? -1 : ret;
}
int a[N],op[N],A[N],B[N],C[N];
namespace sub {
	const int maxn=1e5+5;
	std::vector<int> pos[maxn];
	int q[325],Ans[325][325],T,tot,ans[325][maxn],id[maxn];
	inline int calc(int x,int y) {
		int nw=INF,pt=0;
		for(re int i=0;i<pos[x].size();++i) {
			while(pt<pos[y].size()&&pos[y][pt]<pos[x][i]) ++pt;
			if(pt) nw=min(nw,pos[x][i]-pos[y][pt-1]);
		}
		std::swap(x,y);pt=0;
		for(re int i=0;i<pos[x].size();++i) {
			while(pt<pos[y].size()&&pos[y][pt]<pos[x][i]) ++pt;
			if(pt) nw=min(nw,pos[x][i]-pos[y][pt-1]);
		}
		return nw;
	}
	void solve() {
		for(re int i=1;i<=n;i++) pos[a[i]].push_back(i);T=std::sqrt(n);
		for(re int i=1;i<=n;i++) if(pos[i].size()>T) q[++tot]=i,id[i]=tot;
		for(re int i=1;i<=tot;i++)
			for(re int j=i+1;j<=tot;++j)
				Ans[i][j]=Ans[j][i]=calc(q[i],q[j]);
		for(re int pt,j=1;j<=tot;j++) {
			int x=q[j];
			for(re int i=1;i<=n;i++) ans[j][i]=INF;pt=0;
			for(re int i=1;i<=n;i++) {
				while(pt<pos[x].size()&&pos[x][pt]==i) ++pt;
				if(pt) ans[j][i]=min(ans[j][i],i-pos[x][pt-1]);
			}
			pt=pos[x].size()-1;
			for(re int i=n;i;--i) {
				while(pt>=0&&pos[x][pt]==i) --pt;
				if(pt+1<pos[x].size())
					ans[j][i]=min(ans[j][i],pos[x][pt+1]-i);
			}
		}
		int lst=0;
		for(re int x,y,i=1;i<=m;i++) {
			x=A[i],y=B[i];
			if(f&&lst!=-1) x^=lst,y^=lst;
			if(pos[x].size()==0||pos[y].size()==0) {
				printf("%d\n",lst=-1);
				continue;
			}
			if(x==y) {
				printf("%d\n",lst=0);
				continue;
			}
			if(pos[x].size()>T&&pos[y].size()>T) {
				printf("%d\n",lst=Ans[id[y]][id[x]]);
				continue;
			}
			if(pos[x].size()<=T&&pos[y].size()<=T) {
				printf("%d\n",lst=calc(x,y));
				continue;
			}
			if(pos[x].size()>pos[y].size()) std::swap(x,y);
			lst=INF;
			for(re int j=0;j<pos[x].size();++j)
				lst=min(lst,ans[id[y]][pos[x][j]]);
			printf("%d\n",lst);
		}
	}
}
int main() {
	//freopen("data.in","r",stdin);
	//freopen("a.out","w",stdout);
	n = read(), m = read(), f = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	s.insert(Node(0, 0, 0));
	s.insert(Node(n + 1, n + 1, 0));
	for (int i = 1; i <= n; i++) s.insert(Node(i, i, a[i]));
	for(re int i=1;i<=m;i++) {
		op[i]=read(),A[i]=read(),B[i]=read();
		if(op[i]==1) C[i]=read();
	}
	int sub_flag=1;
	for(re int i=1;i<=m;i++) if(op[i]==1) sub_flag=0;
	if(sub_flag) {
		sub::solve();
		return 0;
	}
	int lastans = 0,a,b,c;
	for (int i = 1; i <= m; i++) {
		a=A[i],b=B[i];
		if(op[i]==1) c=C[i];
		if (f && lastans != -1) {
			a ^= lastans;
			b ^= lastans;
			c ^= lastans;
		}
		if (op[i] == 1) {
			assign(a, b, c);
		}
		else {
			printf("%d\n", lastans = query(a, b));
		}
	}
	return 0;
}

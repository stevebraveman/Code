#include<iostream>
#include<algorithm>
#define For(i) for(register int i=1; i<=n; i++)
using namespace std;
int n;
struct point {
	int begin;
	int end;
} p[1000005];
void init() {
	cin>>n;
	For(i) {
		cin>>p[i].begin>>p[i].end;
	}
}
bool cmp(point a,point b) {
		return a.end<=b.end;
}
void solve() {
	int ans=0;
	int t=-1;
	For(i) {
		if(p[i].begin>=t) {
			ans++;
			t=p[i].end;
		}
	}
	cout<<ans<<endl;
}
int main() {
	init();
	sort(p+1,p+1+n,cmp);
	/*For(i){
		cout<<p[i].begin<<" "<<p[i].end<<endl;
	}*/
	solve();
	return 0;
}

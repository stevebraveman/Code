#include <cstdio>
#include <cstring>
#include <limits>
#include <queue>
#define MAXN 1000
using namespace std;
int n,m;
int next[MAXN + 1];
int first[MAXN + 1];
int u[MAXN + 1],v[MAXN + 1];
int w[MAXN + 1];
int d[MAXN + 1];
int fa[MAXN + 1];
typedef pair<int,int> pii;
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n ; i++) {
		first[i] = 0;
	}
	for(int e = 1; e <= m; e++) {
		scanf("%d%d%d",&u[e],&v[e],&w[e]);
		next[e] = first[u[e]];
		first[u[e]] = e;
	}
	d[1] = 0,fa[1] = 1;
	const int inf = std::numeric_limits<int>::max();
	for(int i = 2; i <= n; i++) {
		d[i] = inf;
		fa[i] = 0;
	}
	priority_queue <pii,vector<pii>,greater<pii> >q;
	bool done[MAXN + 1];
	memset(done,0,sizeof(done));
	q.push(make_pair(d[1],1));
	while(!q.empty()) {
		pii u = q.top();
		q.pop();
		int x = u.second;
		if(done[x]) continue;
		done[x] = true;
		for(int e = first[x]; e != 0; e = next[e]) {

			if(d[v[e]] > d[x] + w[e]) {
				d[v[e]] = d[x] + w[e];
				fa[v[e]] = x;
				q.push(make_pair(d[v[e]],v[e]));
			}

		}
	}
	for(int i = 1; i <= n; i++) {
		printf("%d ",d[i]);
	}
	return 0;
}

#include<cstdio>
#define MAXN 2000002
using namespace std;
int q[MAXN]={0},n,m,head=0,tail=0,p[MAXN];
int main() {
    scanf("%d%d", &n, &m);
    scanf("%d", &q[tail]);
    tail++;
	printf("0\n");
    for(int i=1; i<n; i++) {
        if(i-p[head]>m) head++;
        printf("%d\n", q[head]);
        int x;
        scanf("%d", &x);
        while(tail>head&&x<q[tail-1]) 
            tail--;
        q[tail]=x; p[tail]=i;
        tail++;
    }
    return 0;
}

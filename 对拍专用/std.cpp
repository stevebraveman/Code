#include<cstdio>
#include<algorithm>
#define Rint register int
using namespace std;
const int N = 100003, INF = 2147483647;
int n, m, q, fa[N];
inline int getfa(int x){
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
struct Treap {
    int id, key, prio, size, cnt;
    Treap *ch[2];
} *root[N], *top, *null;
inline int rand(){
    static int seed = 20050915;
    return seed = (((seed * 19260817ll) % 2147483647 ^ 20050818) + 998244353) % 2147483647;
}
inline void init(){
    top = null = new Treap [N * 20];
    null -> key = null -> prio = INF;
    null -> size = null -> cnt = 0;
    null -> ch[0] = null -> ch[1] = null;
    for(Rint i = 1;i <= n;i ++) root[i] = null;
}
inline void pushup(Treap *&x){
    x -> size = x -> ch[0] -> size + x -> ch[1] -> size + x -> cnt;
}
inline Treap* crepoint(int key, int id){
    top ++;
    top -> key = key; top -> id = id; top -> prio = rand();
    top -> cnt = top -> size = 1;
    top -> ch[0] = top -> ch[1] = null;
    return top;
}
inline void rotate(Treap *&x, int d){
    Treap *y = x -> ch[d ^ 1];
    x -> ch[d ^ 1] = y -> ch[d];
    y -> ch[d] = x;
    y -> size = x -> size;
    pushup(x);
    x = y;
}
inline void insert(Treap *&x, int key, int id){
    if(x == null){x = crepoint(key, id); return;}
    if(x -> key == key){x -> cnt ++; pushup(x); return;}
    int d = key > x -> key;
    insert(x -> ch[d], key, id);
    if(x -> prio > x -> ch[d] -> prio) rotate(x, d ^ 1);
    pushup(x);
}
inline int atrank(int i, int x){
    Treap *now = root[i];
    if(x > now -> size) return -1;
    while(true){
        int minused = now -> ch[0] -> size + now -> cnt;
        if(x > now -> ch[0] -> size && x <= minused) return now -> id;
        else if(x <= now -> ch[0] -> size) now = now -> ch[0];
        else {
            x -= minused;
            now = now -> ch[1];
        }
    }
}
inline void dfs(int i, Treap *x){
    if(x == null) return;
    insert(root[i], x -> key, x -> id);
    dfs(i, x -> ch[0]);
    dfs(i, x -> ch[1]);
}
inline void comb(int a, int b){
    if(!a || !b) return;
    int fa1 = getfa(a), fa2 = getfa(b);
    if(root[fa1] -> size < root[fa2] -> size) swap(fa1, fa2);
    dfs(fa1, root[fa2]);
    fa[fa2] = fa1;
}
int main(){
    scanf("%d%d", &n, &m);
    init();
    for(Rint i = 1;i <= n;i ++){
        int x;
        scanf("%d", &x);
        insert(root[i], x, i);
        fa[i] = i;
    }
    while(m --){
        int a, b;
        scanf("%d%d", &a, &b);
        comb(a, b);
    }
    scanf("%d", &q);
    while(q --){
        int x, y;
        char opt[5];
        scanf("%s%d%d", opt, &x, &y);
        if(opt[0] == 'Q')
            printf("%d\n", atrank(getfa(x), y));
        else
            comb(x, y);
    }
}
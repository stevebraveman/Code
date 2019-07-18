// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>
#define ll long long
#define Fill(a, b) memset(a, b, sizeof(a))
std::map <int, int> pw;
int gcd(int x, int y) {
    return (!y) ? x : gcd(y, x % y);
}
int qpow(ll x, ll y, int p) {
    ll ret = 1;
    for(; y; x = x * x % p, y >>= 1) if(y & 1) ret = ret * x % p;
    return ret;
}
int a, b, p;
int bsgs() {
    if(b == 1) return 0;
    pw.clear();
    int cnt = 0, t = 1, s, x, m;
    for(int d = gcd(a, p); d != 1; d = gcd(a, p)) {
        if(b % d) return -1;
        ++cnt, b /= d, p /= d, t = 1LL * t * a / d % p;
        if(b == t) return cnt;
    }
    s = b, m = sqrt(p) + 1;
    for(int i = 0; i < m; ++i) {
        pw[s] = i;
        s = 1LL * s * a % p;
    }
    x = qpow(a, m, p), s = t;
    for(int i = 1; i <= m; ++i) {
        s = 1LL * s * x % p;
        if(pw.count(s)) return i * m - pw[s] + cnt;
    }
    return -1;
}
int ans;
int main() {
    while (1) {
		scanf("%d%d%d", &a, &p, &b);
        if (!(a + p + b)) {
            break;
        }
        a %= p, b %= p, ans = bsgs();
        if (ans < 0) {
            puts("No Solution");
        }
        else {
            printf("%d\n", ans);
        }
    }
    return 0;
}

#pragma GCC optimize(3)
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define delta 0.99998
#define MAXN 100010
#define random(a, b) ((rand() % (b - a + 1)) + (a))
int n, m, c, p[MAXN], G[100][100], tot, nowG[100][100], _p, chG[100][100];
template <typename Tp>
void swap(Tp &a, Tp &b) {
    Tp t = a;
    a = b;
    b = t;
}
int Q() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (nowG[i][j] != nowG[i][j - 1]) ans++;
            if (nowG[i][j] != nowG[i - 1][j]) ans++;
            if (nowG[i][j] != nowG[i][j + 1]) ans++;
            if (nowG[i][j] != nowG[i + 1][j]) ans++;
        }
    }
    return ans;
}
void copy(bool flag) {
    if (flag) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                chG[i][j] = nowG[i][j];
            }
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            G[i][j] = chG[i][j];
        }
    }
    return;
}
void SA() {
    long double t = 1.0;
    _p = tot;
    while (t > 1e-14) {
        int x1 = random(1, n);
        int y1 = random(1, m);
        int x2 = random(1, n);
        int y2 = random(1, m);
		if (nowG[x1][y1] == nowG[x2][y2]) continue;
        std::swap(nowG[x1][y1], nowG[x2][y2]);
        int now = Q();
        int dt = now - _p;
        if (dt < 0 || (exp(-dt * 1.0 / t) * RAND_MAX > ((rand() % 1000000) / 1000000.0))) {
            copy(1);
			_p = now;
        }
		else {
			std::swap(nowG[x1][y1], nowG[x2][y2]);
		}
        if (_p <= tot) {
            tot = _p;
            copy(0);
        }
        t *= delta;
    }
}
int main() {
    srand(19260817);
    // srand(rand() * rand());
    // srand(rand());
	// srand(rand());
	// srand(rand());
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 1; i <= c; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int col = rand() % c + 1;
            while (!p[col]) col = rand() % c + 1;
            G[i][j] = col;
            nowG[i][j] = col;
            p[col]--;
        }
    }
    tot = Q();
    _p = tot;
    SA();
	SA();
	SA();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", G[i][j]);
        }
        puts("");
    }
    return 0;
}
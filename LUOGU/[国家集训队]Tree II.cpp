#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ls(x) c[x][0]
#define rs(x) c[x][1]
#define MAXN 100010
#define MOD 51061
#define ll long long
ll si[MAXN], val[MAXN], st[MAXN], c[MAXN][2], f[MAXN], sz[MAXN], mul[MAXN],
    add[MAXN];
bool r[MAXN];
ll n, m, u, v, a, b;
char op[5];
bool ifr(ll p) { return ls(f[p]) == p || rs(f[p]) == p; }
void pd(ll p) {
  si[p] = (si[ls(p)] + si[rs(p)] + val[p]) % MOD;
  sz[p] = sz[ls(p)] + sz[rs(p)] + 1;
}
void addmodify(ll p, ll c) {
  si[p] = (si[p] + c * sz[p]) % MOD;
  val[p] = (val[p] + c) % MOD;
  add[p] = (add[p] + c) % MOD;
}
void mulmodity(ll p, ll c) {
  si[p] = (si[p] * c) % MOD;
  val[p] = (val[p] * c) % MOD;
  add[p] = (add[p] * c) % MOD;
  mul[p] = (mul[p] * c) % MOD;
}
void flit(ll p) {
  ll t = ls(p);
  ls(p) = rs(p);
  rs(p) = t;
  r[p] ^= 1;
}
void pushd(ll p) {
  if (mul[p] != 1) {
    if (ls(p))
      mulmodity(ls(p), mul[p]);
    if (rs(p))
      mulmodity(rs(p), mul[p]);
    mul[p] = 1;
  }
  if (add[p]) {
    if (ls(p))
      addmodify(ls(p), add[p]);
    if (rs(p))
      addmodify(rs(p), add[p]);
    add[p] = 0;
  }
  if (r[p]) {
    if (ls(p))
      flit(ls(p));
    if (rs(p))
      flit(rs(p));
    r[p] = 0;
  }
}
void rotate(ll p) {
  ll x = f[p], y = f[x], k = rs(x) == p, w = c[p][!k];
  if (ifr(x))
    c[y][c[y][1] == x] = p;
  c[p][!k] = x;
  c[x][k] = w;
  if (w)
    f[w] = x;
  f[x] = p;
  f[p] = y;
  pd(x);
}
void splay(ll p) {
  ll y = p, z = 0;
  st[++z] = y;
  while (ifr(y))
    st[++z] = y = f[y];
  while (z)
    pushd(st[z--]);
  while (ifr(p)) {
    y = f[p];
    z = f[y];
    if (ifr(y)) {
      rotate((ls(y) == p) ^ (ls(z) == y) ? p : y);
    }
    rotate(p);
  }
  pd(p);
}
void access(ll p) {
  for (ll i = 0; p; p = f[i = p]) {
    splay(p);
    rs(p) = i;
    pd(p);
  }
}
void makeroot(ll p) {
  access(p);
  splay(p);
  flit(p);
}
ll findr(ll p) {
  access(p);
  splay(p);
  while (ls(p)) {
    pushd(p);
    p = ls(p);
  }
  splay(p);
  return p;
}
void split(ll x, ll y) {
  makeroot(x);
  access(y);
  splay(y);
}
void link(ll x, ll y) {
  makeroot(x);
  f[x] = y;
}
void cut(ll x, ll y) {
  makeroot(x);
  if (findr(y) == x && f[y] == x && !ls(y)) {
    f[y] = rs(x) = 0;
    pd(x);
  }
}
int main() {
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i < n; i++) {
    scanf("%lld%lld", &u, &v);
    link(u, v);
  }
  for (int i = 1; i <= n; i++) {
    val[i] = mul[i] = sz[i] = 1;
  }
  while (m--) {
    scanf("%s", op);
    if (op[0] == '+') {
      scanf("%lld%lld%lld", &u, &v, &a);
      split(u, v);
      addmodify(v, a);
    }
    if (op[0] == '-') {
      scanf("%lld%lld%lld%lld", &u, &v, &a, &b);
      cut(u, v);
      link(a, b);
    }
    if (op[0] == '*') {
      scanf("%lld%lld%lld", &u, &v, &a);
      split(u, v);
      mulmodity(v, a);
    }
    if (op[0] == '/') {
      scanf("%lld%lld", &u, &v);
      split(u, v);
      printf("%lld\n", si[v]);
    }
  }
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#define MAXN 5000
int phi[MAXN + 10], tot, p[MAXN + 10];
bool chk[MAXN + 10];
void Seive() {
	phi[1] = 1;
	chk[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (!chk[i]) {
			p[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= tot && i * p[j] <= MAXN; j++) {
			chk[i * p[j]] = 1;
			if (i % p[j]) {
				phi[i * p[j]] = phi[i] * phi[p[j]];
			}
			else {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
		}
	}
}
int n;
int main() {
	Seive();
	scanf("%d", &n);
	printf("%d", phi[phi[n]]);
}
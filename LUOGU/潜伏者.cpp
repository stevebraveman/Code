#include <iostream>
#include <cstdio> 
#include <cstring>
#define MAXN 10010
char la[MAXN], a[MAXN], b[MAXN], c[MAXN];
int s;
bool d[MAXN], f[MAXN];
int z(char a) {
	return a - 'A' + 1;
}
int main() {
	std:: cin >> a >> b >> c;
	for (int i = 0; i < strlen(a); i++) {
		if (!d[z(a[i])] && !f[z(b[i])]) {
			la[z(a[i])] = b[i];
			d[z(a[i])] = f[z(b[i])] = 1;
			s++;
		}
		else if (la[z(a[i])] != b[i]) {
			printf("Failed");
			return 0;
		}
	}
	if (s != 26) {
		puts("Failed");
		return 0;
	}
	for (int i = 0; i < strlen(c); i++) {
		std::cout << la[z(c[i])];
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	string s;
	int a;
	cin >> a;
	while (a--) {
		cin >> s;
		if (s == "WMG") {
			puts(">+9");
		}
		if (s == "OW") {
			puts("-9 to -31");
		}
		if (s == "DG") {
			puts("-31 to -42");
		}
		if (s == "MG") {
			puts("-42 to -54");
		}
		if (s == "LG") {
			puts("-54 to -64");
		}
		if (s == "B") {
			puts("-64 to -70");
		}
		if (s == "W") {
			puts("-70 to -76");
		}
		if (s == "CMG") {
			puts("-76 to -81");
		}
		if (s == "CDG") {
			puts("<=-81");
		}
	}
}
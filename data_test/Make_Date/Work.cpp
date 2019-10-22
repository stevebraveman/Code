#include <bits/stdc++.h>
#include <windows.h>
int main() {
	for (int i = 41; i <= 45; i++) {
		char se[50], yt[50];
		memset(se, 0, sizeof(se));
		memset(yt, 0, sizeof(yt));
		sprintf(yt, "data.exe > data%d.in", i);
		system(yt);
		// system("std");
		sprintf(se, "std.exe < data%d.in > data%d.out", i, i);
		system(se);
	}
}
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
map <string,string> fa;
string find(string x) {
	if (x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}
int main() {
	char c;
	cin >> c;
	string b;
	while (c != '$'){
		string a;
		cin >> a;
		if (c == '#') {
			b = a;
			if (fa[a] == "") fa[a] = a;
		}
		if (c == '+') {
			// a = find(a);
			// string k = find(b);
			fa[a] = b;
		}
		if (c == '?') {
			cout << a << " " << find(a) <<"\n";
		}
		cin >> c;
	}
	return 0;
}
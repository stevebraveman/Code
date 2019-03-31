#include<iostream>
#include<map>
#include<cstring>
using namespace std;
map<int, bool> hash;
int main() {
	int t, n, a[50005];
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; ++i) {
			if (hash[a[i]] == 1) {
				continue;
			}
			else {
				hash[a[i]] = 1;
				cout << a[i] << " ";
			}
		}
		memset(a, 0, sizeof(a));
		hash.clear();
	}
}
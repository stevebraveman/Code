#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
struct note {
	int hp;
	int tm;
	char name[2];
	std::queue <char> ti;
	bool die;
	bool pdz;
}pl[11];
std::queue <char> tt;
int n , m , fpn;
char ket[2002] , lati;
char dead[] = {"DEAD"};
void work() {
	int i = 0;
	while (1) {
		i++;
		if (i > n) i = 1;
		if (pl[i].die) continue;
		char k = pl[i].q.top();
		if (k == )
	}
}
int main(){
	std::cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		std::cin >> pl[i].name;
		if (pl[i].name == "MP") {
			pl[i].tm = 1;
		}
		if (pl[i].name == "FP") {
			pl[i].tm = 2;
			fpn++;
		}
		if (pl[i].name == "ZP") {
			pl[i].tm = 3;
		}
		for(int j = 1 ; j <= 4 ; j++){
			char l;
			cin >> l;
			pl[i].q.push(l);
		}
		pl[i].hp = 4;
	}
	for(int i = 1 ; i <= m ; i++){
		char h;
		cin >> h;
		if (i == m) lati = h;
		tt.push(h);
	}
}

#include<bits/stdc++.h>
using namespace std;
int main() {
	while(1) {
		clock_t t1 , t2 , t3;
		system("data > data.in");
		system("std < data.in > 2.out");
		t1 = clock();
		system("mine < data.in > 1.out");
		t2 = clock();
		if(system("fc 1.out 2.out > nul")) {
			puts("WA");
			system("fc 1.out 2.out");
			system("pause");
		}
		else {
			puts("AC");
			printf("%.2f\n", (double)(t2 - t1) * 1000 / CLOCKS_PER_SEC);
			// system("pause");
		}
	}
	return 0;
}

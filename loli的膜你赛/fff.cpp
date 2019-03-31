#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
bool p1;
std::map<int, int> hs;
int main() {
    for (int i = 1; i <= 200000; i++) {
        hs[i] = i;
    }
    bool p2;
    printf("%.4f MB\n", (double)(&p2 - &p1) / 1024.0 / 1024.0);
}
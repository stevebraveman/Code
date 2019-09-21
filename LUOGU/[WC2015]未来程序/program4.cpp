#include <iostream>

const int N = 5000, inf = 0x3F3F3F3F;
int n, m, type;
bool data[N + 11][N + 11];

int seed;
int next_rand(){
	static const int P = 1000000007, Q = 83978833, R = 8523467;
	return seed = ((long long)Q * seed % P * seed + R) % P;
}

void generate_input(){
	std::cin >> n >> m >> type;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			data[i][j] = bool((next_rand() % 8) > 0);
}

long long count1(){
	long long ans = 0LL;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(data[i][j])
				for(int k = 0; k < n; k++)
					for(int l = 0; l < m; l++)
						if(data[k][l] && (k != i || l != j))
							ans++;
	return ans;
}

int abs_int(int x){
	return x < 0 ? -x : x;
}

long long count2(){
	long long ans = 0LL;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(data[i][j]){
				int level = inf;
				for(int k = 0; k < n; k++)
					for(int l = 0; l < m; l++)
						if(!data[k][l]){
							int dist = abs_int(k - i) + abs_int(l - j);
							if(level > dist)
								level = dist;
						}
				ans += level;
			}
	return ans;
}

int main(){
	std::cin >> seed;
	for(int i = 0; i < 10; i++){
		generate_input();
		std::cout << (type == 1 ? count2() : count1()) << std::endl;
	}
	return 0;
}

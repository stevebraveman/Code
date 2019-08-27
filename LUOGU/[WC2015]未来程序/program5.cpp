#include <iostream>

const int N = 5011;
int n, m;
bool data[N][N];

int seed;
int next_rand(){
	static const int P = 1000000007, Q = 83978833, R = 8523467;
	return seed = ((long long)Q * seed % P * seed + R) % P;
}

void generate_input(){
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			data[i][j] = bool((next_rand() % 8) > 0);
}

bool check(int x1, int y1, int x2, int y2){
	bool flag = true;
	for(int i = x1; i <= x2; i++)
		for(int j = y1; j <= y2; j++)
			if(!data[i][j])
				flag = false;
	return flag;
}

long long count3(){
	long long ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			for(int k = i; k < n; k++)
				for(int l = j; l < m; l++)
					if(check(i, j, k, l))
						ans++;
	return ans;
}

int main(){
	std::cin >> seed;
	for(int i = 0; i < 10; i++){
		generate_input();
		std::cout << count3() << std::endl;
	}

	return 0;
}

#include <stdio.h>
#include <string.h>
#include <iostream>
#define Min(X,Y) ((X)<(Y)?(X):(Y))
#define Max(X,Y) ((X)>(Y)?(X):(Y))
#define GC getchar()
#define Clean(X,K) memset(X,K,sizeof(X))
using namespace std ;
const int Maxn = 100005 ;
int N , M , A[Maxn] , Aim = 0 , Ans , Fn[Maxn][2];

bool Fl ;
void DFS (int Stp , int Now) {
//	if (Aim == 5) {
//		for (int i =1 ; i <= N; ++ i) cout << A[i] <<' ';
//		cout << '|'<<Stp<<' '<<Aim<<' '<<Now ;
//		cout <<endl;
//	}

	if (Fl || Stp + N - Now > Ans) return ;
	if (Now >= N) {
		Fl = true ;
		return ;
	}
	for (int i = 2 ; i < N; ++ i) {
		int Tmp = A[i] ;
		if (Tmp < A[i - 1] || Tmp < A[i + 1]) {
			A[i] = Max (A[i - 1] , A[i + 1]) ;
			DFS (Stp + 1 , Now + (Tmp == Aim ? -1 : 0) + (A[i] == Aim ? 1 : 0) ) ;
			A[i] = Tmp ;
		}
		if (Tmp > A[i - 1] || Tmp > A[i + 1]) {
			A[i] = Min (A[i - 1] , A[i + 1]) ;
			DFS (Stp + 1 , Now + (Tmp == Aim ? -1 : 0) + (A[i] == Aim ? 1 : 0) ) ;
			A[i] = Tmp ;
		}
	}
	int Tmp = A[1] ;
	if (A[1] < A[N] || A[1] < A[2]) {
		A[1] = Max (A[N] , A[2]) ;
		DFS (Stp + 1 , Now + (Tmp == Aim ? -1 : 0) + (A[1] == Aim ? 1 : 0)) ;
		A[1] = Tmp ;
	}

	if (A[1] > A[N] || A[1] > A[2]) {
		A[1] = Min (A[N] , A[2]) ;
		DFS (Stp + 1 , Now + (Tmp == Aim ? -1 : 0) + (A[1] == Aim ? 1 : 0)) ;
		A[1] = Tmp ;
	}
	Tmp = A[N] ;
	if (A[N] > A[1] || A[N] > A[N - 1]) {
		A[N] = Min (A[N - 1] , A[1]) ;
		DFS (Stp + 1 , Now + (Tmp == Aim ? -1 : 0) + (A[N] == Aim ? 1 : 0)) ;
		A[N] = Tmp ;
	}

	if (A[N] < A[1] || A[N] < A[N - 1]) {
		A[N] = Max (A[N - 1] , A[1]) ;
		DFS (Stp + 1 , Now + (Tmp == Aim ? -1 : 0) + (A[N] == Aim ? 1 : 0)) ;
		A[N] = Tmp ;
	}
}
int main () {
	scanf("%d%d", &N, &M);
	for (int i = 1 ; i <= N; ++ i) scanf("%d", &A[i]);
	for (Aim = 1 ; Aim <= M ; ++ Aim) {
		int FromG = 0 ;
		for (int i = 1 ; i  <= N; ++ i)if (Aim == A[i]) ++ FromG ;
		if (FromG == 0) {
			printf ("-1 ") ;
			continue ;
		}
		Fl = false ;
		for (Ans = 0 ; Ans <= (N << 1) - 2 ; ++ Ans) {
			Fl = false ;
			DFS (0 , FromG ) ;
			if (Fl) {
				printf ("%d " , Ans) ;
				break;
			}
		}
	}
	fclose (stdin) , fclose (stdout) ;
	return 0 ;
}

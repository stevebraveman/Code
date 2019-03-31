#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 1000002
using namespace std;
char a[MAXN];
int z(char a){
	if(a=='('||a==')'){
		return 1;
	}
	if(a=='['||a==']'){
		return 2;
	}
}
struct Stack{
	int s[MAXN];
	int h;
	int top(){
		return s[h];
	}
	void pop(){
		h--;
	}
	void push(int a){
		h++;
		s[h]=a;
	}
	bool empty(){
		return h==0?1:0;
	}
	void em(){
		h=0;
	}
};
int main(){
	scanf("%s",a);
	int l=strlen(a);
	for(int i=0;i<l;i++){
		
	}
}

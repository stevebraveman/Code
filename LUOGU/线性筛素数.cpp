#include<iostream>
#include<cstdio>
#define SIZE 1000000
int main()
{
    int check[SIZE] = {0};//元素值为0代表是素数
    int prime[SIZE] = {0};
    int pos=0;
    int flag;
    for (int i = 2 ; i < SIZE ; i++)
    {
        if (!check[i])//如果是素数
            prime[pos++] = i;

        for (int j = 0 ; j < pos && i*prime[j] < SIZE ; j++)
        {
            check[i*prime[j]] = 1;//筛掉
            //标注一
            if (i % prime[j] == 0)
                break;
        }
    }
    return 0;
}

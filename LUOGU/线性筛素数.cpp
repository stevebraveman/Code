#include<iostream>
#include<cstdio>
#define SIZE 1000000
int main()
{
    int check[SIZE] = {0};//Ԫ��ֵΪ0����������
    int prime[SIZE] = {0};
    int pos=0;
    int flag;
    for (int i = 2 ; i < SIZE ; i++)
    {
        if (!check[i])//���������
            prime[pos++] = i;

        for (int j = 0 ; j < pos && i*prime[j] < SIZE ; j++)
        {
            check[i*prime[j]] = 1;//ɸ��
            //��עһ
            if (i % prime[j] == 0)
                break;
        }
    }
    return 0;
}

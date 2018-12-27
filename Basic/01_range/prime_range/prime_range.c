/*
dark di 在做数学题目的时候发现了一个现象，2 个相邻的素数之间存在一
个区间，他把这个区间称为非素数区间，那么 dark di 想知道，给定一个正整数x，
x所在的非素数区间长度是多少呢？
例如 23 和 29 是 2 个相邻的素数，他们之间的非素数区间是[24,28]，长度
是 5，假设 x=27，那么 x 所在的非素数区间长度就是 5。
如果 x 是一个素数，则答案是 0。
注意：素数指的是除了 1 和它本身以外不再有其他因数的自然数。

第一行输入一个正整数 T，表示接下去有 T 次询问。
接下去 T 行，每行一个正整数 x。(x<=100000)。
对于 30%的数据，T<=5，x<=100
对于 80%的数据，T<=10，x<=5000
对于 100%的数据，T<=100000，x<=100000
*/

#include <stdio.h>

#define N 100005
short is_not_prime[N] = { 0 }; // all is prime

void Sieve()
{
    int m, k;
    for (m = 2; m * m <= N; m++)
    {
        if (!is_not_prime[m])
        {
            for (k = m + m; k <= N; k += m)
            {
                if (!is_not_prime[k])
                {
                    is_not_prime[k] = 1;
                }
            }
        }
    }
}

int LowerBound(int x)
{
    while (is_not_prime[x - 1])
    {
        x--;
    }
    return x;
}

int UpperBound(int x)
{
    while (is_not_prime[x + 1])
    {
        x++;
    }
    return x;
}

int main(int argc, char const *argv[])
{
    Sieve();

    int t, x;
    scanf("%d", &t);
    
    while (t-- > 0)
    {
        scanf("%d", &x);
        if (x == 1 || !is_not_prime[x])
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", UpperBound(x) - LowerBound(x) + 1);
        }
    }

    return 0;
}

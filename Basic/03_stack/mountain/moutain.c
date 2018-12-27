// Silchen 最近爱上了爬山，现在有 n 座山排成一列，每座山有一个高度 hi。现在 Silchen 想知
// 道他站在每座山上最多能向前看到多少座山。向前看是只在第 i 座山上往第 i+1 . . . n 座山看。
// Silchen 能看到的山有两个要求：
// 1、高度小于他现在所在山
// 2、两座山之间没有高度大于等于他所在山
// Silchen 想请你帮忙解决这个问题，他只要你告诉他能看到的山的总和。

// 第一行一个正整数 n（1<=n<=300000）。
// 接下来 n 个正整数，第 i 个表示 hi（1<=hi<=10000000）
// 对于 40%的数据：1<=n<=1000
// 对于 70%的数据：1<=n<=300000
// 对于 100%的数据：1<=n<=5000000

#include <stdio.h>

#define N 5000005
int increasingStack[N];

int main()
{
    long long sum = 0;
    int hi;
    int n;
    int size = 0;

    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d", &hi);
        while (size > 0 && hi >= increasingStack[size - 1])
        {
            size--;
        }

        sum += size;
        increasingStack[size++] = hi;
    }

    printf("%lld", sum);
    return 0;
}

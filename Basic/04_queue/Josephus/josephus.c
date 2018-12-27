// 实验室里一群小仓鼠要选出仓鼠王。仓鼠王的选择方法是：让 N 只候选仓鼠围成一圈，
// 从某位置起顺序编号为 1~N 号。从第 1 号开始报数，每轮从 1 报到 3，凡报到 3 的仓鼠即退
// 出圈子，接着又从紧邻的下一只仓鼠开始同样的报数。如此不断循环，最后剩下的一只仓鼠
// 就选为仓鼠王。请问是原来第几号仓鼠当选仓鼠王？

// 输入数据 n(n<=1000)表示有 n 只仓鼠在实验室中。

#include <stdio.h>

#define N 1005
int next[N];

void Josephus(int n, int m)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        next[i] = i+1;
    }
    k = n-1;
    next[k] = 0;

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            k = next[k];
        }
        next[k] = next[next[k]];
    }
    printf("%d", next[k] + 1);
}

void EasyJose(int n, int m)
{
    int i, k = 1;
    for (i = 1; i <= n; i++)
    {
        k = (k + m) % i; // i.th winner from i-1.th
    }
    printf("%d", k + 1);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    // Josephus(n, 3);
    EasyJose(n, 3);
    return 0;
}

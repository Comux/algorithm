/*
 * 有一天，杰哥在数轴上玩游戏，杰哥有 N 个区间，第 i 个区间的端点是 li
 * 和 ri,即第 i 个区间覆盖了[li,ri]，他想知道是否存在一个编号最小的区间包
 * 含所有的区间。如果存在，则输出区间编号，否则输出"-1". 区间包含指的是，
 * 假设一个区间[a,b]包含另外一个区间[c,d]，需要满足a<=c<=d<=b.
 * 
 * 第一行一个整数 N 表示区间个数，N<=100000
 * 接下去N行每行2个整数li,ri表示第i个区间的端点 ，
 * 1<=li<=ri<=1000000000
 * 对于 30%的数据，N<=100, 1<=li<=ri<=100
 * 对于 80%的数据，N<=1000, 1<=li<=ri<=1000
 * 对于 100%的数据，N<=100000, 1<=li<=ri<=1000000000
 */

#include <stdio.h>
#define MIN 1
#define MAX 100000000

int main(int argc, char const *argv[])
{
    int i;
    int n, li, ri;
    int min = MAX, max = MIN;
    int index = -1;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &li, &ri);
        if ((li < min && ri >= max) || (li <= min && ri > max))
        {
            index = i + 1;
            min = li;
            max = ri;
        }
        else if (li < min && ri < max)
        {
            index = -1;
            min = li;
        }
        else if (li > min && ri > max)
        {
            index = -1;
            max = ri;
        }
        else if (index == -1 && li == min && ri == max)
        {
            index = i + 1;
        }
    }

    printf("%d", index);
    return 0;
}

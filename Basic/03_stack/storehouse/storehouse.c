// silchen 临时担任了仓库管理员，要负责记录当前货物的情况，silchen 对仓库有三种操
// 作：
// 1. 放入一个重量为 x 的货物
// 2. 取出一个货物，货物取出顺序为先进后出
// 3. 统计获得当前仓库中重量最重的货物有多重并输出
// 当仓库为空时应该忽略取货操作，当仓库为空查询时应该输出 0 。
// 现在告诉你 n 个操作，要求你帮助 silchen 实现这个任务

// 第一行一个正整数 n（1<=n<=100000）。
// 接下来 n 行，
// 每行先是一个整数 o（1<=o<=3），代表三种操作，
// 如果 o=1，那么这一行还会跟一个整数 x（1<=x<=100000）代表货物重量。
// 如果 o=2，代表取出一个货物
// 如果 o=3，代表查询最重货物重量
// 对于 40%的数据：1<=n<=1000
// 对于 100%的数据：1<=n<=100000

// 第一行一个正整数 n（1<=n<=100000）。
// 接下来 n 行，
// 每行先是一个整数 o（1<=o<=3），代表三种操作，
// 如果 o=1，那么这一行还会跟一个整数 x（1<=x<=100000）代表货物重量。
// 如果 o=2，代表取出一个货物
// 如果 o=3，代表查询最重货物重量
// 对于 40%的数据：1<=n<=1000
// 对于 100%的数据：1<=n<=100000

// inline_min: max_stack
// offline_min: UFset

#include <stdio.h>

#define N 100005
int house[N];
int maxStack[N];

int main(int argc, char *argv[])
{
    int n;
    int size1 = 0;
    int size2 = 0;

    int o;
    int x;
    int max_weight = 0;

    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d", &o);
        if (o == 1) // add something
        {
            scanf("%d", &x);
            house[size1++] = x;
            if (x >= max_weight)
            {
                max_weight = x;
                maxStack[size2++] = x;
            }
        }
        else if (o == 2) // remove something
        {
            if (size1 != 0)
            {
                x = house[--size1];
                if (x == maxStack[size2 - 1])
                {
                    size2--;
                    max_weight = (size2 ? maxStack[size2 - 1] : 0);
                }
            }
        }
        else // get max weight
        {
            printf("%d\n", max_weight);
        }
    }

    return 0;
}

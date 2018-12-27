/*
我们把一个好的字符串的定义为，如果合并了所有连续的相等字符，得到的
字符串是回文。
例如，“aabbbaa”是好的字符串，因为合并后的步骤将变成“aba”。
给定一个字符串，必须找到两个值：
偶数长度的好的子串数；
奇数长度的好的子串数。

输入的第一行包含一个长度为 n 的单一字符串
字符串的每个字符将是’a’或’b’。
字符长度 n
30 % 的数据 1 <= n <= 1000
100 % 的数据 1 <= n <= 100000

一个字符串是回文，当且仅当把这个字符串翻转后，还和原串一致。
比如“aba”、“abba”是回文串，而“abc”，“abab”就不是。
*/

#include <stdio.h>
#include <string.h>

#define N 100005
char str[N];

int main(void)
{
    int i, j, len;
    int odd_a = 0, even_a = 0;
    int odd_b = 0, even_b = 0;
    int res_odd = 0, res_even = 0;
    scanf("%s", str);
    len = strlen(str);

    // 统计奇数位置上a, b的数量
    for (i = 0; i < len; i += 2)
    {
        if (str[i] == 'a')
            odd_a++;
        else
        	odd_n++;
    }

    // 统计偶数位置上a, b的数量
    for (i = 1; i < len; i += 2)
    {
        if (str[i] == 'a')
            even_a++;
        else
            even_b++;
    }

    // 排列组合
    res_odd = (odd_a - 1) * odd_a / 2 + (even_a - 1) * even_a / 2 
            + (odd_b - 1) * odd_b / 2 + (even_b - 1) * even_b / 2
            + len;
    res_even = odd_a * even_a + odd_b * even_b;

    printf("%d %d", res_even, res_odd);
    return 0;
}

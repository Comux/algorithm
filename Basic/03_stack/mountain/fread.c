#include <stdio.h>
#define MAX 45000005
char buffer[MAX] = { 0 };
inline void readInt(int *rst)
{
    static int i = 0;
    static const char ISNUM = 16;
    static const char TONUM = 15;
    for (*rst = buffer[++i] & TONUM; buffer[++i] & ISNUM;)
    {
        *rst *= 10;
        *rst += buffer[i] & TONUM;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, i = 0,t;
    long long sum = 0;
    static int height[5000000];
    static int cansee[5000000];
    scanf("%d", &n);
    cansee[n - 1] = n - 1;
    fread(buffer, sizeof(char), MAX, stdin);
    for (i = 0; i < n; i++)
        readInt(&height[i]);
        
    for (i = n - 2; i >= 0; i--)
   {
        t = i;
        while (height[i] > height[t + 1])
            if ((t = cansee[t + 1]) == n - 1)
                break;
        cansee[i] = t;
        sum +=(long long) (t - i);
    }
    printf("%lld", sum);
    return 0;
}

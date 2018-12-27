#include <stdio.h>

#define N 5000005
// stack
int st[N]; 
int sz = 0;

// quick read positive integers
inline int read() 
{
    int data = 0;
    char ch = 0;
    while (ch<'0' || ch>'9') ch = getchar(); // read other char
    while (ch>='0' && ch<='9') data = data*10 + ch-'0', ch=getchar();
    return data;
}

int main()
{
    long long sum = 0;
    int hi, n;

    scanf("%d", &n);
    while (n-- > 0)
    {
        hi = read();
        while (sz > 0 && hi >= st[sz - 1]) {
            sz--;
        }

        sum += size;
        st[sz++] = hi;
    }

    printf("%lld", sum);
    return 0;
}

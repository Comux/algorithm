#include <stdio.h>
#define N 3003

int id[N];
int key[N];

int read()
{
    int data = 0;
    char ch = 0;
    while (ch<'0'||ch>'9') ch=getchar();
    while (ch>='0'&&ch<='9') data=data*10+ch-'0', ch=getchar();
    return data;
}

void JosePhus(int n)
{
    int i, k, m = 1;
    for (i = 0; i < n-1; i++)
    {
        id[i] = i+1;
    }
    
    k = n - 1;
    id[k] = 0;

    for (i = 1; i < n; i++)
    {
        while (m-- > 1)
        {
            k = id[k];
        }
        m = key[ id[k] ];
        printf("%d ", id[k]+1);
        id[k] = id[id[k]];
    }
    printf("%d", id[k]+1);
}

int main(void)
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        key[i] = read();
    }
    JosePhus(n);

    return 0;
}

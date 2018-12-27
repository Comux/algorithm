#include <stdio.h>
#define N 1005

int qA[N], qB[N]; // queue
int fa, ea, fb, eb; // front & end of queue
int ans[N];

int main()
{
    int i, n, v;
    
    fa = ea = fb = eb = 0;

    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d", &v);
        if (v & 1) // odd
            qA[ea++] = v;
        else // even
            qB[eb++] = v;
    }

    // merge two queue into one queue
    n = 0;
    while (fa < ea || fb < eb)
    {
        if (fa < ea) // get two of qA if not empty
        {
            ans[n++] = qA[fa++];
            if (fa < ea)
            {
                ans[n++] = qA[fa++];
            }
        }

        if (fb < eb) // get one of qB if not empty
        {
            ans[n++] = qB[fb++];
        }
    }

    // out put result
    for (i = 0; i < n-1; i++)
        printf("%d ", ans[i]);
    printf("%d", ans[i]);

    return 0;
}

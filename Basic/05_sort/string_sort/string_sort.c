#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101
typedef struct Info
{
    char str[N + 1];
    struct Info *next;
} Node;
typedef Node *Link;

// swap int
#define swap(a, b) do { int t = a; a = b; b = t; } while (0)
// swap pointer Node*
#define swap2(p1, p2) do { Link p = p1; p1 = p2; p2 = p; } while (0)

Node *CreatNode()
{
    Node *p = (Node *)malloc(sizeof(Node));

    if (p == NULL)
    {
        printf("No Memory!");
        exit(-1);
    }

    p->next = NULL;
    return p;
}

void BinSort(int n)
{
    int i, j;
    int b;
    Link p = NULL;
    Link bottom[N + 1];
    Link top[N + 1];
    int count[N + 1] = {0};

    for (b = 1; b <= N; ++b)
    {
        bottom[b] = NULL;
        top[b] = NULL;
    }

    // 创建桶
    for (i = 0; i < n; i++)
    {
        p = CreatNode();
        scanf("%s", p->str);

        b = strlen(p->str);
        if (bottom[b]) // 桶非空
        {
            top[b]->next = p;
            top[b] = p;
        }
        else // 桶
        {
            bottom[b] = top[b] = p;
        }

        count[b]++;
    }

    for (i = 1; i < N; i++)
    {
        for (j = i + 1; j <= N; j++)
        {
            if (count[i] < count[j] ||
               (count[i] == count[j] && count[i] && strlen(bottom[i]->str) > strlen(bottom[j]->str)))
            {
                swap(count[i], count[j]);
                swap2(bottom[i], bottom[j]);
            }
        }
    }

    // 输出结果
    for (b = 1; b <= N; b++)
    {
        if (bottom[b])
        {
            printf("%d", count[b]);
            for (p = bottom[b]; p; p = p->next)
            {
                printf(" %s", p->str);
            }

            putchar('\n');
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    BinSort(n);

    return 0;
}

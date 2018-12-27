#include <cstdio>
#include <iostream>
#include <functional>
#include <queue>

typedef long long LL;

void Solve(std::vector<int>& vec, int n, LL sum)
{
    LL cost = 0;
    int tmp = 0;
    int cnt;
    std::vector<int>::iterator biter = vec.begin();
    std::vector<int>::iterator eiter = vec.end();
    std::make_heap(biter, eiter, std::greater<int>());

    if (!(n & 1) && n > 3)
    {
        *eiter = 0;
        ++eiter;
        std::push_heap(biter, eiter, std::greater<int>());
    }

    while (eiter - biter >= 3)
    {
        tmp = 0;
        std::pop_heap(biter, eiter, std::greater<int>());
        tmp += (*--eiter);
        std::pop_heap(biter, eiter, std::greater<int>());
        tmp += (*--eiter);
        std::pop_heap(biter, eiter, std::greater<int>());
        tmp += (*--eiter);

        *eiter = tmp;
        ++eiter;
        std::push_heap(biter, eiter, std::greater<int>());
        cost += tmp;
    }

    printf("%lld", cost);
}

int main(int argc, char const *argv[])
{
    int n;
    LL sum = 0;
    scanf("%d", &n);
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vec[i]);
        sum = sum + vec[i];
    }
    Solve(vec, n, sum);

    return 0;
}

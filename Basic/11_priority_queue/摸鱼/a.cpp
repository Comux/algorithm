#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef long long LL;
#define min(a,b) (((a) < (b)) ? (a) : (b))

LL GetCost(vector<int> copyed_vec, int m)
{
    LL ret = 0;
    int w = 0;
    vector<int>::iterator biter = copyed_vec.begin();
    vector<int>::iterator eiter = copyed_vec.begin() + m;
    std::make_heap(biter, eiter);

    for (int i = m; i < copyed_vec.size(); i++)
    {
        w++;
        ret += w * copyed_vec.front();
        std::pop_heap(biter, eiter);
        copyed_vec[m - 1] = copyed_vec[i];
        std::push_heap(biter, eiter);
    }

    while (biter < eiter)
    {
        w++;
        ret += w * copyed_vec.front();
        std::pop_heap(biter, eiter);
        --eiter;
    }

    return ret;
}

void Solve(const vector<int>& vec, int n, LL q)
{
    int lo = 1, hi = n-1, mid;
    LL cost;
    int tmp_m = n;

    cost = GetCost(vec, n);
    if (cost > q)
    {
        printf("Impossible");
        return;
    }
    else
    {
        printf("Possible\n");
    }

    while (lo <= hi) // be care for lo equals to hi
    {
        mid = (lo + hi) >> 1;
        cost = GetCost(vec, mid);

        if (cost <= q)
        {
            tmp_m = min(tmp_m, mid);
            hi = mid - 1;
    	} else { // be care tor think about that we can't break from here
            lo = mid + 1;
        }
    }
    printf("%d", tmp_m);
}

int main(void)
{
    int n;
    LL q;
    scanf("%d %lld", &n, &q);
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }

    Solve(vec, n, q);
    return 0;
}

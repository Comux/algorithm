#include <cstdio>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int x;
    long long sum = 0;
    set<int> set;
    while (n-- > 0)
    {
        scanf("%d", &x);
        if (set.find(x) == set.end())
        {
            set.insert(x);
            sum += x;
        }
        else
        {
            set.erase(x);
            sum -= x;
        }
        printf("%lld\n", sum);
    }

    return 0;
}

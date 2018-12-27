#include <cstdio>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, x;
    char ch;
    multiset<int> set;
    multiset<int>::iterator iter;

    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d %c", &x, &ch);
        if (ch == '+')
        {
            iter = set.lower_bound(x + 1);
            set.erase(iter, set.end());
            set.insert(x);
        }
        else // ch == '-'
        {
            iter = set.upper_bound(x - 1);
            set.erase(set.begin(), iter);
            set.insert(x);
        }
    }

    long long ans = 0;
    for (multiset<int>::iterator it = set.begin(); it != set.end(); ++it) { 
        ans += *it;
    }
    printf("%lld", ans);
    return 0;
}





/*


#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	
    int n;
    int x;
    char ch;
    std::multiset<int> set;
    std::multiset<int>::iterator iter;

    std::cin >> n;
    while (n-- > 0)
    {
        std::cin >> x >> ch;
        if (ch == '+')
        {
            iter = set.lower_bound(x + 1);
            set.erase(iter, set.end());
            set.insert(x);
        }
        else // ch == '-'
        {
            iter = set.upper_bound(x - 1);
            set.erase(set.begin(), iter);
            set.insert(x);
        }
    }

    // std::cout << std::accumulate(multiset.begin(), multiset.end(), 0);

    long long ans = 0;
    for (multiset<int>::iterator it = set.begin(); it != set.end(); ++it)
    {
        ans += *it;
    }
    std::cout << ans;
    return 0;
}

*/ 

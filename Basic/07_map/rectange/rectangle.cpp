#include <iostream>
#include <map>
using namespace std;

typedef struct Pair
{
    int w;
    int h;

    Pair(int a, int b):w(a), h(b) {}

    friend bool operator<(const Pair& left, const Pair& right) {
        return (left.w < right.w
                || (left.w == right.w && left.h < right.h));
    }
} Pair;

inline int Gcd(int a, int b)
{
    if (a % b == 0) return b;
    return Gcd(b, a % b);
}

void Init(int n, map<Pair, int>& mp)
{
    int a, b , c, d;
    double k;
    int w, h;
    int gcd;
    int squre_cnt = 0;
    while (n-- > 0)
    {
        std::cin >> a >> b >> c >> d;
        if (c - a == d -b) {
            squre_cnt++;
            continue;
        }

        w = c - a;
        h = d - b;
        gcd = Gcd(w, h);
        w /= gcd;
        h /= gcd;

        if (mp.find(Pair(w, h)) == mp.end()) {
            mp.insert(make_pair(Pair(w, h), 1));
        } else {
            mp[Pair(w, h)]++;
        }
    }
    std::cout << "1:1 have " << squre_cnt << std::endl;
}

int main()
{
    map<Pair, int> mp;
    int n;
    cin >> n;
    Init(n, mp);

    map<Pair, int>::iterator endIter = mp.end();
    cout << mp.size() << endl;
    for (map<Pair, int>::iterator iter = mp.begin(); iter != endIter; iter++) {
        cout << iter->first.w << ":" << iter->first.h << " have " << iter->second << endl;
    }

    return 0;
}

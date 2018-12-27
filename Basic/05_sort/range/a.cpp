#include <cstdio>
#include <algorithm>

const int N = 100000 + 5;
int in[N], out[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; j++ ) {
        scanf("%d %d", &in[j], &out[j]);
    }

    std::sort(in, in + n);
    std::sort(out, out + n);

	int lastDelta = 0, lastStart = -1;;
    int inI = 0, outI = 0;
    int ans = 0, t1 = 1, t2 = 1;
    int delta = 0;

	for (int t = in[0]; t <= out[n-1]; t++)
    {
        for(; inI < n && in[inI] <= t; inI++) { }
        for(; outI < n && out[outI] <= t; outI++) { }

		delta = inI - outI;
        if (delta != lastDelta)
        {
            if (ans < lastDelta)
            {
                ans = lastDelta;
                t1 = lastStart;
                t2 = t;
            }
            lastStart = t;
            lastDelta = delta;
        }
    }
    printf("%d-%d %d", t1, t2, ans);
    return 0;
}

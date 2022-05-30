#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("ptbacnhat.inp", "r", stdin);
    freopen("ptbacnhat.out", "w", stdout);
#endif
    scanf("%lld %lld", &a, &b);
    if (a == 0)
    {
        if (b == 0)
            printf("VO SO NGHIEM\n");
        else
            printf("VO NGHIEM\n");
    }
    else
        printf("PT CO NGHIEM\nX = %.2f", (float)-b / a);
    return 0;
}
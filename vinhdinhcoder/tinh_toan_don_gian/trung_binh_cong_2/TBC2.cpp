#include <bits/stdc++.h>
using namespace std;
double a, b;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("tbc2.inp", "r", stdin);
    freopen("tbc2.out", "w", stdout);
#endif
    b = 0;
    for (int i = 0; i < 4; i++)
    {
        scanf("%lf", &a);
        b = (b * i + a) / (i + 1);
    }
    printf("%.2lf", b);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const double g = 9.8;
double h;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("vantoc.inp", "r", stdin);
    freopen("vantoc.out", "w", stdout);
#endif
    scanf("%lf", &h);
    printf("%0.5lf", sqrt(2 * h * g));
    return 0;
}
#include <iostream>
#include <math.h>
using namespace std;
const double pi = 2 * acos(0.0);
int a, b, r;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("dientichtr.inp", "r", stdin);
    freopen("dientichtr.out", "w", stdout);
#endif
    scanf("%d %d %d", &a, &b, &r);
    printf("%0.2f", a * b - r * r * pi);
    return 0;
}
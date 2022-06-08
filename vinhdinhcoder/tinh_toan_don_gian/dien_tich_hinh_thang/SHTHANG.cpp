#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld a, b;
int alpha;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("shthang.inp", "r", stdin);
    freopen("shthang.out", "w", stdout);
#endif
    scanf("%lf %lf %d", &b, &a, &alpha);
    ld d = (a - b) / 2;
    ld side = d * cos(alpha);
    ld height = sqrt(side * side - d * d);
    // printf("%.4lf\n%.4lf", a + b + side * 2, (a + b) * height / 2);
    cout << side;
    return 0;
}
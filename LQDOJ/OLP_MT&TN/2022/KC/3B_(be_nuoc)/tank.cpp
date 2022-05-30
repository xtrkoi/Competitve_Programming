#include <bits/stdc++.h>
using namespace std;
double a, b, res;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("tank.inp", "r", stdin);
    freopen("tank.out", "w", stdout);
#endif // !ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%lf %lf", &a, &b);
    res = 1 / (1 / a + 1 / b);
    printf("%0.5lf", res);
    return 0;
}
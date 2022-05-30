#include <bits/stdc++.h>
using namespace std;

double a, b, c;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("heron.inp", "r", stdin);
    freopen("heron.out", "w", stdout);
#endif
    scanf("%lf %lf %lf", &a, &b, &c);
    double p = (a + b + c) / 2;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.2lf", S);
    return 0;
}
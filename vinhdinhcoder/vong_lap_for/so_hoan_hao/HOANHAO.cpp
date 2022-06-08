#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("hoanhao.inp", "r", stdin);
    freopen("hoanhao.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int sum = 0;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    cout << (sum == n * 2 ? "YES" : "NO");
    return 0;
}
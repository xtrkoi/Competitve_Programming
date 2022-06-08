#include <bits/stdc++.h>
using namespace std;

int t, x, res;

void run()
{
    cin >> x;
    res = 0;
    for (int i = 0; i < 32; i++)
        if (x & (1 << i))
        {
            res = res | (1 << i);
            break;
        }
    int cnt = 0;
    for (int i = 0; i < 32; i++)
        if (x & 1 << i)
            cnt++;
    if (x == 1 || cnt == 1)
        for (int i = 0; i < 32; i++)
            if (((res & (1 << i)) == 0) && ((x & (1 << i)) == 0))
            {
                res = res | (1 << i);
                break;
            }
    cout << res << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cirno.inp", "r", stdin);
    freopen("cirno.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
        run();
    return 0;
}
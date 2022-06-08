#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int t, n;

void run()
{
    cin >> n;
    int tmp, tmp2, cnt = 0, mn = INF;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp % 2 == 0)
        {
            tmp2 = 0;
            while (tmp % 2 == 0)
            {
                tmp2++;
                tmp /= 2;
            }
            mn = min(mn, tmp2);
        }
        else
            cnt++;
    }
    if (cnt == n)
        cout << "0\n";
    else if (cnt == 0)
        cout << mn + n - 1 << "\n";
    else
        cout << n - cnt << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("patchouli.inp", "r", stdin);
    freopen("patchouli.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
        run();
    return 0;
}
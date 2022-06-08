#include <bits/stdc++.h>
using namespace std;

int s[3], cnt[20 + 20 + 40 + 2];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("bones.inp", "r", stdin);
    freopen("bones.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 3; i++)
        cin >> s[i];
    for (int i = 1; i <= s[0]; i++)
        for (int j = 1; j <= s[1]; j++)
            for (int k = 1; k <= s[2]; k++)
                cnt[i + j + k]++;

    int mx = -1, d = 0;
    for (int i = 1; i <= s[0] + s[1] + s[2]; i++)
        if (cnt[i] > mx)
        {
            mx = cnt[i];
            d = i;
        }
    cout << d;
    return 0;
}
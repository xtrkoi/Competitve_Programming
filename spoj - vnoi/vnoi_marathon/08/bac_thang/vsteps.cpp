#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 2, mod = 14062008;
vector<int> stairs(maxn, 0);
int n, k;

void input()
{
    cin >> n >> k;
    int tmp;
    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        stairs[tmp] = -1;
    }
}

void run()
{
    stairs[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (stairs[i] < 0)
            continue;
        if (stairs[i - 1] >= 0)
            stairs[i] += stairs[i - 1];
        if (stairs[i - 2] >= 0)
            stairs[i] = (stairs[i] + stairs[i - 2]) % 14062008;
    }
    cout << (stairs[n] >= 0 ? stairs[n] : 0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("vsteps.inp", "r", stdin);
    freopen("vsteps.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run();
    return 0;
}
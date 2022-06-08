#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
int n, mn = INF, mx = -INF;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int tmp;
    while (n--)
    {
        cin >> tmp;
        mn = min(mn, tmp);
        mx = max(mx, tmp);
    }
    cout << "SO LON NHAT: " << mx << "\nSO BE NHAT: " << mn;
    return 0;
}
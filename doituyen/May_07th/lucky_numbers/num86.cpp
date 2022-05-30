#include <bits/stdc++.h>
using namespace std;

int res[201];
int t, n;

void find_lucky_number(int x)
{
    x *= 9;
    res[0] = 1;
    for (int i = 1; i <= 200; i++)
        res[i] = res[i - 1] * 10 % x;
    for (int digits = 1; digits <= 200; digits++)
        for (int cnt8 = 0; cnt8 <= digits; cnt8++)
            if ((8 * res[digits] - 2 * res[digits - cnt8] - 6) % x == 0)
            {
                for (int h = 1; h <= cnt8; h++)
                    cout << "8";
                for (int h = 1; h <= digits - cnt8; h++)
                    cout << "6";
                cout << "\n";
                return;
            }
    cout << "-1\n";
}

int main()
{
    freopen("num86.inp", "r", stdin);
    freopen("num86.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        find_lucky_number(n);
    }
    return 0;
}
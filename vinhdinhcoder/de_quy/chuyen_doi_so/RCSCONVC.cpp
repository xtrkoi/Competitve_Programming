#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int a, b;
vector<int> dig_a, dig_b, res;

void input()
{
    cin >> a >> b;
    if (a == 0)
        dig_a.pb(0);
    else
        while (a > 0)
        {
            dig_a.pb(a % 10);
            a /= 10;
        }

    if (b == 0)
        dig_b.pb(0);
    else
        while (b > 0)
        {
            dig_b.pb(b % 10);
            b /= 10;
        }
}

void run(vector<int> x, vector<int> y, bool fmax)
{
    if (x.empty() || y.empty())
    {
        if (x.empty() && y.empty())
            return;
        else if (x.empty())
        {
            res.pb(y.back());
            y.pop_back();
        }
        else
        {
            res.pb(x.back());
            x.pop_back();
        }
    }
    else if ((x.back() > y.back() && fmax) || (x.back() < y.back() && !fmax))
    {
        res.pb(x.back());
        x.pop_back();
    }
    else
    {
        res.pb(y.back());
        y.pop_back();
    }
    run(x, y, fmax);
}

void print()
{
    if (res.empty())
    {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
    cout << "\n";
    res.clear();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("rcsconvc.inp", "r", stdin);
    freopen("rcsconvc.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    run(dig_a, dig_b, 0);
    print();
    run(dig_a, dig_b, 1);
    print();
    return 0;
}

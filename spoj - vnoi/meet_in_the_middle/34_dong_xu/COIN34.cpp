#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
typedef pair<ll, int> plli;

vector<ll> coin;
vector<plli> set1, set2;
int t, res, cnt_coin, test_cnt = 1;
ll x, sum, bound = 0;

void prepare_coins()
{
    coin.pb(0);
    coin.pb(2);
    coin.pb(3);
    coin.pb(5);
    bound = coin[1] + coin[2] + coin[3];
    for (int i = 4; i <= 34; i++)
    {
        coin.pb(coin[i - 1] + coin[i - 2] + coin[i - 3]);
        if (i <= 20)
            bound += coin[i];
    }
}

void output()
{
    cout << "Case #" << test_cnt << ": " << res << "\n";
}

// recursive function for res <= 20
void dfs_1(int i) // i: coin index (start at 1)
{
    for (int c = 0; c <= 1; c++)
    {
        sum += coin[i] * c;
        cnt_coin += c;

        if (i == 20)
            set1.pb(mp(sum, cnt_coin));
        else
            dfs_1(i + 1);

        sum -= coin[i] * c;
        cnt_coin -= c;
    }
}

void dfs_2(int i) // i: coin index (start at 21)
{
    for (int c = 0; c <= 1; c++)
    {
        sum += coin[i] * c;
        cnt_coin += c;

        if (i == 34)
            set2.pb(mp(sum, cnt_coin));
        else
            dfs_2(i + 1);

        sum -= coin[i] * c;
        cnt_coin -= c;
    }
}

bool comp(const plli &a, const plli &b)
{
    return a.X < b.X || (a.X == b.X && a.Y > b.Y);
}

void run()
{
    cin >> x;
    if (x <= bound)
    {
        vector<plli>::iterator j = lower_bound(set1.begin(), set1.end(), mp(x, -1));
        int k = j - set1.begin();
        if (j != set1.end() && set1[k].X == x)
            res = set1[k].Y;
        else
            res = -1;
    }
    else
    {
        res = 0;
        for (int i = 0; i < set2.size() && set2[i].X <= x; i++)
        {
            if (i < 34)
                if (set2[i].X == set2[i + 1].X)
                    continue;
            vector<plli>::iterator j = lower_bound(set1.begin(), set1.end(), mp(x - set2[i].X, -1));
            int k = j - set1.begin();
            if (j != set1.end() && set1[k].X + set2[i].X == x)
                res = max(res, set1[k].Y + set2[i].Y);
        }
        if (res == 0)
            res = -1;
    }
    output();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("coin34.inp", "r", stdin);
    freopen("coin34.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prepare_coins();
    sum = 0;
    cnt_coin = 0;
    dfs_1(1);
    sort(set1.begin(), set1.end(), comp);

    sum = 0;
    cnt_coin = 0;
    dfs_2(21);
    sort(set2.begin(), set2.end());

    cin >> t;
    while (test_cnt <= t)
    {
        run();
        test_cnt++;
    }
    return 0;
}
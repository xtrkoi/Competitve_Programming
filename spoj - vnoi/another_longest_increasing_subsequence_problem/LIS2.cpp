#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e9;
int n;
vector<ii> arr;

void input()
{
    cin >> n;
    int tmp1, tmp2;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp1 >> tmp2;
        arr.pb(mp(tmp1, tmp2));
    }
}

void lis()
{
    vector<int> d(n + 2, INF);
    vector<int> f(n + 2);
    d[0] = -INF;
    stack<ii> processed;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(d.begin(), d.end(), arr[i].X) - d.begin();
        f[i] = j;
        if (d[j - 1] <= arr[i].X && arr[i].X <= d[j])
        {
            d[j] = arr[i].X;
            tmp = max(tmp, j);
        }
    }
    cout << tmp << "\n";

    int tmp2 = tmp;
    int k = n;
    while (tmp2 > 0)
    {
        if (f[--k] == tmp2)
        {
            processed.push(arr[k]);
            tmp2--;
        }
    }

    int res = 0;
    vector<int> d2(n + 2, INF);
    d2[0] = -INF;
    for (int i = 1; i <= tmp; i++)
    {
        ii u = processed.top();
        processed.pop();
        int j = lower_bound(d2.begin(), d2.end(), u.Y) - d2.begin();
        if (d2[j - 1] < u.Y && u.Y < d2[j])
        {
            d2[j] = d[i];
            res = max(res, j);
        }
    }

    cout << res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("lis2.inp", "r", stdin);
    freopen("lis2.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    lis();
    return 0;
}

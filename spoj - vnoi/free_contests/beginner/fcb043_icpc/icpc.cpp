#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

int n, l;
vi arr;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("icpc.inp", "r", stdin);
    freopen("icpc.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.pb(tmp);
    }
    int time = 0, cnt = 0;
    ll penalty = 0;
    sort(arr.begin(), arr.end());
    for (int i : arr)
    {
        if (time + i > l)
            break;
        cnt++;
        time += i;
        penalty += time;
    }
    cout << cnt << " " << penalty;
    return 0;
}
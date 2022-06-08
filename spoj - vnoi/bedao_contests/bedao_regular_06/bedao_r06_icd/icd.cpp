#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
vector<ll> arr;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("icd.inp", "r", stdin);
    freopen("icd.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.pb(tmp);
    }
    ll send = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] += send;
        if (i != n - 1)
        {
            send += arr[i] / (n - i - 1);
            arr[i] = arr[i] % (n - i - 1);
        }
    }
    for (ll i : arr)
        cout << i << " ";
    return 0;
}
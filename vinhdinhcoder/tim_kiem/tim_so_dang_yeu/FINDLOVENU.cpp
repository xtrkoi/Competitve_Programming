#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) A.size()

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 5e6 + 2;
ll arr[maxn], r;

bool find(ll x)
{
    int lt = 1, rt = maxn - 1;
    while (lt <= rt)
    {
        int mid = (lt + rt) >> 1;
        if (x == arr[mid])
            return true;
        if (x < arr[mid])
            rt = mid - 1;
        else
            lt = mid + 1;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("findlovenu.inp", "r", stdin);
    freopen("findlovenu.out", "w", stdout);
#endif  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < maxn; i++)
        arr[i] = arr[i - 1] + i;

    cin >> r;
    for (int i = 1; arr[i] <= r / 2; i++)
        if (find(r - arr[i]))
        {
            cout << arr[i] << " " << r - arr[i] << "\n";
            return 0;
        }
    cout << "-1\n";
    return 0;
}
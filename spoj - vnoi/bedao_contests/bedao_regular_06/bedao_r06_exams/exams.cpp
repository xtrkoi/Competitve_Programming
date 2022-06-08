#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(A) (int)A.size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const ll INF = 2e18, mod = 1e9 + 7;
int n;
vector<ll> arr;

void input()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.pb(tmp);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("exams.inp", "r", stdin);
    freopen("exams.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    return 0;
}

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

const int maxn = 3e5 + 2;
const ll INF = (long double)2e18;
int t, cnt_a, cnt_b;
vector<ll> a(maxn), b(maxn);

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void output(ll num, ll dem)
{
    ll div = gcd(num, dem);
    cout << num / div << "/" << dem / div << "\n";
}

void input()
{
    cin >> cnt_a;
    for (int i = 0; i < cnt_a; i++)
        cin >> a[i];

    cin >> cnt_b;
    for (int i = 0; i < cnt_b; i++)
        cin >> b[i];
    sort(a.begin(), a.begin() + cnt_a);
    sort(b.begin(), b.begin() + cnt_b);
    b[cnt_b] = INF;
}

void run()
{
    ll win = 0, tie = 0, total = (ll)cnt_a * cnt_b;
    for (int i = 0; i < cnt_a; i++)
    {
        int j = lower_bound(b.begin(), b.begin() + cnt_b, a[i]) - b.begin();
        int k = upper_bound(b.begin(), b.begin() + cnt_b, a[i]) - b.begin();
        win += j;
        tie += k - j;
    }
    output(win, total);
    output(tie, total);
}

int main()
{
    // freopen("duels.inp", "r", stdin);
    // freopen("duels.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        input();
        run();
    }
    return 0;
}
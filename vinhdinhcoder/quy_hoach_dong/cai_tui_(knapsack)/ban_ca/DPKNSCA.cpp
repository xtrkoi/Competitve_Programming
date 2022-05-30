#include <bits/stdc++.h>
using namespace std;

const int mx = 20000;
int t, n, a[103];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void run()
{
    bitset<mx> b;
    b[0] = 1;
    for (int i = 0; i < n; i++)
        b |= b << a[i];
    for (int i = 0; i <= mx; i++)
        if (b[i])
            cout << i << " ";
    cout << "\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("dpknsca.inp", "r", stdin);
    freopen("dpknsca.out", "w", stdout);
#endif // !ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        input();
        run();
    }
    return 0;
}

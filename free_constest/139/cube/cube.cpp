#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;

int n;
vi level(200), s(200);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i < 200; i++)
    {
        level[i] = level[i - 1] + i;
        s[i] = s[i - 1] + level[i];
    }
    cin >> n;
    cout << (int)(upper_bound(s.begin(), s.end(), n) - s.begin() - 1);
    return 0;
}
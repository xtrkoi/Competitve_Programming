#include <bits/stdc++.h>
using namespace std;

bool comp(const int &a, const int &b)
{
    if (a > b)
        return a == b * 2 || (a / 3 == b && a % 3 == 0);
    else
        return b == a * 2 || (b / 3 == a && b % 3 == 0);
}

int n;
vector<int> arr;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("rcslist.inp", "r", stdin);
    freopen("rcslist.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), comp);
    for (int i : arr)
        cout << i << " ";
    return 0;
}
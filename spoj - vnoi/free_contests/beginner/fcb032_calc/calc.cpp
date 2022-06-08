#include <bits/stdc++.h>
using namespace std;

void run()
{
    vector<int> arr(3, -1);
    int tmp;
    for (int i = 0; i < 3; i++)
    {
        cin >> tmp;
        if (tmp >= arr[0])
        {
            arr[2] = arr[1];
            arr[1] = arr[0];
            arr[0] = tmp;
        }
        else if (tmp >= arr[1])
        {
            arr[2] = arr[1];
            arr[1] = tmp;
        }
        else if (tmp >= arr[2])
            arr[2] = tmp;
    }
    cout << (arr[0] == arr[1] + arr[2] ? "yes\n" : "no\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("calc.inp", "r", stdin);
    freopen("calc.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 2; i++)
        run();
    return 0;
}
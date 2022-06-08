#include <bits/stdc++.h>
using namespace std;

int n, res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int tmp;
    while (n--)
    {
        cin >> tmp;
        if (tmp == 1)
            res++;
        else
            res--;
    }
    cout << abs(res);
    return 0;
}
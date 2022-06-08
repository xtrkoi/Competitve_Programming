#include <bits/stdc++.h>
using namespace std;

long long a, b, res = 0;

int main()
{
    cin >> a >> b;
    while (a != b * 2)
    {
        res++;
        a++;
        b++;
    }
    cout << res;
    return 0;
}
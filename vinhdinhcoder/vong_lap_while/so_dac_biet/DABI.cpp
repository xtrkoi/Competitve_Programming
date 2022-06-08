#include <bits/stdc++.h>
using namespace std;

long long n;

bool run(long long x)
{
    long long sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return n % sum == 0;
}

int main()
{
    cin >> n;
    cout << run(n);
    return 0;
}
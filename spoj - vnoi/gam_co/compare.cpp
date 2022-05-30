#include <bits/stdc++.h>
using namespace std;

const string NAME = "vbgrass";
const int NTEST = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rd rand

typedef long long ll;

ll Rand(ll l, ll h)
{
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest = NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        int n = Rand(1, 100);
        int m = Rand(1, 100);
        cout << n << " " << m;
    }
}

#include <bits/stdc++.h>
using namespace std;

#define sz(A) (int)A.size()

string a, b, res;
int f[3003][3003];

void trace(int i, int j)
{
}

int main()
{
    // cin >> a >> b;
    a = "abracadabra";
    b = "avadakedavra";
    for (int i = 1; i <= sz(a); i++)
        for (int j = 1; j <= sz(b); j++)
        {
            if (a[i - 1] == b[j - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    return 0;
}
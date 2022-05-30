#include <bits/stdc++.h>
using namespace std;

#define pb push_back

struct mang
{
    long int a, b, du;
} dd[400000];

long int n, x, d, c;
long int q[400000];
int s[9][4];

void run()
{
    long int i, j, l, u, v;

    d = 0;
    c = 2;
    q[1] = 6;
    q[2] = 8;

    dd[1].a = 0;
    dd[1].b = 1;
    dd[1].du = 6 % x;

    dd[2].a = 1;
    dd[2].b = 0;
    dd[2].du = 8 % x;
    do
    {
        d++;

        u = q[d];
        j = 1;
        v = s[q[d]][j];

        while (v != 0)
        {
            c++;
            q[c] = v;
            if (v == 6)
            {
                dd[c].b = dd[d].b + 1;
                dd[c].a = dd[d].a;
                dd[c].du = (dd[d].du * 10 + 6) % x;
            }
            else
            {
                dd[c].a = dd[d].a + 1;
                dd[c].b = dd[d].b;
                dd[c].du = (dd[d].du * 10 + 8) % x;
            }
            j++;
            v = s[q[d]][j];
        }
    } while (dd[d].a + dd[d].b <= 200 && dd[d].du != 0);

    if (dd[d].a + dd[d].b > 200)
        cout << "-1\n";
    else
    {
        for (int i = 1; i <= dd[d].a; i++)
            cout << "8";
        for (int i = 1; i <= dd[d].b; i++)
            cout << "6";
        cout << "\n";
    }
}

int main()
{
    freopen("num86.inp", "r", stdin);
    freopen("num86.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    s[6][1] = 6;
    s[6][2] = 0;
    s[8][1] = 6;
    s[8][2] = 8;
    s[8][3] = 0;
    while (n--)
    {
        cin >> x;
        if (x % 10 == 5)
            cout << "-1\n";
        else
            run();
    }
}
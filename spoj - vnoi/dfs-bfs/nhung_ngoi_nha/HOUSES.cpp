#include <bits/stdc++.h>
using namespace std;

#define pb push_back

// maximum number of houses
const int max_vertices = 1005;

// n: number of people
// l: number of houses
// cnt: count variable
int n, l, cnt = 0;

// check if a person has rented houses
vector<bool> seen(max_vertices, false);

// store how many houses each person wants to rent
vector<int> arr;

// save renting choices
vector<int> res(max_vertices);

// save leftover, unrented houses
int extra_houses = 0;

// function for taking inputs
void input()
{
    // input n and l
    cin >> l >> n;

    // creating temp variable
    int tmp;

    // create starting index
    arr.pb(0);

    // taking inputs
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.pb(tmp);
        extra_houses += tmp;
    }

    extra_houses = l - extra_houses;
}

// print the options
void output()
{
    for (int i = 1; i <= l; i++)
        cout << res[i] << " ";
    cout << "\n";
}

// recursive function
void dfs(int i) // i: person's id
{
    if (i == l + 1)
    // If iterated through all houses
    {
        output();
        cnt++;

        // meeting output threshold
        if (cnt == 1000)
            exit(0);

        return;
    }

    // first house rule (must be filled)
    if (i == 1)
    {
        for (int j = 1; j <= n; j++)
            // Find next person avaiable
            if (!seen[j])
            {
                // Pre-backtracking
                seen[j] = true;

                // Fill house[i -> k] with person j
                for (int k = 1; k <= arr[j]; k++)
                    res[i + k - 1] = j;

                // Backtracking - move to next available house
                dfs(i + arr[j]);

                // Post-backtracking
                seen[j] = false;
            }
    }

    else
    {
        for (int j = 0; j <= n; j++)
            // If the person is avaiable
            if (!seen[j])
                // General case
                if (j > 0)
                {
                    // Pre-backtracking
                    seen[j] = true;

                    // Fill house[i -> i + k - 1] with person j
                    for (int k = 1; k <= arr[j]; k++)
                        res[i + k - 1] = j;

                    // Backtracking - move to next available house
                    dfs(i + arr[j]);

                    // Post-backtracking
                    seen[j] = false;
                }

                // select empty houses
                else if (res[i - 1] > 0) // previous house has a person
                {
                    for (int k = extra_houses; k > 0; k--)
                    {
                        // Fill house[i -> i + k - 1] with 0
                        for (int h = 1; h <= k; h++)
                            res[i + h - 1] = 0;

                        // Pre-backtracking
                        extra_houses -= k;
                        if (extra_houses == 0)
                            seen[0] = true;

                        // Backtracking
                        dfs(i + k);

                        // Post-backtracking
                        seen[0] = false;
                        extra_houses += k;
                    }
                }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("houses.inp", "r", stdin);
    freopen("houses.out", "w", stdout);
#endif // !ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    dfs(1);
    return 0;
}
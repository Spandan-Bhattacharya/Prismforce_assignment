#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[12][103][2][10][10];
    bool canWin(int ind, int currhp, bool skip_prev, int n, vector<int> &powers, vector<bool> &special, int p, int a, int b)
    {
        if (ind == n)
            return 1;
        // fight
        if (dp[ind][currhp][skip_prev][a][b] != -1)
            return dp[ind][currhp][skip_prev][a][b];
        int enemyhp = powers[ind];
        bool ans = 0;
        if (ind > 0 && special[ind - 1])
        {
            if (skip_prev)
                enemyhp += powers[ind - 1];
            else
                enemyhp += powers[ind - 1] / 2;
        }
        if (currhp >= enemyhp)
        {

            ans |= canWin(ind + 1, currhp - enemyhp, 0, n, powers, special, p, a, b);
        }
        else
        {
            // regen
            if (b > 0)
            {

                if (p >= enemyhp)
                {
                    ans |= canWin(ind + 1, p - enemyhp, 0, n, powers, special, p, a, b - 1);
                }
            }
        }
        // skip
        if (a > 0)
        {
            ans |= canWin(ind + 1, currhp, 1, n, powers, special, p, a - 1, b);
        }
        return dp[ind][currhp][skip_prev][a][b] = ans;
    }
    bool fightAbhimanyu(int n, vector<int> &powers, vector<bool> &special, int p, int a, int b)
    {
        memset(dp, -1, sizeof(dp));
        return canWin(0, p, 0, n, powers, special, p, a, b);
    }
};

int main()
{
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> powers(n);
        vector<bool> special(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            powers[i] = x;
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            special[i] = x;
        }
        int p, a, b;
        cin >> p >> a >> b;
        Solution s;
        cout << s.fightAbhimanyu(n, powers, special, p, a, b) << '\n';
    }
    return 0;
}
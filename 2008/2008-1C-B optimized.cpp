#include <bits/stdc++.h>

using namespace std;
void solve(string s)
{
    unsigned long long ans = 0ll;
    int MOD = 210;
    int n = s.size();
    unsigned long long dp[n + 1][MOD];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < MOD; j++)
        {
            dp[i][j] = 0ll;
        }
    }
    dp[0][0] = 1;
    int nextJ, nextK, nextC;
    for (int i = 1; i <= n; i++)
    {
        long val = 0;
        long xValP = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            val = (val + (s[j] - '0') * xValP) % MOD;
            // cout << i << " " << j << " " << val << " " << xValP << endl;

            xValP = (xValP * 10) % MOD;
            for (int x = 0; x < MOD; x++)
            {

                dp[i][(x + val) % MOD] += dp[j][x];
                if (j > 0)
                {
                    dp[i][(x - val + MOD) % MOD] += dp[j][x];
                }
            }
        }
    }
    for (int i = 0; i < MOD; i++)
    {
        if (i % 2 == 0 || i % 3 == 0||i % 5 == 0 || i % 7 == 0)
        {
            if (dp[n][i] > 0)
            {
                //cout << i << " " << dp[n][i] << endl;
            }

            ans += dp[n][i];
        }
    }

    cout << "Case right #" << 1 << ": "
         << ans << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        string s;
        cin >> s;
        //solve(s);
        unsigned long long ans = 0ll;
        int MOD = 210;
        int n = s.size();
        unsigned long long dp[n][MOD][MOD][2];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < MOD; j++)
            {
                for (int k = 0; k < MOD; k++)
                {
                    dp[i][j][k][0] = 0ll;
                    dp[i][j][k][1] = 0ll;
             }
            }
        }
        dp[0][0][(s[0] - '0') % MOD][1] = 1ll;
        int nextJ, nextK, nextC;
        for (int i = 0; i < n - 1; i++)
        {
            nextC = (s[i + 1] - '0');
            for (int j = 0; j < MOD; j++)
            {
                for (int k = 0; k < MOD; k++)
                {
                    for (int l = 0; l < 2; l++)
                    {

                        if (dp[i][j][k][l] == 0)
                            continue;
                        nextJ = j;
                        nextK = (((10 * k) + (l == 1 ? 1 : -1) * nextC+MOD) % MOD);
                        dp[i + 1][nextJ][nextK][l] += dp[i][j][k][l];

                        nextJ = (j + k) % MOD;
                        nextK = nextC % MOD;
                        dp[i + 1][nextJ][nextK][1] += dp[i][j][k][l];

                        nextJ = (j + k) % MOD;
                        nextK = (MOD - nextC) % MOD;
                        dp[i + 1][nextJ][nextK][0] += dp[i][j][k][l];
                    }
                }
            }
        }
        for (int i = 0; i < MOD; i++)
        {
            for (int j = 0; j < MOD; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if ((i + j) % 2 == 0 || (i + j) % 3 == 0||(i + j) % 5 == 0 || (i + j) % 7 == 0)
                    {
                        // if (dp[n - 1][i][j][k])
                        // {
                        //     cout << (i + j) << " " << dp[n - 1][i][j][k] << endl;
                        // }
                        // if (dp[n - 1][i][j][k] < 0)
                        // {
                        //     cout << "aewrewr" << endl;
                        // }
                        ans += dp[n - 1][i][j][k];
                    }
                }
            }
        }

        cout << "Case #" << caseNum << ": "
             << ans << endl;
    }

    return 0;
}

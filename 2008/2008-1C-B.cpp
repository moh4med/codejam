#include <bits/stdc++.h>

using namespace std;

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
        long long ans = 0ll;
        int MOD = 210;
        int n = s.size();
        long long dp[n + 1][MOD];
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
            if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
            {
                // if (dp[n][i] > 0)
                // {
                //     cout << i << endl;
                // }

                ans += dp[n][i];
            }
        }

        cout << "Case #" << caseNum << ": "
             << ans << endl;
    }

    return 0;
}

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
        int n;
        cin >> n;
        vector<string> x(n);
        int cnt = 0;
        bool ok = true;
        string ans[2] = {"", ""};
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            int occ = 0;
            string s[2] = {"", ""};
            for (int j = 0; j < x[i].size(); j++)
            {
                if (x[i][j] == '*')
                {
                    occ++;
                }
                else
                {
                    s[occ] += x[i][j];
                }
            }

            if (occ == 1)
            {
                if (s[0].size() > ans[0].size())
                {
                    ans[0] = s[0];
                }

                if (s[1].size() > ans[1].size())
                {
                    ans[1] = s[1];
                }
            }
            else
            {
                ok = false;
            }
        }
        if (ok)
        {
            bool ok2 = true;

            for (int i = 0; i < n && ok2; i++)
            {

                for (int j = 0, k = 0; j < x[i].size(); j++, k++)
                {
                    if (x[i][j] == '*')
                    {
                        break;
                    }
                    if (x[i][j] != ans[0][k])
                    {
                        ok2 = false;
                        break;
                    }
                }
            }

            for (int i = 0; i < n && ok2; i++)
            {

                for (int j = x[i].size() - 1, k = ans[1].size() - 1; j >= 0; j--, k--)
                {
                    if (x[i][j] == '*')
                    {
                        break;
                    }
                    if (x[i][j] != ans[1][k])
                    {
                        ok2 = false;
                        break;
                    }
                }
            }

            if (ok2)
            {
                cout << "Case #" << caseNum << ": " << ans[0] + ans[1] << endl;
            }
            else
            {
                cout << "Case #" << caseNum << ": "
                     << "*" << endl;
            }
        }
        else
        {
            cout << "Case #" << caseNum << ": "
                 << "**********" << endl;
        }
    }

    return 0;
}

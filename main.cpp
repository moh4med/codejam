#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {

        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            string x = a[i];
            string y = a[i + 1];
            int k = y.size();
            while (y.size() < x.size())
            {
                y.push_back('0');
                ans++;
            }
            bool xBig = true;
            for (int j = 0; j < x.size(); j++)
            {
                if (x[j] > y[j])
                {
                    xBig = true;
                    break;
                }
                else if (x[j] < y[j])
                {
                    xBig = false;
                    break;
                }
            }
            if (y.size() > x.size())
            {
                xBig = false;
            }
            if (xBig)
            {

                bool samePrefix = true;
                for (int j = 0; j < k; j++)
                {
                    if (x[j] > y[j])
                    {
                        samePrefix = false;
                        break;
                    }
                }
                if (samePrefix)
                {
                    bool allNine = true;
                    if (x[k] == '9')
                    {
                        y.push_back('0');
                        ans++;
                    }
                    else
                    {
                        if (k >= y.size())
                        {
                            y.push_back('0');
                            ans++;
                        }
                        else
                        {
                            y[k] = x[k] + 1;
                            allNine = false;
                        }
                    }
                }
                else
                {
                    y.push_back('0');
                    ans++;
                }
            }
            a[i + 1] = y;
        }
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

        cout << "Case #" << caseNum << ": "
             << ans << endl;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

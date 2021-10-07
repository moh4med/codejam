#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        string s;
        cin >> s;
        s = "0" + s;
        int x = s.length() - 1;
        while (s[x] <= s[x - 1])
        {
            x--;
        }
        string ans = "";
        ans = s.substr(0, x - 1);
        char l;
        char k = s[x - 1];
        for (int i = s.length() - 1; i > x - 1; i--)
        {
            if (s[i] > k)
            {
                l = i;
                break;
            }
        }

        ans.push_back(s[l]);
        bool found = false;
        for (int i = s.length() - 1; i > x - 1;)
        {
            if (i == l)
            {
                i--;
                continue;
            }
            if ((s[i] < k) || found)
            {
                ans.push_back(s[i]);
                i--;
            }
            else
            {
                ans.push_back(k);
                found = true;
            }
        }
        if (!found)
        {
            ans.push_back(k);
        }
        if(ans[0]=='0'){
            ans=ans.erase(0,1);
        }
        cout << "Case #" << caseNum << ": "
             << ans << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

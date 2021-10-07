#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        int x, y;
        string s;
        cin >> x >> y >> s;
        x += 1000;
        y += 1000;
        int minTime = INT_MAX, dif;
        for (int i = 0; i < s.size() + 1; i++)
        {
            dif = abs(x - 1000) + abs(y - 1000);
            if (dif <= i)
            {
                minTime = i;
                break;
            }
            if (s[i] == 'S')
            {
                y--;
            }
            else if (s[i] == 'N')
            {
                y++;
            }
            else if (s[i] == 'E')
            {
                x++;
            }
            else if (s[i] == 'W')
            {
                x--;
            }
        }
        if (minTime == INT_MAX)
        {
            cout << "Case #" << caseNum << ": "
                 << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "Case #" << caseNum << ": "
                 << minTime << endl;
        }
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

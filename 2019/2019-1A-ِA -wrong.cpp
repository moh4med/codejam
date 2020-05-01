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
        int r, c;
        cin >> r >> c;
        if (max(r, c) <= 3)
        {
            cout << "Case #" << caseNum << ": "
                 << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "Case #" << caseNum << ": "
                 << "POSSIBLE" << endl;
            bool invert = false;
            vector<pair<int, int>> ans;
            if (c <= 3)
            {
                swap(r, c);
                invert = true;
            }
            if (r == 2 && c == 4)
            {
                if (invert)
                {
                    ans.push_back({3, 1});
                    ans.push_back({1, 1});
                    ans.push_back({3, 2});
                    ans.push_back({1, 2});
                    ans.push_back({4, 1});
                    ans.push_back({2, 1});
                    ans.push_back({4, 2});
                    ans.push_back({2, 2});
                }
                else
                {
                    ans.push_back({2, 3});
                    ans.push_back({2, 1});
                    ans.push_back({1, 3});
                    ans.push_back({1, 1});
                    ans.push_back({2, 4});
                    ans.push_back({2, 2});
                    ans.push_back({1, 4});
                    ans.push_back({1, 2});
                }
            }
            else
            {
                for (int k = 1; k <= 2; k++)
                {

                    for (int i = 1; i <= r; i++)
                    {
                        for (int j = k; j <= c; j += 2)
                        {
                            if (invert)
                            {
                                ans.push_back({c - j + 1, i});
                            }
                            else
                            {
                                ans.push_back({i, j});
                            }
                        }
                    }
                }
            }
            vector< vector<bool> > check(r+1, vector<bool>(c+1, false));
            if (ans.size() != r * c)
            {
                cout << "ERROR not same size\n";
            }

            check[ans[0].first][ans[0].second] = true;

            for (int i = 1; i < ans.size(); i++)
            {

                int r1 = ans[i].first;
                int c1 = ans[i].second;
                // cout << r1 << " " << c1 << endl;

                if (!check[r1][c1])
                {
                    check[r1][c1] = true;
                    int r2 = ans[i - 1].first;
                    int c2 = ans[i - 1].second;
                    if (r1 == r2)
                    {
                        cout << "ERROR  same row\n";
                        break;
                    }
                    if (c1 == c2)
                    {
                        cout << "ERROR  same column\n";
                        break;
                    }
                    if (r1 - c1 == r2 - c2)
                    {
                        cout << "ERROR  same diagonal\n";
                        break;
                    }
                    if (r1 + c1 == r2 + c2)
                    {
                        cout << "ERROR  same diagonal verse\n";
                        break;
                    }
                }
                else
                {
                    cout << "ERROR  same position\n";
                    break;
                }
            }
        }
    }

    return 0;
}

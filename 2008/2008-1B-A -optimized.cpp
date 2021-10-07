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
        long long n, a, b, c, d, x, y, m;
        cin >> n >> a >> b >> c >> d >> x >> y >> m;
        vector<pair<int, int>> p;
        map<pair<int, int>, int> mp;
        map<pair<int, int>, long long> mp2;
        long long mp3[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i < n; i++)
        {
            /* code */
            p.push_back({x, y});
            //    cout << x << " " << y << endl;
            mp[{x, y}] = (i + 1);
            mp2[{x % 3, y % 3}]++;
            mp3[((x % 3)) * 3 + (y % 3)]++;
            // if (x % 3 == 0 && y % 3 == 1)
            // {
            //     cout << 1 << " " << (i + 1) << endl;
            // }
            // if (x % 3 == 1 && y % 3 == 2)
            // {
            //     cout << 2 << " " << (i + 1) << endl;
            // }
            // if (x % 3 == 2 && y % 3 == 0)
            // {
            //     cout << 3 << " " << (i + 1) << endl;
            // }
            x = (a * x + b) % m;
            y = (c * y + d) % m;
        }
        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //           cout << i << "," << j << " : " << (mp2[{i, j}]) << endl;
        //     }
        // }
        long long ans3 = 0ll;
        for (int i = 0; i < 9; i++)
        {
           // cout << i / 3 << " " << i % 3 << "  - " << mp3[i] << endl;
            ans3 += (mp3[i] * (mp3[i] - 1) * (mp3[i] - 2)) / 6;
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = i + 1; j < 9; j++)
            {
                for (int k = j + 1; k < 9; k++)
                {
                    if ((((i / 3) + (j / 3) + (k / 3)) % 3 == 0) && ((((i % 3) + (j % 3) + (k % 3)) % 3) == 0))
                    {
                        ans3 += (1ll * mp3[i] * mp3[j] * mp3[k]);
                    }
                }
            }
        }

        long long xc, yc;
        long long ans = 0ll;
        long long ans2 = 0;
        ans += (1ll * mp2[{0, 0}] * mp2[{0, 1}] * mp2[{0, 2}]);
        ans += (1ll * mp2[{0, 0}] * mp2[{1, 0}] * mp2[{2, 0}]);
        ans += (1ll * mp2[{0, 0}] * mp2[{1, 1}] * mp2[{2, 2}]);
        ans += (1ll * mp2[{0, 0}] * mp2[{1, 2}] * mp2[{2, 1}]);
        ans += (1ll * mp2[{0, 1}] * mp2[{1, 0}] * mp2[{2, 2}]);
        ans += (1ll * mp2[{0, 1}] * mp2[{1, 1}] * mp2[{2, 1}]);
        ans += (1ll * mp2[{0, 1}] * mp2[{1, 2}] * mp2[{2, 0}]);
        ans += (1ll * mp2[{0, 2}] * mp2[{1, 0}] * mp2[{2, 1}]);
        ans += (1ll * mp2[{0, 2}] * mp2[{1, 1}] * mp2[{2, 0}]);
        ans += (1ll * mp2[{0, 2}] * mp2[{1, 2}] * mp2[{2, 2}]);
        ans += (1ll * 1ll * mp2[{1, 0}] * mp2[{1, 1}] * mp2[{1, 2}]);

        ans += (1ll * mp2[{2, 0}] * mp2[{2, 1}] * mp2[{2, 2}]);
        //cout<<ans<<endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                long long d = mp2[{i, j}];
                d = (d * (d - 1) * (d - 2)) / 6;
                ans += d;
            }
        }
        // vector<vector<int>> dummy;
        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         for (int k = 0; k < 3; k++)
        //         {
        //             if ((i + j + k) % 3 == 0)
        //             {
        //                 // cout << i << " " << j << " " << k << endl;
        //                 dummy.push_back(vector<int>({i, j, k}));
        //             }
        //         }
        //     }
        // }

        // for (int i = 0; i < dummy.size(); i++)
        // {
        //     for (int j = 0; j < dummy.size(); j++)
        //     {
        //         // cout << dummy[i][0] << " " << dummy[i][1] << " " << dummy[i][2] << " ";
        //         // cout << dummy[j][0] << " " << dummy[j][1] << " " << dummy[j][2] << endl
        //         //      << endl;

        //         cout << dummy[i][0] << "" << dummy[j][0] << "";
        //         cout << dummy[i][1] << "" << dummy[j][1] << "";
        //         cout << dummy[i][2] << "" << dummy[j][2] << endl
        //              << endl;
        //     }
        // }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         for (int k = j + 1; k < n; k++)
        //         {
        //             //cout<<i+1 <<" "<<j+1<<" "<<k+1<<endl;
        //             xc = p[i].first + p[j].first + p[k].first;
        //             yc = p[i].second + p[j].second + p[k].second;
        //             // cout << xc << " " << yc << endl;
        //             if ((xc % 3 != 0) || (yc % 3 != 0))
        //             {
        //                 continue;
        //             }
        //             //cout << i+1 << " - " << j+1 << " - " << k+1 << endl;
        //             //cout << p[i].first % 3 << "," << p[i].second % 3 << " - " << p[j].first % 3 << "," << p[j].second % 3 << " - " << p[k].first % 3 << "," << p[k].second % 3 << endl;
        //             xc /= 3;
        //             yc /= 3;
        //             ans2++;
        //             //cout << xc << " " << yc << endl;
        //         }
        //     }
        // }
        // if (ans != ans2)
        // {
        //     cout << "Case #" << caseNum << ": "
        //          << "ERROR" << ans << "    " << ans2 << " " << endl;
        // }
        cout << "Case #" << caseNum << ": "
              << ans3 << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        long long n, d, x;
        vector<pair<long long, long long>> a;
        cin >> n >> d;
        map<long long, long long> cnt;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            cnt[x]++;
        }
        if (cnt[1])
        {
            a.push_back({1, 0});
            for (auto f : cnt)
            {
                a.push_back({f.first * d, f.second});
            }
        }
        else
        {
            a.push_back({1, 0});
            for (auto f : cnt)
            {
                a.push_back({f.first, f.second});
            }
        }

        for (auto f : cnt)
        {
            a.push_back({f.first, f.second});
        }
        sort(a.begin(), a.end());
        int k = a.size();
        long long tot = 0;
        long long ans = LONG_LONG_MAX, sum = 0, dummy, time, dummy2;
        for (int i = 0; i < k; i++)
        {
            sum = a[i].second;
            time = 0;
            long long f = cnt[a[i].first * 2];
            if (f != 0)
            {
                if (sum + f > d)
                {
                    sum = d;
                    time += ceil((d - sum) / 2.0);
                }
                else
                {
                    sum += 2 * f;
                    time += f;
                }
            }
            for (int j = i + 1; j < k && sum < d; j++)
            {
                if (a[j].first == a[i].first * 2)
                {
                    continue;
                }
                dummy = (floor(1.0 * (a[j].first - 1) / a[i].first));
                dummy2 = a[j].second * dummy;
                if (sum + dummy2 > d)
                {
                    sum = d;
                    time += (d - sum);
                }
                else
                {
                    sum += (a[j].second * dummy);
                    time += (a[j].second * dummy);
                }
            }

            if (sum >= d)
            {
                ans = min(ans, time);
            }
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

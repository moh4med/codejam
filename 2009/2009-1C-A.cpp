#include <bits/stdc++.h>

using namespace std;
long long solve()
{
    string s;
    cin >> s;
    map<char, int> mp;
    int k = 1;
    long long ans = 0ll;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) == mp.end())
        {
            mp[s[i]] = k;
            if (k == 1)
            {
                k = 0;
            }
            else if (k == 0)
            {
                k = 2;
            }
            else
            {
                k++;
            }
        }
    }
    if (k == 0)
    {
        k = 2;
    }
    long long d = 1ll;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        ans += (1ll * mp[s[i]] * d);
        d *= 1ll * k;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // const clock_t begin_time = clock();
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int ans = solve();
        cout << "Case #" << k << ": "
             << ans << endl;
    }
    // std::cerr << float(clock() - begin_time) / CLOCKS_PER_SEC;
    return 0;
}

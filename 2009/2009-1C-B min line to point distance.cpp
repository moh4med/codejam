#include <bits/stdc++.h>

using namespace std;
void solve(int k)
{
    int n;
    cin >> n;
    int a[n][6];
    vector<int> sum(6, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> a[i][j];
            sum[j] += a[i][j];
        }
    }
    double t = 0;

    if (sum[3] != 0 || sum[4] != 0 || sum[5] != 0)
    {
        t = -1.0 * (sum[0] * sum[3] + sum[1] * sum[4] + sum[2] * sum[5]) / (sum[3] * sum[3] + sum[4] * sum[4] + sum[5] * sum[5]);
        if (t < 0)
        {
            t = 0;
        }
    }
    t = abs(t);
    double ans = sqrt(pow((sum[0] + t * sum[3]), 2) + pow((sum[1] + t * sum[4]), 2) + pow((sum[2] + t * sum[5]), 2));
    ans /= n;
    cout
        << "Case #" << k << ": "
        << fixed << setprecision(10) << ans << " " << t << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // const clock_t begin_time = clock();
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        solve(k);
    }
    // std::cerr << float(clock() - begin_time) / CLOCKS_PER_SEC;
    return 0;
}

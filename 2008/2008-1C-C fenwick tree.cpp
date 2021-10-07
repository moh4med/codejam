#include <bits/stdc++.h>

using namespace std;
long long MOD = 1000000007;

int getBITreeSum(vector<long long> &a, int index)
{
    long long sum = 0;
    while (index > 0)
    {
        sum += a[index];
        sum%=MOD;
        index -= (index & (-index));
    }
    return sum;
}
void updateBITree(vector<long long> &a, int index, long long val)
{
    int n = a.size() - 1;
    while (index <= n)
    {
        a[index] += val;
        a[index]%=MOD;
        index += (index & (-index));
    }
}
void createBITree(vector<long long> &a, vector<long long> b)
{
    int n = b.size();
    a = vector<long long>(n + 1, 0ll);
    for (int i = 0; i < n; i++)
    {
        updateBITree(a, i + 1, b[i]);
    }
}
void bitree()
{
    vector<long long> a = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<long long> BITree;
    createBITree(BITree, a);
    cout << getBITreeSum(BITree, 6) << endl;
    updateBITree(BITree, 3, 6);
    cout << getBITreeSum(BITree, 6) << endl;

    // for (int i = 0; i < BITree.size(); i++)
    // {
    //     cout << BITree[i] << " ";
    // }
    // cout << endl;
}
void solveLarge(int caseNum, vector<int> a)
{
    int n = a.size();
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
    {
        b[i] = {a[i], i + 1};
    }
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++)
    {
        a[b[i].second - 1] = i + 1;
        if (i > 0 && (b[i].first == b[i - 1].first))
        {
            a[b[i].second - 1] = a[b[i - 1].second - 1];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    int maxE = *max_element(a.begin(), a.end());
    //cout << maxE << endl;
    vector<long long> BITree;
    createBITree(BITree, vector<long long>(maxE, 0));
    long long ans = 0ll;
    long long x = 0ll;
    for (int i = 0; i < n; i++)
    {
        x = (getBITreeSum(BITree, a[i] - 1) + 1) % MOD;
        //cout << a[i] << " " << x << endl;
        ans += x;
        ans %= MOD;
        updateBITree(BITree, a[i], x);
    }
    cout << "Case #" << caseNum << ": "
         << ans << endl;
}
void solve(int caseNum, vector<int> a)
{
    int n = a.size();

    vector<long long> cnt(n, 0);
    long long ans = 0ll;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                cnt[i] += cnt[j];
                cnt[i] %= MOD;
            }
        }
        cnt[i]++;
        cnt[i] %= MOD;
        ans += cnt[i];
        ans %= MOD;
    }
    cout << "Case #" << caseNum << ": "
         << ans << endl;
}

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
        long long n, m, x, y, z;
        cin >> n >> m >> x >> y >> z;
        long long b[m];
        vector<int> a(n);
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {

            a[i] = b[i % m];
            b[i % m] = (x * b[i % m] + y * (i + 1)) % z;
        }
        //solve(caseNum, a);
        //bitree2();
        solveLarge(caseNum, a);
    }

    return 0;
}

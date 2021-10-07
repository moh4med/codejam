#include <bits/stdc++.h>

using namespace std;
vector<int> allPrime;
vector<int> prime;
void simpleSieve(int limit)
{
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= limit; ++i)
    {
        if (isPrime[i] == true)
        {
            // If not marked yet, then its a prime
            prime.push_back(i);
            for (int j = 2 * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
}
int find(vector<int> &parent, int i)
{
    if (parent[i] == i)
        return i;
    parent[i] = find(parent, parent[i]);
    return parent[i];
}

void Union(vector<int> &parent, int x, int y)
{
    parent[x] = y;
}
int solve()
{
    long long a, b, p;
    cin >> a >> b >> p;
    int len = b - a + 1;
    vector<int> parent(len, -1);
    for (int i = 0; i < len; i++)
    {
        parent[i] = i;
    }
    int ans = len;
    for (int i = 0; i < prime.size(); i++)
    {
        if (prime[i] < p)
        {
            continue;
        }
        long long loLim = (a / prime[i]) * prime[i];
        if (loLim < a)
        {
            loLim += prime[i];
        }
        if (loLim > b)
        {
            break;
        }
        for (long long j = loLim; j <= b; j += prime[i])
        {
            //j have i as prime factor
            int y = find(parent, loLim - a);
            int z = find(parent, j - a);
            if (y != z)
            {
                Union(parent, z, y);
                ans--;
            }
        }
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const clock_t begin_time = clock();
    int t;
    cin >> t;

    simpleSieve(1000001);
    for (int k = 1; k <= t; k++)
    {
        int ans = solve();
        cout << "Case #" << k << ": "
             << ans << endl;
    }
    std::cerr << float(clock() - begin_time) / CLOCKS_PER_SEC;
    return 0;
}

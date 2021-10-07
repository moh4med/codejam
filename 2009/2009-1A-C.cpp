#include <bits/stdc++.h>

using namespace std;
long long biCoeff[50][50];
void CalcbiCoeff()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            biCoeff[i][j] = 0;
        }
        biCoeff[i][0] = 1;
        biCoeff[i][i] = 1;
    }

    for (int i = 0; i < 50; i++)
    {
        for (int j = 1; j < i; j++)
        {
            biCoeff[i][j] = biCoeff[i - 1][j] + biCoeff[i - 1][j - 1];
        }
    }
}
void solve()
{
    CalcbiCoeff();
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        int n, c;
        cin >> c >> n;
        long double a[c + 1];
        long long totalP=biCoeff[c][n];
        a[c] = 0.0;
        for (int i = c - 1; i >= n; i--)
        {
            long double k = 1.0*biCoeff[i][n]/totalP;
            long long l = 0ll;
            long double d = 1.0;
            for (int j = i + 1; j < c && (j - i <= n); j++)
            {
                l = (biCoeff[c - i][j - i] * biCoeff[i][n - (j - i)]);
                d += (1.0 * l * a[j]/totalP);
            }
            a[i] = (d / (1 - k));
        }

        cout << "Case #" << caseNum << ": "
             << (1+a[n]) << endl;
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

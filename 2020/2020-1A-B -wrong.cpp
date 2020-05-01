#include <bits/stdc++.h>

using namespace std;

const int MaxW = 34;

long long C[MaxW][MaxW];

void binomialCoeff(int n = MaxW, int k = MaxW)
{

    int i, j;

    // Caculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1ll;

            // Calculate value using previously
            // stored values
            else
                C[i][j] = 1ll * C[i - 1][j - 1] +
                          1ll * C[i - 1][j];
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
    int totalCases;
    cin >> totalCases;
    binomialCoeff();
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout<<setw(4)<<C[i][j];
        }
        cout<<endl;
        
    }
    
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        int n;
        cin >> n;
        long long tot = 1;
        // cout << "Case #" << caseNum << ": " << endl;
        // cout << "1 1" << endl;
        // int x=2,y=1;
        // while (tot<n)
        // {
            
        // }
    }

    return 0;
}

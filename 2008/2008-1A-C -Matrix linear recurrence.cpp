#include <bits/stdc++.h>

using namespace std;

long double pow(long double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }
    if (n == 1)
    {
        return x;
    }
    long double f = pow(x, n / 2);
    long double ans = f * f;
    if (n % 2 == 1)
    {
        ans *= x;
    }
    return ans;
}
typedef vector<vector<int>> matrix;
matrix matrixMul(matrix A, matrix B)
{
    int n = A.size();
    int m = A[0].size();
    int f = B[0].size();
    matrix C(n, vector<int>(f, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < f; j++)
        {
            for (int k = 0; k < m; k++)
            {
                C[i][j] += (((A[i][k] + 1000) % 1000) * ((B[k][j] + 1000) % 1000));
                C[i][j] %= 1000;
            }
            //C[i][j]%=1000;
            // C[i][j]=(C[i][j]+1000)%1000;
        }
    }
    return C;
}
matrix matrixPow(matrix a, int n)
{
    if (n == 1)
    {
        return a;
    }
    if (n % 2 == 1)
    {
        return matrixMul(a, matrixPow(a, n - 1));
    }
    matrix X = matrixPow(a, n / 2);
    return matrixMul(X, X);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n;
        cin >> n;
        matrix B(2, vector<int>(2));
        B[0][0] = 6;
        B[0][1] = -4;
        B[1][0] = 1;
        B[1][1] = 0;
        matrix y(2, vector<int>(1));
        y[0][0] = 6;
        y[1][0] = 2;

        //long double x = 3.0 + sqrt(5);
        //long double ans = pow(x, j);
        matrix f = matrixMul(matrixPow(B, n), y);
        int xn = f[1][0];
        int ans = xn - 1;
        string sol = to_string(ans);
        while (sol.size() < 3)
        {
            sol = "0" + sol;
        }
        cout << fixed << setprecision(30) << showpoint;
        cout << "Case #" << k + 1 << ": " << sol << endl;

        //         cout << "Case #" << k + 1 << ": " << j << " : " << showpoint << fixed <<xn<<"  :   "<< (ans) << endl;
    }

    return 0;
}

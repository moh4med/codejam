#include <bits/stdc++.h>

using namespace std;
vector<int> split(string x)
{
    stringstream ss(x);
    string token;
    vector<int> cont;
    while (getline(ss, token, ' '))
    {
        cont.push_back(stoi(token));
    }
    return cont;
}
void solve()
{
    int totalCases;
    cin >> totalCases;
    string sd;
    getline(cin, sd);
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        string s;
        getline(cin, s);
        vector<int> a = split(s);

        char y[100];
        itoa(2, y, 2);
        string x;
        int ans = -1;
        for (int i = 2; i < 1000000; i++)
        {
            bool ok = true;
            for (auto f : a)
            {
                itoa(i, y, f);
                x = y;
                int sum = 0;
                for (int j = 0; j < 100 && sum != 1; j++)
                {

                    for (int i = 0; i < x.size(); i++)
                    {
                        sum += ((x[i] - '0') * (x[i] - '0'));
                    }
                    //cout << i << " " << f << " " << sum << " " << x << endl;
                    if (sum == 1)
                    {
                        // cout << i << " " << f << " " << sum << " " << x << endl;
                        break;
                    }
                    itoa(sum, y, f);
                    x = y;
                    sum = 0;
                }
                if (sum == 1)
                {
                    //  cout << i << " " << f << endl;
                }
                else
                {
                    ok = false;
                    break;
                }

                //cout << i << " , " << f << " : " << x << endl;
            }
            if (ok)
            {
                ans = i;
                break;
            }
        }

        cout << "Case #" << caseNum << ": "
             << ans << endl;
    }
}
void solveLarge()
{
    char y[100];
    itoa(2, y, 2);
    string x;
    int ans = -1;
    vector<vector<int>> d(11, vector<int>());
    int maxE = 12000000;
    vector<vector<int>> exist(11, vector<int>(maxE, 0)); //0:not seen , 1:seen ,2:true,3,false
    for (int i = 2; i < maxE; i++)
    {
        // double xxx = floor(log10(i));
        // if (abs(i * 100.0 / maxE) == floor(i * 100.0 / maxE))
        // {
        //     cout << (i * 100.0 / maxE) << endl;
        // }

        bool ok = true;
        for (int f = 2; f < 11; f++)
        {
            itoa(i, y, f);
            x = y;
            int sum = 0;
            vector<int> prevSum;
            exist[f][i] = 1;
            prevSum.push_back(i);
            int flag = -1;
            for (int j = 0;; j++)
            {

                for (int i = 0; i < x.size(); i++)
                {
                    sum += ((x[i] - '0') * (x[i] - '0'));
                }
                //cout << i << " " << f << " " << sum << " " << x << endl;

                prevSum.push_back(sum);
                if (exist[f][sum] == 1 || exist[f][sum] == 3)
                {
                    flag = 3;
                    break;
                }
                else if (exist[f][sum] == 2 || sum == 1)
                {
                    flag = 2;
                    break;
                }
                exist[f][sum] = 1;

                itoa(sum, y, f);
                x = y;
                sum = 0;
            }
            for (int i = 0; i < prevSum.size(); i++)
            {
                exist[f][prevSum[i]] = flag;
            }
            if (flag == 2)
            {
                d[f].push_back(i);
            }

            //cout << i << " , " << f << " : " << x << endl;
        }
    }
    // for (int i = 2; i < 10; i++)
    // {
    //     cout << i << " : ";
    //     for (auto x : d[i])
    //         cout << x << " ";
    //     cout << endl;
    // }

    int totalCases;
    cin >> totalCases;
    string sd;
    getline(cin, sd);

    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        string s;
        getline(cin, s);
        vector<int> a = split(s);

        vector<int> common = d[a[0]];
        for (int i = 1; i < a.size(); i++)
        {
            // common=set_intersection(common,d[a[i]]);
            vector<int> inter;
            set_intersection(common.begin(), common.end(), d[a[i]].begin(), d[a[i]].end(), back_inserter(inter));
            common = inter;
        }
        if (common.empty())
        {
            cout << "Case #" << caseNum << ": "
                 << "wrong" << endl;
            return;
        }
        else
        {
            cout << "Case #" << caseNum << ": "
                 << common[0] << endl;
        }
    }
}
void solveLarge2()
{
    char y[40];
    for (int i = 0; i < 40; i++)
    {
        y[i] = '0';
    }
    string x;
    int ans = -1;
    vector<vector<int>> d(11, vector<int>());
    int maxE = 12000000;
    // int maxE = 300000;

    vector<vector<int>> exist(11, vector<int>(maxE, 0)); //0:not seen , 1:seen ,2:true,3,false
    vector<string> datasol(maxE, "");
    map<string, int> answer;
    for (int i = 2; i < maxE; i++)
    {
        if (i == 91)
        {
            int dasfd = 213;
        }
        // double xxx = floor(log10(i));
        // if (abs(i * 100.0 / maxE) == floor(i * 100.0 / maxE))
        // {
        //     cout << (i * 100.0 / maxE) << endl;
        // }

        bool ok = true;
        for (int f = 2; f < 11; f++)
        {
            itoa(i, y, f);
            string x(y);
            int sum = 0;
            vector<int> prevSum;
            exist[f][i] = 1;
            prevSum.push_back(i);
            int flag = -1;
            for (int j = 0;; j++)
            {

                for (int i = 0; i < x.size(); i++)
                {
                    sum += ((x[i] - '0') * (x[i] - '0'));
                }
                //cout << i << " " << f << " " << sum << " " << x << endl;

                prevSum.push_back(sum);
                if (exist[f][sum] == 1 || exist[f][sum] == 3)
                {
                    flag = 3;
                    break;
                }
                else if (exist[f][sum] == 2 || sum == 1)
                {
                    flag = 2;
                    break;
                }
                exist[f][sum] = 1;

                itoa(sum, y, f);
                x = y;
                sum = 0;
            }
            for (int i = 0; i < prevSum.size(); i++)
            {
                exist[f][prevSum[i]] = flag;
            }
            if (flag == 2)
            {
                if (f == 10)
                {
                    datasol[i] += "#";
                }
                else
                {
                    datasol[i] += to_string(f);
                }

                if (answer[datasol[i]] == 0)
                {
                    answer[datasol[i]] = i;
                }
            }

            //cout << i << " , " << f << " : " << x << endl;
        }
    }
    // for (int i = 2; i < 10; i++)
    // {
    //     cout << i << " : ";
    //     for (auto x : d[i])
    //         cout << x << " ";
    //     cout << endl;
    // }

    int totalCases;
    cin >> totalCases;
    string sd;
    getline(cin, sd);

    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        string s;
        getline(cin, s);
        string xx = "";
        vector<int> a = split(s);

        ans = maxE + 1;
        for (auto kk : answer)
        {
            bool ok = true;
            for (auto ch : a)
            {

                string cha = "#";
                if (ch != 10)
                {
                    cha = to_string(ch);
                }
                if (kk.first.find(cha) == string::npos)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                ans = min(ans, kk.second);
            }
        }
        if (ans == maxE + 1)
        {
            cout << "Case #" << caseNum << ": "
                 << "wrong" << endl;
            break;
        }
        else
        {
            cout << "Case #" << caseNum << ": "
                 << ans << endl;
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
    //solve();
    // solveLarge();

    solveLarge2();

    return 0;
}

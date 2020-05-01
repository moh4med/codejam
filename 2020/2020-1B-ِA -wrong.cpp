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
        long long x, y, rx, ry;
        cin >> rx >> ry;
        x = abs(rx);
        y = abs(ry);
        if (x % 2 && y % 2)
        {
            cout << "Case #" << caseNum << ": "
                 << "IMPOSSIBLE" << endl;
        }
        else
        {
            string xp = "", yp = "", invp = "", posp = "";
            long long d = x;
            while (d > 0)
            {
                if (d % 2 == 0)
                {
                    xp.push_back('0');
                }
                else
                {
                    xp.push_back('1');
                }
                d /= 2;
            }
            d = y;
            while (d > 0)
            {
                if (d % 2 == 0)
                {
                    yp.push_back('0');
                }
                else
                {
                    yp.push_back('1');
                }
                d /= 2;
            }

            int cs = 0;
            long long xx = 1;
            int lastIndex = -1;
            if (x % 2 == 0 && y % 2 == 1)
            {
                cs = 1;
                posp = xp;
                invp.push_back('1');
                for (int i = 1; i < yp.size(); i++)
                {
                    invp.push_back(yp[i] == '0' ? '1' : '0');
                }
                lastIndex = invp.size();
                invp.push_back('1');
            }

            else if (x % 2 == 1 && y % 2 == 0)
            {
                cs = 2;
                posp = yp;
                invp.push_back('1');
                for (int i = 1; i < xp.size(); i++)
                {
                    invp.push_back(xp[i] == '0' ? '1' : '0');
                }
                lastIndex = invp.size();
                invp.push_back('1');
            }
            while (xp.size() != yp.size())
            {
                if (xp.size() < yp.size())
                {
                    xp.push_back('0');
                }
                else
                {
                    yp.push_back('0');
                }
            }
            while (posp.size() != invp.size())
            {
                if (posp.size() < invp.size())
                {
                    posp.push_back('0');
                }
                else
                {
                    invp.push_back('0');
                }
            }
            bool ok = true;
            string ans = "";
            for (int i = 0; i < yp.size(); i++)
            {
                if (xp[i] == '1' && yp[i] == '1')
                {
                    ok = false;
                    break;
                }
                else if (xp[i] == '1' && yp[i] == '0')
                {
                    ans.push_back('E');
                }
                else if (xp[i] == '0' && yp[i] == '1')
                {
                    ans.push_back('N');
                }
                else
                {
                    ok = false;
                    break;
                }
            }

            if (!ok && cs > 0)
            {
                ok = true;
                ans = "";
                for (int i = 0; i < invp.size(); i++)
                {
                    if (invp[i] == '1' && posp[i] == '1')
                    {
                        ok = false;
                        break;
                    }
                    else if (invp[i] == '1' && posp[i] == '0')
                    {
                        if (cs == 1)
                        {
                            if (i == lastIndex)
                            {
                                ans.push_back('N');
                            }
                            else
                            {
                                ans.push_back('S');
                            }
                        }
                        else
                        {
                            if (i == lastIndex)
                            {
                                ans.push_back('E');
                            }
                            else
                            {
                                ans.push_back('W');
                            }
                        }
                    }
                    else if (invp[i] == '0' && posp[i] == '1')
                    {
                        if (cs == 1)
                        {
                            ans.push_back('E');
                        }
                        else
                        {
                            ans.push_back('N');
                        }
                    }
                    else
                    {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok)
            {
                cout << "Case #" << caseNum << ": "
                     << "IMPOSSIBLE" << endl;
            }
            else
            {
                for (int i = 0; i < ans.size(); i++)
                {
                    if (rx < 0)
                    {
                        if (ans[i] == 'E')
                        {
                            ans[i] = 'W';
                        }
                        else if (ans[i] == 'W')
                        {
                            ans[i] = 'E';
                        }
                    }
                    if (ry < 0)
                    {
                        if (ans[i] == 'N')
                        {
                            ans[i] = 'S';
                        }
                        else if (ans[i] == 'S')
                        {
                            ans[i] = 'N';
                        }
                    }
                }

                cout << "Case #" << caseNum << ": " << ans << endl;
            }
        }
    }

    return 0;
}

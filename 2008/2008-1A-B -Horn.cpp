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
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n, m, l, x, y;
        cin >> n >> m;
        vector<bool> sol(n + 2, false);
        vector<bool> ans(n + 2, false);
        sol[0] = false;
        sol[n + 1] = true;
        ans[0] = true;
        ans[n + 1] = true;
        queue<pair<vector<int>, int>> q;
        vector<vector<pair<int, bool>>> orders(m);
        for (int i = 0; i < m; i++)
        {
            cin >> l;
            vector<int> f;
            int posindex = 0;
            for (int j = 0; j < l; j++)
            {
                cin >> x >> y;
                orders[i].push_back({x, y});
                if (y)
                {
                    posindex = x;
                }
                else
                {
                    f.push_back(x);
                }
            }
            if (l == 1)
            {
                //sol[x] = (posindex != 0);
                vector<int> dummy;
                dummy.push_back(n + 1); //always true
                if (y)
                {
                    q.push({dummy, x});
                }
                else
                {
                    q.push({dummy, x + n + 1});
                }
            }
            else
            {
                q.push({f, posindex});
            }
        }
        bool Impossible = false;
        int totalStep=0;
        while (!q.empty())
        {
            if(totalStep>q.size()+2){
                break;
            }
            totalStep++;
            auto gg = q.front();
            bool sec;
            int itemIndex = gg.second;
            if (gg.second > n + 1)
            {
                sec = !sol[gg.second - n - 1];
                itemIndex -= (n + 1);
            }
            else
            {
                sec = sol[gg.second];
            }
            vector<int> fir = gg.first;
            bool firVal = true;
            if (sec)
            {
                if (gg.second > n + 1)
                {
                    sol[itemIndex] = 0;
                }
                else
                {
                    sol[itemIndex] = 1;
                }

                ans[itemIndex] = true;
                q.pop();
                totalStep=0;
            }
            else
            {
                for (int i = 0; i < fir.size(); i++)
                {
                    if (!sol[fir[i]])
                    {
                        firVal = false;
                        break;
                    }
                }
                if (firVal)
                {
                    if (ans[itemIndex])
                    {
                        Impossible = true;
                        break;
                    }
                    else
                    {
                        if (gg.second > n + 1)
                        {
                            sol[itemIndex] = 0;
                        }
                        else
                        {
                            sol[itemIndex] = 1;
                        }

                        ans[itemIndex] = true;
                    }
                    q.pop();
                    totalStep=0;
                }else{
                    q.push(q.front());
                    q.pop();
                }    
            }
        }
        if (Impossible)
        {
            cout << "Case #" << k + 1 << ": "
                 << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "Case #" << k + 1 << ": ";
            for (int i = 1; i <= n; i++)
            {
                cout << sol[i] << " ";
            }
            cout << endl;

            bool isAllOk = true;
            int failCase = -1;
            for (int i = 0; i < m; i++)
            {
                bool isPersonOk = false;
                for (int j = 0; j < orders[i].size(); j++)
                {
                    auto order = orders[i][j];
                    if (sol[order.first] == order.second)
                    {
                        //cout<<"person "<<i<<" have plate number "<<order.first<<" with  "<<(order.second==0?"negative":"positive")<<endl;
                        isPersonOk = true;
                        break;
                    }
                }
                if (!isPersonOk)
                {
                    cout << "person " << i + 1 << " failed" << endl;

                    isAllOk = false;
                }
            }
            if (isAllOk)
            {
                //cout<<"All Persons Ok"<<endl;
            }
            else
            {
                if (k + 1 == 72)
                {
                    cout<<"Failed Cases:\n";
                    cout << n << endl;
                    cout << m << endl;
                    for (int i = 0; i < m; i++)
                    {
                        cout << orders[i].size() << " ";
                        for (int j = 0; j < orders[i].size(); j++)
                        {
                            auto order = orders[i][j];
                            cout << order.first << " " << order.second << "   ";
                        }
                        cout << endl;
                    }
                }
            }
        }
    }

    return 0;
}

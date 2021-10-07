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
        vector<bool> sol(n + 1, false);
        vector<int>head(m+1,0);
        vector<int>margin(m+1,0);
        vector<vector<int>>tails(n+1,vector<int>());
        queue<int>q;
        for (int i = 1; i <=m; i++)
        {
            cin >> l;
            for (int j = 0; j < l; j++)
            {
                cin >> x >> y;
                if (y)
                {
                    head [i]=x;                     
                }
                else
                {
                    margin[i]++;
                    tails[x].push_back(i);
                }
            }
            if(margin[i]==0){
                q.push(i);
            }        
        }
        bool Impossible = false;
        while (!q.empty())
        {
            int c=q.front();
            int headC=head[c];
            q.pop();
            if(head[c]==0){
                Impossible=true;
                break;
            }
            if(sol[headC])continue;
            sol[headC]=true;
            for (int i = 0; i < tails[headC].size(); i++)
            {
                margin[tails[headC][i]]--;
                if(margin[tails[headC][i]]==0){
                    q.push(tails[headC][i]);
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

           
        }
    }

    return 0;
}

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
        int k, n;
        cin >> k >> n;
        vector<int> d(n);
        vector<int> ans(k + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
            ans[d[i]]=-1;
        }
        //sort(d.begin(),d.end());
        deque<pair<int, int>> q;
        q.push_back({1, k});
        int current = 1;
        
        int cnt = 0;
        int cyclefirst = -1;
        int tot=0;
        while (!q.empty())
        {
            // if(tot==n){
            //     cout<<"Adsfdasfd"<<endl;
            //     break;
            // }
            auto x = q.front();
            if (x.first == cyclefirst)
            {
                //cout<<x.first<<" "<<cnt<<" "<<current<<endl;
                if (current % cnt == 0)
                {
                    cnt = ((int)current/cnt)*cnt-cnt;
                }
                else
                {
                    cnt = ((int)current/cnt)*cnt;
                }
            }
            q.pop_front();
            //cout << x.first << " " << x.second << endl;
            if (cnt + (x.second - x.first + 1) >= current)
            {
                int idx = x.first + (current - cnt) - 1;
                //cout<<current<<" "<<idx<<" "<<x.first<<" "<<x.second<<endl;
                
                if(ans[idx]==-1){
                    tot++;
                }
                ans[idx] = current;
                current++;
                cnt = 0;
                cyclefirst=-1;
                if (idx != x.second)
                {
                    q.push_front({idx + 1, x.second});
                }

                if (idx != x.first)
                {
                    q.push_back({x.first, idx - 1});
                }
            }
            else
            {
                //cout<<"zcvx"<<endl;
                if (cnt == 0)
                {
                    cyclefirst = x.first;
                }
                cnt += (x.second - x.first + 1);
                q.push_back(x);
            }
        }
        cout << "Case #" << caseNum << ": ";
        for (int i = 1; i <= n; i++)
        {
            cout << ans[d[i - 1]] << " ";
        }

        cout << endl;
    }

    return 0;
}

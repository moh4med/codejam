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
        long long p,k,l;
        cin >> p >> k >> l;
        vector<int>x(l);
        for (int i = 0; i < l; i++)
        {
            cin>>x[i];
        }
        
        sort(x.rbegin(),x.rend());
        long long ans=0ll;
        for (int i = 0,cnt=0,f=1; i < l; i++,cnt++)
        {
           if(cnt==k){
               cnt=0;
               f++;
           }
           //cout<<x[i]<<" "<<cnt<<" "<<f<<endl;
           ans+=(1ll*f*x[i]);
        }
        
        cout << "Case #" << caseNum << ": "
             << ans << endl;
    }

    return 0;
}

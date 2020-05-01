#include <bits/stdc++.h>

using namespace std;
struct intersection
{
    int s;
    int w;
    int t;
};

struct gNode
{
    int x;
    int y;
    int v;
    bool operator<(const gNode &rhs) const
    {
        return v < rhs.v;
    }
};
struct ComparegNode
{
    bool operator()(gNode const &p1, gNode const &p2)
    {
        return p1.v > p2.v;
    }
};
void solve()
{
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        int n, m, s, w, t;
        cin >> n >> m;
        intersection a[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j].s >> a[i][j].w >> a[i][j].t;
                a[i][j].t = a[i][j].t % (a[i][j].s + a[i][j].w);
            }
        }

        int dp[2 * n][2 * m];
        memset(dp, 0, sizeof(dp));

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2 * m; j++)
            {
                dp[i][j] = INT_MAX;
            }
        }
        int x, y, d, k, available;
        dp[2 * n - 1][0] = 0;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2 * m; j++)
            {
                x = i / 2;
                y = j / 2;
                intersection f = a[x][y];
                d = dp[i][j];
                if (d < f.t)
                {
                    k = (d - f.t + f.s + f.w) % (f.s + f.w);
                }
                else
                {
                    k = (d - f.t) % (f.s + f.w);
                }
                if (i > 0)
                {
                    //go up
                    if (i % 2 == 1)
                    {
                        //pass through intersection

                        if (k < f.s) //current northsouth is on
                        {
                            available = d;
                        }
                        else //current northsouth is off
                        {
                            available = d - k + f.s + f.w;
                        }

                        dp[i - 1][j] = min(dp[i - 1][j], available + 1);
                    }
                    else
                    {
                        //pass through building
                        dp[i - 1][j] = min(dp[i - 1][j], d + 2);
                    }
                }
                if (j < 2 * m)
                {

                    //go right
                    if (j % 2 == 0)
                    {

                        //pass through building

                        if (k >= f.s) //current northsouth is off
                        {
                            available = d;
                        }
                        else //current northsouth is on
                        {
                            available = d - k + f.s;
                        }

                        dp[i][j + 1] = min(dp[i][j + 1], available + 1);
                    }
                    else
                    {
                        dp[i][j + 1] = min(dp[i][j + 1], d + 2);
                    }
                }
            }
        }

        cout << "Case #" << caseNum << ": "
             << dp[0][2 * m - 1] << endl;
    }
}

void solve2()
{
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        int n, m, s, w, t;
        cin >> n >> m;
        intersection a[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j].s >> a[i][j].w >> a[i][j].t;
                a[i][j].t = a[i][j].t % (a[i][j].s + a[i][j].w);
            }
        }
        priority_queue<gNode, vector<gNode>, ComparegNode> pq;
        pq.push({2 * n - 1, 0, 0});
        vector<int> dist(4 * n * m, INT_MAX);
        vector<int> parent(4 * n * m, -1);
        dist[2 * m * (2 * n - 1)] = 0;
        int x, y, d, k, available, newVal, newIndex, currentIndex;
        int ans = -1;
        while (!pq.empty())
        {
            auto pn = pq.top();
            pq.pop();

            if (pn.x == 0 && pn.y == 2 * m - 1)
            {
                ans = pn.v;
                break;
            }

            currentIndex = 2 * m * (pn.x) + pn.y;
            x = pn.x / 2;
            y = pn.y / 2;
            intersection f = a[x][y];
            d = pn.v;
            if (d < f.t)
            {
                k = (d - f.t + f.s + f.w) % (f.s + f.w);
            }
            else
            {
                k = (d - f.t) % (f.s + f.w);
            }

            if (pn.x > 0)
            {
                //go up
                newVal = -1;
                newIndex = 2 * m * (pn.x - 1) + pn.y;
                if (pn.x % 2 == 1)
                {
                    //pass through intersection up

                    if (k < f.s) //current northsouth is on
                    {
                        available = d;
                    }
                    else //current northsouth is off
                    {
                        available = d - k + f.s + f.w;
                    }
                    newVal = available + 1;
                }
                else
                {
                    //pass through building up
                    newVal = pn.v + 2;
                }
                if (newVal < dist[newIndex])
                {
                    // cout << "push "
                    //      << " " << pn.x - 1 << " ,  " << pn.y << " ,  " << newVal << endl;
                    pq.push({pn.x - 1, pn.y, newVal});
                    dist[newIndex] = newVal;
                    parent[newIndex] = currentIndex;
                }
            }

            if (pn.x < 2 * n - 1)
            {
                //go down
                newVal = -1;
                newIndex = 2 * m * (pn.x + 1) + pn.y;
                if (pn.x % 2 == 0)
                {
                    //pass through intersection down

                    if (k < f.s) //current northsouth is on
                    {
                        available = d;
                    }
                    else //current northsouth is off
                    {
                        available = d - k + f.s + f.w;
                    }
                    newVal = available + 1;
                }
                else
                {
                    //pass through building down
                    newVal = pn.v + 2;
                }
                if (newVal < dist[newIndex])
                {
                    // cout << "push "
                    //      << " " << pn.x + 1 << " ,  " << pn.y << " ,  " << newVal << endl;

                    pq.push({pn.x + 1, pn.y, newVal});
                    dist[newIndex] = newVal;
                    parent[newIndex] = currentIndex;
                }
            }
            if (pn.y < 2 * m - 1)
            {

                //go right

                newVal = -1;
                newIndex = 2 * m * (pn.x) + (pn.y + 1);
                if (pn.y % 2 == 0)
                {

                    //pass through intersection right

                    if (k >= f.s) //current northsouth is off
                    {
                        available = d;
                    }
                    else //current northsouth is on
                    {
                        available = d - k + f.s;
                    }

                    newVal = available + 1;
                }
                else
                {
                    //pass through building right
                    newVal = pn.v + 2;
                }
                if (newVal < dist[newIndex])
                {
                    // cout << "push "
                    //      << " " << pn.x << " ,  " << pn.y + 1 << " ,  " << newVal << endl;

                    pq.push({pn.x, pn.y + 1, newVal});
                    dist[newIndex] = newVal;
                    parent[newIndex] = currentIndex;
                }
            }
            if (pn.y > 0)
            {

                //go left

                newVal = -1;
                newIndex = 2 * m * (pn.x) + (pn.y - 1);
                if (pn.y % 2 == 1)
                {

                    //pass through intersection left

                    if (k >= f.s) //current northsouth is off
                    {
                        available = d;
                    }
                    else //current northsouth is on
                    {
                        available = d - k + f.s;
                    }

                    newVal = available + 1;
                }
                else
                {
                    //pass through building left
                    newVal = pn.v + 2;
                }
                if (newVal < dist[newIndex])
                {
                    // cout << "push "
                    //      << " " << pn.x << " ,  " << pn.y - 1 << " ,  " << newVal << endl;

                    pq.push({pn.x, pn.y - 1, newVal});
                    dist[newIndex] = newVal;
                    parent[newIndex] = currentIndex;
                }
            }
        }
        vector<gNode> Steps;
        int currentPos = 2 * m - 1;
        while (currentPos != -1)
        {
            Steps.push_back({currentPos / (2 * m), currentPos % (2 * m), dist[currentPos]});
            currentPos = parent[currentPos];
        }
        reverse(Steps.begin(), Steps.end());
        // for(auto ff:Steps){
        //     cout<<ff.x<<" "<<ff.y<<" "<<ff.v<<endl;
        // }
        cout << "Case #" << caseNum << ": "
             << ans << endl;
    }
}
void solve3()
{
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        int n, m, s, w, t;
        cin >> n >> m;
        intersection a[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j].s >> a[i][j].w >> a[i][j].t;
                a[i][j].t = a[i][j].t % (a[i][j].s + a[i][j].w);
            }
        }
        priority_queue<gNode, vector<gNode>, ComparegNode> pq;
        pq.push({2 * n - 1, 0, 0});
        vector<int> dist(4 * n * m, INT_MAX);
        vector<int> parent(4 * n * m, -1);
        dist[2 * m * (2 * n - 1)] = 0;
        int x, y, d, k, available, newVal, newIndex, currentIndex, newX, newY;
        int ans = -1;
        while (!pq.empty())
        {
            auto pn = pq.top();
            pq.pop();

            if (pn.x == 0 && pn.y == 2 * m - 1)
            {
                ans = pn.v;
                break;
            }
            if (pn.x == 1 && pn.y == 2)
            {
                int test=1;
            }

            currentIndex = 2 * m * (pn.x) + pn.y;
            x = pn.x / 2;
            y = pn.y / 2;
            intersection f = a[x][y];
            d = pn.v;
            if (d < f.t)
            {
                k = (d - f.t + f.s + f.w) % (f.s + f.w);
            }
            else
            {
                k = (d - f.t) % (f.s + f.w);
            }
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            for (int i = 0; i < 4; i++) //down,up,right,left
            {
                newX = pn.x + dx[i];
                newY = pn.y + dy[i];

                if (newX >= 0 && newX < 2 * n && newY >= 0 && newY < 2 * m)
                {
                    newVal = -1;
                    newIndex = 2 * m * newX + newY;
                    bool isIntersection = i > 1 ? pn.y % 2 == i % 2 : pn.x % 2 == i % 2;
                    bool isOn = i > 1 ? k >= f.s : k < f.s;
                    if (isIntersection)
                    {

                        if (isOn) //current intersection is on in this way
                        {
                            available = d;
                        }
                        else //current intersection is off in this way
                        {
                            available = d - k + f.s + (i > 1 ? 0 : f.w);
                        }
                        newVal = available + 1;
                    }
                    else
                    {
                        //pass through building up
                        newVal = pn.v + 2;
                    }
                    if (newVal < dist[newIndex])
                    {

                        pq.push({newX, newY, newVal});
                        dist[newIndex] = newVal;
                        parent[newIndex] = currentIndex;
                    }
                }
            }
        }
        vector<gNode> Steps;
        int currentPos = 2 * m - 1;
        while (currentPos != -1)
        {
            Steps.push_back({currentPos / (2 * m), currentPos % (2 * m), dist[currentPos]});
            currentPos = parent[currentPos];
        }
        reverse(Steps.begin(), Steps.end());
        // for(auto ff:Steps){
        //     cout<<ff.x<<" "<<ff.y<<" "<<ff.v<<endl;
        // }
        cout << "Case #" << caseNum << ": "
             << ans << endl;
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
    solve3();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
class Xnode
{
public:
    int x;
    int y;
    char op;
    int step;
    int PrevSum;
    string ans;
    Xnode()
    {
        step = 0;
        ans = "";
    }
};
void solve()
{
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        if (caseNum == 33)
        {
            bool test = true;
        }
        int w, q;
        cin >> w >> q;
        vector<string> a(w);
        for (int i = 0; i < w; i++)
        {
            cin >> a[i];
        }
        vector<string> ans(q + 1, "");
        int totAns = 0;
        vector<int> xVal(q + 1);
        map<int, int> arrMap;
        for (int i = 1; i <= q; i++)
        {
            cin >> xVal[i];
            arrMap[xVal[i]] = i;
        }
        queue<Xnode> qS;
        set<string> exist;
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < w; j++)
            {
                Xnode x = Xnode();
                x.x = i;
                x.y = j;
                x.ans.push_back(a[i][j]);
                x.step = 0;
                x.PrevSum = 0;
                if (a[i][j] == '+')
                {
                    x.op = '+';
                }
                else if (a[i][j] == '-')
                {
                    x.op = '-';
                }
                else
                {
                    x.op = ' ';
                    x.PrevSum = a[i][j] - '0';
                }
                string keyVal = to_string(x.x) + to_string(x.y) + to_string(x.PrevSum);
                if (exist.count(keyVal) == 0)
                {
                    exist.insert(keyVal);
                    qS.push(x);
                }

                int f = x.PrevSum;
                int ff = arrMap[f];
                string fff = ans[arrMap[f]];
                if ((arrMap[x.PrevSum] != 0) && (ans[arrMap[x.PrevSum]] == ""))
                {
                    // cout << x.PrevSum << " : " << arrMap[x.PrevSum] << " : " << ans[arrMap[x.PrevSum]] << endl;

                    totAns++;
                    ans[arrMap[x.PrevSum]] = x.ans;
                }
            }
        }
        int totalStep = 0;

        while (!qS.empty() && totalStep < 1000000 && totAns < q)
        {
            totalStep++;
            auto f = qS.front();
            // cout << totalStep << " " << f.ans << " : " << f.PrevSum << endl;

            qS.pop();
            if (f.ans == "1+")
            {
                bool ktest = true;
            }
            Xnode left = Xnode();
            Xnode right = Xnode();
            Xnode up = Xnode();
            Xnode down = Xnode();
            int xx, yy;
            if (f.x > 0)
            {
                xx = f.x - 1;
                yy = f.y;
                up.x = xx;
                up.y = yy;
                up.ans = f.ans;
                up.ans.push_back(a[xx][yy]);
                up.step = f.step + 1;
                up.PrevSum = f.PrevSum;
                if (a[xx][yy] == '+')
                {
                    up.op = '+';
                }
                else if (a[xx][yy] == '-')
                {
                    up.op = '-';
                }
                else
                {
                    up.op = ' ';
                    if (f.op == '+')
                    {
                        up.PrevSum += (a[xx][yy] - '0');
                    }
                    else if (f.op == '-')
                    {
                        up.PrevSum -= (a[xx][yy] - '0');
                    }
                }
                string keyVal = to_string(up.x) + to_string(up.y) + to_string(up.PrevSum);
                if (exist.count(keyVal) == 0)
                {
                    exist.insert(keyVal);
                    qS.push(up);
                }

                if ((arrMap[up.PrevSum] != 0) && (ans[arrMap[up.PrevSum]] == ""))
                {
                    // cout << up.PrevSum << " : " << arrMap[up.PrevSum] << " : " << ans[arrMap[up.PrevSum]] << endl;

                    totAns++;
                    ans[arrMap[up.PrevSum]] = up.ans;
                }
            }
            if (f.x < w - 1)
            {
                xx = f.x + 1;
                yy = f.y;
                down.x = xx;
                down.y = yy;
                down.ans = f.ans;
                down.ans.push_back(a[xx][yy]);
                down.step = f.step + 1;
                down.PrevSum = f.PrevSum;
                if (a[xx][yy] == '+')
                {
                    down.op = '+';
                }
                else if (a[xx][yy] == '-')
                {
                    down.op = '-';
                }
                else
                {
                    down.op = ' ';
                    if (f.op == '+')
                    {
                        down.PrevSum += (a[xx][yy] - '0');
                    }
                    else if (f.op == '-')
                    {
                        down.PrevSum -= (a[xx][yy] - '0');
                    }
                }
                string keyVal = to_string(down.x) + to_string(down.y) + to_string(down.PrevSum);
                if (exist.count(keyVal) == 0)
                {
                    exist.insert(keyVal);
                    qS.push(down);
                }

                if ((arrMap[down.PrevSum] != 0) && (ans[arrMap[down.PrevSum]] == ""))
                {
                    // cout << down.PrevSum << " : " << arrMap[down.PrevSum] << " : " << ans[arrMap[down.PrevSum]] << endl;
                    totAns++;
                    ans[arrMap[down.PrevSum]] = down.ans;
                }
            }
            if (f.y > 0)
            {
                xx = f.x;
                yy = f.y - 1;
                left.x = xx;
                left.y = yy;
                left.ans = f.ans;
                left.ans.push_back(a[xx][yy]);
                left.step = f.step + 1;
                left.PrevSum = f.PrevSum;
                if (a[xx][yy] == '+')
                {
                    left.op = '+';
                }
                else if (a[xx][yy] == '-')
                {
                    left.op = '-';
                }
                else
                {
                    left.op = ' ';
                    if (f.op == '+')
                    {
                        left.PrevSum += (a[xx][yy] - '0');
                    }
                    else if (f.op == '-')
                    {
                        left.PrevSum -= (a[xx][yy] - '0');
                    }
                }
                string keyVal = to_string(left.x) + to_string(left.y) + to_string(left.PrevSum);
                if (exist.count(keyVal) == 0)
                {
                    exist.insert(keyVal);
                    qS.push(left);
                }

                if ((arrMap[left.PrevSum] != 0) && (ans[arrMap[left.PrevSum]] == ""))
                {
                    // cout << left.PrevSum << " : " << arrMap[left.PrevSum] << " : " << ans[arrMap[left.PrevSum]] << endl;

                    totAns++;
                    ans[arrMap[left.PrevSum]] = left.ans;
                }
            }
            if (f.y < w - 1)
            {
                xx = f.x;
                yy = f.y + 1;
                right.x = xx;
                right.y = yy;
                right.ans = f.ans;
                right.ans.push_back(a[xx][yy]);
                right.step = f.step + 1;
                right.PrevSum = f.PrevSum;
                if (a[xx][yy] == '+')
                {
                    right.op = '+';
                }
                else if (a[xx][yy] == '-')
                {
                    right.op = '-';
                }
                else
                {
                    right.op = ' ';
                    if (f.op == '+')
                    {
                        right.PrevSum += (a[xx][yy] - '0');
                    }
                    else if (f.op == '-')
                    {
                        left.PrevSum -= (a[xx][yy] - '0');
                    }
                }
                string keyVal = to_string(right.x) + to_string(right.y) + to_string(right.PrevSum);
                if (exist.count(keyVal) == 0)
                {
                    exist.insert(keyVal);
                    qS.push(right);
                }

                if ((arrMap[right.PrevSum] != 0) && (ans[arrMap[right.PrevSum]] == ""))
                {
                    // cout << right.PrevSum << " : " << arrMap[right.PrevSum] << " : " << ans[arrMap[right.PrevSum]] << endl;

                    totAns++;
                    ans[arrMap[right.PrevSum]] = right.ans;
                }
            }
        }
        // cout << totalStep << endl;
        cout << "Case #" << caseNum << ": "
             << "" << endl;
        for (int i = 1; i <= q; i++)
        {
            if (ans[i][0] == '+')
            {
                cout << ans[i].substr(1) << endl;
            }
            else
            {
                cout << ans[i] << endl;
            }
        }
    }
}
vector<string> a(30);
queue<Xnode> qS;
queue<Xnode *> qSR;
map<string, string> exist;
set<string> exist2;

map<string, Xnode *> exist3;
vector<string> ans(60, "");
int totAns = 0;
map<int, int> arrMap;
int maxStep = 0;
string maxStepAns = "";
int w, q;
void Add_toQueue(Xnode *nextNode)
{
    string keyVal = to_string(nextNode->x) + "-" + to_string(nextNode->y) + "-" + to_string(nextNode->PrevSum);
    bool found = exist.find(keyVal) != exist.end();
    bool found2 = exist2.count(keyVal) != 0;
    bool found3 = exist3.find(keyVal) != exist3.end();
    if (!found3)
    {
        // exist[keyVal] = nextNode.ans;
        // exist2.insert(keyVal);
        exist3[keyVal] = nextNode;
        qSR.push(nextNode);
    }
    else
    {
        // if (exist[keyVal] > nextNode.ans)
        // {
        //     exist[keyVal] = nextNode.ans;
        //     qS.push(nextNode);
        // }
        if (exist3[keyVal]->ans == "4+4+4+9+")
        {
            // cout << "error " << nextNode.ans << endl;
            bool ktest = true;
        }
        string firstA = exist3[keyVal]->ans;
        string secondA = nextNode->ans;
        if (firstA.length() >= secondA.length())
        {
            if (firstA > secondA)
            {
                exist3[keyVal]->ans = nextNode->ans;
            }
        }
    }

    //   qS.push(nextNode);
}
void ProcessNode(Xnode);
void Process_Next(Xnode f, int xx, int yy)
{
    if (a[xx][yy] == '+')
    {
        f.x = xx;
        f.y = yy;
        f.ans.push_back(a[xx][yy]);
        f.step++;
        f.op = '+';
        ProcessNode(f);
    }
    else if (a[xx][yy] == '-')
    {
        f.x = xx;
        f.y = yy;
        f.ans.push_back(a[xx][yy]);
        f.step++;
        f.op = '-';
        ProcessNode(f);
    }
    else
    {
        Xnode *nextNode = new Xnode();
        nextNode->x = xx;
        nextNode->y = yy;
        nextNode->ans = f.ans;
        nextNode->ans.push_back(a[xx][yy]);
        if (nextNode->ans == "2+2+6+6")
        {
            // cout << "error " << nextNode.ans << endl;
            bool ktest = true;
        }
        nextNode->step = f.step + 1;
        nextNode->PrevSum = f.PrevSum;
        nextNode->op = ' ';
        if (f.op == '+')
        {
            nextNode->PrevSum += (a[xx][yy] - '0');
        }
        else if (f.op == '-')
        {
            nextNode->PrevSum -= (a[xx][yy] - '0');
        }
        Add_toQueue(nextNode);
        //qS.push(nextNode);

        int pSum = nextNode->PrevSum;
        int pSumIndex = arrMap[pSum];
        string PsumAns = ans[pSumIndex];
        if ((pSumIndex != 0))
        {
            // cout << nextNode.PrevSum << " : " << arrMap[nextNode.PrevSum] << " : " << ans[arrMap[nextNode.PrevSum]] << endl;

            if (PsumAns == "")
            {
                maxStep = max(maxStep, nextNode->step);
                totAns++;
                ans[pSumIndex] = nextNode->ans;
                maxStepAns = ans[pSumIndex];
            }
            else
            {
                if (PsumAns.length() == nextNode->ans.length())
                {
                    ans[pSumIndex] = min(ans[pSumIndex], nextNode->ans);
                    maxStepAns = ans[pSumIndex];
                }
            }
        }
    }
}
void ProcessNode(Xnode f)
{

    if (f.x > 0)
    {
        Process_Next(f, f.x - 1, f.y); //up
    }
    if (f.x < w - 1)
    {
        Process_Next(f, f.x + 1, f.y); //down
    }
    if (f.y > 0)
    {
        Process_Next(f, f.x, f.y - 1); //left
    }
    if (f.y < w - 1)
    {
        Process_Next(f, f.x, f.y + 1); //right
    }
}
void solve2()
{
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        if (caseNum == 33)
        {
            bool test = true;
        }

        cin >> w >> q;

        while (!qSR.empty())
        {
            delete qSR.front();
            qSR.pop();
        }
        for (auto gg : exist3)
        {
            delete gg.second;
        }
        exist3.clear();

        a = vector<string>(30);
        qS = queue<Xnode>();
        qSR = queue<Xnode *>();
        exist = map<string, string>();
        exist2 = set<string>();
        exist3 = map<string, Xnode *>();
        ans = vector<string>(60, "");
        totAns = 0;
        arrMap = map<int, int>();
        maxStep = 0;
        for (int i = 0; i < w; i++)
        {
            cin >> a[i];
        }
        vector<int> xVal(q + 1);
        for (int i = 1; i <= q; i++)
        {
            cin >> xVal[i];
            arrMap[xVal[i]] = i;
        }

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < w; j++)
            {
                Xnode *x = new Xnode();
                x->x = i;
                x->y = j;
                x->ans.push_back(a[i][j]);
                x->step = 0;
                x->PrevSum = 0;
                if (a[i][j] == '+')
                {
                    x->op = '+';
                    continue;
                }
                else if (a[i][j] == '-')
                {
                    x->op = '-';
                    continue;
                }
                else
                {
                    x->op = ' ';
                    x->PrevSum = a[i][j] - '0';
                }

                // qS.push(x);
                Add_toQueue(x);
                int f = x->PrevSum;
                int ff = arrMap[f];
                string fff = ans[arrMap[f]];
                if ((arrMap[x->PrevSum] != 0) && (ans[arrMap[x->PrevSum]] == ""))
                {
                    // cout << x.PrevSum << " : " << arrMap[x.PrevSum] << " : " << ans[arrMap[x.PrevSum]] << endl;
                    maxStep = max(maxStep, x->step);
                    totAns++;
                    ans[arrMap[x->PrevSum]] = x->ans;
                }
            }
        }
        int totalStep = 0;

        while (!qSR.empty() && totalStep < 10000000)
        {
            totalStep++;
            auto g = qSR.front();
            auto f = *g;
            if (totAns == q)
            {

                if (f.step > maxStep)
                {
                    break;
                }
                // else if (f.ans > maxStepAns)
                // {
                //     // break;
                // }
            }

            // cout << totalStep << " " << f.ans << " : " << f.PrevSum << endl;

            qSR.pop();
            if (f.ans == "4+4+4+9")
            {
                bool ktest = true;
            }
            ProcessNode(f);
        }
        // cout << totalStep << endl;
        cout << "Case #" << caseNum << ":"
             << "" << endl;
        for (int i = 1; i <= q; i++)
        {
            if (ans[i] == "")
            {
                cout << "error" << endl;
                continue;
            }
            cout << ans[i] << endl;
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
    const clock_t begin_time = clock();
    solve2();
    cerr << float(clock() - begin_time) / CLOCKS_PER_SEC;

    return 0;
}

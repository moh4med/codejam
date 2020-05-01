#include <bits/stdc++.h>

using namespace std;

string stree;
int CPos = 0;
int nSize = 0;

class Ptree
{
public:
    double weight;
    string feature;
    Ptree *left;
    Ptree *right;
    bool hasSub = true;
    void parse()
    {
        this->weight = readWeight();
        if (this->hasSub)
        {
            string featureT = readFeature();
            if (!this->hasSub)
            {
                return;
            }
            else
            {
                this->feature = featureT;

                this->left = new Ptree();
                this->left->parse();

                this->right = new Ptree();
                this->right->parse();
                int x = 5;
            }
        }
    }
    double readWeight()
    {
        string x = "";
        char ch;
        for (; CPos < nSize;)
        {
            ch = stree[CPos];
            if (isspace(ch) || ch == '(' || ch == ')')
            {

                CPos++;
                if (x == "")
                {
                    continue;
                }
                else
                {
                    if (ch == ')')
                    {
                        this->hasSub = false;
                    }
                    return stod(x);
                }
            }
            else
            {
                x.push_back(ch);
                CPos++;
            }
        }
        return stod(x);
    }
    string readFeature()
    {
        string x = "";
        char ch;
        for (; CPos < nSize;)
        {
            ch = stree[CPos];
            if (isspace(ch) || ch == '(')
            {
                CPos++;
                if (x == "")
                {
                    continue;
                }
                else
                {
                    return x;
                }
            }
            else
            {
                x.push_back(ch);
                CPos++;
                if (x == ")")
                {
                    this->hasSub = false;
                    return "";
                }
            }
        }
        return x;
    }
};
double check(Ptree *x, set<string> f)
{
    double val = 1.0;
    int i = 0;
    while (1)
    {
        val *= x->weight;
        if (x->hasSub)
        {
            if (f.count(x->feature))
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        else
        {
            break;
        }
    }
    return val;
}
void solve()
{
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        int n;
        cin >> n;
        string s;
        getline(cin, s);
        for (int i = 0; i < n; i++)
        {
            getline(cin, s);
            stree += s;
        }
        nSize = stree.length();
        Ptree *root = new Ptree();
        root->parse();
        int m, k;
        cin >> m;
        cout << "Case #" << caseNum << ": "
             << "" << endl;
        for (int i = 0; i < m; i++)
        {

            cin >> s >> k;
            set<string>features;
            for (int j = 0; j < k; j++)
            {
                cin >> s;
                features.insert(s);
            }
            double val = check(root, features);
            cout <<setprecision(8)<<fixed<< val << endl;
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
    solve();
    return 0;
}

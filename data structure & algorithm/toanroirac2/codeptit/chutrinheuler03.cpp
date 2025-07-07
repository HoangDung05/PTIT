#include<bits/stdc++.h>
using namespace std;
int n, m, u;
set<int> ke[105], ke1[105];

vector<int> deg_ra(105, 0);
vector<int> deg_vao(105, 0);

void Init()
{
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        for (int j = 1; j <= k ; j++)
        {
            int u; cin >> u;
            ke[i].insert(u);
            deg_ra[i]++; 
            deg_vao[u]++;
        }
    }
}

void euler(int u)
{
    vector<int> res;
    stack<int> st;
    st.push(u);
    while (!st.empty())
    {
        int x = st.top();
        if (!ke[x].empty())
        {
            int y = *ke[x].begin();
            st.push(y);
            ke[x].erase(y);
            ke[y].erase(x);
        }
        else
        {
            res.push_back(x);
            st.pop();
        }
    }
    reverse(res.begin(), res.end());
    for (int x : res)
        cout << x << " ";
}

int isEuler(){
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (abs(deg_ra[i] - deg_vao[i]) > 1)
            ++cnt1;
        if (abs(deg_ra[i] - deg_vao[i]) == 1)
            ++cnt2;
    }
    if (cnt1)
        return 0;
    else if (cnt2 == 2)
        return 2;
    else
        return 1;
}

int main()
{
    int t; cin >> t;
    if (t == 1)
    {
        cin >> n;
        for (int u = 1; u <= n; ++u) {
            string str;
            getline(cin >> ws, str);
            stringstream ss(str);
            string v;
            ss >> v;
            while (ss >> v) {
                int x = stoi(v);
                ke[u].insert(x);
                deg_vao[x]++;
                deg_ra[u]++;
            }
        }

        // for (int i = 1; i <= n; ++i)
        //     deg_ra[i] = ke[i].size();  
        cout << isEuler();
    }
    else if (t == 2)
    {
        cin >> n >> u;
        Init();
        euler(u);
    }
    
    return 0;
}
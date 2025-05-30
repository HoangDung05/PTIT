#include<bits/stdc++.h>
using namespace std;
int n, m, u;
vector<bool> visited(105, false);
set<int> ke[105], ke1[105];
vector<int> res;
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
    stack<int> st;
    st.push(u);
    while (!st.empty())
    {
        int x = st.top();
        if (!ke1[x].empty())
        {
            int y = *ke1[x].begin();
            st.push(y);
            ke1[x].erase(y);
            ke1[y].erase(x);
        }
        else
        {
            res.push_back(x);
            st.pop();
        }
    }
    reverse(res.begin(), res.end());
}

void dfs(int u)
{
    visited[u] = true;
    for (int c: ke[u])
        if (!visited[c])
            dfs(c);
}


int main()
{
    int t; cin >> t;
    if (t == 1)
    {
        cin >> n;
        Init();
        bool check = true;
        dfs(1);
        for (int i = 1; i <= n; i++)
            if (!visited[i])
            {
                check = false;
                break;
            }
        if (!check)
            cout << 0;
        else{
            int check1 = 0, check2 = 0;
            bool check_euler = true;
            bool check = true;
            for (int i = 1; i <= n; i++)
            {
                if (deg_ra[i] != deg_vao[i])
                {
                    check_euler = false;
                    if (deg_ra[i] - deg_vao[i] == 1)
                        check1++;
                    else if (deg_vao[i] - deg_ra[i] == 1)
                        check2++;
                    else
                        check = false;
                }
            }
            if (check1 && check2)
                cout << 2;
            else if (!check || !check_euler || check1 != check2)
                cout << 0;
            else if (check1 == 0 && check2 == 0 && check_euler)
                cout << 1;
        }
    }
    else if (t == 2)
    {
        cin >> n >> u;
        Init();
        euler(u);
        for (int c: res)
            cout << c << " ";
    }
    
    return 0;
}
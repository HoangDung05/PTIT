// cho đồ thị vô 
// input
// dòng đầu đưa vào t
// nếu t = 1 thì dòng thứ 2 chứa hai số nguyên dương n là số đỉnh và m là số cạnh của G
// nếu t = 2 thì dòng thứ 2 chứa ba số nguyên dương n, m và u, trong đó n là số đỉnh, m là số cạnh và u là một đỉnh của G
// Trong m dòng tiếp theo, mỗi dòng thứ i chứa hai số nguyên u, v là đỉnh đầu và đỉnh cuổi của cạnh e. Trường hợp này đồ thị Euler
// output
// Nếu t = 1 thì ghi ra giá trị 1 nếu G là Euler, giá trị 2 nếu G là nửa Euler và giá trị 0 nếu G không phải là Euler và nửa Euler.
// Nếu t = 2 thì ghi ra trên một dòng gồm dãy các đỉnh mô tả chu trình Euler bắt đầu tại đỉnh u.

#include<bits/stdc++.h>
using namespace std;
int n, m, u;
vector<bool> visited(105, false);
set<int> ke[105];
vector<int> res;

void Init()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        ke[u].insert(v);
        ke[v].insert(u);
    }
}

void euler(int u)
{
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
        cin >> n >> m;
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
            int bacle = 0;
            for (int i = 1; i <= n; i++)
                if (ke[i].size() % 2 != 0)
                    bacle++;
            if (bacle == 0)
                cout << 1;
            else if (bacle == 2)
                cout << 2;
            else 
                cout << 0;
        }
    }
    else if (t == 2)
    {
        cin >> n >> m >> u;
        Init();
        euler(u);
        for (int c: res)
            cout << c << " ";
    }
    
    return 0;
}
//1 10 11 100 101 110 111 1000
#include<bits/stdc++.h>
using namespace std;
vector<string> res;

void Init()
{
    queue<string> q;
    q.push("1");
    res.push_back("1");
    while (res.size() < 10000)
    {
        string top = q.front();
        q.pop();
        res.push_back(top + "0");
        q.push(res.back());
        res.push_back(top + "1");
        q.push(res.back());
    }
    
}

int main()
{
    Init();
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; i++)
            cout << res[i] << " ";
        cout << endl;
    }
    
    return 0;
}
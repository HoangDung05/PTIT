#include<bits/stdc++.h>
using namespace std;
int n,s,t[31], ok = 0, minn = INT_MAX;
bool visited[31];

void Init()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    sort(t, t + n, greater<int>());
    fill(visited, visited + n, true);
}

void Try(int sum, int cnt){ //X=(x1,x2,...,xn)
    for (int j = 0; j < n; j++)
    {
        if (sum == 0)
        {
            if (cnt < minn)
                minn = cnt;
            ok = 1;
            cnt = 0;
            return;
        }
        if (sum >= t[j])
        {
            visited[j] = false;
            Try(sum-t[j], cnt+1);
            visited[j] = true;
        }
    }
    
    

}

int main()
{
    Init();
    Try(s, 0);
    if (!ok)
        cout << -1;
    else 
        cout << minn;
    return 0;
}
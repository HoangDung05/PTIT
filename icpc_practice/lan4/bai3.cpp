#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n; 
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dx[4] = {0, 1, 1, -1};
    int dy[4] = {1, 0, 1, 1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int x = i, y = j, dots = 0, total = 0;
                for (int k = 0; k < 6; k++)
                {
                    if (x < 0 || x >= n || y < 0 || y >= n)
                    {
                        total = -1;
                        break;
                    }
                    if (a[x][y] == '.')
                        dots++;
                    total++;
                    x += dx[dir]; y += dy[dir];
                }
                if (total == 6 && dots <= 2)
                {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}
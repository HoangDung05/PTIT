#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<int> bac(n);
    int canh = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> v1(n);
        for (int j = 0; j < n; j++)
        {
            cin >> k;
            v[i][j] = k;
            if (j > i && k > 0 && k <= 50)
            {
                bac[i]++;
                bac[j]++;
                canh++;
            }
            
            
        }
    }
    if (t == 2)
    {
        cout << n << " " << canh << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (v[i][j] > 0 && v[i][j] <= 50)
                {
                    cout << i+1 << " " << j+1 << " " << v[i][j] << endl;
                }
            }
        }
        
    }
    else if (t == 1)
    {
        for(auto c: bac)
            cout << c << " ";
    }
    return 0;
}
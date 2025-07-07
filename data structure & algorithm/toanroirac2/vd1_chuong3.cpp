#include<iostream>
using namespace std;

int main()
{
    int t, n;
    cin >> t >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    if (t == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int dem = 0;
            for (int j = 0; j < n; j++)
            {
                dem += a[i][j];
            }
            cout << dem << " ";
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j <= i)
                {
                    continue;
                }
                else if (a[i][j] == 1)
                {
                    cout << i+1 << " " << j+1 << endl;
                }
                
            }
            
        }
        
    }
    
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<int> banbacvao(n), banbacra(n);
    vector<int> bac(n);
    int canh = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> v1(n);
        for (int j = 0; j < n; j++)
        {
            cin >> k;
            v[i][j] = k;
            if (k)
            {
                banbacra[i]++;
                banbacvao[j]++;
            }
        }
    }
    if (t == 2)
    {
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << banbacra[i];
            for (int j = 0; j < n; j++)
            {
                if (v[i][j])
                {
                    cout << " " << j+1 ;
                }
            }
            cout << endl;
        }
        
    }
    else if (t == 1)
    {
        for(int i = 0; i < n; i++)
            cout << banbacvao[i] << " " << banbacra[i] << endl;
    }
    return 0;
}
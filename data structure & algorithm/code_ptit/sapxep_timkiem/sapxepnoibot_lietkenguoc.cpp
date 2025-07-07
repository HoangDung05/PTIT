#include<iostream>
#include<vector>
#include<stdbool.h>
#include<algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n;
        vector<int> v;
        vector<vector<int>> v1;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            v.push_back(k);
        }
        for (int i = 0; i < n; i++)
        {
            bool check = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (v[j] > v[j+1])
                {
                    check = true;
                    swap(v[j], v[j+1]);
                }
            }
            if (check == false)
                break;
            v1.push_back(v);
        }
        for (int i = v1.size() - 1; i >= 0; i--)
        {
            cout << "Buoc " << i + 1 << ": ";
            for (auto c: v1[i])
                cout << c << " " ;
            cout << endl;
        }
    }
    return 0;
}
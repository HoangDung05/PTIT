#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void interchange_Sort(vector<int>& a, int n)
{
    vector<vector<int>> steps;
    for (int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
            }
        }
        steps.push_back(a);
    }

    for (int i = steps.size() - 1; i >= 0; i--)
    {
        cout << "Buoc " << i + 1 << ": ";
        for (auto x: steps[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    interchange_Sort(a, n);
    }
    return 0;
}
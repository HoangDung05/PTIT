#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[i], a[min]);
        b.push_back(a);
    }
    for (int i = b.size() - 1; i >= 0; --i)
    {
        cout << "Buoc " << i + 1 << ": ";
        for (auto c: b[i])
            cout << c << " ";
        cout << endl;
    }
}
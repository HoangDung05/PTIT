#include<bits/stdc++.h>
using namespace std;
int n, n1, k;
set<int> se;
vector<int> x, x1;
bool OK = true;

void Init()
{
    cin >> n >> k;
    int f;
    for (int i = 0; i < n; i++)
    {
        cin >> f;
        se.insert(f);
    }
    x1.assign(se.begin(), se.end());
    x.assign(se.begin(), se.end());
    n1 = x.size();
}

void Result()
{
    for (int i = 0; i < k; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Next_Combination()
{
    int i = k - 1;
    while (i >= 0 && x[i] == x1[n1+i-k])
    {
        i--;
    }
    if (i >= 0)
    {
        auto f = upper_bound(x1.begin(), x1.end(), x[i]);
        x[i] = *f;
        for (int j = i + 1; j < k; j++)
        {
            auto f = upper_bound(x1.begin(), x1.end(), x[j-1]);
            x[j] = *f;
        }
    }
    else
        OK = false;
}

int main()
{
    Init();
    while (OK)
    {
        Result();
        Next_Combination();
    }
    return 0;
}
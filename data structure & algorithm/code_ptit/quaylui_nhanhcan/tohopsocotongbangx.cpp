#include<bits/stdc++.h>
using namespace std;
int n, x, a[20], y[21];
vector<string> v;

void Init()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void Result(int i)
{
    string res = "{";
    for (int j = 0; j <= i; j++)
    {
        res += to_string(y[j]) + " ";
    }
    res.pop_back();
    res += "}";
    v.push_back(res);
}

void Try(int i, int sum, int cur) // Y=(y1,y2,...,yi,...,yn)
{
    for (int j = cur; j < n; j++)
    {
        if (sum + a[j] <= x)
        {
            y[i] = a[j];
            sum += a[j];
            if (sum == x)
                Result(i);
            else
                Try(i+1, sum, j);
            sum -= a[j];
        }
    }

}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        v.clear();
        Init();
        Try(0,0,0);
        if (v.size() != 0)
            cout << -1;
        else 
        {
            cout << v.size() << " ";
            for (string a: v)
                cout << a << " ";
        }
        cout << endl;
    }
    
    return 0;
}
#include<iostream>
using namespace std;

bool sequentialSearch(int x, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return true;
    }
    return false;
}

int main()
{ 
    int n, x;
    cin >> n >> x;
    int a[n];
    for (auto &c: a)
        cin >> c;
    if (sequentialSearch(x, a, n))
        cout << "Tim thay";
    else 
        cout << "Khong tim thay";
    return 0;
}
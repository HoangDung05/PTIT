#include<iostream>
using namespace std;

int sequential_Search(int a[], int n, int x) //x là giá trị cần tìm kiếm
{
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            return i;
        }
    }
    return - 1;
}

int main()
{
    int a[] = {2, 5, 7, 9, 15, 6};
    int x; cin >> x;
    int n = sizeof(a) / sizeof(a[0]);
    cout << sequential_Search(a, n, x);
    return 0;
}
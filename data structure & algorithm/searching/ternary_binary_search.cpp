#include<iostream>
using namespace std;

int ternary_binarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if(x == a[mid1])
            return mid1;
        if (x == a[mid2])
            return mid2;
        if(x < a[mid1])
            right = mid1 - 1;
        else if(x > a[mid2])
            left = mid2 + 1;
        else
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
}

int main()
{
    int a[] = {2, 5, 8, 19, 45, 87, 90, 95};
    int x; cin >> x;
    int n = sizeof(a) / sizeof(a[0]);
    cout << ternary_binarySearch(a, n, x);
    return 0;
}
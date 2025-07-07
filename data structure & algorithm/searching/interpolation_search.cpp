#include<iostream>
using namespace std;

int interpolationSearch(int a[], int n, int x)
{
    if (x < 0)
        return -1;
    if (x < a[0] || x > a[n-1])
        return -1;
    int low = 0, high = n - 1, mid;
    while (a[low] <= x && a[high] >= x)
    {
        if (low == high)
        {
            if (a[low] == x)
                return low;
            return -1;
        }
        if (a[low] == a[high])
            return (a[low] == x) ? low : -1;
        mid = low + (x - a[low])*(high - low)/(a[high] - a[low]);
        if (a[mid] < x)
            low = mid + 1;
        else if (a[mid] > x)
            high = mid - 1;
        else
            return mid;
    }
    if (a[low] == x)
        return low;
    return -1;
}

int main()
{
    int a[] = {2, 5, 8, 19, 45, 87, 90, 95};
    int x; cin >> x;
    int n = sizeof(a) / sizeof(a[0]);
    cout << interpolationSearch(a, n, x);
    return 0;
}
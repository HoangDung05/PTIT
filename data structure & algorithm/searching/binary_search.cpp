#include<iostream>
using namespace std;

int binarySearch(int a[], int n, int x)
{
    if (n <= 0)
        return -1;
    int high = n - 1, low = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (x < a[mid])
            high = mid - 1;
        else if (x > a[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int a[] = {2, 5, 8, 19, 45, 87, 90, 95};
    int x; cin >> x;
    int n = sizeof(a) / sizeof(a[0]);
    cout << binarySearch(a, n, x);
    return 0;
}